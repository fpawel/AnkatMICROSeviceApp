// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeChartGrid.pas' rev: 6.00

#ifndef TeeChartGridHPP
#define TeeChartGridHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StdCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teechartgrid
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TChartGridShow { cgsAuto, cgsNo, cgsYes };
#pragma option pop

class DELPHICLASS TCustomChartGrid;
typedef void __fastcall (__closure *TEditingCellEvent)(TCustomChartGrid* Sender, int ACol, int ARow, bool &Allow);

typedef DynamicArray<bool >  TeeChartGrid__2;

class DELPHICLASS TChartGridNavigator;
class PASCALIMPLEMENTATION TChartGridNavigator : public Teenavigator::TCustomTeeNavigator 
{
	typedef Teenavigator::TCustomTeeNavigator inherited;
	
private:
	TCustomChartGrid* FGrid;
	void __fastcall ActiveChanged(System::TObject* Sender);
	void __fastcall EnableButtonsColRow(int ACol, int ARow);
	void __fastcall SelectedChanged(System::TObject* Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall SetGrid(TCustomChartGrid* Value);
	
protected:
	DYNAMIC void __fastcall BtnClick(Teenavigator::TTeeNavigateBtn Index);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual void __fastcall EnableButtons(void);
	
__published:
	__property TCustomChartGrid* Grid = {read=FGrid, write=SetGrid};
public:
	#pragma option push -w-inl
	/* TCustomTeeNavigator.Create */ inline __fastcall virtual TChartGridNavigator(Classes::TComponent* AOwner) : Teenavigator::TCustomTeeNavigator(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeeNavigator.Destroy */ inline __fastcall virtual ~TChartGridNavigator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartGridNavigator(HWND ParentWindow) : Teenavigator::TCustomTeeNavigator(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomChartGrid : public Grids::TCustomGrid 
{
	typedef Grids::TCustomGrid inherited;
	
private:
	bool FSeriesSymbolClickable;
	bool FAllowAppend;
	bool FAllowInsertSeries;
	Chart::TCustomChart* FChart;
	bool FColors;
	bool FGrid3DMode;
	bool FLabels;
	TChartGridShow FXValues;
	AnsiString FOldValue;
	Classes::TNotifyEvent FOnChangeColor;
	TEditingCellEvent FOnEditing;
	Grids::TSetEditEvent FOnSetCell;
	bool FShowFields;
	bool FWasNull;
	DynamicArray<bool >  IHasNo;
	TChartGridNavigator* INavigator;
	Teengine::TChartSeries* FSeries;
	Teengine::TCustomAxisPanel* ISeriesChart;
	void __fastcall AddListener(Teengine::TCustomAxisPanel* AChart);
	bool __fastcall AtSeriesColor(Teengine::TChartSeries* &Series);
	bool __fastcall GetReadOnly(void);
	void __fastcall NotifyChange(void);
	void __fastcall Regenerate(void);
	void __fastcall RemoveListener(Teengine::TCustomAxisPanel* AChart);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetChart(Chart::TCustomChart* AChart);
	void __fastcall SetGrid3DMode(bool Value);
	void __fastcall SetManualData(Teengine::TChartSeries* ASeries);
	void __fastcall SetNavigator(TChartGridNavigator* ANavigator);
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetShowColors(bool Value);
	void __fastcall SetShowFields(bool Value);
	void __fastcall SetShowLabels(bool Value);
	void __fastcall SetShowXValues(TChartGridShow Value);
	void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	Types::TRect __fastcall SymbolRect(const Types::TRect &Rect);
	
protected:
	Classes::TNotifyEvent FActiveChanged;
	Grids::TSelectCellEvent FSelectedChanged;
	DYNAMIC bool __fastcall CanEditModify(void);
	virtual bool __fastcall CanEditShow(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	DYNAMIC AnsiString __fastcall GetEditText(int ACol, int ARow);
	Teengine::TChartSeries* __fastcall GetSeriesColor(/* out */ Graphics::TColor &AColor)/* overload */;
	Teengine::TChartSeries* __fastcall GetSeriesColor(/* out */ Graphics::TColor &AColor, int ACol, int ARow)/* overload */;
	bool __fastcall HasPoints(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const AnsiString Value);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
public:
	bool AllowChanges;
	__fastcall virtual TCustomChartGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomChartGrid(void);
	void __fastcall AppendRow(void);
	void __fastcall ChangeColor(void)/* overload */;
	void __fastcall ChangeColor(Graphics::TColor AColor)/* overload */;
	void __fastcall ChangeColor(Teengine::TChartSeries* ASeries, Graphics::TColor AColor)/* overload */;
	int __fastcall ColorsColumn(void);
	void __fastcall Delete(void);
	int __fastcall FindXYZIndex(Teengine::TChartSeries* ASeries, int ARow, int ACol);
	int __fastcall FirstRowNum(void);
	Teengine::TChartSeries* __fastcall GetSeries(int ACol)/* overload */;
	Teengine::TChartSeries* __fastcall GetSeries(int ACol, Teengine::TChartValueList* &AList)/* overload */;
	Teengine::TChartSeries* __fastcall GetXYZSeries(void);
	HIDESBASE void __fastcall Insert(void);
	int __fastcall LabelsColumn(void);
	void __fastcall RecalcDimensions(void);
	void __fastcall StartEditing(void);
	void __fastcall StopEditing(bool Cancel);
	__property bool SeriesSymbolClickable = {read=FSeriesSymbolClickable, write=FSeriesSymbolClickable, default=1};
	__property bool AllowAppend = {read=FAllowAppend, write=FAllowAppend, default=1};
	__property bool AllowInsertSeries = {read=FAllowInsertSeries, write=FAllowInsertSeries, default=0};
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property Teengine::TChartSeries* Series = {read=FSeries, write=SetSeries};
	__property bool ShowColors = {read=FColors, write=SetShowColors, default=0};
	__property bool ShowFields = {read=FShowFields, write=SetShowFields, default=1};
	__property bool ShowLabels = {read=FLabels, write=SetShowLabels, default=1};
	__property TChartGridShow ShowXValues = {read=FXValues, write=SetShowXValues, default=0};
	__property FixedCols  = {default=1};
	__property DefaultRowHeight  = {default=16};
	__property bool Grid3DMode = {read=FGrid3DMode, write=SetGrid3DMode, default=0};
	__property GridLineWidth  = {default=1};
	__property Classes::TNotifyEvent OnChangeColor = {read=FOnChangeColor, write=FOnChangeColor};
	__property TEditingCellEvent OnEditingCell = {read=FOnEditing, write=FOnEditing};
	__property Grids::TSetEditEvent OnSetEditText = {read=FOnSetCell, write=FOnSetCell};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomChartGrid(HWND ParentWindow) : Grids::TCustomGrid(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


class DELPHICLASS TChartGrid;
class PASCALIMPLEMENTATION TChartGrid : public TCustomChartGrid 
{
	typedef TCustomChartGrid inherited;
	
public:
	__property Col ;
	__property ColCount  = {default=5};
	__property ColWidths ;
	__property EditorMode ;
	__property GridHeight ;
	__property GridWidth ;
	__property LeftCol ;
	__property Selection ;
	__property Row ;
	__property RowCount  = {default=5};
	__property RowHeights ;
	__property TabStops ;
	__property TopRow ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DefaultColWidth  = {default=64};
	__property DefaultRowHeight  = {default=16};
	__property DefaultDrawing  = {default=1};
	__property DragMode  = {default=0};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property Enabled  = {default=1};
	__property FixedColor  = {default=-2147483633};
	__property Font ;
	__property GridLineWidth  = {default=1};
	__property Options  = {default=31};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnStartDrag ;
	__property OnEndDock ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnStartDock ;
	__property Chart ;
	__property Series ;
	__property ShowColors  = {default=0};
	__property ShowLabels  = {default=1};
	__property ShowXValues  = {default=0};
	__property OnChangeColor ;
	__property OnEditingCell ;
	__property OnSetEditText ;
public:
	#pragma option push -w-inl
	/* TCustomChartGrid.Create */ inline __fastcall virtual TChartGrid(Classes::TComponent* AOwner) : TCustomChartGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartGrid.Destroy */ inline __fastcall virtual ~TChartGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartGrid(HWND ParentWindow) : TCustomChartGrid(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teechartgrid */
using namespace Teechartgrid;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeChartGrid
