//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop

#include "uPidl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
LPSHELLFOLDER DesktopFolder()
{
	static LPSHELLFOLDER ret = NULL;
    if( ret==NULL )
		SHGetDesktopFolder(&ret);
    return ret;
}
//---------------------------------------------------------------------------
PItemIDList StrToPidl(AnsiString path)
{
	if (path.Length()==0) return NULL;
    PItemIDList ret;
	unsigned long parsed;
	DesktopFolder()->ParseDisplayName(NULL,0,WideString(path).c_bstr(),
		&parsed,&ret,NULL);
	return ret;
}
//---------------------------------------------------------------------------
AnsiString PidlToStr(PItemIDList pidl)
{
	char buf[MAX_PATH];
	SHGetPathFromIDList(pidl,buf);
	return AnsiString(buf);
}
//---------------------------------------------------------------------------
int GetShellImage(const PItemIDList PIDL, bool Large, bool Open)
{
	TSHFileInfo FileInfo;
    memset(&FileInfo, 0, sizeof(FileInfo));
    SHGetFileInfo(
    reinterpret_cast<const char*>(PIDL), 0, &FileInfo, sizeof(FileInfo),
        SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_ICON | ( Large ? SHGFI_LARGEICON : SHGFI_SMALLICON) |
        (Open ? SHGFI_OPENICON : 0)
        );
    return FileInfo.iIcon;
}
//---------------------------------------------------------------------------
int GetShellImage(AnsiString fileName, bool Large, bool Open)
{
	const PItemIDList pidl = StrToPidl(fileName);
	if ( pidl )
    	return GetShellImage(pidl, Large, Open);
    else return -1;
}
//---------------------------------------------------------------------------
AnsiString GetDisplayName(LPSHELLFOLDER ShellFolder, PItemIDList pIdl, bool forParsing)
{
	TStrRet strRet;

    AnsiString* Result;
   	int flags = forParsing ? SHGDN_FORPARSING : SHGDN_NORMAL;
	ShellFolder->GetDisplayNameOf(pIdl, flags, &strRet);

    switch (strRet.uType)
    {
    	case STRRET_CSTR:
        	return AnsiString(strRet.cStr, strlen(strRet.cStr));
        case STRRET_OFFSET:
            return AnsiString( (PChar) &pIdl->mkid.abID[strRet.uOffset - sizeof(pIdl->mkid.cb)] );
        case STRRET_WSTR:
        	return AnsiString(strRet.pOleStr);
        default:
        	return "";
    }
}
//---------------------------------------------------------------------------
bool PidlIsFolder(LPSHELLFOLDER ShellFolder, PItemIDList ID)
{
        unsigned long Flags;
        bool Result;

        Flags = SFGAO_FOLDER;

        ShellFolder->GetAttributesOf(1, (const _ITEMIDLIST **) &ID, &Flags);
        Result = ((SFGAO_FOLDER & Flags) !=0 && (SFGAO_STREAM & Flags) ==0  );

        return Result;
}
//---------------------------------------------------------------------------
bool PidlHasSubFolder(LPSHELLFOLDER ShellFolder, PItemIDList ID)
{
	unsigned long Flags;
    bool Result;

    Flags = SFGAO_HASSUBFOLDER ;

    ShellFolder->GetAttributesOf(1, (const _ITEMIDLIST **) &ID, &Flags);
    Result = ((SFGAO_HASSUBFOLDER & Flags) !=0 && (SFGAO_STREAM & Flags) ==0  );

        return Result;
}
//---------------------------------------------------------------------------
unsigned long GetPidlAttrs(LPSHELLFOLDER ShellFolder, PItemIDList ID,
unsigned long attrs)
{
	ShellFolder->GetAttributesOf(1, (const _ITEMIDLIST **) &ID, &attrs);
    return attrs;

}
//---------------------------------------------------------------------------
LPSHELLFOLDER GetPidlShellFolder(const PItemIDList pIdl)
{
	LPSHELLFOLDER  ret = NULL;
	DesktopFolder()->BindToObject(pIdl, NULL, IID_IShellFolder, (void **)&ret);
    return ret;
}
//---------------------------------------------------------------------------
/*
void SHForEachSubItem( LPSHELLFOLDER fldr, ShellItemFoo foo )
{
	unsigned int
    flags = SHCONTF_FOLDERS | SHCONTF_NONFOLDERS | SHCONTF_INCLUDEHIDDEN;
    LPENUMIDLIST EnumList;
    unsigned long numIDs;

    TCursor  SaveCursor = Screen->Cursor;
    try
    {
    	Screen->Cursor = crHourGlass;
        fldr->EnumObjects( Application->Handle, flags, &EnumList);
        PItemIDList pId;
        while (EnumList->Next(1, &pId, &numIDs) == S_OK)
            foo(fldr,pId);

    }
    catch(...)
    {
		Screen->Cursor = SaveCursor;
    }
    Screen->Cursor = SaveCursor;
}
*/
//---------------------------------------------------------------------------

