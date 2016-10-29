// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeRenkoSeries.pas' rev: 6.00

#ifndef TeeRenkoSeriesHPP
#define TeeRenkoSeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teerenkoseries
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TRenkoSeries;
class PASCALIMPLEMENTATION TRenkoSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	double FBoxSize;
	Graphics::TColor FDownSwing;
	bool FDraw3D;
	Tecanvas::TTeeTransparency FTransp;
	Graphics::TColor FUpSwing;
	double IMin;
	double IMax;
	Tecanvas::TTeeBlend* IBlend;
	int __fastcall CalcBricks(bool Draw);
	void __fastcall CompareMinMax(const double Value);
	Teengine::TChartValueList* __fastcall GetCloseValues(void);
	void __fastcall SetBoxSize(const double Value);
	void __fastcall SetDownSwing(const Graphics::TColor Value);
	void __fastcall SetDraw3D(const bool Value);
	void __fastcall SetTransp(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetUpSwing(const Graphics::TColor Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	int __fastcall CalcNumBricks(const double Current, const double Previous);
	virtual void __fastcall DrawAllValues(void);
	void __fastcall DrawBrick(const double low, const double high, int Index);
	void __fastcall DrawBricks(const double Start, int StartIndex, int NumBricks, bool UpTrend);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TRenkoSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall CountLegendItems(void);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	virtual void __fastcall CalcFirstLastVisibleIndex(void);
	__property Teengine::TChartValueList* CloseValues = {read=GetCloseValues};
	
__published:
	__property double BoxSize = {read=FBoxSize, write=SetBoxSize};
	__property Graphics::TColor DownSwingColor = {read=FDownSwing, write=SetDownSwing, default=0};
	__property bool Draw3D = {read=FDraw3D, write=SetDraw3D, default=1};
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransp, write=SetTransp, default=0};
	__property Graphics::TColor UpSwingColor = {read=FUpSwing, write=SetUpSwing, default=16777215};
	__property Active  = {default=1};
	__property Brush ;
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property Pen ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property XLabelsSource ;
	__property XValues ;
	__property YValues ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnGetMarkText ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
public:
	#pragma option push -w-inl
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TRenkoSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRenkoSeriesEditor;
class PASCALIMPLEMENTATION TRenkoSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBDraw3D;
	Tecanvas::TButtonColor* BUp;
	Tecanvas::TButtonColor* BDown;
	Teependlg::TButtonPen* BPen;
	Stdctrls::TButton* BBrush;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EBoxSize;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ETransp;
	Comctrls::TUpDown* UDTransp;
	void __fastcall CBDraw3DClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ETranspChange(System::TObject* Sender);
	void __fastcall EBoxSizeChange(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	
private:
	TRenkoSeries* Renko;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TRenkoSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TRenkoSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TRenkoSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TRenkoSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teerenkoseries */
using namespace Teerenkoseries;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeRenkoSeries
