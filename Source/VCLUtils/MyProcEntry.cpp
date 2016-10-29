#include <SysUtils.hpp>
#include <fstream>

//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "MyProcEntry.h"
#include "MyFileCtrl.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
#include "loki\singleton.h"





void GetWin32SystemSnapshot(ProcEntries& snapshot)
{
	boost::shared_ptr<void> doCreateToolhelp32Snapshot( ::CreateToolhelp32Snapshot(
    	TH32CS_SNAPPROCESS, 0), ::CloseHandle);

    void* hSnapshoot = doCreateToolhelp32Snapshot.get();
    PROCESSENTRY32 pe32 = {0};
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if( ::Process32First(hSnapshoot, &pe32)==FALSE ) return;
    	snapshot.push_back( pe32 );
    while ( ::Process32Next(hSnapshoot, &pe32)!=FALSE )
    	snapshot.push_back( pe32 );
}

bool IsUniqueAppInstance()
{
	const DWORD curProcId = ::GetCurrentProcessId();
	ProcEntries snapshot;
    GetWin32SystemSnapshot(snapshot);
    const AnsiString exeFN = ExtractFileName( ParamStr(0) );

    for( unsigned i=0; i<snapshot.size(); ++i )
    {
    	if( snapshot[i].th32ProcessID==curProcId &&
        	AnsiString(snapshot[i].szExeFile)!=exeFN )
        return false;
    }
    return true;
}
//------------------------------------------------------------------------------
// колличество запущенных экземпл€ров приложени€
unsigned ApplicationInstanceCount()
{
	const DWORD curProcId = ::GetCurrentProcessId();
	ProcEntries snapshot;
    GetWin32SystemSnapshot(snapshot);
    const AnsiString exeFN = ExtractFileName( ParamStr(0) );
    unsigned ret = 0;

    for( unsigned i=0; i<snapshot.size(); ++i )
    {
    	if( snapshot[i].th32ProcessID==curProcId &&
        	AnsiString(snapshot[i].szExeFile)==exeFN )
        	++ret;
    }
    return ret;
}
//------------------------------------------------------------------------------
// параметры командной строки
std::vector<AnsiString> MyExtractParamStr()
{
	std::vector<AnsiString> ret;
    AnsiString s = ParamStr(0);
    for( unsigned i=0; !s.IsEmpty(); s = ParamStr(++i) )
    	ret.push_back(s);
    return ret;
}
//------------------------------------------------------------------------------
AnsiString MakeMyParamStrF(const std::vector<AnsiString>& paramStr, char delim)
{
	AnsiString ret;
    for( unsigned i=1; i<paramStr.size(); ++i )
    	ret += (paramStr[i] +  delim);
    return ret;
}
//------------------------------------------------------------------------------


class MyParamStrT : public boost::noncopyable
{
public:
    explicit MyParamStrT() :
    	paramStr_( MyExtractParamStr() ),
        prmsStrF_( MakeMyParamStrF(paramStr_, ' ') )
    {}
    // параметры командной строки
	const std::vector<AnsiString> paramStr_;
    const AnsiString prmsStrF_;
};
//------------------------------------------------------------------------------
typedef Loki::SingletonHolder
    	<
    		MyParamStrT,
        	Loki::CreateUsingNew,
    		Loki::NoDestroy
    	> MyParamStr;


AnsiString FormatMyParamsStr()
{
	return  MyParamStr::Instance().prmsStrF_;
}
//------------------------------------------------------------------------------
// параметры командной строки
const std::vector<AnsiString>& MyGetParamStr()
{
	return  MyParamStr::Instance().paramStr_;
}
//------------------------------------------------------------------------------
bool MyParamStrHas( const AnsiString& s )
{
	const std::vector<AnsiString>& prms = MyGetParamStr();
    const std::vector<AnsiString>::const_iterator
    	beg = prms.begin(), end = prms.end(),
        fnd = std::find( beg, end, s );
    return fnd!=end;
}
//------------------------------------------------------------------------------

AnsiString ExtractFromComandPrompt(const AnsiString& strKey)
{

	AnsiString ret;
    // ѕ —ы
	const std::vector<AnsiString>& prms = MyGetParamStr();
    const std::vector<AnsiString>::const_iterator e = prms.end();
    
    const int lenKey = strKey.Length();

    for( std::vector<AnsiString>::const_iterator i=prms.begin(); i!=e; ++i)
    {
    	const AnsiString& prm = *i;
        const int len = prm.Length();
        if (len<lenKey+1)  continue;
        const int pos = prm.Pos(strKey);
    	if( pos!=0 )
        {
        	ret =  prm.SubString(lenKey+1, len-lenKey);
        	return ret;
        }
    }
    return "";
}



