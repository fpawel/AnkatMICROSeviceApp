// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFilters.pas' rev: 6.00

#ifndef TeeFiltersHPP
#define TeeFiltersHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teefilters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TResizeFilter;
class PASCALIMPLEMENTATION TResizeFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FWidth;
	int FHeight;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int Width = {read=FWidth, write=FWidth, default=0};
	__property int Height = {read=FHeight, write=FHeight, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TResizeFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TResizeFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TCropFilter;
class PASCALIMPLEMENTATION TCropFilter : public TResizeFilter 
{
	typedef TResizeFilter inherited;
	
private:
	int FLeft;
	bool FSmooth;
	int FTop;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int Left = {read=FLeft, write=FLeft, default=0};
	__property bool Smooth = {read=FSmooth, write=FSmooth, default=0};
	__property int Top = {read=FTop, write=FTop, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TCropFilter(Classes::TCollection* Collection) : TResizeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TCropFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TInvertFilter;
class PASCALIMPLEMENTATION TInvertFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TInvertFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TInvertFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


#pragma option push -b-
enum TGrayMethod { gmSimple, gmEye, gmEye2 };
#pragma option pop

class DELPHICLASS TGrayScaleFilter;
class PASCALIMPLEMENTATION TGrayScaleFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	TGrayMethod FMethod;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property TGrayMethod Method = {read=FMethod, write=FMethod, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TGrayScaleFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TGrayScaleFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TFlipFilter;
class PASCALIMPLEMENTATION TFlipFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TFlipFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TFlipFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TReverseFilter;
class PASCALIMPLEMENTATION TReverseFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TReverseFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TReverseFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TAmountFilter;
class PASCALIMPLEMENTATION TAmountFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FAmount;
	bool FPercent;
	Stdctrls::TScrollBar* FScrollBar;
	bool IOnlyPositive;
	void __fastcall ResetScroll(System::TObject* Sender);
	int __fastcall ScrollMin(void);
	int __fastcall ScrollMax(void);
	
public:
	__fastcall virtual TAmountFilter(Classes::TCollection* Collection);
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	
__published:
	__property bool Percent = {read=FPercent, write=FPercent, default=1};
	__property int Amount = {read=FAmount, write=FAmount, default=5};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TAmountFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMosaicFilter;
class PASCALIMPLEMENTATION TMosaicFilter : public TAmountFilter 
{
	typedef TAmountFilter inherited;
	
public:
	__fastcall virtual TMosaicFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TMosaicFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TBrightnessFilter;
class PASCALIMPLEMENTATION TBrightnessFilter : public TAmountFilter 
{
	typedef TAmountFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TAmountFilter.Create */ inline __fastcall virtual TBrightnessFilter(Classes::TCollection* Collection) : TAmountFilter(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TBrightnessFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TContrastFilter;
class PASCALIMPLEMENTATION TContrastFilter : public TAmountFilter 
{
	typedef TAmountFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TAmountFilter.Create */ inline __fastcall virtual TContrastFilter(Classes::TCollection* Collection) : TAmountFilter(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TContrastFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TColorFilter;
class PASCALIMPLEMENTATION TColorFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FBlue;
	int FGreen;
	int FRed;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int Red = {read=FRed, write=FRed, default=0};
	__property int Green = {read=FGreen, write=FGreen, default=0};
	__property int Blue = {read=FBlue, write=FBlue, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual TColorFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TColorFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS THueLumSatFilter;
class PASCALIMPLEMENTATION THueLumSatFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FHue;
	int FLum;
	int FSat;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int Hue = {read=FHue, write=FHue, default=0};
	__property int Luminance = {read=FLum, write=FLum, default=0};
	__property int Saturation = {read=FSat, write=FSat, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Create */ inline __fastcall virtual THueLumSatFilter(Classes::TCollection* Collection) : Tecanvas::TTeeFilter(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~THueLumSatFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TSharpenFilter;
class PASCALIMPLEMENTATION TSharpenFilter : public Tecanvas::TConvolveFilter 
{
	typedef Tecanvas::TConvolveFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TConvolveFilter.Create */ inline __fastcall virtual TSharpenFilter(Classes::TCollection* Collection) : Tecanvas::TConvolveFilter(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TSharpenFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TEmbossFilter;
class PASCALIMPLEMENTATION TEmbossFilter : public Tecanvas::TConvolveFilter 
{
	typedef Tecanvas::TConvolveFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TConvolveFilter.Create */ inline __fastcall virtual TEmbossFilter(Classes::TCollection* Collection) : Tecanvas::TConvolveFilter(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TEmbossFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TSoftenFilter;
class PASCALIMPLEMENTATION TSoftenFilter : public Tecanvas::TConvolveFilter 
{
	typedef Tecanvas::TConvolveFilter inherited;
	
public:
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TConvolveFilter.Create */ inline __fastcall virtual TSoftenFilter(Classes::TCollection* Collection) : Tecanvas::TConvolveFilter(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TSoftenFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TGammaCorrectionFilter;
class PASCALIMPLEMENTATION TGammaCorrectionFilter : public TAmountFilter 
{
	typedef TAmountFilter inherited;
	
public:
	__fastcall virtual TGammaCorrectionFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property Amount  = {default=70};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TGammaCorrectionFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TRotateFilter;
class PASCALIMPLEMENTATION TRotateFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	double FAngle;
	bool FAutoSize;
	Graphics::TColor FBackColor;
	void __fastcall SetAngle(const double Value);
	
public:
	__fastcall virtual TRotateFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property double Angle = {read=FAngle, write=SetAngle};
	__property bool AutoSize = {read=FAutoSize, write=FAutoSize, default=1};
	__property Graphics::TColor BackColor = {read=FBackColor, write=FBackColor, default=16777215};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TRotateFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


#pragma option push -b-
enum TMirrorDirection { mdDown, mdUp, mdRight, mdLeft };
#pragma option pop

class DELPHICLASS TMirrorFilter;
class PASCALIMPLEMENTATION TMirrorFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	TMirrorDirection FDirection;
	
public:
	__fastcall virtual TMirrorFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property TMirrorDirection Direction = {read=FDirection, write=FDirection, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TMirrorFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TTileFilter;
class PASCALIMPLEMENTATION TTileFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FNumCols;
	int FNumRows;
	
public:
	__fastcall virtual TTileFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int NumCols = {read=FNumCols, write=FNumCols, default=3};
	__property int NumRows = {read=FNumRows, write=FNumRows, default=3};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TTileFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TBevelFilter;
class PASCALIMPLEMENTATION TBevelFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FBright;
	int FSize;
	
public:
	__fastcall virtual TBevelFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int Bright = {read=FBright, write=FBright, default=64};
	__property int Size = {read=FSize, write=FSize, default=15};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TBevelFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TZoomFilter;
class PASCALIMPLEMENTATION TZoomFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	double FPercent;
	bool FSmooth;
	
public:
	__fastcall virtual TZoomFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property double Percent = {read=FPercent, write=FPercent};
	__property bool Smooth = {read=FSmooth, write=FSmooth, default=0};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TZoomFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TImageFiltered;
class PASCALIMPLEMENTATION TImageFiltered : public Extctrls::TImage 
{
	typedef Extctrls::TImage inherited;
	
private:
	Tecanvas::TFilterItems* FFilters;
	bool __fastcall FiltersStored(void);
	void __fastcall ReadFilters(Classes::TReader* Reader);
	void __fastcall SetFilters(const Tecanvas::TFilterItems* Value);
	void __fastcall WriteFilters(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TImageFiltered(Classes::TComponent* AOwner);
	__fastcall virtual ~TImageFiltered(void);
	Graphics::TBitmap* __fastcall Filtered(void);
	
__published:
	__property Tecanvas::TFilterItems* Filters = {read=FFilters, write=SetFilters, stored=false};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Classes::TList* FilterClasses;
extern PACKAGE void __fastcall TeeRegisterFilters(TMetaClass* * FilterList, const int FilterList_Size);
extern PACKAGE void __fastcall TeeUnRegisterFilters(TMetaClass* * FilterList, const int FilterList_Size);
extern PACKAGE void __fastcall ColorToHLS(Graphics::TColor Color, /* out */ Word &Hue, /* out */ Word &Luminance, /* out */ Word &Saturation);
extern PACKAGE void __fastcall RGBToHLS(const Tecanvas::TRGB Color, /* out */ Word &Hue, /* out */ Word &Luminance, /* out */ Word &Saturation);
extern PACKAGE Graphics::TColor __fastcall HLSToColor(Word Hue, Word Luminance, Word Saturation);
extern PACKAGE void __fastcall HLSToRGB(Word Hue, Word Luminance, Word Saturation, /* out */ Tecanvas::TRGB &rgb);
extern PACKAGE void __fastcall TeeGrayScale(Graphics::TBitmap* ABitmap, bool Inverted, int AMethod);

}	/* namespace Teefilters */
using namespace Teefilters;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFilters
