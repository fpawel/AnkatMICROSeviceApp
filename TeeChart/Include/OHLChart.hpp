// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OHLChart.pas' rev: 6.00

#ifndef OHLChartHPP
#define OHLChartHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ohlchart
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOHLCSeries;
class PASCALIMPLEMENTATION TOHLCSeries : public Series::TCustomSeries 
{
	typedef Series::TCustomSeries inherited;
	
private:
	Teengine::TChartValueList* FHighValues;
	Teengine::TChartValueList* FLowValues;
	Teengine::TChartValueList* FOpenValues;
	Teengine::TChartValueList* __fastcall GetCloseValues(void);
	Teengine::TChartValueList* __fastcall GetDateValues(void);
	void __fastcall SetCloseValues(Teengine::TChartValueList* Value);
	void __fastcall SetDateValues(Teengine::TChartValueList* Value);
	void __fastcall SetHighValues(Teengine::TChartValueList* Value);
	void __fastcall SetLowValues(Teengine::TChartValueList* Value);
	void __fastcall SetOpenValues(Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual double __fastcall CalcMinMaxValue(bool IsMin);
	
public:
	__fastcall virtual TOHLCSeries(Classes::TComponent* AOwner);
	int __fastcall AddOHLC(const System::TDateTime ADate, const double AOpen, const double AHigh, const double ALow, const double AClose)/* overload */;
	int __fastcall AddOHLC(const double AOpen, const double AHigh, const double ALow, const double AClose)/* overload */;
	/*         class method */ static void __fastcall GetRandomOHLC(TMetaClass* vmt, double AOpen, double &AClose, double &AHigh, double &ALow, const double YRange);
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	
__published:
	__property Teengine::TChartValueList* CloseValues = {read=GetCloseValues, write=SetCloseValues};
	__property Teengine::TChartValueList* DateValues = {read=GetDateValues, write=SetDateValues};
	__property Teengine::TChartValueList* HighValues = {read=FHighValues, write=SetHighValues};
	__property Teengine::TChartValueList* LowValues = {read=FLowValues, write=SetLowValues};
	__property Teengine::TChartValueList* OpenValues = {read=FOpenValues, write=SetOpenValues};
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TOHLCSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ohlchart */
using namespace Ohlchart;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OHLChart
