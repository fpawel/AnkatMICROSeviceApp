// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeNumericGauge.pas' rev: 6.00

#ifndef TeeNumericGaugeHPP
#define TeeNumericGaugeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeEditTools.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teenumericgauge
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TNumericMarker;
class DELPHICLASS TNumericGauge;
class DELPHICLASS TCustomGauge;
class DELPHICLASS TFramedBorder;
class DELPHICLASS TFrameBrush;
class PASCALIMPLEMENTATION TFrameBrush : public Tecanvas::TChartBrush 
{
	typedef Tecanvas::TChartBrush inherited;
	
private:
	Tecanvas::TTeeGradient* FGradient;
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	
public:
	__fastcall virtual TFrameBrush(Classes::TNotifyEvent OnChangeEvent);
	__fastcall virtual ~TFrameBrush(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
};


class PASCALIMPLEMENTATION TFramedBorder : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TFrameBrush* FBrush;
	bool FCircled;
	TFrameBrush* FInner;
	TFrameBrush* FMiddle;
	TFrameBrush* FOuter;
	Tecanvas::TTeeShadow* FShadow;
	bool FVisible;
	int FWidth;
	Teengine::TChartSeries* IOwner;
	void __fastcall GetPalette(void);
	bool __fastcall IsCircledStored(void);
	void __fastcall SetBrush(const TFrameBrush* Value);
	void __fastcall SetCircled(const bool Value);
	void __fastcall SetInner(const TFrameBrush* Value);
	void __fastcall SetMiddle(const TFrameBrush* Value);
	void __fastcall SetOuter(const TFrameBrush* Value);
	void __fastcall SetShadow(const Tecanvas::TTeeShadow* Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	bool DefaultCircled;
	int __fastcall CalcWidth(const Types::TRect &R);
	void __fastcall Draw(const Types::TRect &R);
	void __fastcall SetDefaultCircled(const bool Value);
	
public:
	__fastcall TFramedBorder(Teengine::TChartSeries* AOwner);
	__fastcall virtual ~TFramedBorder(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TFrameBrush* Brush = {read=FBrush, write=SetBrush};
	__property bool Circled = {read=FCircled, write=SetCircled, stored=IsCircledStored, nodefault};
	__property TFrameBrush* InnerBrush = {read=FInner, write=SetInner};
	__property TFrameBrush* MiddleBrush = {read=FMiddle, write=SetMiddle};
	__property TFrameBrush* OuterBrush = {read=FOuter, write=SetOuter};
	__property Tecanvas::TTeeShadow* Shadow = {read=FShadow, write=SetShadow};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=10};
};


class PASCALIMPLEMENTATION TCustomGauge : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Teeprocs::TTeeShape* FFace;
	TFramedBorder* FFrame;
	Classes::TNotifyEvent FOnChange;
	double __fastcall GetValue(void);
	void __fastcall SetFace(const Teeprocs::TTeeShape* Value);
	void __fastcall SetFrame(const TFramedBorder* Value);
	
protected:
	bool ICircled;
	#pragma pack(push, 1)
	Types::TRect INewRect;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TRect IOrigRect;
	#pragma pack(pop)
	
	virtual void __fastcall CalcOrigRect(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawFace(void);
	virtual void __fastcall SetGaugePalette(const Graphics::TColor * Palette, const int Palette_Size);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetValue(const double AValue);
	virtual void __fastcall SetValues(void);
	
public:
	DynamicArray<Graphics::TColor >  GaugeColorPalette;
	__fastcall virtual TCustomGauge(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomGauge(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	Graphics::TColor __fastcall GetPaletteColor(int Index);
	__property Teeprocs::TTeeShape* Face = {read=FFace, write=SetFace};
	__property TFramedBorder* Frame = {read=FFrame, write=SetFrame};
	__property double Value = {read=GetValue, write=SetValue};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


#pragma option push -b-
enum TDigitalFont { dfBar, dfDot, dfCustom };
#pragma option pop

class DELPHICLASS TNumericMarkers;
class PASCALIMPLEMENTATION TNumericMarkers : public Teengine::TChartTools 
{
	typedef Teengine::TChartTools inherited;
	
public:
	TNumericMarker* operator[](int Index) { return Items[Index]; }
	
private:
	TNumericGauge* FGauge;
	HIDESBASE TNumericMarker* __fastcall Get(int Index);
	HIDESBASE void __fastcall Put(int Index, const TNumericMarker* Value);
	void __fastcall SetParentChart(const Teeprocs::TCustomTeePanel* Value);
	
public:
	HIDESBASE TNumericMarker* __fastcall Add(const AnsiString AText)/* overload */;
	HIDESBASE TNumericMarker* __fastcall Add(const AnsiString AText, int FontSize, Teetools::TAnnotationPosition APosition, int FontColor, int ShapeColor)/* overload */;
	HIDESBASE void __fastcall Assign(TNumericMarkers* Source)/* overload */;
	__property TNumericMarker* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TNumericMarkers(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TNumericMarkers(void) : Teengine::TChartTools() { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline Teengine::TTeeCustomTool* __fastcall  Add(Teengine::TTeeCustomTool* Tool){ return TChartTools::Add(Tool); }
	inline Teengine::TTeeCustomTool* __fastcall  Add(TMetaClass* Tool){ return TChartTools::Add(Tool); }
	
};


class PASCALIMPLEMENTATION TNumericGauge : public TCustomGauge 
{
	typedef TCustomGauge inherited;
	
private:
	TDigitalFont FFont;
	TNumericMarkers* FMarkers;
	void __fastcall ChangeValueMarker(void);
	TNumericMarker* __fastcall GetTextMarker(void);
	TNumericMarker* __fastcall GetUnitsMarker(void);
	TNumericMarker* __fastcall GetValueMarker(void);
	void __fastcall SetFont(const TDigitalFont Value);
	void __fastcall SetMarkers(const TNumericMarkers* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool Sequential = false);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DrawAllValues(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	void __fastcall ReadMarkers(Classes::TStream* Stream);
	virtual void __fastcall SetGaugePalette(const Graphics::TColor * Palette, const int Palette_Size);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	virtual void __fastcall SetValue(const double Value);
	virtual void __fastcall SetValueFormat(const AnsiString Value);
	void __fastcall WriteMarkers(Classes::TStream* Stream);
	
public:
	__fastcall virtual TNumericGauge(Classes::TComponent* AOwner);
	__fastcall virtual ~TNumericGauge(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	DYNAMIC int __fastcall NumSampleValues(void);
	virtual bool __fastcall UseAxis(void);
	__property TNumericMarkers* Markers = {read=FMarkers, write=SetMarkers};
	__property TNumericMarker* TextMarker = {read=GetTextMarker};
	__property TNumericMarker* UnitsMarker = {read=GetUnitsMarker};
	__property TNumericMarker* ValueMarker = {read=GetValueMarker};
	
__published:
	__property Active  = {default=1};
	__property Cursor  = {default=0};
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnChange ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	__property XValues ;
	__property YValues ;
	__property TDigitalFont DigitalFont = {read=FFont, write=SetFont, default=0};
	__property Face ;
	__property Frame ;
	__property Value ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class PASCALIMPLEMENTATION TNumericMarker : public Teetools::TAnnotationTool 
{
	typedef Teetools::TAnnotationTool inherited;
	
private:
	TNumericGauge* FGauge;
	
public:
	__fastcall virtual ~TNumericMarker(void);
	__property TNumericGauge* Gauge = {read=FGauge};
public:
	#pragma option push -w-inl
	/* TAnnotationTool.Create */ inline __fastcall virtual TNumericMarker(Classes::TComponent* AOwner) : Teetools::TAnnotationTool(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TMarkersEditor;
class PASCALIMPLEMENTATION TMarkersEditor : public Teeedittools::TFormTeeTools 
{
	typedef Teeedittools::TFormTeeTools inherited;
	
protected:
	virtual Teengine::TTeeCustomTool* __fastcall CloneTool(Teengine::TTeeCustomTool* Tool);
	virtual Teengine::TTeeCustomTool* __fastcall GetNewTool(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMarkersEditor(Classes::TComponent* AOwner) : Teeedittools::TFormTeeTools(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMarkersEditor(Classes::TComponent* AOwner, int Dummy) : Teeedittools::TFormTeeTools(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMarkersEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMarkersEditor(HWND ParentWindow) : Teeedittools::TFormTeeTools(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TNumericGaugeEditor;
class PASCALIMPLEMENTATION TNumericGaugeEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EValue;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBPalette;
	Extctrls::TRadioGroup* RGFont;
	Comctrls::TTabSheet* TabSheet3;
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabSheet4;
	Comctrls::TTabSheet* TabSheet5;
	Comctrls::TTabSheet* TabSheet6;
	Comctrls::TTabSheet* TabFace;
	Comctrls::TTabSheet* TabSheet8;
	Stdctrls::TLabel* Label3;
	Stdctrls::TCheckBox* CBFrameVisible;
	Stdctrls::TEdit* EWidth;
	Comctrls::TUpDown* UDWidth;
	Buttons::TSpeedButton* SpeedButton1;
	Buttons::TSpeedButton* SpeedButton2;
	Comctrls::TTabSheet* TabShadow;
	Stdctrls::TButton* BBrush;
	Teeedigrad::TButtonGradient* BGradient;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGFontClick(System::TObject* Sender);
	void __fastcall CBPaletteChange(System::TObject* Sender);
	void __fastcall CBFrameVisibleClick(System::TObject* Sender);
	void __fastcall EWidthChange(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall SpeedButton2Click(System::TObject* Sender);
	void __fastcall EValueChange(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	
private:
	TMarkersEditor* Tools;
	void __fastcall IncValue(int Delta);
	
protected:
	TCustomGauge* Gauge;
	
public:
	/*         class method */ static void __fastcall AddBrushDialog(TMetaClass* vmt, TFrameBrush* ABrush, Controls::TWinControl* AParent);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TNumericGaugeEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TNumericGaugeEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TNumericGaugeEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TNumericGaugeEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teenumericgauge */
using namespace Teenumericgauge;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeNumericGauge
