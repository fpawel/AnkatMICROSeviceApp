#ifndef RS485AdapterH
#define RS485AdapterH

//std
#include <vector>

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

// my
#include "..\my_include\MyPort.hpp"
#include "MasterSlaveIOSettings.hpp"
#include "MasterSlaveIO.h"
#include "MyExcpt.hpp"


class RS485Adapter : public boost::noncopyable
{

public:
    struct State { enum { START, END, NO_ANSWER }; };

    explicit RS485Adapter(const MasterSlaveIOSettings &sets, MyPort *port );
    virtual ~RS485Adapter() {}
    // Передать txd, считать данные приёмника в rxd,
    // вернуть GetCRC16(rxd)==0
    void PerformTransfer( unsigned addy, unsigned commandCode,
        const unsigned char* sendBegin, const unsigned char* sendEnd, unsigned timeOut=-1 );

    virtual const unsigned char* SentData() const = 0;
    virtual unsigned SentDataSize() const = 0;
    virtual const unsigned char* AcceptedData() const = 0;
    virtual unsigned AcceptedDataSize() const = 0;

    virtual unsigned Addy() const = 0;
    virtual unsigned CommandCode() const = 0;

    virtual void PrepareTxD( std::vector<unsigned char>& txd, unsigned addy,
        unsigned cmdCode, const unsigned char* sendBegin, const unsigned char* sendEnd) = 0;

    typedef LRESULT (__closure *TOnNotifyState )(const RS485Adapter* thiS, unsigned state);
    void SetNotifyState( TOnNotifyState );

    bool IsNotAnsweredAddy(unsigned addy) const ;

    const MasterSlaveIOImpl& MasterSlave() const;

private:

    boost::shared_ptr<MasterSlaveIOImpl> masterSlaveIO_;
    TOnNotifyState notifyState_;
    TransferManagerT& tmngr_;
    boost::shared_ptr<void> connectOnTransferManagerReport_;
    bool notAnswered_[256], answered_[256];

    void OnTransferManagerReport(unsigned context, const AnsiString& state);
    void SetAddy(unsigned char addy, bool isAnswered);

    
    void SetSignalState(unsigned);

    virtual void CheckCorrectAnswer(const unsigned char* reciveBegin,
        const unsigned char* reciveEnd ) = 0;
};

#endif
