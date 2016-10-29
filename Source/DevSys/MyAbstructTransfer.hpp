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

	// ��������� ������� ������ ���������. ���������� - ���������/�� ���������
	virtual bool HandleBeginTransfer() { return true; }

    // ��������� ������� ��������� ���������. ���������� - ���������/�� ���������
	virtual bool HandleEndTransfer() = 0;

	// ���������. ���� ����� ��������� mustStopThred � true, ���������� �����
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