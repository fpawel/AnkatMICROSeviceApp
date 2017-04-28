//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "ctrlsys.h"
//------------------------------------------------------------------------------
#include <fstream>
#include <sstream>
#include <numeric>
#include <math>
//------------------------------------------------------------------------------
#include <Math.hpp>
#include <inifiles.hpp>
//------------------------------------------------------------------------------
#include "TransferManage.h"
#include "iniUtils_.h"
#include "appcfg.h"
#include "AnsiStringUtils_.h"
#include "guicon.h"
#include "MasterSlaveIO.h"
#include "FooCalledOnce.hpp"
#include "MasterSlaveIOSettings.hpp"
#include "MasterSlaveIOSettingsIni.h"
#include "winRS232.h"
#include "IOProtocols.hpp"
#include "task_.h"
#include "TaskList.h"
#include "Unit1.h"
#include "MyIostream.h"
#include "uAppSetsDlg.h"
#include "MyModFN.hpp"
#include "a7664adpt.h"
#include "ModbusAdapter.h"
#include "modbus_.h"



//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
#define RS232_INI_SEKT "COMPORT"
#define MASTER_SLAVE_IO_SETTINGS_SEKT "Установки МАСТЕР-СЛЭЙВ"
#define MAIN_INI_ID "MAIN"
//------------------------------------------------------------------------------
void HandleError()
{
    MyWCout(FormatMyExceptionMessages( MY_RETHROW_.get(),
        "\n\t", "\"%eMsg\" [%eLine:%eFile]")+"\n", MY_SET_CONSOLE_RED_TEXT);
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
class CtrlSysImpl::Impl : public boost::noncopyable
{
public:
    explicit Impl();
    ~Impl();

    void SetupDialog();

    A7664Adpt& GetA7664Adpt() { return a7664Adpt_; }
    ModbusAdapter& Modbus() { return modbusAdapter_; }

    void AddInitializeTask();

    bool MustShowFlasLog() const{ return mustShowFlasLog_; }

    double KConc_;

    void AddSetDevDateTask();
private:
    TransferManagerT& tmngr_;
    TIniFile* ini_;
    my::RS232::Port rs232_;
    MasterSlaveIOSettings ioSets_;
    MasterSlaveIOImpl masterSlave_;
    A7664Adpt a7664Adpt_;
    ModbusAdapter modbusAdapter_;
    boost::shared_ptr<void> connectOnTransferManager_;
    bool mustShowFlasLog_;



    void OnTNotifyChangeComport(unsigned state, const MyPort& port, const void*, int);
    void OnTransferManager(unsigned state, const AnsiString&);
};
//------------------------------------------------------------------------------
CtrlSysImpl::Impl::Impl() :
    tmngr_( TransferManager::Instance() ),
    ini_( IniConfig() ),
    rs232_(),
    ioSets_(),
    masterSlave_( ioSets_ ),
    a7664Adpt_( masterSlave_ ),
    modbusAdapter_( ioSets_ ),
    connectOnTransferManager_( tmngr_.ConnectOnReportState(OnTransferManager) ),
    KConc_(10.)
{
    ASSERT_FUNCTION_CALLED_ONCE__;
    rs232_.LoadSettingsFromIniFile( ini_, RS232_INI_SEKT );

    my::RS232::Setings sets = rs232_.GetSettings();
    //sets.dcb_.BaudRate = 115200;
    rs232_.SetSettings(sets);
    rs232_.SetNotifyChange( &OnTNotifyChangeComport );

    LoadMasterSlaveIOSettingsFromFile( ioSets_, ini_, MASTER_SLAVE_IO_SETTINGS_SEKT );
    masterSlave_.SetIOPort( &rs232_ );
    modbusAdapter_.SetIOPort( &rs232_ );
    //for(unsigned n=0; n<3; ++n) spanGasConc_[n] = ini_->ReadFloat( MAIN_INI_ID, "ПГС"+IntToStr(n+1), 1 );

    mustShowFlasLog_ = ini_->ReadBool(MAIN_INI_ID, "показывать флэш", 0);
    KConc_ = ini_->ReadFloat(MAIN_INI_ID, "KCONC", 10);
}
//------------------------------------------------------------------------------
CtrlSysImpl::Impl::~Impl()
{
    ASSERT_FUNCTION_CALLED_ONCE__;
    LOG_FOO_LIFETIME_QUOTES;
    tmngr_.StopThread();
    rs232_.SaveSettingsToIniFile( ini_, RS232_INI_SEKT );
    SaveMasterSlaveIOSettingsToFile( ioSets_, ini_, MASTER_SLAVE_IO_SETTINGS_SEKT );
    ini_->WriteBool(MAIN_INI_ID, "показывать флэш", mustShowFlasLog_);
    ini_->WriteFloat(MAIN_INI_ID, "KCONC", KConc_);
    //for(unsigned n=0; n<3; ++n) ini_->WriteFloat( MAIN_INI_ID, "ПГС"+IntToStr(n+1), spanGasConc_[n] );

}
//------------------------------------------------------------------------------
void CtrlSysImpl::Impl::AddInitializeTask()
{
    const TemporaryStopTransferManager tstm;
    tmngr_.GetTaskList().EraseTasksOfClass<InitializeDevice>();
    tmngr_.AddTask( new InitializeDevice(),TransferManagerT::ADD_TASK_HEAD );
}

void CtrlSysImpl::Impl::AddSetDevDateTask(){
    const TemporaryStopTransferManager tstm;
    tmngr_.GetTaskList().EraseTasksOfClass<SyncDevDate>();
    tmngr_.AddTask( new SyncDevDate(),TransferManagerT::ADD_TASK_HEAD );
}

void CtrlSysImpl::Impl::OnTransferManager(unsigned context, const AnsiString&)
{
    const bool
        //isStartThread    	= context==TransferManagerT::State::START,
        isStopThread        = context==TransferManagerT::State::STOP;

    if(isStopThread)
        rs232_.Disconnect();

}
//------------------------------------------------------------------------------
void CtrlSysImpl::Impl::OnTNotifyChangeComport(unsigned state, const MyPort& port, const void*, int)
{
    if(Form1==NULL) return;
    if(state==MyPort::stRead)
    {
        Form1->panelConnect->Caption = "Связь установлена";
        Form1->panelConnect->Font->Color = clNavy;
        Form1->SetStatus( "Связь установлена "+port.Description(), 2 );
    } else if(state==MyPort::stDisconnect)
    {
        Form1->SetStatus( "", 2 );
        Form1->panelConnect->Caption = "";
    }
}
//------------------------------------------------------------------------------
void CtrlSysImpl::Impl::SetupDialog()
{
    const bool wasStarted = !tmngr_.IsThreadStopedOrTerminated();
    tmngr_.StopThread();


    boost::shared_ptr<TFormAppSetsDlg> dlg( new TFormAppSetsDlg(NULL) );
    using namespace AppSetsGrdItems::Row;

    #define VVAl_(nn) dlg->grd1->Cells[2][AppSetsGrdItems::Row::##nn##]
    VVAl_(COM) =  rs232_.GetPortName() ;
    VVAl_(Timeout) =  ioSets_.timeOut_ ;
    VVAl_(WaitDelay) =  ioSets_.tmWriteDelay_;
    VVAl_(SilentTime) =  ioSets_.silentTime_;
    VVAl_(RepeatCount) =  ioSets_.repeatCount_;
    VVAl_(ShowComPortLog) =  ioSets_.mustLogData_ ? "Да" : "Нет" ;

    my::RS232::Setings sets = rs232_.GetSettings();
    VVAl_(COMBoudRate) =  sets.dcb_.BaudRate;

    VVAl_(ShowFlasLog) =  mustShowFlasLog_ ? "Да" : "Нет" ;
    VVAl_(KConc) = KConc_ ;

    //VVAl_(Conc1) =  spanGasConc_[0];
    //VVAl_(Conc2) =  spanGasConc_[1] ;
    //VVAl_(Conc3) =  spanGasConc_[2];

    dlg->ShowModal();
    if( dlg->ModalResult==mrOk )
    {
        rs232_.SetPortName( VVAl_(COM) );
        ioSets_.timeOut_ = StrToIntDef( VVAl_(Timeout), 1000 );
        ioSets_.tmWriteDelay_ = StrToIntDef( VVAl_(WaitDelay), 0);
        ioSets_.silentTime_ = StrToIntDef( VVAl_(SilentTime), 50);
        ioSets_.repeatCount_ = StrToIntDef( VVAl_(RepeatCount), 0);
        ioSets_.mustLogData_ = VVAl_(ShowComPortLog)=="Да";
        mustShowFlasLog_ = VVAl_(ShowFlasLog)=="Да";
        KConc_ = MyStrToFloatDef( VVAl_(KConc), 10);


        //spanGasConc_[0] = MyStrToFloatDef( VVAl_(Conc1), 0);
        //spanGasConc_[1] = MyStrToFloatDef( VVAl_(Conc2), 0);
        //spanGasConc_[2] = MyStrToFloatDef( VVAl_(Conc3), 0);

        sets.dcb_.BaudRate = VVAl_(COMBoudRate).ToInt();
        rs232_.SetSettings(sets);

    }
    #undef VVAL_
    if(wasStarted) tmngr_.StartThread();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
CtrlSysImpl::CtrlSysImpl() : impl_( new Impl ) {}
//------------------------------------------------------------------------------
void CtrlSysImpl::SetupDialog()
{
    impl_->SetupDialog();
}
//------------------------------------------------------------------------------
void CtrlSysImpl::AddInitializeTask()
{
    impl_->AddInitializeTask();
}
bool CtrlSysImpl::MustShowFlasLog() const
{
    return impl_->MustShowFlasLog();
}


A7664Adpt& CtrlSysImpl::GetA7664Adpt()
{
    return impl_->GetA7664Adpt();
}

ModbusAdapter& CtrlSysImpl::Modbus()
{
    return impl_->Modbus();
}

double CtrlSysImpl::KConc() const
{
        return impl_->KConc_;
}

void CtrlSysImpl::AddSetDevDateTask(){
      impl_->AddSetDevDateTask();
}


