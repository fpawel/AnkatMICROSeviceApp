// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ErrorBar.pas' rev: 6.00

#ifndef ErrorBarHPP
#define ErrorBarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Errorbar
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TErrorSeriesStyle { essLeft, essRight, essLeftRight, essTop, essBottom, essTopBottom };
#pragma option pop

#pragma option push -b-
enum TErrorWidthUnits { ewuPercent, ewuPixels };
#pragma option pop

class DELPHICLASS TCustomErrorSeries;
class PASCALIMPLEMENTATION TCustomErrorSeries : public Series::TBarSeries 
{
	typedef Series::TBarSeries inherited;
	
private:
	Tecanvas::TChartPen* FErrorPen;
	TErrorSeriesStyle FErrorStyle;
	Teengine::TChartValueList* FErrorValues;
	int FErrorWidth;
	TErrorWidthUnits FErrorWidthUnits;
	bool IDrawBar;
	double __fastcall GetErrorValue(int Index);
	void __fastcall PrepareErrorPen(int ValueIndex);
	void __fastcall SetErrorStyle(TErrorSeriesStyle Value);
	void __fastcall SetErrorValue(int Index, const double Value);
	void __fastcall SetErrorValues(Teengine::TChartValueList* Value);
	void __fastcall SetErrorWidthUnits(TErrorWidthUnits Value);
	void __fastcall SetErrorWidth(int Value);
	void __fastcall SetErrorPen(const Tecanvas::TChartPen* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	void __fastcall DrawError(int X, int Y, int AWidth, int AHeight, bool Draw3D);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	/* virtual class method */ virtual bool __fastcall SubGalleryStack(TMetaClass* vmt);
	
public:
	__fastcall virtual TCustomErrorSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomErrorSeries(void);
	int __fastcall AddErrorBar(const double AX, const double AY, const double AError, const AnsiString AXLabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	__property double ErrorValue[int Index] = {read=GetErrorValue, write=SetErrorValue};
	__property Tecanvas::TChartPen* ErrorPen = {read=FErrorPen, write=SetErrorPen};
	__property TErrorSeriesStyle ErrorStyle = {read=FErrorStyle, write=SetErrorStyle, default=5};
	__property Teengine::TChartValueList* ErrorValues = {read=FErrorValues, write=SetErrorValues};
	__property int ErrorWidth = {read=FErrorWidth, write=SetErrorWidth, default=100};
	__property TErrorWidthUnits ErrorWidthUnits = {read=FErrorWidthUnits, write=SetErrorWidthUnits, default=0};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TErrorSeries;
class PASCALIMPLEMENTATION TErrorSeries : public TCustomErrorSeries 
{
	typedef TCustomErrorSeries inherited;
	
__published:
	__property ErrorPen ;
	__property ErrorStyle  = {default=5};
	__property ErrorValues ;
	__property ErrorWidth  = {default=100};
	__property ErrorWidthUnits  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomErrorSeries.Create */ inline __fastcall virtual TErrorSeries(Classes::TComponent* AOwner) : TCustomErrorSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomErrorSeries.Destroy */ inline __fastcall virtual ~TErrorSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TErrorBarSeries;
class PASCALIMPLEMENTATION TErrorBarSeries : public TCustomErrorSeries 
{
	typedef TCustomErrorSeries inherited;
	
protected:
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TErrorBarSeries(Classes::TComponent* AOwner);
	
__published:
	__property ErrorPen ;
	__property ErrorValues ;
	__property ErrorWidth  = {default=100};
	__property ErrorWidthUnits  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomErrorSeries.Destroy */ inline __fastcall virtual ~TErrorBarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseHighLowSeries;
class PASCALIMPLEMENTATION TBaseHighLowSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Teengine::TChartValueList* FLow;
	Teengine::TChartValueList* __fastcall GetHigh(void);
	void __fastcall SetHigh(const Teengine::TChartValueList* Value);
	void __fastcall SetLow(const Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	
public:
	__fastcall virtual TBaseHighLowSeries(Classes::TComponent* AOwner);
	int __fastcall AddHighLow(const double AX, const double AHigh, const double ALow, const AnsiString AXLabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Teengine::TChartValueList* HighValues = {read=GetHigh, write=SetHigh};
	__property Teengine::TChartValueList* LowValues = {read=FLow, write=SetLow};
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property Pen ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property XLabelsSource ;
	__property XValues ;
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
public:
	#pragma option push -w-inl
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TBaseHighLowSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS THighLowSeries;
class PASCALIMPLEMENTATION THighLowSeries : public TBaseHighLowSeries 
{
	typedef TBaseHighLowSeries inherited;
	
private:
	Tecanvas::TChartPen* FHighPen;
	Tecanvas::TChartPen* FLowPen;
	Tecanvas::TChartBrush* FLowBrush;
	Tecanvas::TTeeTransparency FTransparency;
	int OldX;
	int OldY0;
	int OldY1;
	Tecanvas::TChartBrush* __fastcall GetHighBrush(void);
	void __fastcall SetHighBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetHighPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetLowBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetLowPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual THighLowSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~THighLowSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	
__published:
	__property Tecanvas::TChartBrush* HighBrush = {read=GetHighBrush, write=SetHighBrush};
	__property Tecanvas::TChartPen* HighPen = {read=FHighPen, write=SetHighPen};
	__property Tecanvas::TChartBrush* LowBrush = {read=FLowBrush, write=SetLowBrush};
	__property Tecanvas::TChartPen* LowPen = {read=FLowPen, write=SetLowPen};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Errorbar */
using namespace Errorbar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ErrorBar
