// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePieTool.pas' rev: 6.00

#ifndef TeePieToolHPP
#define TeePieToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
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

namespace Teepietool
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TPieToolStyle { ptFocus, ptExplode };
#pragma option pop

class DELPHICLASS TPieTool;
class PASCALIMPLEMENTATION TPieTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	int FSpeed;
	TPieToolStyle FStyle;
	int ISlice;
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall FocusSlice(int ValueIndex, bool Focused);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TPieTool(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property int Slice = {read=ISlice, nodefault};
	
__published:
	__property Active  = {default=1};
	__property Pen ;
	__property Series ;
	__property TPieToolStyle Style = {read=FStyle, write=FStyle, default=0};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TPieTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPieToolEditor;
class PASCALIMPLEMENTATION TPieToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBPieSeries;
	Extctrls::TRadioGroup* RGStyle;
	Teependlg::TButtonPen* BPen;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBPieSeriesChange(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	
private:
	TPieTool* Tool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPieToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPieToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPieToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPieToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepietool */
using namespace Teepietool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePieTool
