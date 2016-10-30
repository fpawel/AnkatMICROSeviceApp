//---------------------------------------------------------------------------
#ifndef ModbusAdapterH
#define ModbusAdapterH
//---------------------------------------------------------------------------
//std

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

// my
#include "..\my_include\free_types_.h"
#include "..\my_include\MyPort.hpp"
#include "MasterSlaveIOSettings.hpp"
#include "MyExcpt.hpp"

class MasterSlaveIOImpl;
namespace Inifiles
{
    class TIniFile;
};


class ModbusException : public MyException
{
public:
    ModbusException(const FileLine& loc, const AnsiString& msg,
        const PMyExcpt nest = PMyExcpt() );
};

class ModbusAdapter : public boost::noncopyable
{
public:
    explicit ModbusAdapter(const MasterSlaveIOSettings &sets );
    ~ModbusAdapter();
    // �������� txd, ������� ������ �������� � rxd,
    // ������� GetCRC16(rxd)==0
    void PerformTransfer( unsigned addy, unsigned commandCode,
        ByteBuffPtr sendBegin, ByteBuffPtr sendEnd );

    const unsigned char* SentData() const;
    unsigned SentDataSize() const;
    const unsigned char* AcceptedData() const;
    unsigned AcceptedDataSize() const;

    unsigned Addy() const;
    unsigned CommandCode() const;

    typedef void (__closure *TOnNotifyEndTransfer )(unsigned state	);
    enum { GOT_CORRECT_ANSWER };

    void SetNotifyEndTransfer( TOnNotifyEndTransfer );
    void SetIOPort(MyPort *port);

private:
    boost::shared_ptr<MasterSlaveIOImpl> masterSlaveIO_;
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

