// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCircularGauge.pas' rev: 6.00

#ifndef TeeCircularGaugeHPP
#define TeeCircularGaugeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeNumericGauge.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeLinearGauge.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecirculargauge
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGaugeHand;
class PASCALIMPLEMENTATION TGaugeHand : public Teelineargauge::TGaugeSeriesPointer 
{
	typedef Teelineargauge::TGaugeSeriesPointer inherited;
	
private:
	int FOffset;
	int FDistance;
	void __fastcall SetDistance(const int Value);
	void __fastcall SetOffset(const int Value);
	
public:
	__fastcall TGaugeHand(Teengine::TChartSeries* AOwner);
	HIDESBASE void __fastcall Draw(const double Angle, const Types::TPoint &Center, int Off);
	
__published:
	__property int Distance = {read=FDistance, write=SetDistance, default=80};
	__property int Offset = {read=FOffset, write=SetOffset, default=30};
public:
	#pragma option push -w-inl
	/* TSeriesPointer.Destroy */ inline __fastcall virtual ~TGaugeHand(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCircularGauge;
class PASCALIMPLEMENTATION TCircularGauge : public Teelineargauge::TCustomGaugeMinMax 
{
	typedef Teelineargauge::TCustomGaugeMinMax inherited;
	
private:
	Teelineargauge::TGaugeSeriesPointer* FCenter;
	Teengine::TSeriesPointer* FEndPoint;
	TGaugeHand* FHand;
	bool FLabelsInside;
	bool FRotateLabels;
	double FTotalAngle;
	double IAngleInc;
	#pragma pack(push, 1)
	Types::TPoint ICenter;
	#pragma pack(pop)
	
	double IStartAngle;
	bool FCircled;
	double FRotAngle;
	int FXRadius;
	int FYRadius;
	double __fastcall CalcAngleFromLength(const Types::TPoint &Point, const double Length);
	int __fastcall CalcDistance(int Distance);
	Types::TPoint __fastcall CalcPoint(const double Angle, const Types::TPoint &Center, const double RadiusX, const double RadiusY);
	void __fastcall CalcRadius(void);
	double __fastcall CalcStartAngle(void);
	double __fastcall CalcSweepAngle(void);
	double __fastcall CalcValue(const double AValue);
	HIDESBASE void __fastcall DrawAxisMinorTick(const Types::TPoint &Inner, const Types::TPoint &Outer);
	HIDESBASE void __fastcall DrawAxisTick(const Types::TPoint &Inner, const Types::TPoint &InnerPlus, const Types::TPoint &InnerMinus, const Types::TPoint &Outer, const Types::TPoint &OuterPlus, const Types::TPoint &OuterMinus);
	void __fastcall DrawCenter(void);
	void __fastcall DrawColorLines(void);
	void __fastcall DrawEnd(double Angle);
	void __fastcall SetCenter(const Teelineargauge::TGaugeSeriesPointer* Value);
	void __fastcall SetCircled(const bool Value);
	void __fastcall SetEndPoint(const Teengine::TSeriesPointer* Value);
	HIDESBASE void __fastcall SetHand(const TGaugeHand* Value);
	void __fastcall SetLabelsInside(const bool Value);
	void __fastcall SetRotateLabels(const bool Value);
	void __fastcall SetRotAngle(const double Value);
	void __fastcall SetTotalAngle(const double Value);
	
protected:
	virtual Teengine::TChartAxis* __fastcall Axis(void);
	virtual void __fastcall CalcOrigRect(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAxis(void);
	virtual void __fastcall DrawFace(void);
	virtual void __fastcall DrawHand(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetValues(void);
	
public:
	__fastcall virtual TCircularGauge(Classes::TComponent* AOwner);
	__fastcall virtual ~TCircularGauge(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall UseAxis(void);
	int __fastcall CircleXCenter(void);
	int __fastcall CircleYCenter(void);
	__property int XRadius = {read=FXRadius, nodefault};
	__property int YRadius = {read=FYRadius, nodefault};
	
__published:
	__property Active  = {default=1};
	__property Cursor  = {default=0};
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property ShowInLegend  = {default=0};
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
	__property Teelineargauge::TGaugeSeriesPointer* Center = {read=FCenter, write=SetCenter};
	__property bool Circled = {read=FCircled, write=SetCircled, default=1};
	__property Teengine::TSeriesPointer* EndPoint = {read=FEndPoint, write=SetEndPoint};
	__property Face ;
	__property Frame ;
	__property GreenLine ;
	__property TGaugeHand* Hand = {read=FHand, write=SetHand};
	__property bool LabelsInside = {read=FLabelsInside, write=SetLabelsInside, default=1};
	__property Maximum ;
	__property Minimum ;
	__property MinorTickDistance  = {default=3};
	__property MinorTicks ;
	__property RedLine ;
	__property bool RotateLabels = {read=FRotateLabels, write=SetRotateLabels, default=1};
	__property double RotationAngle = {read=FRotAngle, write=SetRotAngle};
	__property Ticks ;
	__property double TotalAngle = {read=FTotalAngle, write=SetTotalAngle};
	__property Value ;
};


class DELPHICLASS TCircularGaugeEditor;
class PASCALIMPLEMENTATION TCircularGaugeEditor : public Teelineargauge::TLinearGaugeEditor 
{
	typedef Teelineargauge::TLinearGaugeEditor inherited;
	
__published:
	Stdctrls::TButton* BHand;
	Stdctrls::TCheckBox* CBLabelsInside;
	Stdctrls::TCheckBox* CBRotateLabels;
	Stdctrls::TLabel* Label11;
	Stdctrls::TButton* BCenter;
	Stdctrls::TButton* Button3;
	Stdctrls::TEdit* ETotalAngle;
	Comctrls::TUpDown* UDTotalAngle;
	Stdctrls::TLabel* Label12;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDHandDist;
	Stdctrls::TLabel* Label13;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDHandOff;
	Extctrls::TTimer* Timer1;
	Stdctrls::TCheckBox* CBCircled;
	Stdctrls::TLabel* Label14;
	Stdctrls::TEdit* Edit4;
	Comctrls::TUpDown* UDRotAngle;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BHandClick(System::TObject* Sender);
	void __fastcall BCenterClick(System::TObject* Sender);
	HIDESBASE void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall CBLabelsInsideClick(System::TObject* Sender);
	void __fastcall CBRotateLabelsClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall ETotalAngleChange(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall CBCircledClick(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCircularGaugeEditor(Classes::TComponent* AOwner) : Teelineargauge::TLinearGaugeEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCircularGaugeEditor(Classes::TComponent* AOwner, int Dummy) : Teelineargauge::TLinearGaugeEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCircularGaugeEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCircularGaugeEditor(HWND ParentWindow) : Teelineargauge::TLinearGaugeEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecirculargauge */
using namespace Teecirculargauge;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCircularGauge
