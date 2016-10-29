// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCount.pas' rev: 6.00

#ifndef TeeCountHPP
#define TeeCountHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecount
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCountTeeFunction;
class PASCALIMPLEMENTATION TCountTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int First, int Last);
	virtual double __fastcall CalculateMany(Classes::TList* SeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TCountTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCountTeeFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecount */
using namespace Teecount;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCount
