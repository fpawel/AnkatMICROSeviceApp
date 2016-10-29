// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CandleCh.pas' rev: 6.00

#ifndef CandleChHPP
#define CandleChHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <OHLChart.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Candlech
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TCandleStyle { csCandleStick, csCandleBar, csOpenClose, csLine };
#pragma option pop

#pragma option push -b-
enum TCandleColorStyle { cssRelativeToOpen, cssRelativeToClose };
#pragma option pop

#pragma pack(push, 1)
struct TCandleItem
{
	int yOpen;
	int yClose;
	int yHigh;
	int yLow;
	int tmpX;
	int tmpLeftWidth;
	int tmpRightWidth;
} ;
#pragma pack(pop)

class DELPHICLASS TCandleSeries;
class PASCALIMPLEMENTATION TCandleSeries : public Ohlchart::TOHLCSeries 
{
	typedef Ohlchart::TOHLCSeries inherited;
	
private:
	TCandleStyle FCandleStyle;
	int FCandleWidth;
	TCandleColorStyle FColorStyle;
	Tecanvas::TTeeGradient* FDownClose;
	Tecanvas::TChartPen* FHighLowPen;
	bool FShowCloseTick;
	bool FShowOpenTick;
	Tecanvas::TTeeGradient* FUpClose;
	#pragma pack(push, 1)
	Types::TPoint OldP;
	#pragma pack(pop)
	
	void __fastcall CalcItem(int ValueIndex, TCandleItem &AItem);
	bool __fastcall GetDark3D(void);
	Graphics::TColor __fastcall GetDownColor(void);
	bool __fastcall GetDraw3D(void);
	Tecanvas::TChartPen* __fastcall GetPen(void);
	Graphics::TColor __fastcall GetUpColor(void);
	void __fastcall SetCandlePen(Tecanvas::TChartPen* Value);
	void __fastcall SetCandleStyle(TCandleStyle Value);
	void __fastcall SetCandleWidth(int Value);
	void __fastcall SetColorStyle(const TCandleColorStyle Value);
	HIDESBASE void __fastcall SetDark3D(bool Value);
	void __fastcall SetDownColor(const Graphics::TColor Value);
	void __fastcall SetDownGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetDraw3D(bool Value);
	void __fastcall SetHighLowPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetShowCloseTick(bool Value);
	void __fastcall SetShowOpenTick(bool Value);
	void __fastcall SetUpColor(const Graphics::TColor Value);
	void __fastcall SetUpGradient(const Tecanvas::TTeeGradient* Value);
	
protected:
	Graphics::TColor __fastcall CalculateColor(int ValueIndex);
	Tecanvas::TCustomTeeGradient* __fastcall CalculateGradient(int ValueIndex);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawValue(int ValueIndex);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TCandleSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCandleSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall AddCandle(const System::TDateTime ADate, const double AOpen, const double AHigh, const double ALow, const double AClose);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	bool __fastcall ClickedCandle(int ValueIndex, const Types::TPoint &P);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
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
	__property TCandleStyle CandleStyle = {read=FCandleStyle, write=SetCandleStyle, default=0};
	__property int CandleWidth = {read=FCandleWidth, write=SetCandleWidth, default=4};
	__property TCandleColorStyle ColorStyle = {read=FColorStyle, write=SetColorStyle, default=0};
	__property bool Draw3D = {read=GetDraw3D, write=SetDraw3D, default=0};
	__property bool Dark3D = {read=GetDark3D, write=SetDark3D, default=1};
	__property Graphics::TColor DownCloseColor = {read=GetDownColor, write=SetDownColor, default=255};
	__property Tecanvas::TTeeGradient* DownCloseGradient = {read=FDownClose, write=SetDownGradient};
	__property Tecanvas::TChartPen* HighLowPen = {read=FHighLowPen, write=SetHighLowPen};
	__property bool ShowCloseTick = {read=FShowCloseTick, write=SetShowCloseTick, default=1};
	__property bool ShowOpenTick = {read=FShowOpenTick, write=SetShowOpenTick, default=1};
	__property Graphics::TColor UpCloseColor = {read=GetUpColor, write=SetUpColor, default=16777215};
	__property Tecanvas::TTeeGradient* UpCloseGradient = {read=FUpClose, write=SetUpGradient};
	__property Tecanvas::TChartPen* Pen = {read=GetPen, write=SetCandlePen};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TVolumeSeries;
class PASCALIMPLEMENTATION TVolumeSeries : public Series::TCustomSeries 
{
	typedef Series::TCustomSeries inherited;
	
private:
	bool FUseYOrigin;
	double FOrigin;
	Graphics::TColor IColor;
	Teengine::TChartValueList* __fastcall GetVolumeValues(void);
	void __fastcall PrepareCanvas(bool Forced, Graphics::TColor AColor);
	void __fastcall SetOrigin(const double Value);
	void __fastcall SetUseOrigin(const bool Value);
	void __fastcall SetVolumeValues(Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	int __fastcall OriginPosition(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TVolumeSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	DYNAMIC int __fastcall NumSampleValues(void);
	
__published:
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property HorizAxis  = {default=1};
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
	__property LinePen ;
	__property bool UseYOrigin = {read=FUseYOrigin, write=SetUseOrigin, default=0};
	__property Teengine::TChartValueList* VolumeValues = {read=GetVolumeValues, write=SetVolumeValues};
	__property XValues ;
	__property double YOrigin = {read=FOrigin, write=SetOrigin};
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TVolumeSeries(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TADXFunction;
class PASCALIMPLEMENTATION TADXFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	Series::TFastLineSeries* IDMDown;
	Series::TFastLineSeries* IDMUp;
	Tecanvas::TChartPen* __fastcall GetDownPen(void);
	Tecanvas::TChartPen* __fastcall GetUpPen(void);
	void __fastcall SetDownPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetUpPen(const Tecanvas::TChartPen* Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC bool __fastcall IsValidSource(Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TADXFunction(Classes::TComponent* AOwner);
	__fastcall virtual ~TADXFunction(void);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	__property Series::TFastLineSeries* DMDown = {read=IDMDown};
	__property Series::TFastLineSeries* DMUp = {read=IDMUp};
	
__published:
	__property Tecanvas::TChartPen* DownLinePen = {read=GetDownPen, write=SetDownPen};
	__property Tecanvas::TChartPen* UpLinePen = {read=GetUpPen, write=SetUpPen};
};


#pragma option push -b-
enum TRSIStyle { rsiOpenClose, rsiClose };
#pragma option pop

class DELPHICLASS TRSIFunction;
class PASCALIMPLEMENTATION TRSIFunction : public Teengine::TTeeMovingFunction 
{
	typedef Teengine::TTeeMovingFunction inherited;
	
private:
	TRSIStyle FStyle;
	Teengine::TChartSeries* ISeries;
	Teengine::TChartValueList* Opens;
	Teengine::TChartValueList* Closes;
	void __fastcall SetStyle(const TRSIStyle Value);
	
protected:
	DYNAMIC bool __fastcall IsValidSource(Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TRSIFunction(Classes::TComponent* AOwner);
	virtual double __fastcall Calculate(Teengine::TChartSeries* Series, int FirstIndex, int LastIndex);
	
__published:
	__property TRSIStyle Style = {read=FStyle, write=SetStyle, default=0};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TRSIFunction(void) { }
	#pragma option pop
	
};


typedef DynamicArray<Types::TRect >  CandleCh__6;

typedef DynamicArray<Types::TRect >  CandleCh__7;

class DELPHICLASS TDarvasSeries;
class PASCALIMPLEMENTATION TDarvasSeries : public TCandleSeries 
{
	typedef TCandleSeries inherited;
	
private:
	Tecanvas::TChartBrush* FBoxBrush;
	Tecanvas::TChartPen* FBoxPen;
	int FNumBoxes;
	void __fastcall SetBoxBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetBoxPen(const Tecanvas::TChartPen* Value);
	
protected:
	void __fastcall CalculateBoxes(void);
	virtual void __fastcall DrawAllValues(void);
	
public:
	DynamicArray<Types::TRect >  Boxes;
	DynamicArray<Types::TRect >  BoxesRect;
	__fastcall virtual TDarvasSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TDarvasSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall ClickedBox(int x, int y);
	__property int NumBoxes = {read=FNumBoxes, nodefault};
	
__published:
	__property Active  = {default=1};
	__property Tecanvas::TChartBrush* BoxBrush = {read=FBoxBrush, write=SetBoxBrush};
	__property Tecanvas::TChartPen* BoxPen = {read=FBoxPen, write=SetBoxPen};
	__property Brush ;
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property Transparency  = {default=70};
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
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint DefCandleWidth = 0x4;

}	/* namespace Candlech */
using namespace Candlech;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CandleCh
