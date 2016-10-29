// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDraw3D.pas' rev: 6.00

#ifndef TeeDraw3DHPP
#define TeeDraw3DHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedraw3d
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TDraw3DPaintEvent)(System::TObject* Sender, const Types::TRect &ARect);

class DELPHICLASS TDraw3D;
class PASCALIMPLEMENTATION TDraw3D : public Teeprocs::TCustomTeePanelExtended 
{
	typedef Teeprocs::TCustomTeePanelExtended inherited;
	
private:
	TDraw3DPaintEvent FOnPaint;
	
protected:
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
	
__published:
	__property BackImage ;
	__property BackImageMode  = {default=0};
	__property Border ;
	__property BorderRound  = {default=0};
	__property Gradient ;
	__property OnAfterDraw ;
	__property BufferedDisplay  = {default=1};
	__property MarginLeft  = {index=0, default=3};
	__property MarginTop  = {index=1, default=4};
	__property MarginRight  = {index=2, default=3};
	__property MarginBottom  = {index=3, default=4};
	__property MarginUnits  = {default=0};
	__property Monochrome  = {default=0};
	__property PrintProportional  = {default=1};
	__property PrintResolution  = {default=0};
	__property Shadow ;
	__property View3D  = {default=1};
	__property View3DOptions ;
	__property TDraw3DPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property Color  = {default=-2147483633};
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
	/* TCustomTeePanelExtended.Create */ inline __fastcall virtual TDraw3D(Classes::TComponent* AOwner) : Teeprocs::TCustomTeePanelExtended(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeePanelExtended.Destroy */ inline __fastcall virtual ~TDraw3D(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDraw3D(HWND ParentWindow) : Teeprocs::TCustomTeePanelExtended(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teedraw3d */
using namespace Teedraw3d;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDraw3D
