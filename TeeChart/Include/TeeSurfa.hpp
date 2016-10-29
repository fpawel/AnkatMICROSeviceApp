// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSurfa.pas' rev: 6.00

#ifndef TeeSurfaHPP
#define TeeSurfaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeeFilters.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teesurfa
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<DynamicArray<double > >  TArrayGrid;

class DELPHICLASS TCustom3DSeries;
class PASCALIMPLEMENTATION TCustom3DSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	int FTimesZOrder;
	Teengine::TChartValueList* FZValues;
	bool __fastcall BackFaced(void);
	double __fastcall GetZValue(int Index);
	void __fastcall SetTimesZOrder(const int Value);
	void __fastcall SetZValue(int Index, const double Value);
	void __fastcall SetZValues(const Teengine::TChartValueList* Value);
	
protected:
	virtual void __fastcall CalcZOrder(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual Teengine::TChartValueList* __fastcall ValueListOfAxis(Teengine::TChartAxis* Axis);
	
public:
	__fastcall virtual TCustom3DSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	HIDESBASE void __fastcall AddArray(const TArrayGrid Values)/* overload */;
	int __fastcall AddXYZ(const double AX, const double AY, const double AZ)/* overload */;
	virtual int __fastcall AddXYZ(const double AX, const double AY, const double AZ, const AnsiString AXLabel, Graphics::TColor AColor)/* overload */;
	virtual bool __fastcall AssociatedToAxis(Teengine::TChartAxis* Axis);
	int __fastcall CalcZPos(int ValueIndex);
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinZValue(void);
	__property double ZValue[int Index] = {read=GetZValue, write=SetZValue};
	__property int TimesZOrder = {read=FTimesZOrder, write=SetTimesZOrder, default=3};
	__property Teengine::TChartValueList* ZValues = {read=FZValues, write=SetZValues};
public:
	#pragma option push -w-inl
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TCustom3DSeries(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  AddArray(const double * Values, const int Values_Size){ return TChartSeries::AddArray(Values, Values_Size); }
	inline int __fastcall  AddArray(const double * XValues, const int XValues_Size, const double * YValues, const int YValues_Size){ return TChartSeries::AddArray(XValues, XValues_Size, YValues, YValues_Size); }
	
};


#pragma pack(push, 1)
struct TGridPalette
{
	double UpToValue;
	Graphics::TColor Color;
} ;
#pragma pack(pop)

typedef DynamicArray<TGridPalette >  TCustom3DPalette;

#pragma option push -b-
enum TTeePaletteStyle { psPale, psStrong, psGrayScale, psInvGray, psRainbow, psCustom };
#pragma option pop

typedef void __fastcall (__closure *TChartSurfaceGetColor)(Teengine::TChartSeries* Sender, int ValueIndex, Graphics::TColor &Color);

class DELPHICLASS TCustom3DPaletteSeries;
class PASCALIMPLEMENTATION TCustom3DPaletteSeries : public TCustom3DSeries 
{
	typedef TCustom3DSeries inherited;
	
private:
	Graphics::TColor FEndColor;
	Graphics::TColor FMidColor;
	DynamicArray<TGridPalette >  FPalette;
	int FLegendEvery;
	double FPaletteMin;
	double FPaletteStep;
	int FPaletteSteps;
	TTeePaletteStyle FPaletteStyle;
	Graphics::TColor FStartColor;
	bool FUseColorRange;
	bool FUsePalette;
	bool FUsePaletteMin;
	TChartSurfaceGetColor FOnGetColor;
	int IRangeRed;
	int IEndRed;
	int IMidRed;
	int IRangeMidRed;
	int IRangeGreen;
	int IEndGreen;
	int IMidGreen;
	int IRangeMidGreen;
	int IRangeBlue;
	int IEndBlue;
	int IMidBlue;
	int IRangeMidBlue;
	double IValueRangeInv;
	void __fastcall CalcColorRange(void);
	void __fastcall CalcValueRange(void);
	void __fastcall CheckPaletteEmpty(void);
	int __fastcall LegendPaletteIndex(int LegendIndex);
	Graphics::TColor __fastcall RangePercent(const double Percent);
	void __fastcall ReadPalette(Classes::TStream* Stream);
	void __fastcall SetEndColor(const Graphics::TColor Value);
	void __fastcall SetGalleryPalette(void);
	void __fastcall SetLegendEvery(const int Value);
	void __fastcall SetMidColor(const Graphics::TColor Value);
	void __fastcall SetPalette(const TCustom3DPalette Value);
	void __fastcall SetPaletteMin(const double Value);
	void __fastcall SetPaletteStep(const double Value);
	void __fastcall SetPaletteSteps(const int Value);
	void __fastcall SetPaletteStyle(const TTeePaletteStyle Value);
	void __fastcall SetStartColor(const Graphics::TColor Value);
	void __fastcall SetUseColorRange(const bool Value);
	void __fastcall SetUsePalette(const bool Value);
	void __fastcall SetUsePaletteMin(const bool Value);
	void __fastcall WritePalette(Classes::TStream* Stream);
	
protected:
	double PaletteRange;
	virtual void __fastcall AddValues(Teengine::TChartSeries* Source);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	void __fastcall GeneratePalette(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual Graphics::TColor __fastcall GetValueColor(int ValueIndex);
	Graphics::TColor __fastcall GetValueColorValue(const double AValue);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	double RedFactor;
	double GreenFactor;
	double BlueFactor;
	__fastcall virtual TCustom3DPaletteSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustom3DPaletteSeries(void);
	int __fastcall AddPalette(const double AValue, Graphics::TColor AColor)/* overload */;
	void __fastcall AddPalette(const Teeprocs::TColorArray APalette)/* overload */;
	void __fastcall AddPalette(const Graphics::TColor * APalette, const int APalette_Size)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	void __fastcall ClearPalette(void);
	virtual int __fastcall CountLegendItems(void);
	void __fastcall CreateDefaultPalette(int NumSteps = 0x0);
	void __fastcall CreateRangePalette(void);
	Graphics::TColor __fastcall GetSurfacePaletteColor(const double Y);
	void __fastcall InvertPalette(void);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	__property Graphics::TColor EndColor = {read=FEndColor, write=SetEndColor, default=16777215};
	__property Graphics::TColor MidColor = {read=FMidColor, write=SetMidColor, default=536870911};
	__property int LegendEvery = {read=FLegendEvery, write=SetLegendEvery, default=1};
	__property TCustom3DPalette Palette = {read=FPalette, write=SetPalette};
	__property double PaletteMin = {read=FPaletteMin, write=SetPaletteMin};
	__property double PaletteStep = {read=FPaletteStep, write=SetPaletteStep};
	__property int PaletteSteps = {read=FPaletteSteps, write=SetPaletteSteps, default=32};
	__property TTeePaletteStyle PaletteStyle = {read=FPaletteStyle, write=SetPaletteStyle, default=0};
	__property Graphics::TColor StartColor = {read=FStartColor, write=SetStartColor, default=8388608};
	__property bool UseColorRange = {read=FUseColorRange, write=SetUseColorRange, default=1};
	__property bool UsePalette = {read=FUsePalette, write=SetUsePalette, default=0};
	__property bool UsePaletteMin = {read=FUsePaletteMin, write=SetUsePaletteMin, default=0};
	__property TChartSurfaceGetColor OnGetColor = {read=FOnGetColor, write=FOnGetColor};
};


typedef double __fastcall (__closure *TChartSurfaceGetY)(Teengine::TChartSeries* Sender, int X, int Z);

typedef DynamicArray<int >  TeeSurfa__4;

typedef DynamicArray<DynamicArray<int > >  TeeSurfa__5;

class DELPHICLASS TCustom3DGridSeries;
class PASCALIMPLEMENTATION TCustom3DGridSeries : public TCustom3DPaletteSeries 
{
	typedef TCustom3DPaletteSeries inherited;
	
private:
	bool FIrregularGrid;
	int FNumXValues;
	int FNumZValues;
	TChartSurfaceGetY FOnGetYValue;
	int FXStartIndex;
	int FZStartIndex;
	int INextXCell;
	int INextZCell;
	bool __fastcall ExistFourGridIndex(int X, int Z);
	void __fastcall InitGridIndex(int XCount, int ZCount);
	void __fastcall SetIrregularGrid(const bool Value);
	void __fastcall SetNumXValues(int Value);
	void __fastcall SetNumZValues(int Value);
	double __fastcall GetValue(int X, int Z);
	void __fastcall SetValue(int X, int Z, const double Value);
	
protected:
	int ValueIndex0;
	int ValueIndex1;
	int ValueIndex2;
	int ValueIndex3;
	bool IInGallery;
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall AddValues(Teengine::TChartSeries* Source);
	virtual void __fastcall DoBeforeDrawChart(void);
	bool __fastcall CanCreateValues(void);
	
public:
	DynamicArray<DynamicArray<int > >  GridIndex;
	bool ReuseGridIndex;
	__fastcall virtual TCustom3DGridSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	virtual void __fastcall CreateValues(int NumX, int NumZ);
	void __fastcall FillGridIndex(void)/* overload */;
	void __fastcall FillGridIndex(int StartIndex)/* overload */;
	virtual double __fastcall GetXZValue(int X, int Z);
	DYNAMIC bool __fastcall IsValidSeriesSource(Teengine::TChartSeries* Value);
	DYNAMIC int __fastcall NumSampleValues(void);
	void __fastcall ReCreateValues(void);
	__property bool IrregularGrid = {read=FIrregularGrid, write=SetIrregularGrid, default=0};
	__property int NumXValues = {read=FNumXValues, write=SetNumXValues, default=10};
	__property int NumZValues = {read=FNumZValues, write=SetNumZValues, default=10};
	__property double Value[int X][int Z] = {read=GetValue, write=SetValue};
	__property TChartSurfaceGetY OnGetYValue = {read=FOnGetYValue, write=FOnGetYValue};
public:
	#pragma option push -w-inl
	/* TCustom3DPaletteSeries.Destroy */ inline __fastcall virtual ~TCustom3DGridSeries(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TCellsOrientation
{
	int InitX;
	int EndX;
	int IncX;
	int InitZ;
	int EndZ;
	int IncZ;
} ;
#pragma pack(pop)

class DELPHICLASS TSurfaceSeries;
class PASCALIMPLEMENTATION TSurfaceSeries : public TCustom3DGridSeries 
{
	typedef TCustom3DGridSeries inherited;
	
private:
	bool FDotFrame;
	bool FFastBrush;
	bool FHideCells;
	Tecanvas::TChartBrush* FSideBrush;
	Tecanvas::TChartHiddenPen* FSideLines;
	bool FSmoothPalette;
	Tecanvas::TTeeTransparency FTransparency;
	bool FWaterFall;
	Tecanvas::TChartPen* FWaterLines;
	bool FWireFrame;
	bool FSameBrush;
	Teengine::TAxisCalcPos ICalcX;
	Teengine::TAxisCalcPos ICalcY;
	DynamicArray<double >  IXValue;
	DynamicArray<double >  IYValue;
	void __fastcall PrepareCalcPos(void);
	void __fastcall SetDotFrame(bool Value);
	void __fastcall SetFastBrush(const bool Value);
	void __fastcall SetHideCells(const bool Value);
	void __fastcall SetSideBrush(Tecanvas::TChartBrush* Value);
	void __fastcall SetSideLines(Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetSmoothPalette(bool Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetWaterFall(bool Value);
	void __fastcall SetWireFrame(bool Value);
	void __fastcall SetWaterLines(const Tecanvas::TChartPen* Value);
	
protected:
	Types::TPoint Points[4];
	bool IsFastBrush;
	HGDIOBJ DCBRUSH;
	HDC CanvasDC;
	Tecanvas::TTeeBlend* IBlender;
	Types::TPoint __fastcall CalcPointPos(const int Index);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawCell(int x, int z);
	virtual void __fastcall DrawSidePortion(Types::TPoint * P, int z0, int z1);
	virtual void __fastcall DrawValue(int ValueIndex);
	bool __fastcall FastCalcPoints(int x, int z, Tecanvas::TPoint3D &P0, Tecanvas::TPoint3D &P1, Graphics::TColor &Color0, Graphics::TColor &Color1);
	bool __fastcall FourGridIndex(int x, int z);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	void __fastcall PointsTo2D(int Z0, int Z1, Types::TPoint * P);
	void __fastcall PrepareFastBrush(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	void __fastcall SetBrushColor(const Graphics::TColor AColor);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	virtual bool __fastcall ShouldDrawFast(void);
	virtual bool __fastcall ShouldDrawSides(void);
	
public:
	__fastcall virtual TSurfaceSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TSurfaceSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TCellsOrientation __fastcall CellsOrientation();
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	__property bool WaterFall = {read=FWaterFall, write=SetWaterFall, default=0};
	__property Tecanvas::TChartPen* WaterLines = {read=FWaterLines, write=SetWaterLines};
	
__published:
	__property Active  = {default=1};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property bool FastBrush = {read=FFastBrush, write=SetFastBrush, default=0};
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
	__property Brush ;
	__property bool DotFrame = {read=FDotFrame, write=SetDotFrame, default=0};
	__property EndColor  = {default=16777215};
	__property bool HideCells = {read=FHideCells, write=SetHideCells, default=0};
	__property IrregularGrid  = {default=0};
	__property MidColor  = {default=536870911};
	__property NumXValues  = {default=10};
	__property NumZValues  = {default=10};
	__property LegendEvery  = {default=1};
	__property Pen ;
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property PaletteStyle  = {default=0};
	__property Tecanvas::TChartBrush* SideBrush = {read=FSideBrush, write=SetSideBrush};
	__property Tecanvas::TChartHiddenPen* SideLines = {read=FSideLines, write=SetSideLines};
	__property bool SmoothPalette = {read=FSmoothPalette, write=SetSmoothPalette, default=0};
	__property StartColor  = {default=8388608};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property bool WireFrame = {read=FWireFrame, write=SetWireFrame, default=0};
	__property TimesZOrder  = {default=3};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property OnGetYValue ;
	__property OnGetColor ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TContourSeries;
typedef void __fastcall (__closure *TOnBeforeDrawLevelEvent)(TContourSeries* Sender, int LevelIndex);

typedef void __fastcall (__closure *TOnGetLevelEvent)(TContourSeries* Sender, int LevelIndex, double &Value, Graphics::TColor &Color);

#pragma pack(push, 1)
struct TLevelPoint
{
	double X;
	double Y;
} ;
#pragma pack(pop)

typedef DynamicArray<TLevelPoint >  TeeSurfa__7;

#pragma pack(push, 1)
struct TLevelSegment
{
	int Count;
	DynamicArray<TLevelPoint >  Points;
} ;
#pragma pack(pop)

typedef DynamicArray<TLevelSegment >  TLevelSegments;

class DELPHICLASS TContourLevel;
class PASCALIMPLEMENTATION TContourLevel : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Graphics::TColor FColor;
	Tecanvas::TChartPen* FPen;
	double FUpTo;
	TContourSeries* ISeries;
	int FSegmentCount;
	DynamicArray<TLevelSegment >  FSegments;
	void __fastcall CheckAuto(void);
	Tecanvas::TChartPen* __fastcall GetPen(void);
	bool __fastcall IsPenStored(void);
	void __fastcall SetColor(const Graphics::TColor Value);
	void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetUpTo(const double Value);
	
protected:
	Graphics::TColor __fastcall InternalColor(void);
	Tecanvas::TChartPen* __fastcall InternalPen(void);
	
public:
	__fastcall virtual TContourLevel(Classes::TCollection* Collection);
	__fastcall virtual ~TContourLevel(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall ClearSegments(void);
	bool __fastcall Clicked(int x, int y, int &SegmentIndex, int &PointIndex);
	bool __fastcall ClickedSegment(int x, int y, int SegmentIndex, int &PointIndex);
	Tecanvas::TPointArray __fastcall GetSegmentPoints(int SegmentIndex);
	bool __fastcall DefaultPen(void);
	int __fastcall SegmentCount(void);
	__property TLevelSegments Segments = {read=FSegments};
	
__published:
	__property Graphics::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property Tecanvas::TChartPen* Pen = {read=GetPen, write=SetPen, stored=IsPenStored};
	__property double UpToValue = {read=FUpTo, write=SetUpTo};
};


class DELPHICLASS TContourLevels;
class PASCALIMPLEMENTATION TContourLevels : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TContourLevel* operator[](int Index) { return Items[Index]; }
	
private:
	TContourLevel* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TContourLevel* Value);
	
public:
	TContourLevel* __fastcall AddLevel(const double Value, Graphics::TColor Color);
	int __fastcall Clicked(int x, int y, int &SegmentIndex, int &PointIndex);
	__property TContourLevel* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TContourLevels(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TContourLevels(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSmoothPoints;
class PASCALIMPLEMENTATION TSmoothPoints : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FActive;
	Teengine::TChartSeries* ISeries;
	bool FInterpolate;
	void __fastcall SetActive(const bool Value);
	void __fastcall SetInterpolate(const bool Value);
	
public:
	int Factor;
	__fastcall TSmoothPoints(Teengine::TChartSeries* Parent);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Tecanvas::TPointArray __fastcall Calculate(const Types::TPoint * P, const int P_Size);
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool Interpolate = {read=FInterpolate, write=SetInterpolate, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSmoothPoints(void) { }
	#pragma option pop
	
};


class DELPHICLASS TContourMarks;
class PASCALIMPLEMENTATION TContourMarks : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FAntiOverlap;
	bool FAtSegments;
	bool FColorLevel;
	int FDensity;
	int FMargin;
	Teengine::TChartSeries* IContour;
	bool __fastcall GetVisible(void);
	void __fastcall SetAntiOverlap(const bool Value);
	void __fastcall SetAtSegments(const bool Value);
	void __fastcall SetColorLevel(const bool Value);
	void __fastcall SetDensity(const int Value);
	void __fastcall SetMargin(const int Value);
	void __fastcall SetVisible(const bool Value);
	
public:
	__fastcall TContourMarks(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property bool AntiOverlap = {read=FAntiOverlap, write=SetAntiOverlap, default=0};
	__property bool AtSegments = {read=FAtSegments, write=SetAtSegments, default=1};
	__property bool ColorLevel = {read=FColorLevel, write=SetColorLevel, default=0};
	__property int Margin = {read=FMargin, write=SetMargin, default=0};
	__property int Density = {read=FDensity, write=SetDensity, default=4};
	__property bool Visible = {read=GetVisible, write=SetVisible, stored=false, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TContourMarks(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TContourSeries : public TCustom3DGridSeries 
{
	typedef TCustom3DGridSeries inherited;
	
private:
	bool FAutomaticLevels;
	TContourMarks* FContourMarks;
	bool FLegendLines;
	TContourLevels* FLevels;
	Graphics::TColor FLinesColor;
	int FNumLevels;
	Teengine::TSeriesPointer* FPointer;
	TSmoothPoints* FSmoothing;
	Tecanvas::TTeeTransparency FTransparency;
	double FYPosition;
	bool FYPositionLevel;
	TOnBeforeDrawLevelEvent FOnBeforeDrawLevel;
	TOnGetLevelEvent FOnGetLevel;
	bool IModifyingLevels;
	Tecanvas::TChartHiddenPen* FFrame;
	void __fastcall ClearAutoLevels(void);
	int __fastcall GetNumLevels(void);
	bool __fastcall IsLevelsStored(void);
	TContourLevel* __fastcall LegendLevel(int Index);
	void __fastcall SetAutomaticLevels(const bool Value);
	void __fastcall SetContourMarks(const TContourMarks* Value);
	void __fastcall SetFrame(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetLegendLines(const bool Value);
	void __fastcall SetLevels(const TContourLevels* Value);
	void __fastcall SetLinesColor(const Graphics::TColor Value);
	void __fastcall SetNumLevels(int Value);
	void __fastcall SetPointer(const Teengine::TSeriesPointer* Value);
	void __fastcall SetSmoothing(const TSmoothPoints* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetYPosition(const double Value);
	void __fastcall SetYPositionLevel(bool Value);
	void __fastcall TryCreateLevels(void);
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawMarks(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall NotifyValue(Teengine::TValueEvent ValueEvent, int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TContourSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TContourSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual int __fastcall CountLegendItems(void);
	void __fastcall CreateAutoLevels(void);
	Teengine::TChartAxis* __fastcall GetZAxis(void);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Active  = {default=1};
	__property bool AutomaticLevels = {read=FAutomaticLevels, write=SetAutomaticLevels, default=1};
	__property ColorEachPoint  = {default=1};
	__property ColorSource ;
	__property TContourMarks* ContourMarks = {read=FContourMarks, write=SetContourMarks};
	__property Cursor  = {default=0};
	__property Tecanvas::TChartHiddenPen* Frame = {read=FFrame, write=SetFrame};
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
	__property EndColor  = {default=16777215};
	__property IrregularGrid  = {default=0};
	__property LegendEvery  = {default=1};
	__property bool LegendLines = {read=FLegendLines, write=SetLegendLines, default=0};
	__property TContourLevels* Levels = {read=FLevels, write=SetLevels, stored=IsLevelsStored};
	__property Graphics::TColor LinesColor = {read=FLinesColor, write=SetLinesColor, default=0};
	__property MidColor  = {default=536870911};
	__property int NumLevels = {read=GetNumLevels, write=SetNumLevels, default=10};
	__property NumXValues  = {default=10};
	__property NumZValues  = {default=10};
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property PaletteStyle  = {default=0};
	__property Pen ;
	__property Teengine::TSeriesPointer* Pointer = {read=FPointer, write=SetPointer};
	__property TSmoothPoints* Smoothing = {read=FSmoothing, write=SetSmoothing};
	__property StartColor  = {default=8388608};
	__property TimesZOrder  = {default=3};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property XValues ;
	__property double YPosition = {read=FYPosition, write=SetYPosition};
	__property bool YPositionLevel = {read=FYPositionLevel, write=SetYPositionLevel, default=0};
	__property YValues ;
	__property ZValues ;
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
	__property TOnBeforeDrawLevelEvent OnBeforeDrawLevel = {read=FOnBeforeDrawLevel, write=FOnBeforeDrawLevel};
	__property OnGetYValue ;
	__property TOnGetLevelEvent OnGetLevel = {read=FOnGetLevel, write=FOnGetLevel};
	__property Brush ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TWaterFallSeries;
class PASCALIMPLEMENTATION TWaterFallSeries : public TSurfaceSeries 
{
	typedef TSurfaceSeries inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TWaterFallSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property WaterFall  = {default=1};
	__property WaterLines ;
public:
	#pragma option push -w-inl
	/* TSurfaceSeries.Destroy */ inline __fastcall virtual ~TWaterFallSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TColorGridSeries;
class PASCALIMPLEMENTATION TColorGridSeries : public TCustom3DGridSeries 
{
	typedef TCustom3DGridSeries inherited;
	
private:
	Graphics::TBitmap* FBitmap;
	bool FCentered;
	Tecanvas::TCanvas3DPlane FPlane3D;
	Tecanvas::TChartHiddenPen* FFrame;
	int FPosition;
	bool FSmoothBitmap;
	int FXGridEvery;
	int FZGridEvery;
	Tecanvas::TTeeTransparency FTransparency;
	bool FXRegularSteps;
	bool FZRegularSteps;
	double FXRegularStep;
	double FZRegularStep;
	double __fastcall CalcMaxValue(const double Value);
	double __fastcall CalcMinValue(const double Value);
	void __fastcall SetBitmap(const Graphics::TBitmap* Value);
	void __fastcall SetCentered(const bool Value);
	void __fastcall SetPlane3D(const Tecanvas::TCanvas3DPlane Value);
	void __fastcall SetFrame(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetPosition(const int Value);
	void __fastcall SetSmoothBitmap(const bool Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetXGridEvery(const int Value);
	void __fastcall SetZGridEvery(const int Value);
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TColorGridSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TColorGridSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Types::TRect __fastcall CellBounds(int ValueIndex)/* overload */;
	Types::TRect __fastcall CellBounds(int x, int z)/* overload */;
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int X, int Y)/* overload */;
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MinZValue(void);
	virtual double __fastcall MaxZValue(void);
	__property Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap};
	
__published:
	__property Active  = {default=1};
	__property bool CenteredPoints = {read=FCentered, write=SetCentered, default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Tecanvas::TCanvas3DPlane DrawPlane3D = {read=FPlane3D, write=SetPlane3D, default=2};
	__property int DrawPosition = {read=FPosition, write=SetPosition, default=0};
	__property Tecanvas::TChartHiddenPen* Frame = {read=FFrame, write=SetFrame};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property bool SmoothBitmap = {read=FSmoothBitmap, write=SetSmoothBitmap, default=0};
	__property Title ;
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property int XGridEvery = {read=FXGridEvery, write=SetXGridEvery, default=1};
	__property XLabelsSource ;
	__property int ZGridEvery = {read=FZGridEvery, write=SetZGridEvery, default=1};
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
	__property EndColor  = {default=16777215};
	__property IrregularGrid  = {default=0};
	__property MidColor  = {default=536870911};
	__property NumXValues  = {default=10};
	__property NumZValues  = {default=10};
	__property LegendEvery  = {default=1};
	__property Pen ;
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property PaletteStyle  = {default=0};
	__property StartColor  = {default=8388608};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property TimesZOrder  = {default=3};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property OnGetYValue ;
	__property OnGetColor ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TVector3DSeries;
class PASCALIMPLEMENTATION TVector3DSeries : public TCustom3DPaletteSeries 
{
	typedef TCustom3DPaletteSeries inherited;
	
private:
	int FArrowHeight;
	int FArrowWidth;
	Tecanvas::TChartHiddenPen* FStartArrow;
	Tecanvas::TChartPen* FEndArrow;
	Teengine::TChartValueList* FEndXValues;
	Teengine::TChartValueList* FEndYValues;
	Teengine::TChartValueList* FEndZValues;
	void __fastcall SetArrowHeight(const int Value);
	void __fastcall SetArrowWidth(const int Value);
	void __fastcall SetEndXValues(Teengine::TChartValueList* Value);
	void __fastcall SetEndYValues(Teengine::TChartValueList* Value);
	void __fastcall SetEndZValues(Teengine::TChartValueList* Value);
	void __fastcall SetEndArrow(const Tecanvas::TChartPen* Value);
	void __fastcall SetStartArrow(const Tecanvas::TChartHiddenPen* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TVector3DSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TVector3DSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall AddVector(const double X0, const double Y0, const double Z0, const double X1, const double Y1, const double Z1, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000))/* overload */;
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinZValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	
__published:
	__property Active  = {default=1};
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
	__property Brush ;
	__property EndColor  = {default=16777215};
	__property MidColor  = {default=536870911};
	__property LegendEvery  = {default=1};
	__property Pen ;
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property PaletteStyle  = {default=0};
	__property StartColor  = {default=8388608};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property TimesZOrder  = {default=3};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property OnGetColor ;
	__property int ArrowHeight = {read=FArrowHeight, write=SetArrowHeight, default=4};
	__property int ArrowWidth = {read=FArrowWidth, write=SetArrowWidth, default=4};
	__property Tecanvas::TChartPen* EndArrow = {read=FEndArrow, write=SetEndArrow};
	__property Teengine::TChartValueList* EndXValues = {read=FEndXValues, write=SetEndXValues};
	__property Teengine::TChartValueList* EndYValues = {read=FEndYValues, write=SetEndYValues};
	__property Teengine::TChartValueList* EndZValues = {read=FEndZValues, write=SetEndZValues};
	__property Tecanvas::TChartHiddenPen* StartArrow = {read=FStartArrow, write=SetStartArrow};
};


#pragma option push -b-
enum TTowerStyle { tsCube, tsRectangle, tsCover, tsCylinder, tsArrow, tsCone, tsPyramid, tsSlantCube };
#pragma option pop

class DELPHICLASS TTowerSeries;
class PASCALIMPLEMENTATION TTowerSeries : public TCustom3DGridSeries 
{
	typedef TCustom3DGridSeries inherited;
	
private:
	bool FDark3D;
	double FOrigin;
	int FPercDepth;
	int FPercWidth;
	TTowerStyle FTowerStyle;
	Tecanvas::TTeeTransparency FTransparency;
	bool FUseOrigin;
	double IOffW;
	double IOffD;
	Types::TRect __fastcall CalcCell(int &AIndex, int &ATop, int &ABottom, int &Z0, int &Z1);
	void __fastcall SetDark3D(const bool Value);
	void __fastcall SetOrigin(const double Value);
	void __fastcall SetPercDepth(const int Value);
	void __fastcall SetPercWidth(const int Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetUseOrigin(bool Value);
	void __fastcall SetTowerStyle(const TTowerStyle Value);
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawAllValues(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TTowerSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int X, int Y)/* overload */;
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinZValue(void);
	virtual double __fastcall MaxZValue(void);
	
__published:
	__property Active  = {default=1};
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
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property int PercentDepth = {read=FPercDepth, write=SetPercDepth, default=100};
	__property double Origin = {read=FOrigin, write=SetOrigin};
	__property TTowerStyle TowerStyle = {read=FTowerStyle, write=SetTowerStyle, default=0};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property int PercentWidth = {read=FPercWidth, write=SetPercWidth, default=100};
	__property bool UseOrigin = {read=FUseOrigin, write=SetUseOrigin, default=0};
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
	__property EndColor  = {default=16777215};
	__property IrregularGrid  = {default=0};
	__property MidColor  = {default=536870911};
	__property NumXValues  = {default=10};
	__property NumZValues  = {default=10};
	__property LegendEvery  = {default=1};
	__property Pen ;
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property PaletteStyle  = {default=0};
	__property StartColor  = {default=8388608};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property TimesZOrder  = {default=3};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property OnGetYValue ;
	__property OnGetColor ;
public:
	#pragma option push -w-inl
	/* TCustom3DPaletteSeries.Destroy */ inline __fastcall virtual ~TTowerSeries(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TSurfaceSides;
class PASCALIMPLEMENTATION TSurfaceSides : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FLevels;
	Tecanvas::TChartHiddenPen* FPen;
	TSurfaceSeries* ISeries;
	void __fastcall CanvasChanged(System::TObject* Sender);
	Tecanvas::TChartBrush* __fastcall GetBrush(void);
	void __fastcall SetBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetLevels(const bool Value);
	void __fastcall SetPen(const Tecanvas::TChartHiddenPen* Value);
	
public:
	__fastcall TSurfaceSides(TSurfaceSeries* Series);
	__fastcall virtual ~TSurfaceSides(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Tecanvas::TChartBrush* Brush = {read=GetBrush, write=SetBrush};
	__property bool Levels = {read=FLevels, write=SetLevels, default=1};
	__property Tecanvas::TChartHiddenPen* Pen = {read=FPen, write=SetPen};
};


class DELPHICLASS TIsoSurfaceSeries;
class PASCALIMPLEMENTATION TIsoSurfaceSeries : public TSurfaceSeries 
{
	typedef TSurfaceSeries inherited;
	
private:
	Tecanvas::TChartPen* FBandPen;
	TSurfaceSides* FSides;
	bool FUseY;
	double FYPosition;
	DynamicArray<double >  xv;
	DynamicArray<double >  zv;
	DynamicArray<double >  v;
	bool HasImage;
	bool ITransp;
	int PaletteLength;
	DynamicArray<Types::TPoint >  IPoints2D;
	int ICalcYPos;
	void __fastcall SetBandPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetSides(const TSurfaceSides* Value);
	void __fastcall SetUseY(const bool Value);
	void __fastcall SetYPosition(const double Value);
	
protected:
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawCell(int x, int z);
	virtual void __fastcall DrawSidePortion(Types::TPoint * P, int Z0, int Z1);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual bool __fastcall ShouldDrawFast(void);
	virtual bool __fastcall ShouldDrawSides(void);
	
public:
	__fastcall virtual TIsoSurfaceSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TIsoSurfaceSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Tecanvas::TChartPen* BandPen = {read=FBandPen, write=SetBandPen};
	__property TSurfaceSides* Sides = {read=FSides, write=SetSides};
	__property UseColorRange  = {default=0};
	__property UsePalette  = {default=1};
	__property bool UseYPosition = {read=FUseY, write=SetUseY, default=0};
	__property double YPosition = {read=FYPosition, write=SetYPosition};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesurfa */
using namespace Teesurfa;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSurfa
