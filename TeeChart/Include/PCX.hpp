// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PCX.pas' rev: 6.00

#ifndef PCXHPP
#define PCXHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pcx
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall LoadFromFileX(const AnsiString FileName, const Graphics::TBitmap* Bitmap);
extern PACKAGE void __fastcall TeePCXToStream(Classes::TStream* Stream, const Graphics::TBitmap* Bitmap, Byte PcxType);
extern PACKAGE void __fastcall SaveToFileX(const AnsiString FileName, const Graphics::TBitmap* Bitmap, Byte PcxType);

}	/* namespace Pcx */
using namespace Pcx;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PCX
