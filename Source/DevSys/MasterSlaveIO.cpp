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

// вывести массив в cout
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
// Передать txd, считать данные приёмника в rxd, вернуть длительность трансфера
void MasterSlaveIOImpl::Send(	const char* sendBegin, const char* sendEnd, bool needAnswer )
{
    if( IsTransferManagerWasStopedOrTerminated() )
    {
        MyWCout( "Отмена трансфера! Поток остановлен!\n" );
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
    // очистка буфферов
    port_->Purge();
    rxd_.clear();
    // вывести txd в cout
    LogOut( "txd:\n"+ PrintVInt8( txd_ )+"\n" );
    // отправить запрос
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
    // запомнить момент начала считывания из RxD
    unsigned tmStart = GetTickCount();
    while( !IsTransferManagerWasStopedOrTerminated() &&
        (GetTickCount() - tmStart < sets_.timeOut_) )
    {
		// определим количество байтов в буффере порта
        const int rxdSize = port_->GetRxDSize();
        // если RxD пуст, продолжаем мониторинг
        if( rxdSize==0 )
        {
            ::Sleep(1);
            continue;
        }
        // в приёмнике появились данные. Считываем
        const unsigned oldReadBuffSize = rxd_.size();
        rxd_.resize(oldReadBuffSize + rxdSize);
        void *pReadBuff = reinterpret_cast<void*>( &rxd_.at(oldReadBuffSize) );
        port_->Read( pReadBuff, rxdSize );
        // ждём ещё некоторое время silentTime_ и проверяем длину RxD.
        // Если не 0, продолжаем считывание
        // иначе считаем что посылка завершена
        ::Sleep(sets_.silentTime_);
        if( port_->GetRxDSize()==0 ) break;
        tmStart = ::GetTickCount();
    }
    LogOut( MYSPRINTF_("%d мсек ", GetTickCount() - tmStart)  );
    const bool timeOutFixed = (GetTickCount() - tmStart >= sets_.timeOut_);

    static unsigned timeOutCount = 0;
    if( timeOutFixed )
    {
    	++timeOutCount;
        LogOut( MYSPRINTF_(" Таймаут %d.", timeOutCount ));
        if(timeOutCount<sets_.repeatCount_)
        {
            LogOut( MYSPRINTF_(" Повтор №%d из %d.\n", timeOutCount, sets_.repeatCount_ ));
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
        LogOut( " нет ответа!\n" );
        //MY_THROW_(port_->Description()+" не отвечает!");
        MY_THROW_CLASS_(MyNoAnswerException, port_->Description()+" не отвечает!");
    }


}
//------------------------------------------------------------------------------
void MasterSlaveIOImpl::SetIOPort(MyPort* port)
{
    const TemporaryStopTransferManager tstm;
    port_ = port;
}
//------------------------------------------------------------------------------
// открыть канал связи с текущими настройками
void MasterSlaveIOImpl::OpenPort()
{
    assert(port_);
	if( port_->IsConnected() ) return;
    try
    {
        MYWCOUT_( "Соединение с \"%s\" ....\n", port_->Description() ));
    	port_->Connect();
        MyWCout( "Соединение установлено.\n");
    }
    catch(...)
    {
    	// подождать секунду, чтобы постоянно не дёргать нерабочий порт
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
    MYWCOUT_( "Соединение с \"%s\" закрыто.\n", port_->Description() ));
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




