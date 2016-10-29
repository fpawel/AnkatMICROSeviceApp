//---------------------------------------------------------------------------
#ifndef a7664adptH
#define a7664adptH
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


class MyA7664Exception : public MyException
{
public:
    MyA7664Exception(const FileLine& loc, const AnsiString& msg,
        const PMyExcpt nest = PMyExcpt() );
};

class MasterSlaveIOImpl;
namespace Inifiles
{
    class TIniFile;
};

class TransferManagerT;

class A7664Adpt : public boost::noncopyable
{
public:
    explicit A7664Adpt(MasterSlaveIOImpl &masterSlaveIO );
    ~A7664Adpt();
    void PerformTransfer( unsigned commandCode,
        ByteBuffPtr sendBegin, ByteBuffPtr sendEnd );

    const unsigned char* SentData() const;
    unsigned SentDataSize() const;
    const unsigned char* AcceptedData() const;
    unsigned AcceptedDataSize() const;

    unsigned CommandCode() const;


    typedef void (__closure *TOnNotifyEndTransfer )(unsigned state	);
    enum { GOT_CORRECT_ANSWER };

    void SetNotifyEndTransfer( TOnNotifyEndTransfer );

private:
    MasterSlaveIOImpl &masterSlaveIO_;

    TransferManagerT& tmngr_;
    boost::shared_ptr<void> connectOnTransferManagerReport_;
    TOnNotifyEndTransfer notifyEndTransfer_;
    unsigned char commandNumber_;

    void OnTransferManagerReport(unsigned context, const AnsiString& state);

};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

