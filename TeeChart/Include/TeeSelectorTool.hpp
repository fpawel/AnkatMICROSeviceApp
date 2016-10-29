// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSelectorTool.pas' rev: 6.00

#ifndef TeeSelectorToolHPP
#define TeeSelectorToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teeselectortool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSelectorTool;
class PASCALIMPLEMENTATION TSelectorTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	bool FAllowDrag;
	bool FAllowResizeChart;
	Controls::TCursor FCursor;
	int FHandleSize;
	Classes::TNotifyEvent FOnDragged;
	Classes::TNotifyEvent FOnDragging;
	Classes::TNotifyEvent FOnResized;
	Classes::TNotifyEvent FOnResizing;
	Classes::TNotifyEvent FOnSelected;
	Teetools::TAnnotationTool* FAnnotation;
	bool FDrawHandles;
	Chart::TTeeCustomShapePosition* FShape;
	Chart::TChartWall* FWall;
	bool IDragging;
	bool IDragged;
	#pragma pack(push, 1)
	Types::TPoint IDif;
	#pragma pack(pop)
	
	bool IResizingChart;
	bool IResized;
	void __fastcall EmptySelection(void);
	Classes::TPersistent* __fastcall GetSelection(void);
	Teengine::TChartSeries* __fastcall GetSeries(void);
	void __fastcall SetHandleSize(const int Value);
	void __fastcall SetAnnotation(const Teetools::TAnnotationTool* Value);
	void __fastcall SetWall(const Chart::TChartWall* Value);
	void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoSelected(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
public:
	#pragma pack(push, 1)
	Teengine::TChartClickedPart Part;
	#pragma pack(pop)
	
	__fastcall virtual TSelectorTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TSelectorTool(void);
	void __fastcall ClearSelection(void);
	void __fastcall StopDragging(void);
	bool __fastcall ClickedCorner(int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	Chart::TChartTitle* __fastcall SelectedTitle(void);
	__property Teetools::TAnnotationTool* Annotation = {read=FAnnotation, write=SetAnnotation};
	__property Chart::TTeeCustomShapePosition* DraggingShape = {read=FShape};
	__property bool DrawHandles = {read=FDrawHandles, write=FDrawHandles, nodefault};
	__property Classes::TPersistent* Selection = {read=GetSelection};
	__property Teengine::TChartSeries* Series = {read=GetSeries, write=SetSeries};
	__property Chart::TChartWall* Wall = {read=FWall, write=SetWall};
	
__published:
	__property Active  = {default=1};
	__property bool AllowDrag = {read=FAllowDrag, write=FAllowDrag, default=1};
	__property bool AllowResizeChart = {read=FAllowResizeChart, write=FAllowResizeChart, default=0};
	__property Brush ;
	__property Controls::TCursor Cursor = {read=FCursor, write=FCursor, default=-21};
	__property int HandleSize = {read=FHandleSize, write=SetHandleSize, default=3};
	__property Pen ;
	__property Classes::TNotifyEvent OnDragged = {read=FOnDragged, write=FOnDragged};
	__property Classes::TNotifyEvent OnDragging = {read=FOnDragging, write=FOnDragging};
	__property Classes::TNotifyEvent OnResized = {read=FOnResized, write=FOnResized};
	__property Classes::TNotifyEvent OnResizing = {read=FOnResizing, write=FOnResizing};
	__property Classes::TNotifyEvent OnSelected = {read=FOnSelected, write=FOnSelected};
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


class DELPHICLASS TSelectorToolEditor;
class PASCALIMPLEMENTATION TSelectorToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* ButtonPen1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDSize;
	Tecanvas::TButtonColor* ButtonColor1;
	Stdctrls::TCheckBox* CBAllowDrag;
	Stdctrls::TCheckBox* CBResizeChart;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBCursor;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall CBAllowDragClick(System::TObject* Sender);
	void __fastcall CBResizeChartClick(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	
private:
	TSelectorTool* Selector;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSelectorToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSelectorToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSelectorToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSelectorToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeselectortool */
using namespace Teeselectortool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSelectorTool
