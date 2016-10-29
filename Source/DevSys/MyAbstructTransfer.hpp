#ifndef MY_ABSTRUCT_TRANSFER_HEADER_INCLUDED_____
#define MY_ABSTRUCT_TRANSFER_HEADER_INCLUDED_____

//std
#include <utility>

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

//vcl
#include <system.hpp>

//my
#include "..\my_include\free_types_.h"


//------------------------------------------------------------------------------
class MyAbstructTransfer : public boost::noncopyable
{
public:
    virtual ~MyAbstructTransfer() {}
    virtual AnsiString What() const { return " "; }

	// Обработка события начала трансфера. Возвращает - выполнять/не выполнять
	virtual bool HandleBeginTransfer() { return true; }

    // Обработка события окончания трансфера. Возвращает - повторить/не повторять
	virtual bool HandleEndTransfer() = 0;

	// выполнить. Если вернёт установит mustStopThred в true, остановить поток
    virtual void Perform() = 0;
};
//------------------------------------------------------------------------------

class NamedTransfer : public MyAbstructTransfer
{
public:
    explicit NamedTransfer(const AnsiString& what) : what_(what) {}
    virtual ~NamedTransfer() {}
	virtual AnsiString What() const { return what_; }
private:
    const AnsiString what_;
};
//------------------------------------------------------------------------------
typedef boost::shared_ptr<MyAbstructTransfer> PTransfer;
typedef std::vector< PTransfer > ScenaryList;






#endif