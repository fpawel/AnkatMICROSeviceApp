// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeExtraLegendTool.pas' rev: 6.00

#ifndef TeeExtraLegendToolHPP
#define TeeExtraLegendToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiLege.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teeextralegendtool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TExtraLegendTool;
class PASCALIMPLEMENTATION TExtraLegendTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Chart::TChartLegend* FLegend;
	Chart::TChartLegend* __fastcall GetLegend(void);
	void __fastcall SetLegend(const Chart::TChartLegend* Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual ~TExtraLegendTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Chart::TChartLegend* Legend = {read=GetLegend, write=SetLegend};
	__property Series ;
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TExtraLegendTool(Classes::TComponent* AOwner) : Teengine::TTeeCustomToolSeries(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TExtraLegendEditor;
class PASCALIMPLEMENTATION TExtraLegendEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	
private:
	Teeedilege::TFormTeeLegend* LegendEditor;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TExtraLegendEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TExtraLegendEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TExtraLegendEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TExtraLegendEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeextralegendtool */
using namespace Teeextralegendtool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeExtraLegendTool
