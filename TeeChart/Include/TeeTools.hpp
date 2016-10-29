// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTools.pas' rev: 6.00

#ifndef TeeToolsHPP
#define TeeToolsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeAntiAlias.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
#include <TeeFilters.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teetools
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TCursorToolStyle { cssHorizontal, cssVertical, cssBoth, cssScope, cssScopeOnly };
#pragma option pop

#pragma option push -b-
enum TCursorClicked { ccNone, ccHorizontal, ccVertical, ccBoth };
#pragma option pop

class DELPHICLASS TCursorTool;
typedef void __fastcall (__closure *TCursorToolChangeEvent)(TCursorTool* Sender, int x, int y, const double XValue, const double YValue, Teengine::TChartSeries* Series, int ValueIndex);

typedef void __fastcall (__closure *TCursorToolGetAxisRect)(TCursorTool* Sender, Types::TRect &Rect);

#pragma option push -b-
enum TSnapStyle { ssDefault, ssHorizontal, ssVertical };
#pragma option pop

#pragma option push -b-
enum TScopeCursorStyle { scsRectangle, scsCircle, scsDiamond, scsEmpty, scsCamera };
#pragma option pop

class PASCALIMPLEMENTATION TCursorTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	int FClick;
	bool FFollowMouse;
	int FHorizSize;
	TCursorToolChangeEvent FOnChange;
	TCursorToolGetAxisRect FOnGetAxisRect;
	TCursorToolChangeEvent FOnSnapChange;
	int FScopeSize;
	TScopeCursorStyle FScopeStyle;
	bool FSnap;
	TSnapStyle FSnapStyle;
	TCursorToolStyle FStyle;
	bool FUseChartRect;
	bool FUseSeriesZ;
	int FVertSize;
	TCursorClicked IDragging;
	int IOldSnap;
	void __fastcall CalcValuePositions(int X, int Y);
	void __fastcall DoChange(void);
	Types::TRect __fastcall GetAxisRect();
	bool __fastcall InMouseRectangle(int x, int y, bool UseSize = false);
	Types::TRect __fastcall MouseRectangle(int X, int Y, bool UseSize);
	void __fastcall SetHorizSize(const int Value);
	void __fastcall SetScopeSize(const int Value);
	void __fastcall SetScopeStyle(const TScopeCursorStyle Value);
	void __fastcall SetStyle(TCursorToolStyle Value);
	void __fastcall SetUseChartRect(const bool Value);
	void __fastcall SetUseSeriesZ(const bool Value);
	void __fastcall SetVertSize(const int Value);
	void __fastcall SetXValue(const double Value);
	void __fastcall SetYValue(const double Value);
	int __fastcall Z(void);
	
protected:
	double IXValue;
	double IYValue;
	#pragma pack(push, 1)
	Types::TPoint IPoint;
	#pragma pack(pop)
	
	void __fastcall CalcScreenPositions(void);
	virtual void __fastcall Changed(int SnapPoint);
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TCursorTool(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TCursorClicked __fastcall Clicked(int x, int y);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	int __fastcall NearestPoint(TCursorToolStyle AStyle, /* out */ double &Difference);
	int __fastcall SnapToPoint(void);
	void __fastcall RedrawCursor(void);
	__property bool UseChartRect = {read=FUseChartRect, write=SetUseChartRect, default=0};
	__property double XValue = {read=IXValue, write=SetXValue};
	__property double YValue = {read=IYValue, write=SetYValue};
	__property TCursorToolGetAxisRect OnGetAxisRect = {read=FOnGetAxisRect, write=FOnGetAxisRect};
	
__published:
	__property Active  = {default=1};
	__property int ClickTolerance = {read=FClick, write=FClick, default=3};
	__property bool FollowMouse = {read=FFollowMouse, write=FFollowMouse, default=0};
	__property int HorizSize = {read=FHorizSize, write=SetHorizSize, default=0};
	__property Pen ;
	__property Series ;
	__property int ScopeSize = {read=FScopeSize, write=SetScopeSize, default=4};
	__property TScopeCursorStyle ScopeStyle = {read=FScopeStyle, write=SetScopeStyle, default=0};
	__property bool Snap = {read=FSnap, write=FSnap, default=0};
	__property TSnapStyle SnapStyle = {read=FSnapStyle, write=FSnapStyle, default=0};
	__property TCursorToolStyle Style = {read=FStyle, write=SetStyle, default=2};
	__property bool UseSeriesZ = {read=FUseSeriesZ, write=SetUseSeriesZ, default=0};
	__property int VertSize = {read=FVertSize, write=SetVertSize, default=0};
	__property TCursorToolChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TCursorToolChangeEvent OnSnapChange = {read=FOnSnapChange, write=FOnSnapChange};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TCursorTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDragMarksTool;
typedef void __fastcall (__closure *TDragMarkEvent)(TDragMarksTool* Sender, int Index, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

class PASCALIMPLEMENTATION TDragMarksTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	TDragMarkEvent FOnDragged;
	TDragMarkEvent FOnDragging;
	int IOldX;
	int IOldY;
	int Index;
	Teengine::TChartSeries* ISeries;
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TDragMarksTool(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Series ;
	__property TDragMarkEvent OnDraggedMark = {read=FOnDragged, write=FOnDragged};
	__property TDragMarkEvent OnDraggingMark = {read=FOnDragging, write=FOnDragging};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TDragMarksTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAxisArrowTool;
typedef void __fastcall (__closure *TAxisArrowClickEvent)(TAxisArrowTool* Sender, bool AtStart);

#pragma option push -b-
enum TAxisArrowToolPosition { aaStart, aaEnd, aaBoth };
#pragma option pop

class PASCALIMPLEMENTATION TAxisArrowTool : public Teengine::TTeeCustomToolAxis 
{
	typedef Teengine::TTeeCustomToolAxis inherited;
	
private:
	int FHeadWidth;
	int FLength;
	TAxisArrowToolPosition FPosition;
	int FScrollPercent;
	bool FScrollInverted;
	int FSizePercent;
	TAxisArrowClickEvent FOnClick;
	int __fastcall ClickedArrow(int x, int y);
	void __fastcall SetHeadWidth(const int Value);
	void __fastcall SetLength(const int Value);
	void __fastcall SetPosition(const TAxisArrowToolPosition Value);
	void __fastcall SetSizePercent(const int Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TAxisArrowTool(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property TAxisArrowToolPosition Position = {read=FPosition, write=SetPosition, default=2};
	__property Axis ;
	__property Brush ;
	__property int HeadWidth = {read=FHeadWidth, write=SetHeadWidth, default=8};
	__property int Length = {read=FLength, write=SetLength, default=16};
	__property Pen ;
	__property bool ScrollInverted = {read=FScrollInverted, write=FScrollInverted, default=0};
	__property int ScrollPercent = {read=FScrollPercent, write=FScrollPercent, default=10};
	__property int SizePercent = {read=FSizePercent, write=SetSizePercent, default=50};
	__property TAxisArrowClickEvent OnClick = {read=FOnClick, write=FOnClick};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TAxisArrowTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAxisScrollTool;
class PASCALIMPLEMENTATION TAxisScrollTool : public Teengine::TTeeCustomToolAxis 
{
	typedef Teengine::TTeeCustomToolAxis inherited;
	
private:
	bool FScrollInverted;
	int OldX;
	int OldY;
	Teengine::TChartAxis* InAxis;
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Axis ;
	__property bool ScrollInverted = {read=FScrollInverted, write=FScrollInverted, default=0};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TAxisScrollTool(Classes::TComponent* AOwner) : Teengine::TTeeCustomToolAxis(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TAxisScrollTool(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDrawLineHandle { chNone, chStart, chEnd, chSeries };
#pragma option pop

#pragma option push -b-
enum TDrawLineStyle { dlLine, dlHorizParallel, dlVertParallel, dlRectangle, dlEllipse };
#pragma option pop

class DELPHICLASS TDrawLine;
class DELPHICLASS TDrawLineTool;
class PASCALIMPLEMENTATION TDrawLine : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Tecanvas::TChartPen* FPen;
	TDrawLineStyle FStyle;
	TDrawLineTool* __fastcall GetParent(void);
	Tecanvas::TChartPen* __fastcall GetPen(void);
	double __fastcall GetX0(void);
	double __fastcall GetX1(void);
	double __fastcall GetY0(void);
	double __fastcall GetY1(void);
	bool __fastcall IsPenStored(void);
	void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetStyle(TDrawLineStyle Value);
	void __fastcall SetX0(const double Value);
	void __fastcall SetX1(const double Value);
	void __fastcall SetY0(const double Value);
	void __fastcall SetY1(const double Value);
	
public:
	#pragma pack(push, 1)
	Tecanvas::TFloatPoint EndPos;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Tecanvas::TFloatPoint StartPos;
	#pragma pack(pop)
	
	__fastcall TDrawLine(Classes::TCollection* Collection, const double X0, const double Y0, const double X1, const double Y1);
	__fastcall virtual ~TDrawLine(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall Clicked(int X, int Y, TDrawLineHandle AHandle, int PixelsTolerance = 0x0);
	void __fastcall DrawHandles(void);
	Types::TRect __fastcall EndHandle();
	Types::TRect __fastcall StartHandle();
	__property TDrawLineTool* Parent = {read=GetParent};
	
__published:
	__property Tecanvas::TChartPen* Pen = {read=GetPen, write=SetPen, stored=IsPenStored};
	__property TDrawLineStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property double X0 = {read=GetX0, write=SetX0};
	__property double Y0 = {read=GetY0, write=SetY0};
	__property double X1 = {read=GetX1, write=SetX1};
	__property double Y1 = {read=GetY1, write=SetY1};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TDrawLine(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	
};


class DELPHICLASS TDrawLines;
class PASCALIMPLEMENTATION TDrawLines : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TDrawLine* operator[](int Index) { return Line[Index]; }
	
private:
	TDrawLine* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TDrawLine* Value);
	
public:
	TDrawLine* __fastcall AddLine(const double X0, const double Y0, const double X1, const double Y1);
	TDrawLine* __fastcall Last(void);
	__property TDrawLine* Line[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TDrawLines(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDrawLines(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TDrawLineSelecting)(TDrawLineTool* Sender, TDrawLine* Line, bool &AllowSelect);

class PASCALIMPLEMENTATION TDrawLineTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Controls::TMouseButton FButton;
	int FClick;
	bool FEnableDraw;
	bool FEnableSelect;
	TDrawLines* FLines;
	bool FSelectNew;
	TDrawLineStyle FStyle;
	Classes::TNotifyEvent FOnDraggedLine;
	Classes::TNotifyEvent FOnDragLine;
	Classes::TNotifyEvent FOnNewLine;
	Classes::TNotifyEvent FOnSelect;
	TDrawLineSelecting FOnSelecting;
	bool IDrawing;
	bool IMoved;
	#pragma pack(push, 1)
	Types::TPoint IPoint;
	#pragma pack(pop)
	
	TDrawLine* ISelected;
	void __fastcall DrawLine(const Types::TPoint &StartPos, const Types::TPoint &EndPos, TDrawLineStyle AStyle);
	TDrawLine* __fastcall InternalClicked(int X, int Y, TDrawLineHandle AHandle, int ClickTolerance)/* overload */;
	TDrawLine* __fastcall InternalClicked(int X, int Y, TDrawLineHandle AHandle)/* overload */;
	void __fastcall RedrawLine(TDrawLine* ALine);
	void __fastcall SetEnableSelect(bool Value);
	void __fastcall SetLines(const TDrawLines* Value);
	void __fastcall SetSelected(TDrawLine* Value);
	
protected:
	TDrawLineHandle IHandle;
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton AButton, Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall ClipDrawingRegion(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	#pragma pack(push, 1)
	Types::TPoint FromPoint;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint ToPoint;
	#pragma pack(pop)
	
	__fastcall virtual TDrawLineTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TDrawLineTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Types::TPoint __fastcall AxisPoint(const Tecanvas::TFloatPoint &P);
	TDrawLine* __fastcall Clicked(int X, int Y)/* overload */;
	TDrawLine* __fastcall Clicked(int X, int Y, int ClickTolerance)/* overload */;
	void __fastcall DeleteSelected(void);
	Tecanvas::TFloatPoint __fastcall ScreenPoint(const Types::TPoint &P);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property TDrawLine* Selected = {read=ISelected, write=SetSelected};
	
__published:
	__property Active  = {default=1};
	__property Controls::TMouseButton Button = {read=FButton, write=FButton, default=0};
	__property int ClickTolerance = {read=FClick, write=FClick, default=0};
	__property bool EnableDraw = {read=FEnableDraw, write=FEnableDraw, default=1};
	__property bool EnableSelect = {read=FEnableSelect, write=SetEnableSelect, default=1};
	__property TDrawLines* Lines = {read=FLines, write=SetLines};
	__property bool SelectNewLines = {read=FSelectNew, write=FSelectNew, default=1};
	__property Pen ;
	__property Series ;
	__property TDrawLineStyle Style = {read=FStyle, write=FStyle, default=0};
	__property Classes::TNotifyEvent OnDraggedLine = {read=FOnDraggedLine, write=FOnDraggedLine};
	__property Classes::TNotifyEvent OnDragLine = {read=FOnDragLine, write=FOnDragLine};
	__property Classes::TNotifyEvent OnNewLine = {read=FOnNewLine, write=FOnNewLine};
	__property Classes::TNotifyEvent OnSelect = {read=FOnSelect, write=FOnSelect};
	__property TDrawLineSelecting OnSelecting = {read=FOnSelecting, write=FOnSelecting};
};


typedef TMetaClass*TDrawLineClass;

#pragma option push -b-
enum TMarkToolMouseAction { mtmMove, mtmClick };
#pragma option pop

class DELPHICLASS TMarksTipTool;
typedef void __fastcall (__closure *TMarksTipGetText)(TMarksTipTool* Sender, AnsiString &Text);

class PASCALIMPLEMENTATION TMarksTipTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	TMarkToolMouseAction FMouseAction;
	Classes::TNotifyEvent FOnCancel;
	TMarksTipGetText FOnGetText;
	Teengine::TSeriesMarksStyle FStyle;
	void __fastcall DoCancelHint(void);
	int __fastcall GetHideDelay(void);
	int __fastcall GetMouseDelay(void);
	void __fastcall SetHideDelay(const int Value);
	void __fastcall SetMouseAction(TMarkToolMouseAction Value);
	void __fastcall SetMouseDelay(const int Value);
	
protected:
	Chart::TCustomChart* __fastcall Chart(void);
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetActive(bool Value);
	
public:
	__fastcall virtual TMarksTipTool(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property int HideDelay = {read=GetHideDelay, write=SetHideDelay, default=2500};
	__property TMarkToolMouseAction MouseAction = {read=FMouseAction, write=SetMouseAction, default=0};
	__property int MouseDelay = {read=GetMouseDelay, write=SetMouseDelay, default=500};
	__property Series ;
	__property Teengine::TSeriesMarksStyle Style = {read=FStyle, write=FStyle, default=2};
	__property Classes::TNotifyEvent OnCancelHint = {read=FOnCancel, write=FOnCancel};
	__property TMarksTipGetText OnGetText = {read=FOnGetText, write=FOnGetText};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TMarksTipTool(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TNearestToolStyle { hsNone, hsCircle, hsRectangle, hsDiamond, hsSeries };
#pragma option pop

class DELPHICLASS TNearestTool;
class PASCALIMPLEMENTATION TNearestTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	bool FFullRepaint;
	Tecanvas::TChartPen* FLinePen;
	int FSize;
	TNearestToolStyle FStyle;
	Classes::TNotifyEvent FOnChange;
	#pragma pack(push, 1)
	Types::TPoint IMouse;
	#pragma pack(pop)
	
	bool __fastcall GetDrawLine(void);
	void __fastcall PaintHint(void);
	void __fastcall SetDrawLine(const bool Value);
	void __fastcall SetLinePen(const Tecanvas::TChartPen* Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetStyle(const TNearestToolStyle Value);
	int __fastcall ZAxisCalc(const double Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	int Point;
	__fastcall virtual TNearestTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TNearestTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/*         class method */ static int __fastcall GetNearestPoint(TMetaClass* vmt, Teengine::TChartSeries* Series, int X, int Y)/* overload */;
	/*         class method */ static int __fastcall GetNearestPoint(TMetaClass* vmt, Teengine::TChartSeries* Series, int X, int Y, bool IncludeNulls)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Brush ;
	__property bool DrawLine = {read=GetDrawLine, write=SetDrawLine, default=1};
	__property bool FullRepaint = {read=FFullRepaint, write=FFullRepaint, default=1};
	__property Tecanvas::TChartPen* LinePen = {read=FLinePen, write=SetLinePen};
	__property Pen ;
	__property Series ;
	__property int Size = {read=FSize, write=SetSize, default=20};
	__property TNearestToolStyle Style = {read=FStyle, write=SetStyle, default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TColorBandTool;
class DELPHICLASS TColorLineTool;
typedef void __fastcall (__closure *TColorLineToolOnDrag)(TColorLineTool* Sender);

#pragma option push -b-
enum TColorLineStyle { clCustom, clMaximum, clCenter, clMinimum };
#pragma option pop

class PASCALIMPLEMENTATION TColorLineTool : public Teengine::TTeeCustomToolAxis 
{
	typedef Teengine::TTeeCustomToolAxis inherited;
	
private:
	bool FAllowDrag;
	bool FDragRepaint;
	bool FDraw3D;
	bool FDrawBehind;
	bool FNoLimitDrag;
	TColorLineToolOnDrag FOnBeginDragLine;
	TColorLineToolOnDrag FOnDragLine;
	TColorLineToolOnDrag FOnEndDragLine;
	TColorLineStyle FStyle;
	double FValue;
	bool IDragging;
	Teengine::TCustomAxisPanel* IParent;
	TColorLineToolOnDrag InternalOnEndDragLine;
	Teengine::TCustomAxisPanel* __fastcall Chart(void);
	void __fastcall DrawColorLine(bool Back);
	void __fastcall SetDraw3D(const bool Value);
	void __fastcall SetDrawBehind(const bool Value);
	void __fastcall SetStyle(const TColorLineStyle Value);
	void __fastcall SetValue(const double AValue);
	
protected:
	double __fastcall CalcValue(void);
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoEndDragLine(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	void __fastcall InternalDrawLine(bool Back);
	virtual void __fastcall SetParent(Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TColorLineTool(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall Clicked(int x, int y);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	double __fastcall LimitValue(const double AValue);
	
__published:
	__property Active  = {default=1};
	__property Axis ;
	__property bool AllowDrag = {read=FAllowDrag, write=FAllowDrag, default=1};
	__property bool DragRepaint = {read=FDragRepaint, write=FDragRepaint, default=0};
	__property bool Draw3D = {read=FDraw3D, write=SetDraw3D, default=1};
	__property bool DrawBehind = {read=FDrawBehind, write=SetDrawBehind, default=0};
	__property bool NoLimitDrag = {read=FNoLimitDrag, write=FNoLimitDrag, default=0};
	__property Pen ;
	__property TColorLineStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property double Value = {read=FValue, write=SetValue};
	__property TColorLineToolOnDrag OnBeginDragLine = {read=FOnBeginDragLine, write=FOnBeginDragLine};
	__property TColorLineToolOnDrag OnDragLine = {read=FOnDragLine, write=FOnDragLine};
	__property TColorLineToolOnDrag OnEndDragLine = {read=FOnEndDragLine, write=FOnEndDragLine};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TColorLineTool(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TColorBandTool : public Teengine::TTeeCustomToolAxis 
{
	typedef Teengine::TTeeCustomToolAxis inherited;
	
private:
	Graphics::TColor FColor;
	Controls::TCursor FCursor;
	bool FDrawBehind;
	bool FDrawBehindAxes;
	double FEnd;
	Tecanvas::TTeeGradient* FGradient;
	Controls::TMouseEvent FOnClick;
	Classes::TNotifyEvent FOnResized;
	Tecanvas::TTeePicture* FPicture;
	double FStart;
	Tecanvas::TTeeTransparency FTransparency;
	TColorLineTool* FLineEnd;
	TColorLineTool* FLineStart;
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall DragLine(TColorLineTool* Sender);
	void __fastcall EndDragLine(TColorLineTool* Sender);
	Tecanvas::TChartPen* __fastcall GetEndLinePen(void);
	Tecanvas::TTeePicture* __fastcall GetPicture(void);
	bool __fastcall GetResizeEnd(void);
	bool __fastcall GetResizeStart(void);
	Tecanvas::TChartPen* __fastcall GetStartLinePen(void);
	TColorLineTool* __fastcall NewColorLine(void);
	void __fastcall PaintBand(void);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetDrawBehind(const bool Value);
	void __fastcall SetDrawBehindAxes(const bool Value);
	void __fastcall SetEnd(const double Value);
	void __fastcall SetEndLinePen(const Tecanvas::TChartPen* Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetLines(void);
	void __fastcall SetPicture(const Tecanvas::TTeePicture* Value);
	void __fastcall SetResizeEnd(const bool Value);
	void __fastcall SetResizeStart(const bool Value);
	void __fastcall SetStart(const double Value);
	void __fastcall SetStartLinePen(const Tecanvas::TChartPen* Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetAxis(const Teengine::TChartAxis* Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	int __fastcall ZPosition(void);
	
public:
	__fastcall virtual TColorBandTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TColorBandTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Types::TRect __fastcall BoundsRect();
	bool __fastcall Clicked(int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property TColorLineTool* StartLine = {read=FLineStart};
	__property TColorLineTool* EndLine = {read=FLineEnd};
	
__published:
	__property Active  = {default=1};
	__property Axis ;
	__property Brush ;
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property Controls::TCursor Cursor = {read=FCursor, write=FCursor, default=0};
	__property bool DrawBehind = {read=FDrawBehind, write=SetDrawBehind, default=1};
	__property bool DrawBehindAxes = {read=FDrawBehindAxes, write=SetDrawBehindAxes, default=0};
	__property Tecanvas::TChartPen* EndLinePen = {read=GetEndLinePen, write=SetEndLinePen};
	__property double EndValue = {read=FEnd, write=SetEnd};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Pen ;
	__property Tecanvas::TTeePicture* Picture = {read=GetPicture, write=SetPicture};
	__property bool ResizeEnd = {read=GetResizeEnd, write=SetResizeEnd, default=0};
	__property bool ResizeStart = {read=GetResizeStart, write=SetResizeStart, default=0};
	__property Tecanvas::TChartPen* StartLinePen = {read=GetStartLinePen, write=SetStartLinePen};
	__property double StartValue = {read=FStart, write=SetStart};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property Controls::TMouseEvent OnClick = {read=FOnClick, write=FOnClick};
	__property Classes::TNotifyEvent OnResized = {read=FOnResized, write=FOnResized};
};


class DELPHICLASS TGridBandBrush;
class PASCALIMPLEMENTATION TGridBandBrush : public Tecanvas::TChartBrush 
{
	typedef Tecanvas::TChartBrush inherited;
	
private:
	Tecanvas::TTeeGradient* FGradient;
	Tecanvas::TTeeTransparency FTransp;
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetTransp(const Tecanvas::TTeeTransparency Value);
	
public:
	__fastcall virtual TGridBandBrush(Classes::TNotifyEvent OnChangeEvent);
	__fastcall virtual ~TGridBandBrush(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property BackColor  = {default=536870911};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransp, write=SetTransp, default=0};
};


class DELPHICLASS TGridBandTool;
class PASCALIMPLEMENTATION TGridBandTool : public Teengine::TTeeCustomToolAxis 
{
	typedef Teengine::TTeeCustomToolAxis inherited;
	
private:
	TGridBandBrush* FBand1;
	TGridBandBrush* FBand2;
	void __fastcall DrawGrids(Teengine::TChartAxis* Sender);
	void __fastcall SetBand1(TGridBandBrush* Value);
	void __fastcall SetBand2(TGridBandBrush* Value);
	
protected:
	int StartPos;
	int EndPos;
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetAxis(const Teengine::TChartAxis* Value);
	
public:
	__fastcall virtual TGridBandTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TGridBandTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Graphics::TColor __fastcall BandBackColor(TGridBandBrush* ABand);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Axis ;
	__property TGridBandBrush* Band1 = {read=FBand1, write=SetBand1};
	__property TGridBandBrush* Band2 = {read=FBand2, write=SetBand2};
};


#pragma option push -b-
enum TRotateToolStyles { rsAll, rsRotation, rsElevation };
#pragma option pop

class DELPHICLASS TRotateTool;
class PASCALIMPLEMENTATION TRotateTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	Controls::TMouseButton FButton;
	Controls::TCursor FCursor;
	int FInertia;
	bool FInverted;
	Classes::TNotifyEvent FOnRotate;
	int FSpeed;
	TRotateToolStyles FStyle;
	bool IDragging;
	bool IFirstTime;
	bool IOldRepaint;
	int IOldX;
	int IOldY;
	Extctrls::TTimer* ITimer;
	double IDifX;
	double IDifY;
	Controls::TCursor IOldCursor;
	void __fastcall DoTimer(System::TObject* Sender);
	void __fastcall DoRotation(const double IDifX, const double IDifY);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton AButton, Classes::TShiftState AShift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TRotateTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TRotateTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	/*         class method */ static double __fastcall ElevationChange(TMetaClass* vmt, bool FullRotation, const double AAngle, const double AChange);
	void __fastcall Rotate(const double RotationDegrees, const double ElevationDegrees);
	/*         class method */ static double __fastcall RotationChange(TMetaClass* vmt, bool FullRotation, const double AAngle, const double AChange);
	
__published:
	__property Active  = {default=1};
	__property Controls::TMouseButton Button = {read=FButton, write=FButton, default=0};
	__property Controls::TCursor Cursor = {read=FCursor, write=FCursor, default=2020};
	__property int Inertia = {read=FInertia, write=FInertia, default=0};
	__property bool Inverted = {read=FInverted, write=FInverted, default=0};
	__property Pen ;
	__property int Speed = {read=FSpeed, write=FSpeed, default=50};
	__property TRotateToolStyles Style = {read=FStyle, write=FStyle, default=0};
	__property Classes::TNotifyEvent OnRotate = {read=FOnRotate, write=FOnRotate};
};


class DELPHICLASS TChartImageTool;
class PASCALIMPLEMENTATION TChartImageTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Tecanvas::TTeePicture* FPicture;
	void __fastcall SetPicture(const Tecanvas::TTeePicture* Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TChartImageTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartImageTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Pen ;
	__property Tecanvas::TTeePicture* Picture = {read=FPicture, write=SetPicture};
	__property Series ;
};


class DELPHICLASS TTeeShapePosition;
class PASCALIMPLEMENTATION TTeeShapePosition : public Chart::TTeeCustomShapePosition 
{
	typedef Chart::TTeeCustomShapePosition inherited;
	
__published:
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Brush ;
	__property Color  = {default=16777215};
	__property CustomPosition ;
	__property Font ;
	__property Frame ;
	__property Gradient ;
	__property Left ;
	__property Picture ;
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property Top ;
	__property Transparency  = {default=0};
	__property Transparent ;
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TTeeShapePosition(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : Chart::TTeeCustomShapePosition(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TTeeShapePosition(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TAnnotationPosition { ppLeftTop, ppLeftBottom, ppRightTop, ppRightBottom, ppCenter };
#pragma option pop

class DELPHICLASS TAnnotationTool;
typedef void __fastcall (__closure *TAnnotationClick)(TAnnotationTool* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

class DELPHICLASS TAnnotationCallout;
class PASCALIMPLEMENTATION TAnnotationCallout : public Teengine::TCallout 
{
	typedef Teengine::TCallout inherited;
	
private:
	int FX;
	int FY;
	int FZ;
	Types::TPoint __fastcall CloserPoint(const Types::TRect &R, const Types::TPoint &P);
	void __fastcall SetX(const int Value);
	void __fastcall SetY(const int Value);
	void __fastcall SetZ(const int Value);
	
public:
	__fastcall TAnnotationCallout(Teengine::TChartSeries* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Visible  = {default=0};
	__property int XPosition = {read=FX, write=SetX, default=0};
	__property int YPosition = {read=FY, write=SetY, default=0};
	__property int ZPosition = {read=FZ, write=SetZ, default=0};
public:
	#pragma option push -w-inl
	/* TCallout.Destroy */ inline __fastcall virtual ~TAnnotationCallout(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTextShape;
class PASCALIMPLEMENTATION TTextShape : public TTeeShapePosition 
{
	typedef TTeeShapePosition inherited;
	
private:
	bool FAutoSize;
	bool FClipText;
	Controls::TCursor FCursor;
	Teengine::TMargins* FMargins;
	Classes::TAlignment FTextAlign;
	void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetClipText(const bool Value);
	void __fastcall SetMargins(const Teengine::TMargins* Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetTextAlign(const Classes::TAlignment Value);
	
protected:
	AnsiString FText;
	int INumLines;
	void __fastcall CalcBounds(Teengine::TCustomAxisPanel* Panel);
	
public:
	__fastcall virtual TTextShape(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	__fastcall virtual ~TTextShape(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall DrawText(Teengine::TCustomAxisPanel* Panel, const Types::TRect &R, int XOffset, int NumLines);
	
__published:
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property bool ClipText = {read=FClipText, write=SetClipText, default=1};
	__property Controls::TCursor Cursor = {read=FCursor, write=FCursor, default=0};
	__property Teengine::TMargins* Margins = {read=FMargins, write=SetMargins};
	__property AnsiString Text = {read=FText, write=SetText};
	__property Classes::TAlignment TextAlignment = {read=FTextAlign, write=SetTextAlign, default=0};
};


class PASCALIMPLEMENTATION TAnnotationTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	TAnnotationCallout* FCallout;
	Classes::TNotifyEvent FOnAfterDraw;
	Classes::TNotifyEvent FOnBeforeDraw;
	TAnnotationClick FOnClick;
	TAnnotationClick FOnDblClick;
	TAnnotationPosition FPosition;
	Teeprocs::TTeeUnits FPositionUnits;
	TTextShape* FShape;
	bool __fastcall GetAutoSize(void);
	Types::TRect __fastcall GetBounds();
	bool __fastcall GetClipText(void);
	Controls::TCursor __fastcall GetCursor(void);
	int __fastcall GetHeight(void);
	int __fastcall GetLeft(void);
	Classes::TAlignment __fastcall GetTextAlign(void);
	int __fastcall GetTop(void);
	int __fastcall GetWidth(void);
	bool __fastcall IsNotAutoSize(void);
	HIDESBASE void __fastcall Repaint(void);
	void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetBounds(const Types::TRect &Value);
	void __fastcall SetCallout(const TAnnotationCallout* Value);
	void __fastcall SetClipText(const bool Value);
	void __fastcall SetCursor(const Controls::TCursor Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetPosition(const TAnnotationPosition Value);
	void __fastcall SetPositionUnits(const Teeprocs::TTeeUnits Value);
	void __fastcall SetShape(const TTextShape* Value);
	void __fastcall SetTextAlign(const Classes::TAlignment Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	virtual int __fastcall GetXOffset(void);
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DrawText(void)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual AnsiString __fastcall GetText();
	virtual Types::TRect __fastcall GetTextBounds(/* out */ int &NumLines, /* out */ int &x, /* out */ int &y)/* overload */;
	Types::TRect __fastcall GetTextBounds(Teengine::TCustomAxisPanel* Panel, /* out */ int &NumLines, /* out */ int &x, /* out */ int &y)/* overload */;
	Types::TRect __fastcall GetTextBounds(Teengine::TCustomAxisPanel* Panel, const Types::TRect &ABounds, /* out */ int &NumLines, /* out */ int &x, /* out */ int &y)/* overload */;
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	void __fastcall SetText(const AnsiString Value);
	
public:
	__fastcall virtual TAnnotationTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TAnnotationTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall Clicked(int x, int y);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property Types::TRect Bounds = {read=GetBounds, write=SetBounds};
	
__published:
	__property Active  = {default=1};
	__property bool AutoSize = {read=GetAutoSize, write=SetAutoSize, default=1};
	__property TAnnotationCallout* Callout = {read=FCallout, write=SetCallout};
	__property bool ClipText = {read=GetClipText, write=SetClipText, default=1};
	__property Controls::TCursor Cursor = {read=GetCursor, write=SetCursor, default=0};
	__property TAnnotationPosition Position = {read=FPosition, write=SetPosition, default=0};
	__property Teeprocs::TTeeUnits PositionUnits = {read=FPositionUnits, write=SetPositionUnits, default=1};
	__property TTextShape* Shape = {read=FShape, write=SetShape};
	__property AnsiString Text = {read=GetText, write=SetText};
	__property Classes::TAlignment TextAlignment = {read=GetTextAlign, write=SetTextAlign, default=0};
	__property int Height = {read=GetHeight, write=SetHeight, stored=IsNotAutoSize, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, stored=false, nodefault};
	__property int Top = {read=GetTop, write=SetTop, stored=false, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsNotAutoSize, nodefault};
	__property Classes::TNotifyEvent OnAfterDraw = {read=FOnAfterDraw, write=FOnAfterDraw};
	__property Classes::TNotifyEvent OnBeforeDraw = {read=FOnBeforeDraw, write=FOnBeforeDraw};
	__property TAnnotationClick OnClick = {read=FOnClick, write=FOnClick};
	__property TAnnotationClick OnDblClick = {read=FOnDblClick, write=FOnDblClick};
};


class DELPHICLASS TSeriesAnimationTool;
typedef void __fastcall (__closure *TSeriesAnimationStep)(TSeriesAnimationTool* Sender, int Step);

#pragma option push -b-
enum TSeriesAnimationLoop { salNo, salOneWay, salCircular };
#pragma option pop

class PASCALIMPLEMENTATION TSeriesAnimationTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Teengine::TChartSeries* FBackup;
	int FDelay;
	int FDrawEvery;
	TSeriesAnimationLoop FLoop;
	double FStartValue;
	int FSteps;
	bool FStartAtMin;
	Classes::TNotifyEvent FOnStart;
	TSeriesAnimationStep FOnStep;
	Classes::TNotifyEvent FOnStop;
	bool IStopped;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TSeriesAnimationTool(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	virtual void __fastcall Execute(void)/* overload */;
	void __fastcall Execute(System::TObject* Sender)/* overload */;
	bool __fastcall Running(void);
	void __fastcall Stop(void);
	
__published:
	__property Active  = {default=1};
	__property int Delay = {read=FDelay, write=FDelay, default=0};
	__property int DrawEvery = {read=FDrawEvery, write=FDrawEvery, default=0};
	__property TSeriesAnimationLoop Loop = {read=FLoop, write=FLoop, default=0};
	__property Series ;
	__property bool StartAtMin = {read=FStartAtMin, write=FStartAtMin, default=1};
	__property double StartValue = {read=FStartValue, write=FStartValue};
	__property int Steps = {read=FSteps, write=FSteps, default=100};
	__property Classes::TNotifyEvent OnStart = {read=FOnStart, write=FOnStart};
	__property TSeriesAnimationStep OnStep = {read=FOnStep, write=FOnStep};
	__property Classes::TNotifyEvent OnStop = {read=FOnStop, write=FOnStop};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TSeriesAnimationTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRectangleTool;
class PASCALIMPLEMENTATION TRectangleTool : public TAnnotationTool 
{
	typedef TAnnotationTool inherited;
	
private:
	bool FAllowDrag;
	bool FAllowResize;
	Classes::TNotifyEvent FOnDragged;
	Classes::TNotifyEvent FOnDragging;
	Classes::TNotifyEvent FOnResized;
	Classes::TNotifyEvent FOnResizing;
	#pragma pack(push, 1)
	Types::TPoint P;
	#pragma pack(pop)
	
	bool IDrag;
	int IEdge;
	bool __fastcall GetResizing(void);
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual TRectangleTool(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Graphics::TBitmap* __fastcall Bitmap(bool ChartOnly = false);
	int __fastcall ClickedEdge(int x, int y);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	__property bool Dragging = {read=IDrag, nodefault};
	__property bool Resizing = {read=GetResizing, nodefault};
	
__published:
	__property bool AllowDrag = {read=FAllowDrag, write=FAllowDrag, default=1};
	__property bool AllowResize = {read=FAllowResize, write=FAllowResize, default=1};
	__property AutoSize  = {default=0};
	__property Cursor  = {default=-21};
	__property PositionUnits  = {default=1};
	__property Classes::TNotifyEvent OnDragged = {read=FOnDragged, write=FOnDragged};
	__property Classes::TNotifyEvent OnDragging = {read=FOnDragging, write=FOnDragging};
	__property Classes::TNotifyEvent OnResized = {read=FOnResized, write=FOnResized};
	__property Classes::TNotifyEvent OnResizing = {read=FOnResizing, write=FOnResizing};
public:
	#pragma option push -w-inl
	/* TAnnotationTool.Destroy */ inline __fastcall virtual ~TRectangleTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClipSeriesTool;
class PASCALIMPLEMENTATION TClipSeriesTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
protected:
	virtual void __fastcall SeriesEvent(Teengine::TChartToolEvent AEvent);
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Series ;
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TClipSeriesTool(Classes::TComponent* AOwner) : Teengine::TTeeCustomToolSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TClipSeriesTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFullScreenTool;
class PASCALIMPLEMENTATION TFullScreenTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	Word FKey;
	Controls::TAlign OldAlign;
	Controls::TWinControl* OldParent;
	#pragma pack(push, 1)
	Types::TRect OldRChart;
	#pragma pack(pop)
	
	bool IFreeForm;
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall FormKeyUp(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall RemoveFullScreen(void);
	
protected:
	virtual void __fastcall SetActive(bool Value);
	
public:
	__fastcall virtual TFullScreenTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TFullScreenTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=0};
	__property Word ReleaseKey = {read=FKey, write=FKey, default=27};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeClickTolerance = 0x3;
extern PACKAGE TMetaClass*TeeDrawLineClass;

}	/* namespace Teetools */
using namespace Teetools;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTools
