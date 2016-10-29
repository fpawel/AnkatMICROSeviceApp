// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePolar.pas' rev: 6.00

#ifndef TeePolarHPP
#define TeePolarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teepolar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomPolarSeries;
typedef void __fastcall (__closure *TOnGetPolarLabel)(TCustomPolarSeries* Sender, const double Angle, int Index, AnsiString &Text);

class PASCALIMPLEMENTATION TCustomPolarSeries : public Series::TCircledSeries 
{
	typedef Series::TCircledSeries inherited;
	
private:
	bool FCircleLabels;
	Tecanvas::TTeeFont* FCircleLabelsFont;
	bool FCircleLabelsInside;
	bool FCircleLabelsRot;
	Tecanvas::TChartPen* FCirclePen;
	bool FClockWiseLabels;
	bool FCloseCircle;
	int FLabelsMargin;
	TOnGetPolarLabel FOnGetCircleLabel;
	Series::TOnGetPointerStyle FOnGetPointerStyle;
	Teengine::TSeriesPointer* FPointer;
	Tecanvas::TTeeTransparency FTransparency;
	Series::TTreatNullsStyle FTreatNulls;
	int OldX;
	int OldY;
	int IMaxValuesCount;
	Graphics::TColor __fastcall CalcValueColor(int ValueIndex);
	void __fastcall CalcXYPos(int ValueIndex, int ARadius, int &X, int &Y);
	Teengine::TSeriesPointerStyle __fastcall DoGetPointerStyle(int ValueIndex);
	bool __fastcall DrawAxesBehind(void);
	void __fastcall DrawAxis(void);
	void __fastcall FillTriangle(const Types::TPoint &A, const Types::TPoint &B, int Z);
	double __fastcall GetAngleIncrement(void);
	Teengine::TChartValueList* __fastcall GetAngleValues(void);
	double __fastcall GetRadiusIncrement(void);
	Teengine::TChartValueList* __fastcall GetRadiusValues(void);
	bool __fastcall IsRadiusStored(void);
	void __fastcall SetAngleIncrement(const double Value);
	void __fastcall SetAngleValues(Teengine::TChartValueList* Value);
	void __fastcall SetCircleLabels(bool Value);
	void __fastcall SetCircleLabelsFont(Tecanvas::TTeeFont* Value);
	void __fastcall SetCircleLabelsInside(const bool Value);
	void __fastcall SetCirclePen(Tecanvas::TChartPen* Value);
	void __fastcall SetClockWiseLabels(const bool Value);
	void __fastcall SetCloseCircle(bool Value);
	void __fastcall SetLabelsMargin(const int Value);
	void __fastcall SetLabelsRotated(bool Value);
	void __fastcall SetPointer(Teengine::TSeriesPointer* Value);
	void __fastcall SetRadiusIncrement(const double Value);
	void __fastcall SetRadiusValues(Teengine::TChartValueList* Value);
	void __fastcall SetTransparency(Tecanvas::TTeeTransparency Value);
	void __fastcall SetTreatNulls(const Series::TTreatNullsStyle Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	void __fastcall CalcXYPosition(const double XValue, const double YValue, int ARadius, int &X, int &Y);
	void __fastcall CalcXYRadius(const double Value, int &X, int &Y);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DoAfterDrawValues(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawCircleGradient(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawPolarCircle(int HalfWidth, int HalfHeight, int Z);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual AnsiString __fastcall GetCircleLabel(const double Angle, int Index);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall InternalDrawValue(int ValueIndex, int X, int Y);
	void __fastcall LinePrepareCanvas(int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TCustomPolarSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomPolarSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	void __fastcall DrawRing(const double Value, int Z);
	virtual bool __fastcall DrawValuesForward(void);
	void __fastcall DrawZone(const double Min, const double Max, int Z);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	__property double AngleIncrement = {read=GetAngleIncrement, write=SetAngleIncrement};
	__property Teengine::TChartValueList* AngleValues = {read=GetAngleValues, write=SetAngleValues};
	__property Brush ;
	__property bool CircleLabels = {read=FCircleLabels, write=SetCircleLabels, default=0};
	__property Tecanvas::TTeeFont* CircleLabelsFont = {read=FCircleLabelsFont, write=SetCircleLabelsFont};
	__property bool CircleLabelsInside = {read=FCircleLabelsInside, write=SetCircleLabelsInside, default=0};
	__property bool CircleLabelsRotated = {read=FCircleLabelsRot, write=SetLabelsRotated, default=0};
	__property Tecanvas::TChartPen* CirclePen = {read=FCirclePen, write=SetCirclePen};
	__property bool ClockWiseLabels = {read=FClockWiseLabels, write=SetClockWiseLabels, default=0};
	__property bool CloseCircle = {read=FCloseCircle, write=SetCloseCircle, default=1};
	__property int LabelsMargin = {read=FLabelsMargin, write=SetLabelsMargin, default=3};
	__property Pen ;
	__property Teengine::TSeriesPointer* Pointer = {read=FPointer, write=SetPointer};
	__property double RadiusIncrement = {read=GetRadiusIncrement, write=SetRadiusIncrement};
	__property Teengine::TChartValueList* RadiusValues = {read=GetRadiusValues, write=SetRadiusValues, stored=IsRadiusStored};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property Series::TTreatNullsStyle TreatNulls = {read=FTreatNulls, write=SetTreatNulls, default=2};
	__property TOnGetPolarLabel OnGetCircleLabel = {read=FOnGetCircleLabel, write=FOnGetCircleLabel};
	__property Series::TOnGetPointerStyle OnGetPointerStyle = {read=FOnGetPointerStyle, write=FOnGetPointerStyle};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TPolarSeries;
class PASCALIMPLEMENTATION TPolarSeries : public TCustomPolarSeries 
{
	typedef TCustomPolarSeries inherited;
	
public:
	int __fastcall AddPolar(const double Angle, const double Value, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	
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
	__property CircleLabels  = {default=0};
	__property CircleLabelsFont ;
	__property CircleLabelsInside  = {default=0};
	__property CircleLabelsRotated  = {default=0};
	__property CirclePen ;
	__property ClockWiseLabels  = {default=0};
	__property CloseCircle  = {default=1};
	__property LabelsMargin  = {default=3};
	__property Pen ;
	__property Pointer ;
	__property RadiusIncrement ;
	__property RadiusValues ;
	__property RotationAngle  = {default=0};
	__property Transparency  = {default=0};
	__property TreatNulls  = {default=2};
	__property OnGetCircleLabel ;
	__property OnGetPointerStyle ;
public:
	#pragma option push -w-inl
	/* TCustomPolarSeries.Create */ inline __fastcall virtual TPolarSeries(Classes::TComponent* AOwner) : TCustomPolarSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPolarSeries.Destroy */ inline __fastcall virtual ~TPolarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRadarSeries;
class PASCALIMPLEMENTATION TRadarSeries : public TCustomPolarSeries 
{
	typedef TCustomPolarSeries inherited;
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual AnsiString __fastcall GetCircleLabel(const double Angle, int Index);
	virtual double __fastcall GetxValue(int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	DYNAMIC int __fastcall NumSampleValues(void);
	
__published:
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property HorizAxis  = {default=1};
	__property SeriesColor ;
	__property VertAxis  = {default=0};
	__property Brush ;
	__property CircleBackColor  = {default=536870912};
	__property CircleGradient ;
	__property CircleLabels  = {default=0};
	__property CircleLabelsFont ;
	__property CircleLabelsRotated  = {default=0};
	__property CirclePen ;
	__property CloseCircle  = {default=1};
	__property LabelsMargin  = {default=3};
	__property Pen ;
	__property Pointer ;
	__property RadiusIncrement ;
	__property RadiusValues ;
	__property Transparency  = {default=0};
	__property OnGetCircleLabel ;
	__property OnGetPointerStyle ;
public:
	#pragma option push -w-inl
	/* TCustomPolarSeries.Create */ inline __fastcall virtual TRadarSeries(Classes::TComponent* AOwner) : TCustomPolarSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPolarSeries.Destroy */ inline __fastcall virtual ~TRadarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPolarBarSeries;
class PASCALIMPLEMENTATION TPolarBarSeries : public TPolarSeries 
{
	typedef TPolarSeries inherited;
	
protected:
	virtual void __fastcall InternalDrawValue(int ValueIndex, int X, int Y);
public:
	#pragma option push -w-inl
	/* TCustomPolarSeries.Create */ inline __fastcall virtual TPolarBarSeries(Classes::TComponent* AOwner) : TPolarSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPolarSeries.Destroy */ inline __fastcall virtual ~TPolarBarSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepolar */
using namespace Teepolar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePolar
