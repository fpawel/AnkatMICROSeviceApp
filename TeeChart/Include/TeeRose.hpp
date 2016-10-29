// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeRose.pas' rev: 6.00

#ifndef TeeRoseHPP
#define TeeRoseHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePolar.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teerose
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustom2DPolarSeries;
class PASCALIMPLEMENTATION TCustom2DPolarSeries : public Teepolar::TCustomPolarSeries 
{
	typedef Teepolar::TCustomPolarSeries inherited;
	
protected:
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
public:
	#pragma option push -w-inl
	/* TCustomPolarSeries.Create */ inline __fastcall virtual TCustom2DPolarSeries(Classes::TComponent* AOwner) : Teepolar::TCustomPolarSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPolarSeries.Destroy */ inline __fastcall virtual ~TCustom2DPolarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindRoseSeries;
class PASCALIMPLEMENTATION TWindRoseSeries : public TCustom2DPolarSeries 
{
	typedef TCustom2DPolarSeries inherited;
	
private:
	bool FMirrorAngles;
	bool FMirrorLabels;
	void __fastcall SetMirrorAngles(const bool Value);
	void __fastcall SetMirrorLabels(const bool Value);
	
protected:
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual AnsiString __fastcall GetCircleLabel(const double Angle, int Index);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual double __fastcall GetxValue(int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TWindRoseSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
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
	__property CircleLabels  = {default=1};
	__property CircleLabelsFont ;
	__property CircleLabelsInside  = {default=0};
	__property CircleLabelsRotated  = {default=0};
	__property CirclePen ;
	__property CloseCircle  = {default=1};
	__property bool MirrorAngles = {read=FMirrorAngles, write=SetMirrorAngles, default=0};
	__property bool MirrorLabels = {read=FMirrorLabels, write=SetMirrorLabels, default=0};
	__property Pen ;
	__property Pointer ;
	__property RadiusIncrement ;
	__property RadiusValues ;
	__property RotationAngle  = {default=90};
	__property Transparency  = {default=0};
	__property TreatNulls  = {default=2};
	__property OnGetCircleLabel ;
	__property OnGetPointerStyle ;
public:
	#pragma option push -w-inl
	/* TCustomPolarSeries.Destroy */ inline __fastcall virtual ~TWindRoseSeries(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TClockSeriesStyle { cssDecimal, cssRoman };
#pragma option pop

class DELPHICLASS TClockSeries;
typedef void __fastcall (__closure *TClockSeriesGetTimeEvent)(TClockSeries* Sender, System::TDateTime &ATime);

class PASCALIMPLEMENTATION TClockSeries : public TCustom2DPolarSeries 
{
	typedef TCustom2DPolarSeries inherited;
	
private:
	TClockSeriesGetTimeEvent FOnGetTime;
	Tecanvas::TChartPen* FPenHours;
	Tecanvas::TChartPen* FPenMinutes;
	Tecanvas::TChartPen* FPenSeconds;
	TClockSeriesStyle FStyle;
	bool OldAxesVisible;
	Extctrls::TTimer* ITimer;
	void __fastcall SetPenHours(Tecanvas::TChartPen* Value);
	void __fastcall SetPenMinutes(Tecanvas::TChartPen* Value);
	void __fastcall SetPenSeconds(Tecanvas::TChartPen* Value);
	void __fastcall SetStyle(TClockSeriesStyle Value);
	void __fastcall OnTimerExpired(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual AnsiString __fastcall GetCircleLabel(const double Angle, int Index);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TClockSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TClockSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	System::TDateTime __fastcall ClockTime(void);
	virtual int __fastcall CountLegendItems(void);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	DYNAMIC int __fastcall NumSampleValues(void);
	__property Extctrls::TTimer* Timer = {read=ITimer};
	
__published:
	__property Active  = {default=1};
	__property Brush ;
	__property CircleBackColor  = {default=536870912};
	__property CircleGradient ;
	__property Circled  = {default=1};
	__property CircleLabels  = {default=1};
	__property CircleLabelsFont ;
	__property CircleLabelsInside  = {default=0};
	__property CircleLabelsRotated  = {default=0};
	__property CirclePen ;
	__property Tecanvas::TChartPen* PenHours = {read=FPenHours, write=SetPenHours};
	__property Tecanvas::TChartPen* PenMinutes = {read=FPenMinutes, write=SetPenMinutes};
	__property Tecanvas::TChartPen* PenSeconds = {read=FPenSeconds, write=SetPenSeconds};
	__property RotationAngle  = {default=90};
	__property ShowInLegend  = {default=0};
	__property TClockSeriesStyle Style = {read=FStyle, write=SetStyle, default=1};
	__property Transparency  = {default=0};
	__property OnGetCircleLabel ;
	__property TClockSeriesGetTimeEvent OnGetTime = {read=FOnGetTime, write=FOnGetTime};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teerose */
using namespace Teerose;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeRose
