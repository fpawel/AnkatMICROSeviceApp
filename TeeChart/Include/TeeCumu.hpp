// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCumu.pas' rev: 6.00

#ifndef TeeCumuHPP
#define TeeCumuHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecumu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCumulative;
class PASCALIMPLEMENTATION TCumulative : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	__fastcall virtual TCumulative(Classes::TComponent* AOwner);
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int First, int Last);
	virtual double __fastcall CalculateMany(Classes::TList* SeriesList, int ValueIndex);
	
__published:
	__property Period ;
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCumulative(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecumu */
using namespace Teecumu;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCumu
