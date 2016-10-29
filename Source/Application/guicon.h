//---------------------------------------------------------------------------
#ifndef guiconH
#define guiconH
//---------------------------------------------------------------------------
#include "MyIostream.h"


// windows
#include <basetsd.h>

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

//std
#include <sstream>
#include <utility>
//------------------------------------------------------------------------------
#define MYWCOUT_ MyWCout( AnsiString().sprintf
//------------------------------------------------------------------------------
void MyWriteConsole(const wchar_t* str, DWORD nNumberOfCharsToWrite);
void MyWCout(const AnsiString& str );    
typedef std::pair<WORD,WORD> IncExcAttr;
void MyWCout(const AnsiString& str, IncExcAttr inc_exc );
void MyWCoutTime(const AnsiString& str, IncExcAttr inc_exc = IncExcAttr() );
void CreateGUIConsole();
void SaveGUIConsoleToFile();
//------------------------------------------------------------------------------
const IncExcAttr
    MY_SET_CONSOLE_VELVET_TEXT( FOREGROUND_BLUE  | FOREGROUND_RED | FOREGROUND_INTENSITY, FOREGROUND_GREEN),
    MY_SET_CONSOLE_AQUA_TEXT( FOREGROUND_BLUE  | FOREGROUND_GREEN | FOREGROUND_INTENSITY, FOREGROUND_RED),
    MY_SET_CONSOLE_BLUE_TEXT( FOREGROUND_BLUE | FOREGROUND_INTENSITY, FOREGROUND_RED | FOREGROUND_GREEN ),
    MY_SET_CONSOLE_RED_TEXT( FOREGROUND_RED  | FOREGROUND_INTENSITY, FOREGROUND_BLUE | FOREGROUND_GREEN),
    MY_SET_CONSOLE_YELLOW_TEXT( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, FOREGROUND_BLUE );
//------------------------------------------------------------------------------
class ConsoleScreenAtrributesHolder : public boost::noncopyable
{
public:
    explicit ConsoleScreenAtrributesHolder(IncExcAttr inc_exc);
    ~ConsoleScreenAtrributesHolder();
private:
    WORD attrs_;
};
//------------------------------------------------------------------------------
class ConsoleMultioutputHelper : public boost::noncopyable
{
public:
    explicit ConsoleMultioutputHelper();
    void Set(const AnsiString& s);
private:
    HANDLE hCon_;
    COORD pos0_;
    unsigned curWriteConsoleCount_;
};
//------------------------------------------------------------------------------


class MyConQuote : public boost::noncopyable
{
public:
	MyConQuote( const AnsiString& s );
    ~MyConQuote();
private:
	const AnsiString s_;
};
#ifdef _DEBUG
#define LOG_MY_CON_QUOTES(s) const MyConQuote qteCout( s )
#else
#define LOG_MY_CON_QUOTES(s)
#endif

//------------------------------------------------------------------------------
class TemporaryRedirectConsole : public boost::noncopyable
{
public:
    explicit TemporaryRedirectConsole(const AnsiString& fn);
    ~TemporaryRedirectConsole();
};
//---------------------------------------------------------------------------


#endif
//---------------------------------------------------------------------------




