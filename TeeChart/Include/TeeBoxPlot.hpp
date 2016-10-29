// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBoxPlot.pas' rev: 6.00

#ifndef TeeBoxPlotHPP
#define TeeBoxPlotHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeboxplot
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomBoxSeries;
class PASCALIMPLEMENTATION TCustomBoxSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TSeriesPointer* FExtrOut;
	Tecanvas::TChartPen* FMedianPen;
	Teengine::TSeriesPointer* FMildOut;
	double FPosition;
	double FWhiskerLength;
	Tecanvas::TChartPen* FWhiskerPen;
	bool IVertical;
	bool FUseCustomValues;
	double FMedian;
	double FQuartile1;
	double FQuartile3;
	double FInnerFence1;
	double FInnerFence3;
	double FOuterFence1;
	double FOuterFence3;
	double FAdjacentPoint1;
	double FAdjacentPoint3;
	void __fastcall CalcValues(Types::TRect &R, int &x, int &y, int &horiz, int &vert, int &tmp);
	Teengine::TSeriesPointer* __fastcall GetBox(void);
	void __fastcall SetAdjacentPoint1(const double Value);
	void __fastcall SetAdjacentPoint3(const double Value);
	void __fastcall SetExtrOut(Teengine::TSeriesPointer* Value);
	void __fastcall SetInnerFence1(const double Value);
	void __fastcall SetInnerFence3(const double Value);
	void __fastcall SetMedian(const double Value);
	void __fastcall SetMedianPen(Tecanvas::TChartPen* Value);
	void __fastcall SetMildOut(Teengine::TSeriesPointer* Value);
	void __fastcall SetOuterFence1(const double Value);
	void __fastcall SetOuterFence3(const double Value);
	void __fastcall SetPosition(const double Value);
	void __fastcall SetQuartile1(const double Value);
	void __fastcall SetQuartile3(const double Value);
	void __fastcall SetUseCustomValues(const bool Value);
	void __fastcall SetWhiskerLength(const double Value);
	void __fastcall SetWhiskerPen(Tecanvas::TChartPen* Value);
	bool __fastcall SaveCustomValues(void);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual Teengine::TChartValueList* __fastcall GetSampleValues(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetSampleValues(Teengine::TChartValueList* Value);
	
public:
	__fastcall virtual TCustomBoxSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomBoxSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	void __fastcall RecalcStats(void);
	__property Teengine::TSeriesPointer* Box = {read=GetBox};
	
__published:
	__property Teengine::TSeriesPointer* ExtrOut = {read=FExtrOut, write=SetExtrOut};
	__property Tecanvas::TChartPen* MedianPen = {read=FMedianPen, write=SetMedianPen};
	__property Teengine::TSeriesPointer* MildOut = {read=FMildOut, write=SetMildOut};
	__property double Position = {read=FPosition, write=SetPosition};
	__property Teengine::TChartValueList* SampleValues = {read=GetSampleValues, write=SetSampleValues};
	__property bool UseCustomValues = {read=FUseCustomValues, write=SetUseCustomValues, default=0};
	__property double WhiskerLength = {read=FWhiskerLength, write=SetWhiskerLength};
	__property Tecanvas::TChartPen* WhiskerPen = {read=FWhiskerPen, write=SetWhiskerPen};
	__property double AdjacentPoint1 = {read=FAdjacentPoint1, write=SetAdjacentPoint1, stored=SaveCustomValues};
	__property double AdjacentPoint3 = {read=FAdjacentPoint3, write=SetAdjacentPoint3, stored=SaveCustomValues};
	__property double InnerFence1 = {read=FInnerFence1, write=SetInnerFence1, stored=SaveCustomValues};
	__property double InnerFence3 = {read=FInnerFence3, write=SetInnerFence3, stored=SaveCustomValues};
	__property double Median = {read=FMedian, write=SetMedian, stored=SaveCustomValues};
	__property double OuterFence1 = {read=FOuterFence1, write=SetOuterFence1, stored=SaveCustomValues};
	__property double OuterFence3 = {read=FOuterFence3, write=SetOuterFence3, stored=SaveCustomValues};
	__property double Quartile1 = {read=FQuartile1, write=SetQuartile1, stored=SaveCustomValues};
	__property double Quartile3 = {read=FQuartile3, write=SetQuartile3, stored=SaveCustomValues};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TBoxSeries;
class PASCALIMPLEMENTATION TBoxSeries : public TCustomBoxSeries 
{
	typedef TCustomBoxSeries inherited;
	
public:
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxYValue(void);
public:
	#pragma option push -w-inl
	/* TCustomBoxSeries.Create */ inline __fastcall virtual TBoxSeries(Classes::TComponent* AOwner) : TCustomBoxSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomBoxSeries.Destroy */ inline __fastcall virtual ~TBoxSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS THorizBoxSeries;
class PASCALIMPLEMENTATION THorizBoxSeries : public TCustomBoxSeries 
{
	typedef TCustomBoxSeries inherited;
	
public:
	__fastcall virtual THorizBoxSeries(Classes::TComponent* AOwner);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxXValue(void);
public:
	#pragma option push -w-inl
	/* TCustomBoxSeries.Destroy */ inline __fastcall virtual ~THorizBoxSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeboxplot */
using namespace Teeboxplot;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBoxPlot
