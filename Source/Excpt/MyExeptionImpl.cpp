//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <exception>
#include <vector>
#include <typeinfo>
#include <string>
#include <fstream>

#include <windows.h>
#include <wininet.h>             
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "MyExeptionImpl.h"

//my
#include "MyWinExcpt.hpp"
#include "..\my_include\win\WinErr.hpp"
#include "AnsiStringUtils_.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace Private
{
    FileLine ExtractFileLine( unsigned line, const char* fileName )
    {
        return std::make_pair( line, ExtractFileName(fileName) );
    }
};
//---------------------------------------------------------------------------
// Определение MyException
//---------------------------------------------------------------------------
MyException::MyException(const FileLine& loc, const AnsiString& msg,
	PMyExcpt nest) : location_(loc), message_(msg), nested_(nest)
{
}
//---------------------------------------------------------------------------
AnsiString MyException::ClassName() const
{
	return "MyException";
}
//---------------------------------------------------------------------------
const FileLine& MyException::Location() const
{
    return location_;
}
//---------------------------------------------------------------------------
const AnsiString& MyException::Message() const
{
    return message_;
}
//---------------------------------------------------------------------------
const MyException* MyException::Nested() const
{
    return nested_.get();
}
//---------------------------------------------------------------------------
const MyException* MyException::Root() const
{
    const MyException* ret=this;
    for ( ; ret->Nested(); ret=ret->Nested() );
    return ret;
}
//---------------------------------------------------------------------------
AnsiString MyException::ToString() const
{
    return AnsiString().sprintf("%s %d %s", location_.second, location_.first, message_);
}
//---------------------------------------------------------------------------
AnsiString MyException::ToStringAll() const
{
	AnsiString ret = "";

	for (const MyException* ptr=this; ptr; ptr=ptr->nested_.get())
	    ret = ret + ptr->ToString() + (ptr->nested_ ? "\n" : " ") ;
	return ret;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
AnsiString MyWindowsException::ClassName() const{ return "MyWindowsException";}
//------------------------------------------------------------------------------
AnsiString MyWindowsException::MakeMsg(const AnsiString& msg, unsigned long int code)
{
    code_ = code;
	assert(code && "Попытка возбудить исключение Windows при нулевом коде ошибки!");
    const AnsiString s = AnsiString().sprintf("%s %s",
    WindowsErrorCodeToStr( code ).c_str(), msg.c_str() );
    return s.c_str();
}

//---------------------------------------------------------------------------
MyWindowsException::MyWindowsException(unsigned long int code, const FileLine& loc,
	const AnsiString& msg, PMyExcpt nest) :
    MyException(loc, MakeMsg(msg,code), nest)
{}

MyWindowsException::MyWindowsException(const FileLine& loc,
	const AnsiString& msg, PMyExcpt nest) :
    MyException(loc, MakeMsg(msg, ::GetLastError() ), nest)
{}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
AnsiString FormatMyException( const MyException* excpt,
    const AnsiString& format )
{
    AnsiString ret = format;
    ret = ReplaceSubstring( ret, "%eClass", excpt->ClassName() );
    ret = ReplaceSubstring( ret, "%eMsg", excpt->Message() );
    ret = ReplaceSubstring( ret, "%eFile", excpt->Location().first );
    ret = ReplaceSubstring( ret, "%eLine", excpt->Location().second );
    return ret;
}
//------------------------------------------------------------------------------

/*
AnsiString FormatMyException( const MyException* excpt )
{
    return AnsiString().sprintf("%s %d %s", excpt->Location().second,
        excpt->Location().first, excpt->Message() );
}
*/
//------------------------------------------------------------------------------
AnsiString FormatMyExceptionMessages( const MyException* excpt,
    const AnsiString& delim, const AnsiString& format )
{
    AnsiString ret = "";
    unsigned st = 0;
	for ( ; excpt; excpt=excpt->Nested() )
    {
	    ret = ret + FormatMyException(excpt, format);
        if( excpt->Nested() ) ret = ret + delim;
    }
	return ret;
}


//------------------------------------------------------------------------------

PMyExcpt RethrowMyException(const FileLine& location)
{
	try
	{
		throw;
	}
	catch (PMyExcpt ce)
	{
	   return ce;
	}
	catch (const std::exception& e)
	{
        const AnsiString s = AnsiString(typeid(e).name()) + ":" + e.what();
        return  MyExcptionFactory::Create<MyStdException>(location, s );
	}
    catch (const AnsiString& s)
	{
        return  MyExcptionFactory::Create<MyException>(location, s );
	}
    catch (const std::string& s)
	{
        return  MyExcptionFactory::Create<MyException>(location, s.c_str() );
	}

    catch (const EAccessViolation& e)
	{   
        return  MyExcptionFactory::Create<MyAccessViolationException>(location,
            "Нарушение границ области памяти модуля" );
    }

    catch (const Exception& e)
	{
#pragma warn -ncf
        const AnsiString s = AnsiString(e.ClassName()) + ":" + e.Message;
        return  MyExcptionFactory::Create<MyVCLException>(location, s );
#pragma warn +ncf
	}
	catch (...)
	{
    	return MyExcptionFactory::Create<MyUnknownException>(location, "Unknown exception" );
	}
}
//---------------------------------------------------------------------------

