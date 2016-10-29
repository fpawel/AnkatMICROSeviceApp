// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeHtml.pas' rev: 6.00

#ifndef TeeHtmlHPP
#define TeeHtmlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teehtml
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TSize
{
	int Width;
	int Height;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Graphics::TGraphic* __fastcall (*GraphicFileExtension)(const AnsiString FileExtension);
extern PACKAGE int __fastcall (*GraphicDownload)(const AnsiString URL, Classes::TStream* Stream);
extern PACKAGE TSize __fastcall HtmlTextExtent(Tecanvas::TTeeCanvas* ACanvas, const AnsiString Text);
extern PACKAGE void __fastcall HtmlTextOut(Tecanvas::TTeeCanvas* ACanvas, int x, int y, AnsiString Text);

}	/* namespace Teehtml */
using namespace Teehtml;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeHtml
