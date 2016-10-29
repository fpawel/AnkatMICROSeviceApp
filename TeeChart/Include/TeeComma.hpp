// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeComma.pas' rev: 6.00

#ifndef TeeCommaHPP
#define TeeCommaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeEdit.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teecomma
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomTeeCommander;
class PASCALIMPLEMENTATION TCustomTeeCommander : public Teeprocs::TCustomPanelNoCaption 
{
	typedef Teeprocs::TCustomPanelNoCaption inherited;
	
private:
	Tecanvas::TTeeGradient* FGradient;
	Controls::TMouseButton FMouseButton;
	Teeprocs::TCustomTeePanel* FPanel;
	bool FVertical;
	void __fastcall CanvasChanged(System::TObject* Sender);
	Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	void __fastcall ReAlignTeeControls(void);
	void __fastcall SetGradient(Tecanvas::TTeeGradient* Value);
	void __fastcall SetVertical(bool Value);
	
protected:
	HIDESBASE virtual void __fastcall DoMouseDown(int X, int Y);
	virtual void __fastcall DoMouseMove(int X, int Y, const Classes::TShiftState Shift);
	HIDESBASE virtual void __fastcall DoMouseUp(void);
	virtual bool __fastcall DoPanelMouse(void);
	void __fastcall FreeOwnedControls(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall RemovingControl(Controls::TControl* AControl);
	virtual void __fastcall SetPanel(const Teeprocs::TCustomTeePanel* Value);
	virtual void __fastcall ShowHideControls(bool Value);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	AnsiString __fastcall TeePanelClass();
	
public:
	__fastcall virtual TCustomTeeCommander(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTeeCommander(void);
	void __fastcall CreateBevel(int APos);
	Buttons::TSpeedButton* __fastcall CreateButton(int APos, Classes::TNotifyEvent AProc, const AnsiString AHint, const AnsiString AResName, int AGroupIndex)/* overload */;
	Buttons::TSpeedButton* __fastcall CreateButton(int APos, Classes::TNotifyEvent AProc, const AnsiString AHint, Graphics::TBitmap* ABitmap, int AGroupIndex)/* overload */;
	Stdctrls::TLabel* __fastcall CreateLabel(int APos, Graphics::TColor AColor);
	
__published:
	__property Tecanvas::TTeeGradient* Gradient = {read=GetGradient, write=SetGradient};
	__property Teeprocs::TCustomTeePanel* Panel = {read=FPanel, write=SetPanel};
	__property bool Vertical = {read=FVertical, write=SetVertical, default=0};
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
	__property Color  = {default=-2147483633};
	__property DragMode  = {default=0};
	__property DragCursor  = {default=-12};
	__property Enabled  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint  = {default=1};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property Anchors  = {default=3};
	__property Constraints ;
	__property AutoSize  = {default=0};
	__property DragKind  = {default=0};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnStartDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnConstrainedResize ;
	__property OnCanResize ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnEndDock ;
	__property OnStartDock ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTeeCommander(HWND ParentWindow) : Teeprocs::TCustomPanelNoCaption(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


#pragma option push -b-
enum TCommanderControls { tcbNormal, tcbSeparator, tcbRotate, tcbMove, tcbZoom, tcbDepth, tcbEdit, tcbPrintPreview, tcbCopy, tcbSave, tcbLabel, tcb3D };
#pragma option pop

class DELPHICLASS TTeeCommander;
typedef void __fastcall (__closure *TTeeEditedChartEvent)(TTeeCommander* Sender, Chart::TCustomChart* AChart);

typedef void __fastcall (__closure *TTeeCommanderOnSetLabel)(TTeeCommander* Sender, AnsiString &Text);

class PASCALIMPLEMENTATION TTeeCommander : public TCustomTeeCommander 
{
	typedef TCustomTeeCommander inherited;
	
private:
	bool FAllowFull;
	Buttons::TSpeedButton* FButtonCopy;
	Buttons::TSpeedButton* FButtonDepth;
	Buttons::TSpeedButton* FButtonEdit;
	Buttons::TSpeedButton* FButtonMove;
	Buttons::TSpeedButton* FButtonNormal;
	Buttons::TSpeedButton* FButtonPrint;
	Buttons::TSpeedButton* FButtonRotate;
	Buttons::TSpeedButton* FButtonSave;
	Buttons::TSpeedButton* FButtonZoom;
	Buttons::TSpeedButton* FButton3D;
	Teeedit::TChartEditor* FEditor;
	Teeedit::TChartPreviewer* FPreviewer;
	bool FEnablePieExp;
	Stdctrls::TLabel* FLabel;
	bool FLabelValues;
	bool FDragging;
	int FDraggingIndex;
	int FOldX;
	int FOldY;
	Series::TPieSeries* IPieSeries;
	TTeeEditedChartEvent FOnEditedChart;
	TTeeCommanderOnSetLabel FOnSetLabel;
	void __fastcall Button3DClick(System::TObject* Sender);
	void __fastcall ButtonCopyClick(System::TObject* Sender);
	void __fastcall ButtonDepthClick(System::TObject* Sender);
	void __fastcall ButtonEditClick(System::TObject* Sender);
	void __fastcall ButtonMoveClick(System::TObject* Sender);
	void __fastcall ButtonNormalClick(System::TObject* Sender);
	void __fastcall ButtonPrintClick(System::TObject* Sender);
	void __fastcall ButtonRotateClick(System::TObject* Sender);
	void __fastcall ButtonSaveClick(System::TObject* Sender);
	void __fastcall ButtonZoomClick(System::TObject* Sender);
	bool __fastcall IsButtonDown(Buttons::TSpeedButton* AButton);
	TCommanderControls __fastcall GetDefault(void);
	void __fastcall SetDefault(TCommanderControls AButton);
	void __fastcall SetLabelCaption(const AnsiString ACaption);
	void __fastcall SetLabelValues(bool Value);
	AnsiString __fastcall CaptionPanel(const AnsiString ACaption);
	Series::TPieSeries* __fastcall GetPieSeries(int x, int y);
	void __fastcall SetEditor(const Teeedit::TChartEditor* Value);
	void __fastcall SetPreviewer(const Teeedit::TChartPreviewer* Value);
	
protected:
	virtual void __fastcall DoMouseDown(int X, int Y);
	virtual void __fastcall DoMouseMove(int X, int Y, const Classes::TShiftState Shift);
	virtual void __fastcall DoMouseUp(void);
	virtual bool __fastcall DoPanelMouse(void);
	DYNAMIC void __fastcall RemovingControl(Controls::TControl* AControl);
	virtual void __fastcall ShowHideControls(bool Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TTeeCommander(Classes::TComponent* AOwner);
	void __fastcall CreateControls(const TCommanderControls * AControls, const int AControls_Size);
	void __fastcall RepositionControls(void);
	__property Buttons::TSpeedButton* Button3D = {read=FButton3D};
	__property Buttons::TSpeedButton* ButtonCopy = {read=FButtonCopy};
	__property Buttons::TSpeedButton* ButtonDepth = {read=FButtonDepth};
	__property Buttons::TSpeedButton* ButtonEdit = {read=FButtonEdit};
	__property Buttons::TSpeedButton* ButtonMove = {read=FButtonMove};
	__property Buttons::TSpeedButton* ButtonNormal = {read=FButtonNormal};
	__property Buttons::TSpeedButton* ButtonPrint = {read=FButtonPrint};
	__property Buttons::TSpeedButton* ButtonRotate = {read=FButtonRotate};
	__property Buttons::TSpeedButton* ButtonSave = {read=FButtonSave};
	__property Buttons::TSpeedButton* ButtonZoom = {read=FButtonZoom};
	__property TCommanderControls DefaultButton = {read=GetDefault, write=SetDefault, nodefault};
	__property bool FullRotation = {read=FAllowFull, write=FAllowFull, default=0};
	__property Stdctrls::TLabel* LabelText = {read=FLabel};
	void __fastcall ShowValues(void);
	
__published:
	__property Teeedit::TChartEditor* ChartEditor = {read=FEditor, write=SetEditor};
	__property Teeedit::TChartPreviewer* Previewer = {read=FPreviewer, write=SetPreviewer};
	__property bool EnablePieExploding = {read=FEnablePieExp, write=FEnablePieExp, default=1};
	__property bool LabelValues = {read=FLabelValues, write=SetLabelValues, default=1};
	__property TTeeEditedChartEvent OnEditedChart = {read=FOnEditedChart, write=FOnEditedChart};
	__property TTeeCommanderOnSetLabel OnSetLabel = {read=FOnSetLabel, write=FOnSetLabel};
public:
	#pragma option push -w-inl
	/* TCustomTeeCommander.Destroy */ inline __fastcall virtual ~TTeeCommander(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeCommander(HWND ParentWindow) : TCustomTeeCommander(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecomma */
using namespace Teecomma;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeComma
