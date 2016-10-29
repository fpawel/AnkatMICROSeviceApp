#include <map>
//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "TransferManage.h"
//------------------------------------------------------------------------------
#include <windows.h>
#include <vcl.h>
#include <DateUtils.hpp>
//------------------------------------------------------------------------------
// loki
#include "Loki\singleton.h"
//------------------------------------------------------------------------------
#include "..\VCLUtils\myThread.h"
#include "TaskList.h"
#include "MyExcpt.hpp"
#include "uFrmWait.h"
#include "AnsiStringUtils_.h"
#include "..\appcfg.h"
#include "MyExeptionImpl.h"
#include "guicon.h"
#include "FooCalledOnce.hpp"
#include "MyShllFldr.h"
#include "MySynchronize.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma option -xp
//------------------------------------------------------------------------------
#define TRANSFERS_SEKT "Трансфер"
#define TRANSFERS_THREAD_PRIORITY_ID "приоритет_второго_потока"
//------------------------------------------------------------------------------

AnsiString FormatTimeSpecial1(unsigned msec)
{
    return FormatDateTime("hh:nn:ss:zzz", IncMilliSecond(0, msec) );
}
//------------------------------------------------------------------------------
LRESULT HideTopmostPanel1(TFrmWait *topPanel)
{   
    topPanel->Hide();
    topPanel->pb1->Visible = 0;
    topPanel->pb1->Position = 0;
    topPanel->pb1->Min = 0;
    topPanel->pb1->Max = 0;
    topPanel->Panel1->Visible = 0;
    //throw;
    return 0;
}
void HideTopmostPanel(TFrmWait *topPanel)
{
    my::Synchronize1( &HideTopmostPanel1, topPanel, __FILE_LINE__ );
}
//------------------------------------------------------------------------------
LRESULT ShowTopmostPanel1( TFrmWait *topPanel, const AnsiString& s, bool showProgress )
{
    topPanel->Label2->Caption = "00:00:00";
    if(topPanel->Visible && topPanel->Panel2->Caption == s) return 0;
    topPanel->Panel2->Caption = s;
    if(!topPanel->Visible)
        topPanel->FixPosition();
    topPanel->Position = poScreenCenter;
    topPanel->Show();
    topPanel->Repaint();

    if( showProgress )
    {
        topPanel->pb1->Visible = 1;
        topPanel->pb1->Position = 0;
        topPanel->pb1->Min = 0;
        topPanel->pb1->Max = 0;
        topPanel->Panel1->Visible = 1;

    }


    return 0;
}
void ShowTopmostPanel( TFrmWait *topPanel, const AnsiString& s, bool showProgress )
{
    my::Synchronize3( &ShowTopmostPanel1, topPanel, s, showProgress, __FILE_LINE__ );
}
//------------------------------------------------------------------------------
LRESULT SetTopmostPanelProgress1( TFrmWait *topPanel, unsigned v, unsigned vMax, unsigned vMin )
{
    if( topPanel->pb1->Visible )
    {
        if(v!=-1)
        {
            if(v==-2)
                topPanel->pb1->Position = topPanel->pb1->Position + 1;
            else
                topPanel->pb1->Position = v;
        }
        if(vMax!=-1)
            topPanel->pb1->Max = vMax;
        if(vMin!=-1)
            topPanel->pb1->Min = vMin;

        topPanel->Repaint();
    }
    return 0;
}

void SetTopmostPanelProgress( TFrmWait *topPanel, unsigned v, unsigned vMax, unsigned vMin )
{
    my::Synchronize4( &SetTopmostPanelProgress1, topPanel, v, vMax, vMin, __FILE_LINE__ );
}


class TopmostPanelHelper : public boost::noncopyable
{
public:
    TopmostPanelHelper(TFrmWait *topPanel, const AnsiString& s ) : topPanel_(topPanel)
    {
        ShowTopmostPanel( topPanel, s, false );
    }
    ~TopmostPanelHelper()
    {
        HideTopmostPanel(topPanel_);
    }
private:
    TFrmWait *topPanel_;
};

class FlagRester : public boost::noncopyable
{
public:
    explicit FlagRester(bool& flag_) : flag(flag_) { flag=1; }
    ~FlagRester() { flag = 0; }
private:
    bool& flag;
};

//------------------------------------------------------------------------------
class TransferManagerT::Impl : public boost::noncopyable
{
public:
    explicit Impl();
    ~Impl();
    //--------------------------------------------------------------------------
    // управление потоком
    void StartThread();
    void StopThread();
    bool IsThreadStopedOrTerminated() const { return thr_->IsTerminated() || thr_->WasStoped(); }
    //--------------------------------------------------------------------------
	TReportStateSignal::Connections& ReportStateConnections()
    { return signalReportState_.GetConnections(); }
    //---------------------------------------------------------------------------
    TaskList& GetTaskList() { return taskList_; }
    //---------------------------------------------------------------------------
    void DebugConsoleInput();

    // Выполнить трансфер приёмопередачи.
	void PerformTransfer( uInt8 modusAddr, uInt8 commandCode, ByteBuffPtr sendBegin,
    	ByteBuffPtr sendEnd, ByteBuffPtr& reciveBegin, ByteBuffPtr& reciveEnd );

    // упрвление списком - добавить задание
    void AddTask( MyAbstructTransfer *trnsfr, bool addTail = ADD_TASK_TAIL)
    {
        if( addTail==ADD_TASK_TAIL )
            taskList_.PushBackTail( PTransfer(trnsfr) );
        else
            taskList_.PushFrontHead( PTransfer(trnsfr) );
    }

    void AddTask( TVoidMthd mthd, const AnsiString& what, bool addTail );

    void SyncronizedSleep( unsigned tm, bool showDelayProgress );

    const MyException* GetLastException() const
    {
        return lastExcpt_.get();
    }

    void HideTopPanel(){ HideTopmostPanel( topPanel_);    }
    void ShowTopPanel( const AnsiString& s, bool showProgress ){ ShowTopmostPanel( topPanel_, s, showProgress); }
    void SetTopPanelProgress( unsigned v, unsigned vMax, unsigned vMin )
    {
        SetTopmostPanelProgress( topPanel_, v, vMax, vMin);
    }

private:
    boost::shared_ptr<void> logLifeTime_;
    //--------------------------------------------------------------------------
    //  поток
    //boost::shared_ptr<my::Thread> thr_;
    my::Thread *thr_;
	//--------------------------------------------------------------------------
    // список планируемых трансферов
    TaskList taskList_;
    //--------------------------------------------------------------------------
    TReportStateSignal signalReportState_;
    //--------------------------------------------------------------------------
    // последнее зафиксированное исключение
    PMyExcpt lastExcpt_;
    //--------------------------------------------------------------------------
    TFrmWait *topPanel_;
    bool goingStop_;

    const unsigned mainThreadId_;

    struct TerminateFromThreadSignal {};


	// потоковая продцедура
	void __fastcall Execute();
    //--------------------------------------------------------------------------
    LRESULT SignalReportState1(unsigned context, const AnsiString& s)
    {
        signalReportState_.Signal2(context, s);
        return 0;
    }
    // отправить отчёт
    void SignalReportState(unsigned context, const AnsiString& s)
    {
        my::Synchronize2( &SignalReportState1, context, s, __FILE_LINE__  );
    }
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    //подготовить задание из списка - вызывать из потока
    PTransfer PrepareCurentTask();
    //--------------------------------------------------------------------------
    //              реакциИ на событиЯ
    LRESULT HandleBeginTransfer();
    LRESULT HandleEndTransfer();
    LRESULT HandleCurentException();

    void __fastcall OnBtnCloseClick( TObject* )
    {
        StopThread();
    }
};
//------------------------------------------------------------------------------
TransferManagerT::Impl::Impl() :
    logLifeTime_( MakeMyLogQuote("MyTransfer::Manager.[members]") ),
    // оконный объект данного модуля
	thr_( new my::Thread(&Execute) ),
    taskList_(),
    signalReportState_(),
    mainThreadId_( ::GetCurrentThreadId() ) 
{
    ASSERT_FUNCTION_CALLED_ONCE__;
    thr_->SetPriority( static_cast<TThreadPriority> (
        IniConfig()->ReadInteger(TRANSFERS_SEKT, TRANSFERS_THREAD_PRIORITY_ID, tpLowest)
        ) );
    topPanel_ = new TFrmWait(NULL);
    topPanel_->Panel2->Font->Size = 14;
    topPanel_->btnClose->OnClick = OnBtnCloseClick;
}
//------------------------------------------------------------------------------
TransferManagerT::Impl::~Impl()
{
	//LOG_FOO_LIFETIME_QUOTES;
    try
    {

        IniConfig()->WriteInteger(TRANSFERS_SEKT, TRANSFERS_THREAD_PRIORITY_ID, thr_->GetPriority() );
        signalReportState_.GetConnections().DisconnectAll();
        //assert( thr_->WasStoped() );
    }
    catch (...)
    {
        assert(false);
    }

}
//------------------------------------------------------------------------------
void TransferManagerT::Impl::SyncronizedSleep( const unsigned msec, bool showDelayProgress )
{
    const unsigned moment0 = ::GetTickCount();

    if( !showDelayProgress )
    {
        while( GetTickCount()-moment0 < msec )
        {
            if( IsThreadStopedOrTerminated() ) return;
            Sleep(1);
        }
        return;
    }

    ConsoleMultioutputHelper cmoh;
    //const unsigned tmStart = ::GetTickCount();
    const AnsiString ssPrecent = "%";
    unsigned iterN = 0;
    for( unsigned moment = moment0; moment-moment0<msec &&
        !IsThreadStopedOrTerminated(); moment= ::GetTickCount() )
    {
        ::Sleep(1);
        if(++iterN!=30) continue;
        iterN = 0;
        const unsigned elepsed = moment-moment0;
        cmoh.Set( MYSPRINTF_("%s из %s %d%s", FormatTimeSpecial1(elepsed),
                FormatTimeSpecial1(msec), 100*elepsed/msec, ssPrecent ) );
    }
    cmoh.Set("");
    //MYWCOUT_("Задержка %s\n", FormatTimeSpecial1( ::GetTickCount()-moment0 ) )) ;
}
//------------------------------------------------------------------------------
// управление потоком
void TransferManagerT::Impl::StartThread()
{
	//LOG_FOO_LIFETIME_QUOTES;
    lastExcpt_.reset();
    thr_->Run();
}

//------------------------------------------------------------------------------
void TransferManagerT::Impl::StopThread()
{
    if( ::GetCurrentThreadId()!=mainThreadId_ )
        throw TerminateFromThreadSignal();


    if( ::InSendMessage()==TRUE )
    {
        goingStop_ = 1;
        return;
    }

    //ShowTopPanel("Выполняется закрытие соединения...");
    const TThreadPriority threadPriority = thr_->GetPriority();
    thr_->SetPriority( tpTimeCritical );
    thr_->Stop();
    thr_->SetPriority( threadPriority );
    SignalReportState( State::STOP, "Опрос остановлен" );
    HideTopPanel();
}
//------------------------------------------------------------------------------
void __fastcall TransferManagerT::Impl::Execute()
{   
    //LOG_FOO_LIFETIME_QUOTES;
    goingStop_ = 0;
    SignalReportState( State::START, "Опрос: старт" );
	for
    (
    	PTransfer curentTask = PrepareCurentTask();
        !thr_->IsTerminated();
        curentTask = PrepareCurentTask()
    )
    {
        #define CHECK_STOP_THREAD_ if( IsThreadStopedOrTerminated() || goingStop_) break;

        CHECK_STOP_THREAD_;
    	try
    	{
    	    if(curentTask.get()==NULL)
            {
            	if( taskList_.IsEmpty() ) break; else continue;
            }
            //обработка события начала трансфера
    		if( HandleBeginTransfer()==false )
            {
            	taskList_.PopFrontBody();
                continue;
            }
            CHECK_STOP_THREAD_;

            // выполнить трансфер
            curentTask->Perform();

            CHECK_STOP_THREAD_;

            //обработка события окончания трансфера
            if( HandleEndTransfer()==true )
            	taskList_.PushBackBody( curentTask ) ;
            taskList_.PopFrontBody();
            CHECK_STOP_THREAD_;

        }// try
        catch(const TerminateFromThreadSignal&)
        {
            MyWCout("Опрос прерван из потоковой продцедуры.\n");
            break;
        }
   	 	catch(...)
    	{
        	lastExcpt_ = MY_RETHROW_;
            HandleCurentException();
            CHECK_STOP_THREAD_;
            SyncronizedSleep(10,false);
    	}
        #undef CHECK_STOP_THREAD_
    } // for( PTaskData curentTask = taskList_.Front();
    HideTopPanel();
    SignalReportState( State::STOP, "Опрос остановлен" );
}
//------------------------------------------------------------------------------
// реакция на событие "начало трансфера"
LRESULT TransferManagerT::Impl::HandleBeginTransfer()
{
	if( thr_->IsTerminated() || taskList_.IsEmpty() ) return 0;
	const PTransfer curentTask = taskList_.FrontBody();
    assert(curentTask);
    const LRESULT ret = static_cast<LRESULT>( curentTask->HandleBeginTransfer() );
    if(ret!=0)
    	SignalReportState(State::BEG, curentTask->What() );
	return ret;
}
//------------------------------------------------------------------------------
// реакция на событие "окончание трансфера"
LRESULT TransferManagerT::Impl::HandleEndTransfer()
{
	if( thr_->IsTerminated() || taskList_.IsEmpty() ) return 0;
	const PTransfer curentTask = taskList_.FrontBody();
    if( curentTask.get() == NULL ) return 0;
    SignalReportState( State::END, curentTask->What() );
    lastExcpt_.reset();
    HideTopPanel();
    return static_cast<LRESULT>( curentTask->HandleEndTransfer() );
}
//------------------------------------------------------------------------------
LRESULT TransferManagerT::Impl::HandleCurentException()
{
	if( thr_->IsTerminated() || !lastExcpt_.get() ) return 0;
    this->HideTopPanel();
    const AnsiString msg = FormatMyExceptionMessages( lastExcpt_.get(), "\n" );
    MyWCout( FormatMyExceptionMessages( lastExcpt_.get(), "\n\t",
        "%eMsg %eLine %eFile")+"\n", MY_SET_CONSOLE_RED_TEXT );
    SignalReportState(State::ERR, lastExcpt_->Message() );
    return 0;
}
//------------------------------------------------------------------------------
//подготовить задание из списка - вызывать из потока
PTransfer TransferManagerT::Impl::PrepareCurentTask()
{
	assert(thr_);
    if( IsThreadStopedOrTerminated() ) return PTransfer();
    taskList_.Merge();
    PTransfer ret  = taskList_.FrontBody();
    return ret;
}
//------------------------------------------------------------------------------
void TransferManagerT::Impl::AddTask( TVoidMthd mthd, const AnsiString& what, bool addTail )
{
    class SingleAction : public NamedTransfer
    {
    public:
        explicit SingleAction(const AnsiString& what, TVoidMthd mthd)
            :
            NamedTransfer(what), mthd_(mthd)
        {}
        virtual ~SingleAction() {}
    private:
        const TVoidMthd mthd_;
        virtual bool HandleBeginTransfer() { return true; }
        virtual bool HandleEndTransfer() { return false; }
        virtual void Perform()
        {
            mthd_();
        }
    };

    AddTask( new SingleAction( what, mthd ), addTail );
}


/////////////////////////////////////////////////////////////////////////////////
//					class TransferManagerT
/////////////////////////////////////////////////////////////////////////////////
TransferManagerT::TransferManagerT() : impl_(new Impl)
{
}
//------------------------------------------------------------------------------
boost::shared_ptr<void> TransferManagerT::ConnectOnReportState(TVoid_IntStrMthd method)
{
	return impl_->ReportStateConnections().AutoConnect(method);
}
//------------------------------------------------------------------------------
// упрвление списком - добавить задание
void TransferManagerT::AddTask( MyAbstructTransfer *trnsfr, bool addTail)
{
    impl_->AddTask(trnsfr, addTail);
}
void TransferManagerT::AddTask( TVoidMthd mthd, const AnsiString& what,  bool addTail )
{
    impl_->AddTask(mthd, what, addTail);
}
//---------------------------------------------------------------------------
void TransferManagerT::ShowTopPanel(const AnsiString& s, bool showProgress)
{
    impl_->ShowTopPanel(s, showProgress);
}
//------------------------------------------------------------------------------
void TransferManagerT::HideTopPanel()
{
    impl_->HideTopPanel();
}
void TransferManagerT::SetTopPanelProgress( unsigned v, unsigned vMax, unsigned vMin )
{
    impl_->SetTopPanelProgress( v, vMax, vMin );
}
// управление потоком
void TransferManagerT::StartThread() { impl_->StartThread(); }
void TransferManagerT::StopThread() {  impl_->StopThread();  }

bool TransferManagerT::IsThreadStopedOrTerminated() const {	return impl_->IsThreadStopedOrTerminated(); }
const MyException* TransferManagerT::GetLastException() const { return impl_->GetLastException(); }

//---------------------------------------------------------------------------
/**
*       список трансферов
*/
TaskList& TransferManagerT::GetTaskList()
{
    return impl_->GetTaskList();
}
//------------------------------------------------------------------------------
void TransferManagerT::SyncronizedSleep( unsigned tm, bool showDelayProgress )
{
	impl_->SyncronizedSleep( tm, showDelayProgress );
}

TemporaryStopTransferManager::TemporaryStopTransferManager()
    : wasStarted_( !TransferManager::Instance().IsThreadStopedOrTerminated() )
{
    TransferManager::Instance().StopThread();
}
TemporaryStopTransferManager::~TemporaryStopTransferManager()
{
    if(wasStarted_)
        TransferManager::Instance().StartThread();
}




////////////////////////////////////////////////////////////////////////////////









