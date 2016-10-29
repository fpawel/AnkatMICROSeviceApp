// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGanttTool.pas' rev: 6.00

#ifndef TeeGanttToolHPP
#define TeeGanttToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <GanttCh.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teegantttool
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TGanttToolBarPart { pbStart, pbAll, pbEnd };
#pragma option pop

class DELPHICLASS TGanttTool;
typedef void __fastcall (__closure *TGanttDragEvent)(TGanttTool* Sender, int GanttBar);

typedef void __fastcall (__closure *TGanttResizeEvent)(TGanttTool* Sender, int GanttBar, TGanttToolBarPart BarPart);

class PASCALIMPLEMENTATION TGanttTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	bool FAllowDrag;
	bool FAllowResize;
	int FBar;
	TGanttToolBarPart FBarPart;
	Controls::TCursor FCursorDrag;
	Controls::TCursor FCursorResize;
	int FMinPixels;
	double FXOriginal;
	TGanttDragEvent FOnDragBar;
	TGanttResizeEvent FOnResizeBar;
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TGanttTool(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	Ganttch::TGanttSeries* __fastcall Gantt(void);
	
__published:
	__property Active  = {default=1};
	__property bool AllowDrag = {read=FAllowDrag, write=FAllowDrag, default=1};
	__property bool AllowResize = {read=FAllowResize, write=FAllowResize, default=1};
	__property Controls::TCursor CursorDrag = {read=FCursorDrag, write=FCursorDrag, default=-21};
	__property Controls::TCursor CursorResize = {read=FCursorResize, write=FCursorResize, default=-9};
	__property int MinPixels = {read=FMinPixels, write=FMinPixels, default=5};
	__property Series ;
	__property TGanttDragEvent OnDragBar = {read=FOnDragBar, write=FOnDragBar};
	__property TGanttResizeEvent OnResizeBar = {read=FOnResizeBar, write=FOnResizeBar};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TGanttTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGanttToolEditor;
class PASCALIMPLEMENTATION TGanttToolEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TCheckBox* CBAllowDrag;
	Stdctrls::TCheckBox* CBAllowResize;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBCursorDrag;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBCursorResize;
	void __fastcall Edit1Change(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBAllowDragClick(System::TObject* Sender);
	void __fastcall CBAllowResizeClick(System::TObject* Sender);
	void __fastcall CBCursorDragChange(System::TObject* Sender);
	void __fastcall CBCursorResizeChange(System::TObject* Sender);
	
private:
	bool CreatingForm;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TGanttToolEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TGanttToolEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TGanttToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGanttToolEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teegantttool */
using namespace Teegantttool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGanttTool
