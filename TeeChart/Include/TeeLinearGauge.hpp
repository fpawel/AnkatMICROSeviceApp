// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLinearGauge.pas' rev: 6.00

#ifndef TeeLinearGaugeHPP
#define TeeLinearGaugeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeProCo.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeNumericGauge.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teelineargauge
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TGaugePointerStyles { gpHand, gpCenter, gpTick, gpMinorTick, gpColorLine };
#pragma option pop

class DELPHICLASS TGaugeSeriesPointer;
class PASCALIMPLEMENTATION TGaugeSeriesPointer : public Teengine::TSeriesPointer 
{
	typedef Teengine::TSeriesPointer inherited;
	
private:
	TGaugePointerStyles FGaugeStyle;
	void __fastcall SetGaugeStyle(const TGaugePointerStyles Value);
	
protected:
	int PXMinus;
	int PXPlus;
	int PYMinus;
	int PYPlus;
	int PXMinusSmall;
	int PXPlusSmall;
	int PYMinusSmall;
	int PYPlusSmall;
	double IStartAngle;
	void __fastcall SetValues(int x, int y, int horiz, int vert);
	
public:
	HIDESBASE void __fastcall Draw(const Types::TPoint &Inner, const Types::TPoint &InnerPlus, const Types::TPoint &InnerMinus, const Types::TPoint &Outer, const Types::TPoint &OuterPlus, const Types::TPoint &OuterMinus)/* overload */;
	
__published:
	__property TGaugePointerStyles GaugeStyle = {read=FGaugeStyle, write=SetGaugeStyle, nodefault};
public:
	#pragma option push -w-inl
	/* TSeriesPointer.Create */ inline __fastcall TGaugeSeriesPointer(Teengine::TChartSeries* AOwner) : Teengine::TSeriesPointer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSeriesPointer.Destroy */ inline __fastcall virtual ~TGaugeSeriesPointer(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Draw(const Types::TPoint &P){ TSeriesPointer::Draw(P); }
	inline void __fastcall  Draw(int X, int Y){ TSeriesPointer::Draw(X, Y); }
	inline void __fastcall  Draw(int px, int py, Graphics::TColor ColorValue, Teengine::TSeriesPointerStyle AStyle){ TSeriesPointer::Draw(px, py, ColorValue, AStyle); }
	
};


class DELPHICLASS TGaugePointerRange;
class PASCALIMPLEMENTATION TGaugePointerRange : public TGaugeSeriesPointer 
{
	typedef TGaugeSeriesPointer inherited;
	
private:
	double FEndValue;
	double FStartValue;
	void __fastcall SetEndValue(const double Value);
	void __fastcall SetStartValue(const double Value);
	
public:
	HIDESBASE void __fastcall Draw(const double StartAngle, const double EndAngle, const Types::TRect &Rectangle);
	
__published:
	__property double EndValue = {read=FEndValue, write=SetEndValue};
	__property double StartValue = {read=FStartValue, write=SetStartValue};
public:
	#pragma option push -w-inl
	/* TSeriesPointer.Create */ inline __fastcall TGaugePointerRange(Teengine::TChartSeries* AOwner) : TGaugeSeriesPointer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSeriesPointer.Destroy */ inline __fastcall virtual ~TGaugePointerRange(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomGaugeMinMax;
class PASCALIMPLEMENTATION TCustomGaugeMinMax : public Teenumericgauge::TCustomGauge 
{
	typedef Teenumericgauge::TCustomGauge inherited;
	
private:
	TGaugePointerRange* FGreenLine;
	TGaugeSeriesPointer* FHand;
	bool FHorizontal;
	double FMaximum;
	double FMinimum;
	int FMinorDist;
	TGaugeSeriesPointer* FMinorTicks;
	TGaugePointerRange* FRedLine;
	TGaugeSeriesPointer* FTicks;
	bool IAxisDone;
	void __fastcall SetAxisOnce(void);
	void __fastcall SetGreenLine(const TGaugePointerRange* Value);
	void __fastcall SetHand(const TGaugeSeriesPointer* Value);
	HIDESBASE void __fastcall SetHorizontal(const bool Value);
	void __fastcall SetMaximum(const double Value);
	void __fastcall SetMinimum(const double Value);
	void __fastcall SetMinorDist(const int Value);
	void __fastcall SetMinorTicks(const TGaugeSeriesPointer* Value);
	void __fastcall SetRedLine(const TGaugePointerRange* Value);
	void __fastcall SetTicks(const TGaugeSeriesPointer* Value);
	
protected:
	double IRange;
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual Teengine::TChartAxis* __fastcall Axis(void) = 0 ;
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawAxis(void) = 0 ;
	void __fastcall DrawAxisMinorTick(const Types::TPoint &Inner, const Types::TPoint &Outer);
	void __fastcall DrawAxisTick(const Types::TPoint &Inner, const Types::TPoint &InnerPlus, const Types::TPoint &InnerMinus, const Types::TPoint &Outer, const Types::TPoint &OuterPlus, const Types::TPoint &OuterMinus);
	virtual void __fastcall DrawHand(void);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetValues(void);
	
public:
	__fastcall virtual TCustomGaugeMinMax(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomGaugeMinMax(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TGaugePointerRange* GreenLine = {read=FGreenLine, write=SetGreenLine};
	__property TGaugeSeriesPointer* Hand = {read=FHand, write=SetHand};
	__property bool Horizontal = {read=FHorizontal, write=SetHorizontal, default=1};
	__property double Maximum = {read=FMaximum, write=SetMaximum};
	__property double Minimum = {read=FMinimum, write=SetMinimum};
	__property int MinorTickDistance = {read=FMinorDist, write=SetMinorDist, default=0};
	__property TGaugeSeriesPointer* MinorTicks = {read=FMinorTicks, write=SetMinorTicks};
	__property TGaugePointerRange* RedLine = {read=FRedLine, write=SetRedLine};
	__property TGaugeSeriesPointer* Ticks = {read=FTicks, write=SetTicks};
	
__published:
	__property ShowInLegend  = {default=0};
};


class DELPHICLASS TLinearGauge;
class PASCALIMPLEMENTATION TLinearGauge : public TCustomGaugeMinMax 
{
	typedef TCustomGaugeMinMax inherited;
	
private:
	TGaugeSeriesPointer* FMaxIndicator;
	bool FUseValuePalette;
	Teeprocs::TTeeShape* FValueArea;
	#pragma pack(push, 1)
	Types::TRect IAxisRect;
	#pragma pack(pop)
	
	double IMaxValue;
	void __fastcall DrawColorLines(void);
	void __fastcall SetMaxIndicator(const TGaugeSeriesPointer* Value);
	void __fastcall SetUseValuePalette(const bool Value);
	void __fastcall SetValueArea(const Teeprocs::TTeeShape* Value);
	
protected:
	virtual Teengine::TChartAxis* __fastcall Axis(void);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawAxis(void);
	virtual void __fastcall DrawHand(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetValue(const double AValue);
	virtual void __fastcall SetValues(void);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TLinearGauge(Classes::TComponent* AOwner);
	__fastcall virtual ~TLinearGauge(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall UseAxis(void);
	
__published:
	__property Active  = {default=1};
	__property Cursor  = {default=0};
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property ShowInLegend  = {default=0};
	__property Title ;
	__property ValueFormat ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnChange ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	__property XValues ;
	__property YValues ;
	__property Face ;
	__property Frame ;
	__property GreenLine ;
	__property Hand ;
	__property Horizontal  = {default=1};
	__property Maximum ;
	__property TGaugeSeriesPointer* MaxValueIndicator = {read=FMaxIndicator, write=SetMaxIndicator};
	__property Minimum ;
	__property MinorTickDistance  = {default=0};
	__property MinorTicks ;
	__property RedLine ;
	__property Ticks ;
	__property bool UseValueColorPalette = {read=FUseValuePalette, write=SetUseValuePalette, default=0};
	__property Value ;
	__property Teeprocs::TTeeShape* ValueArea = {read=FValueArea, write=SetValueArea};
};


class DELPHICLASS TLinearGaugeEditor;
class PASCALIMPLEMENTATION TLinearGaugeEditor : public Teenumericgauge::TNumericGaugeEditor 
{
	typedef Teenumericgauge::TNumericGaugeEditor inherited;
	
__published:
	Comctrls::TTabSheet* TabAxis;
	Comctrls::TTabSheet* TabGreen;
	Comctrls::TTabSheet* TabRed;
	Stdctrls::TEdit* EStartGreen;
	Stdctrls::TEdit* EEndGreen;
	Comctrls::TUpDown* UDStartGreen;
	Comctrls::TUpDown* UDEndGreen;
	Stdctrls::TButton* BValueArea;
	Stdctrls::TButton* BMaxIndicator;
	Comctrls::TPageControl* PageControl3;
	Comctrls::TTabSheet* TabSheet7;
	Comctrls::TTabSheet* TabSheet9;
	Comctrls::TTabSheet* TabTitle;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TButton* Button1;
	Stdctrls::TEdit* ETicks;
	Comctrls::TUpDown* UDTicks;
	Comctrls::TUpDown* UDTicksDist;
	Stdctrls::TEdit* ETicksDist;
	Stdctrls::TButton* Button2;
	Stdctrls::TEdit* EMinor;
	Comctrls::TUpDown* UDMinorCount;
	Comctrls::TUpDown* UDMinorSize;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TEdit* EMax;
	Stdctrls::TEdit* EMin;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* EFormat;
	Stdctrls::TButton* Button6;
	Stdctrls::TCheckBox* CBLabels;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label10;
	Stdctrls::TButton* BRed;
	Stdctrls::TEdit* EStartRed;
	Stdctrls::TEdit* EEndRed;
	Comctrls::TUpDown* UDStartRed;
	Comctrls::TUpDown* UDEndRed;
	Stdctrls::TButton* BGreen;
	Stdctrls::TButton* BLinearHand;
	Stdctrls::TCheckBox* CBGreenVisible;
	Stdctrls::TCheckBox* CBRedVisible;
	Teependlg::TButtonPen* BAxis;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall CBLabelsClick(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall EFormatChange(System::TObject* Sender);
	void __fastcall BGreenClick(System::TObject* Sender);
	void __fastcall EStartGreenChange(System::TObject* Sender);
	void __fastcall EEndGreenChange(System::TObject* Sender);
	void __fastcall EMinChange(System::TObject* Sender);
	void __fastcall EMaxChange(System::TObject* Sender);
	void __fastcall BValueAreaClick(System::TObject* Sender);
	void __fastcall BMaxIndicatorClick(System::TObject* Sender);
	void __fastcall Button6Click(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall EMinorChange(System::TObject* Sender);
	void __fastcall ETicksChange(System::TObject* Sender);
	void __fastcall ETicksDistChange(System::TObject* Sender);
	void __fastcall BLinearHandClick(System::TObject* Sender);
	void __fastcall CBGreenVisibleClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLinearGaugeEditor(Classes::TComponent* AOwner) : Teenumericgauge::TNumericGaugeEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLinearGaugeEditor(Classes::TComponent* AOwner, int Dummy) : Teenumericgauge::TNumericGaugeEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLinearGaugeEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLinearGaugeEditor(HWND ParentWindow) : Teenumericgauge::TNumericGaugeEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teelineargauge */
using namespace Teelineargauge;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLinearGauge
