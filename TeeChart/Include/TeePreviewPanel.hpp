// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePreviewPanel.pas' rev: 6.00

#ifndef TeePreviewPanelHPP
#define TeePreviewPanelHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepreviewpanel
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTeePreviewPanelOrientation { ppoDefault, ppoPortrait, ppoLandscape };
#pragma option pop

typedef void __fastcall (__closure *TOnChangeMarginsEvent)(System::TObject* Sender, bool DisableProportional, const Types::TRect &NewMargins);

typedef void __fastcall (__closure *TOnGetPaperRect)(System::TObject* Sender, Types::TRect &PaperRect);

class DELPHICLASS TPreviewChartPen;
class PASCALIMPLEMENTATION TPreviewChartPen : public Tecanvas::TChartPen 
{
	typedef Tecanvas::TChartPen inherited;
	
__published:
	__property Style  = {default=2};
	__property SmallDots  = {default=1};
public:
	#pragma option push -w-inl
	/* TChartPen.Create */ inline __fastcall TPreviewChartPen(Classes::TNotifyEvent OnChangeEvent) : Tecanvas::TChartPen(OnChangeEvent) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TPreviewChartPen(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TeePreviewZones { teePrev_None, teePrev_Left, teePrev_Top, teePrev_Right, teePrev_Bottom, teePrev_Image, teePrev_LeftTop, teePrev_RightTop, teePrev_LeftBottom, teePrev_RightBottom };
#pragma option pop

class DELPHICLASS TTeePanelsList;
class PASCALIMPLEMENTATION TTeePanelsList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	Teeprocs::TCustomTeePanel* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE Teeprocs::TCustomTeePanel* __fastcall Get(int Index);
	HIDESBASE void __fastcall Put(int Index, Teeprocs::TCustomTeePanel* Value);
	
public:
	__property Teeprocs::TCustomTeePanel* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TTeePanelsList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeePanelsList(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TTeePreviewPanel;
class PASCALIMPLEMENTATION TTeePreviewPanel : public Teeprocs::TCustomTeePanelExtended 
{
	typedef Teeprocs::TCustomTeePanelExtended inherited;
	
private:
	bool FAllowResize;
	bool FAllowMove;
	bool FAsBitmap;
	TTeePanelsList* FPanels;
	bool FDragImage;
	TPreviewChartPen* FMargins;
	TTeePreviewPanelOrientation FOrientation;
	TOnChangeMarginsEvent FOnChangeMargins;
	TOnGetPaperRect FOnGetPaperRect;
	Graphics::TColor FPaperColor;
	Tecanvas::TTeeShadow* FPaperShadow;
	bool FShowImage;
	bool FSmoothBitmap;
	AnsiString FTitle;
	TeePreviewZones IDragged;
	int OldX;
	int OldY;
	#pragma pack(push, 1)
	Types::TRect OldRect;
	#pragma pack(pop)
	
	bool IOldShowImage;
	void __fastcall CheckPrinterOrientation(void);
	Teeprocs::TCustomTeePanel* __fastcall GetPanel(void);
	Graphics::TBitmap* __fastcall GetPrintingBitmap(Teeprocs::TCustomTeePanel* APanel);
	Graphics::TColor __fastcall GetShadowColor(void);
	int __fastcall GetShadowSize(void);
	void __fastcall SendAsBitmap(Teeprocs::TCustomTeePanel* APanel, Graphics::TCanvas* ACanvas, const Types::TRect &R)/* overload */;
	void __fastcall SendAsBitmap(Teeprocs::TCustomTeePanel* APanel, const Types::TRect &R)/* overload */;
	void __fastcall SetAsBitmap(bool Value);
	void __fastcall SetMargins(TPreviewChartPen* Value);
	void __fastcall SetOrientation(TTeePreviewPanelOrientation Value);
	void __fastcall SetPanel(Teeprocs::TCustomTeePanel* Value);
	void __fastcall SetPaperColor(Graphics::TColor Value);
	void __fastcall SetPaperShadow(Tecanvas::TTeeShadow* Value);
	void __fastcall SetShadowColor(Graphics::TColor Value);
	void __fastcall SetShadowSize(int Value);
	void __fastcall SetShowImage(bool Value);
	void __fastcall SetSmoothBitmap(const bool Value);
	
protected:
	Types::TRect __fastcall CalcImagePrintMargins(Teeprocs::TCustomTeePanel* APanel);
	void __fastcall DrawPaper(void);
	void __fastcall DrawPanelImage(Teeprocs::TCustomTeePanel* APanel);
	void __fastcall DrawMargins(const Types::TRect &R);
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	TeePreviewZones __fastcall WhereIsCursor(int x, int y);
	
public:
	#pragma pack(push, 1)
	Types::TRect ImageRect;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TRect PaperRect;
	#pragma pack(pop)
	
	__fastcall virtual TTeePreviewPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeePreviewPanel(void);
	HIDESBASE void __fastcall Print(void);
	__property TTeePanelsList* Panels = {read=FPanels};
	__property Graphics::TColor ShadowColor = {read=GetShadowColor, write=SetShadowColor, nodefault};
	__property int ShadowSize = {read=GetShadowSize, write=SetShadowSize, nodefault};
	
__published:
	__property bool AllowResize = {read=FAllowResize, write=FAllowResize, default=1};
	__property bool AllowMove = {read=FAllowMove, write=FAllowMove, default=1};
	__property bool AsBitmap = {read=FAsBitmap, write=SetAsBitmap, default=0};
	__property bool DragImage = {read=FDragImage, write=FDragImage, default=0};
	__property TPreviewChartPen* Margins = {read=FMargins, write=SetMargins};
	__property TTeePreviewPanelOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property Teeprocs::TCustomTeePanel* Panel = {read=GetPanel, write=SetPanel};
	__property Graphics::TColor PaperColor = {read=FPaperColor, write=SetPaperColor, default=16777215};
	__property Tecanvas::TTeeShadow* PaperShadow = {read=FPaperShadow, write=SetPaperShadow};
	__property Shadow ;
	__property bool ShowImage = {read=FShowImage, write=SetShowImage, default=1};
	__property bool SmoothBitmap = {read=FSmoothBitmap, write=SetSmoothBitmap, default=1};
	__property AnsiString Title = {read=FTitle, write=FTitle};
	__property TOnChangeMarginsEvent OnChangeMargins = {read=FOnChangeMargins, write=FOnChangeMargins};
	__property TOnGetPaperRect OnGetPaperRect = {read=FOnGetPaperRect, write=FOnGetPaperRect};
	__property BackImage ;
	__property BackImageMode  = {default=0};
	__property Border ;
	__property BorderRound  = {default=0};
	__property Gradient ;
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property Color  = {default=-2147483633};
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
	__property AutoSize  = {default=0};
	__property Constraints ;
	__property DragKind  = {default=0};
	__property Locked  = {default=0};
	__property OnAfterDraw ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnStartDrag ;
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
	/* TWinControl.CreateParented */ inline __fastcall TTeePreviewPanel(HWND ParentWindow) : Teeprocs::TCustomTeePanelExtended(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepreviewpanel */
using namespace Teepreviewpanel;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePreviewPanel
