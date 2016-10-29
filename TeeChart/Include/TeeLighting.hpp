// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLighting.pas' rev: 6.00

#ifndef TeeLightingHPP
#define TeeLightingHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeeComma.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teelighting
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TLightStyle { lsLinear, lsSpotLight };
#pragma option pop

class DELPHICLASS TLightFilter;
class PASCALIMPLEMENTATION TLightFilter : public Tecanvas::TTeeFilter 
{
	typedef Tecanvas::TTeeFilter inherited;
	
private:
	int FTop;
	int FLeft;
	int FFactor;
	TLightStyle FStyle;
	void __fastcall SetFactor(const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetStyle(const TLightStyle Value);
	void __fastcall SetTop(const int Value);
	
public:
	__fastcall virtual TLightFilter(Classes::TCollection* Collection);
	virtual void __fastcall Apply(Graphics::TBitmap* Bitmap, const Types::TRect &R)/* overload */;
	virtual void __fastcall CreateEditor(Tecanvas::_di_IFormCreator Creator, Classes::TNotifyEvent AChanged);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	
__published:
	__property int Factor = {read=FFactor, write=SetFactor, default=10};
	__property int Left = {read=FLeft, write=SetLeft, default=-1};
	__property TLightStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property int Top = {read=FTop, write=SetTop, default=-1};
public:
	#pragma option push -w-inl
	/* TTeeFilter.Destroy */ inline __fastcall virtual ~TLightFilter(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Apply(Graphics::TBitmap* Bitmap){ TTeeFilter::Apply(Bitmap); }
	
};


class DELPHICLASS TLightTool;
class PASCALIMPLEMENTATION TLightTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	TLightFilter* FFilter;
	bool FMouse;
	Graphics::TBitmap* Buffer;
	bool InsideLighting;
	void __fastcall SetFactor(const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetStyle(const TLightStyle Value);
	void __fastcall SetTop(const int Value);
	int __fastcall GetFactor(void);
	int __fastcall GetLeft(void);
	TLightStyle __fastcall GetStyle(void);
	int __fastcall GetTop(void);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton AButton, Classes::TShiftState AShift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TLightTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TLightTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	void __fastcall Iluminate(void);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property int Factor = {read=GetFactor, write=SetFactor, default=10};
	__property bool FollowMouse = {read=FMouse, write=FMouse, default=0};
	__property int Left = {read=GetLeft, write=SetLeft, default=-1};
	__property TLightStyle Style = {read=GetStyle, write=SetStyle, default=0};
	__property int Top = {read=GetTop, write=SetTop, default=-1};
};


class DELPHICLASS TLightToolEditor;
class PASCALIMPLEMENTATION TLightToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CheckBox2;
	Stdctrls::TLabel* Label1;
	Comctrls::TTrackBar* TBLeft;
	Comctrls::TTrackBar* TBTop;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBStyle;
	Comctrls::TTrackBar* TBFactor;
	Stdctrls::TLabel* Label4;
	void __fastcall CheckBox2Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall TBFactorChange(System::TObject* Sender);
	void __fastcall TBTopChange(System::TObject* Sender);
	void __fastcall TBLeftChange(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	
private:
	bool CreatingForm;
	TLightTool* Light;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLightToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLightToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLightToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLightToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teelighting */
using namespace Teelighting;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLighting
