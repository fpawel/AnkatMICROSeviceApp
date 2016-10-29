// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFlexCanvas.pas' rev: 6.00

#ifndef TeeFlexCanvasHPP
#define TeeFlexCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeExport.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeConst.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <FileCtrl.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeflexcanvas
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFlexCanvas;
class PASCALIMPLEMENTATION TFlexCanvas : public Tecanvas::TTeeCanvas3D 
{
	typedef Tecanvas::TTeeCanvas3D inherited;
	
private:
	Graphics::TColor FBackColor;
	Tecanvas::TCanvasBackMode FBackMode;
	int FTextAlign;
	int FX;
	int FY;
	Classes::TStrings* FStrings;
	bool IAddedInitApp;
	int IApplication;
	Tecanvas::TChartPen* IChartPen;
	AnsiString IIdent;
	Classes::TStrings* IItems;
	int IImageID;
	Teeprocs::TCustomTeePanel* IPanel;
	Classes::TStrings* IPath;
	int IScript;
	bool ISmallDots;
	Tecanvas::TTeeTransparency ITransp;
	void __fastcall AddItem(const AnsiString S);
	void __fastcall AddTag(const AnsiString ATag, const AnsiString AText);
	AnsiString __fastcall BrushColor();
	void __fastcall CalcArcAngles(int XC, int YC, int StartX, int StartY, int EndX, int EndY, /* out */ float &StartAngle, /* out */ float &EndAngle);
	AnsiString __fastcall FlexAlpha();
	AnsiString __fastcall FlexFloatToStr(const double Value);
	AnsiString __fastcall FlexFont(Graphics::TFont* AFont);
	AnsiString __fastcall FlexGradient(Tecanvas::TCustomTeeGradient* Gradient)/* overload */;
	AnsiString __fastcall FlexGradient(Graphics::TColor StartColor, Graphics::TColor EndColor, Tecanvas::TGradientDirection Direction, int Balance)/* overload */;
	AnsiString __fastcall FlexPoints(const Types::TPoint * Points, const int Points_Size);
	AnsiString __fastcall FlexPosition(int x, int y);
	AnsiString __fastcall FlexSize(int w, int h)/* overload */;
	AnsiString __fastcall FlexSize(const Types::TRect &R)/* overload */;
	AnsiString __fastcall ImageFileName(Graphics::TGraphic* Graphic);
	AnsiString __fastcall PenColor();
	AnsiString __fastcall PenWidth();
	
protected:
	void __fastcall AddLink(int x, int y, const AnsiString Text, const AnsiString URL, const AnsiString Hint);
	void __fastcall AddToolTip(const AnsiString Entity, const AnsiString ToolTip);
	virtual void __fastcall BeginEntity(const AnsiString Entity);
	virtual void __fastcall EndEntity(void);
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual int __fastcall GetTextAlign(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual Tecanvas::TCanvasBackMode __fastcall GetBackMode(void);
	virtual bool __fastcall GetMonochrome(void);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual void __fastcall SetBackMode(Tecanvas::TCanvasBackMode Mode);
	virtual void __fastcall SetMonochrome(bool Value);
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	virtual void __fastcall SetTextAlign(int Align);
	
public:
	bool EmbeddImages;
	AnsiString ImagePath;
	__fastcall TFlexCanvas(Teeprocs::TCustomTeePanel* Panel, Classes::TStrings* AStrings);
	__fastcall virtual ~TFlexCanvas(void);
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, Tecanvas::TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect);
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY)/* overload */;
	virtual void __fastcall AssignVisiblePenColor(Graphics::TPen* APen, Graphics::TColor AColor);
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
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall PolygonGradient(const Types::TPoint * Points, const int Points_Size, Tecanvas::TCustomTeeGradient* Gradient);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual Tecanvas::TTeeBlend* __fastcall BeginBlending(const Types::TRect &R, Tecanvas::TTeeTransparency Transparency);
	virtual void __fastcall EndBlending(Tecanvas::TTeeBlend* Blend);
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect);
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
	
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
	
private:
	void *__ICanvasHyperlinks;	/* Tecanvas::ICanvasHyperlinks */
	void *__ICanvasToolTips;	/* Tecanvas::ICanvasToolTips */
	
public:
	operator ICanvasToolTips*(void) { return (ICanvasToolTips*)&__ICanvasToolTips; }
	operator ICanvasHyperlinks*(void) { return (ICanvasHyperlinks*)&__ICanvasHyperlinks; }
	
};


class DELPHICLASS TFlexOptions;
class PASCALIMPLEMENTATION TFlexOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* BCompile;
	Stdctrls::TEdit* ETemp;
	Stdctrls::TLabel* Label1;
	Buttons::TSpeedButton* SpeedButton1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EFlex;
	Buttons::TSpeedButton* SpeedButton2;
	Stdctrls::TCheckBox* CBPreview;
	Stdctrls::TMemo* AC_OETags_js;
	Stdctrls::TMemo* Chart1_html;
	Stdctrls::TCheckBox* CBDelete;
	Stdctrls::TCheckBox* CBEmbedd;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BCompileClick(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall SpeedButton2Click(System::TObject* Sender);
	void __fastcall ETempChange(System::TObject* Sender);
	void __fastcall EFlexChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	void __fastcall CheckCompile(void);
	bool __fastcall Compile(const AnsiString TargetFile);
	void __fastcall ReadOptions(void);
	
public:
	Teeprocs::TCustomTeePanel* Panel;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFlexOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFlexOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFlexOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFlexOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TFlexExportFormat;
class PASCALIMPLEMENTATION TFlexExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	void __fastcall CheckProperties(void);
	
protected:
	TFlexOptions* FProperties;
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	bool EmbeddImages;
	AnsiString ImagePath;
	bool __fastcall Compile(const AnsiString TargetFile);
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	Classes::TStringList* __fastcall FlexMXML(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TFlexExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TFlexExportFormat(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeSaveToFlexFile(Teeprocs::TCustomTeePanel* APanel, const WideString FileName, int AWidth = 0x0, int AHeight = 0x0, bool EmbededImages = true);

}	/* namespace Teeflexcanvas */
using namespace Teeflexcanvas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFlexCanvas
