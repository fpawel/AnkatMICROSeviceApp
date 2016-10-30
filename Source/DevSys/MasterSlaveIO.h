//------------------------------------------------------------------------------
#ifndef MasterSlaveIOH
#define MasterSlaveIOH
//------------------------------------------------------------------------------
//std
#include <vector>

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

// my
#include "..\my_include\MyPort.hpp"
#include "MasterSlaveIOSettings.hpp"
#include "MyExcpt.hpp"
//------------------------------------------------------------------------------
class MyNoAnswerException : public MyException
{
public:
    MyNoAnswerException(const FileLine& loc, const AnsiString& msg,
        const PMyExcpt nest = PMyExcpt() );
};
//------------------------------------------------------------------------------
class TransferManagerT;
namespace Inifiles
{
    class TIniFile;
};
//------------------------------------------------------------------------------
class MasterSlaveIOImpl : public boost::noncopyable
{

public:
    explicit MasterSlaveIOImpl( const MasterSlaveIOSettings &sets );
    ~MasterSlaveIOImpl();

    void Send(	const char* sendBegin, const char* sendEnd, bool needAnswer );

    const char* TxD() const;
    const char* RxD() const;
    unsigned TxDSize() const;
    unsigned RxDSize() const;
    bool IsTransferManagerWasStopedOrTerminated() const;

    void OpenPort();
    void ClosePort();
    void SetIOPort(MyPort* port);

private:
    const unsigned mainThreadId_;
	TransferManagerT& tmngr_;
    MyPort* port_;
    std::vector<char> rxd_, txd_;
    const MasterSlaveIOSettings& sets_;
    void SendTxD();

    void SendTxDAndGetAnswer();
    void LogOut( const AnsiString& );
};

//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

