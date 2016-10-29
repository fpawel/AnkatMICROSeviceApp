// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDataTableTool.pas' rev: 6.00

#ifndef TeeDataTableToolHPP
#define TeeDataTableToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedatatabletool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTableLegend;
class PASCALIMPLEMENTATION TTableLegend : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	bool FFontColor;
	bool FOtherSide;
	Chart::TLegendSymbol* FSymbol;
	int __fastcall CalcSymbolHeight(void);
	void __fastcall SetFontColor(const bool Value);
	void __fastcall SetSymbol(const Chart::TLegendSymbol* Value);
	void __fastcall SetOtherSide(const bool Value);
	
protected:
	virtual void __fastcall SetParent(Teeprocs::TCustomTeePanel* Value);
	
public:
	__fastcall virtual TTableLegend(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	__fastcall virtual ~TTableLegend(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Brush ;
	__property Color  = {default=16777215};
	__property Font ;
	__property bool FontSeriesColor = {read=FFontColor, write=SetFontColor, default=0};
	__property Gradient ;
	__property bool OtherSide = {read=FOtherSide, write=SetOtherSide, default=0};
	__property Pen ;
	__property Chart::TLegendSymbol* Symbol = {read=FSymbol, write=SetSymbol};
	__property Transparency  = {default=0};
	__property Transparent  = {default=1};
	__property Visible ;
};


class DELPHICLASS TDataTableTool;
typedef void __fastcall (__closure *TDataTableFilterSeries)(TDataTableTool* Sender, Teengine::TChartSeries* Series, bool &Accept);

class PASCALIMPLEMENTATION TDataTableTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	bool FAutoPos;
	bool FClipText;
	Tecanvas::TChartPen* FColumnPen;
	Tecanvas::TTeeFont* FFont;
	bool FInverted;
	int FLeft;
	TTableLegend* FLegend;
	TDataTableFilterSeries FOnFilterSeries;
	int FTop;
	int __fastcall CalcMaxSeriesCount(void);
	int __fastcall CalcPosLabels(Teengine::TChartAxis* Axis, int Value);
	int __fastcall CalcTableSize(Teengine::TChartAxis* Axis);
	Chart::TCustomChart* __fastcall Chart(void);
	void __fastcall Draw(void);
	Tecanvas::TChartPen* __fastcall GetRowPen(void);
	Teengine::TChartAxis* __fastcall GuessAxis(void);
	AnsiString __fastcall ItemText(Teengine::TChartSeries* Series, int ValueIndex);
	int __fastcall LegendWidth(int &SymbolWidth);
	void __fastcall SetAutoPos(const bool Value);
	void __fastcall SetClipText(const bool Value);
	void __fastcall SetColumnPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetFont(const Tecanvas::TTeeFont* Value);
	void __fastcall SetInverted(const bool Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetLegend(const TTableLegend* Value);
	void __fastcall SetRowPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetTop(const int Value);
	int __fastcall TableSize(void);
	bool __fastcall ValidSeries(int Index);
	int __fastcall VisibleSeriesCount(void);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TDataTableTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TDataTableTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property bool AutoPosition = {read=FAutoPos, write=SetAutoPos, default=1};
	__property Brush ;
	__property bool ClipText = {read=FClipText, write=SetClipText, default=1};
	__property Tecanvas::TChartPen* ColumnPen = {read=FColumnPen, write=SetColumnPen};
	__property Tecanvas::TTeeFont* Font = {read=FFont, write=SetFont};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=0};
	__property int Left = {read=FLeft, write=SetLeft, default=0};
	__property TTableLegend* Legend = {read=FLegend, write=SetLegend};
	__property Tecanvas::TChartPen* RowPen = {read=GetRowPen, write=SetRowPen};
	__property int Top = {read=FTop, write=SetTop, default=0};
	__property TDataTableFilterSeries OnFilterSeries = {read=FOnFilterSeries, write=FOnFilterSeries};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teedatatabletool */
using namespace Teedatatabletool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDataTableTool
