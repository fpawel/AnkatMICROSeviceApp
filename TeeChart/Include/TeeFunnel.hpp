// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFunnel.pas' rev: 6.00

#ifndef TeeFunnelHPP
#define TeeFunnelHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teefunnel
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<Types::TPoint >  TeeFunnel__2;

class DELPHICLASS TFunnelSeries;
class PASCALIMPLEMENTATION TFunnelSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Graphics::TColor FAboveColor;
	bool FAutoUpdate;
	Graphics::TColor FBelowColor;
	double FDifferenceLimit;
	Tecanvas::TChartPen* FLinesPen;
	Teengine::TChartValueList* FOpportunityValues;
	bool FQuotesSorted;
	Graphics::TColor FWithinColor;
	DynamicArray<Types::TPoint >  IPolyPoints;
	bool ISorted;
	double IMin;
	double IMax;
	double ISlope;
	double IDiff;
	Types::TPoint BoundingPoints[4];
	Graphics::TColor __fastcall DefineFunnelRegion(int ValueIndex);
	virtual Teengine::TChartValueList* __fastcall GetQuoteValues(void);
	void __fastcall SetAboveColor(const Graphics::TColor Value);
	void __fastcall SetAutoUpdate(const bool Value);
	void __fastcall SetBelowColor(const Graphics::TColor Value);
	void __fastcall SetDifferenceLimit(const double Value);
	void __fastcall SetLinesPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetOpportunityValues(const Teengine::TChartValueList* Value);
	void __fastcall SetQuotesSorted(const bool Value);
	virtual void __fastcall SetQuoteValues(const Teengine::TChartValueList* Value);
	void __fastcall SetWithinColor(const Graphics::TColor Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	HIDESBASE void __fastcall GetMarkText(Teengine::TChartSeries* Sender, int ValueIndex, AnsiString &MarkText);
	
public:
	__fastcall virtual TFunnelSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TFunnelSeries(void);
	int __fastcall AddSegment(const double AQuote, const double AOpportunity, const AnsiString ALabel, Graphics::TColor AColor);
	virtual int __fastcall Clicked(int X, int Y)/* overload */;
	virtual int __fastcall CountLegendItems(void);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MinYValue(void);
	void __fastcall Recalc(void);
	
__published:
	__property Brush ;
	__property Pen ;
	__property Graphics::TColor AboveColor = {read=FAboveColor, write=SetAboveColor, default=32768};
	__property bool AutoUpdate = {read=FAutoUpdate, write=SetAutoUpdate, default=1};
	__property Graphics::TColor BelowColor = {read=FBelowColor, write=SetBelowColor, default=255};
	__property double DifferenceLimit = {read=FDifferenceLimit, write=SetDifferenceLimit};
	__property Tecanvas::TChartPen* LinesPen = {read=FLinesPen, write=SetLinesPen};
	__property Teengine::TChartValueList* OpportunityValues = {read=FOpportunityValues, write=SetOpportunityValues};
	__property bool QuotesSorted = {read=FQuotesSorted, write=SetQuotesSorted, default=0};
	__property Teengine::TChartValueList* QuoteValues = {read=GetQuoteValues, write=SetQuoteValues};
	__property Graphics::TColor WithinColor = {read=FWithinColor, write=SetWithinColor, default=65535};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teefunnel */
using namespace Teefunnel;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFunnel
