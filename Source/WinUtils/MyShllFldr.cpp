//---------------------------------------------------------------------------


#pragma hdrstop

#include "MyShllFldr.h"
#include "uPidl.h"

#include <shlobj.hpp>
#include "MyModFN.hpp"

//---------------------------------------------------------------------------

#pragma package(smart_init)


bool MySHBrowseForFolder( void* hwndOwner, char* title, char *result )
{
	BROWSEINFO bi = {0};
    bi.hwndOwner = hwndOwner;
    bi.lpszTitle = title;
    bi.pszDisplayName = result;
    bi.ulFlags = BIF_NEWDIALOGSTYLE |
        BIF_RETURNFSANCESTORS |
        BIF_SHAREABLE |
		BIF_STATUSTEXT |
		BIF_UAHINT |
        0;
    LPITEMIDLIST resPidl = ::SHBrowseForFolder(&bi);
    return  (resPidl==NULL )  ? FALSE : ::SHGetPathFromIDList( resPidl, result);

}

namespace ShllFldr
{

bool GetLocation( int nFolder, char *pBuff )
{
	ITEMIDLIST idl;
    LPITEMIDLIST pidl = &idl;
    if( ::SHGetFolderLocation(NULL, nFolder, NULL, NULL, &pidl)!=S_OK ) return FALSE;
    return ::SHGetPathFromIDList( pidl, pBuff);
}

AnsiString Path(int nFolder)
{
    char fileName[MAX_PATH+1];
	GetLocation( nFolder, fileName );
    fileName[MAX_PATH] = '\0';
    return AnsiString(fileName);

}


}; // namespace ShllFldr
//------------------------------------------------------------------------------
AnsiString MyAppDirName()
{
    return "\\Filimonenkow_Pawel\\Applications\\"+ChangeFileExt( MyGetExeName(), "")+"\\"; 
}
//------------------------------------------------------------------------------
AnsiString GetPersonalDir()
{
    return ShllFldr::Path(ShllFldr::PERSONAL)+MyAppDirName();
}
//------------------------------------------------------------------------------
AnsiString GetAppDataDir()
{
    return ShllFldr::Path(ShllFldr::APPDATA)+MyAppDirName();
}



