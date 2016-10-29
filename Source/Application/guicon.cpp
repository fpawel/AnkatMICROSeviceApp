//---------------------------------------------------------------------------
// win
#include <windows.h>
#include <wincon.h>
//std
#include <stdio>
#include <fstream>
#include <utility>

//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "guicon.h"

// my
#include "..\my_include\win\MyModFN.hpp"
#include "..\my_include\FooCalledOnce.hpp"
#include "MyFileCtrl.h"
#include "AnsiStringUtils_.h"
#include "..\my_include\win\WinErr.hpp"


//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------





////////////////////////////////////////////////////////////////////////////////
	std::pair<unsigned,unsigned> GetOrders()
    {
   		CONSOLE_SCREEN_BUFFER_INFO lConsoleScreenBufferInfo;
   		GetConsoleScreenBufferInfo( GetStdHandle(STD_OUTPUT_HANDLE), &lConsoleScreenBufferInfo );
        return std::make_pair( lConsoleScreenBufferInfo.dwSize.X,
        	lConsoleScreenBufferInfo.dwSize.Y);
    }

    //  control signal type
    BOOL WINAPI HandlerRoutine( const DWORD dwCtrlType)
    {
        const bool isCtrlBreakEvent =
            (dwCtrlType==CTRL_BREAK_EVENT	|| dwCtrlType==CTRL_C_EVENT);
        if( !isCtrlBreakEvent )
            return FALSE;
        printf( "\n\t\t---Ctrl+Break pressed!---\n" );
        return TRUE;
    }
	//--------------------------------------------------------------------------
    
	void InitializeGUIConsole()
	{
        std::fclose(stdin);
        std::fclose(stderr);
    	std::fclose(stdout);
        std::freopen("CONIN$", "r", stdin);
        std::freopen("CONOUT$", "w", stderr);
    	std::freopen("CONOUT$", "w", stdout);
        std::system("MODE CON COLS=80");
    	std::system("MODE CON LINES=9999");
    	std::system("MODE CON CP SELECT=866");
        printf( "GUI CON initialized.\n" );
	}
    //--------------------------------------------------------------------------
    void SaveConsoleToFile(const AnsiString& fn)
	{
        MyForceDirectory( ExtractFilePath(fn) );

		struct FindEndNotSpace
    	{
    		char* operator()( char *b, char *e ) const
			{
				while( (*(e-1)==' ' || *(e-1)=='\0' || *(e-1)=='\t') && --e!=b ) ;
    			return e;
			}
    	};
		const HANDLE hStdout = ::GetStdHandle(STD_OUTPUT_HANDLE);
   		DWORD cWritten;

   		COORD coordBufSize, coordBufCoord;
   		SMALL_RECT srctReadRect;
   		CONSOLE_SCREEN_BUFFER_INFO lConsoleScreenBufferInfo;

   		// Get the screen buffer information and set the rectangles
   		if( GetConsoleScreenBufferInfo( hStdout, &lConsoleScreenBufferInfo )==FALSE )
        	return;

   		const int
    		szX = lConsoleScreenBufferInfo.dwSize.X,
    		szY = lConsoleScreenBufferInfo.dwSize.Y;

   		std::vector<char> lineBuff( szX+1 );

   		DWORD numberOfCharsRead;

        ::SetLastError(0);
    	std::ofstream logCout( fn.c_str() );
        if( !logCout.is_open() )
        {
        	ShowLastWindowsError();
            return;
        }

    	COORD rdCrd;
    	for( rdCrd.Y = 0; rdCrd.Y<szY; ++rdCrd.Y )
    	{
        	rdCrd.X = 0;
            char *pBuff = &*lineBuff.begin()
            //, pBuffEnd = &*lineBuff.end()
            ;
        	::ReadConsoleOutputCharacter
        	(
    			hStdout,			// handle of a console screen buffer
    			pBuff,			    // address of buffer to receive characters
    			szX,				// number of character cells to read from
    			rdCrd,				// coordinates of first cell to read from
    			&numberOfCharsRead 	// address of number of cells read from
   			);
            char *lineBuffEnd = FindEndNotSpace()( lineBuff.begin(), lineBuff.end() );
            *lineBuffEnd = '\0';
            const unsigned cchDstLength = lineBuffEnd - &*lineBuff.begin();

            if( cchDstLength==0 ) continue;

            std::vector<char> translatedBuff( cchDstLength+1 );
            char *pTranslatedBuff = &*translatedBuff.begin();

            ::OemToCharBuff
            (
                pBuff,	                    // pointer to string to translate
                pTranslatedBuff,	        // pointer to buffer for translated string
                cchDstLength  	            // size of buffer
            );

        	logCout << pTranslatedBuff << std::endl;
    	}
    	logCout.close();
	}
//------------------------------------------------------------------------------
class GUIConsole : public boost::noncopyable
{
public:
    void InitializePaths();
    void Create();
    void Redirect();
    bool IsCreated() const { return isCreated_; }
    bool IsRedirected() const  { return isRedirected_; }
    void Backup();

    static GUIConsole& Instance()
    {
    	static GUIConsole* pRet = NULL;
        if(pRet==NULL) pRet = new GUIConsole;
        return *pRet;
    }

private:
    bool isCreated_;
    bool isRedirected_;
    AnsiString logDir_, logFn_, logArchiveFileName_;

     explicit GUIConsole();
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
GUIConsole::GUIConsole() :
	isCreated_(false), isRedirected_(false)
{
    // проверка уникальности вызова функции
    ASSERT_FUNCTION_CALLED_ONCE__;
    Create();
}
//------------------------------------------------------------------------------
void GUIConsole::InitializePaths()
{
	static bool isInitialized = 0;
    if(isInitialized) return;
	logDir_ =  MyGetExePath()+"\\Log" ;
    logFn_ = logDir_+"\\STDOUT.LOG";
    logArchiveFileName_ = "log.rar";
    MyForceDirectory(logDir_);
    isInitialized = 1;
}
//------------------------------------------------------------------------------
void GUIConsole::Create()
{
    if( isCreated_ ) return;

    InitializePaths();

    ::AllocConsole();
    const HWND
        hWnd_ = ::GetConsoleWindow(),
        hMenu_ = ::GetSystemMenu(hWnd_, FALSE);
    // удалить меню "закрыть"
    ::DeleteMenu(hMenu_, SC_CLOSE, MF_BYCOMMAND);
    // скрыть окно консоли
    ::ShowWindow(hWnd_, SW_HIDE);
    ::SetConsoleCtrlHandler( HandlerRoutine, TRUE);

    InitializeGUIConsole();
    isCreated_ = true;
    isRedirected_ = false;

}
//------------------------------------------------------------------------------
void GUIConsole::Redirect()
{
	InitializePaths();
    
    std::fclose(stdout);
    std::freopen(logFn_.c_str(), "w+", stdout);

    if(isCreated_)
    {
    	::FreeConsole();
        isCreated_ = false;

    }
    isRedirected_ = true;
    printf( "CON redirected to file.\n" );
}
//------------------------------------------------------------------------------
void GUIConsole::Backup()
{
	if( !(IsCreated() || IsRedirected() ) ) return;

    // сохранить содержимое консоли
    if( IsRedirected() ) std::fclose(stdout); else
    if( IsCreated() ) SaveConsoleToFile( logFn_ );

    // архивироваить логфайл
    const AnsiString
    	logFileNameAsDate_ = logDir_ + "\\"+ DateToFilename( Now() ) + ".log";

    PerformRARArchivation( logFn_, DateToPath( Now() )+"\\"+DateToFilename( Now() ) + ".log",
        logArchiveFileName_  );

    if( IsRedirected() ) Redirect();
}
//------------------------------------------------------------------------------
void CreateGUIConsole()
{
    GUIConsole& guiCon = GUIConsole::Instance();
    guiCon.Create();
}
//------------------------------------------------------------------------------
void SaveGUIConsoleToFile()
{
    GUIConsole::Instance().Backup();
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
void MyWriteConsole(const wchar_t* str, DWORD nNumberOfCharsToWrite)
{
    DWORD lpNumberOfCharsWritten  = 0;
    ::WriteConsoleW( ::GetStdHandle(STD_OUTPUT_HANDLE), (const void*) str,
    	nNumberOfCharsToWrite, &lpNumberOfCharsWritten, NULL);
}
//------------------------------------------------------------------------------
void MyWCout(const AnsiString& str)
{
	GUIConsole& inst =  GUIConsole::Instance();
    if( inst.IsRedirected() )
        std::cout << str.c_str();
    else if( inst.IsCreated() )
    {
        WideString s = str;
        const DWORD nNumberOfCharsToWrite = s.Length();
        MyWriteConsole( s.c_bstr(), nNumberOfCharsToWrite );
    }
}
//------------------------------------------------------------------------------
void MyWCout(const AnsiString& str, IncExcAttr inc_exc )
{
    const ConsoleScreenAtrributesHolder obj(inc_exc);
    MyWCout( str );
}
//------------------------------------------------------------------------------
void MyWCoutTime(const AnsiString& str, IncExcAttr inc_exc  )
{
    const ConsoleScreenAtrributesHolder obj(inc_exc);
    MYWCOUT_( "<%s> %s\n", TimeToStr( Time() ), str ));
}
//------------------------------------------------------------------------------
TemporaryRedirectConsole::TemporaryRedirectConsole( const AnsiString& fn) //: fn_(fn)
{
    std::freopen(fn.c_str(), "w+", stdout);
}
TemporaryRedirectConsole::~TemporaryRedirectConsole()
{
    std::freopen("CONOUT$", "w", stdout);

    /*
    // извлечь содержимое входного файла в буффер buff
	std::ifstream ifstrm( fn_.c_str() );
    AutoCloseFileStreamHelper<std::ifstream> acf(ifstrm);
    std::string s;
    while( std::getline(ifstrm, s) )
        MyWCout( AnsiString(s.c_str())+"\n"  );
    ifstrm.close();
    */
}
//------------------------------------------------------------------------------
ConsoleScreenAtrributesHolder::ConsoleScreenAtrributesHolder(IncExcAttr inc_exc)
{
    HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi = {0};
    ::GetConsoleScreenBufferInfo( hConsoleOutput,  &csbi );
    attrs_ = csbi.wAttributes;
    ::SetConsoleTextAttribute(hConsoleOutput, (attrs_ | inc_exc.first ) & ~inc_exc.second );
}
//------------------------------------------------------------------------------
ConsoleScreenAtrributesHolder::~ConsoleScreenAtrributesHolder()
{
    ::SetConsoleTextAttribute( ::GetStdHandle(STD_OUTPUT_HANDLE), attrs_ );
}
//------------------------------------------------------------------------------
ConsoleMultioutputHelper::ConsoleMultioutputHelper()
{
    CONSOLE_SCREEN_BUFFER_INFO lConsoleScreenBufferInfo_ = {0};
    hCon_ = ::GetStdHandle(STD_OUTPUT_HANDLE);
    ::GetConsoleScreenBufferInfo( hCon_, &lConsoleScreenBufferInfo_ );
    pos0_ = lConsoleScreenBufferInfo_.dwCursorPosition;
    curWriteConsoleCount_ = 0;
}
//------------------------------------------------------------------------------
void ConsoleMultioutputHelper::Set(const AnsiString& s)
{
    CONSOLE_SCREEN_BUFFER_INFO lConsoleScreenBufferInfo_ = {0};
    ::GetConsoleScreenBufferInfo( hCon_, &lConsoleScreenBufferInfo_ );
    const COORD pos = lConsoleScreenBufferInfo_.dwCursorPosition;

    if( curWriteConsoleCount_!=0 )
    {
        ::SetConsoleCursorPosition( hCon_, pos0_);
        MyWCout( AnsiString::StringOfChar(' ', curWriteConsoleCount_) );
        ::SetConsoleCursorPosition( hCon_, pos0_);
    }
    MyWCout(s);
    curWriteConsoleCount_ = s.Length();
    ::SetConsoleCursorPosition( hCon_, pos);
}
//------------------------------------------------------------------------------



    MyConQuote::MyConQuote( const AnsiString& s ) :  s_(s)
    {
    	MyWCout( "<" + s_ + ">\n");

    }
    MyConQuote::~MyConQuote()
    {
    	MyWCout( "<\\" + s_ + ">\n");
    }

