// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDownSampling.pas' rev: 6.00

#ifndef TeeDownSamplingHPP
#define TeeDownSamplingHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedownsampling
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TPointFloat2D
{
	double X;
	double Y;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TDownSampleMethod { dsDouglas, dsMax, dsMin, dsMinMax, dsAverage, dsMinMaxFirstLast, dsMinMaxFirstLastNull };
#pragma option pop

class DELPHICLASS TDownSamplingFunction;
class PASCALIMPLEMENTATION TDownSamplingFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	TDownSampleMethod FDownSampleMethod;
	double FTolerance;
	int FDisplayedPointCount;
	void __fastcall SetDownSampleMethod(const TDownSampleMethod Value);
	void __fastcall SetTolerance(double Value);
	void __fastcall SetDisplayedPointCount(const int Value);
	int __fastcall Reduce(TDownSampleMethod Method, const double Tol, const int lbound, const int ubound, Teengine::TChartSeries* s, Teengine::TChartValues &RX, Teengine::TChartValues &RY, Graphics::TColor * colors, const int colors_Size, Graphics::TColor color);
	
public:
	int ReducedSize;
	__fastcall virtual TDownSamplingFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property TDownSampleMethod DownSampleMethod = {read=FDownSampleMethod, write=SetDownSampleMethod, default=0};
	__property double Tolerance = {read=FTolerance, write=SetTolerance};
	__property int DisplayedPointCount = {read=FDisplayedPointCount, write=SetDisplayedPointCount, default=0};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TDownSamplingFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teedownsampling */
using namespace Teedownsampling;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDownSampling
