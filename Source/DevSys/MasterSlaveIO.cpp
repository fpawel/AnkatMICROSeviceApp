//---------------------------------------------------------------------------
#include <windows.h>

//std
#include <sstream>

#pragma hdrstop
//------------------------------------------------------------------------------
#include "MasterSlaveIO.h"
//------------------------------------------------------------------------------
// loki
#include "loki\threads.h"
//------------------------------------------------------------------------------
#include <forms.hpp>
//------------------------------------------------------------------------------

#include "AnsiStringUtils_.h"
#include "guicon.h"
#include "TransferManage.h"

//------------------------------------------------------------------------------
using std::cout;
using std::endl;
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
MyNoAnswerException::MyNoAnswerException(const FileLine& loc, const AnsiString& msg,
    const PMyExcpt nest ) : MyException( loc, msg, nest )
{}
//------------------------------------------------------------------------------

// ������� ������ � cout
AnsiString PrintVInt8( const std::vector<char>& v, int lim = -1 )
{
    const unsigned maxIdx = (lim==-1) ? v.size() : std::min(lim, v.size() );
    return MyBuffToStr( v.begin(), v.begin() + maxIdx );
}
//------------------------------------------------------------------------------
void PerformDelay(TBoolMthd mthd, unsigned tm)
{
	const unsigned tmStart = GetTickCount();
    while( (GetTickCount()-tmStart < tm) && !mthd() )
        ::Sleep(1);
}
//---------------------------------------------------------------------------
MasterSlaveIOImpl::MasterSlaveIOImpl(const MasterSlaveIOSettings &sets) :
    mainThreadId_( ::GetCurrentThreadId() ),
    tmngr_( TransferManager::Instance() ),
    onNoAnswer_(NULL),
    port_(NULL), sets_(sets)
{   
}
//------------------------------------------------------------------------------
MasterSlaveIOImpl::~MasterSlaveIOImpl()
{       
}
//------------------------------------------------------------------------------
bool MasterSlaveIOImpl::IsTransferManagerWasStopedOrTerminated() const
{
    return ::GetCurrentThreadId()!=mainThreadId_ && tmngr_.IsThreadStopedOrTerminated();

}
//------------------------------------------------------------------------------
void MasterSlaveIOImpl::LogOut( const AnsiString& s)
{
	if( !sets_.mustLogData_ ) return;
    MyWCout( s );
}
//------------------------------------------------------------------------------
// �������� txd, ������� ������ �������� � rxd, ������� ������������ ���������
void MasterSlaveIOImpl::Send(	const char* sendBegin, const char* sendEnd, bool needAnswer )
{
    if( IsTransferManagerWasStopedOrTerminated() )
    {
        MyWCout( "������ ���������! ����� ����������!\n" );
        return;
    }

    txd_.assign( sendBegin, sendEnd );
    if( ::GetCurrentThreadId()!=mainThreadId_ )
        tmngr_.SyncronizedSleep( sets_.tmWriteDelay_ );
    else
        ::Sleep(sets_.tmWriteDelay_);
    OpenPort();
    if(!needAnswer)
        SendTxD();
    else
        SendTxDAndGetAnswer();
}
//------------------------------------------------------------------------------
void MasterSlaveIOImpl::SendTxD()
{
    // ������� ��������
    port_->Purge();
    rxd_.clear();
    // ������� txd � cout
    LogOut( "txd:\n"+ PrintVInt8( txd_ )+"\n" );
    // ��������� ������
    const unsigned txdSz = txd_.size();
    assert(txdSz>0);
    void *pTxdBuf = reinterpret_cast<void*>( const_cast<char*>(&txd_.at(0)) );
    port_->Write( pTxdBuf, txdSz );
}
//------------------------------------------------------------------------------
void MasterSlaveIOImpl::SendTxDAndGetAnswer()
{
    beginProcedureLable:
    SendTxD();
    // ��������� ������ ������ ���������� �� RxD
    unsigned tmStart = GetTickCount();
    while( !IsTransferManagerWasStopedOrTerminated() &&
        (GetTickCount() - tmStart < sets_.timeOut_) )
    {
		// ��������� ���������� ������ � ������� �����
        const int rxdSize = port_->GetRxDSize();
        // ���� RxD ����, ���������� ����������
        if( rxdSize==0 )
        {
            ::Sleep(1);
            continue;
        }
        // � �������� ��������� ������. ���������
        const unsigned oldReadBuffSize = rxd_.size();
        rxd_.resize(oldReadBuffSize + rxdSize);
        void *pReadBuff = reinterpret_cast<void*>( &rxd_.at(oldReadBuffSize) );
        port_->Read( pReadBuff, rxdSize );
        // ��� ��� ��������� ����� silentTime_ � ��������� ����� RxD.
        // ���� �� 0, ���������� ����������
        // ����� ������� ��� ������� ���������
        ::Sleep(sets_.silentTime_);
        if( port_->GetRxDSize()==0 ) break;
        tmStart = ::GetTickCount();
    }
    LogOut( MYSPRINTF_("%d ���� ", GetTickCount() - tmStart)  );
    const bool timeOutFixed = (GetTickCount() - tmStart >= sets_.timeOut_);

    static unsigned timeOutCount = 0;
    if( timeOutFixed )
    {
    	++timeOutCount;
        LogOut( MYSPRINTF_(" ������� %d.", timeOutCount ));
        if(timeOutCount<sets_.repeatCount_)
        {
            LogOut( MYSPRINTF_(" ������ �%d �� %d.\n", timeOutCount, sets_.repeatCount_ ));
        	goto beginProcedureLable;
        }
    }
    timeOutCount = 0;
    if( !rxd_.empty() )
    {
    	LogOut( "rxd:\n"+ PrintVInt8( rxd_ )+"\n" );
    }
    else
    {
        LogOut( " ��� ������!\n" );
        if(onNoAnswer_) onNoAnswer_();
        //MY_THROW_(port_->Description()+" �� ��������!");
        MY_THROW_CLASS_(MyNoAnswerException, port_->Description()+" �� ��������!");
    }


}
//------------------------------------------------------------------------------
void MasterSlaveIOImpl::SetIOPort(MyPort* port)
{
    const TemporaryStopTransferManager tstm;
    port_ = port;
}
//------------------------------------------------------------------------------
// ������� ����� ����� � �������� �����������
void MasterSlaveIOImpl::OpenPort()
{
    assert(port_);
	if( port_->IsConnected() ) return;
    try
    {
        MYWCOUT_( "���������� � \"%s\" ....\n", port_->Description() ));
    	port_->Connect();
        MyWCout( "���������� �����������.\n");
    }
    catch(...)
    {
    	// ��������� �������, ����� ��������� �� ������ ��������� ����
    	Sleep(1000);
        throw;
    }
}
//------------------------------------------------------------------------------
void MasterSlaveIOImpl::ClosePort()
{
	if( !port_->IsConnected() ) return;
    port_->Purge();
    port_->Disconnect();
    MYWCOUT_( "���������� � \"%s\" �������.\n", port_->Description() ));
}
//------------------------------------------------------------------------------
const char* MasterSlaveIOImpl::TxD() const
{
    return txd_.empty() ? NULL : &txd_.at(0);
}
//------------------------------------------------------------------------------
const char* MasterSlaveIOImpl::RxD() const
{
    return rxd_.empty() ? NULL : &rxd_.at(0);
}
//------------------------------------------------------------------------------
unsigned MasterSlaveIOImpl::TxDSize() const { return txd_.size(); }
unsigned MasterSlaveIOImpl::RxDSize() const { return rxd_.size(); }


//------------------------------------------------------------------------------




