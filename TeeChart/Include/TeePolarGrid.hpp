// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePolarGrid.pas' rev: 6.00

#ifndef TeePolarGridHPP
#define TeePolarGridHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeePolarEditor.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeePolar.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepolargrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGridColorPalette;
class PASCALIMPLEMENTATION TGridColorPalette : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Teesurfa::TCustom3DPaletteSeries* IPalette;
	Graphics::TColor __fastcall GetEndColor(void);
	int __fastcall GetLegendEvery(void);
	Graphics::TColor __fastcall GetMidColor(void);
	Teesurfa::TCustom3DPalette __fastcall GetPalette();
	double __fastcall GetPaletteMin(void);
	double __fastcall GetPaletteStep(void);
	int __fastcall GetPaletteSteps(void);
	Teesurfa::TTeePaletteStyle __fastcall GetPaletteStyle(void);
	Graphics::TColor __fastcall GetStartColor(void);
	bool __fastcall GetUseColorRange(void);
	bool __fastcall GetUsePalette(void);
	bool __fastcall GetUsePaletteMin(void);
	void __fastcall SetEndColor(const Graphics::TColor Value);
	void __fastcall SetLegendEvery(const int Value);
	void __fastcall SetMidColor(const Graphics::TColor Value);
	void __fastcall SetPalette(const Teesurfa::TCustom3DPalette Value);
	void __fastcall SetPaletteMin(const double Value);
	void __fastcall SetPaletteStep(const double Value);
	void __fastcall SetPaletteSteps(const int Value);
	void __fastcall SetPaletteStyle(const Teesurfa::TTeePaletteStyle Value);
	void __fastcall SetStartColor(const Graphics::TColor Value);
	void __fastcall SetUseColorRange(const bool Value);
	void __fastcall SetUsePalette(const bool Value);
	void __fastcall SetUsePaletteMin(const bool Value);
	
public:
	__property Teesurfa::TCustom3DPalette Palette = {read=GetPalette, write=SetPalette};
	
__published:
	__property Graphics::TColor EndColor = {read=GetEndColor, write=SetEndColor, default=16777215};
	__property Graphics::TColor MidColor = {read=GetMidColor, write=SetMidColor, default=536870911};
	__property int LegendEvery = {read=GetLegendEvery, write=SetLegendEvery, default=1};
	__property double PaletteMin = {read=GetPaletteMin, write=SetPaletteMin};
	__property double PaletteStep = {read=GetPaletteStep, write=SetPaletteStep};
	__property int PaletteSteps = {read=GetPaletteSteps, write=SetPaletteSteps, default=32};
	__property Teesurfa::TTeePaletteStyle PaletteStyle = {read=GetPaletteStyle, write=SetPaletteStyle, default=0};
	__property Graphics::TColor StartColor = {read=GetStartColor, write=SetStartColor, default=8388608};
	__property bool UseColorRange = {read=GetUseColorRange, write=SetUseColorRange, default=1};
	__property bool UsePalette = {read=GetUsePalette, write=SetUsePalette, default=0};
	__property bool UsePaletteMin = {read=GetUsePaletteMin, write=SetUsePaletteMin, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGridColorPalette(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TGridColorPalette(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TPolarGridSeries;
class PASCALIMPLEMENTATION TPolarGridSeries : public Teepolar::TCustomPolarSeries 
{
	typedef Teepolar::TCustomPolarSeries inherited;
	
private:
	bool FCentered;
	int FNumSectors;
	int FNumTracks;
	TGridColorPalette* FPalette;
	Teengine::TChartValueList* FValues;
	Chart::TCustomChart* IChart;
	Teesurfa::TCustom3DPaletteSeries* I3D;
	double __fastcall InternalX(int ValueIndex);
	void __fastcall SetCentered(const bool Value);
	void __fastcall SetPalette(const TGridColorPalette* Value);
	void __fastcall SetValues(const Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	void __fastcall CellPolygon(int ValueIndex, Types::TPoint * P);
	virtual void __fastcall DoAfterDrawValues(void);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawPolarCircle(int HalfWidth, int HalfHeight, int Z);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual AnsiString __fastcall GetCircleLabel(const double Angle, int Index);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TPolarGridSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TPolarGridSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall AddCell(const int Sector, const int Track, const double Value);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual int __fastcall CountLegendItems(void);
	Graphics::TColor __fastcall GetCellColor(const double Value);
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	__property TGridColorPalette* Palette = {read=FPalette, write=SetPalette};
	
__published:
	__property Teengine::TChartValueList* CellValues = {read=FValues, write=SetValues};
	__property bool Centered = {read=FCentered, write=SetCentered, default=1};
	__property int NumSectors = {read=FNumSectors, write=FNumSectors, default=10};
	__property int NumTracks = {read=FNumTracks, write=FNumTracks, default=10};
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property HorizAxis  = {default=1};
	__property SeriesColor ;
	__property VertAxis  = {default=0};
	__property AngleIncrement ;
	__property AngleValues ;
	__property Brush ;
	__property CircleBackColor  = {default=536870912};
	__property CircleGradient ;
	__property CircleLabels  = {default=0};
	__property CircleLabelsFont ;
	__property CircleLabelsInside  = {default=0};
	__property CircleLabelsRotated  = {default=0};
	__property CirclePen ;
	__property ClockWiseLabels  = {default=0};
	__property LabelsMargin  = {default=3};
	__property Pen ;
	__property RadiusIncrement ;
	__property RadiusValues ;
	__property RotationAngle  = {default=90};
	__property Transparency  = {default=0};
	__property TreatNulls  = {default=2};
	__property OnGetCircleLabel ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TPolarGridEditor;
class PASCALIMPLEMENTATION TPolarGridEditor : public Teepolareditor::TPolarSeriesEditor 
{
	typedef Teepolareditor::TPolarSeriesEditor inherited;
	
__published:
	Comctrls::TTabSheet* TabPalette;
	Stdctrls::TCheckBox* CBCentered;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBCenteredClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPolarGridEditor(Classes::TComponent* AOwner) : Teepolareditor::TPolarSeriesEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPolarGridEditor(Classes::TComponent* AOwner, int Dummy) : Teepolareditor::TPolarSeriesEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPolarGridEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPolarGridEditor(HWND ParentWindow) : Teepolareditor::TPolarSeriesEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepolargrid */
using namespace Teepolargrid;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePolarGrid
