// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeNavigator.pas' rev: 6.00

#ifndef TeeNavigatorHPP
#define TeeNavigatorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teenavigator
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTeeNavGlyph { ngEnabled, ngDisabled };
#pragma option pop

#pragma option push -b-
enum TTeeNavigateBtn { nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel };
#pragma option pop

typedef Set<TTeeNavigateBtn, nbFirst, nbCancel>  TTeeButtonSet;

class DELPHICLASS TTeeNavButton;
class PASCALIMPLEMENTATION TTeeNavButton : public Buttons::TSpeedButton 
{
	typedef Buttons::TSpeedButton inherited;
	
private:
	TTeeNavigateBtn FIndex;
	Extctrls::TTimer* FRepeatTimer;
	void __fastcall TimerExpired(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual ~TTeeNavButton(void);
	__property TTeeNavigateBtn Index = {read=FIndex, write=FIndex, nodefault};
public:
	#pragma option push -w-inl
	/* TSpeedButton.Create */ inline __fastcall virtual TTeeNavButton(Classes::TComponent* AOwner) : Buttons::TSpeedButton(AOwner) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TNotifyButtonClickedEvent)(TTeeNavigateBtn Index);

class DELPHICLASS TCustomTeeNavigator;
class PASCALIMPLEMENTATION TCustomTeeNavigator : public Teeprocs::TCustomPanelNoCaption 
{
	typedef Teeprocs::TCustomPanelNoCaption inherited;
	
private:
	Classes::TStrings* FHints;
	Classes::TStrings* FDefHints;
	int ButtonWidth;
	#pragma pack(push, 1)
	Types::TPoint MinBtnSize;
	#pragma pack(pop)
	
	TTeeNavigateBtn FocusedButton;
	TNotifyButtonClickedEvent FOnButtonClicked;
	Teeprocs::TCustomTeePanel* FPanel;
	void __fastcall BtnMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ClickHandler(System::TObject* Sender);
	void __fastcall CheckSize(void);
	void __fastcall HintsChanged(System::TObject* Sender);
	void __fastcall SetSize(int &W, int &H);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
protected:
	DYNAMIC void __fastcall BtnClick(TTeeNavigateBtn Index);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall InitButtons(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall DoTeeEvent(Teeprocs::TTeeEvent* Event);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetPanel(const Teeprocs::TCustomTeePanel* Value);
	
public:
	TTeeNavButton* Buttons[9];
	__fastcall virtual TCustomTeeNavigator(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTeeNavigator(void);
	virtual void __fastcall EnableButtons(void);
	void __fastcall InitHints(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual int __fastcall PageCount(void);
	__property Teeprocs::TCustomTeePanel* Panel = {read=FPanel, write=SetPanel};
	virtual void __fastcall Print(void);
	__property TNotifyButtonClickedEvent OnButtonClicked = {read=FOnButtonClicked, write=FOnButtonClicked};
	
__published:
	__property Align  = {default=0};
	__property BorderStyle  = {default=0};
	__property Color  = {default=-2147483633};
	__property UseDockManager  = {default=1};
	__property DockSite  = {default=0};
	__property DragMode  = {default=0};
	__property DragCursor  = {default=-12};
	__property Enabled  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property Anchors  = {default=3};
	__property Constraints ;
	__property DragKind  = {default=0};
	__property Locked  = {default=0};
	__property OnClick ;
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
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnResize ;
	__property OnCanResize ;
	__property OnConstrainedResize ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnEndDock ;
	__property OnGetSiteInfo ;
	__property OnStartDock ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTeeNavigator(HWND ParentWindow) : Teeprocs::TCustomPanelNoCaption(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


typedef TMetaClass*TTeePageNavigatorClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teenavigator */
using namespace Teenavigator;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeNavigator
