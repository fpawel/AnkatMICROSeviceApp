// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeMapSeries.pas' rev: 6.00

#ifndef TeeMapSeriesHPP
#define TeeMapSeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teemapseries
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPolygonSeries;
class DELPHICLASS TTeePolygon;
class PASCALIMPLEMENTATION TPolygonSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
protected:
	virtual void __fastcall CanvasChanged(System::TObject* Sender);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall NotifyValue(Teengine::TValueEvent ValueEvent, int ValueIndex);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	
public:
	DYNAMIC void __fastcall FillSampleValues(int NumValues);
	TTeePolygon* __fastcall Polygon(void);
public:
	#pragma option push -w-inl
	/* TChartSeries.Create */ inline __fastcall virtual TPolygonSeries(Classes::TComponent* AOwner) : Teengine::TChartSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TPolygonSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMapSeries;
class DELPHICLASS TTeePolygonList;
class PASCALIMPLEMENTATION TTeePolygonList : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TTeePolygon* operator[](int Index) { return Polygon[Index]; }
	
private:
	HIDESBASE void __fastcall Delete(int Start, int Quantity)/* overload */;
	TTeePolygon* __fastcall Get(int Index);
	TTeePolygon* __fastcall GetByName(const AnsiString AName);
	void __fastcall Put(int Index, const TTeePolygon* Value);
	
public:
	HIDESBASE TTeePolygon* __fastcall Add(void);
	HIDESBASE TMapSeries* __fastcall Owner(void);
	__property TTeePolygon* Polygon[int Index] = {read=Get, write=Put/*, default*/};
	__property TTeePolygon* ByName[AnsiString AName] = {read=GetByName};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TTeePolygonList(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TTeePolygonList(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TTeePolygon* >  TeeMapSeries__5;

class PASCALIMPLEMENTATION TMapSeries : public Teesurfa::TCustom3DPaletteSeries 
{
	typedef Teesurfa::TCustom3DPaletteSeries inherited;
	
public:
	TTeePolygon* operator[](int Index) { return Polygon[Index]; }
	
private:
	int FPointSize;
	Tecanvas::TTeeShadow* FShadow;
	TTeePolygonList* FShapes;
	Tecanvas::TTeeTransparency FTransparency;
	bool FTransparent;
	DynamicArray<TTeePolygon* >  I3DList;
	int __fastcall CompareOrder(int a, int b);
	TTeePolygon* __fastcall GetPolygon(int Index);
	void __fastcall SetPointSize(const int Value);
	void __fastcall SetShadow(const Tecanvas::TTeeShadow* Value);
	void __fastcall SetShapes(const TTeePolygonList* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetTransparent(const bool Value);
	void __fastcall SwapPolygon(int a, int b);
	
protected:
	bool CanSaveData;
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcSelectionPos(int ValueIndex, /* out */ int &X, /* out */ int &Y);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TMapSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TMapSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual void __fastcall Delete(int ValueIndex)/* overload */;
	virtual void __fastcall Delete(int Start, int Quantity, bool RemoveGap = false)/* overload */;
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MinYValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	DYNAMIC void __fastcall SwapValueIndex(int a, int b);
	__property TTeePolygon* Polygon[int Index] = {read=GetPolygon/*, default*/};
	
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
	__property Brush ;
	__property EndColor  = {default=16777215};
	__property MidColor  = {default=536870911};
	__property LegendEvery  = {default=1};
	__property Pen ;
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property int PointSize = {read=FPointSize, write=SetPointSize, default=1};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property TTeePolygonList* Shapes = {read=FShapes, write=SetShapes};
	__property StartColor  = {default=8388608};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property TimesZOrder  = {default=3};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnGetColor ;
	__property OnGetMarkText ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class PASCALIMPLEMENTATION TTeePolygon : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	bool FClosed;
	Tecanvas::TTeeGradient* FGradient;
	bool FParentBrush;
	bool FParentPen;
	TPolygonSeries* FPoints;
	Tecanvas::TTeeTransparency FTransparency;
	Tecanvas::TChartBrush* __fastcall GetBrush(void);
	Graphics::TColor __fastcall GetColor(void);
	Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	Tecanvas::TChartPen* __fastcall GetPen(void);
	AnsiString __fastcall GetText();
	bool __fastcall GetTransparent(void);
	double __fastcall GetZ(void);
	Types::TRect __fastcall PointRect();
	void __fastcall SetBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetClosed(const bool Value);
	void __fastcall SetColor(const Graphics::TColor Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetParentBrush(const bool Value);
	void __fastcall SetParentPen(const bool Value);
	void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetTransparent(const bool Value);
	void __fastcall SetZ(const double Value);
	
protected:
	DynamicArray<Types::TPoint >  IPoints;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall DoDraw(Tecanvas::TCanvas3D* ACanvas, int Index, Graphics::TColor AColor, Tecanvas::TTeeTransparency ATransp, bool DrawGradient);
	
public:
	TMapSeries* ParentSeries;
	__fastcall virtual TTeePolygon(Classes::TCollection* Collection);
	__fastcall virtual ~TTeePolygon(void);
	int __fastcall AddXY(const Tecanvas::TFloatPoint &Point)/* overload */;
	int __fastcall AddXY(const double X, const double Y)/* overload */;
	void __fastcall Draw(Tecanvas::TCanvas3D* ACanvas, int ValueIndex);
	Tecanvas::TPointArray __fastcall GetPoints();
	bool __fastcall Visible(void);
	Types::TRect __fastcall Bounds();
	__property TPolygonSeries* Points = {read=FPoints};
	
__published:
	__property Tecanvas::TChartBrush* Brush = {read=GetBrush, write=SetBrush};
	__property bool Closed = {read=FClosed, write=SetClosed, default=1};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, default=16777215};
	__property Tecanvas::TTeeGradient* Gradient = {read=GetGradient, write=SetGradient};
	__property bool ParentBrush = {read=FParentBrush, write=SetParentBrush, default=1};
	__property bool ParentPen = {read=FParentPen, write=SetParentPen, default=1};
	__property Tecanvas::TChartPen* Pen = {read=GetPen, write=SetPen};
	__property AnsiString Text = {read=GetText, write=SetText};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, default=0};
	__property double Z = {read=GetZ, write=SetZ};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE double __fastcall PolygonArea(const Tecanvas::TPointArray P);
extern PACKAGE _POINTFLOAT __fastcall PolygonCentroid(const Tecanvas::TPointArray P);

}	/* namespace Teemapseries */
using namespace Teemapseries;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeMapSeries
