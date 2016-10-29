// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeXAMLCanvas.pas' rev: 6.00

#ifndef TeeXAMLCanvasHPP
#define TeeXAMLCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeExport.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teexamlcanvas
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TXAMLCanvas;
class PASCALIMPLEMENTATION TXAMLCanvas : public Tecanvas::TTeeCanvas3D 
{
	typedef Tecanvas::TTeeCanvas3D inherited;
	
private:
	Graphics::TColor FBackColor;
	Tecanvas::TCanvasBackMode FBackMode;
	int FTextAlign;
	int FX;
	int FY;
	Classes::TStrings* FStrings;
	Graphics::TPenStyle IPenStyle;
	int IPenWidth;
	Tecanvas::TTeeTransparency ITransp;
	Teeprocs::TCustomTeePanel* IPanel;
	void __fastcall Add(const AnsiString S);
	void __fastcall AddStrings(const AnsiString Strings);
	void __fastcall ChangedPen(System::TObject* Sender);
	AnsiString __fastcall PointToStr(int X, int Y);
	AnsiString __fastcall PrepareShape(const AnsiString Prefix, bool UsePen = true, bool UseBrush = true);
	AnsiString __fastcall XAMLColor(Graphics::TColor AColor);
	
protected:
	virtual AnsiString __fastcall BeginCanvasTag(Graphics::TColor ABackColor);
	virtual AnsiString __fastcall EndCanvasTag();
	virtual int __fastcall GetTextAlign(void);
	virtual void __fastcall InternalRect(const Types::TRect &Rect, bool UsePen, bool IsRound);
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	virtual void __fastcall SetBackMode(Tecanvas::TCanvasBackMode Mode);
	virtual bool __fastcall GetMonochrome(void);
	virtual void __fastcall SetMonochrome(bool Value);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual Tecanvas::TCanvasBackMode __fastcall GetBackMode(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual void __fastcall SetTextAlign(int Align);
	AnsiString __fastcall XAMLPen();
	
public:
	__fastcall virtual TXAMLCanvas(Teeprocs::TCustomTeePanel* Panel, Classes::TStrings* AStrings);
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
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect)/* overload */;
	virtual void __fastcall ClipCube(const Types::TRect &Rect, int MinZ, int MaxZ);
	virtual void __fastcall UnClipRectangle(void);
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, Tecanvas::TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, double RotDegree);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, double RotDegree);
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual Tecanvas::TTeeBlend* __fastcall BeginBlending(const Types::TRect &R, Tecanvas::TTeeTransparency Transparency);
	virtual void __fastcall EndBlending(Tecanvas::TTeeBlend* Blend);
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect);
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z)/* overload */;
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
public:
	#pragma option push -w-inl
	/* TTeeCanvas3D.Destroy */ inline __fastcall virtual ~TXAMLCanvas(void) { }
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
	inline void __fastcall  ClipRectangle(const Types::TRect &Rect, int RoundSize){ TTeeCanvas::ClipRectangle(Rect, RoundSize); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size, int Z){ TCanvas3D::Polyline(Points, Points_Size, Z); }
	inline void __fastcall  EllipseWithZ(const Types::TRect &Rect, int Z){ TCanvas3D::EllipseWithZ(Rect, Z); }
	
};


#pragma pack(push, 1)
struct TTextOutItem
{
	int XPos;
	int YPos;
	int ZPos;
	AnsiString FontFamily;
	AnsiString ItemText;
	Graphics::TColor FontColor;
	Graphics::TColor ItemBack;
} ;
#pragma pack(pop)

typedef DynamicArray<TTextOutItem >  TeeXAMLCanvas__3;

class DELPHICLASS TXAML3DCanvas;
class PASCALIMPLEMENTATION TXAML3DCanvas : public TXAMLCanvas 
{
	typedef TXAMLCanvas inherited;
	
private:
	int FZ;
	Classes::TStrings* IItems;
	DynamicArray<TTextOutItem >  ITexts;
	AnsiString __fastcall GetOpacity();
	AnsiString __fastcall IDTag(const AnsiString Prefix);
	AnsiString __fastcall TextOutList();
	
protected:
	virtual AnsiString __fastcall BeginCanvasTag(Graphics::TColor ABackColor);
	virtual void __fastcall BeginEntity(const AnsiString Entity);
	virtual AnsiString __fastcall EndCanvasTag();
	virtual void __fastcall EndEntity(void);
	virtual bool __fastcall GetSupportsFullRotation(void);
	virtual void __fastcall InternalRect(const Types::TRect &Rect, bool UsePen, bool IsRound);
	
public:
	bool ScrollBars;
	__fastcall virtual TXAML3DCanvas(Teeprocs::TCustomTeePanel* Panel, Classes::TStrings* AStrings);
	__fastcall virtual ~TXAML3DCanvas(void);
	virtual void __fastcall Cone(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D, int ConePercent);
	virtual void __fastcall Cube(int Left, int Right, int Top, int Bottom, int Z0, int Z1, bool DarkSides)/* overload */;
	virtual void __fastcall EraseBackground(const Types::TRect &Rect);
	virtual void __fastcall LineTo(int X, int Y)/* overload */;
	virtual void __fastcall LineTo3D(int X, int Y, int Z)/* overload */;
	virtual void __fastcall MoveTo3D(int X, int Y, int Z)/* overload */;
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual void __fastcall RectangleWithZ(const Types::TRect &Rect, int Z);
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Cube(const Types::TRect &R, int Z0, int Z1, bool DarkSides = true){ TCanvas3D::Cube(R, Z0, Z1, DarkSides); }
	inline void __fastcall  LineTo(const Types::TPoint &P){ TTeeCanvas::LineTo(P); }
	inline void __fastcall  LineTo3D(const Tecanvas::TPoint3D &P){ TCanvas3D::LineTo3D(P); }
	inline void __fastcall  MoveTo3D(const Tecanvas::TPoint3D &P){ TCanvas3D::MoveTo3D(P); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size, int Z){ TCanvas3D::Polyline(Points, Points_Size, Z); }
	
};


class DELPHICLASS TXAMLOptions;
class PASCALIMPLEMENTATION TXAMLOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CB3D;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TXAMLOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TXAMLOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TXAMLOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TXAMLOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TXAMLExportFormat;
class PASCALIMPLEMENTATION TXAMLExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	TXAMLOptions* FProperties;
	void __fastcall CheckProperties(void);
	
protected:
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	bool Is3D;
	bool ScrollBars;
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	Classes::TStringList* __fastcall XAML(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TXAMLExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TXAMLExportFormat(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeSaveToXAMLFile(Teeprocs::TCustomTeePanel* APanel, const WideString FileName, int AWidth = 0x0, int AHeight = 0x0, bool XAML3D = false);

}	/* namespace Teexamlcanvas */
using namespace Teexamlcanvas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeXAMLCanvas
