//---------------------------------------------------------------------------

#ifndef uPidlH
#define uPidlH
//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <comObj.hpp>
#include <ShellAPI.h>
#include <Shlobj.hpp>

//#include "Loki\Functor.h"

LPSHELLFOLDER DesktopFolder();
PItemIDList StrToPidl(AnsiString path);
AnsiString PidlToStr(PItemIDList pidl);

int GetShellImage(const PItemIDList PIDL, bool Large, bool Open);
int GetShellImage(AnsiString fileName, bool Large, bool Open);

AnsiString GetDisplayName(LPSHELLFOLDER ShellFolder, PItemIDList pIdl, bool forParsing);

bool PidlIsFolder(LPSHELLFOLDER ShellFolder, PItemIDList ID);
bool PidlHasSubFolder(LPSHELLFOLDER ShellFolder, PItemIDList ID);
unsigned long GetPidlAttrs(LPSHELLFOLDER ShellFolder, PItemIDList ID,
unsigned long attrs = SFGAO_FOLDER | SFGAO_HASSUBFOLDER);

LPSHELLFOLDER GetPidlShellFolder(const PItemIDList PIDL);

//void SHForEachSubItem( LPSHELLFOLDER fldr, ShellItemFoo foo );

#endif
