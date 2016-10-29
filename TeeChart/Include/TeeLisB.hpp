// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLisB.pas' rev: 6.00

#ifndef TeeLisBHPP
#define TeeLisBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teelisb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartListBox;
typedef void __fastcall (__closure *TDblClickSeriesEvent)(TChartListBox* Sender, int Index);

typedef void __fastcall (__closure *TNotifySeriesEvent)(TChartListBox* Sender, Teengine::TCustomChartSeries* Series);

typedef void __fastcall (__closure *TChangeOrderEvent)(TChartListBox* Sender, Teengine::TCustomChartSeries* Series1, Teengine::TCustomChartSeries* Series2);

#pragma pack(push, 1)
struct TListBoxSection
{
	int Width;
	bool Visible;
} ;
#pragma pack(pop)

typedef TListBoxSection TListBoxSections[4];

class PASCALIMPLEMENTATION TChartListBox : public Stdctrls::TCustomListBox 
{
	typedef Stdctrls::TCustomListBox inherited;
	
private:
	bool FAllowAdd;
	bool FAllowDelete;
	bool FAskDelete;
	Chart::TCustomChart* FChart;
	Chart::TCheckBoxesStyle FCheckStyle;
	Stdctrls::TEdit* FEditor;
	bool FEnableChangeColor;
	bool FEnableDragSeries;
	bool FEnableChangeType;
	bool FFontSeriesColor;
	Teengine::TSeriesGroup* FGroup;
	#pragma pack(push, 1)
	Types::TPoint FHitTest;
	#pragma pack(pop)
	
	bool FNames;
	TNotifySeriesEvent FOnChangeActive;
	TNotifySeriesEvent FOnChangeColor;
	TChangeOrderEvent FOnChangeOrder;
	TDblClickSeriesEvent FOnEditSeries;
	TNotifySeriesEvent FOnRemovedSeries;
	Classes::TStrings* FOtherItems;
	Classes::TNotifyEvent FOtherItemsChange;
	Classes::TNotifyEvent FRefresh;
	bool ComingFromDoubleClick;
	void __fastcall CheckLegendBoxes(void);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	void __fastcall DoRefresh(void);
	void __fastcall EditorKey(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall EditorPress(System::TObject* Sender, char &Key);
	Teengine::TChartSeries* __fastcall GetSelectedSeries(void);
	Teengine::TCustomSeriesList* __fastcall GetSeriesGroup(void);
	bool __fastcall GetShowActive(void);
	bool __fastcall GetShowIcon(void);
	bool __fastcall GetShowColor(void);
	bool __fastcall GetShowTitle(void);
	Teengine::TChartSeries* __fastcall GetSeries(int Index);
	void __fastcall LBSeriesClick(System::TObject* Sender);
	void __fastcall LBSeriesDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall LBSeriesDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall RefreshDesigner(void);
	int __fastcall SectionLeft(int ASection);
	void __fastcall SelectSeries(int AIndex);
	void __fastcall SetChart(Chart::TCustomChart* Value);
	void __fastcall SetCheckStyle(Chart::TCheckBoxesStyle Value);
	void __fastcall SetFontSeriesColor(const bool Value);
	void __fastcall SetGroup(Teengine::TSeriesGroup* Value);
	void __fastcall SetNames(bool Value);
	void __fastcall SetSelectedSeries(Teengine::TChartSeries* Value);
	void __fastcall SetShowActive(bool Value);
	void __fastcall SetShowIcon(bool Value);
	void __fastcall SetShowColor(bool Value);
	void __fastcall SetShowTitle(bool Value);
	Controls::TWinControl* __fastcall VerifyParent(Controls::TWinControl* &AControl);
	
protected:
	DYNAMIC void __fastcall DblClick(void);
	virtual int __fastcall GetItemIndex(void);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Msg);
	virtual void __fastcall SetParent(Controls::TWinControl* Control);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
public:
	Chart::TCustomChart* ReferenceChart;
	TListBoxSection Sections[4];
	__fastcall virtual TChartListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartListBox(void);
	Teengine::TChartSeries* __fastcall AddSeriesGallery(void);
	bool __fastcall AnySelected(void);
	void __fastcall ChangeTypeSeries(System::TObject* Sender);
	void __fastcall ClearItems(void);
	void __fastcall CloneSeries(void);
	bool __fastcall DeleteSeries(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	void __fastcall FillSeries(Teengine::TChartSeries* OldSeries);
	void __fastcall HideEditor(void);
	void __fastcall MoveCurrentDown(void);
	void __fastcall MoveCurrentUp(void);
	__property Classes::TStrings* OtherItems = {read=FOtherItems, write=FOtherItems};
	bool __fastcall PointInSection(const Types::TPoint &P, int ASection);
	bool __fastcall RenameSeries(void);
	virtual void __fastcall SelectAll(void);
	__property Teengine::TChartSeries* Series[int Index] = {read=GetSeries};
	__property Teengine::TSeriesGroup* SeriesGroup = {read=FGroup, write=SetGroup};
	int __fastcall SeriesAtMousePos(Types::TPoint &p);
	__property Teengine::TChartSeries* SelectedSeries = {read=GetSelectedSeries, write=SetSelectedSeries};
	void __fastcall ShowEditor(void);
	void __fastcall SwapSeries(int tmp1, int tmp2);
	void __fastcall UpdateSeries(void);
	__property bool ShowSeriesNames = {read=FNames, write=SetNames, nodefault};
	
__published:
	__property bool AllowAddSeries = {read=FAllowAdd, write=FAllowAdd, default=1};
	__property bool AllowDeleteSeries = {read=FAllowDelete, write=FAllowDelete, default=1};
	__property bool AskDelete = {read=FAskDelete, write=FAskDelete, default=1};
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property Chart::TCheckBoxesStyle CheckStyle = {read=FCheckStyle, write=SetCheckStyle, default=0};
	__property bool EnableChangeColor = {read=FEnableChangeColor, write=FEnableChangeColor, default=1};
	__property bool EnableDragSeries = {read=FEnableDragSeries, write=FEnableDragSeries, default=1};
	__property bool EnableChangeType = {read=FEnableChangeType, write=FEnableChangeType, default=1};
	__property bool FontSeriesColor = {read=FFontSeriesColor, write=SetFontSeriesColor, default=0};
	__property TNotifySeriesEvent OnChangeActive = {read=FOnChangeActive, write=FOnChangeActive};
	__property TNotifySeriesEvent OnChangeColor = {read=FOnChangeColor, write=FOnChangeColor};
	__property TChangeOrderEvent OnChangeOrder = {read=FOnChangeOrder, write=FOnChangeOrder};
	__property TDblClickSeriesEvent OnDblClickSeries = {read=FOnEditSeries, write=FOnEditSeries};
	__property Classes::TNotifyEvent OnOtherItemsChange = {read=FOtherItemsChange, write=FOtherItemsChange};
	__property Classes::TNotifyEvent OnRefresh = {read=FRefresh, write=FRefresh};
	__property TNotifySeriesEvent OnRemovedSeries = {read=FOnRemovedSeries, write=FOnRemovedSeries};
	__property bool ShowActiveCheck = {read=GetShowActive, write=SetShowActive, default=1};
	__property bool ShowSeriesColor = {read=GetShowColor, write=SetShowColor, default=1};
	__property bool ShowSeriesIcon = {read=GetShowIcon, write=SetShowIcon, default=1};
	__property bool ShowSeriesTitle = {read=GetShowTitle, write=SetShowTitle, default=1};
	__property OnDrawItem ;
	__property Align  = {default=0};
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Ctl3D ;
	__property Enabled  = {default=1};
	__property ExtendedSelect  = {default=1};
	__property Font ;
	__property ImeMode  = {default=3};
	__property ImeName ;
	__property ItemHeight ;
	__property MultiSelect  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartListBox(HWND ParentWindow) : Stdctrls::TCustomListBox(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Teengine::TChartSeries* __fastcall (*TeeAddGalleryProc)(Classes::TComponent* AOwner, Chart::TCustomChart* Chart, Teengine::TChartSeries* Series);
extern PACKAGE TMetaClass* __fastcall (*TeeChangeGalleryProc)(Classes::TComponent* AOwner, Teengine::TChartSeries* &Series);

}	/* namespace Teelisb */
using namespace Teelisb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLisB
