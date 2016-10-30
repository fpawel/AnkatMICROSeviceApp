//------------------------------------------------------------------------------
#ifndef ctrlsysH
#define ctrlsysH
//------------------------------------------------------------------------------
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"
//------------------------------------------------------------------------------
#include "MyNoDestroySingleton.hpp"
#include "MyAbstructTransfer.hpp"
//------------------------------------------------------------------------------

class TransferManagerT;
class A7664Adpt;
class ModbusAdapter;

class CtrlSysImpl : public boost::noncopyable
{
public:
    explicit CtrlSysImpl();
    void SetupDialog();

    A7664Adpt& GetA7664Adpt();
    ModbusAdapter& Modbus();

    void AddInitializeTask();
    
    bool MustShowFlasLog() const;

private:
    class Impl;
    boost::shared_ptr<Impl> impl_;
};

struct CtrlSysTag {};
typedef MyNoDestroySingletonHolder<CtrlSysImpl, CtrlSysTag> CtrlSys;


//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
