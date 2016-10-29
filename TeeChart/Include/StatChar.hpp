// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StatChar.pas' rev: 6.00

#ifndef StatCharHPP
#define StatCharHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <CandleCh.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Statchar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMovingAverageFunction;
class PASCALIMPLEMENTATION TMovingAverageFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
private:
	bool FWeighted;
	bool FWeightedIndex;
	void __fastcall SetWeighted(bool Value);
	void __fastcall SetWeightedIndex(const bool Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int FirstIndex, int LastIndex);
	
__published:
	__property bool Weighted = {read=FWeighted, write=SetWeighted, default=0};
	__property bool WeightedIndex = {read=FWeightedIndex, write=SetWeightedIndex, default=0};
public:
	#pragma option push -w-inl
	/* TTeeMovingFunction.Create */ inline __fastcall virtual TMovingAverageFunction(Classes::TComponent* AOwner) : Teengine::TTeeMovingFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMovingAverageFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExpMovAveFunction;
class PASCALIMPLEMENTATION TExpMovAveFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FIgnoreNulls;
	void __fastcall SetIgnoreNulls(const bool Value);
	
public:
	__fastcall virtual TExpMovAveFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property bool IgnoreNulls = {read=FIgnoreNulls, write=SetIgnoreNulls, default=1};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TExpMovAveFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExpAverageFunction;
class PASCALIMPLEMENTATION TExpAverageFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
private:
	double FWeight;
	void __fastcall SetWeight(const double Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TExpAverageFunction(Classes::TComponent* AOwner);
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int FirstIndex, int LastIndex);
	
__published:
	__property double Weight = {read=FWeight, write=SetWeight};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TExpAverageFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMomentumFunction;
class PASCALIMPLEMENTATION TMomentumFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int FirstIndex, int LastIndex);
public:
	#pragma option push -w-inl
	/* TTeeMovingFunction.Create */ inline __fastcall virtual TMomentumFunction(Classes::TComponent* AOwner) : Teengine::TTeeMovingFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMomentumFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMomentumDivFunction;
class PASCALIMPLEMENTATION TMomentumDivFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int FirstIndex, int LastIndex);
public:
	#pragma option push -w-inl
	/* TTeeMovingFunction.Create */ inline __fastcall virtual TMomentumDivFunction(Classes::TComponent* AOwner) : Teengine::TTeeMovingFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMomentumDivFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRMSFunction;
class PASCALIMPLEMENTATION TRMSFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FComplete;
	int INumPoints;
	double ISum2;
	void __fastcall Accumulate(const double Value);
	double __fastcall CalculateRMS(void);
	void __fastcall SetComplete(const bool Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
	
__published:
	__property bool Complete = {read=FComplete, write=SetComplete, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TRMSFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TRMSFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStdDeviationFunction;
class PASCALIMPLEMENTATION TStdDeviationFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FComplete;
	double ISum;
	double ISum2;
	int INumPoints;
	void __fastcall Accumulate(const double Value);
	double __fastcall CalculateDeviation(void);
	void __fastcall SetComplete(bool Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
	
__published:
	__property bool Complete = {read=FComplete, write=SetComplete, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TStdDeviationFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TStdDeviationFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMACDFunction;
class PASCALIMPLEMENTATION TMACDFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
private:
	Candlech::TVolumeSeries* IHisto;
	TExpMovAveFunction* IMoving1;
	TExpMovAveFunction* IMoving2;
	Series::TFastLineSeries* IOther;
	Teengine::TChartSeries* ISeries1;
	Teengine::TChartSeries* ISeries2;
	Tecanvas::TChartPen* __fastcall GetHistoPen(void);
	Tecanvas::TChartPen* __fastcall GetMACDExpPen(void);
	double __fastcall GetPeriod2(void);
	int __fastcall GetPeriod3(void);
	void __fastcall SetHistoPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetMACDExpPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetPeriod2(const double Value);
	void __fastcall SetPeriod3(const int Value);
	Tecanvas::TChartPen* __fastcall GetMACDPen(void);
	void __fastcall SetMACDPen(const Tecanvas::TChartPen* Value);
	
protected:
	DYNAMIC void __fastcall Clear(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TMACDFunction(Classes::TComponent* AOwner);
	__fastcall virtual ~TMACDFunction(void);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	__property Series::TFastLineSeries* MACDExp = {read=IOther};
	__property Candlech::TVolumeSeries* Histogram = {read=IHisto};
	
__published:
	__property Tecanvas::TChartPen* HistogramPen = {read=GetHistoPen, write=SetHistoPen};
	__property Tecanvas::TChartPen* MACDPen = {read=GetMACDPen, write=SetMACDPen};
	__property Tecanvas::TChartPen* MACDExpPen = {read=GetMACDExpPen, write=SetMACDExpPen};
	__property double Period2 = {read=GetPeriod2, write=SetPeriod2};
	__property int Period3 = {read=GetPeriod3, write=SetPeriod3, default=9};
};


typedef DynamicArray<double >  StatChar__01;

typedef DynamicArray<double >  StatChar__11;

class DELPHICLASS TStochasticFunction;
class PASCALIMPLEMENTATION TStochasticFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
protected:
	DynamicArray<double >  FNums;
	DynamicArray<double >  FDens;
	
public:
	__fastcall virtual TStochasticFunction(Classes::TComponent* AOwner);
	__fastcall virtual ~TStochasticFunction(void);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int FirstIndex, int LastIndex);
};


class DELPHICLASS THistogramSeries;
class PASCALIMPLEMENTATION THistogramSeries : public Series::TCustomLineSeries 
{
	typedef Series::TCustomLineSeries inherited;
	
private:
	Tecanvas::TChartHiddenPen* FLinesPen;
	Tecanvas::TTeeTransparency FTransparency;
	int IPrevious;
	void __fastcall InternalCalcHoriz(Teengine::TChartAxis* Axis, int &Min, int &Max);
	void __fastcall SetLinesPen(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	int __fastcall VisiblePoints(void);
	
protected:
	virtual Types::TRect __fastcall CalcRect(int ValueIndex);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual THistogramSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~THistogramSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual void __fastcall CalcFirstLastVisibleIndex(void);
	
__published:
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property HorizAxis  = {default=1};
	__property LinePen ;
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property XLabelsSource ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnGetMarkText ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	__property Brush ;
	__property Tecanvas::TChartHiddenPen* LinesPen = {read=FLinesPen, write=SetLinesPen};
	__property Pen ;
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property XValues ;
	__property YValues ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS THorizHistogramSeries;
class PASCALIMPLEMENTATION THorizHistogramSeries : public THistogramSeries 
{
	typedef THistogramSeries inherited;
	
protected:
	virtual Types::TRect __fastcall CalcRect(int ValueIndex);
	
public:
	__fastcall virtual THorizHistogramSeries(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* THistogramSeries.Destroy */ inline __fastcall virtual ~THorizHistogramSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBollingerFunction;
class PASCALIMPLEMENTATION TBollingerFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FExponential;
	double FDeviation;
	Teengine::TChartSeries* IOther;
	void __fastcall SetDeviation(const double Value);
	void __fastcall SetExponential(const bool Value);
	Tecanvas::TChartPen* __fastcall GetLowBandPen(void);
	void __fastcall SetLowBandPen(const Tecanvas::TChartPen* Value);
	Tecanvas::TChartPen* __fastcall GetUpperBandPen(void);
	void __fastcall SetUpperBandPen(const Tecanvas::TChartPen* Value);
	
protected:
	DYNAMIC void __fastcall Clear(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TBollingerFunction(Classes::TComponent* AOwner);
	__fastcall virtual ~TBollingerFunction(void);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	__property Teengine::TChartSeries* LowBand = {read=IOther};
	
__published:
	__property double Deviation = {read=FDeviation, write=SetDeviation};
	__property bool Exponential = {read=FExponential, write=SetExponential, default=1};
	__property Tecanvas::TChartPen* LowBandPen = {read=GetLowBandPen, write=SetLowBandPen};
	__property Tecanvas::TChartPen* UpperBandPen = {read=GetUpperBandPen, write=SetUpperBandPen};
};


class DELPHICLASS TCrossPointsFunction;
class PASCALIMPLEMENTATION TCrossPointsFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TCrossPointsFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCrossPointsFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPerformanceFunction;
class PASCALIMPLEMENTATION TPerformanceFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
public:
	#pragma option push -w-inl
	/* TTeeMovingFunction.Create */ inline __fastcall virtual TPerformanceFunction(Classes::TComponent* AOwner) : Teengine::TTeeMovingFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TPerformanceFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TVarianceFunction;
class PASCALIMPLEMENTATION TVarianceFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TVarianceFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TVarianceFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPerimeterFunction;
class PASCALIMPLEMENTATION TPerimeterFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	__fastcall virtual TPerimeterFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TPerimeterFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Statchar */
using namespace Statchar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StatChar
