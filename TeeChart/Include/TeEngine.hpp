// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeEngine.pas' rev: 6.00

#ifndef TeEngineHPP
#define TeEngineHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teengine
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomChartElement;
class DELPHICLASS TCustomAxisPanel;
class DELPHICLASS TChartAxes;
class DELPHICLASS TChartAxis;
class DELPHICLASS TChartDepthAxis;
typedef int __fastcall (__closure *TAxisCalcPosLabels)(TChartAxis* Axis, int Value);

class PASCALIMPLEMENTATION TChartAxes : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TChartAxis* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomAxisPanel* FChart;
	bool IFastCalc;
	HIDESBASE TChartAxis* __fastcall Get(int Index);
	TChartAxis* __fastcall GetBottomAxis(void);
	TChartDepthAxis* __fastcall GetDepthAxis(void);
	TChartDepthAxis* __fastcall GetDepthTopAxis(void);
	TChartAxis* __fastcall GetLeftAxis(void);
	TChartAxis* __fastcall GetRightAxis(void);
	TChartAxis* __fastcall GetTopAxis(void);
	void __fastcall SetFastCalc(const bool Value);
	bool __fastcall GetBehind(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetBehind(const bool Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	TAxisCalcPosLabels CalcPosLabels;
	
public:
	virtual void __fastcall Clear(void);
	void __fastcall Hide(void);
	void __fastcall Reset(void);
	__property TChartAxis* Items[int Index] = {read=Get/*, default*/};
	__property TChartAxis* Bottom = {read=GetBottomAxis};
	__property TChartDepthAxis* Depth = {read=GetDepthAxis};
	__property TChartDepthAxis* DepthTop = {read=GetDepthTopAxis};
	__property TChartAxis* Left = {read=GetLeftAxis};
	__property TChartAxis* Right = {read=GetRightAxis};
	__property TChartAxis* Top = {read=GetTopAxis};
	__property bool Behind = {read=GetBehind, write=SetBehind, nodefault};
	__property bool FastCalc = {read=IFastCalc, write=SetFastCalc, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TChartAxes(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartAxes(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TChartCustomAxes;
class PASCALIMPLEMENTATION TChartCustomAxes : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TChartAxis* operator[](int Index) { return Items[Index]; }
	
private:
	TChartAxis* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TChartAxis* Value);
	
public:
	void __fastcall ResetScales(TChartAxis* Axis);
	__property TChartAxis* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TChartCustomAxes(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TChartCustomAxes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartSeriesList;
class DELPHICLASS TCustomSeriesList;
class DELPHICLASS TChartSeries;
class PASCALIMPLEMENTATION TCustomSeriesList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TChartSeries* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomAxisPanel* FOwner;
	HIDESBASE TChartSeries* __fastcall Get(int Index);
	HIDESBASE void __fastcall Put(int Index, TChartSeries* Value);
	
public:
	void __fastcall ClearValues(void);
	void __fastcall FillSampleValues(int Num = 0x0);
	HIDESBASE TChartSeries* __fastcall First(void);
	HIDESBASE TChartSeries* __fastcall Last(void);
	__property TChartSeries* Items[int Index] = {read=Get, write=Put/*, default*/};
	__property TCustomAxisPanel* Owner = {read=FOwner};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TCustomSeriesList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCustomSeriesList(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesGroups;
class DELPHICLASS TSeriesGroup;
class PASCALIMPLEMENTATION TSeriesGroups : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TSeriesGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TSeriesGroup* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TSeriesGroup* Value);
	
public:
	int __fastcall Contains(TChartSeries* Series);
	TSeriesGroup* __fastcall FindByName(const AnsiString Name, bool CaseSensitive = false);
	__property TSeriesGroup* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TSeriesGroups(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TSeriesGroups(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TChartSeriesList : public TCustomSeriesList 
{
	typedef TCustomSeriesList inherited;
	
private:
	TSeriesGroups* FGroups;
	bool __fastcall GetAllActive(void);
	void __fastcall SetAllActive(const bool Value);
	void __fastcall SetGroups(const TSeriesGroups* Value);
	
public:
	__fastcall virtual ~TChartSeriesList(void);
	TSeriesGroup* __fastcall AddGroup(const AnsiString Name);
	HIDESBASE void __fastcall Assign(TChartSeriesList* Source);
	__property bool AllActive = {read=GetAllActive, write=SetAllActive, nodefault};
	__property TSeriesGroups* Groups = {read=FGroups, write=SetGroups};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartSeriesList(void) : TCustomSeriesList() { }
	#pragma option pop
	
};


class DELPHICLASS TCustomChartSeries;
typedef void __fastcall (__closure *TSeriesNotifyEvent)(TCustomChartSeries* Sender);

typedef void __fastcall (__closure *TAxisOnGetLabel)(TChartAxis* Sender, TChartSeries* Series, int ValueIndex, AnsiString &LabelText);

typedef void __fastcall (__closure *TAxisOnGetNextLabel)(TChartAxis* Sender, int LabelIndex, double &LabelValue, bool &Stop);

class DELPHICLASS TChartPage;
class PASCALIMPLEMENTATION TChartPage : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FAutoScale;
	int FCurrent;
	int FPointsPerPage;
	bool FScaleLastPage;
	TCustomAxisPanel* IParent;
	void __fastcall SetAutoScale(const bool Value);
	void __fastcall SetCurrent(int Value);
	void __fastcall SetPointsPerPage(const int Value);
	void __fastcall SetScaleLastPage(const bool Value);
	
public:
	__fastcall TChartPage(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall Count(void);
	int __fastcall FirstValueIndex(void);
	void __fastcall NextPage(void);
	void __fastcall PreviousPage(void);
	__property TCustomAxisPanel* Parent = {read=IParent};
	
__published:
	__property bool AutoScale = {read=FAutoScale, write=SetAutoScale, default=0};
	__property int Current = {read=FCurrent, write=SetCurrent, default=1};
	__property int MaxPointsPerPage = {read=FPointsPerPage, write=SetPointsPerPage, default=0};
	__property bool ScaleLastPage = {read=FScaleLastPage, write=SetScaleLastPage, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TChartPage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartTools;
class DELPHICLASS TTeeCustomTool;
typedef TMetaClass*TTeeCustomToolClass;

class PASCALIMPLEMENTATION TChartTools : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TTeeCustomTool* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomAxisPanel* FOwner;
	HIDESBASE TTeeCustomTool* __fastcall Get(int Index);
	void __fastcall SetActive(bool Value);
	
public:
	HIDESBASE TTeeCustomTool* __fastcall Add(TTeeCustomTool* Tool)/* overload */;
	HIDESBASE TTeeCustomTool* __fastcall Add(TMetaClass* Tool)/* overload */;
	virtual void __fastcall Clear(void);
	__property bool Active = {write=SetActive, nodefault};
	__property TTeeCustomTool* Items[int Index] = {read=Get/*, default*/};
	__property TCustomAxisPanel* Owner = {read=FOwner};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TChartTools(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartTools(void) : Classes::TList() { }
	#pragma option pop
	
};


typedef TMetaClass*TTeeEventClass;

#pragma option push -b-
enum TChartToolEvent { cteAfterDraw, cteBeforeDrawSeries, cteBeforeDraw, cteBeforeDrawAxes, cteAfterDrawSeries, cteMouseLeave };
#pragma option pop

#pragma option push -b-
enum TChartSeriesEvent { seAdd, seRemove, seChangeTitle, seChangeColor, seSwap, seChangeActive, seDataChanged };
#pragma option pop

class DELPHICLASS TTeeCustomDesigner;
class PASCALIMPLEMENTATION TTeeCustomDesigner : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	DYNAMIC void __fastcall Refresh(void);
	DYNAMIC void __fastcall Repaint(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeCustomDesigner(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeCustomDesigner(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TChartSeriesClass;

class PASCALIMPLEMENTATION TCustomAxisPanel : public Teeprocs::TCustomTeePanelExtended 
{
	typedef Teeprocs::TCustomTeePanelExtended inherited;
	
public:
	TChartSeries* operator[](int Index) { return Series[Index]; }
	
private:
	int F3DPercent;
	TChartAxes* FAxes;
	bool FAxisBehind;
	bool FAxisVisible;
	bool FClipPoints;
	TChartCustomAxes* FCustomAxes;
	TChartSeriesList* FSeriesList;
	TChartDepthAxis* FDepthAxis;
	TChartDepthAxis* FDepthTopAxis;
	TChartAxis* FTopAxis;
	TChartAxis* FBottomAxis;
	TChartAxis* FLeftAxis;
	TChartAxis* FRightAxis;
	bool FView3DWalls;
	TSeriesNotifyEvent FOnAddSeries;
	Classes::TNotifyEvent FOnBeforeDrawChart;
	Classes::TNotifyEvent FOnBeforeDrawAxes;
	Classes::TNotifyEvent FOnBeforeDrawSeries;
	TAxisOnGetLabel FOnGetAxisLabel;
	TAxisOnGetNextLabel FOnGetNextAxisLabel;
	Classes::TNotifyEvent FOnPageChange;
	TSeriesNotifyEvent FOnRemoveSeries;
	TChartPage* FPage;
	int FMaxZOrder;
	int FSeriesWidth3D;
	int FSeriesHeight3D;
	TChartTools* FTools;
	bool InvertedRotation;
	void __fastcall BroadcastTeeEventClass(TMetaClass* Event);
	void __fastcall BroadcastToolEvent(TChartToolEvent AEvent);
	void __fastcall CalcInvertedRotation(void);
	void __fastcall CheckOtherSeries(TChartSeries* Dest, TChartSeries* Source);
	TChartSeries* __fastcall GetAxisSeriesMaxPoints(TChartAxis* Axis);
	int __fastcall GetPage(void);
	int __fastcall GetPointsPerPage(void);
	bool __fastcall GetScaleLastPage(void);
	TChartSeries* __fastcall GetSeries(int Index);
	TSeriesGroups* __fastcall GetSeriesGroups(void);
	void __fastcall InternalAddSeries(TCustomChartSeries* ASeries);
	double __fastcall InternalMinMax(TChartAxis* AAxis, bool IsMin, bool IsX);
	bool __fastcall IsSeriesGroupsStored(void);
	bool __fastcall NoActiveSeries(TChartAxis* AAxis);
	void __fastcall ReadMaxPointsPerPage(Classes::TReader* Reader);
	void __fastcall ReadPage(Classes::TReader* Reader);
	void __fastcall ReadScaleLastPage(Classes::TReader* Reader);
	void __fastcall Set3DPercent(int Value);
	void __fastcall SetAxisBehind(bool Value);
	void __fastcall SetAxisVisible(bool Value);
	void __fastcall SetBottomAxis(TChartAxis* Value);
	void __fastcall SetClipPoints(bool Value);
	void __fastcall SetCustomAxes(TChartCustomAxes* Value);
	void __fastcall SetDepthAxis(TChartDepthAxis* Value);
	void __fastcall SetDepthTopAxis(const TChartDepthAxis* Value);
	void __fastcall SetLeftAxis(TChartAxis* Value);
	void __fastcall SetPages(const TChartPage* Value);
	void __fastcall SetPointsPerPage(const int Value);
	void __fastcall SetRightAxis(TChartAxis* Value);
	void __fastcall SetScaleLastPage(const bool Value);
	void __fastcall SetSeriesGroups(const TSeriesGroups* Value);
	void __fastcall SetTopAxis(TChartAxis* Value);
	void __fastcall SetView3DWalls(bool Value);
	bool __fastcall IsCustomAxesStored(void);
	
protected:
	bool DoNotBroadcast;
	Graphics::TColor LegendColor;
	Tecanvas::TChartPen* LegendPen;
	void __fastcall BroadcastSeriesEvent(TCustomChartSeries* ASeries, TChartSeriesEvent Event);
	bool __fastcall CalcIsAxisVisible(TChartAxis* Axis);
	virtual void __fastcall CalcWallsRect(void) = 0 ;
	virtual int __fastcall CalcWallSize(TChartAxis* Axis) = 0 ;
	bool __fastcall CheckMouseSeries(int x, int y);
	void __fastcall ColorPaletteChanged(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DoOnAfterDraw(void);
	virtual void __fastcall DoOnBeforeDrawAxes(void);
	virtual void __fastcall DoOnBeforeDrawChart(void);
	virtual void __fastcall DoOnBeforeDrawSeries(void);
	virtual void __fastcall DrawTitlesAndLegend(bool BeforeSeries) = 0 ;
	virtual bool __fastcall DrawBackWallAfter(int Z);
	virtual void __fastcall DrawLegendShape(const Types::TRect &Rect);
	virtual void __fastcall DrawWalls(void) = 0 ;
	bool __fastcall HasActiveSeries(TChartAxis* Axis, bool Default = false);
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
	bool __fastcall IsAxisVisible(TChartAxis* Axis);
	DYNAMIC void __fastcall RemovedDataSource(TChartSeries* ASeries, Classes::TComponent* AComponent);
	void __fastcall SetPage(const int Value);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	
public:
	TTeeCustomDesigner* Designer;
	DynamicArray<Graphics::TColor >  ColorPalette;
	__fastcall virtual TCustomAxisPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAxisPanel(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TChartSeries* __fastcall ActiveSeriesLegend(int ItemIndex);
	TChartSeries* __fastcall AddSeries(const TChartSeries* ASeries)/* overload */;
	TChartSeries* __fastcall AddSeries(TMetaClass* ASeriesClass)/* overload */;
	void __fastcall CalcSize3DWalls(void);
	virtual void __fastcall CheckDatasource(TChartSeries* ASeries);
	int __fastcall CountActiveSeries(void);
	void __fastcall ExchangeSeries(int a, int b)/* overload */;
	void __fastcall ExchangeSeries(TCustomChartSeries* a, TCustomChartSeries* b)/* overload */;
	virtual AnsiString __fastcall FormattedValueLegend(TChartSeries* ASeries, int ValueIndex);
	void __fastcall FreeAllSeries(TMetaClass* SeriesClass = 0x0);
	TChartSeries* __fastcall GetAxisSeries(TChartAxis* Axis);
	Graphics::TColor __fastcall GetDefaultColor(int Index);
	Graphics::TColor __fastcall GetFreeSeriesColor(bool CheckBackground = true, TChartSeries* Series = (TChartSeries*)(0x0));
	int __fastcall GetMaxValuesCount(void);
	virtual bool __fastcall IsFreeSeriesColor(Graphics::TColor AColor, bool CheckBackground, TChartSeries* Series = (TChartSeries*)(0x0)) = 0 ;
	DYNAMIC bool __fastcall IsValidDataSource(TChartSeries* ASeries, Classes::TComponent* AComponent);
	double __fastcall MaxXValue(TChartAxis* AAxis);
	double __fastcall MaxYValue(TChartAxis* AAxis);
	double __fastcall MinXValue(TChartAxis* AAxis);
	double __fastcall MinYValue(TChartAxis* AAxis);
	int __fastcall MaxMarkWidth(void);
	int __fastcall MaxTextWidth(void);
	int __fastcall MultiLineTextWidth(AnsiString S, /* out */ int &NumLines);
	DYNAMIC int __fastcall NumPages(void);
	void __fastcall PrintPages(int FromPage = 0x1, int ToPage = 0x0);
	void __fastcall RemoveSeries(TCustomChartSeries* ASeries)/* overload */;
	void __fastcall RemoveSeries(int SeriesIndex)/* overload */;
	__property TChartSeries* Series[int Index] = {read=GetSeries/*, default*/};
	int __fastcall SeriesCount(void);
	TChartSeries* __fastcall SeriesLegend(int ItemIndex, bool OnlyActive);
	AnsiString __fastcall SeriesTitleLegend(int SeriesIndex, bool OnlyActive = false);
	__property TChartAxes* Axes = {read=FAxes};
	__property TChartAxes* AxesList = {read=FAxes};
	__property TChartCustomAxes* CustomAxes = {read=FCustomAxes, write=SetCustomAxes, stored=IsCustomAxesStored};
	__property int MaxZOrder = {read=FMaxZOrder, write=FMaxZOrder, nodefault};
	__property int SeriesWidth3D = {read=FSeriesWidth3D, nodefault};
	__property int SeriesHeight3D = {read=FSeriesHeight3D, nodefault};
	__property bool AxisBehind = {read=FAxisBehind, write=SetAxisBehind, default=1};
	__property bool AxisVisible = {read=FAxisVisible, write=SetAxisVisible, default=1};
	__property TChartAxis* BottomAxis = {read=FBottomAxis, write=SetBottomAxis};
	__property int Chart3DPercent = {read=F3DPercent, write=Set3DPercent, default=15};
	__property bool ClipPoints = {read=FClipPoints, write=SetClipPoints, default=1};
	__property Color  = {default=-2147483633};
	__property TChartDepthAxis* DepthAxis = {read=FDepthAxis, write=SetDepthAxis};
	__property TChartDepthAxis* DepthTopAxis = {read=FDepthTopAxis, write=SetDepthTopAxis};
	__property TChartAxis* LeftAxis = {read=FLeftAxis, write=SetLeftAxis};
	__property int MaxPointsPerPage = {read=GetPointsPerPage, write=SetPointsPerPage, nodefault};
	__property int Page = {read=GetPage, write=SetPage, nodefault};
	__property TChartPage* Pages = {read=FPage, write=SetPages};
	__property TChartAxis* RightAxis = {read=FRightAxis, write=SetRightAxis};
	__property bool ScaleLastPage = {read=GetScaleLastPage, write=SetScaleLastPage, nodefault};
	__property TSeriesGroups* SeriesGroups = {read=GetSeriesGroups, write=SetSeriesGroups, stored=IsSeriesGroupsStored};
	__property TChartSeriesList* SeriesList = {read=FSeriesList};
	__property TChartTools* Tools = {read=FTools};
	__property TChartAxis* TopAxis = {read=FTopAxis, write=SetTopAxis};
	__property bool View3DWalls = {read=FView3DWalls, write=SetView3DWalls, default=1};
	__property TSeriesNotifyEvent OnAddSeries = {read=FOnAddSeries, write=FOnAddSeries};
	__property Classes::TNotifyEvent OnBeforeDrawChart = {read=FOnBeforeDrawChart, write=FOnBeforeDrawChart};
	__property Classes::TNotifyEvent OnBeforeDrawAxes = {read=FOnBeforeDrawAxes, write=FOnBeforeDrawAxes};
	__property Classes::TNotifyEvent OnBeforeDrawSeries = {read=FOnBeforeDrawSeries, write=FOnBeforeDrawSeries};
	__property TAxisOnGetLabel OnGetAxisLabel = {read=FOnGetAxisLabel, write=FOnGetAxisLabel};
	__property TAxisOnGetNextLabel OnGetNextAxisLabel = {read=FOnGetNextAxisLabel, write=FOnGetNextAxisLabel};
	__property Classes::TNotifyEvent OnPageChange = {read=FOnPageChange, write=FOnPageChange};
	__property TSeriesNotifyEvent OnRemoveSeries = {read=FOnRemoveSeries, write=FOnRemoveSeries};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomAxisPanel(HWND ParentWindow) : Teeprocs::TCustomTeePanelExtended(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomChartElement : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	Tecanvas::TChartBrush* FBrush;
	TCustomAxisPanel* FParent;
	Tecanvas::TChartPen* FPen;
	bool FShowInEditor;
	
protected:
	bool DontSerialize;
	virtual void __fastcall CanvasChanged(System::TObject* Sender);
	Tecanvas::TChartPen* __fastcall CreateChartPen(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetActive(bool Value);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetColorProperty(Graphics::TColor &Variable, Graphics::TColor Value);
	void __fastcall SetDoubleProperty(double &Variable, const double Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	virtual void __fastcall SetParentChart(const TCustomAxisPanel* Value);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	virtual void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetStringProperty(AnsiString &Variable, const AnsiString Value);
	
public:
	__fastcall virtual TCustomChartElement(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomChartElement(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/*         class method */ static AnsiString __fastcall EditorClass(TMetaClass* vmt);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall Repaint(void);
	__property bool Active = {read=FActive, write=SetActive, default=1};
	__property Tecanvas::TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property TCustomAxisPanel* ParentChart = {read=FParent, write=SetParentChart, stored=false};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property bool Visible = {read=FActive, write=SetActive, default=1};
	
__published:
	__property bool ShowInEditor = {read=FShowInEditor, write=FShowInEditor, default=1};
};


typedef double TChartValue;

typedef DynamicArray<double >  TChartValues;

#pragma option push -b-
enum TChartListOrder { loNone, loAscending, loDescending };
#pragma option pop

class DELPHICLASS TChartValueList;
class PASCALIMPLEMENTATION TChartValueList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	double operator[](int Index) { return Items[Index]; }
	
private:
	int FCount;
	bool FDateTime;
	double FMaxValue;
	double FMinValue;
	AnsiString FName;
	TChartListOrder FOrder;
	TChartSeries* FOwner;
	double FTempValue;
	double FTotal;
	double FTotalABS;
	AnsiString FValueSource;
	bool IDefDateTime;
	int __fastcall GetCount(void);
	void __fastcall SetCount(const int Value);
	int __fastcall CompareValueIndex(int a, int b);
	double __fastcall GetMaxValue(void);
	double __fastcall GetMinValue(void);
	double __fastcall GetTotal(void);
	double __fastcall GetTotalABS(void);
	bool __fastcall IsDateStored(void);
	void __fastcall SetDateTime(const bool Value);
	void __fastcall ReadMultiplier(Classes::TReader* Reader);
	void __fastcall SetValueSource(const AnsiString Value);
	
protected:
	bool FModified;
	System::TObject* IData;
	int __fastcall AddChartValue(void)/* overload */;
	virtual int __fastcall AddChartValue(const double AValue)/* overload */;
	virtual void __fastcall ClearValues(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	double __fastcall GetValue(int ValueIndex);
	void __fastcall InitDateTime(bool Value);
	virtual void __fastcall InsertChartValue(int ValueIndex, const double AValue);
	void __fastcall RecalcStats(void)/* overload */;
	void __fastcall RecalcStats(int StartIndex)/* overload */;
	void __fastcall SetValue(int ValueIndex, const double AValue);
	
public:
	DynamicArray<double >  Value;
	__fastcall virtual TChartValueList(TChartSeries* AOwner, const AnsiString AName);
	__fastcall virtual ~TChartValueList(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	virtual void __fastcall Delete(int ValueIndex)/* overload */;
	void __fastcall Delete(int Start, int Quantity)/* overload */;
	void __fastcall Exchange(int Index1, int Index2);
	void __fastcall FillSequence(void);
	double __fastcall First(void);
	double __fastcall Last(void);
	int __fastcall Locate(const double AValue)/* overload */;
	int __fastcall Locate(const double AValue, int FirstIndex, int LastIndex)/* overload */;
	double __fastcall Range(void);
	DYNAMIC void __fastcall Scroll(void);
	void __fastcall Sort(void);
	__property double MaxValue = {read=GetMaxValue};
	__property double MinValue = {read=GetMinValue};
	__property bool Modified = {read=FModified, write=FModified, nodefault};
	__property TChartSeries* Owner = {read=FOwner};
	__property double TempValue = {read=FTempValue, write=FTempValue};
	AnsiString __fastcall ValueToString(const int Index);
	AnsiString __fastcall ToString(const int Index);
	__property double Total = {read=GetTotal};
	__property double TotalABS = {read=GetTotalABS, write=FTotalABS};
	__property double Items[int Index] = {read=GetValue, write=SetValue/*, default*/};
	
__published:
	__property bool DateTime = {read=FDateTime, write=SetDateTime, stored=IsDateStored, nodefault};
	__property AnsiString Name = {read=FName, write=FName};
	__property TChartListOrder Order = {read=FOrder, write=FOrder, nodefault};
	__property AnsiString ValueSource = {read=FValueSource, write=SetValueSource};
};


class DELPHICLASS TChartAxisTitle;
class PASCALIMPLEMENTATION TChartAxisTitle : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	int FAngle;
	AnsiString FCaption;
	int IDefaultAngle;
	bool __fastcall IsAngleStored(void);
	void __fastcall SetAngle(const int Value);
	void __fastcall SetCaption(const AnsiString Value);
	
public:
	__fastcall virtual TChartAxisTitle(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall Clicked(int x, int y);
	
__published:
	__property int Angle = {read=FAngle, write=SetAngle, stored=IsAngleStored, nodefault};
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property Font ;
	__property Visible  = {default=1};
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Brush ;
	__property Pen ;
	__property RoundSize  = {default=16};
	__property ShapeStyle  = {default=0};
	__property Color  = {default=16777215};
	__property Gradient ;
	__property Picture ;
	__property Shadow ;
	__property Transparency  = {default=0};
	__property Transparent  = {default=1};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TChartAxisTitle(void) { }
	#pragma option pop
	
};


class DELPHICLASS AxisException;
class PASCALIMPLEMENTATION AxisException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall AxisException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall AxisException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall AxisException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall AxisException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall AxisException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall AxisException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall AxisException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall AxisException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~AxisException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TAxisLabelStyle { talAuto, talNone, talValue, talMark, talText };
#pragma option pop

#pragma option push -b-
enum TAxisLabelAlign { alDefault, alOpposite };
#pragma option pop

typedef int __fastcall (__closure *TAxisCalcPos)(const double Value);

class DELPHICLASS TAxisGridPen;
class PASCALIMPLEMENTATION TAxisGridPen : public Tecanvas::TDottedGrayPen 
{
	typedef Tecanvas::TDottedGrayPen inherited;
	
private:
	bool FCentered;
	int FDrawEvery;
	double FZ;
	double IDefaultZ;
	bool __fastcall IsZStored(void);
	void __fastcall SetCentered(const bool Value);
	void __fastcall SetDrawEvery(const int Value);
	void __fastcall SetZ(const double Value);
	
public:
	__fastcall TAxisGridPen(Classes::TNotifyEvent OnChangeEvent);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property bool Centered = {read=FCentered, write=SetCentered, default=0};
	
__published:
	__property int DrawEvery = {read=FDrawEvery, write=SetDrawEvery, default=1};
	__property double ZPosition = {read=FZ, write=SetZ, stored=IsZStored};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TAxisGridPen(void) { }
	#pragma option pop
	
};


typedef DynamicArray<int >  TAxisTicks;

class DELPHICLASS TAxisItem;
class DELPHICLASS TAxisItems;
class PASCALIMPLEMENTATION TAxisItems : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TAxisItem* operator[](int Index) { return Item[Index]; }
	
private:
	bool FAuto;
	Teeprocs::TTeeShape* FFormat;
	TChartAxis* IAxis;
	HIDESBASE TAxisItem* __fastcall Get(int Index);
	
public:
	__fastcall TAxisItems(TChartAxis* Axis);
	__fastcall virtual ~TAxisItems(void);
	HIDESBASE TAxisItem* __fastcall Add(const double Value)/* overload */;
	HIDESBASE TAxisItem* __fastcall Add(const double Value, const AnsiString Text)/* overload */;
	void __fastcall CopyFrom(TAxisItems* Source);
	virtual void __fastcall Clear(void);
	__property bool Automatic = {read=FAuto, write=FAuto, default=1};
	__property Teeprocs::TTeeShape* Format = {read=FFormat};
	__property TAxisItem* Item[int Index] = {read=Get/*, default*/};
};


class PASCALIMPLEMENTATION TAxisItem : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	double FValue;
	AnsiString FText;
	TAxisItems* IAxisItems;
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetValue(const double Value);
	
public:
	HIDESBASE void __fastcall Repaint(void);
	
__published:
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Color  = {default=16777215};
	__property Font ;
	__property Gradient ;
	__property Picture ;
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property AnsiString Text = {read=FText, write=SetText};
	__property Transparency  = {default=0};
	__property Transparent  = {default=1};
	__property double Value = {read=FValue, write=SetValue};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TAxisItem(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : Teeprocs::TTeeCustomShape(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TAxisItem(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPenLineMode { lmLine, lmCylinder, lmRectangle };
#pragma option pop

class DELPHICLASS TChartAxisPen;
class PASCALIMPLEMENTATION TChartAxisPen : public Tecanvas::TChartPen 
{
	typedef Tecanvas::TChartPen inherited;
	
private:
	TPenLineMode FLineMode;
	void __fastcall SetLineMode(const TPenLineMode Value);
	
public:
	__fastcall TChartAxisPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property TPenLineMode LineMode = {read=FLineMode, write=SetLineMode, default=0};
	__property Width  = {default=2};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartAxisPen(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TAxisDrawLabelEvent)(TChartAxis* Sender, int &X, int &Y, int &Z, AnsiString &Text, bool &DrawLabel);

typedef void __fastcall (__closure *TAxisDrawGrids)(TChartAxis* Sender);

class PASCALIMPLEMENTATION TChartAxis : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	bool FAutomatic;
	bool FAutomaticMaximum;
	bool FAutomaticMinimum;
	double FDesiredIncrement;
	double FMaximumValue;
	double FMinimumValue;
	bool FLogarithmic;
	double FLogarithmicBase;
	int FMaximumOffset;
	int FMinimumOffset;
	bool FMaximumRound;
	bool FMinimumRound;
	TChartAxisPen* FAxis;
	int FPosAxis;
	double FZPosition;
	TChartAxisTitle* FAxisTitle;
	int FTitleSize;
	int FPosTitle;
	TAxisGridPen* FGrid;
	TAxisLabelAlign FLabelsAlign;
	bool FLabelsAlternate;
	int FLabelsAngle;
	TAxisItems* FItems;
	bool FLabelsOnAxis;
	int FLabelsSeparation;
	int FLabelsSize;
	TAxisLabelStyle FLabelStyle;
	bool FLabelsExponent;
	bool FLabelsMultiLine;
	bool FRoundFirstLabel;
	int FPosLabels;
	AnsiString FAxisValuesFormat;
	AnsiString FDateTimeFormat;
	bool FExactDateTime;
	Tecanvas::TChartHiddenPen* FMinorGrid;
	int FMinorTickCount;
	int FMinorTickLength;
	Tecanvas::TDarkGrayPen* FMinorTicks;
	Tecanvas::TDarkGrayPen* FTicks;
	Tecanvas::TDarkGrayPen* FTicksInner;
	int FTickInnerLength;
	int FTickLength;
	bool FTickOnLabelsOnly;
	bool FInverted;
	bool FHorizontal;
	bool FOtherSide;
	TCustomAxisPanel* FParentChart;
	bool FVisible;
	double FStartPosition;
	double FEndPosition;
	double FPositionPercent;
	Teeprocs::TTeeUnits FPosUnits;
	TAxisDrawLabelEvent FOnDrawLabel;
	TChartAxis* FMaster;
	bool IAxisDateTime;
	double IAxisLogSizeRange;
	double IAxisSizeRange;
	int ICenterPos;
	bool IDepthAxis;
	double ILogMax;
	double ILogMin;
	double IMaximum;
	double IMinimum;
	double IRange;
	double IRangeLog;
	bool IRangeZero;
	TCustomSeriesList* ISeriesList;
	bool IsVisible;
	int IWallSize;
	int IZPos;
	void __fastcall CalcRoundScales(void);
	int __fastcall DepthAxisAlign(void);
	int __fastcall DepthAxisPos(void);
	int __fastcall InflateAxisPos(int Value, int Amount);
	void __fastcall InflateAxisRect(Types::TRect &R, const int Value);
	double __fastcall RoundLogPower(const double Value);
	void __fastcall SetAutomatic(bool Value);
	void __fastcall SetAutomaticMinimum(bool Value);
	void __fastcall SetAutomaticMaximum(bool Value);
	void __fastcall SetAutoMinMax(bool &Variable, bool Var2, bool Value);
	void __fastcall SetAxis(TChartAxisPen* Value);
	void __fastcall SetAxisTitle(TChartAxisTitle* Value);
	void __fastcall SetDateTimeFormat(const AnsiString Value);
	void __fastcall SetDesiredIncrement(const double Value);
	void __fastcall SetExactDateTime(bool Value);
	void __fastcall SetGrid(TAxisGridPen* Value);
	void __fastcall SetGridCentered(bool Value);
	void __fastcall SetLabels(bool Value);
	void __fastcall SetLabelsAlign(TAxisLabelAlign Value);
	void __fastcall SetLabelsAlternate(bool Value);
	void __fastcall SetLabelsAngle(const int Value);
	void __fastcall SetLabelsFont(Tecanvas::TTeeFont* Value);
	void __fastcall SetLabelsMultiLine(bool Value);
	void __fastcall SetLabelsOnAxis(bool Value);
	void __fastcall SetLabelsSeparation(int Value);
	void __fastcall SetLabelsSize(int Value);
	void __fastcall SetLabelStyle(TAxisLabelStyle Value);
	void __fastcall SetLogarithmic(bool Value);
	void __fastcall SetLogarithmicBase(const double Value);
	void __fastcall SetMaximum(const double Value);
	void __fastcall SetMinimum(const double Value);
	void __fastcall SetMaximumRound(const bool Value);
	void __fastcall SetMinimumRound(const bool Value);
	void __fastcall SetMinorGrid(Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetMinorTickCount(int Value);
	void __fastcall SetMinorTickLength(int Value);
	void __fastcall SetMinorTicks(Tecanvas::TDarkGrayPen* Value);
	void __fastcall SetStartPosition(const double Value);
	void __fastcall SetEndPosition(const double Value);
	void __fastcall SetPositionPercent(const double Value);
	void __fastcall SetPosUnits(const Teeprocs::TTeeUnits Value);
	void __fastcall SetRoundFirstLabel(bool Value);
	void __fastcall SetTickLength(int Value);
	void __fastcall SetTickInnerLength(int Value);
	void __fastcall SetTicks(Tecanvas::TDarkGrayPen* Value);
	void __fastcall SetTicksInner(Tecanvas::TDarkGrayPen* Value);
	void __fastcall SetTickOnLabelsOnly(bool Value);
	void __fastcall SetTitleSize(int Value);
	void __fastcall SetValuesFormat(const AnsiString Value);
	void __fastcall SetVisible(bool Value);
	int __fastcall ApplyPosition(int APos, const Types::TRect &R);
	double __fastcall CalcDateTimeIncrement(int MaxNumLabels);
	double __fastcall CalcLabelsIncrement(int MaxNumLabels);
	void __fastcall CalcRect(Types::TRect &R, bool InflateChartRectangle);
	int __fastcall CalcZPos(void);
	void __fastcall DrawGridLine(int tmp);
	bool __fastcall GetGridCentered(void);
	bool __fastcall GetLabels(void);
	Tecanvas::TTeeFont* __fastcall GetLabelsFont(void);
	int __fastcall GetRectangleEdge(const Types::TRect &R);
	void __fastcall IncDecDateTime(bool Increment, double &Value, const double AnIncrement, Teeprocs::TDateTimeStep tmpWhichDateTime);
	int __fastcall LogXPosValue(const double Value);
	int __fastcall LogYPosValue(const double Value);
	int __fastcall InternalCalcDepthPosValue(const double Value);
	void __fastcall InternalCalcRange(void);
	void __fastcall InternalCalcPositions(void);
	int __fastcall InternalCalcSize(Tecanvas::TTeeFont* tmpFont, int tmpAngle, const AnsiString tmpText, int tmpSize);
	int __fastcall InternalLabelSize(const double Value, bool IsWidth);
	bool __fastcall IsAxisValuesFormatStored(void);
	bool __fastcall IsLogBaseStored(void);
	bool __fastcall IsMaxStored(void);
	bool __fastcall IsMinStored(void);
	bool __fastcall IsPosStored(void);
	bool __fastcall IsStartStored(void);
	bool __fastcall IsEndStored(void);
	bool __fastcall IsCustom(void);
	bool __fastcall IsZStored(void);
	void __fastcall RecalcSizeCenter(void);
	void __fastcall SetHorizontal(const bool Value);
	void __fastcall SetOtherSide(const bool Value);
	void __fastcall SetLabelsExponent(bool Value);
	void __fastcall SetCalcPosValue(void);
	void __fastcall SetMaximumOffset(const int Value);
	void __fastcall SetMinimumOffset(const int Value);
	void __fastcall SetZPosition(const double Value);
	int __fastcall XPosValue(const double Value);
	int __fastcall YPosValue(const double Value);
	int __fastcall XPosValueCheck(const double Value);
	int __fastcall YPosValueCheck(const double Value);
	
protected:
	bool IHideBackGrid;
	bool IHideSideGrid;
	TAxisOnGetNextLabel OnCalcMaxLabel;
	Classes::TNotifyEvent OnDrawAxis;
	TAxisDrawGrids OnDrawGrids;
	Types::TRect __fastcall AxisRect();
	void __fastcall DrawGrids(int NumTicks);
	void __fastcall DrawLineSegment(int AStart, int AEnd);
	void __fastcall DrawTitle(int x, int y);
	virtual TAxisLabelStyle __fastcall InternalCalcLabelStyle(void);
	void __fastcall InternalSetInverted(bool Value);
	void __fastcall InternalSetMaximum(const double Value);
	void __fastcall InternalSetMinimum(const double Value);
	virtual void __fastcall SetInverted(bool Value);
	int __fastcall SizeLabels(void);
	int __fastcall SizeTickAxis(void);
	
public:
	int IStartPos;
	int IEndPos;
	int IAxisSize;
	TAxisCalcPos CalcXPosValue;
	TAxisCalcPos CalcYPosValue;
	TAxisCalcPos CalcPosValue;
	DynamicArray<int >  Tick;
	__fastcall TChartAxis(TCustomAxisPanel* Chart)/* overload */;
	__fastcall virtual TChartAxis(Classes::TCollection* Collection)/* overload */;
	__fastcall virtual ~TChartAxis(void);
	void __fastcall AdjustMaxMin(void);
	void __fastcall AdjustMaxMinRect(const Types::TRect &Rect);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	double __fastcall CalcIncrement(void);
	TAxisLabelStyle __fastcall CalcLabelStyle(void);
	void __fastcall CalcMinMax(/* out */ double &AMin, /* out */ double &AMax);
	double __fastcall CalcPosPoint(int Value);
	int __fastcall CalcSizeValue(const double Value);
	double __fastcall CalcXYIncrement(int MaxLabelSize);
	void __fastcall CustomDraw(int APosLabels, int APosTitle, int APosAxis, bool GridVisible);
	void __fastcall CustomDrawMinMax(int APosLabels, int APosTitle, int APosAxis, bool GridVisible, const double AMinimum, const double AMaximum, const double AIncrement);
	void __fastcall CustomDrawMinMaxStartEnd(int APosLabels, int APosTitle, int APosAxis, bool GridVisible, const double AMinimum, const double AMaximum, const double AIncrement, int AStartPos, int AEndPos);
	void __fastcall CustomDrawStartEnd(int APosLabels, int APosTitle, int APosAxis, bool GridVisible, int AStartPos, int AEndPos);
	bool __fastcall Clicked(int x, int y);
	void __fastcall Draw(bool CalcPosAxis);
	void __fastcall DrawAxisLabel(int x, int y, int Angle, const AnsiString St, Teeprocs::TTeeCustomShape* Format = (Teeprocs::TTeeCustomShape*)(0x0), int z = 0x0);
	bool __fastcall IsDateTime(void);
	int __fastcall LabelWidth(const double Value);
	int __fastcall LabelHeight(const double Value);
	virtual AnsiString __fastcall LabelValue(const double Value);
	int __fastcall MaxLabelsWidth(void);
	void __fastcall Scroll(const double Offset, bool CheckLimits = false);
	void __fastcall SetMinMax(double AMin, double AMax);
	__property bool IsDepthAxis = {read=IDepthAxis, nodefault};
	__property TAxisItems* Items = {read=FItems};
	__property TChartAxis* MasterAxis = {read=FMaster, write=FMaster};
	__property int PosAxis = {read=FPosAxis, nodefault};
	__property int PosLabels = {read=FPosLabels, nodefault};
	__property int PosTitle = {read=FPosTitle, nodefault};
	__property TCustomAxisPanel* ParentChart = {read=FParentChart};
	
__published:
	__property bool Automatic = {read=FAutomatic, write=SetAutomatic, default=1};
	__property bool AutomaticMaximum = {read=FAutomaticMaximum, write=SetAutomaticMaximum, default=1};
	__property bool AutomaticMinimum = {read=FAutomaticMinimum, write=SetAutomaticMinimum, default=1};
	__property TChartAxisPen* Axis = {read=FAxis, write=SetAxis};
	__property AnsiString AxisValuesFormat = {read=FAxisValuesFormat, write=SetValuesFormat, stored=IsAxisValuesFormatStored};
	__property AnsiString DateTimeFormat = {read=FDateTimeFormat, write=SetDateTimeFormat};
	__property bool ExactDateTime = {read=FExactDateTime, write=SetExactDateTime, default=1};
	__property TAxisGridPen* Grid = {read=FGrid, write=SetGrid};
	__property bool GridCentered = {read=GetGridCentered, write=SetGridCentered, default=0};
	__property double Increment = {read=FDesiredIncrement, write=SetDesiredIncrement};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=0};
	__property bool Horizontal = {read=FHorizontal, write=SetHorizontal, stored=IsCustom, nodefault};
	__property bool OtherSide = {read=FOtherSide, write=SetOtherSide, stored=IsCustom, nodefault};
	__property bool Labels = {read=GetLabels, write=SetLabels, default=1};
	__property TAxisLabelAlign LabelsAlign = {read=FLabelsAlign, write=SetLabelsAlign, default=0};
	__property bool LabelsAlternate = {read=FLabelsAlternate, write=SetLabelsAlternate, default=0};
	__property int LabelsAngle = {read=FLabelsAngle, write=SetLabelsAngle, default=0};
	__property bool LabelsExponent = {read=FLabelsExponent, write=SetLabelsExponent, default=0};
	__property Tecanvas::TTeeFont* LabelsFont = {read=GetLabelsFont, write=SetLabelsFont};
	__property bool LabelsMultiLine = {read=FLabelsMultiLine, write=SetLabelsMultiLine, default=0};
	__property bool LabelsOnAxis = {read=FLabelsOnAxis, write=SetLabelsOnAxis, default=1};
	__property int LabelsSeparation = {read=FLabelsSeparation, write=SetLabelsSeparation, default=10};
	__property int LabelsSize = {read=FLabelsSize, write=SetLabelsSize, default=0};
	__property TAxisLabelStyle LabelStyle = {read=FLabelStyle, write=SetLabelStyle, default=0};
	__property bool Logarithmic = {read=FLogarithmic, write=SetLogarithmic, default=0};
	__property double LogarithmicBase = {read=FLogarithmicBase, write=SetLogarithmicBase, stored=IsLogBaseStored};
	__property double Maximum = {read=FMaximumValue, write=SetMaximum, stored=IsMaxStored};
	__property int MaximumOffset = {read=FMaximumOffset, write=SetMaximumOffset, default=0};
	__property bool MaximumRound = {read=FMaximumRound, write=SetMaximumRound, default=0};
	__property double Minimum = {read=FMinimumValue, write=SetMinimum, stored=IsMinStored};
	__property int MinimumOffset = {read=FMinimumOffset, write=SetMinimumOffset, default=0};
	__property bool MinimumRound = {read=FMinimumRound, write=SetMinimumRound, default=0};
	__property Tecanvas::TChartHiddenPen* MinorGrid = {read=FMinorGrid, write=SetMinorGrid};
	__property int MinorTickCount = {read=FMinorTickCount, write=SetMinorTickCount, default=3};
	__property int MinorTickLength = {read=FMinorTickLength, write=SetMinorTickLength, default=2};
	__property Tecanvas::TDarkGrayPen* MinorTicks = {read=FMinorTicks, write=SetMinorTicks};
	__property double StartPosition = {read=FStartPosition, write=SetStartPosition, stored=IsStartStored};
	__property double EndPosition = {read=FEndPosition, write=SetEndPosition, stored=IsEndStored};
	__property double PositionPercent = {read=FPositionPercent, write=SetPositionPercent, stored=IsPosStored};
	__property Teeprocs::TTeeUnits PositionUnits = {read=FPosUnits, write=SetPosUnits, default=0};
	__property bool RoundFirstLabel = {read=FRoundFirstLabel, write=SetRoundFirstLabel, default=1};
	__property int TickInnerLength = {read=FTickInnerLength, write=SetTickInnerLength, default=0};
	__property int TickLength = {read=FTickLength, write=SetTickLength, default=4};
	__property Tecanvas::TDarkGrayPen* Ticks = {read=FTicks, write=SetTicks};
	__property Tecanvas::TDarkGrayPen* TicksInner = {read=FTicksInner, write=SetTicksInner};
	__property bool TickOnLabelsOnly = {read=FTickOnLabelsOnly, write=SetTickOnLabelsOnly, default=1};
	__property TChartAxisTitle* Title = {read=FAxisTitle, write=SetAxisTitle};
	__property int TitleSize = {read=FTitleSize, write=SetTitleSize, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property double ZPosition = {read=FZPosition, write=SetZPosition, stored=IsZStored};
	__property TAxisDrawLabelEvent OnDrawLabel = {read=FOnDrawLabel, write=FOnDrawLabel};
};


class PASCALIMPLEMENTATION TChartDepthAxis : public TChartAxis 
{
	typedef TChartAxis inherited;
	
protected:
	virtual TAxisLabelStyle __fastcall InternalCalcLabelStyle(void);
	virtual void __fastcall SetInverted(bool Value);
	
__published:
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TChartAxis.Create */ inline __fastcall TChartDepthAxis(TCustomAxisPanel* Chart)/* overload */ : TChartAxis(Chart) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TChartAxis.Destroy */ inline __fastcall virtual ~TChartDepthAxis(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TSeriesClick)(TChartSeries* Sender, int ValueIndex, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

#pragma option push -b-
enum TValueEvent { veClear, veAdd, veDelete, veRefresh, veModify };
#pragma option pop

#pragma option push -b-
enum THorizAxis { aTopAxis, aBottomAxis, aBothHorizAxis, aCustomHorizAxis };
#pragma option pop

#pragma option push -b-
enum TVertAxis { aLeftAxis, aRightAxis, aBothVertAxis, aCustomVertAxis };
#pragma option pop

#pragma option push -b-
enum TChartClickedPartStyle { cpNone, cpLegend, cpAxis, cpSeries, cpTitle, cpFoot, cpChartRect, cpSeriesMarks, cpSubTitle, cpSubFoot, cpAxisTitle };
#pragma option pop

#pragma pack(push, 1)
struct TChartClickedPart
{
	TChartClickedPartStyle Part;
	int PointIndex;
	TChartSeries* ASeries;
	TChartAxis* AAxis;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TSeriesGroupActive { gaYes, gaNo, gaSome };
#pragma option pop

class PASCALIMPLEMENTATION TSeriesGroup : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FName;
	TCustomSeriesList* FSeries;
	TSeriesGroupActive __fastcall GetActive(void);
	bool __fastcall IsSeriesStored(void);
	void __fastcall SetActive(const TSeriesGroupActive Value);
	void __fastcall SetSeries(const TCustomSeriesList* Value);
	
public:
	__fastcall virtual TSeriesGroup(Classes::TCollection* Collection)/* overload */;
	__fastcall virtual ~TSeriesGroup(void);
	void __fastcall Add(TChartSeries* Series);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Hide(void);
	void __fastcall Show(void);
	
__published:
	__property TSeriesGroupActive Active = {read=GetActive, write=SetActive, default=0};
	__property AnsiString Name = {read=FName, write=FName};
	__property TCustomSeriesList* Series = {read=FSeries, write=SetSeries, stored=IsSeriesStored};
};


class DELPHICLASS TChartChangePage;
class PASCALIMPLEMENTATION TChartChangePage : public Teeprocs::TTeeEvent 
{
	typedef Teeprocs::TTeeEvent inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartChangePage(void) : Teeprocs::TTeeEvent() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TChartChangePage(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TChartMouseEvent { cmeDown, cmeMove, cmeUp };
#pragma option pop

#pragma option push -b-
enum TWheelMouseEvent { wmeDown, wmeMove, wmeUp };
#pragma option pop

class PASCALIMPLEMENTATION TTeeCustomTool : public TCustomChartElement 
{
	typedef TCustomChartElement inherited;
	
protected:
	virtual void __fastcall ChartEvent(TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall SeriesEvent(TChartToolEvent AEvent);
	virtual void __fastcall SetParentChart(const TCustomAxisPanel* Value);
	virtual void __fastcall WheelMouseEvent(TWheelMouseEvent AEvent, int WheelDelta, int X, int Y);
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TTeeCustomTool(Classes::TComponent* AOwner) : TCustomChartElement(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TTeeCustomTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeCustomToolSeries;
class PASCALIMPLEMENTATION TTeeCustomToolSeries : public TTeeCustomTool 
{
	typedef TTeeCustomTool inherited;
	
private:
	TChartSeries* FSeries;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	TChartAxis* __fastcall GetHorizAxis(void);
	TChartAxis* __fastcall GetVertAxis(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetSeries(const TChartSeries* Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TChartSeries* Series = {read=FSeries, write=SetSeries};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TTeeCustomToolSeries(Classes::TComponent* AOwner) : TTeeCustomTool(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TTeeCustomToolSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeCustomToolAxis;
class PASCALIMPLEMENTATION TTeeCustomToolAxis : public TTeeCustomTool 
{
	typedef TTeeCustomTool inherited;
	
private:
	TChartAxis* FAxis;
	void __fastcall ReadAxis(Classes::TReader* Reader);
	void __fastcall WriteAxis(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetAxis(const TChartAxis* Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TChartAxis* Axis = {read=FAxis, write=SetAxis, stored=false};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TTeeCustomToolAxis(Classes::TComponent* AOwner) : TTeeCustomTool(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TTeeCustomToolAxis(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeSeriesEvent;
class PASCALIMPLEMENTATION TTeeSeriesEvent : public Teeprocs::TTeeEvent 
{
	typedef Teeprocs::TTeeEvent inherited;
	
public:
	TChartSeriesEvent Event;
	TCustomChartSeries* Series;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeSeriesEvent(void) : Teeprocs::TTeeEvent() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeSeriesEvent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesMarkPosition;
class PASCALIMPLEMENTATION TSeriesMarkPosition : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma pack(push, 1)
	Types::TPoint ArrowFrom;
	#pragma pack(pop)
	
	bool ArrowFix;
	#pragma pack(push, 1)
	Types::TPoint ArrowTo;
	#pragma pack(pop)
	
	bool Custom;
	int Height;
	#pragma pack(push, 1)
	Types::TPoint LeftTop;
	#pragma pack(pop)
	
	int Width;
	#pragma pack(push, 1)
	Types::TPoint MidPoint;
	#pragma pack(pop)
	
	bool HasMid;
	void __fastcall Assign(TSeriesMarkPosition* Source);
	Types::TRect __fastcall Bounds();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSeriesMarkPosition(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSeriesMarkPosition(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesMarksPositions;
class DELPHICLASS TSeriesMarks;
class DELPHICLASS TMarksCallout;
class DELPHICLASS TCallout;
class DELPHICLASS TSeriesPointer;
#pragma option push -b-
enum TSeriesPointerStyle { psRectangle, psCircle, psTriangle, psDownTriangle, psCross, psDiagCross, psStar, psDiamond, psSmallDot, psNothing, psLeftTriangle, psRightTriangle, psHexagon };
#pragma option pop

class PASCALIMPLEMENTATION TSeriesPointer : public Teeprocs::TTeeCustomShapeBrushPen 
{
	typedef Teeprocs::TTeeCustomShapeBrushPen inherited;
	
private:
	bool FDark3D;
	bool FDraw3D;
	Tecanvas::TTeeGradient* FGradient;
	int FHorizSize;
	bool FInflate;
	TChartSeries* FSeries;
	Tecanvas::TTeeShadow* FShadow;
	TSeriesPointerStyle FStyle;
	Tecanvas::TTeeTransparency FTransparency;
	int FVertSize;
	void __fastcall CheckPointerSize(int Value);
	Graphics::TColor __fastcall GetColor(void);
	int __fastcall GetSize(void);
	int __fastcall GetStartZ(void);
	int __fastcall GetMiddleZ(void);
	int __fastcall GetEndZ(void);
	void __fastcall SetColor(const Graphics::TColor Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetDraw3D(bool Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetHorizSize(int Value);
	void __fastcall SetInflate(bool Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetShadow(const Tecanvas::TTeeShadow* Value);
	void __fastcall SetStyle(TSeriesPointerStyle Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetVertSize(int Value);
	
protected:
	bool AllowChangeSize;
	bool FullGradient;
	void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	void __fastcall Change3D(bool Value);
	void __fastcall ChangeHorizSize(int NewSize);
	void __fastcall ChangeStyle(TSeriesPointerStyle NewStyle);
	void __fastcall ChangeVertSize(int NewSize);
	void __fastcall Prepare(void);
	
public:
	__fastcall TSeriesPointer(TChartSeries* AOwner);
	__fastcall virtual ~TSeriesPointer(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Draw(const Types::TPoint &P)/* overload */;
	void __fastcall Draw(int X, int Y)/* overload */;
	void __fastcall Draw(int px, int py, Graphics::TColor ColorValue, TSeriesPointerStyle AStyle)/* overload */;
	void __fastcall DrawPointer(Tecanvas::TCanvas3D* ACanvas, bool Is3D, int px, int py, int tmpHoriz, int tmpVert, Graphics::TColor ColorValue, TSeriesPointerStyle AStyle);
	void __fastcall PrepareCanvas(Tecanvas::TCanvas3D* ACanvas, Graphics::TColor ColorValue);
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property TChartSeries* ParentSeries = {read=FSeries};
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	
__published:
	__property Brush ;
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property bool Draw3D = {read=FDraw3D, write=SetDraw3D, default=1};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property int HorizSize = {read=FHorizSize, write=SetHorizSize, default=4};
	__property bool InflateMargins = {read=FInflate, write=SetInflate, nodefault};
	__property Pen ;
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property TSeriesPointerStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property int VertSize = {read=FVertSize, write=SetVertSize, default=4};
	__property Visible ;
};


#pragma option push -b-
enum TArrowHeadStyle { ahNone, ahLine, ahSolid };
#pragma option pop

class PASCALIMPLEMENTATION TCallout : public TSeriesPointer 
{
	typedef TSeriesPointer inherited;
	
private:
	Tecanvas::TWhitePen* FArrow;
	TArrowHeadStyle FArrowHead;
	int FDistance;
	int FArrowHeadSize;
	void __fastcall SetDistance(const int Value);
	void __fastcall SetArrow(const Tecanvas::TWhitePen* Value);
	void __fastcall SetArrowHead(const TArrowHeadStyle Value);
	void __fastcall SetArrowHeadSize(const int Value);
	
protected:
	HIDESBASE void __fastcall Draw(Graphics::TColor AColor, const Types::TPoint &AFrom, const Types::TPoint &AMid, const Types::TPoint &ATo, int Z, bool MidPoint = false)/* overload */;
	
public:
	__fastcall TCallout(TChartSeries* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall virtual ~TCallout(void);
	
__published:
	__property Tecanvas::TWhitePen* Arrow = {read=FArrow, write=SetArrow};
	__property TArrowHeadStyle ArrowHead = {read=FArrowHead, write=SetArrowHead, default=0};
	__property int ArrowHeadSize = {read=FArrowHeadSize, write=SetArrowHeadSize, default=8};
	__property int Distance = {read=FDistance, write=SetDistance, default=0};
	__property Draw3D  = {default=0};
	__property InflateMargins  = {default=1};
	__property Style  = {default=0};
	__property Visible  = {default=1};
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Draw(const Types::TPoint &P){ TSeriesPointer::Draw(P); }
	inline void __fastcall  Draw(int X, int Y){ TSeriesPointer::Draw(X, Y); }
	inline void __fastcall  Draw(int px, int py, Graphics::TColor ColorValue, TSeriesPointerStyle AStyle){ TSeriesPointer::Draw(px, py, ColorValue, AStyle); }
	
};


class PASCALIMPLEMENTATION TMarksCallout : public TCallout 
{
	typedef TCallout inherited;
	
private:
	int FLength;
	void __fastcall ApplyArrowLength(TSeriesMarkPosition* APosition);
	bool __fastcall IsLengthStored(void);
	void __fastcall SetLength(const int Value);
	
protected:
	int DefaultLength;
	
public:
	__fastcall TMarksCallout(TChartSeries* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property int Length = {read=FLength, write=SetLength, stored=IsLengthStored, nodefault};
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TCallout.Destroy */ inline __fastcall virtual ~TMarksCallout(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMarksItems;
class DELPHICLASS TMarksItem;
class PASCALIMPLEMENTATION TMarksItems : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TMarksItem* operator[](int Index) { return Format[Index]; }
	
private:
	Teeprocs::TTeeCustomShape* IMarks;
	bool ILoadingCustom;
	HIDESBASE TMarksItem* __fastcall Get(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property TMarksItem* Format[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TMarksItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMarksItems(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TMargins;
#pragma option push -b-
enum TMarginUnits { maPercentFont, maPercentSize, maPixels };
#pragma option pop

class PASCALIMPLEMENTATION TMargins : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FLeft;
	int FTop;
	int FRight;
	int FBottom;
	TMarginUnits FUnits;
	int DefaultHoriz;
	#pragma pack(push, 1)
	Types::TRect ILast;
	#pragma pack(pop)
	
	Teeprocs::TTeeCustomShapeBrushPen* IParent;
	bool __fastcall IsLeftStored(void);
	bool __fastcall IsRightStored(void);
	void __fastcall SetBottom(const int Value);
	void __fastcall SetDefaultHoriz(const int Value);
	void __fastcall SetIntegerProperty(int &Variable, const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetRight(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetUnits(const TMarginUnits Value);
	
public:
	__fastcall TMargins(Teeprocs::TTeeCustomShapeBrushPen* AParent);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Calculate(const int Width, const int Height, const int FontSize);
	int __fastcall HorizSize(void);
	int __fastcall VertSize(void);
	__property Types::TRect Size = {read=ILast};
	
__published:
	__property int Left = {read=FLeft, write=SetLeft, stored=IsLeftStored, nodefault};
	__property int Top = {read=FTop, write=SetTop, default=5};
	__property int Right = {read=FRight, write=SetRight, stored=IsRightStored, nodefault};
	__property int Bottom = {read=FBottom, write=SetBottom, default=5};
	__property TMarginUnits Units = {read=FUnits, write=SetUnits, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TMargins(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSeriesMarksStyle { smsValue, smsPercent, smsLabel, smsLabelPercent, smsLabelValue, smsLegend, smsPercentTotal, smsLabelPercentTotal, smsXValue, smsXY, smsSeriesTitle, smsPointIndex, smsPercentRelative };
#pragma option pop

class DELPHICLASS TSeriesMarksSymbol;
class PASCALIMPLEMENTATION TSeriesMarksSymbol : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	bool __fastcall ShouldDraw(void);
	
public:
	__fastcall virtual TSeriesMarksSymbol(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	
__published:
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Brush ;
	__property Frame ;
	__property Gradient ;
	__property Pen ;
	__property Picture ;
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property Transparency  = {default=0};
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TSeriesMarksSymbol(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TSeriesMarks : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
public:
	TMarksItem* operator[](int Index) { return Item[Index]; }
	
private:
	int FAngle;
	TMarksCallout* FCallout;
	bool FClip;
	int FDrawEvery;
	TMarksItems* FItems;
	TMargins* FMargins;
	TSeriesMarksStyle FMarkerStyle;
	bool FMultiLine;
	TChartSeries* FSeries;
	TSeriesMarksPositions* FPositions;
	TSeriesMarksSymbol* FSymbol;
	Classes::TAlignment FTextAlign;
	int FZPosition;
	bool FFontSeriesColor;
	int __fastcall GetArrowLength(void);
	Tecanvas::TWhitePen* __fastcall GetArrowPen(void);
	Graphics::TColor __fastcall GetBackColor(void);
	TMarksCallout* __fastcall GetCallout(void);
	TMarksItem* __fastcall GetItem(int Index);
	TSeriesMarksSymbol* __fastcall GetSymbol(void);
	void __fastcall InternalDraw(int Index, Graphics::TColor AColor, const AnsiString St, TSeriesMarkPosition* APosition);
	void __fastcall ReadItems(Classes::TStream* Stream);
	void __fastcall SetAngle(int Value);
	void __fastcall SetCallout(const TMarksCallout* Value);
	void __fastcall SetArrowPen(const Tecanvas::TWhitePen* Value);
	void __fastcall SetArrowLength(int Value);
	void __fastcall SetBackColor(Graphics::TColor Value);
	void __fastcall SetClip(bool Value);
	void __fastcall SetDrawEvery(int Value);
	void __fastcall SetFontSeriesColor(const bool Value);
	void __fastcall SetMargins(const TMargins* Value);
	void __fastcall SetMultiline(bool Value);
	void __fastcall SetStyle(TSeriesMarksStyle Value);
	void __fastcall SetSymbol(const TSeriesMarksSymbol* Value);
	void __fastcall SetTextAlign(const Classes::TAlignment Value);
	void __fastcall WriteItems(Classes::TStream* Stream);
	
protected:
	void __fastcall AntiOverlap(int First, int ValueIndex, TSeriesMarkPosition* APosition);
	Types::TPoint __fastcall ConvertTo2D(const Types::TPoint &Point, const Types::TPoint &P);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC TMetaClass* __fastcall GetGradientClass(void);
	DYNAMIC void __fastcall InitShadow(Tecanvas::TTeeShadow* AShadow);
	Teeprocs::TTeeCustomShape* __fastcall MarkItem(int ValueIndex);
	virtual void __fastcall SetParent(Teeprocs::TCustomTeePanel* Value);
	int __fastcall TextWidth(int ValueIndex);
	void __fastcall UsePosition(int Index, TSeriesMarkPosition* &MarkPosition);
	
public:
	__fastcall TSeriesMarks(TChartSeries* AOwner)/* overload */;
	__fastcall virtual ~TSeriesMarks(void);
	void __fastcall ApplyArrowLength(TSeriesMarkPosition* APosition);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	int __fastcall Clicked(int X, int Y);
	void __fastcall DrawItem(Teeprocs::TTeeCustomShape* Shape, Graphics::TColor AColor, const AnsiString Text, TSeriesMarkPosition* APosition);
	void __fastcall DrawText(const Types::TRect &R, const AnsiString St);
	__property bool FontSeriesColor = {read=FFontSeriesColor, write=SetFontSeriesColor, default=0};
	__property TMarksItem* Item[int Index] = {read=GetItem/*, default*/};
	__property TMarksItems* Items = {read=FItems};
	__property TChartSeries* ParentSeries = {read=FSeries};
	__property TSeriesMarksPositions* Positions = {read=FPositions};
	void __fastcall ResetPositions(void);
	__property int ZPosition = {read=FZPosition, write=FZPosition, nodefault};
	
__published:
	__property int Angle = {read=FAngle, write=SetAngle, default=0};
	__property Tecanvas::TWhitePen* Arrow = {read=GetArrowPen, write=SetArrowPen};
	__property int ArrowLength = {read=GetArrowLength, write=SetArrowLength, stored=false, nodefault};
	__property TMarksCallout* Callout = {read=GetCallout, write=SetCallout};
	__property Graphics::TColor BackColor = {read=GetBackColor, write=SetBackColor, default=-2147483624};
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Brush ;
	__property bool Clip = {read=FClip, write=SetClip, default=0};
	__property Color  = {default=-2147483624};
	__property int DrawEvery = {read=FDrawEvery, write=SetDrawEvery, default=1};
	__property Font ;
	__property Frame ;
	__property Gradient ;
	__property TMargins* Margins = {read=FMargins, write=SetMargins};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiline, default=0};
	__property Picture ;
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property TSeriesMarksStyle Style = {read=FMarkerStyle, write=SetStyle, default=2};
	__property TSeriesMarksSymbol* Symbol = {read=GetSymbol, write=SetSymbol};
	__property Classes::TAlignment TextAlign = {read=FTextAlign, write=SetTextAlign, default=2};
	__property Transparency  = {default=0};
	__property Transparent ;
	__property Visible ;
};


class PASCALIMPLEMENTATION TSeriesMarksPositions : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TSeriesMarkPosition* operator[](int Index) { return Position[Index]; }
	
private:
	TSeriesMarks* IMarks;
	HIDESBASE TSeriesMarkPosition* __fastcall Get(int Index);
	HIDESBASE void __fastcall Put(int Index, TSeriesMarkPosition* APosition);
	
public:
	void __fastcall Automatic(int Index);
	virtual void __fastcall Clear(void);
	bool __fastcall ExistCustom(void);
	void __fastcall MoveTo(TSeriesMarkPosition* &Position, int XPos, int YPos);
	__property TSeriesMarkPosition* Position[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TSeriesMarksPositions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSeriesMarksPositions(void) : Classes::TList() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TMarksItem : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	Classes::TStrings* FText;
	Classes::TStrings* __fastcall GetText(void);
	void __fastcall SetText(const Classes::TStrings* Value);
	
public:
	__fastcall virtual ~TMarksItem(void);
	
__published:
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Color  = {default=-2147483624};
	__property Font ;
	__property Gradient ;
	__property Picture ;
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property Classes::TStrings* Text = {read=GetText, write=SetText};
	__property Transparency  = {default=0};
	__property Transparent ;
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TMarksItem(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : Teeprocs::TTeeCustomShape(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesMarksGradient;
class PASCALIMPLEMENTATION TSeriesMarksGradient : public Tecanvas::TTeeGradient 
{
	typedef Tecanvas::TTeeGradient inherited;
	
public:
	__fastcall virtual TSeriesMarksGradient(Classes::TNotifyEvent ChangedEvent);
	
__published:
	__property Direction  = {default=3};
	__property EndColor  = {default=16777215};
	__property StartColor  = {default=12632256};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Destroy */ inline __fastcall virtual ~TSeriesMarksGradient(void) { }
	#pragma option pop
	
};


typedef TWhitePen TChartArrowPen;
;

typedef bool __fastcall (__closure *TSeriesOnBeforeAdd)(TChartSeries* Sender);

typedef void __fastcall (__closure *TSeriesOnAfterAdd)(TChartSeries* Sender, int ValueIndex);

typedef void __fastcall (__closure *TSeriesOnClear)(TChartSeries* Sender);

typedef void __fastcall (__closure *TSeriesOnGetMarkText)(TChartSeries* Sender, int ValueIndex, AnsiString &MarkText);

#pragma option push -b-
enum TeEngine__73 { rOnDelete, rOnModify, rOnInsert, rOnClear };
#pragma option pop

typedef Set<TeEngine__73, rOnDelete, rOnClear>  TSeriesRecalcOptions;

#pragma option push -b-
enum TFunctionPeriodStyle { psNumPoints, psRange };
#pragma option pop

#pragma option push -b-
enum TFunctionPeriodAlign { paFirst, paCenter, paLast };
#pragma option pop

class DELPHICLASS TTeeFunction;
class PASCALIMPLEMENTATION TTeeFunction : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	double FPeriod;
	TFunctionPeriodStyle FPeriodStyle;
	TFunctionPeriodAlign FPeriodAlign;
	TChartSeries* FParent;
	void __fastcall SetPeriod(const double Value);
	void __fastcall SetParentSeries(TChartSeries* AParent);
	void __fastcall SetPeriodAlign(TFunctionPeriodAlign Value);
	void __fastcall SetPeriodStyle(TFunctionPeriodStyle Value);
	
protected:
	bool IUpdating;
	bool CanUsePeriod;
	bool NoSourceRequired;
	bool SingleSource;
	bool HideSourceList;
	void __fastcall AddFunctionXY(bool YMandatorySource, const double tmpX, const double tmpY);
	virtual void __fastcall CalculatePeriod(TChartSeries* Source, const double tmpX, int FirstIndex, int LastIndex);
	virtual void __fastcall CalculateAllPoints(TChartSeries* Source, TChartValueList* NotMandatorySource);
	virtual void __fastcall CalculateByPeriod(TChartSeries* Source, TChartValueList* NotMandatorySource);
	DYNAMIC void __fastcall Clear(void);
	virtual void __fastcall DoCalculation(TChartSeries* Source, TChartValueList* NotMandatorySource);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	void __fastcall InternalSetPeriod(const double APeriod);
	DYNAMIC bool __fastcall IsValidSource(TChartSeries* Value);
	/* virtual class method */ virtual void __fastcall PrepareForGallery(TMetaClass* vmt, TCustomAxisPanel* Chart);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
	TChartValueList* __fastcall ValueList(TChartSeries* ASeries);
	
public:
	__fastcall virtual TTeeFunction(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	DYNAMIC void __fastcall AddPoints(TChartSeries* Source);
	void __fastcall BeginUpdate(void);
	virtual double __fastcall Calculate(TChartSeries* SourceSeries, int First, int Last);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
	void __fastcall EndUpdate(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__property TChartSeries* ParentSeries = {read=FParent, write=SetParentSeries};
	void __fastcall ReCalculate(void);
	
__published:
	__property double Period = {read=FPeriod, write=SetPeriod};
	__property TFunctionPeriodAlign PeriodAlign = {read=FPeriodAlign, write=SetPeriodAlign, default=1};
	__property TFunctionPeriodStyle PeriodStyle = {read=FPeriodStyle, write=SetPeriodStyle, default=0};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeMovingFunction;
class PASCALIMPLEMENTATION TTeeMovingFunction : public TTeeFunction 
{
	typedef TTeeFunction inherited;
	
protected:
	virtual void __fastcall DoCalculation(TChartSeries* Source, TChartValueList* NotMandatorySource);
	
public:
	__fastcall virtual TTeeMovingFunction(Classes::TComponent* AOwner);
	
__published:
	__property Period ;
	__property PeriodAlign  = {default=2};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TTeeMovingFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartValueLists;
class PASCALIMPLEMENTATION TChartValueLists : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TChartValueList* operator[](int Index) { return ValueList[Index]; }
	
private:
	HIDESBASE TChartValueList* __fastcall Get(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property TChartValueList* ValueList[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TChartValueLists(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartValueLists(void) : Classes::TList() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TeEngine__14 { tssIsTemplate, tssDenyChangeType, tssDenyDelete, tssDenyClone, tssIsPersistent, tssHideDataSource };
#pragma option pop

typedef Set<TeEngine__14, tssIsTemplate, tssHideDataSource>  TChartSeriesStyle;

class PASCALIMPLEMENTATION TCustomChartSeries : public TCustomChartElement 
{
	typedef TCustomChartElement inherited;
	
private:
	bool FShowInLegend;
	AnsiString FTitle;
	AnsiString FIdentifier;
	TChartSeriesStyle FStyle;
	void __fastcall ReadIdentifier(Classes::TReader* Reader);
	void __fastcall WriteIdentifier(Classes::TWriter* Writer);
	void __fastcall ReadStyle(Classes::TReader* Reader);
	void __fastcall WriteStyle(Classes::TWriter* Writer);
	void __fastcall RepaintDesigner(void);
	void __fastcall SetShowInLegend(bool Value);
	void __fastcall SetTitle(const AnsiString Value);
	
protected:
	DYNAMIC void __fastcall Added(void);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DoBeforeDrawChart(void);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	DYNAMIC void __fastcall Removed(void);
	virtual void __fastcall SetActive(bool Value);
	
public:
	__fastcall virtual TCustomChartSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall SameClass(TChartSeries* tmpSeries);
	__property bool ShowInLegend = {read=FShowInLegend, write=SetShowInLegend, default=1};
	__property AnsiString Title = {read=FTitle, write=SetTitle};
	__property AnsiString Identifier = {read=FIdentifier, write=FIdentifier};
	__property TChartSeriesStyle Style = {read=FStyle, write=FStyle, default=0};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TCustomChartSeries(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TSeriesRandomBounds
{
	double tmpX;
	double StepX;
	double tmpY;
	double MinY;
	double DifY;
} ;
#pragma pack(pop)

typedef TMetaClass*TTeeFunctionClass;

class DELPHICLASS TTeeSeriesType;
class PASCALIMPLEMENTATION TTeeSeriesType : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TMetaClass*SeriesClass;
	TMetaClass*FunctionClass;
	AnsiString *Description;
	AnsiString *GalleryPage;
	int NumGallerySeries;
	int SubIndex;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeSeriesType(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeSeriesType(void) { }
	#pragma option pop
	
};


typedef TCustomAxisPanel* __fastcall (__closure *TChartSubGalleryProc)(const AnsiString AName);

#pragma option push -b-
enum TLegendTextStyle { ltsPlain, ltsLeftValue, ltsRightValue, ltsLeftPercent, ltsRightPercent, ltsXValue, ltsValue, ltsPercent, ltsXAndValue, ltsXAndPercent };
#pragma option pop

#pragma option push -b-
enum TeeFormatFlags { tfNoMandatory, tfColor, tfLabel, tfMarkPosition };
#pragma option pop

typedef Set<TeeFormatFlags, tfNoMandatory, tfMarkPosition>  TeeFormatFlag;

class DELPHICLASS TLabelsList;
class PASCALIMPLEMENTATION TLabelsList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	AnsiString operator[](int Index) { return Labels[Index]; }
	
private:
	TChartSeries* Series;
	void __fastcall DeleteLabel(int ValueIndex);
	AnsiString __fastcall GetLabel(int ValueIndex);
	void __fastcall SetLabel(int ValueIndex, const AnsiString ALabel);
	void __fastcall InsertLabel(int ValueIndex, const AnsiString ALabel);
	
public:
	HIDESBASE void __fastcall Assign(TLabelsList* Source);
	virtual void __fastcall Clear(void);
	int __fastcall IndexOfLabel(const AnsiString ALabel, bool CaseSensitive = true);
	__property AnsiString Labels[int Index] = {read=GetLabel, write=SetLabel/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TLabelsList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TLabelsList(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TDataSourcesList;
class PASCALIMPLEMENTATION TDataSourcesList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
private:
	TChartSeries* Series;
	int __fastcall InheritedAdd(Classes::TComponent* Value);
	void __fastcall InheritedClear(void);
	
protected:
	virtual void __fastcall Notify(void * Ptr, Classes::TListNotification Action);
	
public:
	HIDESBASE int __fastcall Add(Classes::TComponent* Value);
	virtual void __fastcall Clear(void);
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TDataSourcesList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDataSourcesList(void) : Classes::TList() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TChartSeries : public TCustomChartSeries 
{
	typedef TCustomChartSeries inherited;
	
private:
	Graphics::TColor FColor;
	bool FColorEachPoint;
	Classes::TList* FColors;
	AnsiString FColorSource;
	Controls::TCursor FCursor;
	TDataSourcesList* FDataSources;
	int FDepth;
	TChartAxis* FGetHorizAxis;
	TChartAxis* FGetVertAxis;
	AnsiString FLabelsSource;
	TCustomSeriesList* FLinkedSeries;
	TSeriesMarks* FMarks;
	AnsiString FPercentFormat;
	Classes::TStringList* FTempDataSources;
	AnsiString FValueFormat;
	TChartValueLists* FValuesList;
	TChartValueList* FX;
	TLabelsList* FLabels;
	TChartValueList* FY;
	double FDefaultNull;
	THorizAxis FHorizAxis;
	TChartAxis* FCustomHorizAxis;
	TChartAxis* FCustomVertAxis;
	int FZOrder;
	TVertAxis FVertAxis;
	TSeriesRecalcOptions FRecalcOptions;
	TTeeFunction* FTeeFunction;
	bool IsMouseInside;
	TChartListOrder ILabelOrder;
	Graphics::TColor ISeriesColor;
	Classes::TNotifyEvent FAfterDrawValues;
	Classes::TNotifyEvent FBeforeDrawValues;
	TSeriesOnAfterAdd FOnAfterAdd;
	TSeriesOnBeforeAdd FOnBeforeAdd;
	TSeriesOnClear FOnClearValues;
	TSeriesClick FOnClick;
	TSeriesClick FOnDblClick;
	TSeriesOnGetMarkText FOnGetMarkText;
	Classes::TNotifyEvent FOnMouseEnter;
	Classes::TNotifyEvent FOnMouseLeave;
	void __fastcall BroadcastEvent(TChartToolEvent AEvent);
	bool __fastcall CanAddRandomPoints(void);
	void __fastcall ChangeInternalColor(Graphics::TColor Value);
	int __fastcall CompareLabelIndex(int a, int b);
	Classes::TComponent* __fastcall GetDataSource(void);
	int __fastcall GetZOrder(void);
	void __fastcall GrowColors(void);
	int __fastcall InternalAddDataSource(Classes::TComponent* Value);
	int __fastcall InternalSetDataSource(Classes::TComponent* Value, bool ClearAll);
	void __fastcall InternalRemoveDataSource(Classes::TComponent* Value);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsPercentFormatStored(void);
	bool __fastcall IsValidDataSource(Classes::TComponent* Value);
	bool __fastcall IsValueFormatStored(void);
	void __fastcall NotifyColorChanged(void);
	void __fastcall ReadCustomHorizAxis(Classes::TReader* Reader);
	void __fastcall ReadCustomVertAxis(Classes::TReader* Reader);
	void __fastcall ReadDataSources(Classes::TReader* Reader);
	void __fastcall RecalcGetAxis(void);
	void __fastcall RemoveAllLinkedSeries(void);
	void __fastcall SetColorSource(const AnsiString Value);
	void __fastcall SetCustomHorizAxis(TChartAxis* Value);
	void __fastcall SetCustomVertAxis(TChartAxis* Value);
	void __fastcall SetDataSource(Classes::TComponent* Value);
	void __fastcall SetDepth(const int Value);
	void __fastcall SetHorizAxis(const THorizAxis Value);
	void __fastcall SetLabelsSource(const AnsiString Value);
	void __fastcall SetMarks(TSeriesMarks* Value);
	void __fastcall SetPercentFormat(const AnsiString Value);
	void __fastcall SetValueColor(int ValueIndex, Graphics::TColor AColor);
	void __fastcall SetVertAxis(const TVertAxis Value);
	void __fastcall SetXValue(int Index, const double Value);
	void __fastcall SetYValue(int Index, const double Value);
	void __fastcall SetZOrder(int Value);
	void __fastcall WriteCustomHorizAxis(Classes::TWriter* Writer);
	void __fastcall WriteCustomVertAxis(Classes::TWriter* Writer);
	void __fastcall WriteDataSources(Classes::TWriter* Writer);
	AnsiString __fastcall GetXLabel(int Index);
	void __fastcall SetXLabel(int Index, const AnsiString Value);
	void __fastcall SetDefaultNullValue(const double Value);
	
protected:
	bool DontSaveData;
	bool ForceSaveData;
	bool ManualData;
	int FFirstVisibleIndex;
	int FLastVisibleIndex;
	bool IHideWhenVisible;
	int INumSampleValues;
	int IUpdating;
	bool IUseSeriesColor;
	bool IUseNotMandatory;
	int IZOrder;
	Teeprocs::TTeeCustomShape* ILegend;
	int IFirstDrawIndex;
	bool IMandatoryPen;
	bool IMandatoryPen2D;
	virtual int __fastcall AddChartValue(TChartSeries* Source, int ValueIndex);
	DYNAMIC void __fastcall Added(void);
	virtual void __fastcall AddedValue(TChartSeries* Source, int ValueIndex);
	void __fastcall AddLinkedSeries(TChartSeries* ASeries);
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall AddValues(TChartSeries* Source);
	void __fastcall CalcFirstLastPage(/* out */ int &First, /* out */ int &Last);
	virtual void __fastcall CalcZOrder(void);
	virtual void __fastcall CalcDepthPositions(void);
	virtual void __fastcall CalcSelectionPos(int ValueIndex, /* out */ int &X, /* out */ int &Y);
	void __fastcall CalculateMarkPosition(Teeprocs::TTeeCustomShape* Shape, const AnsiString AText, int XPos, int YPos, TSeriesMarkPosition* &Position);
	bool __fastcall CheckMouse(int x, int y);
	virtual void __fastcall ClearLists(void);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DeletedValue(TChartSeries* Source, int ValueIndex);
	virtual void __fastcall DoAfterDrawValues(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawMarks(void);
	virtual void __fastcall DrawValue(int ValueIndex);
	bool __fastcall FirstInZOrder(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	AnsiString __fastcall GetMarkText(int ValueIndex);
	Graphics::TColor __fastcall GetSeriesColor(void);
	virtual Graphics::TColor __fastcall GetValueColor(int ValueIndex);
	virtual double __fastcall GetxValue(int ValueIndex);
	virtual double __fastcall GetyValue(int ValueIndex);
	Graphics::TColor __fastcall InternalColor(int ValueIndex);
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	virtual void __fastcall Loaded(void);
	TChartAxis* __fastcall MandatoryAxis(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall NotifyNewValue(TChartSeries* Sender, int ValueIndex);
	virtual void __fastcall NotifyValue(TValueEvent ValueEvent, int ValueIndex);
	virtual bool __fastcall MoreSameZOrder(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	/*         class method */ static int __fastcall RandomValue(TMetaClass* vmt, const int Range);
	void __fastcall ReadData(Classes::TStream* Stream);
	DYNAMIC void __fastcall Removed(void);
	void __fastcall RemoveLinkedSeries(TChartSeries* ASeries);
	void __fastcall SetChartValueList(TChartValueList* AValueList, TChartValueList* Value);
	virtual void __fastcall SetColorEachPoint(bool Value);
	void __fastcall SetHorizontal(void);
	void __fastcall SetMarkText(int ValueIndex, const AnsiString Value);
	virtual void __fastcall SetParentChart(const TCustomAxisPanel* Value);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, TChartSeries* ASeries, int Index);
	virtual void __fastcall SetValueFormat(const AnsiString Value);
	void __fastcall SetXValues(TChartValueList* Value);
	void __fastcall SetYValues(TChartValueList* Value);
	virtual TChartValueList* __fastcall ValueListOfAxis(TChartAxis* Axis);
	DYNAMIC void __fastcall WriteData(Classes::TStream* Stream);
	virtual bool __fastcall RaiseClicked(void);
	
public:
	bool CalcVisiblePoints;
	bool DrawBetweenPoints;
	bool AllowSinglePoint;
	bool HasZValues;
	int StartZ;
	int MiddleZ;
	int EndZ;
	TChartValueList* MandatoryValueList;
	TChartValueList* NotMandatoryValueList;
	bool YMandatory;
	__fastcall virtual TChartSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartSeries(void);
	virtual int __fastcall Add(const double AValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000))/* overload */;
	int __fastcall AddArray(const double * Values, const int Values_Size)/* overload */;
	int __fastcall AddArray(const double * XValues, const int XValues_Size, const double * YValues, const int YValues_Size)/* overload */;
	int __fastcall AddNull(const double Value)/* overload */;
	virtual int __fastcall AddNull(const AnsiString ALabel = "")/* overload */;
	virtual int __fastcall AddNullXY(const double X, const double Y, const AnsiString ALabel = "");
	int __fastcall AddX(const double AXValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual int __fastcall AddXY(const double AXValue, const double AYValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	int __fastcall AddY(const double AYValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall AssignFormat(TChartSeries* Source);
	virtual bool __fastcall AssociatedToAxis(TChartAxis* Axis);
	void __fastcall BeginUpdate(void);
	DYNAMIC void __fastcall CheckOrder(void);
	virtual void __fastcall Clear(void);
	int __fastcall Count(void);
	virtual int __fastcall CountLegendItems(void);
	virtual void __fastcall Delete(int ValueIndex)/* overload */;
	virtual void __fastcall Delete(int Start, int Quantity, bool RemoveGap = false)/* overload */;
	void __fastcall EndUpdate(void);
	DYNAMIC void __fastcall FillSampleValues(int NumValues = 0x0);
	int __fastcall FirstDisplayedIndex(void);
	int __fastcall LastDisplayedIndex(void);
	bool __fastcall IsNull(int ValueIndex);
	DYNAMIC bool __fastcall IsValidSourceOf(TChartSeries* Value);
	DYNAMIC bool __fastcall IsValidSeriesSource(TChartSeries* Value);
	virtual int __fastcall LegendToValueIndex(int LegendIndex);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, TLegendTextStyle LegendTextStyle);
	__property TCustomSeriesList* LinkedSeries = {read=FLinkedSeries};
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MinZValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	TSeriesRandomBounds __fastcall RandomBounds(int NumValues);
	void __fastcall RemoveDataSource(Classes::TComponent* Value);
	void __fastcall SetNull(int ValueIndex, bool Null = true);
	void __fastcall SortByLabels(TChartListOrder Order = (TChartListOrder)(0x1));
	int __fastcall VisibleCount(void);
	__property TChartValueLists* ValuesList = {read=FValuesList};
	__property double XValue[int Index] = {read=GetxValue, write=SetXValue};
	__property double YValue[int Index] = {read=GetyValue, write=SetYValue};
	__property int ZOrder = {read=GetZOrder, write=SetZOrder, default=-1};
	int __fastcall MaxMarkWidth(void);
	virtual int __fastcall CalcXPos(int ValueIndex);
	int __fastcall CalcXPosValue(const double Value);
	int __fastcall CalcXSizeValue(const double Value);
	virtual int __fastcall CalcYPos(int ValueIndex);
	int __fastcall CalcYPosValue(const double Value);
	int __fastcall CalcYSizeValue(const double Value);
	int __fastcall CalcPosValue(const double Value);
	double __fastcall XScreenToValue(int ScreenPos);
	double __fastcall YScreenToValue(int ScreenPos);
	AnsiString __fastcall XValueToText(const double AValue);
	AnsiString __fastcall YValueToText(const double AValue);
	void __fastcall ColorRange(TChartValueList* AValueList, const double FromValue, const double ToValue, Graphics::TColor AColor);
	void __fastcall CheckDataSource(void);
	virtual void __fastcall CalcFirstLastVisibleIndex(void);
	__property TLabelsList* Labels = {read=FLabels};
	__property AnsiString XLabel[int Index] = {read=GetXLabel, write=SetXLabel};
	__property AnsiString ValueMarkText[int Index] = {read=GetMarkText, write=SetMarkText};
	__property Graphics::TColor ValueColor[int Index] = {read=GetValueColor, write=SetValueColor};
	__property TChartValueList* XValues = {read=FX, write=SetXValues};
	__property TChartValueList* YValues = {read=FY, write=SetYValues};
	virtual TChartValueList* __fastcall GetYValueList(AnsiString AListName);
	__property TChartAxis* GetVertAxis = {read=FGetVertAxis};
	__property TChartAxis* GetHorizAxis = {read=FGetHorizAxis};
	AnsiString __fastcall MarkPercent(int ValueIndex, bool AddTotal = false);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	int __fastcall Clicked(const Types::TPoint &P)/* overload */;
	void __fastcall RefreshSeries(void);
	__property int FirstValueIndex = {read=FFirstVisibleIndex, nodefault};
	__property int LastValueIndex = {read=FLastVisibleIndex, nodefault};
	virtual double __fastcall GetOriginValue(int ValueIndex);
	virtual double __fastcall GetMarkValue(int ValueIndex);
	void __fastcall AssignValues(TChartSeries* Source);
	virtual bool __fastcall DrawValuesForward(void);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	DYNAMIC void __fastcall SwapValueIndex(int a, int b);
	__property TSeriesRecalcOptions RecalcOptions = {read=FRecalcOptions, write=FRecalcOptions, default=15};
	int __fastcall GetCursorValueIndex(void);
	void __fastcall GetCursorValues(/* out */ double &XValue, /* out */ double &YValue);
	virtual void __fastcall DrawLegend(int ValueIndex, const Types::TRect &Rect);
	virtual bool __fastcall UseAxis(void);
	virtual void __fastcall SetFunction(TTeeFunction* AFunction);
	__property Graphics::TColor SeriesColor = {read=GetSeriesColor, write=SetSeriesColor, stored=IsColorStored, nodefault};
	__property double DefaultNullValue = {read=FDefaultNull, write=SetDefaultNullValue};
	__property TDataSourcesList* DataSources = {read=FDataSources};
	__property TTeeFunction* FunctionType = {read=FTeeFunction, write=SetFunction};
	void __fastcall CheckOtherSeries(TChartSeries* Source);
	void __fastcall ReplaceList(TChartValueList* OldList, TChartValueList* NewList);
	__property TChartAxis* CustomHorizAxis = {read=FCustomHorizAxis, write=SetCustomHorizAxis};
	__property TChartAxis* CustomVertAxis = {read=FCustomVertAxis, write=SetCustomVertAxis};
	__property Active  = {default=1};
	__property Graphics::TColor Color = {read=GetSeriesColor, write=SetSeriesColor, stored=IsColorStored, nodefault};
	__property bool ColorEachPoint = {read=FColorEachPoint, write=SetColorEachPoint, default=0};
	__property AnsiString ColorSource = {read=FColorSource, write=SetColorSource};
	__property Controls::TCursor Cursor = {read=FCursor, write=FCursor, default=0};
	__property int Depth = {read=FDepth, write=SetDepth, default=-1};
	__property THorizAxis HorizAxis = {read=FHorizAxis, write=SetHorizAxis, default=1};
	__property TSeriesMarks* Marks = {read=FMarks, write=SetMarks};
	__property ParentChart ;
	__property Classes::TComponent* DataSource = {read=GetDataSource, write=SetDataSource};
	__property AnsiString PercentFormat = {read=FPercentFormat, write=SetPercentFormat, stored=IsPercentFormatStored};
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property AnsiString ValueFormat = {read=FValueFormat, write=SetValueFormat, stored=IsValueFormatStored};
	__property TVertAxis VertAxis = {read=FVertAxis, write=SetVertAxis, default=0};
	__property AnsiString XLabelsSource = {read=FLabelsSource, write=SetLabelsSource};
	__property Classes::TNotifyEvent AfterDrawValues = {read=FAfterDrawValues, write=FAfterDrawValues};
	__property Classes::TNotifyEvent BeforeDrawValues = {read=FBeforeDrawValues, write=FBeforeDrawValues};
	__property TSeriesOnAfterAdd OnAfterAdd = {read=FOnAfterAdd, write=FOnAfterAdd};
	__property TSeriesOnBeforeAdd OnBeforeAdd = {read=FOnBeforeAdd, write=FOnBeforeAdd};
	__property TSeriesOnClear OnClearValues = {read=FOnClearValues, write=FOnClearValues};
	__property TSeriesClick OnClick = {read=FOnClick, write=FOnClick};
	__property TSeriesClick OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property TSeriesOnGetMarkText OnGetMarkText = {read=FOnGetMarkText, write=FOnGetMarkText};
	__property Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
};


class DELPHICLASS ChartException;
class PASCALIMPLEMENTATION ChartException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ChartException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ChartException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ChartException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ChartException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ChartException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ChartException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ChartException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ChartException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ChartException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSourceLoadMode { lmClear, lmAppend };
#pragma option pop

class DELPHICLASS TTeeSeriesSource;
class PASCALIMPLEMENTATION TTeeSeriesSource : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	TSourceLoadMode FLoadMode;
	TChartSeries* FSeries;
	void __fastcall SetSeries(const TChartSeries* Value);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetActive(const bool Value);
	
public:
	__fastcall virtual TTeeSeriesSource(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeeSeriesSource(void);
	/* virtual class method */ virtual bool __fastcall Available(TMetaClass* vmt, TCustomAxisPanel* AChart);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	/* virtual class method */ virtual bool __fastcall HasNew(TMetaClass* vmt);
	/* virtual class method */ virtual bool __fastcall HasSeries(TMetaClass* vmt, TChartSeries* ASeries);
	virtual void __fastcall Close(void);
	virtual void __fastcall Load(void);
	virtual void __fastcall Open(void);
	void __fastcall Refresh(void);
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property TSourceLoadMode LoadMode = {read=FLoadMode, write=FLoadMode, default=0};
	__property TChartSeries* Series = {read=FSeries, write=SetSeries};
};


typedef TMetaClass*TTeeSeriesSourceClass;

//-- var, const, procedure ---------------------------------------------------
static const int ChartMarkColor = 0x80000018;
extern PACKAGE double MinAxisIncrement;
extern PACKAGE double MinAxisRange;
static const Shortint TeeAllValues = 0xffffffff;
static const Graphics::TColor clTeeColor = 0x20000000;
static const Word ChartSamplesMax = 0x3e8;
static const Shortint TeeAutoZOrder = 0xffffffff;
static const Shortint TeeAutoDepth = 0xffffffff;
static const Shortint TeeNoPointClicked = 0xffffffff;
static const Shortint TeeDef3DPercent = 0xf;
extern PACKAGE char TeeColumnSeparator;
extern PACKAGE char TeeLineSeparator;
static const Shortint TeeInitialCustomAxis = 0x6;
static const Shortint TeeDefaultLabelsSeparation = 0xa;
extern PACKAGE bool TeeCheckMarkArrowColor;
extern PACKAGE bool TeeRandomAtRunTime;
extern PACKAGE int clTeeGallery1;
extern PACKAGE int clTeeGallery2;
extern PACKAGE int TeeAxisClickGap;
extern PACKAGE int TeeDefaultCapacity;
extern PACKAGE TeeFormatFlag __fastcall SeriesGuessContents(TChartSeries* ASeries);
extern PACKAGE AnsiString __fastcall SeriesNameOrIndex(TCustomChartSeries* ASeries);
extern PACKAGE AnsiString __fastcall SeriesTitleOrName(TCustomChartSeries* ASeries);
extern PACKAGE void __fastcall FillSeriesItems(Classes::TStrings* AItems, TCustomSeriesList* AList, bool UseTitles = true);
extern PACKAGE Classes::TList* __fastcall TeeSources(void);
extern PACKAGE void __fastcall ShowMessageUser(const AnsiString S);
extern PACKAGE bool __fastcall HasNoMandatoryValues(TChartSeries* ASeries);
extern PACKAGE bool __fastcall HasColors(TChartSeries* ASeries);
extern PACKAGE bool __fastcall HasLabels(TChartSeries* ASeries);
extern PACKAGE void __fastcall TeeDrawBitmapEditor(Graphics::TCanvas* Canvas, TCustomChartElement* Element, int Left, int Top);

}	/* namespace Teengine */
using namespace Teengine;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeEngine
