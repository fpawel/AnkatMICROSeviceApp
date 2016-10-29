// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeCanvas.pas' rev: 6.00

#ifndef TeCanvasHPP
#define TeCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TypInfo.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tecanvas
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFilterRegion;
class PASCALIMPLEMENTATION TFilterRegion : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FHeight;
	int FLeft;
	int FTop;
	int FWidth;
	Types::TRect __fastcall GetRectangle();
	void __fastcall SetRectangle(const Types::TRect &Rect);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Types::TRect Rectangle = {read=GetRectangle, write=SetRectangle};
	
__published:
	__property int Height = {read=FHeight, write=FHeight, default=0};
	__property int Left = {read=FLeft, write=FLeft, default=0};
	__property int Top = {read=FTop, write=FTop, default=0};
	__property int Width = {read=FWidth, write=FWidth, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TFilterRegion(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TFilterRegion(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TRGB
{
	Byte Blue;
	Byte Green;
	Byte Red;
} ;
#pragma pack(pop)

typedef TRGB TRGBs[1];

typedef TRGB *PRGBs;

__interface IFormCreator;
typedef System::DelphiInterface<IFormCreator> _di_IFormCreator;
__interface IFormCreator  : public IInterface 
{
	
public:
	virtual Stdctrls::TCheckBox* __fastcall AddCheckBox(const AnsiString PropName, const AnsiString ACaption, Classes::TNotifyEvent OnChange = 0x0) = 0 ;
	virtual Stdctrls::TButton* __fastcall AddColor(const AnsiString PropName, const AnsiString ACaption) = 0 ;
	virtual Stdctrls::TComboBox* __fastcall AddCombo(const AnsiString PropName) = 0 ;
	virtual Stdctrls::TEdit* __fastcall AddInteger(const AnsiString PropName, const AnsiString ACaption, int AMin, int AMax) = 0 ;
	virtual Stdctrls::TScrollBar* __fastcall AddScroll(const AnsiString PropName, int AMin, int AMax) = 0 ;
};

typedef DynamicArray<PRGBs >  TRGBArray;

class DELPHICLASS TTeeFilter;
class PASCALIMPLEMENTATION TTeeFilter : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	bool FEnabled;
	TFilterRegion* FRegion;
	TFilterRegion* __fastcall GetRegion(void);
	void __fastcall SetRegion(TFilterRegion* Value);
	
protected:
	bool AllowRegion;
	Classes::TNotifyEvent FChanged;
	bool ReuseLines;
	void __fastcall CalcLines(Graphics::TBitmap* Bitmap);
	
public:
	DynamicArray<PRGBs >  Lines;
	__fastcall virtual TTeeFilter(Classes::TCollection* Collection);
	__fastcall virtual ~TTeeFilter(void);
	/*         class method */ static void __fastcall ApplyTo(TMetaClass* vmt, Graphics::TBitmap* Bitmap)/* overload */;
	void __fastcall Apply(Graphics::TBitmap* Bitmap)/* overload */;
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall CreateEditor(_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property TFilterRegion* Region = {read=GetRegion, write=SetRegion};
};


typedef TMetaClass*TFilterClass;

class DELPHICLASS TFilterItems;
class PASCALIMPLEMENTATION TFilterItems : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TTeeFilter* operator[](int Index) { return Item[Index]; }
	
private:
	TTeeFilter* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TTeeFilter* Value);
	
public:
	HIDESBASE TTeeFilter* __fastcall Add(TMetaClass* Filter);
	void __fastcall ApplyTo(Graphics::TBitmap* ABitmap);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TTeeFilter* Item[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TFilterItems(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TFilterItems(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConvolveFilter;
class PASCALIMPLEMENTATION TConvolveFilter : public TTeeFilter 
{
	typedef TTeeFilter inherited;
	
protected:
	TRGB *Prev;
	TRGB *This;
	TRGB *Next;
	float InvTotalWeight;
	
public:
	float Weights[3][3];
	__fastcall virtual TConvolveFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TConvolveFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TBlurFilter;
class PASCALIMPLEMENTATION TBlurFilter : public TConvolveFilter 
{
	typedef TConvolveFilter inherited;
	
private:
	int FAmount;
	int FSteps;
	
public:
	__fastcall virtual TBlurFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	virtual void __fastcall CreateEditor(_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	
__published:
	__property int Amount = {read=FAmount, write=FAmount, default=1};
	__property int Steps = {read=FSteps, write=FSteps, default=1};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TBlurFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TTeePicture;
class PASCALIMPLEMENTATION TTeePicture : public Graphics::TPicture 
{
	typedef Graphics::TPicture inherited;
	
private:
	TFilterItems* FFilters;
	Graphics::TBitmap* IBitmap;
	void __fastcall DoReadFilters(Classes::TReader* Reader);
	void __fastcall DoWriteFilters(Classes::TWriter* Writer);
	bool __fastcall FiltersStored(void);
	TFilterItems* __fastcall GetFilters(void);
	void __fastcall SetFilters(const TFilterItems* Value);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
public:
	__fastcall virtual ~TTeePicture(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Graphics::TGraphic* __fastcall Filtered(void);
	void __fastcall Repaint(void);
	/*         class method */ static void __fastcall ReadFilters(TMetaClass* vmt, Classes::TReader* Reader, TFilterItems* Filters);
	/*         class method */ static void __fastcall WriteFilters(TMetaClass* vmt, Classes::TWriter* Writer, TFilterItems* Filters);
	
__published:
	__property TFilterItems* Filters = {read=GetFilters, write=SetFilters, stored=false};
public:
	#pragma option push -w-inl
	/* TPicture.Create */ inline __fastcall TTeePicture(void) : Graphics::TPicture() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPenEndStyle { esRound, esSquare, esFlat };
#pragma option pop

class DELPHICLASS TChartPen;
class PASCALIMPLEMENTATION TChartPen : public Graphics::TPen 
{
	typedef Graphics::TPen inherited;
	
private:
	TPenEndStyle FEndStyle;
	bool FSmallDots;
	int FSmallSpace;
	bool FVisible;
	bool __fastcall IsEndStored(void);
	bool __fastcall IsVisibleStored(void);
	void __fastcall SetEndStyle(const TPenEndStyle Value);
	void __fastcall SetSmallDots(const bool Value);
	void __fastcall SetSmallSpace(const int Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	TPenEndStyle DefaultEnd;
	bool DefaultVisible;
	
public:
	__fastcall TChartPen(Classes::TNotifyEvent OnChangeEvent);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Hide(void);
	void __fastcall Show(void);
	
__published:
	__property TPenEndStyle EndStyle = {read=FEndStyle, write=SetEndStyle, stored=IsEndStored, nodefault};
	__property bool SmallDots = {read=FSmallDots, write=SetSmallDots, default=0};
	__property int SmallSpace = {read=FSmallSpace, write=SetSmallSpace, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, nodefault};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartHiddenPen;
class PASCALIMPLEMENTATION TChartHiddenPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TChartHiddenPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartHiddenPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDottedGrayPen;
class PASCALIMPLEMENTATION TDottedGrayPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TDottedGrayPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color  = {default=8421504};
	__property Style  = {default=2};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TDottedGrayPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDarkGrayPen;
class PASCALIMPLEMENTATION TDarkGrayPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TDarkGrayPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color  = {default=8421504};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TDarkGrayPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWhitePen;
class PASCALIMPLEMENTATION TWhitePen : public TChartPen 
{
	typedef TChartPen inherited;
	
private:
	HIDESBASE bool __fastcall IsVisibleStored(void);
	
public:
	__fastcall TWhitePen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color  = {default=16777215};
	__property Visible  = {stored=IsVisibleStored};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TWhitePen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartBrush;
class PASCALIMPLEMENTATION TChartBrush : public Graphics::TBrush 
{
	typedef Graphics::TBrush inherited;
	
private:
	Graphics::TColor FBackColor;
	Graphics::TPicture* FImage;
	Graphics::TPicture* __fastcall GetImage(void);
	void __fastcall SetBackColor(const Graphics::TColor Value);
	void __fastcall SetImage(const Graphics::TPicture* Value);
	
public:
	__fastcall virtual TChartBrush(Classes::TNotifyEvent OnChangeEvent);
	__fastcall virtual ~TChartBrush(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	
__published:
	__property Graphics::TColor BackColor = {read=FBackColor, write=SetBackColor, default=536870911};
	__property Color  = {default=536870912};
	__property Graphics::TPicture* Image = {read=GetImage, write=SetImage};
};


typedef void __fastcall (__closure *TTeeView3DScrolled)(bool IsHoriz);

typedef void __fastcall (__closure *TTeeView3DChangedZoom)(int NewZoom);

class DELPHICLASS TView3DOptions;
class PASCALIMPLEMENTATION TView3DOptions : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	double FElevation;
	int FFontZoom;
	int FHorizOffset;
	bool FOrthogonal;
	int FOrthoAngle;
	int FPerspective;
	double FRotation;
	int FTilt;
	int FVertOffset;
	double FZoom;
	bool FZoomText;
	TTeeView3DScrolled FOnScrolled;
	TTeeView3DChangedZoom FOnChangedZoom;
	Controls::TWinControl* FParent;
	int __fastcall GetElevation(void);
	int __fastcall GetRotation(void);
	int __fastcall GetZoom(void);
	void __fastcall SetElevationInteger(const int Value);
	void __fastcall SetElevation(const double Value);
	void __fastcall SetFontZoom(int Value);
	void __fastcall SetPerspective(int Value);
	void __fastcall SetRotationInteger(const int Value);
	void __fastcall SetRotation(const double Value)/* overload */;
	void __fastcall SetTilt(int Value);
	void __fastcall SetHorizOffset(int Value);
	void __fastcall SetVertOffset(int Value);
	void __fastcall SetOrthoAngle(int Value);
	void __fastcall SetOrthogonal(bool Value);
	void __fastcall SetZoomInteger(const int Value);
	void __fastcall SetZoom(const double Value);
	void __fastcall SetZoomText(bool Value);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	
protected:
	double __fastcall CalcOrthoRatio(void);
	
public:
	__fastcall TView3DOptions(Controls::TWinControl* AParent);
	void __fastcall Repaint(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Controls::TWinControl* Parent = {read=FParent, write=FParent};
	__property double ElevationFloat = {read=FElevation, write=SetElevation};
	__property double RotationFloat = {read=FRotation, write=SetRotation};
	__property double ZoomFloat = {read=FZoom, write=SetZoom};
	__property TTeeView3DChangedZoom OnChangedZoom = {read=FOnChangedZoom, write=FOnChangedZoom};
	__property TTeeView3DScrolled OnScrolled = {read=FOnScrolled, write=FOnScrolled};
	
__published:
	__property int Elevation = {read=GetElevation, write=SetElevationInteger, default=345};
	__property int FontZoom = {read=FFontZoom, write=SetFontZoom, default=100};
	__property int HorizOffset = {read=FHorizOffset, write=SetHorizOffset, default=0};
	__property int OrthoAngle = {read=FOrthoAngle, write=SetOrthoAngle, default=45};
	__property bool Orthogonal = {read=FOrthogonal, write=SetOrthogonal, default=1};
	__property int Perspective = {read=FPerspective, write=SetPerspective, default=15};
	__property int Rotation = {read=GetRotation, write=SetRotationInteger, default=345};
	__property int Tilt = {read=FTilt, write=SetTilt, default=0};
	__property int VertOffset = {read=FVertOffset, write=SetVertOffset, default=0};
	__property int Zoom = {read=GetZoom, write=SetZoomInteger, default=100};
	__property bool ZoomText = {read=FZoomText, write=SetZoomText, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TView3DOptions(void) { }
	#pragma option pop
	
};


typedef Shortint TTeeTransparency;

class DELPHICLASS TTeeBlend;
class DELPHICLASS TTeeCanvas;
class DELPHICLASS TTeeFont;
class DELPHICLASS TTeeFontGradient;
class DELPHICLASS TTeeGradient;
class DELPHICLASS TCustomTeeGradient;
#pragma option push -b-
enum TGradientDirection { gdTopBottom, gdBottomTop, gdLeftRight, gdRightLeft, gdFromCenter, gdFromTopLeft, gdFromBottomLeft, gdRadial, gdDiagonalUp, gdDiagonalDown };
#pragma option pop

class DELPHICLASS TSubGradient;
typedef Types::TPoint TFourPoints[4];

class DELPHICLASS TCanvas3D;
typedef DynamicArray<Types::TPoint >  TPointArray;

class PASCALIMPLEMENTATION TCustomTeeGradient : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FAngle;
	int FBalance;
	TGradientDirection FDirection;
	Graphics::TColor FEndColor;
	Graphics::TColor FMidColor;
	int FRadialX;
	int FRadialY;
	Graphics::TColor FStartColor;
	TSubGradient* FSub;
	bool FVisible;
	bool IHasMiddle;
	void __fastcall DrawRadial(TTeeCanvas* Canvas, const Types::TRect &Rect);
	void __fastcall DrawRotated(TTeeCanvas* Canvas, const Types::TRect &R);
	void __fastcall DrawSubGradient(TTeeCanvas* Canvas, const Types::TRect &Rect, int RoundRectSize = 0x0);
	Graphics::TColor __fastcall GetMidColor(void);
	TSubGradient* __fastcall GetSub(void);
	void __fastcall SetAngle(int Value);
	void __fastcall SetBalance(int Value);
	void __fastcall SetColorProperty(Graphics::TColor &Variable, const Graphics::TColor Value);
	void __fastcall SetDirection(TGradientDirection Value);
	void __fastcall SetEndColor(Graphics::TColor Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	void __fastcall SetMidColor(Graphics::TColor Value);
	void __fastcall SetRadialX(const int Value);
	void __fastcall SetRadialY(const int Value);
	void __fastcall SetStartColor(Graphics::TColor Value);
	void __fastcall SetSub(const TSubGradient* Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	Classes::TNotifyEvent IChanged;
	void __fastcall DoChanged(void);
	
public:
	__fastcall virtual TCustomTeeGradient(Classes::TNotifyEvent ChangedEvent);
	__fastcall virtual ~TCustomTeeGradient(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Draw(TTeeCanvas* Canvas, const Types::TRect &Rect, int RoundRectSize = 0x0)/* overload */;
	void __fastcall Draw(TTeeCanvas* Canvas, Types::TPoint * P)/* overload */;
	void __fastcall Draw(TCanvas3D* Canvas, Types::TPoint * P, int Z)/* overload */;
	void __fastcall Draw(TCanvas3D* Canvas, TPointArray &P, int Z, bool Is3D)/* overload */;
	__property Classes::TNotifyEvent Changed = {read=IChanged, write=IChanged};
	void __fastcall UseMiddleColor(void);
	__property int Angle = {read=FAngle, write=SetAngle, default=0};
	__property int Balance = {read=FBalance, write=SetBalance, default=50};
	__property TGradientDirection Direction = {read=FDirection, write=SetDirection, default=0};
	__property Graphics::TColor EndColor = {read=FEndColor, write=SetEndColor, default=65535};
	__property Graphics::TColor MidColor = {read=GetMidColor, write=SetMidColor, default=536870911};
	__property int RadialX = {read=FRadialX, write=SetRadialX, default=0};
	__property int RadialY = {read=FRadialY, write=SetRadialY, default=0};
	__property Graphics::TColor StartColor = {read=FStartColor, write=SetStartColor, default=16777215};
	__property TSubGradient* SubGradient = {read=GetSub, write=SetSub};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
};


class PASCALIMPLEMENTATION TSubGradient : public TCustomTeeGradient 
{
	typedef TCustomTeeGradient inherited;
	
private:
	TTeeTransparency FTransparency;
	void __fastcall SetTransparency(const TTeeTransparency Value);
	
__published:
	__property Angle  = {default=0};
	__property Balance  = {default=50};
	__property Direction  = {default=0};
	__property EndColor  = {default=65535};
	__property MidColor  = {default=536870911};
	__property RadialX  = {default=0};
	__property RadialY  = {default=0};
	__property StartColor  = {default=16777215};
	__property TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=50};
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Create */ inline __fastcall virtual TSubGradient(Classes::TNotifyEvent ChangedEvent) : TCustomTeeGradient(ChangedEvent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeeGradient.Destroy */ inline __fastcall virtual ~TSubGradient(void) { }
	#pragma option pop
	
};



class PASCALIMPLEMENTATION TTeeGradient : public TCustomTeeGradient 
{
	typedef TCustomTeeGradient inherited;
	
__published:
	__property Angle  = {default=0};
	__property Balance  = {default=50};
	__property Direction  = {default=0};
	__property EndColor  = {default=65535};
	__property MidColor  = {default=536870911};
	__property RadialX  = {default=0};
	__property RadialY  = {default=0};
	__property StartColor  = {default=16777215};
	__property SubGradient ;
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Create */ inline __fastcall virtual TTeeGradient(Classes::TNotifyEvent ChangedEvent) : TCustomTeeGradient(ChangedEvent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeeGradient.Destroy */ inline __fastcall virtual ~TTeeGradient(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTeeFontGradient : public TTeeGradient 
{
	typedef TTeeGradient inherited;
	
private:
	bool FOutline;
	void __fastcall SetBooleanProperty(bool &Variable, const bool Value);
	void __fastcall SetOutline(const bool Value);
	
__published:
	__property bool Outline = {read=FOutline, write=SetOutline, default=0};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Create */ inline __fastcall virtual TTeeFontGradient(Classes::TNotifyEvent ChangedEvent) : TTeeGradient(ChangedEvent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeeGradient.Destroy */ inline __fastcall virtual ~TTeeFontGradient(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeShadow;
class PASCALIMPLEMENTATION TTeeShadow : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FClip;
	Graphics::TColor FColor;
	int FHorizSize;
	bool FSmooth;
	int FSmoothBlur;
	TTeeTransparency FTransparency;
	int FVertSize;
	bool FVisible;
	Classes::TNotifyEvent IOnChange;
	TTeeBlend* IBlend;
	void __fastcall Changed(void);
	void __fastcall DrawSmooth(TCanvas3D* ACanvas, const Types::TRect &Rect, bool Ellipse, bool Polygon, int RoundSize, const TPointArray P);
	void __fastcall FinishBlending(TTeeCanvas* ACanvas);
	int __fastcall GetSize(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsHorizStored(void);
	bool __fastcall IsVertStored(void);
	bool __fastcall IsVisibleStored(void);
	bool __fastcall PrepareCanvas(TCanvas3D* ACanvas, const Types::TRect &R, int Z = 0x0);
	void __fastcall SetClip(const bool Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetHorizSize(int Value);
	void __fastcall SetIntegerProperty(int &Variable, const int Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetSmooth(const bool Value);
	void __fastcall SetSmoothBlur(const int Value);
	void __fastcall SetTransparency(TTeeTransparency Value);
	void __fastcall SetVertSize(int Value);
	void __fastcall SetVisible(bool Value);
	bool __fastcall ValidCanvas(TCanvas3D* ACanvas);
	
protected:
	Graphics::TColor DefaultColor;
	int DefaultSize;
	bool DefaultVisible;
	bool FullDraw;
	void __fastcall InitValues(Graphics::TColor AColor, int ASize);
	
public:
	__fastcall TTeeShadow(Classes::TNotifyEvent AOnChange);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Draw(TCanvas3D* ACanvas, const Types::TPoint * P, const int P_Size)/* overload */;
	void __fastcall Draw(TCanvas3D* ACanvas, const Types::TRect &Rect)/* overload */;
	void __fastcall Draw(TCanvas3D* ACanvas, const Types::TRect &Rect, int Z, int RoundSize = 0x0)/* overload */;
	void __fastcall DrawEllipse(TCanvas3D* ACanvas, const Types::TRect &Rect, int Z = 0x0);
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	
__published:
	__property bool Clip = {read=FClip, write=SetClip, default=0};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, nodefault};
	__property int HorizSize = {read=FHorizSize, write=SetHorizSize, stored=IsHorizStored, nodefault};
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=1};
	__property int SmoothBlur = {read=FSmoothBlur, write=SetSmoothBlur, default=0};
	__property TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property int VertSize = {read=FVertSize, write=SetVertSize, stored=IsVertStored, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TTeeShadow(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTeeFont : public Graphics::TFont 
{
	typedef Graphics::TFont inherited;
	
private:
	TTeeFontGradient* FGradient;
	int FInterCharSize;
	TChartHiddenPen* FOutLine;
	TTeePicture* FPicture;
	TTeeShadow* FShadow;
	TTeeCanvas* ICanvas;
	void __fastcall DoChanged(System::TObject* Sender);
	TTeeFontGradient* __fastcall GetGradient(void);
	TChartHiddenPen* __fastcall GetOutLine(void);
	TTeePicture* __fastcall GetPicture(void);
	TTeeShadow* __fastcall GetShadow(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsHeightStored(void);
	bool __fastcall IsNameStored(void);
	bool __fastcall IsStyleStored(void);
	void __fastcall SetGradient(const TTeeFontGradient* Value);
	void __fastcall SetInterCharSize(int Value);
	void __fastcall SetOutLine(TChartHiddenPen* Value);
	void __fastcall SetPicture(TTeePicture* Value);
	void __fastcall SetShadow(TTeeShadow* Value);
	
protected:
	Graphics::TColor IDefColor;
	Graphics::TFontStyles IDefStyle;
	
public:
	__fastcall TTeeFont(Classes::TNotifyEvent ChangedEvent);
	__fastcall virtual ~TTeeFont(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Charset  = {default=1};
	__property Color  = {stored=IsColorStored};
	__property TTeeFontGradient* Gradient = {read=GetGradient, write=SetGradient};
	__property Height  = {stored=IsHeightStored};
	__property int InterCharSize = {read=FInterCharSize, write=SetInterCharSize, default=0};
	__property Name  = {stored=IsNameStored};
	__property TChartHiddenPen* OutLine = {read=GetOutLine, write=SetOutLine};
	__property TTeePicture* Picture = {read=GetPicture, write=SetPicture};
	__property TTeeShadow* Shadow = {read=GetShadow, write=SetShadow};
	__property Style  = {stored=IsStyleStored};
};


#pragma option push -b-
enum TCanvasBackMode { cbmNone, cbmTransparent, cbmOpaque };
#pragma option pop

class PASCALIMPLEMENTATION TTeeCanvas : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	Graphics::TFont* FFont;
	Graphics::TPen* FPen;
	Graphics::TBrush* FBrush;
	bool FMetafiling;
	int ITransp;
	int __fastcall GetFontHeight(void);
	void __fastcall InternalDark(const Graphics::TColor AColor, Byte Quantity);
	
protected:
	#pragma pack(push, 1)
	Types::TRect FBounds;
	#pragma pack(pop)
	
	TTeeFont* IFont;
	void __fastcall SetCanvas(Graphics::TCanvas* ACanvas);
	virtual Graphics::TColor __fastcall GetBackColor(void) = 0 ;
	virtual TCanvasBackMode __fastcall GetBackMode(void) = 0 ;
	virtual HDC __fastcall GetHandle(void) = 0 ;
	virtual bool __fastcall GetMonochrome(void) = 0 ;
	virtual Graphics::TColor __fastcall GetPixel(int x, int y) = 0 ;
	virtual bool __fastcall GetSupportsFullRotation(void) = 0 ;
	virtual bool __fastcall GetIsNoBMPGrid(void) = 0 ;
	virtual int __fastcall GetTextAlign(void) = 0 ;
	virtual bool __fastcall GetUseBuffer(void) = 0 ;
	virtual void __fastcall SetBackColor(Graphics::TColor Color) = 0 ;
	virtual void __fastcall SetBackMode(TCanvasBackMode Mode) = 0 ;
	virtual void __fastcall SetMonochrome(bool Value) = 0 ;
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value) = 0 ;
	virtual void __fastcall SetTextAlign(int Align) = 0 ;
	virtual void __fastcall SetUseBuffer(bool Value) = 0 ;
	tagSIZE __fastcall TextExtent(const WideString Text);
	
public:
	double FontZoom;
	void __fastcall AssignBrush(TChartBrush* ABrush)/* overload */;
	void __fastcall AssignBrush(TChartBrush* ABrush, Graphics::TColor ABackColor)/* overload */;
	void __fastcall AssignBrush(TChartBrush* ABrush, Graphics::TColor AColor, Graphics::TColor ABackColor)/* overload */;
	void __fastcall AssignBrushColor(TChartBrush* ABrush, Graphics::TColor AColor, Graphics::TColor ABackColor);
	void __fastcall AssignVisiblePen(Graphics::TPen* APen);
	virtual void __fastcall AssignVisiblePenColor(Graphics::TPen* APen, Graphics::TColor AColor);
	void __fastcall AssignFont(TTeeFont* AFont);
	void __fastcall ResetState(void);
	virtual TTeeBlend* __fastcall BeginBlending(const Types::TRect &R, TTeeTransparency Transparency);
	virtual void __fastcall EndBlending(TTeeBlend* Blend);
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY) = 0 /* overload */;
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, double StartAngle, double EndAngle)/* overload */;
	void __fastcall Arrow(bool Filled, const double ArrowPercent, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight)/* overload */;
	virtual void __fastcall Donut(int XCenter, int YCenter, int XRadius, int YRadius, const double StartAngle, const double EndAngle, const double HolePercent) = 0 ;
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic) = 0 ;
	void __fastcall Ellipse(const Types::TRect &R)/* overload */;
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2) = 0 /* overload */;
	virtual void __fastcall FillRect(const Types::TRect &Rect) = 0 ;
	virtual void __fastcall Frame3D(Types::TRect &Rect, Graphics::TColor TopColor, Graphics::TColor BottomColor, int Width);
	virtual void __fastcall LineTo(int X, int Y) = 0 /* overload */;
	void __fastcall LineTo(const Types::TPoint &P)/* overload */;
	virtual void __fastcall MoveTo(int X, int Y) = 0 /* overload */;
	void __fastcall MoveTo(const Types::TPoint &P)/* overload */;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) = 0 ;
	void __fastcall Rectangle(const Types::TRect &R)/* overload */;
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1) = 0 /* overload */;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3) = 0 /* overload */;
	void __fastcall RoundRect(const Types::TRect &R, int X, int Y)/* overload */;
	virtual void __fastcall StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic) = 0 /* overload */;
	void __fastcall TextOut(int X, int Y, const AnsiString Text, bool AllowHtml)/* overload */;
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text) = 0 /* overload */;
	virtual int __fastcall TextWidth(const AnsiString St)/* overload */;
	virtual int __fastcall TextHeight(const AnsiString St)/* overload */;
	virtual int __fastcall TextWidth(const WideString St)/* overload */;
	virtual int __fastcall TextHeight(const WideString St)/* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect) = 0 /* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect, int RoundSize)/* overload */;
	virtual void __fastcall ClipEllipse(const Types::TRect &Rect, bool Inverted = false);
	virtual void __fastcall ClipPolygon(const Types::TPoint * Points, const int Points_Size, int NumPoints, bool DiffRegion = false);
	bool __fastcall ConvexHull(TPointArray &Points);
	virtual void __fastcall DoHorizLine(int X0, int X1, int Y);
	void __fastcall DoRectangle(const Types::TRect &Rect);
	virtual void __fastcall DoVertLine(int X, int Y0, int Y1);
	virtual void __fastcall EraseBackground(const Types::TRect &Rect) = 0 ;
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0) = 0 ;
	virtual void __fastcall Invalidate(void) = 0 ;
	virtual void __fastcall Line(int X0, int Y0, int X1, int Y1)/* overload */;
	void __fastcall Line(const Types::TPoint &FromPoint, const Types::TPoint &ToPoint)/* overload */;
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size) = 0 /* overload */;
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size) = 0 ;
	virtual void __fastcall PolygonGradient(const Types::TPoint * Points, const int Points_Size, TCustomTeeGradient* Gradient);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, double RotDegree) = 0 ;
	__property bool SupportsFullRotation = {read=GetSupportsFullRotation, nodefault};
	__property bool IsNoBMPGrid = {read=GetIsNoBMPGrid, nodefault};
	virtual void __fastcall UnClipRectangle(void) = 0 ;
	__property Graphics::TColor BackColor = {read=GetBackColor, write=SetBackColor, nodefault};
	__property TCanvasBackMode BackMode = {read=GetBackMode, write=SetBackMode, nodefault};
	__property Types::TRect Bounds = {read=FBounds};
	__property Graphics::TBrush* Brush = {read=FBrush};
	__property Graphics::TFont* Font = {read=FFont};
	__property int FontHeight = {read=GetFontHeight, nodefault};
	__property HDC Handle = {read=GetHandle, nodefault};
	__property bool Metafiling = {read=FMetafiling, write=FMetafiling, nodefault};
	__property bool Monochrome = {read=GetMonochrome, write=SetMonochrome, nodefault};
	__property Graphics::TPen* Pen = {read=FPen};
	__property Graphics::TColor Pixels[int X][int Y] = {read=GetPixel, write=SetPixel};
	__property Graphics::TCanvas* ReferenceCanvas = {read=FCanvas, write=SetCanvas};
	__property int TextAlign = {read=GetTextAlign, write=SetTextAlign, nodefault};
	__property bool UseBuffer = {read=GetUseBuffer, write=SetUseBuffer, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeCanvas(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeCanvas(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTeeBlend : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Graphics::TBitmap* FBitmap;
	TTeeCanvas* FCanvas;
	#pragma pack(push, 1)
	Types::TRect FRect;
	#pragma pack(pop)
	
	bool IValidSize;
	
public:
	__fastcall TTeeBlend(TTeeCanvas* ACanvas, const Types::TRect &R);
	__fastcall virtual ~TTeeBlend(void);
	void __fastcall DoBlend(TTeeTransparency Transparency);
	void __fastcall SetRectangle(const Types::TRect &R);
	__property Graphics::TBitmap* Bitmap = {read=FBitmap};
};


typedef int TCanvasTextAlign;

typedef HDC TTeeCanvasHandle;

#pragma pack(push, 1)
struct TFloatPoint
{
	double X;
	double Y;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TPoint3DFloat
{
	double X;
	double Y;
	double Z;
} ;
#pragma pack(pop)

class DELPHICLASS TFloatXYZ;
class PASCALIMPLEMENTATION TFloatXYZ : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	double FX;
	double FY;
	double FZ;
	void __fastcall SetDoubleProperty(double &Variable, const double Value);
	
protected:
	Classes::TNotifyEvent FOnChange;
	TPoint3DFloat __fastcall Point();
	void __fastcall SetX(const double Value);
	void __fastcall SetY(const double Value);
	void __fastcall SetZ(const double Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property double X = {read=FX, write=SetX};
	__property double Y = {read=FY, write=SetY};
	__property double Z = {read=FZ, write=SetZ};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TFloatXYZ(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TFloatXYZ(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TPoint3D
{
	int x;
	int y;
	int z;
} ;
#pragma pack(pop)

typedef TPoint3D TTrianglePoints3D[3];

typedef Graphics::TColor TTriangleColors3D[3];

typedef bool __fastcall (__closure *TTeeCanvasCalcPoints)(int x, int z, TPoint3D &P0, TPoint3D &P1, Graphics::TColor &Color0, Graphics::TColor &Color1);

#pragma option push -b-
enum TTeeCanvasSurfaceStyle { tcsSolid, tcsWire, tcsDot };
#pragma option pop

#pragma option push -b-
enum TCanvas3DPlane { cpX, cpY, cpZ };
#pragma option pop

class PASCALIMPLEMENTATION TCanvas3D : public TTeeCanvas 
{
	typedef TTeeCanvas inherited;
	
private:
	TView3DOptions* F3DOptions;
	int IDisabledRotation;
	
protected:
	bool FIsOrthogonal;
	int FXCenter;
	int FYCenter;
	int FZCenter;
	int GradientZ;
	bool SupportsID;
	virtual void __fastcall BeginEntity(const AnsiString Entity);
	virtual void __fastcall EndEntity(void);
	void __fastcall CalcPieAngles(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, Extended &Theta, Extended &Theta2);
	virtual Graphics::TColor __fastcall GetPixel3D(int X, int Y, int Z) = 0 ;
	virtual bool __fastcall GetSupports3DText(void) = 0 ;
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value) = 0 ;
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	
public:
	#pragma pack(push, 1)
	TPoint3DFloat RotationCenter;
	#pragma pack(pop)
	
	bool FIsNoBMPGrid;
	Types::TRect __fastcall CalcRect3D(const Types::TRect &R, int Z);
	virtual void __fastcall Calculate2DPosition(int &x, int &y, int z) = 0 /* overload */;
	Types::TPoint __fastcall Calculate3DPosition(const TPoint3D &P)/* overload */;
	Types::TPoint __fastcall Calculate3DPosition(const Types::TPoint &P, int z)/* overload */;
	virtual Types::TPoint __fastcall Calculate3DPosition(int x, int y, int z) = 0 /* overload */;
	TPointArray __fastcall Calc3DPoints(const Types::TPoint * Points, const int Points_Size, int z);
	void __fastcall FourPointsFromRect(const Types::TRect &R, int Z, Types::TPoint * P);
	Types::TRect __fastcall RectFromRectZ(const Types::TRect &R, int Z);
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect) = 0 ;
	virtual void __fastcall Assign(TCanvas3D* Source);
	virtual void __fastcall Projection(int MaxDepth, const Types::TRect &ABounds, const Types::TRect &Rect) = 0 ;
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect) = 0 ;
	virtual bool __fastcall ReDrawBitmap(void) = 0 ;
	HIDESBASE void __fastcall Arrow(bool Filled, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight, int Z)/* overload */;
	HIDESBASE virtual void __fastcall Arrow(bool Filled, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight, int Z, const double ArrowPercent) = 0 /* overload */;
	virtual void __fastcall ClipCube(const Types::TRect &Rect, int MinZ, int MaxZ) = 0 ;
	virtual void __fastcall Cone(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D, int ConePercent) = 0 ;
	virtual void __fastcall Cube(int Left, int Right, int Top, int Bottom, int Z0, int Z1, bool DarkSides = true) = 0 /* overload */;
	void __fastcall Cube(const Types::TRect &R, int Z0, int Z1, bool DarkSides = true)/* overload */;
	virtual void __fastcall Cylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D = true) = 0 ;
	virtual void __fastcall DisableRotation(void);
	void __fastcall EllipseWithZ(const Types::TRect &Rect, int Z)/* overload */;
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z) = 0 /* overload */;
	virtual void __fastcall EnableRotation(void);
	virtual void __fastcall HorizLine3D(int Left, int Right, int Y, int Z);
	virtual void __fastcall VertLine3D(int X, int Top, int Bottom, int Z);
	virtual void __fastcall ZLine3D(int X, int Y, int Z0, int Z1);
	virtual void __fastcall FrontPlaneBegin(void);
	virtual void __fastcall FrontPlaneEnd(void);
	virtual void __fastcall LineWithZ(int X0, int Y0, int X1, int Y1, int Z)/* overload */;
	void __fastcall LineWithZ(const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int Z)/* overload */;
	virtual void __fastcall MoveTo3D(int X, int Y, int Z)/* overload */;
	void __fastcall MoveTo3D(const TPoint3D &P)/* overload */;
	virtual void __fastcall LineTo3D(int X, int Y, int Z)/* overload */;
	void __fastcall LineTo3D(const TPoint3D &P)/* overload */;
	virtual void __fastcall Pie3D(int XCenter, int YCenter, int XRadius, int YRadius, int Z0, int Z1, const double StartAngle, const double EndAngle, bool DarkSides, bool DrawSides, int DonutPercent = 0x0, TCustomTeeGradient* Gradient = (TCustomTeeGradient*)(0x0)) = 0 ;
	virtual void __fastcall Plane3D(const Types::TPoint &A, const Types::TPoint &B, int Z0, int Z1) = 0 ;
	void __fastcall PlaneWithZ(const Types::TPoint * P, int Z)/* overload */;
	virtual void __fastcall PlaneWithZ(const Types::TPoint &P1, const Types::TPoint &P2, const Types::TPoint &P3, const Types::TPoint &P4, int Z) = 0 /* overload */;
	virtual void __fastcall PlaneFour3D(Types::TPoint * Points, int Z0, int Z1) = 0 ;
	virtual void __fastcall Polygon3D(const TPoint3D * Points, const int Points_Size) = 0 ;
	virtual void __fastcall PolygonWithZ(const Types::TPoint * Points, const int Points_Size, int Z);
	HIDESBASE virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size, int Z)/* overload */;
	virtual void __fastcall Pyramid(bool Vertical, int Left, int Top, int Right, int Bottom, int z0, int z1, bool DarkSides = true) = 0 ;
	virtual void __fastcall PyramidTrunc(const Types::TRect &R, int StartZ, int EndZ, int TruncX, int TruncZ) = 0 ;
	HIDESBASE void __fastcall Rectangle(const Types::TRect &R, int Z)/* overload */;
	HIDESBASE void __fastcall Rectangle(int X0, int Y0, int X1, int Y1, int Z)/* overload */;
	virtual void __fastcall RectangleWithZ(const Types::TRect &Rect, int Z) = 0 ;
	virtual void __fastcall RectangleY(int Left, int Top, int Right, int Z0, int Z1) = 0 ;
	virtual void __fastcall RectangleZ(int Left, int Top, int Bottom, int Z0, int Z1) = 0 ;
	void __fastcall RotatedEllipse(int Left, int Top, int Right, int Bottom, int Z, const double Angle);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, double RotDegree) = 0 ;
	virtual void __fastcall Sphere(int x, int y, int z, const double Radius) = 0 /* overload */;
	HIDESBASE void __fastcall StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic, int Pos, TCanvas3DPlane Plane = (TCanvas3DPlane)(0x2))/* overload */;
	virtual void __fastcall Surface3D(TTeeCanvasSurfaceStyle Style, bool SameBrush, int NumXValues, int NumZValues, TTeeCanvasCalcPoints CalcPoints) = 0 ;
	virtual void __fastcall TextOut3D(int x, int y, int z, const AnsiString Text) = 0 ;
	virtual void __fastcall Triangle3D(const TPoint3D * Points, const Graphics::TColor * Colors) = 0 ;
	virtual void __fastcall TriangleWithZ(const Types::TPoint &P1, const Types::TPoint &P2, const Types::TPoint &P3, int Z) = 0 ;
	__property Graphics::TColor Pixels3D[int X][int Y][int Z] = {read=GetPixel3D, write=SetPixel3D};
	__property bool Supports3DText = {read=GetSupports3DText, nodefault};
	__property TView3DOptions* View3DOptions = {read=F3DOptions, write=F3DOptions};
	__property int XCenter = {read=FXCenter, write=FXCenter, nodefault};
	__property int YCenter = {read=FYCenter, write=FYCenter, nodefault};
	__property int ZCenter = {read=FZCenter, write=FZCenter, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCanvas3D(void) : TTeeCanvas() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCanvas3D(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Arrow(bool Filled, const double ArrowPercent, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight){ TTeeCanvas::Arrow(Filled, ArrowPercent, FromPoint, ToPoint, ArrowWidth, ArrowHeight); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size){ TTeeCanvas::Polyline(Points, Points_Size); }
	inline void __fastcall  Rectangle(const Types::TRect &R){ TTeeCanvas::Rectangle(R); }
	inline void __fastcall  Rectangle(int X0, int Y0, int X1, int Y1){ TTeeCanvas::Rectangle(X0, Y0, X1, Y1); }
	inline void __fastcall  StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic){ TTeeCanvas::StretchDraw(Rect, Graphic); }
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef Types::TPoint TTrianglePoints[3];

typedef Types::TPoint TCirclePoints[64];

class DELPHICLASS TTeeCanvas3D;
class PASCALIMPLEMENTATION TTeeCanvas3D : public TCanvas3D 
{
	typedef TCanvas3D inherited;
	
private:
	Extended s1;
	Extended s2;
	Extended s3;
	Extended c1;
	Extended c2;
	Extended c3;
	double c2s3;
	double c2c3;
	double tempXX;
	double tempYX;
	double tempXZ;
	double tempYZ;
	bool FWas3D;
	Graphics::TBitmap* FBitmap;
	bool FDirty;
	bool FMonochrome;
	int FTextAlign;
	bool IHasPerspec;
	bool IHasTilt;
	double IOrthoX;
	double IOrthoY;
	double IZoomPerspec;
	double IZoomFactor;
	bool IZoomText;
	void __fastcall InternalCylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D, int ConePercent);
	
protected:
	bool FBufferedDisplay;
	bool FIs3D;
	bool IKeepBitmap;
	Types::TPoint IPoints[4];
	double CharacterAngle;
	int XCenterOffset;
	int YCenterOffset;
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual TCanvasBackMode __fastcall GetBackMode(void);
	virtual HDC __fastcall GetHandle(void);
	virtual bool __fastcall GetMonochrome(void);
	virtual Graphics::TColor __fastcall GetPixel(int X, int Y);
	virtual Graphics::TColor __fastcall GetPixel3D(int X, int Y, int Z);
	virtual bool __fastcall GetSupports3DText(void);
	virtual bool __fastcall GetSupportsFullRotation(void);
	virtual bool __fastcall GetIsNoBMPGrid(void);
	virtual int __fastcall GetTextAlign(void);
	virtual bool __fastcall GetUseBuffer(void);
	virtual void __fastcall PolygonFour(void);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual void __fastcall SetBackMode(TCanvasBackMode Mode);
	virtual void __fastcall SetBitmap(Graphics::TBitmap* ABitmap);
	virtual void __fastcall SetMonochrome(bool Value);
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual void __fastcall SetTextAlign(int Align);
	virtual void __fastcall SetUseBuffer(bool Value);
	virtual void __fastcall DeleteBitmap(void);
	virtual void __fastcall TransferBitmap(int ALeft, int ATop, Graphics::TCanvas* ACanvas);
	void __fastcall Calc3DTPoint(Types::TPoint &P, int z);
	Types::TPoint __fastcall Calc3DTPoint3D(const TPoint3D &P);
	void __fastcall Calc3DPoint(Types::TPoint &P, int x, int y, int z)/* overload */;
	void __fastcall Calc3DPoint(Types::TPoint &P, double x, double y, int z)/* overload */;
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	void __fastcall Calc3DPos(int &x, int &y, int z)/* overload */;
	void __fastcall CalcPerspective(const Types::TRect &Rect);
	void __fastcall CalcTrigValues(void);
	
public:
	__fastcall TTeeCanvas3D(void);
	__fastcall virtual ~TTeeCanvas3D(void);
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect);
	virtual bool __fastcall ReDrawBitmap(void);
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect);
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY)/* overload */;
	virtual void __fastcall Donut(int XCenter, int YCenter, int XRadius, int YRadius, const double StartAngle, const double EndAngle, const double HolePercent);
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic);
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	virtual void __fastcall EraseBackground(const Types::TRect &Rect);
	virtual void __fastcall FillRect(const Types::TRect &Rect);
	virtual void __fastcall LineTo(int X, int Y)/* overload */;
	virtual void __fastcall MoveTo(int X, int Y)/* overload */;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1)/* overload */;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3)/* overload */;
	virtual void __fastcall StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic)/* overload */;
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text)/* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect)/* overload */;
	virtual void __fastcall ClipCube(const Types::TRect &Rect, int MinZ, int MaxZ);
	virtual void __fastcall DisableRotation(void);
	virtual void __fastcall EnableRotation(void);
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, double RotDegree);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, double RotDegree);
	virtual void __fastcall UnClipRectangle(void);
	virtual void __fastcall Calculate2DPosition(int &x, int &y, int z)/* overload */;
	virtual Types::TPoint __fastcall Calculate3DPosition(int x, int y, int z)/* overload */;
	virtual void __fastcall Projection(int MaxDepth, const Types::TRect &ABounds, const Types::TRect &Rect);
	virtual void __fastcall Arrow(bool Filled, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight, int Z, const double ArrowPercent)/* overload */;
	virtual void __fastcall Cone(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D, int ConePercent);
	virtual void __fastcall Cube(int Left, int Right, int Top, int Bottom, int Z0, int Z1, bool DarkSides = true)/* overload */;
	virtual void __fastcall Cylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D = true);
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z)/* overload */;
	void __fastcall GetCirclePoints(Types::TPoint * P, int X1, int Y1, int X2, int Y2, int Z);
	virtual void __fastcall RectangleZ(int Left, int Top, int Bottom, int Z0, int Z1);
	virtual void __fastcall RectangleY(int Left, int Top, int Right, int Z0, int Z1);
	virtual void __fastcall Pie3D(int AXCenter, int AYCenter, int XRadius, int YRadius, int Z0, int Z1, const double StartAngle, const double EndAngle, bool DarkSides, bool DrawSides, int DonutPercent = 0x0, TCustomTeeGradient* Gradient = (TCustomTeeGradient*)(0x0));
	virtual void __fastcall Plane3D(const Types::TPoint &A, const Types::TPoint &B, int Z0, int Z1);
	virtual void __fastcall PlaneWithZ(const Types::TPoint &P1, const Types::TPoint &P2, const Types::TPoint &P3, const Types::TPoint &P4, int Z)/* overload */;
	virtual void __fastcall PlaneFour3D(Types::TPoint * Points, int Z0, int Z1);
	virtual void __fastcall Polygon3D(const TPoint3D * Points, const int Points_Size);
	virtual void __fastcall Pyramid(bool Vertical, int Left, int Top, int Right, int Bottom, int z0, int z1, bool DarkSides = true);
	virtual void __fastcall PyramidTrunc(const Types::TRect &R, int StartZ, int EndZ, int TruncX, int TruncZ);
	virtual void __fastcall RectangleWithZ(const Types::TRect &Rect, int Z);
	virtual void __fastcall Sphere(int x, int y, int z, const double Radius)/* overload */;
	virtual void __fastcall Surface3D(TTeeCanvasSurfaceStyle Style, bool SameBrush, int NumXValues, int NumZValues, TTeeCanvasCalcPoints CalcPoints);
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
	virtual void __fastcall Triangle3D(const TPoint3D * Points, const Graphics::TColor * Colors);
	virtual void __fastcall TriangleWithZ(const Types::TPoint &P1, const Types::TPoint &P2, const Types::TPoint &P3, int Z);
	__property Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap};
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Arc(const int Left, const int Top, const int Right, const int Bottom, double StartAngle, double EndAngle){ TTeeCanvas::Arc(Left, Top, Right, Bottom, StartAngle, EndAngle); }
	inline void __fastcall  Ellipse(const Types::TRect &R){ TTeeCanvas::Ellipse(R); }
	inline void __fastcall  LineTo(const Types::TPoint &P){ TTeeCanvas::LineTo(P); }
	inline void __fastcall  MoveTo(const Types::TPoint &P){ TTeeCanvas::MoveTo(P); }
	inline void __fastcall  Rectangle(const Types::TRect &R, int Z){ TCanvas3D::Rectangle(R, Z); }
	inline void __fastcall  Rectangle(int X0, int Y0, int X1, int Y1, int Z){ TCanvas3D::Rectangle(X0, Y0, X1, Y1, Z); }
	inline void __fastcall  Rectangle(const Types::TRect &R){ TTeeCanvas::Rectangle(R); }
	inline void __fastcall  RoundRect(const Types::TRect &R, int X, int Y){ TTeeCanvas::RoundRect(R, X, Y); }
	inline void __fastcall  StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic, int Pos, TCanvas3DPlane Plane = (TCanvas3DPlane)(0x2)){ TCanvas3D::StretchDraw(Rect, Graphic, Pos, Plane); }
	inline void __fastcall  TextOut(int X, int Y, const AnsiString Text, bool AllowHtml){ TTeeCanvas::TextOut(X, Y, Text, AllowHtml); }
	inline void __fastcall  ClipRectangle(const Types::TRect &Rect, int RoundSize){ TTeeCanvas::ClipRectangle(Rect, RoundSize); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size, int Z){ TCanvas3D::Polyline(Points, Points_Size, Z); }
	inline Types::TPoint __fastcall  Calculate3DPosition(const TPoint3D &P){ return TCanvas3D::Calculate3DPosition(P); }
	inline Types::TPoint __fastcall  Calculate3DPosition(const Types::TPoint &P, int z){ return TCanvas3D::Calculate3DPosition(P, z); }
	inline void __fastcall  Arrow(bool Filled, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight, int Z){ TCanvas3D::Arrow(Filled, FromPoint, ToPoint, ArrowWidth, ArrowHeight, Z); }
	inline void __fastcall  Arrow(bool Filled, const double ArrowPercent, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight){ TTeeCanvas::Arrow(Filled, ArrowPercent, FromPoint, ToPoint, ArrowWidth, ArrowHeight); }
	inline void __fastcall  Cube(const Types::TRect &R, int Z0, int Z1, bool DarkSides = true){ TCanvas3D::Cube(R, Z0, Z1, DarkSides); }
	inline void __fastcall  EllipseWithZ(const Types::TRect &Rect, int Z){ TCanvas3D::EllipseWithZ(Rect, Z); }
	inline void __fastcall  PlaneWithZ(const Types::TPoint * P, int Z){ TCanvas3D::PlaneWithZ(P, Z); }
	
};


typedef Graphics::TColor __fastcall (__closure *TButtonGetColorProc)(void);

class DELPHICLASS TTeeButton;
class PASCALIMPLEMENTATION TTeeButton : public Stdctrls::TButton 
{
	typedef Stdctrls::TButton inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	
protected:
	System::TObject* Instance;
	Typinfo::TPropInfo *Info;
	virtual void __fastcall DrawSymbol(TTeeCanvas* ACanvas);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	virtual void __fastcall PaintWindow(HDC DC);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	Types::TRect __fastcall SymbolRectangle();
	
public:
	void __fastcall LinkProperty(System::TObject* AInstance, const AnsiString PropName);
	
__published:
	__property Height  = {default=25};
	__property Width  = {default=75};
public:
	#pragma option push -w-inl
	/* TButton.Create */ inline __fastcall virtual TTeeButton(Classes::TComponent* AOwner) : Stdctrls::TButton(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeButton(HWND ParentWindow) : Stdctrls::TButton(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TTeeButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TButtonColor;
class PASCALIMPLEMENTATION TButtonColor : public TTeeButton 
{
	typedef TTeeButton inherited;
	
private:
	Graphics::TColor FSymbolColor;
	Graphics::TColor __fastcall GetSymbolColor(void);
	void __fastcall SetSymbolColor(const Graphics::TColor Value);
	
protected:
	virtual void __fastcall DrawSymbol(TTeeCanvas* ACanvas);
	
public:
	TButtonGetColorProc GetColorProc;
	DYNAMIC void __fastcall Click(void);
	__property Graphics::TColor SymbolColor = {read=GetSymbolColor, write=SetSymbolColor, nodefault};
public:
	#pragma option push -w-inl
	/* TButton.Create */ inline __fastcall virtual TButtonColor(Classes::TComponent* AOwner) : TTeeButton(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TButtonColor(HWND ParentWindow) : TTeeButton(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TButtonColor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComboFlat;
class PASCALIMPLEMENTATION TComboFlat : public Stdctrls::TComboBox 
{
	typedef Stdctrls::TComboBox inherited;
	
private:
	bool Inside;
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMFocusChanged(Controls::TCMFocusChanged &Message);
	int __fastcall GetDropWidth(void);
	bool __fastcall IsDropWidthStored(void);
	void __fastcall SetDropWidth(const int Value);
	
public:
	__fastcall virtual TComboFlat(Classes::TComponent* AOwner);
	void __fastcall Add(const AnsiString Item);
	AnsiString __fastcall CurrentItem();
	System::TObject* __fastcall SelectedObject(void);
	
__published:
	__property int DropDownWidth = {read=GetDropWidth, write=SetDropWidth, stored=IsDropWidthStored, nodefault};
	__property Height  = {default=21};
	__property ItemHeight  = {default=13};
	__property ItemIndex  = {default=-1};
	__property Style  = {default=2};
public:
	#pragma option push -w-inl
	/* TCustomComboBox.Destroy */ inline __fastcall virtual ~TComboFlat(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TComboFlat(HWND ParentWindow) : Stdctrls::TComboBox(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSmoothStretchOption { ssBestQuality, ssBestPerformance };
#pragma option pop

typedef void __fastcall (*TGradientRotate)(TCustomTeeGradient* Gradient, Graphics::TBitmap* Bitmap);

__interface ICanvasHyperlinks;
typedef System::DelphiInterface<ICanvasHyperlinks> _di_ICanvasHyperlinks;
__interface INTERFACE_UUID("{84DBB276-CBD2-4BBB-AC31-AACBF8B6F34C}") ICanvasHyperlinks  : public IInterface 
{
	
public:
	virtual void __fastcall AddLink(int x, int y, const AnsiString Text, const AnsiString URL, const AnsiString Hint) = 0 ;
};

__interface ICanvasToolTips;
typedef System::DelphiInterface<ICanvasToolTips> _di_ICanvasToolTips;
__interface INTERFACE_UUID("{03EBCB55-D01F-4CA8-8A2F-48EB3BEBC5E3}") ICanvasToolTips  : public IInterface 
{
	
public:
	virtual void __fastcall AddToolTip(const AnsiString Entity, const AnsiString ToolTip) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeDefaultPerspective = 0xf;
static const Word TeeMinAngle = 0x10e;
static const Shortint NumCirclePoints = 0x40;
extern PACKAGE Types::TRect TeeZeroRect;
extern PACKAGE int TeeDefaultConePercent;
extern PACKAGE bool TeeCheckPenWidth;
static const char TeeCharForHeight = '\x57';
extern PACKAGE Byte DarkerColorQuantity;
extern PACKAGE Byte DarkColorQuantity;
extern PACKAGE bool IsWindowsNT;
extern PACKAGE int GetDefaultFontSize;
extern PACKAGE AnsiString GetDefaultFontName;
#define TeePixelFormat (Graphics::TPixelFormat)(6)
extern PACKAGE Classes::TStrings* TeeCustomEditColors;
extern PACKAGE Byte TeeFontAntiAlias;
extern PACKAGE unsigned __stdcall (*TeeSetDCBrushColor)(HDC DC, unsigned Color);
extern PACKAGE unsigned __stdcall (*TeeSetDCPenColor)(HDC DC, unsigned Color);
extern PACKAGE int TeeNumCylinderSides;
extern PACKAGE TGradientRotate TeeGradientRotate;
extern PACKAGE bool __fastcall TeeCull(const Types::TPoint &P0, const Types::TPoint &P1, const Types::TPoint &P2)/* overload */;
extern PACKAGE bool __fastcall TeeCull(const Types::TPoint * P)/* overload */;
extern PACKAGE Types::TPoint __fastcall TeePoint(const int aX, const int aY);
extern PACKAGE bool __fastcall PointInRect(const Types::TRect &Rect, int x, int y)/* overload */;
extern PACKAGE bool __fastcall PointInRect(const Types::TRect &Rect, const Types::TPoint &P)/* overload */;
extern PACKAGE Types::TRect __fastcall TeeRect(int Left, int Top, int Right, int Bottom);
extern PACKAGE Types::TRect __fastcall OrientRectangle(const Types::TRect &R);
extern PACKAGE TPoint3D __fastcall Point3D(const int x, const int y, const int z);
extern PACKAGE void __fastcall RectSize(const Types::TRect &R, int &RectWidth, int &RectHeight);
extern PACKAGE void __fastcall RectCenter(const Types::TRect &R, int &X, int &Y);
extern PACKAGE void __fastcall TeeSetBitmapSize(Graphics::TBitmap* Bitmap, int Width, int Height);
extern PACKAGE Types::TRect __fastcall PolygonBounds(const Types::TPoint * P, const int P_Size);
extern PACKAGE bool __fastcall PolygonInPolygon(const Types::TPoint * A, const int A_Size, const Types::TPoint * B, const int B_Size);
extern PACKAGE TRGB __fastcall RGBValue(const Graphics::TColor Color);
extern PACKAGE HPEN __fastcall TeeCreatePenSmallDots(const Graphics::TColor AColor, const int Space = 0x0);
extern PACKAGE void __fastcall TeeSetTeePen(Graphics::TPen* FPen, TChartPen* APen, Graphics::TColor AColor, HDC Handle);
extern PACKAGE void __fastcall ClipCanvas(Graphics::TCanvas* ACanvas, const Types::TRect &Rect);
extern PACKAGE void __fastcall ClipEllipse(TTeeCanvas* ACanvas, const Types::TRect &Rect);
extern PACKAGE void __fastcall ClipRoundRectangle(TTeeCanvas* ACanvas, const Types::TRect &Rect, int RoundSize);
extern PACKAGE void __fastcall ClipPolygon(TTeeCanvas* ACanvas, const Types::TPoint * Points, const int Points_Size, int NumPoints);
extern PACKAGE Types::TRect __fastcall RectFromPolygon(const Types::TPoint * Points, const int Points_Size, int NumPoints);
extern PACKAGE Types::TRect __fastcall RectFromTriangle(const Types::TPoint * Points);
extern PACKAGE bool __fastcall RectangleInRectangle(const Types::TRect &Small, const Types::TRect &Big);
extern PACKAGE void __fastcall UnClipCanvas(Graphics::TCanvas* ACanvas);
extern PACKAGE Graphics::TColor __fastcall ApplyDark(Graphics::TColor Color, Byte HowMuch);
extern PACKAGE Graphics::TColor __fastcall ApplyBright(Graphics::TColor Color, Byte HowMuch);
extern PACKAGE void __fastcall TeeCalcLines(TRGBArray &Lines, Graphics::TBitmap* Bitmap);
extern PACKAGE void __fastcall TeeShadowSmooth(Graphics::TBitmap* Bitmap, Graphics::TBitmap* Back, int Left, int Top, int Width, int Height, int horz, int vert, double Smoothness, bool FullDraw, TCanvas3D* ACanvas, bool Clip);
extern PACKAGE void __fastcall SwapDouble(double &a, double &b);
extern PACKAGE void __fastcall SwapInteger(int &a, int &b);
extern PACKAGE void __fastcall TeeBlendBitmaps(const double Percent, Graphics::TBitmap* ABitmap, Graphics::TBitmap* BBitmap, const Types::TPoint &BOrigin);
extern PACKAGE Graphics::TColor __fastcall EditColor(Classes::TComponent* AOwner, Graphics::TColor AColor);
extern PACKAGE bool __fastcall EditColorDialog(Classes::TComponent* AOwner, Graphics::TColor &AColor);
extern PACKAGE Types::TPoint __fastcall PointAtDistance(const Types::TPoint &AFrom, const Types::TPoint &ATo, int ADist);
extern PACKAGE double __fastcall TeeDistance(const double x, const double y);
extern PACKAGE void __fastcall SmoothStretch(Graphics::TBitmap* Src, Graphics::TBitmap* Dst)/* overload */;
extern PACKAGE void __fastcall SmoothStretch(Graphics::TBitmap* Src, Graphics::TBitmap* Dst, TSmoothStretchOption Option)/* overload */;
extern PACKAGE unsigned __fastcall TeeLoadLibrary(const AnsiString FileName);
extern PACKAGE void __fastcall TeeFreeLibrary(unsigned hLibModule);

}	/* namespace Tecanvas */
using namespace Tecanvas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeCanvas
