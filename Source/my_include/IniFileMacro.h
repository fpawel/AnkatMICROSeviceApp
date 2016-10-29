#ifndef MY_NONDELETEABLE_INIFILE_MACROS_HEADER_INCLUDED__________
#define MY_NONDELETEABLE_INIFILE_MACROS_HEADER_INCLUDED__________

#include <inifiles.hpp>
#include "MyModFN.hpp"

TIniFile *MyCreateIni( const AnsiString& filename)
{
    return new TIniFile( MyGetExePath()+filename );
}

#define DEFINE_NONDELETEABLE_INIFILE_EX_( nname, filename )\
TIniFile* Ini##nname##()\
{\
	static TIniFile* ret = NULL;\
    if(ret==NULL)\
    	ret = MyCreateIni( filename );\
    return ret;\
}

#endif