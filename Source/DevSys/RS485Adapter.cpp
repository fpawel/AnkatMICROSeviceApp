//---------------------------------------------------------------------------

#pragma hdrstop

#include "RS485Adapter.h"

#include <windows.h>

//std
#include <sstream>

#include "MasterSlaveIO.h"
//#include "loki\threads.h"
//#include <forms.hpp>
#include "AnsiStringUtils_.h"
#include "guicon.h"
#include "TransferManage.h"
#include "MySynchronize.h"

using std::cout;
using std::endl;

#pragma package(smart_init)

void RS485Adapter::SetAddy(unsigned char addy, bool isAnswered)
{
    notAnswered_[addy] = !isAnswered;
    answered_[addy] = isAnswered;
}

bool RS485Adapter::IsNotAnsweredAddy(unsigned addy) const { return notAnswered_[addy];  }

void RS485Adapter::OnTransferManagerReport(unsigned context, const AnsiString& state)
{
    if(context==TransferManagerT::State::START)
    {
        std::fill( notAnswered_, notAnswered_+256, false );
        std::fill( answered_, answered_+256, false );
    }
}

RS485Adapter::RS485Adapter(const MasterSlaveIOSettings &sets, MyPort *port ) :
    masterSlaveIO_( new MasterSlaveIOImpl(sets) ), notifyState_(NULL),
    tmngr_( TransferManager::Instance() ),
    connectOnTransferManagerReport_
        ( tmngr_.ConnectOnReportState(OnTransferManagerReport) )
{
    
}

const MasterSlaveIOImpl& RS485Adapter::MasterSlave() const
{
    return *masterSlaveIO_.get();
}

void RS485Adapter::SetSignalState(unsigned state)
{
    if( notifyState_ && !masterSlaveIO_->IsTransferManagerWasStopedOrTerminated() )
        my::Synchronize2( notifyState_, this, state, __FILE_LINE__ );
}


void RS485Adapter::SetNotifyState( TOnNotifyState foo )
{
    notifyState_ = foo;
}

void RS485Adapter::PerformTransfer( unsigned addy, unsigned commandCode,
    const unsigned char* sendBegin, const unsigned char* sendEnd, unsigned timeOut )
{
    SetSignalState(State::START);

    std::vector<unsigned char> txd;

    PrepareTxD(txd, addy, commandCode, sendBegin, sendEnd);

    const bool needAnswer = addy!=0;
    masterSlaveIO_->Send( txd.begin(), txd.end(), needAnswer );

    if( !needAnswer || masterSlaveIO_->IsTransferManagerWasStopedOrTerminated()  ) return;
    const unsigned rxdSize = masterSlaveIO_->RxDSize();
    const unsigned char *rxd = masterSlaveIO_->RxD(), *rxdEnd = rxd + rxdSize;

    // проверка корректности rxd_ - возбуждаются исключения
    CheckCorrectAnswer(rxd, rxdEnd);

    SetAddy( this->Addy(), true );
    SetSignalState(State::END);
}



