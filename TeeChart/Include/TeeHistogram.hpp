// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeHistogram.pas' rev: 6.00

#ifndef TeeHistogramHPP
#define TeeHistogramHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teehistogram
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THistogramFunction;
class PASCALIMPLEMENTATION THistogramFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FCumulative;
	int FNumBins;
	bool FIncludeNulls;
	void __fastcall SetCumulative(const bool Value);
	void __fastcall SetNumBins(int Value);
	void __fastcall SetIncludeNulls(const bool Value);
	
public:
	__fastcall virtual THistogramFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property bool Cumulative = {read=FCumulative, write=SetCumulative, default=0};
	__property int NumBins = {read=FNumBins, write=SetNumBins, default=20};
	__property bool IncludeNulls = {read=FIncludeNulls, write=SetIncludeNulls, default=1};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~THistogramFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Histogram(Teengine::TChartValues Data, Teengine::TChartValues &Bins, Teengine::TChartValues &Counts, double Min, double Max, int nbins);

}	/* namespace Teehistogram */
using namespace Teehistogram;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeHistogram
