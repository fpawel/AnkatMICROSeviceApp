#ifndef MY_PROCESSES_INFORMATION_EXTRACT_HEADER_INCLUDED__________
#define MY_PROCESSES_INFORMATION_EXTRACT_HEADER_INCLUDED__________


//boost
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"

#include <vector>
#include "MyModFN.hpp"
#include <Tlhelp32.h>

typedef std::vector<PROCESSENTRY32> MyProcEntries;

void GetWin32SystemSnapshot(MyProcEntries& snapshot)
{
	boost::shared_ptr<void> doCreateToolhelp32Snapshot( ::CreateToolhelp32Snapshot(
    	TH32CS_SNAPPROCESS, 0), ::CloseHandle);

    void* hSnapshoot = doCreateToolhelp32Snapshot.get();
    PROCESSENTRY32 pe32 = {0};
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if( ::Process32First(hSnapshoot, &pe32)==FALSE )
    	return;
    snapshot.push_back( pe32 );
    while ( ::Process32Next(hSnapshoot, &pe32)!=FALSE )
    	snapshot.push_back( pe32 );
}

bool IsUniqueAppInstance()
{
	const DWORD curProcId = ::GetCurrentProcessId();
	MyProcEntries snapshot;
    GetWin32SystemSnapshot(snapshot);
    const AnsiString exeFN = MyGetExeName();

    for( unsigned i=0; i<snapshot.size(); ++i )
    {
    	const AnsiString modFN = snapshot[i].szExeFile;
    	if( snapshot[i].th32ProcessID!=curProcId && modFN==exeFN )
        	return false;
    }
    return true;
}





#endif