// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeShape.pas' rev: 6.00

#ifndef TeeShapeHPP
#define TeeShapeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeshape
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TChartShapeXYStyle { xysPixels, xysAxis, xysAxisOrigin };
#pragma option pop

#pragma option push -b-
enum TChartShapeStyle { chasRectangle, chasCircle, chasVertLine, chasHorizLine, chasTriangle, chasInvertTriangle, chasLine, chasDiamond, chasCube, chasCross, chasDiagCross, chasStar, chasPyramid, chasInvertPyramid };
#pragma option pop

#pragma option push -b-
enum TTeeVertAlign { vaTop, vaCenter, vaBottom };
#pragma option pop

class DELPHICLASS TChartShape;
class PASCALIMPLEMENTATION TChartShape : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Classes::TAlignment FAlignment;
	Tecanvas::TTeeFont* FFont;
	Tecanvas::TTeeGradient* FGradient;
	bool FRoundRectangle;
	TChartShapeStyle FStyle;
	Classes::TStrings* FText;
	Tecanvas::TTeeTransparency FTransparency;
	bool FTransparent;
	TTeeVertAlign FVertAlign;
	TChartShapeXYStyle FXYStyle;
	void __fastcall AddDefaultPoints(void);
	double __fastcall GetX0(void);
	double __fastcall GetX1(void);
	double __fastcall GetY0(void);
	double __fastcall GetY1(void);
	void __fastcall ChangeToManual(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetFont(Tecanvas::TTeeFont* Value);
	void __fastcall SetRoundRectangle(bool Value);
	void __fastcall SetShapeRectangle(const Types::TRect &ARect);
	void __fastcall SetStyle(TChartShapeStyle Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetVertAlign(TTeeVertAlign Value);
	void __fastcall SetX0(const double Value);
	void __fastcall SetX1(const double Value);
	void __fastcall SetXYStyle(TChartShapeXYStyle Value);
	void __fastcall SetY0(const double Value);
	void __fastcall SetY1(const double Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall CalcZOrder(void);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	void __fastcall DrawShape(bool Is3D, const Types::TRect &R);
	void __fastcall DrawText(const Types::TRect &R);
	virtual void __fastcall DrawValue(int ValueIndex);
	Types::TRect __fastcall GetAdjustedRectangle();
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual Types::TRect __fastcall GetShapeRectangle();
	virtual bool __fastcall MoreSameZOrder(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	virtual void __fastcall SetText(Classes::TStrings* Value);
	
public:
	__fastcall virtual TChartShape(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartShape(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual bool __fastcall UseAxis(void);
	__property Types::TRect Bounds = {read=GetShapeRectangle, write=SetShapeRectangle};
	
__published:
	__property Active  = {default=1};
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property VertAxis  = {default=0};
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property Brush ;
	__property Tecanvas::TTeeFont* Font = {read=FFont, write=SetFont};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Classes::TStrings* Text = {read=FText, write=SetText};
	__property Pen ;
	__property bool RoundRectangle = {read=FRoundRectangle, write=SetRoundRectangle, default=0};
	__property TChartShapeStyle Style = {read=FStyle, write=SetStyle, default=1};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property TTeeVertAlign VertAlign = {read=FVertAlign, write=SetVertAlign, default=1};
	__property TChartShapeXYStyle XYStyle = {read=FXYStyle, write=SetXYStyle, default=1};
	__property double X0 = {read=GetX0, write=SetX0};
	__property double X1 = {read=GetX1, write=SetX1};
	__property double Y0 = {read=GetY0, write=SetY0};
	__property double Y1 = {read=GetY1, write=SetY1};
	__property XValues ;
	__property YValues ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeshape */
using namespace Teeshape;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeShape
