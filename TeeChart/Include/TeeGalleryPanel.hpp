// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGalleryPanel.pas' rev: 6.00

#ifndef TeeGalleryPanelHPP
#define TeeGalleryPanelHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teegallerypanel
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGalleryChart;
class PASCALIMPLEMENTATION TGalleryChart : public Chart::TCustomChart 
{
	typedef Chart::TCustomChart inherited;
	
private:
	bool FSmooth;
	bool ICreatingBitmap;
	void __fastcall AfterDraw(System::TObject* Sender);
	Types::TPoint __fastcall ArrowOrigin();
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	void __fastcall DrawSmoothChart(void);
	void __fastcall DrawSubGalleryArrow(void);
	void __fastcall SetSmooth(bool Value);
	
public:
	__fastcall virtual TGalleryChart(Classes::TComponent* AOwner);
	void __fastcall DrawFrame3D(bool Erase);
	void __fastcall Focus(bool Is3D);
	void __fastcall SetMargins(void);
	void __fastcall UnFocus(bool Is3D);
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
public:
	#pragma option push -w-inl
	/* TCustomChart.Destroy */ inline __fastcall virtual ~TGalleryChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGalleryChart(HWND ParentWindow) : Chart::TCustomChart(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TChartList;
class PASCALIMPLEMENTATION TChartList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TGalleryChart* operator[](int Index) { return Items[Index]; }
	
private:
	TGalleryChart* __fastcall GetChart(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property TGalleryChart* Items[int Index] = {read=GetChart/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TChartList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartList(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TChartGalleryPanel;
class PASCALIMPLEMENTATION TChartGalleryPanel : public Teeprocs::TCustomPanelNoCaption 
{
	typedef Teeprocs::TCustomPanelNoCaption inherited;
	
public:
	TGalleryChart* operator[](int Index) { return Chart[Index]; }
	
private:
	TChartList* FCharts;
	int FColWidth;
	bool FDisplaySub;
	bool FFocusRotation;
	int FNumRows;
	int FNumCols;
	int FRowHeight;
	bool FSmooth;
	bool FView3D;
	Classes::TNotifyEvent FOnChangeChart;
	Classes::TNotifyEvent FOnSelectedChart;
	Classes::TNotifyEvent FOnSubSelected;
	Forms::TForm* tmpSub;
	bool ISubGallery;
	TGalleryChart* ISelectedChart;
	bool FOldSmooth;
	void __fastcall ChartKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	bool __fastcall ClickedArrow(const Types::TPoint &P);
	TGalleryChart* __fastcall GetChart(int Index);
	void __fastcall SetNumCols(int Value);
	void __fastcall SetNumRows(int Value);
	void __fastcall SetSmooth(bool Value);
	void __fastcall SetView3D(bool Value);
	void __fastcall ShowSubGallery(void);
	void __fastcall SubKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall SubPaintBox(System::TObject* Sender);
	void __fastcall SubPanelClick(System::TObject* Sender);
	void __fastcall SubSelected(System::TObject* Sender);
	bool __fastcall ValidSeries(const Teengine::TTeeSeriesType* ASeriesType, const AnsiString APage);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	
protected:
	TChartGalleryPanel* tmpG;
	Teengine::TChartSeries* tmpSeries;
	Teengine::TTeeSeriesType* tmpType;
	void __fastcall CalcChartWidthHeight(void);
	void __fastcall ChartEvent(System::TObject* Sender);
	void __fastcall ChartOnDblClick(System::TObject* Sender);
	Teengine::TCustomAxisPanel* __fastcall CreateSubChart(const AnsiString ATitle);
	void __fastcall CreateSubGallery(TChartGalleryPanel* AGallery, TMetaClass* AClass);
	void __fastcall GetChartXY(TGalleryChart* AChart, int &x, int &y);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall Resize(void);
	void __fastcall ResizeChart(TGalleryChart* AChart, int TopOffset = 0x0);
	void __fastcall AddSubCharts(TChartGalleryPanel* AGallery);
	void __fastcall FindSelectedChart(void);
	void __fastcall ShowSelectedChart(void);
	
public:
	bool CheckSeries;
	bool FunctionsVisible;
	Teengine::TChartSeries* SelectedSeries;
	__fastcall virtual TChartGalleryPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartGalleryPanel(void);
	virtual void __fastcall SelectChart(TGalleryChart* Chart);
	Teengine::TCustomAxisPanel* __fastcall CreateChart(const Teengine::TTeeSeriesType* AType);
	void __fastcall CreateChartList(TMetaClass* const * ASeriesList, const int ASeriesList_Size);
	void __fastcall CreateGalleryPage(const AnsiString PageName);
	__property int ColWidth = {read=FColWidth, nodefault};
	/*         class method */ static int __fastcall DefaultMode(TMetaClass* vmt);
	/*         class method */ static bool __fastcall DefaultSmooth(TMetaClass* vmt);
	bool __fastcall GetSeriesClass(TMetaClass* &tmpClass, TMetaClass* &tmpFunctionClass, int &SubIndex);
	void __fastcall ResizeCharts(void);
	/*         class method */ static void __fastcall SaveMode(TMetaClass* vmt, int Value);
	/*         class method */ static void __fastcall SaveSmooth(TMetaClass* vmt, bool Value);
	void __fastcall UseTheme(TMetaClass* Theme);
	__property TGalleryChart* Chart[int Index] = {read=GetChart/*, default*/};
	__property TChartList* Charts = {read=FCharts};
	__property int RowHeight = {read=FRowHeight, nodefault};
	__property TGalleryChart* SelectedChart = {read=ISelectedChart, write=SelectChart};
	
__published:
	__property bool DisplaySub = {read=FDisplaySub, write=FDisplaySub, default=1};
	__property bool FocusRotation = {read=FFocusRotation, write=FFocusRotation, default=1};
	__property int NumRows = {read=FNumRows, write=SetNumRows, default=3};
	__property int NumCols = {read=FNumCols, write=SetNumCols, default=4};
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
	__property bool View3D = {read=FView3D, write=SetView3D, default=1};
	__property Classes::TNotifyEvent OnSelectedChart = {read=FOnSelectedChart, write=FOnSelectedChart};
	__property Classes::TNotifyEvent OnChangeChart = {read=FOnChangeChart, write=FOnChangeChart};
	__property Classes::TNotifyEvent OnSubSelected = {read=FOnSubSelected, write=FOnSubSelected};
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
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
	/* TWinControl.CreateParented */ inline __fastcall TChartGalleryPanel(HWND ParentWindow) : Teeprocs::TCustomPanelNoCaption(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeGalleryNumRows = 0x3;
static const Shortint TeeGalleryNumCols = 0x4;
static const short TeeCursorDisabled = 0xfffffff3;
extern PACKAGE Graphics::TColor clTeeGallery;
extern PACKAGE bool TeeGalleryCheckMaximize;

}	/* namespace Teegallerypanel */
using namespace Teegallerypanel;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGalleryPanel
