//---------------------------------------------------------------------------
#include <cassert>

#pragma hdrstop

#include "iniUtils_.h"
#include "AnsiStringUtils_.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


namespace Ini
{

void SaveWindowPlacement( HWND hWnd, TCustomIniFile* ini, const AnsiString& sekt )
{
    WINDOWPLACEMENT wndpl = {0};
    GetWindowPlacement(hWnd, &wndpl);
    SaveWindowPlacement( wndpl, ini, sekt );
}


void LoadWindowPlacement( HWND hWnd, TCustomIniFile* ini, const AnsiString& sekt )
{
    WINDOWPLACEMENT wndpl = {0};
    GetWindowPlacement(hWnd, &wndpl);
    LoadWindowPlacement( wndpl, ini, sekt );
    SetWindowPlacement(hWnd, &wndpl);
}

void SaveConsolePlacement( TCustomIniFile* ini, const AnsiString& sekt )
{
	HWND hCon = ::GetConsoleWindow();
    WINDOWPLACEMENT wndpl = {0};
    ::GetWindowPlacement(hCon, &wndpl);
    Ini::SaveWindowPlacement( hCon, ini, sekt );
}

void LoadConsolePlacement( TCustomIniFile* ini, const AnsiString& sekt )
{
	// перехват консоли на себя
    const HWND hCon = ::GetConsoleWindow();

    WINDOWPLACEMENT wndpl = {0};
    Ini::LoadWindowPlacement( wndpl, ini, sekt );
    ::SetWindowPlacement( hCon, &wndpl );

    const bool conIsVis =
    	wndpl.showCmd==SW_NORMAL ||
        wndpl.showCmd==SW_SHOWMAXIMIZED ||
        wndpl.showCmd==SW_SHOWNOACTIVATE ||
        wndpl.showCmd==SW_SHOW
    ;
    if( !conIsVis )
    	::ShowWindow( hCon, SW_HIDE );
}


void SaveWindowPlacement( const WINDOWPLACEMENT& wndpl, TCustomIniFile* ini, const AnsiString& sekt )
{
    #define SAVE_(nn) ini->WriteInteger(sekt,""#nn, wndpl.##nn )
    SAVE_(length);
    SAVE_(flags);
    SAVE_(showCmd);
    SAVE_(ptMinPosition.x);
    SAVE_(ptMinPosition.y);
    SAVE_(ptMaxPosition.x);
    SAVE_(ptMaxPosition.y);
    SAVE_(rcNormalPosition.left);
    SAVE_(rcNormalPosition.top);
    SAVE_(rcNormalPosition.right);
    SAVE_(rcNormalPosition.bottom);
    #undef SAVE_
}


void LoadWindowPlacement( WINDOWPLACEMENT& wndpl, TCustomIniFile* ini, const AnsiString& sekt )
{
    #define LOAD_(nn) wndpl.##nn = ini->ReadInteger(sekt,""#nn, wndpl.##nn )
    LOAD_(length);
    LOAD_(flags);
    LOAD_(showCmd);
    LOAD_(ptMinPosition.x);
    LOAD_(ptMinPosition.y);
    LOAD_(ptMaxPosition.x);
    LOAD_(ptMaxPosition.y);
    LOAD_(rcNormalPosition.left);
    LOAD_(rcNormalPosition.top);
    LOAD_(rcNormalPosition.right);
    LOAD_(rcNormalPosition.bottom);
    #undef LOAD_
}

int GetInteger( TCustomIniFile* ini, const AnsiString& sekt,
	const AnsiString& id, int valMin, int valMax, int defVal)
{
    assert(valMin<=valMax && defVal<=valMax && valMin<=defVal);
    int v;
    const bool ret = GetInt(ini, sekt, id, valMin, valMax, v);
    if( !ret )
        v = defVal;
    return v;
}

bool GetInt(TCustomIniFile* ini, const AnsiString& sekt,
    const AnsiString& id, int valMin, int valMax, int& v)
{
    assert(valMin<=valMax);
    const AnsiString s = ini->ReadString(sekt, id, "" );
    const MyInt getVal = MyStrToInt( s );
    v = getVal.first;
    return  getVal.second && v>=valMin && v<=valMax ;
}

    void SetStr( TCustomIniFile* ini, const AnsiString& sekt, const AnsiString& id,
    	const AnsiString& str )
    {
    	if( str.IsEmpty() ) return;
        ini->WriteString( sekt, id, str );
    }

};// namespace Ini

