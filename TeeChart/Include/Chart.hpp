// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Chart.pas' rev: 6.00

#ifndef ChartHPP
#define ChartHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Chart
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomChartWall;
class PASCALIMPLEMENTATION TCustomChartWall : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	bool FAutoHide;
	bool FDark3D;
	int FEnd;
	int FSize;
	int FStart;
	bool __fastcall ApplyDark3D(void);
	void __fastcall CalcPositions(/* out */ int &ATop, /* out */ int &ABottom);
	Tecanvas::TChartPen* __fastcall GetPen(void);
	bool __fastcall HasGradient(void);
	void __fastcall InitColor(const Graphics::TColor AColor);
	bool __fastcall IsColorStored(void);
	void __fastcall SetAutoHide(const bool Value);
	void __fastcall SetDark3D(const bool Value);
	void __fastcall SetEnd(const int Value);
	HIDESBASE void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetStart(const int Value);
	Tecanvas::TTeeBlend* __fastcall TryDrawWall(const int APos1, const int APos2);
	
protected:
	Graphics::TColor DefaultColor;
	void __fastcall DoEndBlending(Tecanvas::TTeeBlend* Blend);
	bool __fastcall ShouldDraw(void);
	
public:
	__fastcall virtual TCustomChartWall(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property bool AutoHide = {read=FAutoHide, write=SetAutoHide, default=0};
	__property Color  = {stored=IsColorStored};
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property int EndPosition = {read=FEnd, write=SetEnd, default=100};
	__property Tecanvas::TChartPen* Pen = {read=GetPen, write=SetPen};
	__property int Size = {read=FSize, write=SetSize, default=0};
	__property int StartPosition = {read=FStart, write=SetStart, default=0};
	__property Transparency  = {default=0};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TCustomChartWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartWall;
class PASCALIMPLEMENTATION TChartWall : public TCustomChartWall 
{
	typedef TCustomChartWall inherited;
	
__published:
	__property AutoHide  = {default=0};
	__property Brush ;
	__property Color ;
	__property Dark3D  = {default=1};
	__property EndPosition  = {default=100};
	__property Gradient ;
	__property Pen ;
	__property Size  = {default=0};
	__property StartPosition  = {default=0};
	__property Transparency  = {default=0};
	__property Transparent ;
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomChartWall.Create */ inline __fastcall virtual TChartWall(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : TCustomChartWall(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TChartWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartLegendGradient;
class PASCALIMPLEMENTATION TChartLegendGradient : public Tecanvas::TTeeGradient 
{
	typedef Tecanvas::TTeeGradient inherited;
	
public:
	__fastcall virtual TChartLegendGradient(Classes::TNotifyEvent ChangedEvent);
	
__published:
	__property Direction  = {default=3};
	__property EndColor  = {default=16777215};
	__property StartColor  = {default=12632256};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Destroy */ inline __fastcall virtual ~TChartLegendGradient(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TLegendStyle { lsAuto, lsSeries, lsValues, lsLastValues, lsSeriesGroups };
#pragma option pop

#pragma option push -b-
enum TLegendAlignment { laLeft, laRight, laTop, laBottom };
#pragma option pop

class DELPHICLASS LegendException;
class PASCALIMPLEMENTATION LegendException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall LegendException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall LegendException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall LegendException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall LegendException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall LegendException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall LegendException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall LegendException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall LegendException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~LegendException(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TOnGetLegendText)(Teengine::TCustomAxisPanel* Sender, TLegendStyle LegendStyle, int Index, AnsiString &LegendText);

#pragma option push -b-
enum TLegendSymbolSize { lcsPercent, lcsPixels };
#pragma option pop

#pragma option push -b-
enum TLegendSymbolPosition { spLeft, spRight };
#pragma option pop

typedef void __fastcall (__closure *TSymbolDrawEvent)(System::TObject* Sender, Teengine::TChartSeries* Series, int ValueIndex, const Types::TRect &R);

typedef int __fastcall (__closure *TSymbolCalcHeight)(void);

class DELPHICLASS TLegendSymbol;
class PASCALIMPLEMENTATION TLegendSymbol : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FContinuous;
	bool FDefaultPen;
	Tecanvas::TTeeGradient* FGradient;
	TSymbolDrawEvent FOnDraw;
	Tecanvas::TChartPen* FPen;
	TLegendSymbolPosition FPosition;
	Tecanvas::TTeeShadow* FShadow;
	bool FSquared;
	bool FVisible;
	int FWidth;
	TLegendSymbolSize FWidthUnits;
	void __fastcall CanvasChanged(System::TObject* Sender);
	void __fastcall Repaint(void);
	void __fastcall SetBooleanProperty(bool &Variable, const bool Value);
	void __fastcall SetContinuous(const bool Value);
	void __fastcall SetDefaultPen(const bool Value);
	void __fastcall SetGradient(Tecanvas::TTeeGradient* Value);
	void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetPosition(const TLegendSymbolPosition Value);
	void __fastcall SetShadow(const Tecanvas::TTeeShadow* Value);
	void __fastcall SetSquared(const bool Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall SetWidthUnits(const TLegendSymbolSize Value);
	
protected:
	TSymbolCalcHeight CalcItemHeight;
	int __fastcall CalcWidth(int Value);
	void __fastcall Draw(Graphics::TColor AColor, const Types::TRect &R);
	
public:
	Teeprocs::TCustomTeePanel* Parent;
	__fastcall TLegendSymbol(Teeprocs::TCustomTeePanel* AParent);
	__fastcall virtual ~TLegendSymbol(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property bool Continuous = {read=FContinuous, write=SetContinuous, default=0};
	__property bool DefaultPen = {read=FDefaultPen, write=SetDefaultPen, default=1};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property TLegendSymbolPosition Position = {read=FPosition, write=SetPosition, default=0};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property bool Squared = {read=FSquared, write=SetSquared, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=20};
	__property TLegendSymbolSize WidthUnits = {read=FWidthUnits, write=SetWidthUnits, default=0};
	__property TSymbolDrawEvent OnDraw = {read=FOnDraw, write=FOnDraw};
};


class DELPHICLASS TTeeCustomShapePosition;
class PASCALIMPLEMENTATION TTeeCustomShapePosition : public Teeprocs::TTeeCustomShape 
{
	typedef Teeprocs::TTeeCustomShape inherited;
	
private:
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	bool __fastcall IsCustomStored(void);
	void __fastcall SetCustomPosition(const bool Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetTop(const int Value);
	
protected:
	bool FCustomPosition;
	bool DefaultCustom;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property bool CustomPosition = {read=FCustomPosition, write=SetCustomPosition, stored=IsCustomStored, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, stored=FCustomPosition, nodefault};
	__property int Top = {read=GetTop, write=SetTop, stored=FCustomPosition, nodefault};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TTeeCustomShapePosition(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : Teeprocs::TTeeCustomShape(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TTeeCustomShapePosition(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCheckBoxesStyle { cbsCheck, cbsRadio };
#pragma option pop

class DELPHICLASS TLegendTitle;
class PASCALIMPLEMENTATION TLegendTitle : public Teeprocs::TTeeShape 
{
	typedef Teeprocs::TTeeShape inherited;
	
private:
	Classes::TStringList* FText;
	Classes::TAlignment FTextAlign;
	void __fastcall CalcHeight(void);
	void __fastcall CalcShapeBounds(const Types::TRect &R);
	void __fastcall SetText(const Classes::TStringList* Value);
	void __fastcall SetTextAlign(const Classes::TAlignment Value);
	void __fastcall TextChanged(System::TObject* Sender);
	int __fastcall TotalWidth(void);
	AnsiString __fastcall GetCaption();
	void __fastcall SetCaption(const AnsiString Value);
	
protected:
	void __fastcall DrawText(void);
	
public:
	__fastcall virtual TLegendTitle(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	__fastcall virtual ~TLegendTitle(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property AnsiString Caption = {read=GetCaption, write=SetCaption};
	
__published:
	__property Classes::TStringList* Text = {read=FText, write=SetText};
	__property Classes::TAlignment TextAlignment = {read=FTextAlign, write=SetTextAlign, default=0};
	__property TextFormat  = {default=0};
	__property Visible  = {default=1};
};


class DELPHICLASS TLegendItem;
class DELPHICLASS TCustomChartLegend;
class DELPHICLASS TLegendItems;
class PASCALIMPLEMENTATION TLegendItems : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TLegendItem* operator[](int Index) { return Items[Index]; }
	
private:
	bool FCustom;
	TCustomChartLegend* ILegend;
	void __fastcall ClearItems(void);
	HIDESBASE TLegendItem* __fastcall Get(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property bool Custom = {read=FCustom, write=FCustom, nodefault};
	__property TLegendItem* Items[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TLegendItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TLegendItems(void) : Classes::TList() { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TLegendCalcSize)(TCustomChartLegend* Sender, int &ASize);

class PASCALIMPLEMENTATION TCustomChartLegend : public TTeeCustomShapePosition 
{
	typedef TTeeCustomShapePosition inherited;
	
public:
	TLegendItem* operator[](int Index) { return Item[Index]; }
	
private:
	TLegendAlignment FAlignment;
	bool FCheckBoxes;
	TCheckBoxesStyle FCheckBoxesStyle;
	bool FCurrentPage;
	Tecanvas::TChartHiddenPen* FDividingLines;
	int FFirstValue;
	bool FFontSeriesColor;
	int FHorizMargin;
	bool FInverted;
	TLegendItems* FItems;
	int FLeftPercent;
	TLegendStyle FLegendStyle;
	int FMaxNumRows;
	Teeprocs::TTeeUnits FPosUnits;
	bool FResizeChart;
	Teengine::TChartSeries* FSeries;
	TLegendSymbol* FSymbol;
	Teengine::TLegendTextStyle FTextStyle;
	TLegendTitle* FTitle;
	int FTopLeftPos;
	int FTopPercent;
	int FVertMargin;
	int FVertSpacing;
	int IColorWidth;
	int ILastValue;
	int ITotalItems;
	bool IDrawTitle;
	int __fastcall CalcItemHeight(void);
	int __fastcall FirstItemTop(void);
	TLegendItem* __fastcall GetItem(int Index);
	Teengine::TChartSeries* __fastcall GetLegendSeries(void);
	Types::TRect __fastcall GetRectLegend();
	int __fastcall GetSymbolWidth(void);
	bool __fastcall GetVertical(void);
	bool __fastcall HasCheckBoxes(void);
	void __fastcall PrepareSymbolPen(void);
	void __fastcall SetAlignment(const TLegendAlignment Value);
	void __fastcall SetCheckBoxes(const bool Value);
	void __fastcall SetCheckBoxesStyle(const TCheckBoxesStyle Value);
	void __fastcall SetCurrentPage(const bool Value);
	void __fastcall SetDividingLines(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetFirstValue(const int Value);
	void __fastcall SetFontSeriesColor(const bool Value);
	void __fastcall SetHorizMargin(const int Value);
	void __fastcall SetInverted(const bool Value);
	void __fastcall SetLeftPercent(const int Value);
	void __fastcall SetLegendStyle(const TLegendStyle Value);
	void __fastcall SetMaxNumRows(const int Value);
	void __fastcall SetPosUnits(const Teeprocs::TTeeUnits Value);
	void __fastcall SetResizeChart(const bool Value);
	void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	void __fastcall SetSymbol(const TLegendSymbol* Value);
	void __fastcall SetSymbolWidth(const int Value);
	void __fastcall SetTextStyle(const Teengine::TLegendTextStyle Value);
	void __fastcall SetTitle(const TLegendTitle* Value);
	void __fastcall SetTopLeftPos(const int Value);
	void __fastcall SetTopPercent(const int Value);
	void __fastcall SetVertMargin(const int Value);
	void __fastcall SetVertSpacing(const int Value);
	
protected:
	TLegendStyle InternalLegendStyle;
	TLegendCalcSize FOnCalcSize;
	void __fastcall CalcLegendStyle(void);
	bool __fastcall DoMouseDown(const int x, const int y, int PointIndex);
	DYNAMIC TMetaClass* __fastcall GetGradientClass(void);
	
public:
	int NumCols;
	int NumRows;
	bool ColumnWidthAuto;
	int ColumnWidths[2];
	__fastcall virtual TCustomChartLegend(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	__fastcall virtual ~TCustomChartLegend(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall Clicked(int x, int y);
	void __fastcall DrawLegend(void);
	AnsiString __fastcall FormattedValue(Teengine::TChartSeries* ASeries, int ValueIndex);
	AnsiString __fastcall FormattedLegend(int Index);
	bool __fastcall ShouldDraw(void);
	__property int TotalLegendItems = {read=ITotalItems, nodefault};
	__property Types::TRect RectLegend = {read=GetRectLegend};
	__property bool Vertical = {read=GetVertical, nodefault};
	__property TLegendAlignment Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property bool CheckBoxes = {read=FCheckBoxes, write=SetCheckBoxes, default=0};
	__property TCheckBoxesStyle CheckBoxesStyle = {read=FCheckBoxesStyle, write=SetCheckBoxesStyle, default=0};
	__property int ColorWidth = {read=GetSymbolWidth, write=SetSymbolWidth, default=20};
	__property bool CurrentPage = {read=FCurrentPage, write=SetCurrentPage, default=1};
	__property Tecanvas::TChartHiddenPen* DividingLines = {read=FDividingLines, write=SetDividingLines};
	__property int FirstValue = {read=FFirstValue, write=SetFirstValue, default=0};
	__property bool FontSeriesColor = {read=FFontSeriesColor, write=SetFontSeriesColor, default=0};
	__property int HorizMargin = {read=FHorizMargin, write=SetHorizMargin, default=0};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=0};
	__property TLegendItem* Item[int Index] = {read=GetItem/*, default*/};
	__property TLegendItems* Items = {read=FItems};
	__property int LastValue = {read=ILastValue, nodefault};
	__property int LeftPercent = {read=FLeftPercent, write=SetLeftPercent, default=0};
	__property TLegendStyle LegendStyle = {read=FLegendStyle, write=SetLegendStyle, default=0};
	__property int MaxNumRows = {read=FMaxNumRows, write=SetMaxNumRows, default=10};
	__property Teeprocs::TTeeUnits PositionUnits = {read=FPosUnits, write=SetPosUnits, default=1};
	__property bool ResizeChart = {read=FResizeChart, write=SetResizeChart, default=1};
	__property Teengine::TChartSeries* Series = {read=FSeries, write=SetSeries};
	__property TLegendSymbol* Symbol = {read=FSymbol, write=SetSymbol};
	__property Teengine::TLegendTextStyle TextStyle = {read=FTextStyle, write=SetTextStyle, default=1};
	__property TLegendTitle* Title = {read=FTitle, write=SetTitle};
	__property int TopPercent = {read=FTopPercent, write=SetTopPercent, default=0};
	__property int TopPos = {read=FTopLeftPos, write=SetTopLeftPos, default=10};
	__property int VertMargin = {read=FVertMargin, write=SetVertMargin, default=0};
	__property int VertSpacing = {read=FVertSpacing, write=SetVertSpacing, default=0};
	__property Visible  = {default=1};
};


class PASCALIMPLEMENTATION TLegendItem : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FAlign;
	int FLeft;
	#pragma pack(push, 1)
	Types::TRect FSymbol;
	#pragma pack(pop)
	
	AnsiString FText;
	AnsiString FText2;
	int FTop;
	TCustomChartLegend* ILegend;
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetText2(const AnsiString Value);
	void __fastcall SetTextVariable(AnsiString &Variable, const AnsiString Value);
	
public:
	__property Types::TRect SymbolRect = {read=FSymbol, write=FSymbol};
	
__published:
	__property int Align = {read=FAlign, nodefault};
	__property int Left = {read=FLeft, nodefault};
	__property AnsiString Text = {read=FText, write=SetText};
	__property AnsiString Text2 = {read=FText2, write=SetText2};
	__property int Top = {read=FTop, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TLegendItem(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TLegendItem(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TChartLegend;
class PASCALIMPLEMENTATION TChartLegend : public TCustomChartLegend 
{
	typedef TCustomChartLegend inherited;
	
__published:
	__property Alignment  = {default=1};
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Brush ;
	__property CheckBoxes  = {default=0};
	__property CheckBoxesStyle  = {default=0};
	__property Color  = {default=16777215};
	__property ColorWidth  = {default=20};
	__property CurrentPage  = {default=1};
	__property CustomPosition ;
	__property DividingLines ;
	__property FirstValue  = {default=0};
	__property Font ;
	__property FontSeriesColor  = {default=0};
	__property Frame ;
	__property Gradient ;
	__property HorizMargin  = {default=0};
	__property Inverted  = {default=0};
	__property Left ;
	__property LeftPercent  = {default=0};
	__property LegendStyle  = {default=0};
	__property MaxNumRows  = {default=10};
	__property Picture ;
	__property PositionUnits  = {default=1};
	__property ResizeChart  = {default=1};
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property Symbol ;
	__property TextStyle  = {default=1};
	__property Title ;
	__property Top ;
	__property TopPercent  = {default=0};
	__property TopPos  = {default=10};
	__property Transparency  = {default=0};
	__property Transparent ;
	__property VertMargin  = {default=0};
	__property VertSpacing  = {default=0};
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomChartLegend.Create */ inline __fastcall virtual TChartLegend(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : TCustomChartLegend(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartLegend.Destroy */ inline __fastcall virtual ~TChartLegend(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartTitle;
class PASCALIMPLEMENTATION TChartTitle : public TTeeCustomShapePosition 
{
	typedef TTeeCustomShapePosition inherited;
	
private:
	bool FAdjustFrame;
	Classes::TAlignment FAlignment;
	Classes::TStrings* FText;
	int FVertMargin;
	bool IOnTop;
	AnsiString __fastcall GetCaption();
	Types::TRect __fastcall GetShapeBounds();
	void __fastcall SetAdjustFrame(bool Value);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetText(Classes::TStrings* Value);
	void __fastcall SetVertMargin(const int Value);
	
public:
	__fastcall virtual TChartTitle(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	__fastcall virtual ~TChartTitle(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	bool __fastcall Clicked(int x, int y);
	void __fastcall DrawTitle(void);
	__property AnsiString Caption = {read=GetCaption, write=SetCaption};
	__property Types::TRect TitleRect = {read=GetShapeBounds};
	
__published:
	__property bool AdjustFrame = {read=FAdjustFrame, write=SetAdjustFrame, default=1};
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
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
	__property Classes::TStrings* Text = {read=FText, write=SetText};
	__property TextFormat  = {default=0};
	__property Top ;
	__property Transparency  = {default=0};
	__property Transparent  = {default=1};
	__property int VertMargin = {read=FVertMargin, write=SetVertMargin, default=5};
	__property Visible  = {default=1};
};


class DELPHICLASS TChartFootTitle;
class PASCALIMPLEMENTATION TChartFootTitle : public TChartTitle 
{
	typedef TChartTitle inherited;
	
public:
	__fastcall virtual TChartFootTitle(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
public:
	#pragma option push -w-inl
	/* TChartTitle.Destroy */ inline __fastcall virtual ~TChartFootTitle(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomChart;
typedef void __fastcall (__closure *TChartClick)(TCustomChart* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TChartClickAxis)(TCustomChart* Sender, Teengine::TChartAxis* Axis, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TChartClickSeries)(TCustomChart* Sender, Teengine::TChartSeries* Series, int ValueIndex, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TChartClickTitle)(TCustomChart* Sender, TChartTitle* ATitle, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TOnGetLegendPos)(TCustomChart* Sender, int Index, int &X, int &Y, int &XColor);

typedef void __fastcall (__closure *TOnGetLegendRect)(TCustomChart* Sender, Types::TRect &Rect);

struct TAxisSavedScales
{
	bool Auto;
	bool AutoMin;
	bool AutoMax;
	double Min;
	double Max;
} ;

typedef DynamicArray<TAxisSavedScales >  TAllAxisSavedScales;

class DELPHICLASS TChartBackWall;
class PASCALIMPLEMENTATION TChartBackWall : public TChartWall 
{
	typedef TChartWall inherited;
	
public:
	__fastcall virtual TChartBackWall(Teeprocs::TCustomTeePanel* AOwner)/* overload */;
	
__published:
	__property Color  = {default=12632256};
	__property Picture ;
	__property Shadow ;
	__property Transparent  = {default=1};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TChartBackWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartRightWall;
class PASCALIMPLEMENTATION TChartRightWall : public TChartWall 
{
	typedef TChartWall inherited;
	
__published:
	__property Color  = {default=12632256};
	__property Picture ;
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomChartWall.Create */ inline __fastcall virtual TChartRightWall(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : TChartWall(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TChartRightWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartBottomWall;
class PASCALIMPLEMENTATION TChartBottomWall : public TChartWall 
{
	typedef TChartWall inherited;
	
__published:
	__property Picture ;
public:
	#pragma option push -w-inl
	/* TCustomChartWall.Create */ inline __fastcall virtual TChartBottomWall(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : TChartWall(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TChartBottomWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartLeftWall;
class PASCALIMPLEMENTATION TChartLeftWall : public TChartWall 
{
	typedef TChartWall inherited;
	
__published:
	__property Picture ;
public:
	#pragma option push -w-inl
	/* TCustomChartWall.Create */ inline __fastcall virtual TChartLeftWall(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : TChartWall(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TChartLeftWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartWalls;
class PASCALIMPLEMENTATION TChartWalls : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TChartBackWall* FBack;
	TChartBottomWall* FBottom;
	TCustomChart* FChart;
	TChartLeftWall* FLeft;
	TChartRightWall* FRight;
	bool __fastcall GetVisible(void);
	void __fastcall SetBack(const TChartBackWall* Value);
	void __fastcall SetBottom(const TChartBottomWall* Value);
	void __fastcall SetLeft(const TChartLeftWall* Value);
	void __fastcall SetRight(const TChartRightWall* Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetVisible(const bool Value);
	
public:
	__fastcall TChartWalls(TCustomChart* Chart);
	__fastcall virtual ~TChartWalls(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TChartBackWall* Back = {read=FBack, write=SetBack};
	__property TChartBottomWall* Bottom = {read=FBottom, write=SetBottom};
	__property TChartLeftWall* Left = {read=FLeft, write=SetLeft};
	__property TChartRightWall* Right = {read=FRight, write=SetRight};
	__property int Size = {write=SetSize, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
};


typedef void __fastcall (__closure *TChartAllowScrollEvent)(Teengine::TChartAxis* Sender, double &AMin, double &AMax, bool &AllowScroll);

class PASCALIMPLEMENTATION TCustomChart : public Teengine::TCustomAxisPanel 
{
	typedef Teengine::TCustomAxisPanel inherited;
	
private:
	int FColorPaletteIndex;
	TChartTitle* FFoot;
	TChartLegend* FLegend;
	DynamicArray<TAxisSavedScales >  FSavedScales;
	Controls::TMouseButton FScrollMouse;
	TChartTitle* FSubFoot;
	TChartTitle* FSubTitle;
	TChartTitle* FTitle;
	TChartWalls* FWalls;
	TChartAllowScrollEvent FOnAllowScroll;
	TChartClickAxis FOnClickAxis;
	TChartClick FOnClickBackGround;
	TChartClick FOnClickLegend;
	TChartClickSeries FOnClickSeries;
	TChartClickTitle FOnClickTitle;
	TOnGetLegendPos FOnGetLegendPos;
	TOnGetLegendRect FOnGetLegendRect;
	TOnGetLegendText FOnGetLegendText;
	bool __fastcall ActiveSeriesUseAxis(void);
	HIDESBASE void __fastcall BroadcastMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall BroadcastWheelEvent(Teengine::TWheelMouseEvent AEvent, int WheelDelta, int X, int Y);
	Teengine::TChartClickedPart __fastcall CalcNeedClickedPart(const Types::TPoint &Pos, bool Needed);
	bool __fastcall CanWheelScroll(void);
	void __fastcall DrawBackWall(void);
	void __fastcall DrawLeftWall(void);
	void __fastcall DrawRightWall(void);
	bool __fastcall DrawWallFirst(int APos);
	TChartBackWall* __fastcall GetBackWall(void);
	TChartBottomWall* __fastcall GetBottomWall(void);
	Tecanvas::TChartPen* __fastcall GetFrame(void);
	TChartLeftWall* __fastcall GetLeftWall(void);
	TChartRightWall* __fastcall GetRightWall(void);
	void __fastcall PrepareWallCanvas(TChartWall* AWall);
	void __fastcall ReadBackColor(Classes::TReader* Reader);
	void __fastcall ReadColorPalette(Classes::TReader* Reader);
	void __fastcall RestoreScales(TAllAxisSavedScales &Saved);
	TAllAxisSavedScales __fastcall SaveScales();
	void __fastcall ScrollVerticalAxes(bool Up);
	void __fastcall SetBackColor(Graphics::TColor Value);
	void __fastcall SetBackWall(TChartBackWall* Value);
	void __fastcall SetBottomWall(TChartBottomWall* Value);
	void __fastcall SetColorPaletteIndex(const int Value);
	void __fastcall SetFoot(TChartTitle* Value);
	void __fastcall SetFrame(Tecanvas::TChartPen* Value);
	void __fastcall SetLeftWall(TChartLeftWall* Value);
	void __fastcall SetLegend(TChartLegend* Value);
	void __fastcall SetRightWall(TChartRightWall* Value);
	void __fastcall SetSubFoot(const TChartTitle* Value);
	void __fastcall SetSubTitle(const TChartTitle* Value);
	void __fastcall SetTitle(TChartTitle* Value);
	void __fastcall SetWalls(TChartWalls* Value);
	void __fastcall WriteColorPalette(Classes::TWriter* Writer);
	void __fastcall SetScrollMouseButton(const Controls::TMouseButton Value);
	
protected:
	bool RestoredAxisScales;
	virtual void __fastcall CalcWallsRect(void);
	virtual int __fastcall CalcWallSize(Teengine::TChartAxis* Axis);
	DYNAMIC void __fastcall CalcZoomPoints(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	void __fastcall DoZoom(const double TopI, const double TopF, const double BotI, const double BotF, const double LefI, const double LefF, const double RigI, const double RigF);
	bool __fastcall DrawLeftWallFirst(void);
	bool __fastcall DrawRightWallAfter(void);
	virtual void __fastcall DrawLegendShape(const Types::TRect &Rect);
	virtual void __fastcall DrawTitlesAndLegend(bool BeforeSeries);
	virtual void __fastcall DrawWalls(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	AnsiString __fastcall InternalFormattedLegend(TCustomChartLegend* ALegend, int SeriesOrValueIndex);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual TCustomChart(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomChart(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	AnsiString __fastcall AxisTitleOrName(Teengine::TChartAxis* Axis);
	void __fastcall CalcClickedPart(const Types::TPoint &Pos, Teengine::TChartClickedPart &Part);
	DYNAMIC void __fastcall FillSeriesSourceItems(Teengine::TChartSeries* ASeries, Classes::TGetStrProc Proc);
	DYNAMIC void __fastcall FillValueSourceItems(Teengine::TChartValueList* ValueList, Classes::TGetStrProc Proc);
	Teengine::TChartSeries* __fastcall GetASeries(void);
	virtual bool __fastcall IsFreeSeriesColor(Graphics::TColor AColor, bool CheckBackground, Teengine::TChartSeries* ASeries = (Teengine::TChartSeries*)(0x0));
	void __fastcall NextPage(void);
	void __fastcall PreviousPage(void);
	void __fastcall RemoveAllSeries(void);
	void __fastcall ClearChart(void);
	void __fastcall SeriesDown(Teengine::TChartSeries* ASeries);
	void __fastcall SeriesUp(Teengine::TChartSeries* ASeries);
	DYNAMIC void __fastcall UndoZoom(void);
	void __fastcall ZoomPercent(const double PercentZoom);
	void __fastcall ZoomRect(const Types::TRect &Rect);
	virtual AnsiString __fastcall FormattedValueLegend(Teengine::TChartSeries* ASeries, int ValueIndex);
	AnsiString __fastcall FormattedLegend(int SeriesOrValueIndex);
	__property Graphics::TColor BackColor = {read=GetBackColor, write=SetBackColor, nodefault};
	__property int ColorPaletteIndex = {read=FColorPaletteIndex, write=SetColorPaletteIndex, nodefault};
	__property TChartWalls* Walls = {read=FWalls, write=SetWalls};
	__property TChartBackWall* BackWall = {read=GetBackWall, write=SetBackWall};
	__property Tecanvas::TChartPen* Frame = {read=GetFrame, write=SetFrame};
	__property TChartBottomWall* BottomWall = {read=GetBottomWall, write=SetBottomWall};
	__property TChartTitle* Foot = {read=FFoot, write=SetFoot};
	__property TChartLeftWall* LeftWall = {read=GetLeftWall, write=SetLeftWall};
	__property TChartLegend* Legend = {read=FLegend, write=SetLegend};
	__property TChartRightWall* RightWall = {read=GetRightWall, write=SetRightWall};
	__property Controls::TMouseButton ScrollMouseButton = {read=FScrollMouse, write=SetScrollMouseButton, default=1};
	__property TChartTitle* SubFoot = {read=FSubFoot, write=SetSubFoot};
	__property TChartTitle* SubTitle = {read=FSubTitle, write=SetSubTitle};
	__property TChartTitle* Title = {read=FTitle, write=SetTitle};
	__property TChartAllowScrollEvent OnAllowScroll = {read=FOnAllowScroll, write=FOnAllowScroll};
	__property TChartClickAxis OnClickAxis = {read=FOnClickAxis, write=FOnClickAxis};
	__property TChartClick OnClickBackground = {read=FOnClickBackGround, write=FOnClickBackGround};
	__property TChartClick OnClickLegend = {read=FOnClickLegend, write=FOnClickLegend};
	__property TChartClickSeries OnClickSeries = {read=FOnClickSeries, write=FOnClickSeries};
	__property TChartClickTitle OnClickTitle = {read=FOnClickTitle, write=FOnClickTitle};
	__property TOnGetLegendPos OnGetLegendPos = {read=FOnGetLegendPos, write=FOnGetLegendPos};
	__property TOnGetLegendRect OnGetLegendRect = {read=FOnGetLegendRect, write=FOnGetLegendRect};
	__property TOnGetLegendText OnGetLegendText = {read=FOnGetLegendText, write=FOnGetLegendText};
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property Color  = {default=-2147483633};
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
	/* TWinControl.CreateParented */ inline __fastcall TCustomChart(HWND ParentWindow) : Teengine::TCustomAxisPanel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TChart;
class PASCALIMPLEMENTATION TChart : public TCustomChart 
{
	typedef TCustomChart inherited;
	
public:
	__property DockManager ;
	
__published:
	__property AllowPanning  = {default=3};
	__property BackImage ;
	__property BackImageInside  = {default=0};
	__property BackImageMode  = {default=0};
	__property BackImageTransp  = {default=0};
	__property BackWall ;
	__property Border ;
	__property BorderRound  = {default=0};
	__property BottomWall ;
	__property Foot ;
	__property Gradient ;
	__property LeftWall ;
	__property Legend ;
	__property MarginBottom  = {index=3, default=4};
	__property MarginLeft  = {index=0, default=3};
	__property MarginRight  = {index=2, default=3};
	__property MarginTop  = {index=1, default=4};
	__property MarginUnits  = {default=0};
	__property PrintProportional  = {default=1};
	__property RightWall ;
	__property ScrollMouseButton  = {default=1};
	__property SubFoot ;
	__property SubTitle ;
	__property Title ;
	__property OnAllowScroll ;
	__property OnClickAxis ;
	__property OnClickBackground ;
	__property OnClickLegend ;
	__property OnClickSeries ;
	__property OnClickTitle ;
	__property OnGetLegendPos ;
	__property OnGetLegendRect ;
	__property OnScroll ;
	__property OnUndoZoom ;
	__property OnZoom ;
	__property AxisBehind  = {default=1};
	__property AxisVisible  = {default=1};
	__property BottomAxis ;
	__property Chart3DPercent  = {default=15};
	__property ClipPoints  = {default=1};
	__property DepthAxis ;
	__property DepthTopAxis ;
	__property CustomAxes ;
	__property Frame ;
	__property LeftAxis ;
	__property Monochrome  = {default=0};
	__property Pages ;
	__property RightAxis ;
	__property SeriesGroups ;
	__property SeriesList ;
	__property Shadow ;
	__property Tools ;
	__property TopAxis ;
	__property View3D  = {default=1};
	__property View3DOptions ;
	__property View3DWalls  = {default=1};
	__property Zoom ;
	__property OnAddSeries ;
	__property OnAfterDraw ;
	__property OnBeforeDrawAxes ;
	__property OnBeforeDrawChart ;
	__property OnBeforeDrawSeries ;
	__property OnBeforePrint ;
	__property OnGetAxisLabel ;
	__property OnGetLegendText ;
	__property OnGetNextAxisLabel ;
	__property OnPageChange ;
	__property OnRemoveSeries ;
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property Color  = {default=-2147483633};
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
	__property OnCanResize ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnConstrainedResize ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnEndDock ;
	__property OnGetSiteInfo ;
	__property OnStartDock ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomChart.Create */ inline __fastcall virtual TChart(Classes::TComponent* AOwner) : TCustomChart(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChart.Destroy */ inline __fastcall virtual ~TChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChart(HWND ParentWindow) : TCustomChart(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeSeriesTypes;
class PASCALIMPLEMENTATION TTeeSeriesTypes : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	Teengine::TTeeSeriesType* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE Teengine::TTeeSeriesType* __fastcall Get(int Index);
	
public:
	virtual void __fastcall Clear(void);
	Teengine::TTeeSeriesType* __fastcall Find(TMetaClass* ASeriesClass);
	__property Teengine::TTeeSeriesType* Items[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TTeeSeriesTypes(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeSeriesTypes(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TTeeToolTypes;
class PASCALIMPLEMENTATION TTeeToolTypes : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TMetaClass* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TMetaClass* __fastcall Get(int Index);
	
public:
	__property TMetaClass* Items[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TTeeToolTypes(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeToolTypes(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TTeeDragObject;
class PASCALIMPLEMENTATION TTeeDragObject : public Controls::TDragObject 
{
	typedef Controls::TDragObject inherited;
	
private:
	#pragma pack(push, 1)
	Teengine::TChartClickedPart FPart;
	#pragma pack(pop)
	
	
protected:
	virtual Controls::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	
public:
	__fastcall TTeeDragObject(const Teengine::TChartClickedPart &APart);
	__property Teengine::TChartClickedPart Part = {read=FPart};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeDragObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TColorPalettes;
class PASCALIMPLEMENTATION TColorPalettes : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
public:
	/*         class method */ static void __fastcall AddTo(TMetaClass* vmt, const Classes::TStrings* Items, bool AddDefault = false);
	/*         class method */ static void __fastcall ApplyPalette(TMetaClass* vmt, Teengine::TCustomAxisPanel* Chart, int Index)/* overload */;
	/*         class method */ static void __fastcall ApplyPalette(TMetaClass* vmt, Teengine::TCustomAxisPanel* Chart, const Graphics::TColor * Palette, const int Palette_Size)/* overload */;
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TColorPalettes(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TColorPalettes(void) : Classes::TStringList() { }
	#pragma option pop
	
};


class DELPHICLASS TChartTheme;
class PASCALIMPLEMENTATION TChartTheme : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	
public:
	TCustomChart* Chart;
	__fastcall virtual TChartTheme(TCustomChart* AChart);
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TChartTheme(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TChartThemeClass;

typedef TMetaClass* __fastcall (*TTeeThemeSelectorProc)(TCustomChart* Chart);

typedef TMetaClass*TCanvasClass;

//-- var, const, procedure ---------------------------------------------------
#define TeeMsg_DefaultFunctionName "TeeFunction"
#define TeeMsg_DefaultSeriesName "Series"
#define TeeMsg_DefaultToolName "ChartTool"
#define ChartComponentPalette "TeeChart"
static const Shortint TeeMaxLegendColumns = 0x2;
static const Shortint TeeDefaultLegendSymbolWidth = 0x14;
static const Shortint TeeTitleFootDistance = 0x5;
extern PACKAGE double AnimatedZoomFactor;
extern PACKAGE Classes::TShiftState TeeScrollKeyShift;
extern PACKAGE bool TeeUseMouseWheel;
extern PACKAGE TColorPalettes* ColorPalettes;
extern PACKAGE TTeeSeriesTypes* TeeSeriesTypes;
extern PACKAGE TTeeToolTypes* TeeToolTypes;
extern PACKAGE TMetaClass*TeePageNumToolClass;
extern PACKAGE TTeeThemeSelectorProc TeeThemeSelectorHook;
extern PACKAGE TTeeThemeSelectorProc TeeNewChartHook;
extern PACKAGE TMetaClass*TeeAntiAliasCanvas;
extern PACKAGE Graphics::TColor ExcelPalette[22];
extern PACKAGE Graphics::TColor VictorianPalette[11];
extern PACKAGE Graphics::TColor PastelsPalette[14];
extern PACKAGE Graphics::TColor SolidPalette[8];
extern PACKAGE Graphics::TColor ClassicPalette[12];
extern PACKAGE Graphics::TColor WebPalette[9];
extern PACKAGE Graphics::TColor ModernPalette[14];
extern PACKAGE Graphics::TColor RainbowPalette[25];
extern PACKAGE Graphics::TColor WindowsXPPalette[13];
extern PACKAGE Graphics::TColor MacOSPalette[16];
extern PACKAGE Graphics::TColor WindowsVistaPalette[15];
extern PACKAGE Graphics::TColor GrayScalePalette[15];
extern PACKAGE Graphics::TColor OperaPalette[12];
extern PACKAGE Graphics::TColor WarmPalette[8];
extern PACKAGE Graphics::TColor CoolPalette[8];
extern PACKAGE void __fastcall PaintSeriesLegend(Teengine::TChartSeries* ASeries, Graphics::TCanvas* ACanvas, const Types::TRect &R, TCustomChart* ReferenceChart = (TCustomChart*)(0x0));
extern PACKAGE AnsiString __fastcall GetNewSeriesName(Classes::TComponent* AOwner);
extern PACKAGE void __fastcall AssignSeries(Teengine::TChartSeries* &OldSeries, Teengine::TChartSeries* &NewSeries);
extern PACKAGE Teengine::TTeeFunction* __fastcall CreateNewTeeFunction(Teengine::TChartSeries* ASeries, TMetaClass* AClass);
extern PACKAGE Teengine::TChartSeries* __fastcall CreateNewSeries(Classes::TComponent* AOwner, Teengine::TCustomAxisPanel* AChart, TMetaClass* AClass, TMetaClass* AFunctionClass = 0x0);
extern PACKAGE Teengine::TChartSeries* __fastcall CloneChartSeries(Teengine::TChartSeries* ASeries)/* overload */;
extern PACKAGE Teengine::TChartSeries* __fastcall CloneChartSeries(Teengine::TChartSeries* ASeries, Teengine::TCustomAxisPanel* AChart)/* overload */;
extern PACKAGE Teengine::TChartSeries* __fastcall CloneChartSeries(Teengine::TChartSeries* ASeries, Classes::TComponent* AOwner, Teengine::TCustomAxisPanel* AChart)/* overload */;
extern PACKAGE Teengine::TTeeCustomTool* __fastcall CloneChartTool(Teengine::TTeeCustomTool* ATool, Classes::TComponent* AOwner);
extern PACKAGE Teengine::TChartSeries* __fastcall ChangeSeriesType(Teengine::TChartSeries* &ASeries, TMetaClass* NewType);
extern PACKAGE void __fastcall ChangeAllSeriesType(TCustomChart* AChart, TMetaClass* AClass);
extern PACKAGE void __fastcall RegisterTeeSeriesFunction(TMetaClass* ASeriesClass, TMetaClass* AFunctionClass, System::PAnsiString ADescription, System::PAnsiString AGalleryPage, int ANumGallerySeries = 0x1, int ASubIndex = 0x0);
extern PACKAGE void __fastcall RegisterTeeSeries(TMetaClass* ASeriesClass, System::PAnsiString ADescription, System::PAnsiString AGalleryPage, int ANumGallerySeries)/* overload */;
extern PACKAGE void __fastcall RegisterTeeSeries(TMetaClass* ASeriesClass, System::PAnsiString ADescription)/* overload */;
extern PACKAGE void __fastcall RegisterTeeFunction(TMetaClass* AFunctionClass, System::PAnsiString ADescription, System::PAnsiString AGalleryPage, int ANumGallerySeries = 0x1);
extern PACKAGE void __fastcall RegisterTeeBasicFunction(TMetaClass* AFunctionClass, System::PAnsiString ADescription);
extern PACKAGE void __fastcall UnRegisterTeeSeries(TMetaClass* * ASeriesList, const int ASeriesList_Size);
extern PACKAGE void __fastcall UnRegisterTeeFunctions(TMetaClass* * AFunctionList, const int AFunctionList_Size);
extern PACKAGE void __fastcall RegisterTeeTools(TMetaClass* const * ATools, const int ATools_Size);
extern PACKAGE void __fastcall UnRegisterTeeTools(TMetaClass* const * ATools, const int ATools_Size);
extern PACKAGE AnsiString __fastcall GetGallerySeriesName(Teengine::TChartSeries* ASeries);

}	/* namespace Chart */
using namespace Chart;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Chart
