// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSeriesBandTool.pas' rev: 6.00

#ifndef TeeSeriesBandToolHPP
#define TeeSeriesBandToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeProCo.hpp>	// Pascal unit
#include <TeeConst.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
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

namespace Teeseriesbandtool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSeriesBandTool;
class PASCALIMPLEMENTATION TSeriesBandTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	bool FDrawBehind;
	Tecanvas::TTeeGradient* FGradient;
	Teengine::TChartSeries* FSeries2;
	Tecanvas::TTeeTransparency FTransparency;
	bool ISerie1Drawed;
	bool ISerie2Drawed;
	double FBoundValue;
	void __fastcall AfterSeriesDraw(System::TObject* Sender);
	void __fastcall BeforeSeriesDraw(System::TObject* Sender);
	void __fastcall RemoveEvents(Teengine::TChartSeries* ASeries);
	void __fastcall SetDrawBehind(const bool Value);
	void __fastcall SetEvents(Teengine::TChartSeries* ASeries);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetBoundValue(const double Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	virtual void __fastcall SetSeries2(const Teengine::TChartSeries* Value);
	virtual void __fastcall DrawBandTool(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TSeriesBandTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TSeriesBandTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property double BoundValue = {read=FBoundValue, write=SetBoundValue};
	__property Active  = {default=1};
	__property Brush ;
	__property bool DrawBehindSeries = {read=FDrawBehind, write=SetDrawBehind, default=1};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Pen ;
	__property Series ;
	__property Teengine::TChartSeries* Series2 = {read=FSeries2, write=SetSeries2};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
};


class DELPHICLASS TSeriesBandToolEdit;
class PASCALIMPLEMENTATION TSeriesBandToolEdit : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Stdctrls::TButton* Button1;
	Stdctrls::TCheckBox* CBDrawBehindSeries;
	Teependlg::TButtonPen* BPen;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBSeries2;
	Teeedigrad::TButtonGradient* BGradient;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* ETransp;
	Comctrls::TUpDown* UDTransp;
	void __fastcall Button1Click(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBDrawBehindSeriesClick(System::TObject* Sender);
	void __fastcall CBSeries2Change(System::TObject* Sender);
	void __fastcall ETranspChange(System::TObject* Sender);
	
private:
	TSeriesBandTool* SeriesBand;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSeriesBandToolEdit(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesBandToolEdit(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSeriesBandToolEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesBandToolEdit(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeseriesbandtool */
using namespace Teeseriesbandtool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSeriesBandTool
