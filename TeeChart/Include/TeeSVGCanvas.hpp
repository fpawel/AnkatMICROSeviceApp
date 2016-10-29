// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSVGCanvas.pas' rev: 6.00

#ifndef TeeSVGCanvasHPP
#define TeeSVGCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teesvgcanvas
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSVGCanvas;
class PASCALIMPLEMENTATION TSVGCanvas : public Tecanvas::TTeeCanvas3D 
{
	typedef Tecanvas::TTeeCanvas3D inherited;
	
private:
	Graphics::TColor FBackColor;
	Tecanvas::TCanvasBackMode FBackMode;
	int FTextAlign;
	int FX;
	int FY;
	Classes::TStrings* FStrings;
	int IClipCount;
	int IClipStack;
	int IGradientCount;
	Graphics::TPenStyle IPenStyle;
	int IPenWidth;
	Tecanvas::TTeeTransparency ITransp;
	void __fastcall Add(const AnsiString S);
	void __fastcall AddEnd(const AnsiString s);
	void __fastcall ChangedPen(System::TObject* Sender);
	void __fastcall InternalRect(const Types::TRect &Rect, bool UsePen, int RoundX = 0x0, int RoundY = 0x0);
	AnsiString __fastcall PointToStr(int X, int Y);
	void __fastcall PrepareShape(void);
	AnsiString __fastcall SVGBrushPen(bool UsePen = true);
	void __fastcall SVGClip(void);
	AnsiString __fastcall SVGEllipse(int X1, int Y1, int X2, int Y2);
	void __fastcall SVGEndClip(void);
	AnsiString __fastcall SVGPen();
	AnsiString __fastcall SVGPoints(const Types::TPoint * Points, const int Points_Size);
	AnsiString __fastcall SVGRect(const Types::TRect &Rect);
	AnsiString __fastcall TotalBounds();
	
protected:
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual int __fastcall GetTextAlign(void);
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	virtual void __fastcall SetBackMode(Tecanvas::TCanvasBackMode Mode);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual Tecanvas::TCanvasBackMode __fastcall GetBackMode(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual void __fastcall SetTextAlign(int Align);
	virtual AnsiString __fastcall HeaderContents();
	
public:
	bool Antialias;
	AnsiString DocType;
	__fastcall TSVGCanvas(Classes::TStrings* AStrings);
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, Tecanvas::TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect);
	virtual void __fastcall AssignVisiblePenColor(Graphics::TPen* APen, Graphics::TColor AColor);
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY)/* overload */;
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic);
	virtual void __fastcall FillRect(const Types::TRect &Rect);
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	virtual void __fastcall LineTo(int X, int Y)/* overload */;
	virtual void __fastcall MoveTo(int X, int Y)/* overload */;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1)/* overload */;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3)/* overload */;
	virtual void __fastcall StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic)/* overload */;
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text)/* overload */;
	virtual void __fastcall ClipEllipse(const Types::TRect &Rect, bool Inverted = false);
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect)/* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect, int RoundSize)/* overload */;
	virtual void __fastcall ClipPolygon(const Types::TPoint * Points, const int Points_Size, int NumPoints, bool DiffRegion = false);
	virtual void __fastcall UnClipRectangle(void);
	virtual Tecanvas::TTeeBlend* __fastcall BeginBlending(const Types::TRect &R, Tecanvas::TTeeTransparency Transparency);
	virtual void __fastcall EndBlending(Tecanvas::TTeeBlend* Blend);
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, Tecanvas::TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, double RotDegree);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, double RotDegree);
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect);
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
public:
	#pragma option push -w-inl
	/* TTeeCanvas3D.Destroy */ inline __fastcall virtual ~TSVGCanvas(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Arc(const int Left, const int Top, const int Right, const int Bottom, double StartAngle, double EndAngle){ TTeeCanvas::Arc(Left, Top, Right, Bottom, StartAngle, EndAngle); }
	inline void __fastcall  Ellipse(const Types::TRect &R){ TTeeCanvas::Ellipse(R); }
	inline void __fastcall  LineTo(const Types::TPoint &P){ TTeeCanvas::LineTo(P); }
	inline void __fastcall  MoveTo(const Types::TPoint &P){ TTeeCanvas::MoveTo(P); }
	inline void __fastcall  Rectangle(const Types::TRect &R, int Z){ TCanvas3D::Rectangle(R, Z); }
	inline void __fastcall  Rectangle(int X0, int Y0, int X1, int Y1, int Z){ TCanvas3D::Rectangle(X0, Y0, X1, Y1, Z); }
	inline void __fastcall  Rectangle(const Types::TRect &R){ TTeeCanvas::Rectangle(R); }
	inline void __fastcall  RoundRect(const Types::TRect &R, int X, int Y){ TTeeCanvas::RoundRect(R, X, Y); }
	inline void __fastcall  StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic, int Pos, Tecanvas::TCanvas3DPlane Plane = (Tecanvas::TCanvas3DPlane)(0x2)){ TCanvas3D::StretchDraw(Rect, Graphic, Pos, Plane); }
	inline void __fastcall  TextOut(int X, int Y, const AnsiString Text, bool AllowHtml){ TTeeCanvas::TextOut(X, Y, Text, AllowHtml); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size, int Z){ TCanvas3D::Polyline(Points, Points_Size, Z); }
	
};


class DELPHICLASS TSVGOptions;
class PASCALIMPLEMENTATION TSVGOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBAntiAlias;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSVGOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSVGOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSVGOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSVGOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TSVGExportFormat;
class PASCALIMPLEMENTATION TSVGExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	void __fastcall CheckProperties(void);
	
protected:
	TSVGOptions* FProperties;
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	__fastcall virtual ~TSVGExportFormat(void);
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	Classes::TStringList* __fastcall SVG(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TSVGExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeSaveToSVGFile(Teeprocs::TCustomTeePanel* APanel, AnsiString FileName, int AWidth = 0x0, int AHeight = 0x0);

}	/* namespace Teesvgcanvas */
using namespace Teesvgcanvas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSVGCanvas
