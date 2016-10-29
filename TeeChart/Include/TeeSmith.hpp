// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSmith.pas' rev: 6.00

#ifndef TeeSmithHPP
#define TeeSmithHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePolar.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teesmith
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSmithSeries;
class PASCALIMPLEMENTATION TSmithSeries : public Series::TCircledSeries 
{
	typedef Series::TCircledSeries inherited;
	
private:
	Tecanvas::TChartPen* FCirclePen;
	AnsiString FImagSymbol;
	Teengine::TSeriesPointer* FPointer;
	int OldX;
	int OldY;
	Series::TOnGetPointerStyle FOnGetPointerStyle;
	Teengine::TChartValueList* __fastcall GetResistanceValues(void);
	Teengine::TChartValueList* __fastcall GetReactance(void);
	Tecanvas::TChartPen* __fastcall GetCPen(void);
	Tecanvas::TChartPen* __fastcall GetRPen(void);
	bool __fastcall GetCLabels(void);
	bool __fastcall GetRLabels(void);
	void __fastcall SetResistanceValues(Teengine::TChartValueList* Value);
	void __fastcall SetReactance(Teengine::TChartValueList* Value);
	void __fastcall SetRPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetCPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetPointer(const Teengine::TSeriesPointer* Value);
	void __fastcall SetCLabels(const bool Value);
	void __fastcall SetRLabels(const bool Value);
	void __fastcall SetCirclePen(const Tecanvas::TChartPen* Value);
	Tecanvas::TTeeFont* __fastcall GetCLabelsFont(void);
	Tecanvas::TTeeFont* __fastcall GetRLabelsFont(void);
	void __fastcall SetCLabelsFont(const Tecanvas::TTeeFont* Value);
	void __fastcall SetRLabelsFont(const Tecanvas::TTeeFont* Value);
	void __fastcall SetImagSymbol(const AnsiString Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	AnsiString __fastcall GetXCircleLabel(const double Reactance);
	void __fastcall LinePrepareCanvas(int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	
public:
	__fastcall virtual TSmithSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TSmithSeries(void);
	int __fastcall AddPoint(const double Resist, const double React, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int X, int Y)/* overload */;
	void __fastcall DrawRCircle(const double Value, int Z, bool ShowLabel = true);
	void __fastcall DrawXCircle(const double Value, int Z, bool ShowLabel = true);
	void __fastcall PosToZ(int X, int Y, double &Resist, double &React);
	void __fastcall ZToPos(const double Resist, const double React, int &X, int &Y);
	
__published:
	__property Active  = {default=1};
	__property Tecanvas::TChartPen* CCirclePen = {read=GetCPen, write=SetCPen};
	__property CircleBackColor  = {default=536870912};
	__property CircleGradient ;
	__property Tecanvas::TChartPen* CirclePen = {read=FCirclePen, write=SetCirclePen};
	__property bool CLabels = {read=GetCLabels, write=SetCLabels, nodefault};
	__property Tecanvas::TTeeFont* CLabelsFont = {read=GetCLabelsFont, write=SetCLabelsFont};
	__property ColorEachPoint  = {default=0};
	__property AnsiString ImagSymbol = {read=FImagSymbol, write=SetImagSymbol};
	__property Teengine::TChartValueList* ResistanceValues = {read=GetResistanceValues, write=SetResistanceValues};
	__property Teengine::TChartValueList* ReactanceValues = {read=GetReactance, write=SetReactance};
	__property Pen ;
	__property Teengine::TSeriesPointer* Pointer = {read=FPointer, write=SetPointer};
	__property Tecanvas::TChartPen* RCirclePen = {read=GetRPen, write=SetRPen};
	__property bool RLabels = {read=GetRLabels, write=SetRLabels, nodefault};
	__property Tecanvas::TTeeFont* RLabelsFont = {read=GetRLabelsFont, write=SetRLabelsFont};
	__property Series::TOnGetPointerStyle OnGetPointerStyle = {read=FOnGetPointerStyle, write=FOnGetPointerStyle};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesmith */
using namespace Teesmith;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSmith
