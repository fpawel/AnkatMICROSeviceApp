//------------------------------------------------------------------------------
#include <cassert>
//------------------------------------------------------------------------------

#pragma hdrstop

#include "winrc.h"

#include <windows.h>

//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------

RecourceBufferT MyGetResource( const char *name, const char *type )
{
	const HRSRC hRes = ::FindResource(NULL, name, type );
    assert(hRes != NULL);
    const DWORD resSz = ::SizeofResource( NULL, hRes);
    const HRSRC hResLoad = ::LoadResource( NULL, hRes );
    assert(hResLoad != NULL);
    void *lpResLock = ::LockResource(hResLoad);
    assert(lpResLock != NULL);
    return std::make_pair(lpResLock,resSz);
}
