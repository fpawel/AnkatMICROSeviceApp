// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeProcs.pas' rev: 6.00

#ifndef TeeProcsHPP
#define TeeProcsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeprocs
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDateTimeStep { dtOneMicroSecond, dtOneMillisecond, dtOneSecond, dtFiveSeconds, dtTenSeconds, dtFifteenSeconds, dtThirtySeconds, dtOneMinute, dtFiveMinutes, dtTenMinutes, dtFifteenMinutes, dtThirtyMinutes, dtOneHour, dtTwoHours, dtSixHours, dtTwelveHours, dtOneDay, dtTwoDays, dtThreeDays, dtOneWeek, dtHalfMonth, dtOneMonth, dtTwoMonths, dtThreeMonths, dtFourMonths, dtSixMonths, dtOneYear, dtNone };
#pragma option pop

class DELPHICLASS TCustomPanelNoCaption;
class PASCALIMPLEMENTATION TCustomPanelNoCaption : public Extctrls::TCustomPanel 
{
	typedef Extctrls::TCustomPanel inherited;
	
public:
	__fastcall virtual TCustomPanelNoCaption(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TCustomPanelNoCaption(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomPanelNoCaption(HWND ParentWindow) : Extctrls::TCustomPanel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TZoomPanning;
class PASCALIMPLEMENTATION TZoomPanning : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FActive;
	
public:
	int X0;
	int Y0;
	int X1;
	int Y1;
	void __fastcall Check(void);
	void __fastcall Activate(int x, int y);
	__property bool Active = {read=FActive, write=FActive, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TZoomPanning(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TZoomPanning(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TTeeEvent;
class DELPHICLASS TCustomTeePanel;
#pragma option push -b-
enum TTeeUnits { muPercent, muPixels };
#pragma option pop

typedef void __fastcall (__closure *TTeePrintEvent)(TCustomTeePanel* Sender, Graphics::TCanvas* Canvas, Types::TRect &R);

class DELPHICLASS TTeeEventListeners;
__interface ITeeEventListener;
typedef System::DelphiInterface<ITeeEventListener> _di_ITeeEventListener;
class PASCALIMPLEMENTATION TTeeEventListeners : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	_di_ITeeEventListener operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE _di_ITeeEventListener __fastcall Get(int Index);
	
public:
	HIDESBASE int __fastcall Add(const _di_ITeeEventListener Item);
	HIDESBASE int __fastcall Remove(_di_ITeeEventListener Item);
	__property _di_ITeeEventListener Items[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TTeeEventListeners(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeEventListeners(void) : Classes::TList() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTeeMouseEventKind { meDown, meUp, meMove };
#pragma option pop

class PASCALIMPLEMENTATION TCustomTeePanel : public TCustomPanelNoCaption 
{
	typedef TCustomPanelNoCaption inherited;
	
private:
	bool FApplyZOrder;
	bool FAutoRepaint;
	Tecanvas::TChartHiddenPen* FBorder;
	int FBorderRound;
	bool FCancelMouse;
	#pragma pack(push, 1)
	Types::TRect FChartBounds;
	#pragma pack(pop)
	
	int FChartWidth;
	int FChartHeight;
	int FChartXCenter;
	int FChartYCenter;
	Graphics::TCanvas* FDelphiCanvas;
	int FHeight3D;
	#pragma pack(push, 1)
	Types::TRect FMargins;
	#pragma pack(pop)
	
	TTeeUnits FMarginUnits;
	TTeePrintEvent FOnBeforePrint;
	Controls::TCursor FOriginalCursor;
	TZoomPanning* FPanning;
	bool FPrinting;
	#pragma pack(push, 1)
	Types::TRect FPrintMargins;
	#pragma pack(pop)
	
	bool FPrintProportional;
	int FPrintResolution;
	Tecanvas::TTeeShadow* FShadow;
	bool FView3D;
	Tecanvas::TView3DOptions* FView3DOptions;
	int FWidth3D;
	Classes::TComponent* FGLComponent;
	TTeeEventListeners* IEventListeners;
	bool IRounding;
	void __fastcall BroadcastMouseEvent(TTeeMouseEventKind Kind, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	Forms::TBorderStyle __fastcall GetBorderStyle(void);
	bool __fastcall GetBufferedDisplay(void);
	int __fastcall GetMargin(int Index);
	bool __fastcall GetMonochrome(void);
	Types::TRect __fastcall GetPrintMargins();
	void __fastcall NonBufferDraw(Graphics::TCanvas* ACanvas, const Types::TRect &R);
	void __fastcall ReadBorderStyle(Classes::TReader* Reader);
	void __fastcall SetBorder(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetBorderRound(int Value);
	void __fastcall SetTheBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetBufferedDisplay(bool Value);
	void __fastcall SetControlRounded(void);
	void __fastcall SetMargin(int Index, int Value);
	void __fastcall SetMarginUnits(const TTeeUnits Value);
	void __fastcall SetMonochrome(bool Value);
	void __fastcall SetShadow(Tecanvas::TTeeShadow* Value);
	void __fastcall SetView3D(bool Value);
	void __fastcall SetView3DOptions(Tecanvas::TView3DOptions* Value);
	
protected:
	bool FCustomChartRect;
	Tecanvas::TCanvas3D* InternalCanvas;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	TTeeEvent* __fastcall BroadcastTeeEvent(TTeeEvent* Event);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall DblClick(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
	__property TTeeEventListeners* Listeners = {read=IEventListeners};
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	void __fastcall RemoveListener(_di_ITeeEventListener Sender);
	DYNAMIC void __fastcall Resize(void);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetColorProperty(Graphics::TColor &Variable, Graphics::TColor Value);
	void __fastcall SetDoubleProperty(double &Variable, const double Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	void __fastcall SetStringProperty(AnsiString &Variable, const AnsiString Value);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	__property Classes::TComponent* GLComponent = {read=FGLComponent, write=FGLComponent};
	
public:
	#pragma pack(push, 1)
	Types::TRect ChartRect;
	#pragma pack(pop)
	
	__fastcall virtual TCustomTeePanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTeePanel(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall CalcMetaBounds(Types::TRect &R, const Types::TRect &AChartRect, int &WinWidth, int &WinHeight, int &ViewWidth, int &ViewHeight);
	Types::TRect __fastcall CalcProportionalMargins();
	bool __fastcall CanClip(void);
	virtual void __fastcall CanvasChanged(System::TObject* Sender);
	Types::TRect __fastcall ChartPrintRect();
	void __fastcall CopyToClipboardBitmap(void)/* overload */;
	void __fastcall CopyToClipboardBitmap(const Types::TRect &R)/* overload */;
	void __fastcall CopyToClipboardMetafile(bool Enhanced)/* overload */;
	void __fastcall CopyToClipboardMetafile(bool Enhanced, const Types::TRect &R)/* overload */;
	Graphics::TBitmap* __fastcall TeeCreateBitmap(Graphics::TColor ABackColor, const Types::TRect &Rect, Graphics::TPixelFormat APixelFormat = (Graphics::TPixelFormat)(0x0))/* overload */;
	Graphics::TBitmap* __fastcall TeeCreateBitmap(void)/* overload */;
	virtual void __fastcall Draw(Graphics::TCanvas* UserCanvas, const Types::TRect &UserRect)/* overload */;
	void __fastcall Draw(void)/* overload */;
	DYNAMIC void __fastcall DrawPanelBevels(const Types::TRect &Rect);
	void __fastcall DrawToMetaCanvas(Graphics::TCanvas* ACanvas, const Types::TRect &Rect);
	Types::TPoint __fastcall GetCursorPos();
	virtual Types::TRect __fastcall GetRectangle();
	virtual void __fastcall Invalidate(void);
	bool __fastcall IsScreenHighColor(void);
	void __fastcall Print(void);
	void __fastcall PrintLandscape(void);
	void __fastcall PrintOrientation(Printers::TPrinterOrientation AOrientation);
	void __fastcall PrintPartial(const Types::TRect &PrinterRect);
	void __fastcall PrintPartialCanvas(Graphics::TCanvas* PrintCanvas, const Types::TRect &PrinterRect);
	void __fastcall PrintPortrait(void);
	void __fastcall PrintRect(const Types::TRect &R);
	void __fastcall SaveToBitmapFile(const AnsiString FileName)/* overload */;
	void __fastcall SaveToBitmapFile(const AnsiString FileName, const Types::TRect &R)/* overload */;
	void __fastcall SaveToMetafile(const AnsiString FileName);
	void __fastcall SaveToMetafileEnh(const AnsiString FileName);
	void __fastcall SaveToMetafileRect(bool Enhanced, const AnsiString FileName, const Types::TRect &Rect);
	void __fastcall SetBrushCanvas(Graphics::TColor AColor, Tecanvas::TChartBrush* ABrush, Graphics::TColor ABackColor);
	void __fastcall SetInternalCanvas(Tecanvas::TCanvas3D* NewCanvas);
	void __fastcall ReCalcWidthHeight(void);
	Graphics::TMetafile* __fastcall TeeCreateMetafile(bool Enhanced, const Types::TRect &Rect);
	__property bool ApplyZOrder = {read=FApplyZOrder, write=FApplyZOrder, nodefault};
	__property bool AutoRepaint = {read=FAutoRepaint, write=FAutoRepaint, nodefault};
	__property Tecanvas::TChartHiddenPen* Border = {read=FBorder, write=SetBorder};
	__property int BorderRound = {read=FBorderRound, write=SetBorderRound, default=0};
	__property Forms::TBorderStyle BorderStyle = {read=GetBorderStyle, write=SetTheBorderStyle, nodefault};
	__property bool BufferedDisplay = {read=GetBufferedDisplay, write=SetBufferedDisplay, nodefault};
	__property bool CancelMouse = {read=FCancelMouse, write=FCancelMouse, nodefault};
	__property Tecanvas::TCanvas3D* Canvas = {read=InternalCanvas, write=SetInternalCanvas};
	__property Types::TRect ChartBounds = {read=FChartBounds};
	__property int ChartHeight = {read=FChartHeight, nodefault};
	__property int ChartWidth = {read=FChartWidth, nodefault};
	__property int ChartXCenter = {read=FChartXCenter, nodefault};
	__property int ChartYCenter = {read=FChartYCenter, nodefault};
	__property bool CustomChartRect = {read=FCustomChartRect, write=FCustomChartRect, nodefault};
	__property Graphics::TCanvas* DelphiCanvas = {read=FDelphiCanvas};
	__property int Height3D = {read=FHeight3D, write=FHeight3D, nodefault};
	__property TZoomPanning* IPanning = {read=FPanning};
	__property Controls::TCursor OriginalCursor = {read=FOriginalCursor, write=FOriginalCursor, nodefault};
	__property bool Printing = {read=FPrinting, write=FPrinting, nodefault};
	__property int Width3D = {read=FWidth3D, write=FWidth3D, nodefault};
	__property int PrintResolution = {read=FPrintResolution, write=FPrintResolution, default=0};
	__property int MarginLeft = {read=GetMargin, write=SetMargin, index=0, default=3};
	__property int MarginTop = {read=GetMargin, write=SetMargin, index=1, default=4};
	__property int MarginRight = {read=GetMargin, write=SetMargin, index=2, default=3};
	__property int MarginBottom = {read=GetMargin, write=SetMargin, index=3, default=4};
	__property TTeeUnits MarginUnits = {read=FMarginUnits, write=SetMarginUnits, default=0};
	__property bool Monochrome = {read=GetMonochrome, write=SetMonochrome, default=0};
	__property Types::TRect PrintMargins = {read=GetPrintMargins, write=FPrintMargins};
	__property bool PrintProportional = {read=FPrintProportional, write=FPrintProportional, default=1};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property bool View3D = {read=FView3D, write=SetView3D, default=1};
	__property Tecanvas::TView3DOptions* View3DOptions = {read=FView3DOptions, write=SetView3DOptions};
	__property Tecanvas::TView3DOptions* Aspect = {read=FView3DOptions, write=SetView3DOptions};
	__property Align  = {default=0};
	__property Anchors  = {default=3};
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
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TTeePrintEvent OnBeforePrint = {read=FOnBeforePrint, write=FOnBeforePrint};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTeePanel(HWND ParentWindow) : TCustomPanelNoCaption(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTeeEvent : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TCustomTeePanel* Sender;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeEvent(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeEvent(void) { }
	#pragma option pop
	
};


__interface ITeeEventListener  : public IInterface 
{
	
public:
	virtual void __fastcall TeeEvent(TTeeEvent* Event) = 0 ;
};

class DELPHICLASS TTeeMouseEvent;
class PASCALIMPLEMENTATION TTeeMouseEvent : public TTeeEvent 
{
	typedef TTeeEvent inherited;
	
public:
	TTeeMouseEventKind Event;
	Controls::TMouseButton Button;
	Classes::TShiftState Shift;
	int X;
	int Y;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeMouseEvent(void) : TTeeEvent() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeMouseEvent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeView3DEvent;
class PASCALIMPLEMENTATION TTeeView3DEvent : public TTeeEvent 
{
	typedef TTeeEvent inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeView3DEvent(void) : TTeeEvent() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeView3DEvent(void) { }
	#pragma option pop
	
};


typedef TTeeGradient TChartGradient;
;

typedef TMetaClass*TChartGradientClass;

#pragma option push -b-
enum TPanningMode { pmNone, pmHorizontal, pmVertical, pmBoth };
#pragma option pop

class DELPHICLASS TTeeZoomPen;
class PASCALIMPLEMENTATION TTeeZoomPen : public Tecanvas::TChartPen 
{
	typedef Tecanvas::TChartPen inherited;
	
private:
	bool __fastcall IsColorStored(void);
	
protected:
	Graphics::TColor DefaultColor;
	
__published:
	__property Color  = {stored=IsColorStored};
public:
	#pragma option push -w-inl
	/* TChartPen.Create */ inline __fastcall TTeeZoomPen(Classes::TNotifyEvent OnChangeEvent) : Tecanvas::TChartPen(OnChangeEvent) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TTeeZoomPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeZoomBrush;
class PASCALIMPLEMENTATION TTeeZoomBrush : public Tecanvas::TChartBrush 
{
	typedef Tecanvas::TChartBrush inherited;
	
__published:
	__property Color  = {default=16777215};
	__property Style  = {default=1};
public:
	#pragma option push -w-inl
	/* TChartBrush.Create */ inline __fastcall virtual TTeeZoomBrush(Classes::TNotifyEvent OnChangeEvent) : Tecanvas::TChartBrush(OnChangeEvent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TChartBrush.Destroy */ inline __fastcall virtual ~TTeeZoomBrush(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTeeZoomDirection { tzdHorizontal, tzdVertical, tzdBoth };
#pragma option pop

class DELPHICLASS TTeeZoom;
class PASCALIMPLEMENTATION TTeeZoom : public TZoomPanning 
{
	typedef TZoomPanning inherited;
	
private:
	bool FAllow;
	bool FAnimated;
	int FAnimatedSteps;
	TTeeZoomBrush* FBrush;
	TTeeZoomDirection FDirection;
	Classes::TShiftState FKeyShift;
	int FMinimumPixels;
	Controls::TMouseButton FMouseButton;
	TTeeZoomPen* FPen;
	bool FUpLeftZooms;
	TTeeZoomBrush* __fastcall GetBrush(void);
	TTeeZoomPen* __fastcall GetPen(void);
	void __fastcall SetBrush(TTeeZoomBrush* Value);
	void __fastcall SetPen(TTeeZoomPen* Value);
	
public:
	__fastcall TTeeZoom(void);
	__fastcall virtual ~TTeeZoom(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property bool Allow = {read=FAllow, write=FAllow, default=1};
	__property bool Animated = {read=FAnimated, write=FAnimated, default=0};
	__property int AnimatedSteps = {read=FAnimatedSteps, write=FAnimatedSteps, default=8};
	__property TTeeZoomBrush* Brush = {read=GetBrush, write=SetBrush};
	__property TTeeZoomDirection Direction = {read=FDirection, write=FDirection, default=2};
	__property Classes::TShiftState KeyShift = {read=FKeyShift, write=FKeyShift, default=0};
	__property int MinimumPixels = {read=FMinimumPixels, write=FMinimumPixels, default=16};
	__property Controls::TMouseButton MouseButton = {read=FMouseButton, write=FMouseButton, default=0};
	__property TTeeZoomPen* Pen = {read=GetPen, write=SetPen};
	__property bool UpLeftZooms = {read=FUpLeftZooms, write=FUpLeftZooms, default=0};
};


#pragma option push -b-
enum TTeeBackImageMode { pbmStretch, pbmTile, pbmCenter, pbmCustom };
#pragma option pop

class DELPHICLASS TBackImage;
class DELPHICLASS TCustomTeePanelExtended;
class PASCALIMPLEMENTATION TBackImage : public Tecanvas::TTeePicture 
{
	typedef Tecanvas::TTeePicture inherited;
	
private:
	bool FInside;
	int FLeft;
	TTeeBackImageMode FMode;
	int FTop;
	void __fastcall SetInside(const bool Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetMode(const TTeeBackImageMode Value);
	void __fastcall SetTop(int Value);
	
public:
	__fastcall TBackImage(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Draw(TCustomTeePanelExtended* Panel, const Types::TRect &Rect, int Z);
	
__published:
	__property bool Inside = {read=FInside, write=SetInside, default=0};
	__property int Left = {read=FLeft, write=SetLeft, default=0};
	__property TTeeBackImageMode Mode = {read=FMode, write=SetMode, default=0};
	__property int Top = {read=FTop, write=SetTop, default=0};
public:
	#pragma option push -w-inl
	/* TTeePicture.Destroy */ inline __fastcall virtual ~TBackImage(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomTeePanelExtended : public TCustomTeePanel 
{
	typedef TCustomTeePanel inherited;
	
private:
	TPanningMode FAllowPanning;
	Tecanvas::TTeeGradient* FGradient;
	TTeeZoom* FZoom;
	bool FZoomed;
	bool __fastcall GetAllowZoom(void);
	bool __fastcall GetAnimatedZoom(void);
	int __fastcall GetAnimatedZoomSteps(void);
	TBackImage* __fastcall GetBackImage(void);
	bool __fastcall GetBackImageInside(void);
	TTeeBackImageMode __fastcall GetBackImageMode(void);
	bool __fastcall GetBackImageTransp(void);
	Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	void __fastcall PaintBack(const Types::TRect &ARect, Graphics::TColor AColor, int BorderRound = 0x0);
	void __fastcall ReadAnimatedZoomSteps(Classes::TReader* Reader);
	void __fastcall ReadAnimatedZoom(Classes::TReader* Reader);
	void __fastcall ReadAllowZoom(Classes::TReader* Reader);
	void __fastcall ReadPrintMargins(Classes::TReader* Reader);
	void __fastcall SavePrintMargins(Classes::TWriter* Writer);
	void __fastcall SetAllowZoom(bool Value);
	void __fastcall SetAnimatedZoom(bool Value);
	void __fastcall SetAnimatedZoomSteps(int Value);
	void __fastcall SetBackImage(const TBackImage* Value);
	void __fastcall SetBackImageInside(const bool Value);
	void __fastcall SetBackImageMode(const TTeeBackImageMode Value);
	void __fastcall SetBackImageTransp(const bool Value);
	void __fastcall SetGradient(Tecanvas::TTeeGradient* Value);
	void __fastcall SetZoom(TTeeZoom* Value);
	
protected:
	TBackImage* FBackImage;
	Classes::TNotifyEvent FOnAfterDraw;
	Classes::TNotifyEvent FOnScroll;
	Classes::TNotifyEvent FOnUndoZoom;
	Classes::TNotifyEvent FOnZoom;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall DrawBitmap(const Types::TRect &Rect, int Z);
	virtual void __fastcall FillPanelRect(const Types::TRect &Rect);
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	virtual void __fastcall PanelPaint(const Types::TRect &UserRect);
	
public:
	__fastcall virtual TCustomTeePanelExtended(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTeePanelExtended(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall DrawZoomRectangle(void);
	bool __fastcall HasBackImage(void);
	DYNAMIC void __fastcall UndoZoom(void);
	__property bool Zoomed = {read=FZoomed, write=FZoomed, nodefault};
	__property TPanningMode AllowPanning = {read=FAllowPanning, write=FAllowPanning, default=3};
	__property bool AllowZoom = {read=GetAllowZoom, write=SetAllowZoom, default=1};
	__property bool AnimatedZoom = {read=GetAnimatedZoom, write=SetAnimatedZoom, default=0};
	__property int AnimatedZoomSteps = {read=GetAnimatedZoomSteps, write=SetAnimatedZoomSteps, default=8};
	__property TBackImage* BackImage = {read=GetBackImage, write=SetBackImage};
	__property bool BackImageInside = {read=GetBackImageInside, write=SetBackImageInside, default=0};
	__property TTeeBackImageMode BackImageMode = {read=GetBackImageMode, write=SetBackImageMode, default=0};
	__property bool BackImageTransp = {read=GetBackImageTransp, write=SetBackImageTransp, default=0};
	__property Tecanvas::TTeeGradient* Gradient = {read=GetGradient, write=SetGradient};
	__property TTeeZoom* Zoom = {read=FZoom, write=SetZoom};
	__property Classes::TNotifyEvent OnAfterDraw = {read=FOnAfterDraw, write=FOnAfterDraw};
	__property Classes::TNotifyEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property Classes::TNotifyEvent OnUndoZoom = {read=FOnUndoZoom, write=FOnUndoZoom};
	__property Classes::TNotifyEvent OnZoom = {read=FOnZoom, write=FOnZoom};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTeePanelExtended(HWND ParentWindow) : TCustomTeePanel(ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TChartBrushClass;

class DELPHICLASS TTeeCustomShapeBrushPen;
class PASCALIMPLEMENTATION TTeeCustomShapeBrushPen : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Tecanvas::TChartBrush* FBrush;
	TCustomTeePanel* FParent;
	Tecanvas::TChartPen* FPen;
	bool FVisible;
	void __fastcall SetBrush(Tecanvas::TChartBrush* Value);
	void __fastcall SetPen(Tecanvas::TChartPen* Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	void __fastcall CanvasChanged(System::TObject* Sender);
	DYNAMIC TMetaClass* __fastcall GetBrushClass(void);
	virtual void __fastcall SetParent(TCustomTeePanel* Value);
	
public:
	__fastcall TTeeCustomShapeBrushPen(void);
	__fastcall virtual ~TTeeCustomShapeBrushPen(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Show(void);
	void __fastcall Hide(void);
	void __fastcall Repaint(void);
	__property Tecanvas::TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Tecanvas::TChartPen* Frame = {read=FPen, write=SetPen};
	__property TCustomTeePanel* ParentChart = {read=FParent, write=SetParent};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
};


#pragma option push -b-
enum TChartObjectShapeStyle { fosRectangle, fosRoundRectangle, fosEllipse };
#pragma option pop

#pragma option push -b-
enum TTextFormat { ttfNormal, ttfHtml };
#pragma option pop

class DELPHICLASS TTeeCustomShape;
class PASCALIMPLEMENTATION TTeeCustomShape : public TTeeCustomShapeBrushPen 
{
	typedef TTeeCustomShapeBrushPen inherited;
	
private:
	Controls::TBevelCut FBevel;
	Controls::TBevelWidth FBevelWidth;
	Graphics::TColor FColor;
	Tecanvas::TTeeFont* FFont;
	int FRoundSize;
	Tecanvas::TTeeShadow* FShadow;
	TChartObjectShapeStyle FShapeStyle;
	TTextFormat FTextFormat;
	bool FTransparent;
	Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	TBackImage* __fastcall GetPicture(void);
	Graphics::TColor __fastcall GetShadowColor(void);
	int __fastcall GetShadowSize(void);
	bool __fastcall IsTranspStored(void);
	void __fastcall ReadShadowColor(Classes::TReader* Reader);
	void __fastcall ReadShadowSize(Classes::TReader* Reader);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetBevel(Controls::TBevelCut Value);
	void __fastcall SetBevelWidth(Controls::TBevelWidth Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetFont(Tecanvas::TTeeFont* Value);
	void __fastcall SetGradient(Tecanvas::TTeeGradient* Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetPicture(TBackImage* Value);
	void __fastcall SetRoundSize(int Value);
	void __fastcall SetShadow(Tecanvas::TTeeShadow* Value);
	void __fastcall SetShadowColor(Graphics::TColor Value);
	void __fastcall SetShadowSize(int Value);
	void __fastcall SetShapeStyle(TChartObjectShapeStyle Value);
	void __fastcall SetTextFormat(TTextFormat Value);
	void __fastcall SetTransparency(Tecanvas::TTeeTransparency Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetWidth(int Value);
	
protected:
	bool DefaultTransparent;
	Tecanvas::TTeeGradient* FGradient;
	TBackImage* FPicture;
	Tecanvas::TTeeTransparency FTransparency;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC TMetaClass* __fastcall GetGradientClass(void);
	DYNAMIC void __fastcall InitShadow(Tecanvas::TTeeShadow* AShadow);
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	
public:
	#pragma pack(push, 1)
	Types::TRect ShapeBounds;
	#pragma pack(pop)
	
	__fastcall virtual TTeeCustomShape(TCustomTeePanel* AOwner)/* overload */;
	__fastcall virtual ~TTeeCustomShape(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Draw(void);
	void __fastcall DrawRectRotated(const Types::TRect &Rect, int Angle = 0x0, int AZ = 0x0)/* overload */;
	void __fastcall DrawRectRotated(TCustomTeePanel* Panel, const Types::TRect &Rect, int Angle = 0x0, int AZ = 0x0)/* overload */;
	__property Graphics::TColor ShadowColor = {read=GetShadowColor, write=SetShadowColor, default=0};
	__property int ShadowSize = {read=GetShadowSize, write=SetShadowSize, default=3};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property Controls::TBevelCut Bevel = {read=FBevel, write=SetBevel, default=0};
	__property Controls::TBevelWidth BevelWidth = {read=FBevelWidth, write=SetBevelWidth, default=2};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property Tecanvas::TTeeFont* Font = {read=FFont, write=SetFont};
	__property Tecanvas::TTeeGradient* Gradient = {read=GetGradient, write=SetGradient};
	__property TBackImage* Picture = {read=GetPicture, write=SetPicture};
	__property int RoundSize = {read=FRoundSize, write=SetRoundSize, default=16};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property TChartObjectShapeStyle ShapeStyle = {read=FShapeStyle, write=SetShapeStyle, default=0};
	__property TTextFormat TextFormat = {read=FTextFormat, write=SetTextFormat, default=0};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, stored=IsTranspStored, nodefault};
};


class DELPHICLASS TTeeShape;
class PASCALIMPLEMENTATION TTeeShape : public TTeeCustomShape 
{
	typedef TTeeCustomShape inherited;
	
public:
	__property Transparency  = {default=0};
	
__published:
	__property Bevel  = {default=0};
	__property BevelWidth  = {default=2};
	__property Color  = {default=16777215};
	__property Font ;
	__property Gradient ;
	__property Picture ;
	__property RoundSize  = {default=16};
	__property Shadow ;
	__property ShapeStyle  = {default=0};
	__property Transparent ;
	__property Visible ;
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TTeeShape(TCustomTeePanel* AOwner)/* overload */ : TTeeCustomShape(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TTeeShape(void) { }
	#pragma option pop
	
};


typedef char TeeString256[256];

class DELPHICLASS TTeeExportData;
class PASCALIMPLEMENTATION TTeeExportData : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	virtual AnsiString __fastcall AsString();
	DYNAMIC void __fastcall CopyToClipboard(void);
	DYNAMIC void __fastcall SaveToFile(const AnsiString FileName);
	DYNAMIC void __fastcall SaveToStream(Classes::TStream* AStream);
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TTeeExportData(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeExportData(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


typedef int __fastcall (__closure *TTeeSortCompare)(int a, int b);

typedef void __fastcall (__closure *TTeeSortSwap)(int a, int b);

typedef DynamicArray<Graphics::TColor >  TColorArray;

typedef void __fastcall (*TTeeTranslateHook)(Controls::TControl* AControl, const Controls::TControl* * ExcludedChilds, const int ExcludedChilds_Size);

typedef AnsiString __fastcall (*TTeeTranslateStringHook)(const AnsiString Text);

typedef int TeeWindowHandle;

//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeDefVerticalMargin = 0x4;
static const Shortint TeeDefHorizMargin = 0x3;
static const Controls::TCursor crTeeHand = 0x7e4;
#define TeeMsg_TeeHand "crTeeHand"
static const Shortint TeeNormalPrintDetail = 0x0;
static const Shortint TeeHighPrintDetail = 0xffffff9c;
static const Shortint TeeDefault_PrintMargin = 0xf;
static const Shortint MaxDefaultColors = 0x13;
static const char TeeTabDelimiter = '\x9';
extern PACKAGE bool TeeClipWhenPrinting;
extern PACKAGE bool TeeClipWhenMetafiling;
extern PACKAGE bool TeeEraseBack;
extern PACKAGE bool PrintTeePanel;
extern PACKAGE double DateTimeStep[28];
extern PACKAGE AnsiString TeeFieldsSeparator;
extern PACKAGE DynamicArray<Graphics::TColor >  ColorPalette;
#define TeeBorderStyle (Forms::TFormBorderStyle)(3)
static const Shortint TeeCheckBoxSize = 0xb;
static const Shortint TeeKey_Escape = 0x1b;
static const Shortint TeeKey_Up = 0x26;
static const Shortint TeeKey_Down = 0x28;
static const Shortint TeeKey_Insert = 0x2d;
static const Shortint TeeKey_Delete = 0x2e;
static const Shortint TeeKey_Left = 0x25;
static const Shortint TeeKey_Right = 0x27;
static const Shortint TeeKey_Return = 0xd;
static const Shortint TeeKey_Space = 0x20;
static const Shortint TeeKey_Back = 0x8;
static const Shortint TeeKey_F1 = 0x70;
static const Shortint TeeKey_F2 = 0x71;
static const Shortint TeeKey_F3 = 0x72;
static const Shortint TeeKey_F4 = 0x73;
static const Shortint TeeKey_F5 = 0x74;
static const Shortint TeeKey_F6 = 0x75;
static const Shortint TeeKey_F7 = 0x76;
static const Shortint TeeKey_F8 = 0x77;
static const Shortint TeeKey_F9 = 0x78;
static const Shortint TeeKey_F10 = 0x79;
static const Shortint TeeKey_F11 = 0x7a;
static const Shortint TeeKey_F12 = 0x7b;
extern PACKAGE TTeeTranslateHook TeeTranslateHook;
extern PACKAGE TTeeTranslateStringHook TeeTranslateStringHook;
extern PACKAGE AnsiString __fastcall TeeStr(const int Num);
extern PACKAGE Graphics::TColor __fastcall GetDefaultColor(const int Index);
extern PACKAGE Word __fastcall DaysInMonth(Word Year, Word Month);
extern PACKAGE AnsiString __fastcall DateTimeDefaultFormat(const double AStep);
extern PACKAGE double __fastcall NextDateTimeStep(const double AStep);
extern PACKAGE TDateTimeStep __fastcall FindDateTimeStep(const double StepValue);
extern PACKAGE void __fastcall TeeDrawCheckBox(int x, int y, Graphics::TCanvas* Canvas, bool Checked, Graphics::TColor ABackColor, bool CheckBox = true);
extern PACKAGE double __fastcall ScreenRatio(Tecanvas::TCanvas3D* ACanvas);
extern PACKAGE void __fastcall DrawBevel(Tecanvas::TTeeCanvas* Canvas, Controls::TBevelCut Bevel, Types::TRect &R, int Width, int Round = 0x0);
extern PACKAGE void __fastcall RectToFourPoints(const Types::TRect &ARect, const double Angle, Types::TPoint * P);
extern PACKAGE bool __fastcall PointInLine(const Types::TPoint &P, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, const int TolerancePixels)/* overload */;
extern PACKAGE bool __fastcall PointInLine(const Types::TPoint &P, const int px, const int py, const int qx, const int qy, const int TolerancePixels)/* overload */;
extern PACKAGE bool __fastcall PointInLineTolerance(const Types::TPoint &P, const int px, const int py, const int qx, const int qy, const int TolerancePixels);
extern PACKAGE bool __fastcall PointInLine(const Types::TPoint &P, const int px, const int py, const int qx, const int qy)/* overload */;
extern PACKAGE bool __fastcall PointInLine(const Types::TPoint &P, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint)/* overload */;
extern PACKAGE bool __fastcall PointInPolygon(const Types::TPoint &P, const Types::TPoint * Poly, const int Poly_Size);
extern PACKAGE bool __fastcall PointInTriangle(const Types::TPoint &P, const Types::TPoint &P0, const Types::TPoint &P1, const Types::TPoint &P2)/* overload */;
extern PACKAGE bool __fastcall PointInTriangle(const Types::TPoint &P, int X0, int X1, int Y0, int Y1)/* overload */;
extern PACKAGE bool __fastcall PointInHorizTriangle(const Types::TPoint &P, int Y0, int Y1, int X0, int X1);
extern PACKAGE bool __fastcall PointInEllipse(const Types::TPoint &P, int Left, int Top, int Right, int Bottom)/* overload */;
extern PACKAGE bool __fastcall PointInEllipse(const Types::TPoint &P, const Types::TRect &Rect)/* overload */;
extern PACKAGE AnsiString __fastcall DelphiToLocalFormat(const AnsiString Format);
extern PACKAGE AnsiString __fastcall LocalToDelphiFormat(const AnsiString Format);
extern PACKAGE void __fastcall EnableControls(bool Enable, const Controls::TControl* * ControlArray, const int ControlArray_Size);
extern PACKAGE System::TDateTime __fastcall TeeRoundDate(const System::TDateTime ADate, TDateTimeStep AStep);
extern PACKAGE void __fastcall TeeDateTimeIncrement(bool IsDateTime, bool Increment, double &Value, const double AnIncrement, TDateTimeStep tmpWhichDateTime);
extern PACKAGE void __fastcall TeeSort(int StartIndex, int EndIndex, TTeeSortCompare CompareFunc, TTeeSortSwap SwapFunc);
extern PACKAGE AnsiString __fastcall TeeGetUniqueName(Classes::TComponent* AOwner, const AnsiString AStartName);
extern PACKAGE int __fastcall TeeNumFields(AnsiString St)/* overload */;
extern PACKAGE int __fastcall TeeNumFields(const AnsiString St, const AnsiString Separator)/* overload */;
extern PACKAGE AnsiString __fastcall TeeExtractField(AnsiString St, int Index)/* overload */;
extern PACKAGE AnsiString __fastcall TeeExtractField(AnsiString St, int Index, const AnsiString Separator)/* overload */;
extern PACKAGE void __fastcall TeeLoadBitmap(Graphics::TBitmap* Bitmap, const AnsiString Name1, const AnsiString Name2);
extern PACKAGE void __fastcall TeeGetBitmapEditor(System::TObject* AObject, Graphics::TBitmap* &Bitmap);
extern PACKAGE bool __fastcall CrossingLines(const double X1, const double Y1, const double X2, const double Y2, const double X3, const double Y3, const double X4, const double Y4, /* out */ double &x, /* out */ double &y);
extern PACKAGE void __fastcall TeeTranslateControl(Controls::TControl* AControl, const Controls::TControl* * ExcludeChilds, const int ExcludeChilds_Size)/* overload */;
extern PACKAGE void __fastcall TeeTranslateControl(Controls::TControl* AControl)/* overload */;
extern PACKAGE AnsiString __fastcall TeeTranslateString(const AnsiString Text);
extern PACKAGE AnsiString __fastcall ReplaceChar(const AnsiString AString, const char Search, const char Replace = '\x0');
extern PACKAGE Graphics::TBitmap* __fastcall TeeAntiAlias(TCustomTeePanel* Panel, bool ChartRect = false);
extern PACKAGE void __fastcall SetDefaultColorPalette(void)/* overload */;
extern PACKAGE void __fastcall SetDefaultColorPalette(const Graphics::TColor * Palette, const int Palette_Size)/* overload */;
extern PACKAGE bool __fastcall TeeReadBoolOption(const AnsiString AKey, bool DefaultValue);
extern PACKAGE void __fastcall TeeSaveBoolOption(const AnsiString AKey, bool Value);
extern PACKAGE int __fastcall TeeReadIntegerOption(const AnsiString AKey, int DefaultValue);
extern PACKAGE void __fastcall TeeSaveIntegerOption(const AnsiString AKey, int Value);
extern PACKAGE AnsiString __fastcall TeeReadStringOption(const AnsiString AKey, const AnsiString DefaultValue);
extern PACKAGE void __fastcall TeeSaveStringOption(const AnsiString AKey, const AnsiString Value);
extern PACKAGE AnsiString __fastcall TeeDefaultXMLEncoding();
extern PACKAGE void __fastcall ConvertTextToXML(Classes::TStream* Stream, bool XMLHeader = true);
extern PACKAGE void __fastcall TeeGotoURL(int Handle, const AnsiString URL);

}	/* namespace Teeprocs */
using namespace Teeprocs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeProcs
