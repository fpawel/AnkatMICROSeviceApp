//---------------------------------------------------------------------------
#include <windows.h>

//std
#include <sstream>

#pragma hdrstop
//------------------------------------------------------------------------------
#include "ModbusAdapter.h"
//------------------------------------------------------------------------------
// loki
//#include "loki\threads.h"
//------------------------------------------------------------------------------
#include "CRC16.h"
#include "bcd_.h"
#include "..\appcfg.h"
#include "AnsiStringUtils_.h"
#include "guicon.h"
#include "iniUtils_.h"
#include "CommSetsIOHelper.h"
//#include "MyTransferExcpt.hpp"
#include "TransferManage.h"
#include "FooCalledOnce.hpp"
#include "MasterSlaveIO.h"
//------------------------------------------------------------------------------
using std::cout;
using std::endl;

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// вывести массив в cout
AnsiString PrintVInt8( const VInt8& v, int lim = -1 )
{
    const unsigned maxIdx = (lim==-1) ? v.size() : std::min(lim, v.size() );
    return MyBuffToStr( v.begin(), v.begin() + maxIdx );
}
//------------------------------------------------------------------------------
bool IsModbusStr(const uInt8 *b, const uInt8 *e, uInt8 devAddr, uInt8 commandCode)
{
	return !(e-b<4) && b[0]==devAddr &&
    ( b[1]==commandCode || b[1]==( commandCode | 0x80 ) ) &&
    GetCRC16( b, e )==0;
}
//------------------------------------------------------------------------------
#define THROW_TRANSFER_EXCEPTION_(CNTXT, MSG)\
	throw PMyExcpt( new MyTransferException(TRANSFER_EXCEPTION::##CNTXT##,\
    __FILE_LINE__, MYSPRINTF_("%d: %s", addy, MSG) ) )
//------------------------------------------------------------------------------
void CheckModbusStr(ByteBuffPtr reciveBegin, ByteBuffPtr reciveEnd,
    unsigned addy, unsigned commandCode)
{
	if( addy==0) return;
	const int rxdLen = reciveEnd - reciveBegin;
    assert(rxdLen>=0);
    if( rxdLen==0 ) THROW_TRANSFER_EXCEPTION_( NO_ANSWER, "не отвечает" );
    if( rxdLen<4 )
    	THROW_TRANSFER_EXCEPTION_( LESS_THEN_4,
    		MYSPRINTF_(" длина ответа %s равна %d, должна быть не менее 4",
        		MyBuffToStr1( reciveBegin, reciveEnd ), rxdLen) );
    if( (unsigned)reciveBegin[0]!=addy )
    	THROW_TRANSFER_EXCEPTION_( ADDRESS_MISMATCH,
    		MYSPRINTF_("несовпадение адрессов запроса %d и ответа %d",
        		addy,  reciveBegin[0] ) ) ;
    const bool
        cmdCodeMatch = ( (unsigned)reciveBegin[1]==commandCode ),
        modbusError = ( (unsigned)reciveBegin[1]==( commandCode | 0x80 ) );

    if( !cmdCodeMatch && !modbusError )
        THROW_TRANSFER_EXCEPTION_( COMMAND_MISMATCH,
        	MYSPRINTF_("несовпадение кодов комманд запроса %d и ответа %d", commandCode, reciveBegin[1] ));

    if( GetCRC16( reciveBegin, reciveEnd )!=0 )
    	THROW_TRANSFER_EXCEPTION_( NOT_NULL_CRC16, "ненулевая контрольная сумма ответа");

    assert( IsModbusStr(reciveBegin, reciveEnd, addy, commandCode ) );
}
//------------------------------------------------------------------------------



//---------------------------------------------------------------------------
ModbusAdapter::ModbusAdapter(const MasterSlaveIOSettings &sets ) :
    masterSlaveIO_( new MasterSlaveIOImpl(sets) )
{
}
//------------------------------------------------------------------------------
ModbusAdapter::~ModbusAdapter()
{

}
//------------------------------------------------------------------------------
void ModbusAdapter::SetIOPort(MyPort *port)
{
    masterSlaveIO_->SetIOPort(port);
}
//------------------------------------------------------------------------------
// Передать txd, считать данные приёмника в rxd, вернуть длительность трансфера
void ModbusAdapter::PerformTransfer( unsigned addy,
    unsigned commandCode, ByteBuffPtr sendBegin, ByteBuffPtr sendEnd )
{   
	const int sendStrLen = sendEnd - sendBegin;
    assert(sendStrLen<10000);
    assert( commandCode!=3 || sendStrLen==4 );
	// подготовить посылку
    std::vector<uInt8> txd(sendEnd - sendBegin + 4);
    // формировать строку с адрессом и контрольной суммой CRC16
    txd[0] = addy;
    txd[1] = commandCode;
    std::copy( sendBegin, sendEnd, txd.begin()+2 );
    const short unsigned int crc16 = GetCRC16 ( txd.begin(), txd.end()-2 );
    *(txd.end()-2) = crc16 >> 8;
    *(txd.end()-1) = crc16;
    assert( IsModbusStr(txd.begin(), txd.end(), addy, commandCode) );

    const bool needAnswer = addy!=0;
    masterSlaveIO_->Send( txd.begin(), txd.end(), needAnswer );
    if( !needAnswer || masterSlaveIO_->IsTransferManagerWasStopedOrTerminated()  ) return;
    const unsigned rxdSize = masterSlaveIO_->RxDSize();
    if( rxdSize==0 )
        THROW_TRANSFER_EXCEPTION_( NO_ANSWER, "не отвечает" );

    const unsigned char *rxd = masterSlaveIO_->RxD(), *rxdEnd = rxd + rxdSize;

    // проверка корректности rxd_ - возбуждаются исключения
    CheckModbusStr( rxd, rxdEnd, addy, commandCode );

    if( rxdSize==5 && ( rxd[1] == (commandCode | 0x80) ) )
    {
    	if( commandCode==3 && rxd[2]==2 )
        {
        	const unsigned regAdr = (sendBegin[0]<<8) + sendBegin[1];
    		THROW_TRANSFER_EXCEPTION_( CMD3_ADDRESS_NOT_SUPPORTED,
            	MYSPRINTF_("команда 3, адрес регистра %d не допустим для данного прибора", regAdr ) );
        }

    	if( rxd[2]!=0 )
    		THROW_TRANSFER_EXCEPTION_( MODBUS_EXCEPTION,
            	MYSPRINTF_("исключительная ситуация %d.", rxd[2] ) );
    }

}
//------------------------------------------------------------------------------
unsigned ModbusAdapter::SentDataSize() const
{
    const unsigned txdSize = masterSlaveIO_->TxDSize();
    return txdSize>5 ? txdSize-4 : 0;
}
//------------------------------------------------------------------------------
const unsigned char* ModbusAdapter::SentData() const
{
    return masterSlaveIO_->TxDSize()>5 ? masterSlaveIO_->TxD()+2 : 0;
}
//------------------------------------------------------------------------------
unsigned ModbusAdapter::AcceptedDataSize() const
{
    const unsigned rxdSize = masterSlaveIO_->RxDSize();
    return rxdSize>5 ? rxdSize-4 : 0;
}
//------------------------------------------------------------------------------
const unsigned char* ModbusAdapter::AcceptedData() const
{
    return masterSlaveIO_->RxDSize()>5 ? masterSlaveIO_->RxD()+2 : 0;
}
//------------------------------------------------------------------------------
unsigned ModbusAdapter::Addy() const
{
    return masterSlaveIO_->RxDSize()>0 ? masterSlaveIO_->RxD()[0] : -1;
}
//------------------------------------------------------------------------------
unsigned ModbusAdapter::CommandCode() const
{
    return masterSlaveIO_->RxDSize()>1 ? masterSlaveIO_->RxD()[1] : -1;
}
//------------------------------------------------------------------------------






