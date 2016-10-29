// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePoly.pas' rev: 6.00

#ifndef TeePolyHPP
#define TeePolyHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepoly
{
//-- type declarations -------------------------------------------------------
typedef Extended Float;

typedef Extended TDegreeVector[20];

typedef Extended TPolyMatrix[20][20];

typedef DynamicArray<Extended >  TVector;

//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxPolyDegree = 0x14;
extern PACKAGE Extended __fastcall GetVectorValue(const TVector V, int Index);
extern PACKAGE void __fastcall SetVectorValue(const TVector V, int Index, const Extended Value);
extern PACKAGE Extended __fastcall CalcFitting(int PolyDegree, const Extended * Answer, const Extended XWert);
extern PACKAGE void __fastcall PolyFitting(int NumPoints, int PolyDegree, const TVector X, const TVector Y, Extended * Answer);

}	/* namespace Teepoly */
using namespace Teepoly;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePoly
