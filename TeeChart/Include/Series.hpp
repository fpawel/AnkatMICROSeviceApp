// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Series.pas' rev: 6.00

#ifndef SeriesHPP
#define SeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Series
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTreatNullsStyle { tnDontPaint, tnSkip, tnIgnore };
#pragma option pop

class DELPHICLASS TCustomLineSeries;
class PASCALIMPLEMENTATION TCustomLineSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	TTreatNullsStyle FTreatNulls;
	void __fastcall SetTreatNulls(const TTreatNullsStyle Value);
	
protected:
	Tecanvas::TChartPen* __fastcall GetLinePen(void);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Tecanvas::TChartPen* LinePen = {read=GetLinePen, write=SetPen};
	__property TTreatNullsStyle TreatNulls = {read=FTreatNulls, write=SetTreatNulls, default=0};
public:
	#pragma option push -w-inl
	/* TChartSeries.Create */ inline __fastcall virtual TCustomLineSeries(Classes::TComponent* AOwner) : Teengine::TChartSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TCustomLineSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomSeries;
typedef void __fastcall (__closure *TSeriesClickPointerEvent)(TCustomSeries* Sender, int ValueIndex, int X, int Y);

#pragma option push -b-
enum TCustomSeriesStack { cssNone, cssOverlap, cssStack, cssStack100 };
#pragma option pop

typedef Teengine::TSeriesPointerStyle __fastcall (__closure *TOnGetPointerStyle)(Teengine::TChartSeries* Sender, int ValueIndex);

class PASCALIMPLEMENTATION TCustomSeries : public TCustomLineSeries 
{
	typedef TCustomLineSeries inherited;
	
private:
	Tecanvas::TChartBrush* FAreaBrush;
	Graphics::TColor FAreaColor;
	Tecanvas::TChartPen* FAreaLinesPen;
	bool FClickableLine;
	bool FColorEachLine;
	bool FDark3D;
	bool FDrawArea;
	bool FDrawLine;
	bool FInvertedStairs;
	int FLineHeight;
	Tecanvas::TChartHiddenPen* FOutLine;
	Teengine::TSeriesPointer* FPointer;
	Tecanvas::TTeeShadow* FShadow;
	TCustomSeriesStack FStacked;
	bool FStairs;
	Tecanvas::TTeeTransparency FTransparency;
	TSeriesClickPointerEvent FOnClickPointer;
	TOnGetPointerStyle FOnGetPointerStyle;
	int BottomPos;
	int OldBottomPos;
	int OldX;
	int OldY;
	Graphics::TColor OldColor;
	double tmpDark3DRatio;
	int __fastcall CalcStackedPos(int ValueIndex, double Value);
	Graphics::TBrushStyle __fastcall GetAreaBrush(void);
	Graphics::TBrushStyle __fastcall GetLineBrush(void);
	void __fastcall InternalCalcMargin(bool SameSide, bool Horizontal, int &A, int &B);
	double __fastcall PointOrigin(int ValueIndex, bool SumAll);
	void __fastcall SetAreaBrush(Tecanvas::TChartBrush* Value);
	void __fastcall SetAreaBrushStyle(Graphics::TBrushStyle Value);
	void __fastcall SetAreaColor(Graphics::TColor Value);
	void __fastcall SetAreaLinesPen(Tecanvas::TChartPen* Value);
	void __fastcall SetColorEachLine(const bool Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetDrawArea(bool Value);
	void __fastcall SetGradient(Tecanvas::TTeeGradient* Value);
	void __fastcall SetInvertedStairs(bool Value);
	void __fastcall SetLineBrush(Graphics::TBrushStyle Value);
	void __fastcall SetLineHeight(int Value);
	void __fastcall SetOutLine(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetPointer(Teengine::TSeriesPointer* Value);
	void __fastcall SetShadow(Tecanvas::TTeeShadow* Value);
	void __fastcall SetStacked(TCustomSeriesStack Value);
	void __fastcall SetStairs(bool Value);
	
protected:
	Tecanvas::TTeeGradient* FGradient;
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual int __fastcall CalcMarkLength(void);
	virtual double __fastcall CalcMinMaxValue(bool IsMin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual void __fastcall CalcZOrder(void);
	virtual bool __fastcall ClickedPointer(int ValueIndex, int tmpX, int tmpY, int x, int y);
	Teengine::TSeriesPointerStyle __fastcall DoGetPointerStyle(int ValueIndex);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	DYNAMIC void __fastcall DrawPointer(int AX, int AY, Graphics::TColor AColor, int ValueIndex);
	virtual void __fastcall DrawValue(int ValueIndex);
	Graphics::TColor __fastcall GetAreaBrushColor(Graphics::TColor AColor);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	virtual Tecanvas::TTeeTransparency __fastcall GetTransparency(void);
	void __fastcall InitDrawValue(int ValueIndex);
	virtual void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	__property Tecanvas::TTeeGradient* Gradient = {read=GetGradient, write=SetGradient};
	void __fastcall LinePrepareCanvas(Tecanvas::TCanvas3D* tmpCanvas, Graphics::TColor tmpColor);
	virtual void __fastcall PreparePointer(int ValueIndex);
	virtual bool __fastcall SameClassOrigin(Teengine::TChartSeries* ASeries);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	__property TCustomSeriesStack Stacked = {read=FStacked, write=SetStacked, default=0};
	__property Tecanvas::TTeeTransparency Transparency = {read=GetTransparency, write=SetTransparency, default=0};
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	virtual bool __fastcall RaiseClicked(void);
	
public:
	__fastcall virtual TCustomSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual int __fastcall GetOriginPos(int ValueIndex);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual void __fastcall CalcFirstLastVisibleIndex(void);
	__property Graphics::TBrushStyle AreaBrush = {read=GetAreaBrush, write=SetAreaBrushStyle, default=0};
	__property Tecanvas::TChartBrush* AreaChartBrush = {read=FAreaBrush, write=SetAreaBrush};
	__property Graphics::TColor AreaColor = {read=FAreaColor, write=SetAreaColor, default=536870912};
	__property Tecanvas::TChartPen* AreaLinesPen = {read=FAreaLinesPen, write=SetAreaLinesPen};
	__property bool ClickableLine = {read=FClickableLine, write=FClickableLine, default=1};
	__property bool ColorEachLine = {read=FColorEachLine, write=SetColorEachLine, default=1};
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property bool DrawArea = {read=FDrawArea, write=SetDrawArea, default=0};
	__property bool InvertedStairs = {read=FInvertedStairs, write=SetInvertedStairs, default=0};
	__property Graphics::TBrushStyle LineBrush = {read=GetLineBrush, write=SetLineBrush, default=0};
	__property int LineHeight = {read=FLineHeight, write=SetLineHeight, default=0};
	__property Tecanvas::TChartHiddenPen* OutLine = {read=FOutLine, write=SetOutLine};
	__property Teengine::TSeriesPointer* Pointer = {read=FPointer, write=SetPointer};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property bool Stairs = {read=FStairs, write=SetStairs, default=0};
	__property TSeriesClickPointerEvent OnClickPointer = {read=FOnClickPointer, write=FOnClickPointer};
	
__published:
	__property TOnGetPointerStyle OnGetPointerStyle = {read=FOnGetPointerStyle, write=FOnGetPointerStyle};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TLineSeries;
class PASCALIMPLEMENTATION TLineSeries : public TCustomSeries 
{
	typedef TCustomSeries inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TLineSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Active  = {default=1};
	__property ColorEachLine  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property Gradient ;
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property Shadow ;
	__property ShowInLegend  = {default=1};
	__property Stacked  = {default=0};
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
	__property ClickableLine  = {default=1};
	__property Dark3D  = {default=1};
	__property InvertedStairs  = {default=0};
	__property LineBrush  = {default=0};
	__property LineHeight  = {default=0};
	__property LinePen ;
	__property OutLine ;
	__property Pointer ;
	__property Stairs  = {default=0};
	__property TreatNulls  = {default=0};
	__property XValues ;
	__property YValues ;
	__property Transparency  = {default=0};
	__property OnClickPointer ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TLineSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS THorizLineSeries;
class PASCALIMPLEMENTATION THorizLineSeries : public TLineSeries 
{
	typedef TLineSeries inherited;
	
protected:
	virtual int __fastcall CalcMarkLength(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	
public:
	__fastcall virtual THorizLineSeries(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~THorizLineSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPointSeries;
class PASCALIMPLEMENTATION TPointSeries : public TCustomSeries 
{
	typedef TCustomSeries inherited;
	
private:
	void __fastcall SetFixed(void);
	
protected:
	/* virtual class method */ virtual bool __fastcall CanDoExtra(TMetaClass* vmt);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual Tecanvas::TTeeTransparency __fastcall GetTransparency(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetColorEachPoint(bool Value);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	virtual void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	
public:
	__fastcall virtual TPointSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
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
	__property Stacked  = {default=0};
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
	__property ClickableLine  = {default=1};
	__property Pointer ;
	__property Transparency  = {default=0};
	__property XValues ;
	__property YValues ;
	__property OnClickPointer ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TPointSeries(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMultiArea { maNone, maStacked, maStacked100 };
#pragma option pop

class DELPHICLASS TAreaSeries;
class PASCALIMPLEMENTATION TAreaSeries : public TCustomSeries 
{
	typedef TCustomSeries inherited;
	
private:
	double FOrigin;
	int FStackGroup;
	bool FUseOrigin;
	TMultiArea __fastcall GetMultiArea(void);
	void __fastcall SetGalleryFormat(void);
	void __fastcall SetMultiArea(TMultiArea Value);
	void __fastcall SetOrigin(const double Value);
	void __fastcall SetStackGroup(const int Value);
	void __fastcall SetUseOrigin(bool Value);
	
protected:
	virtual void __fastcall CalcZOrder(void);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual bool __fastcall SameClassOrigin(Teengine::TChartSeries* ASeries);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TAreaSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	virtual int __fastcall GetOriginPos(int ValueIndex);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Active  = {default=1};
	__property ColorEachLine  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property Gradient ;
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
	__property AreaBrush  = {default=0};
	__property AreaChartBrush ;
	__property AreaColor  = {default=536870912};
	__property AreaLinesPen ;
	__property ClickableLine  = {default=1};
	__property Dark3D  = {default=1};
	__property DrawArea  = {default=0};
	__property InvertedStairs  = {default=0};
	__property LinePen ;
	__property TMultiArea MultiArea = {read=GetMultiArea, write=SetMultiArea, default=0};
	__property Pointer ;
	__property Stairs  = {default=0};
	__property int StackGroup = {read=FStackGroup, write=SetStackGroup, default=0};
	__property Transparency  = {default=0};
	__property TreatNulls  = {default=0};
	__property bool UseYOrigin = {read=FUseOrigin, write=SetUseOrigin, default=0};
	__property XValues ;
	__property double YOrigin = {read=FOrigin, write=SetOrigin};
	__property YValues ;
	__property OnClickPointer ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TAreaSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS THorizAreaSeries;
class PASCALIMPLEMENTATION THorizAreaSeries : public TAreaSeries 
{
	typedef TAreaSeries inherited;
	
protected:
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	
public:
	__fastcall virtual THorizAreaSeries(Classes::TComponent* AOwner);
	DYNAMIC int __fastcall NumSampleValues(void);
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~THorizAreaSeries(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMultiBar { mbNone, mbSide, mbStacked, mbStacked100, mbSideAll, mbSelfStack };
#pragma option pop

#pragma option push -b-
enum TBarStyle { bsRectangle, bsPyramid, bsInvPyramid, bsCilinder, bsEllipse, bsArrow, bsRectGradient, bsCone, bsBevel, bsSlantCube, bsDiamond, bsInvArrow, bsInvCone };
#pragma option pop

class DELPHICLASS TCustomBarSeries;
typedef void __fastcall (__closure *TGetBarStyleEvent)(TCustomBarSeries* Sender, int ValueIndex, TBarStyle &TheBarStyle);

class DELPHICLASS TBarSeriesGradient;
class PASCALIMPLEMENTATION TBarSeriesGradient : public Tecanvas::TCustomTeeGradient 
{
	typedef Tecanvas::TCustomTeeGradient inherited;
	
private:
	bool FRelative;
	void __fastcall SetRelative(const bool Value);
	
__published:
	__property Angle  = {default=0};
	__property Balance  = {default=50};
	__property Direction ;
	__property MidColor  = {default=536870911};
	__property RadialX  = {default=0};
	__property RadialY  = {default=0};
	__property bool Relative = {read=FRelative, write=SetRelative, default=0};
	__property SubGradient ;
	__property StartColor  = {default=16777215};
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Create */ inline __fastcall virtual TBarSeriesGradient(Classes::TNotifyEvent ChangedEvent) : Tecanvas::TCustomTeeGradient(ChangedEvent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeeGradient.Destroy */ inline __fastcall virtual ~TBarSeriesGradient(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomBarSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	bool FAutoBarSize;
	bool FAutoMarkPosition;
	TBarStyle FBarStyle;
	int FBarWidthPercent;
	int FBevelSize;
	int FConePercent;
	bool FDark3D;
	int FDarkPen;
	int FDepthPercent;
	TBarSeriesGradient* FGradient;
	TMultiBar FMultiBar;
	int FOffsetPercent;
	Tecanvas::TTeeShadow* FShadow;
	bool FSideMargins;
	int FStackGroup;
	Tecanvas::TChartHiddenPen* FTickLines;
	Tecanvas::TTeeTransparency FTransparency;
	bool FUseOrigin;
	double FOrigin;
	TGetBarStyleEvent FOnGetBarStyle;
	#pragma pack(push, 1)
	Types::TRect FBarBounds;
	#pragma pack(pop)
	
	int INumBars;
	int IMaxBarPoints;
	int IOrderPos;
	int IPreviousCount;
	void __fastcall CalcGradientColor(int ValueIndex);
	Tecanvas::TTeeBlend* __fastcall CreateBlend(int Transp);
	void __fastcall DrawBevel(void);
	Tecanvas::TChartBrush* __fastcall GetBarBrush(void);
	Tecanvas::TChartPen* __fastcall GetBarPen(void);
	TBarStyle __fastcall GetBarStyle(int ValueIndex);
	void __fastcall PrepareBarPen(int ValueIndex);
	void __fastcall SetAutoBarSize(bool Value);
	void __fastcall SetAutoMarkPosition(bool Value);
	void __fastcall SetBarWidthPercent(int Value);
	void __fastcall SetOffsetPercent(int Value);
	void __fastcall SetBarStyle(TBarStyle Value);
	void __fastcall SetBevelSize(const int Value);
	void __fastcall SetConePercent(const int Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetDarkPen(int Value);
	void __fastcall SetDepthPercent(int Value);
	void __fastcall SetGradient(TBarSeriesGradient* Value);
	void __fastcall SetMultiBar(TMultiBar Value);
	void __fastcall SetOrigin(const double Value);
	void __fastcall SetOtherBars(bool SetOthers);
	void __fastcall SetShadow(const Tecanvas::TTeeShadow* Value);
	void __fastcall SetSideMargins(bool Value);
	void __fastcall SetStackGroup(int Value);
	void __fastcall SetTickLines(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetUseOrigin(bool Value);
	void __fastcall BarGradient(int ValueIndex, const Types::TRect &R);
	void __fastcall InternalApplyBarMargin(int &MarginA, int &MarginB);
	int __fastcall InternalGetOriginPos(int ValueIndex, int DefaultOrigin);
	double __fastcall MaxMandatoryValue(const double Value);
	double __fastcall MinMandatoryValue(const double Value);
	
protected:
	int IBarSize;
	int FCustomBarSize;
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool Sequential = false);
	virtual void __fastcall CalcDepthPositions(void);
	virtual void __fastcall CalcZOrder(void);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	DYNAMIC void __fastcall DrawTickLine(int TickPos, TBarStyle AStyle);
	void __fastcall DrawTickLines(int StartPos, int EndPos, TBarStyle AStyle);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual int __fastcall InternalCalcMarkLength(int ValueIndex);
	virtual bool __fastcall InternalClicked(int ValueIndex, const Types::TPoint &P);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	void __fastcall SetCustomBarSize(int Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	/* virtual class method */ virtual bool __fastcall SubGalleryStack(TMetaClass* vmt);
	
public:
	Graphics::TColor NormalBarColor;
	__fastcall virtual TCustomBarSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomBarSeries(void);
	int __fastcall AddBar(const double AValue, const AnsiString ALabel, Graphics::TColor AColor);
	int __fastcall ApplyBarOffset(int Position);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall BarMargin(void);
	void __fastcall BarRectangle(Graphics::TColor BarColor, int ALeft, int ATop, int ARight, int ABottom);
	virtual Types::TRect __fastcall CalcBarBounds(int ValueIndex) = 0 ;
	int __fastcall CalcMarkLength(int ValueIndex);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos) = 0 ;
	DYNAMIC int __fastcall NumSampleValues(void);
	virtual double __fastcall PointOrigin(int ValueIndex, bool SumAll);
	void __fastcall SetPenBrushBar(Graphics::TColor BarColor, int ValueIndex = 0xffffffff);
	virtual void __fastcall CalcFirstLastVisibleIndex(void);
	__property Types::TRect BarBounds = {read=FBarBounds};
	__property int ConePercent = {read=FConePercent, write=SetConePercent, default=0};
	
__published:
	__property Active  = {default=1};
	__property Tecanvas::TChartBrush* BarBrush = {read=GetBarBrush, write=SetBrush};
	__property Tecanvas::TChartPen* BarPen = {read=GetBarPen, write=SetPen};
	__property int BevelSize = {read=FBevelSize, write=SetBevelSize, default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property int DarkPen = {read=FDarkPen, write=SetDarkPen, default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
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
	__property bool AutoBarSize = {read=FAutoBarSize, write=SetAutoBarSize, default=0};
	__property bool AutoMarkPosition = {read=FAutoMarkPosition, write=SetAutoMarkPosition, default=1};
	__property TBarStyle BarStyle = {read=FBarStyle, write=SetBarStyle, default=0};
	__property int BarWidthPercent = {read=FBarWidthPercent, write=SetBarWidthPercent, default=70};
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property int DepthPercent = {read=FDepthPercent, write=SetDepthPercent, default=100};
	__property TBarSeriesGradient* Gradient = {read=FGradient, write=SetGradient};
	__property TMultiBar MultiBar = {read=FMultiBar, write=SetMultiBar, default=1};
	__property int OffsetPercent = {read=FOffsetPercent, write=SetOffsetPercent, default=0};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property bool SideMargins = {read=FSideMargins, write=SetSideMargins, default=1};
	__property int StackGroup = {read=FStackGroup, write=SetStackGroup, default=0};
	__property Tecanvas::TChartHiddenPen* TickLines = {read=FTickLines, write=SetTickLines};
	__property bool UseYOrigin = {read=FUseOrigin, write=SetUseOrigin, default=1};
	__property double YOrigin = {read=FOrigin, write=SetOrigin};
	__property XValues ;
	__property YValues ;
	__property TGetBarStyleEvent OnGetBarStyle = {read=FOnGetBarStyle, write=FOnGetBarStyle};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TBarSeries;
class PASCALIMPLEMENTATION TBarSeries : public TCustomBarSeries 
{
	typedef TCustomBarSeries inherited;
	
protected:
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcSelectionPos(int ValueIndex, /* out */ int &X, /* out */ int &Y);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	DYNAMIC void __fastcall DrawTickLine(int TickPos, TBarStyle AStyle);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual int __fastcall InternalCalcMarkLength(int ValueIndex);
	virtual bool __fastcall InternalClicked(int ValueIndex, const Types::TPoint &P);
	virtual bool __fastcall MoreSameZOrder(void);
	
public:
	__fastcall virtual TBarSeries(Classes::TComponent* AOwner);
	virtual Types::TRect __fastcall CalcBarBounds(int ValueIndex);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	int __fastcall GetOriginPos(int ValueIndex);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	__property int BarWidth = {read=IBarSize, nodefault};
	
__published:
	__property int CustomBarWidth = {read=FCustomBarSize, write=SetCustomBarSize, default=0};
public:
	#pragma option push -w-inl
	/* TCustomBarSeries.Destroy */ inline __fastcall virtual ~TBarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS THorizBarSeries;
class PASCALIMPLEMENTATION THorizBarSeries : public TCustomBarSeries 
{
	typedef TCustomBarSeries inherited;
	
protected:
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcSelectionPos(int ValueIndex, /* out */ int &X, /* out */ int &Y);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	DYNAMIC void __fastcall DrawTickLine(int TickPos, TBarStyle AStyle);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual int __fastcall InternalCalcMarkLength(int ValueIndex);
	virtual bool __fastcall InternalClicked(int ValueIndex, const Types::TPoint &P);
	
public:
	__fastcall virtual THorizBarSeries(Classes::TComponent* AOwner);
	virtual Types::TRect __fastcall CalcBarBounds(int ValueIndex);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	int __fastcall GetOriginPos(int ValueIndex);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	__property int BarHeight = {read=IBarSize, nodefault};
	
__published:
	__property int CustomBarHeight = {read=FCustomBarSize, write=SetCustomBarSize, default=0};
public:
	#pragma option push -w-inl
	/* TCustomBarSeries.Destroy */ inline __fastcall virtual ~THorizBarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCircledShadow;
class PASCALIMPLEMENTATION TCircledShadow : public Tecanvas::TTeeShadow 
{
	typedef Tecanvas::TTeeShadow inherited;
	
__published:
	__property Color  = {default=10526880};
public:
	#pragma option push -w-inl
	/* TTeeShadow.Create */ inline __fastcall TCircledShadow(Classes::TNotifyEvent AOnChange) : Tecanvas::TTeeShadow(AOnChange) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TCircledShadow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCircledSeries;
class PASCALIMPLEMENTATION TCircledSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Graphics::TColor FCircleBackColor;
	bool FCircled;
	int FCustomXRadius;
	int FCustomYRadius;
	int FRotationAngle;
	TCircledShadow* FShadow;
	int FXRadius;
	int FYRadius;
	Tecanvas::TView3DOptions* IBack3D;
	int FCircleWidth;
	int FCircleHeight;
	int FCircleXCenter;
	int FCircleYCenter;
	#pragma pack(push, 1)
	Types::TRect FCircleRect;
	#pragma pack(pop)
	
	void __fastcall SetBackupProperties(void);
	void __fastcall SetCircleBackColor(Graphics::TColor Value);
	void __fastcall SetCircled(bool Value);
	void __fastcall SetCustomXRadius(int Value);
	void __fastcall SetCustomYRadius(int Value);
	void __fastcall SetOtherCustomRadius(bool IsXRadius, int Value);
	void __fastcall SetShadow(const TCircledShadow* Value);
	
protected:
	Tecanvas::TTeeGradient* FCircleGradient;
	double IRotDegree;
	bool IAdjustCircleForMarks;
	void __fastcall AdjustCircleRect(void);
	Graphics::TColor __fastcall CalcCircleBackColor(void);
	void __fastcall CalcRadius(void);
	DYNAMIC void __fastcall CheckOtherSeriesMarks(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawCircleGradient(void);
	bool __fastcall HasBackColor(void);
	DYNAMIC void __fastcall InitCustom3DOptions(void);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SetActive(bool Value);
	void __fastcall SetCircleGradient(const Tecanvas::TTeeGradient* Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	DYNAMIC void __fastcall SetParentProperties(bool EnableParentProps);
	void __fastcall SetRotationAngle(const int Value);
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	__property Tecanvas::TTeeGradient* CircleGradient = {read=FCircleGradient, write=SetCircleGradient};
	
public:
	__fastcall virtual TCircledSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCircledSeries(void);
	/*         class method */ static void __fastcall AdjustScreenRatio(TMetaClass* vmt, Tecanvas::TCanvas3D* ACanvas, int AXRadius, int AYRadius, Types::TRect &R);
	void __fastcall AngleToPos(const double Angle, const double AXRadius, const double AYRadius, /* out */ int &X, /* out */ int &Y);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall AssociatedToAxis(Teengine::TChartAxis* Axis);
	double __fastcall PointToAngle(int x, int y);
	double __fastcall PointToRadius(int x, int y);
	void __fastcall Rotate(const int Angle);
	virtual bool __fastcall UseAxis(void);
	__property Graphics::TColor CircleBackColor = {read=FCircleBackColor, write=SetCircleBackColor, default=536870912};
	__property int CircleHeight = {read=FCircleHeight, nodefault};
	__property Types::TRect CircleRect = {read=FCircleRect};
	__property int CircleWidth = {read=FCircleWidth, nodefault};
	__property int CircleXCenter = {read=FCircleXCenter, nodefault};
	__property int CircleYCenter = {read=FCircleYCenter, nodefault};
	__property int RotationAngle = {read=FRotationAngle, write=SetRotationAngle, default=0};
	__property int XRadius = {read=FXRadius, nodefault};
	__property int YRadius = {read=FYRadius, nodefault};
	
__published:
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
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
	__property bool Circled = {read=FCircled, write=SetCircled, default=0};
	__property int CustomXRadius = {read=FCustomXRadius, write=SetCustomXRadius, default=0};
	__property int CustomYRadius = {read=FCustomYRadius, write=SetCustomYRadius, default=0};
	__property TCircledShadow* Shadow = {read=FShadow, write=SetShadow};
};


#pragma pack(push, 1)
struct TPieAngle
{
	double StartAngle;
	double MidAngle;
	double EndAngle;
} ;
#pragma pack(pop)

typedef DynamicArray<TPieAngle >  TPieAngles;

class DELPHICLASS TSliceValueList;
class PASCALIMPLEMENTATION TSliceValueList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	int operator[](int Index) { return Value[Index]; }
	
private:
	HIDESBASE int __fastcall Get(int Index);
	HIDESBASE void __fastcall Put(int Index, int Value);
	
protected:
	Teengine::TChartSeries* OwnerSeries;
	
public:
	__property int Value[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TSliceValueList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSliceValueList(void) : Classes::TList() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPieOtherStyle { poNone, poBelowPercent, poBelowValue };
#pragma option pop

class DELPHICLASS TPieOtherSlice;
class PASCALIMPLEMENTATION TPieOtherSlice : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Graphics::TColor FColor;
	Chart::TChartLegend* FLegend;
	TPieOtherStyle FStyle;
	AnsiString FText;
	double FValue;
	Teengine::TChartSeries* FOwner;
	Chart::TChartLegend* __fastcall GetLegend(void);
	AnsiString __fastcall GetText();
	bool __fastcall IsTextStored(void);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetLegend(const Chart::TChartLegend* Value);
	void __fastcall SetStyle(TPieOtherStyle Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetValue(const double Value);
	
public:
	__fastcall TPieOtherSlice(Teengine::TChartSeries* AOwner);
	__fastcall virtual ~TPieOtherSlice(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property Chart::TChartLegend* Legend = {read=GetLegend, write=SetLegend};
	__property TPieOtherStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property AnsiString Text = {read=GetText, write=SetText, stored=IsTextStored};
	__property double Value = {read=FValue, write=SetValue};
};


class DELPHICLASS TPieMarks;
class PASCALIMPLEMENTATION TPieMarks : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FLegSize;
	bool FVertCenter;
	Teengine::TChartSeries* IParent;
	void __fastcall SetLegSize(const int Value);
	void __fastcall SetVertCenter(const bool Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property bool VertCenter = {read=FVertCenter, write=SetVertCenter, default=0};
	__property int LegSize = {read=FLegSize, write=SetLegSize, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TPieMarks(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TPieMarks(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMultiPie { mpAutomatic, mpDisabled };
#pragma option pop

typedef DynamicArray<int >  Series__81;

class DELPHICLASS TPieSeries;
class PASCALIMPLEMENTATION TPieSeries : public TCircledSeries 
{
	typedef TCircledSeries inherited;
	
private:
	int FAngleSize;
	bool FAutoMarkPosition;
	bool FDark3D;
	int FDarkPen;
	int FDonutPercent;
	TSliceValueList* FExplodedSlice;
	int FExplodeBiggest;
	int FGradientBright;
	TMultiPie FMultiPie;
	TPieOtherSlice* FOtherSlice;
	TPieMarks* FPieMarks;
	TSliceValueList* FSliceHeights;
	bool FUsePatterns;
	DynamicArray<int >  ISortedSlice;
	#pragma pack(push, 1)
	Types::TRect IOldChartRect;
	#pragma pack(pop)
	
	void __fastcall CalcExplodeBiggest(void);
	int __fastcall CompareSlice(int A, int B);
	void __fastcall DisableRotation(void);
	Tecanvas::TChartPen* __fastcall GetPiePen(void);
	Teengine::TChartValueList* __fastcall GetPieValues(void);
	int __fastcall PieCount(void);
	void __fastcall PreparePiePen(int ValueIndex);
	void __fastcall RemoveOtherSlice(void);
	void __fastcall SetAngleSize(int Value);
	void __fastcall SetAutoMarkPosition(bool Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetDarkPen(const int Value);
	void __fastcall SetExplodeBiggest(int Value);
	void __fastcall SetGradientBright(int Value);
	void __fastcall SetGradientColor(Graphics::TColor AColor);
	void __fastcall SetMultiPie(const TMultiPie Value);
	void __fastcall SetOtherSlice(TPieOtherSlice* Value);
	void __fastcall SetPieMarks(const TPieMarks* Value);
	void __fastcall SetPieValues(Teengine::TChartValueList* Value);
	void __fastcall SetUsePatterns(bool Value);
	Graphics::TBrushStyle __fastcall SliceBrushStyle(int ValueIndex);
	int __fastcall SliceEndZ(int ValueIndex);
	void __fastcall SwapSlice(int a, int b);
	
protected:
	DynamicArray<TPieAngle >  FAngles;
	bool IsExploded;
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool Sequential = false);
	void __fastcall CalcAngles(void);
	void __fastcall CalcExplodedOffset(int ValueIndex, /* out */ int &OffsetX, /* out */ int &OffsetY);
	void __fastcall CalcExplodedRadius(int ValueIndex, /* out */ int &AXRadius, /* out */ int &AYRadius);
	virtual void __fastcall CalcSelectionPos(int ValueIndex, /* out */ int &X, /* out */ int &Y);
	virtual void __fastcall CalcZOrder(void);
	void __fastcall CheckAngles(void);
	DYNAMIC void __fastcall CheckOtherSeriesMarks(void);
	virtual void __fastcall ClearLists(void);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DoAfterDrawValues(void);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawPie(int ValueIndex);
	virtual void __fastcall DrawValue(int ValueIndex);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall InitCustom3DOptions(void);
	virtual bool __fastcall MoreSameZOrder(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	void __fastcall SetDonutPercent(int Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	DYNAMIC void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TPieSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TPieSeries(void);
	int __fastcall AddPie(const double AValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall BelongsToOtherSlice(int ValueIndex);
	int __fastcall CalcClickedPie(int x, int y, bool Exploded = true);
	virtual int __fastcall CalcXPos(int ValueIndex);
	DYNAMIC void __fastcall CheckOrder(void);
	virtual void __fastcall Clear(void);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual int __fastcall CountLegendItems(void);
	virtual void __fastcall Delete(int ValueIndex)/* overload */;
	virtual int __fastcall LegendToValueIndex(int LegendIndex);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	DYNAMIC void __fastcall SwapValueIndex(int a, int b);
	virtual void __fastcall CalcFirstLastVisibleIndex(void);
	__property TPieAngles Angles = {read=FAngles};
	__property int DonutPercent = {read=FDonutPercent, write=SetDonutPercent, nodefault};
	__property TSliceValueList* ExplodedSlice = {read=FExplodedSlice};
	__property TSliceValueList* SliceHeight = {read=FSliceHeights};
	
__published:
	__property Active  = {default=1};
	__property int AngleSize = {read=FAngleSize, write=SetAngleSize, default=360};
	__property bool AutoMarkPosition = {read=FAutoMarkPosition, write=SetAutoMarkPosition, default=1};
	__property CircleBackColor  = {default=536870912};
	__property ColorEachPoint  = {default=1};
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property int DarkPen = {read=FDarkPen, write=SetDarkPen, default=0};
	__property int ExplodeBiggest = {read=FExplodeBiggest, write=SetExplodeBiggest, default=0};
	__property Tecanvas::TTeeGradient* Gradient = {read=FCircleGradient, write=SetCircleGradient};
	__property int GradientBright = {read=FGradientBright, write=SetGradientBright, default=0};
	__property TMultiPie MultiPie = {read=FMultiPie, write=SetMultiPie, default=0};
	__property TPieOtherSlice* OtherSlice = {read=FOtherSlice, write=SetOtherSlice};
	__property TPieMarks* PieMarks = {read=FPieMarks, write=SetPieMarks};
	__property Tecanvas::TChartPen* PiePen = {read=GetPiePen, write=SetPen};
	__property Teengine::TChartValueList* PieValues = {read=GetPieValues, write=SetPieValues};
	__property RotationAngle  = {default=0};
	__property bool UsePatterns = {read=FUsePatterns, write=SetUsePatterns, default=0};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	inline void __fastcall  Delete(int Start, int Quantity, bool RemoveGap = false){ TChartSeries::Delete(Start, Quantity, RemoveGap); }
	
};


class DELPHICLASS TFastLineSeries;
class PASCALIMPLEMENTATION TFastLineSeries : public TCustomLineSeries 
{
	typedef TCustomLineSeries inherited;
	
private:
	bool FAutoRepaint;
	bool FDrawAll;
	bool FFastPen;
	bool FIgnoreNulls;
	bool FInvertedStairs;
	bool FStairs;
	HGDIOBJ DCPEN;
	int OldX;
	int OldY;
	void __fastcall DoMove(int X, int Y);
	void __fastcall SetDrawAll(const bool Value);
	void __fastcall SetFastPen(const bool Value);
	void __fastcall SetIgnoreNulls(const bool Value);
	void __fastcall SetInvertedStairs(const bool Value);
	void __fastcall SetStairs(const bool Value);
	
protected:
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	void __fastcall CalcPosition(int ValueIndex, /* out */ int &x, /* out */ int &y);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall NotifyNewValue(Teengine::TChartSeries* Sender, int ValueIndex);
	void __fastcall PrepareCanvas(void);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TFastLineSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	__property bool FastPen = {read=FFastPen, write=SetFastPen, default=0};
	
__published:
	__property Active  = {default=1};
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
	__property bool AutoRepaint = {read=FAutoRepaint, write=FAutoRepaint, default=1};
	__property bool DrawAllPoints = {read=FDrawAll, write=SetDrawAll, default=1};
	__property bool IgnoreNulls = {read=FIgnoreNulls, write=SetIgnoreNulls, default=1};
	__property bool InvertedStairs = {read=FInvertedStairs, write=SetInvertedStairs, default=0};
	__property LinePen ;
	__property bool Stairs = {read=FStairs, write=SetStairs, default=0};
	__property TreatNulls  = {default=2};
	__property XValues ;
	__property YValues ;
public:
	#pragma option push -w-inl
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TFastLineSeries(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE double PiDegree;
static const Graphics::TColor Tee_CircledShadowColor = 0xa0a0a0;
#define bsCylinder (TBarStyle)(3)
extern PACKAGE void __fastcall TeePointerDrawLegend(Teengine::TSeriesPointer* Pointer, Graphics::TColor AColor, const Types::TRect &Rect, bool DrawPen, Teengine::TSeriesPointerStyle AStyle);
extern PACKAGE void __fastcall RegisterTeeStandardSeries(void);

}	/* namespace Series */
using namespace Series;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Series
