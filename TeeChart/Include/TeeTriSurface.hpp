// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTriSurface.pas' rev: 6.00

#ifndef TeeTriSurfaceHPP
#define TeeTriSurfaceHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teetrisurface
{
//-- type declarations -------------------------------------------------------
struct TTriangle;
typedef TTriangle *PTriangle;

#pragma pack(push, 1)
struct TTriangle
{
	int Index;
	Graphics::TColor Color;
	TTriangle *Next;
	TTriangle *Prev;
	Types::TPoint P[3];
	double Z;
} ;
#pragma pack(pop)

class DELPHICLASS ETriSurfaceException;
class PASCALIMPLEMENTATION ETriSurfaceException : public Teengine::ChartException 
{
	typedef Teengine::ChartException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ETriSurfaceException(const AnsiString Msg) : Teengine::ChartException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ETriSurfaceException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Teengine::ChartException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ETriSurfaceException(int Ident)/* overload */ : Teengine::ChartException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ETriSurfaceException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Teengine::ChartException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ETriSurfaceException(const AnsiString Msg, int AHelpContext) : Teengine::ChartException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ETriSurfaceException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Teengine::ChartException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ETriSurfaceException(int Ident, int AHelpContext)/* overload */ : Teengine::ChartException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ETriSurfaceException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Teengine::ChartException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ETriSurfaceException(void) { }
	#pragma option pop
	
};


typedef DynamicArray<int >  TeeTriSurface__3;

typedef DynamicArray<int >  TeeTriSurface__4;

class DELPHICLASS TCustomTriSurfaceSeries;
class PASCALIMPLEMENTATION TCustomTriSurfaceSeries : public Teesurfa::TCustom3DPaletteSeries 
{
	typedef Teesurfa::TCustom3DPaletteSeries inherited;
	
private:
	Tecanvas::TChartHiddenPen* FBorder;
	bool FFastBrush;
	bool FHide;
	Tecanvas::TTeeTransparency FTransp;
	int FNumLines;
	bool ICreated;
	DynamicArray<int >  IPT;
	DynamicArray<int >  IPL;
	TTriangle *Triangles;
	TTriangle *ILastTriangle;
	HGDIOBJ DCBRUSH;
	HDC CanvasDC;
	Tecanvas::TPoint3D __fastcall CalcPointResult(int Index);
	void __fastcall ClearTriangles(void);
	int __fastcall IDxchg(int I1, int I2, int I3, int I4);
	void __fastcall SetBorder(Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetFastBrush(const bool Value);
	void __fastcall SetHide(const bool Value);
	void __fastcall SetTransp(Tecanvas::TTeeTransparency Value);
	void __fastcall TrianglePointsTo2D(const Tecanvas::TPoint3D * P, Types::TPoint * Result);
	
protected:
	bool ImprovedTriangles;
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	bool CacheTriangles;
	int NumTriangles;
	__fastcall virtual TCustomTriSurfaceSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTriSurfaceSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	DYNAMIC int __fastcall NumSampleValues(void);
	void __fastcall TrianglePoints(int TriangleIndex, Tecanvas::TPoint3D * P);
	__property Tecanvas::TChartHiddenPen* Border = {read=FBorder, write=SetBorder};
	__property Brush ;
	__property bool FastBrush = {read=FFastBrush, write=SetFastBrush, default=0};
	__property bool HideTriangles = {read=FHide, write=SetHide, default=1};
	__property Pen ;
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransp, write=SetTransp, default=0};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TTriSurfaceSeries;
class PASCALIMPLEMENTATION TTriSurfaceSeries : public TCustomTriSurfaceSeries 
{
	typedef TCustomTriSurfaceSeries inherited;
	
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
	__property Border ;
	__property Brush ;
	__property EndColor  = {default=16777215};
	__property FastBrush  = {default=0};
	__property HideTriangles  = {default=1};
	__property LegendEvery  = {default=1};
	__property MidColor  = {default=536870911};
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
	__property Transparency  = {default=0};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property OnGetColor ;
public:
	#pragma option push -w-inl
	/* TCustomTriSurfaceSeries.Create */ inline __fastcall virtual TTriSurfaceSeries(Classes::TComponent* AOwner) : TCustomTriSurfaceSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTriSurfaceSeries.Destroy */ inline __fastcall virtual ~TTriSurfaceSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teetrisurface */
using namespace Teetrisurface;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTriSurface
