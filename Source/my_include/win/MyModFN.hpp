#ifndef MY_GET_MODULE_FILE_NAME_HEADER_INCLUDED__________
#define MY_GET_MODULE_FILE_NAME_HEADER_INCLUDED__________

#include <system.hpp>
#include <windows>

AnsiString MyExtractFileName( const AnsiString& path )
{
	char lpBuffer[MAX_PATH],  *lpFilePart = NULL;
	GetFullPathName( path.c_str(),  MAX_PATH-1, lpBuffer, &lpFilePart);
	lpBuffer[MAX_PATH-1] = '\0';
	return lpFilePart==NULL ? AnsiString("") : AnsiString( lpFilePart );
}

AnsiString MyExtractFilePath( const AnsiString& path )
{
	char lpBuffer[MAX_PATH],  *lpFilePart = NULL;
	GetFullPathName( path.c_str(),  MAX_PATH-1, lpBuffer, &lpFilePart);
	lpBuffer[MAX_PATH-1] = '\0';
	return lpFilePart==NULL ? AnsiString(lpBuffer) :
    AnsiString( static_cast<const char*>(lpBuffer), static_cast<unsigned int>(lpFilePart-lpBuffer) );
}

AnsiString MyGetExeFileName()
{
	char lpFilename[MAX_PATH];
	const DWORD len=::GetModuleFileName( NULL, lpFilename, MAX_PATH );
    lpFilename[MAX_PATH-1] = '\0';
    return len==0 ? "" : lpFilename;
}

AnsiString MyGetExePath()
{
	return MyExtractFilePath( MyGetExeFileName() );
}

AnsiString MyGetExeName()
{
	return MyExtractFileName( MyGetExeFileName() );
}



#endif