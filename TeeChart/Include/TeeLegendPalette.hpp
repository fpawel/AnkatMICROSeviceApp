// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLegendPalette.pas' rev: 6.00

#ifndef TeeLegendPaletteHPP
#define TeeLegendPaletteHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiAxis.hpp>	// Pascal unit
#include <TeeEdiPane.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teelegendpalette
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TLegendPaletteAxis { laDefault, laOther, laBoth };
#pragma option pop

class DELPHICLASS TLegendPaletteTool;
class PASCALIMPLEMENTATION TLegendPaletteTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Chart::TCustomChart* FChart;
	int FHeight;
	int FLeft;
	Teeprocs::TTeeUnits FPositionUnits;
	bool FSmooth;
	int FTop;
	bool FVertical;
	int FWidth;
	TLegendPaletteAxis __fastcall GetAxis(void);
	Tecanvas::TChartHiddenPen* __fastcall GetBorder(void);
	Graphics::TColor __fastcall GetColor(void);
	Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	bool __fastcall GetInverted(void);
	Tecanvas::TTeeShadow* __fastcall GetShadow(void);
	bool __fastcall GetTransp(void);
	void __fastcall SetAxis(const TLegendPaletteAxis Value);
	void __fastcall SetBorder(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetColor(const Graphics::TColor Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetInverted(const bool Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetPositionUnits(const Teeprocs::TTeeUnits Value);
	void __fastcall SetShadow(const Tecanvas::TTeeShadow* Value);
	void __fastcall SetSmooth(const bool Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetTransp(const bool Value);
	void __fastcall SetVertical(const bool Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TLegendPaletteTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TLegendPaletteTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property Chart::TCustomChart* Chart = {read=FChart};
	
__published:
	__property Active  = {default=1};
	__property TLegendPaletteAxis Axis = {read=GetAxis, write=SetAxis, default=2};
	__property Tecanvas::TChartHiddenPen* Border = {read=GetBorder, write=SetBorder};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, default=16777215};
	__property Tecanvas::TTeeGradient* Gradient = {read=GetGradient, write=SetGradient};
	__property int Height = {read=FHeight, write=SetHeight, default=200};
	__property bool Inverted = {read=GetInverted, write=SetInverted, default=0};
	__property int Left = {read=FLeft, write=SetLeft, default=10};
	__property Pen ;
	__property Teeprocs::TTeeUnits PositionUnits = {read=FPositionUnits, write=SetPositionUnits, default=1};
	__property Series ;
	__property Tecanvas::TTeeShadow* Shadow = {read=GetShadow, write=SetShadow};
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
	__property int Top = {read=FTop, write=SetTop, default=10};
	__property bool Transparent = {read=GetTransp, write=SetTransp, default=0};
	__property bool Vertical = {read=FVertical, write=SetVertical, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=100};
};


class DELPHICLASS TLegendPaletteEditor;
class PASCALIMPLEMENTATION TLegendPaletteEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabPanel;
	Teependlg::TButtonPen* ButtonPen1;
	Extctrls::TRadioGroup* RGAxis;
	Stdctrls::TCheckBox* CBTransp;
	Stdctrls::TCheckBox* CBSmooth;
	Stdctrls::TCheckBox* CBVertical;
	Comctrls::TTabSheet* TabAxes;
	Stdctrls::TCheckBox* CBInverted;
	Comctrls::TTabSheet* TabSheet4;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label13;
	Stdctrls::TEdit* ECustLeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TEdit* ECustTop;
	Comctrls::TUpDown* UDTop;
	Tecanvas::TComboFlat* CBUnits;
	Comctrls::TTabSheet* TabSheet5;
	Stdctrls::TLabel* Label14;
	Stdctrls::TLabel* Label15;
	Stdctrls::TEdit* ECustWidth;
	Stdctrls::TEdit* ECustHeight;
	Comctrls::TUpDown* UDWidth;
	Comctrls::TUpDown* UDHeight;
	Teependlg::TButtonPen* BBorder;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGAxisClick(System::TObject* Sender);
	void __fastcall CBTranspClick(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall CBVerticalClick(System::TObject* Sender);
	void __fastcall CBInvertedClick(System::TObject* Sender);
	void __fastcall ECustLeftChange(System::TObject* Sender);
	void __fastcall ECustTopChange(System::TObject* Sender);
	void __fastcall CBUnitsChange(System::TObject* Sender);
	void __fastcall ECustWidthChange(System::TObject* Sender);
	void __fastcall ECustHeightChange(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Teeediaxis::TFormTeeAxis* IAxes;
	Teeedipane::TFormTeePanel* IPanel;
	bool CreatingForm;
	TLegendPaletteTool* __fastcall LegendTool(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLegendPaletteEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLegendPaletteEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLegendPaletteEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLegendPaletteEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const int DefaultPanelColor = 0xffffff;

}	/* namespace Teelegendpalette */
using namespace Teelegendpalette;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLegendPalette
