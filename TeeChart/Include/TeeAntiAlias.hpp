// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAntiAlias.pas' rev: 6.00

#ifndef TeeAntiAliasHPP
#define TeeAntiAliasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeFilters.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeantialias
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TAntiAlias { aaYes, aaNo };
#pragma option pop

typedef bool TPenDots[8];

class DELPHICLASS TAntiAliasCanvas;
class DELPHICLASS TAntiAliasTool;
class PASCALIMPLEMENTATION TAntiAliasTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	TAntiAliasCanvas* FCanvas;
	Tecanvas::TFilterItems* FFilters;
	void __fastcall CheckParentCanvas(void);
	bool __fastcall FiltersStored(void);
	bool __fastcall GetAntiAlias(void);
	void __fastcall ReadFilters(Classes::TReader* Reader);
	void __fastcall SetFilters(const Tecanvas::TFilterItems* Value);
	void __fastcall SetAntiAlias(const bool Value);
	void __fastcall WriteFilters(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TAntiAliasTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TAntiAliasTool(void);
	Graphics::TBitmap* __fastcall Bitmap(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property TAntiAliasCanvas* Canvas = {read=FCanvas};
	
__published:
	__property Active  = {default=1};
	__property bool AntiAlias = {read=GetAntiAlias, write=SetAntiAlias, default=1};
	__property Tecanvas::TFilterItems* Filters = {read=FFilters, write=SetFilters, stored=false};
};


class PASCALIMPLEMENTATION TAntiAliasCanvas : public Tecanvas::TTeeCanvas3D 
{
	typedef Tecanvas::TTeeCanvas3D inherited;
	
private:
	TAntiAlias FAlias;
	#pragma pack(push, 1)
	Types::TPoint FCurrent;
	#pragma pack(pop)
	
	bool IAlias;
	Byte r;
	Byte g;
	Byte b;
	float dist;
	float oneDist;
	Tecanvas::TTeeFilter* IFilter;
	HDC IDC;
	TAntiAliasTool* ITool;
	Graphics::TColor IPenColor;
	bool IPenSmallDot;
	Graphics::TPenStyle IPenStyle;
	int IPenWidth;
	void __fastcall BlendColor1(const int AX, const int AY);
	void __fastcall BlendColor2(const int AX, const int AY);
	void __fastcall CalcArcAngles(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, /* out */ double &StartAngle, /* out */ double &EndAngle);
	void __fastcall CheckBufferLines(void);
	void __fastcall GetPenDots(/* out */ bool * Dots, /* out */ bool &Solid);
	void __fastcall SetAntiAlias(const TAntiAlias Value);
	
protected:
	virtual void __fastcall PolygonFour(void);
	virtual void __fastcall SetBitmap(Graphics::TBitmap* ABitmap);
	virtual void __fastcall SetUseBuffer(bool Value);
	
public:
	__fastcall virtual ~TAntiAliasCanvas(void);
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY)/* overload */;
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, double StartAngle, double EndAngle)/* overload */;
	virtual void __fastcall AssignVisiblePenColor(Graphics::TPen* APen, Graphics::TColor AColor);
	virtual void __fastcall Donut(int XCenter, int YCenter, int XRadius, int YRadius, const double StartAngle, const double EndAngle, const double HolePercent);
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, Tecanvas::TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0);
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, Tecanvas::TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect);
	virtual void __fastcall LineTo(int X, int Y)/* overload */;
	virtual void __fastcall MoveTo(int X, int Y)/* overload */;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3)/* overload */;
	__property TAntiAlias AntiAlias = {read=FAlias, write=SetAntiAlias, default=0};
	__property Types::TPoint Current = {read=FCurrent, write=FCurrent};
public:
	#pragma option push -w-inl
	/* TTeeCanvas3D.Create */ inline __fastcall TAntiAliasCanvas(void) : Tecanvas::TTeeCanvas3D() { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Ellipse(const Types::TRect &R){ TTeeCanvas::Ellipse(R); }
	inline void __fastcall  LineTo(const Types::TPoint &P){ TTeeCanvas::LineTo(P); }
	inline void __fastcall  MoveTo(const Types::TPoint &P){ TTeeCanvas::MoveTo(P); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size, int Z){ TCanvas3D::Polyline(Points, Points_Size, Z); }
	inline void __fastcall  RoundRect(const Types::TRect &R, int X, int Y){ TTeeCanvas::RoundRect(R, X, Y); }
	
};


class DELPHICLASS TAntiAliasEditor;
class PASCALIMPLEMENTATION TAntiAliasEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* Button1;
	Stdctrls::TCheckBox* CBAnti;
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBAntiClick(System::TObject* Sender);
	
private:
	TAntiAliasTool* Tool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAntiAliasEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAntiAliasEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAntiAliasEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAntiAliasEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeantialias */
using namespace Teeantialias;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAntiAlias
