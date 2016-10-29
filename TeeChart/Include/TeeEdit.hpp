// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdit.pas' rev: 6.00

#ifndef TeeEditHPP
#define TeeEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeePreviewPanel.hpp>	// Pascal unit
#include <TeePrevi.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <TeeEditCha.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomChartEditor;
class PASCALIMPLEMENTATION TCustomChartEditor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Chart::TCustomChart* FChart;
	AnsiString FTitle;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetChart(const Chart::TCustomChart* Value);
	
public:
	virtual void __fastcall Execute(void);
	__property AnsiString Title = {read=FTitle, write=FTitle};
	
__published:
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomChartEditor(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomChartEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartEditor;
class PASCALIMPLEMENTATION TChartEditor : public TCustomChartEditor 
{
	typedef TCustomChartEditor inherited;
	
private:
	bool FAutoRepaint;
	Teeeditcha::TChartEditorTab FDefaultTab;
	Teeeditcha::TChartEditorHiddenTabs FHideTabs;
	bool FHighLight;
	Teelisb::TChangeOrderEvent FOnChangeOrder;
	Teeeditcha::TChartEditorOptions FOptions;
	int FPixels;
	bool FRememberPosition;
	Teengine::TChartSeries* FSeries;
	bool FTree;
	void __fastcall ChangeSeriesOrder(Teelisb::TChartListBox* Sender, Teengine::TCustomChartSeries* Series1, Teengine::TCustomChartSeries* Series2);
	void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetChart(const Chart::TCustomChart* Value);
	
public:
	__fastcall virtual TChartEditor(Classes::TComponent* AOwner);
	virtual void __fastcall Execute(void);
	
__published:
	__property bool AutoRepaint = {read=FAutoRepaint, write=FAutoRepaint, default=1};
	__property Teeeditcha::TChartEditorTab DefaultTab = {read=FDefaultTab, write=FDefaultTab, default=0};
	__property Teeeditcha::TChartEditorHiddenTabs HideTabs = {read=FHideTabs, write=FHideTabs, default=0};
	__property bool HighLightTabs = {read=FHighLight, write=FHighLight, default=0};
	__property Teeeditcha::TChartEditorOptions Options = {read=FOptions, write=FOptions, default=1919};
	__property int PixelsPerInch = {read=FPixels, write=FPixels, default=0};
	__property bool RememberPosition = {read=FRememberPosition, write=FRememberPosition, default=0};
	__property Teengine::TChartSeries* Series = {read=FSeries, write=SetSeries};
	__property Title ;
	__property bool TreeView = {read=FTree, write=FTree, default=0};
	__property Teelisb::TChangeOrderEvent OnChangeSeriesOrder = {read=FOnChangeOrder, write=FOnChangeOrder};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TChartEditor(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TChartPreviewOption { cpoChangePrinter, cpoSetupPrinter, cpoResizeChart, cpoMoveChart, cpoChangeDetail, cpoChangePaperOrientation, cpoChangeMargins, cpoProportional, cpoDragChart, cpoPrintPanel, cpoAsBitmap };
#pragma option pop

typedef Set<TChartPreviewOption, cpoChangePrinter, cpoAsBitmap>  TChartPreviewOptions;

class DELPHICLASS TChartPreviewer;
class PASCALIMPLEMENTATION TChartPreviewer : public TCustomChartEditor 
{
	typedef TCustomChartEditor inherited;
	
private:
	Classes::TNotifyEvent FOnAfterDraw;
	TChartPreviewOptions FOptions;
	Graphics::TColor FPaperColor;
	Forms::TWindowState FWindowState;
	Teeprevi::TChartPreview* TheForm;
	Teepreviewpanel::TTeePreviewPanel* __fastcall GetPreview(void);
	
public:
	__fastcall virtual TChartPreviewer(Classes::TComponent* AOwner);
	virtual void __fastcall Execute(void);
	__property Teepreviewpanel::TTeePreviewPanel* PreviewPanel = {read=GetPreview};
	
__published:
	__property TChartPreviewOptions Options = {read=FOptions, write=FOptions, default=255};
	__property Graphics::TColor PaperColor = {read=FPaperColor, write=FPaperColor, default=16777215};
	__property Title ;
	__property Forms::TWindowState WindowState = {read=FWindowState, write=FWindowState, default=0};
	__property Classes::TNotifyEvent OnAfterDraw = {read=FOnAfterDraw, write=FOnAfterDraw};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TChartPreviewer(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartEditorPanel;
class PASCALIMPLEMENTATION TChartEditorPanel : public Teeprocs::TCustomPanelNoCaption 
{
	typedef Teeprocs::TCustomPanelNoCaption inherited;
	
private:
	Chart::TCustomChart* FChart;
	Teeeditcha::TChartEditForm* FEditor;
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	void __fastcall SetChart(Chart::TCustomChart* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TChartEditorPanel(Classes::TComponent* AOwner);
	void __fastcall SelectUnderMouse(void);
	__property Teeeditcha::TChartEditForm* Editor = {read=FEditor};
	
__published:
	__property Align  = {default=0};
	__property BevelOuter  = {default=1};
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property UseDockManager  = {default=1};
	__property DockSite  = {default=0};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=0};
	__property Constraints ;
	__property DragKind  = {default=0};
	__property Locked  = {default=0};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnStartDrag ;
	__property OnConstrainedResize ;
	__property OnCanResize ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnEndDock ;
	__property OnGetSiteInfo ;
	__property OnStartDock ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TChartEditorPanel(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartEditorPanel(HWND ParentWindow) : Teeprocs::TCustomPanelNoCaption(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define DefaultChartPreviewOptions (System::Set<TChartPreviewOption, cpoChangePrinter, cpoAsBitmap> () << TChartPreviewOption(0) << TChartPreviewOption(1) << TChartPreviewOption(2) << TChartPreviewOption(3) << TChartPreviewOption(4) << TChartPreviewOption(5) << TChartPreviewOption(6) << TChartPreviewOption(7) )

}	/* namespace Teeedit */
using namespace Teeedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdit
