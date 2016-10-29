// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeMagnifyTool.pas' rev: 6.00

#ifndef TeeMagnifyToolHPP
#define TeeMagnifyToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeAnnToolEdit.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teemagnifytool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMagnifyTool;
class PASCALIMPLEMENTATION TMagnifyTool : public Teetools::TRectangleTool 
{
	typedef Teetools::TRectangleTool inherited;
	
private:
	bool FCircled;
	bool FFollowMouse;
	double FPercent;
	bool FSmooth;
	int FWheelZoom;
	void __fastcall DrawLoupe(void);
	void __fastcall SetCircled(const bool Value);
	void __fastcall SetPercent(const double Value);
	void __fastcall SetSmooth(const bool Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton AButton, Classes::TShiftState AShift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall WheelMouseEvent(Teengine::TWheelMouseEvent AEvent, int WheelDelta, int X, int Y);
	
public:
	__fastcall virtual TMagnifyTool(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property bool Circled = {read=FCircled, write=SetCircled, default=0};
	__property bool FollowMouse = {read=FFollowMouse, write=FFollowMouse, default=0};
	__property Pen ;
	__property double Percent = {read=FPercent, write=SetPercent};
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
	__property int WheelZoom = {read=FWheelZoom, write=FWheelZoom, default=5};
public:
	#pragma option push -w-inl
	/* TAnnotationTool.Destroy */ inline __fastcall virtual ~TMagnifyTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMagnifyToolEditor;
class PASCALIMPLEMENTATION TMagnifyToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TCheckBox* CBFollow;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TLabel* Label7;
	Comctrls::TTrackBar* TBFactor;
	Teependlg::TButtonPen* BBorder;
	Stdctrls::TCheckBox* CBCircled;
	Stdctrls::TLabel* Label9;
	Tecanvas::TComboFlat* CBCursor;
	Stdctrls::TCheckBox* CBDrag;
	Stdctrls::TCheckBox* CBResize;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDWheel;
	Stdctrls::TLabel* Label2;
	void __fastcall CBFollowClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall TBFactorChange(System::TObject* Sender);
	void __fastcall CBCircledClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	void __fastcall CBDragClick(System::TObject* Sender);
	void __fastcall CBResizeClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teeanntooledit::TAnnotationToolEdit* IAnnEditor;
	
public:
	TMagnifyTool* Zoom;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMagnifyToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMagnifyToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMagnifyToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMagnifyToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teemagnifytool */
using namespace Teemagnifytool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeMagnifyTool
