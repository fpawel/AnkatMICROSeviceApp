// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSeriesRegion.pas' rev: 6.00

#ifndef TeeSeriesRegionHPP
#define TeeSeriesRegionHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeseriesregion
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSeriesRegionTool;
class PASCALIMPLEMENTATION TSeriesRegionTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	bool FAutoBounds;
	bool FDrawBehindSeries;
	Tecanvas::TTeeGradient* FGradient;
	double FLowerBound;
	double FOrigin;
	Tecanvas::TTeeTransparency FTransparency;
	double FUpperBound;
	bool FUseOrigin;
	bool ISeriesDrawn;
	Graphics::TColor __fastcall GetColor(void);
	int __fastcall IntersectionPoint(const double Value, /* out */ double &y);
	void __fastcall SetAutoBounds(const bool Value);
	void __fastcall SetColor(const Graphics::TColor Value);
	void __fastcall SetDrawBehindSeries(const bool Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetLowerBound(const double Value);
	void __fastcall SetOrigin(const double Value);
	void __fastcall SetTransparency(const Tecanvas::TTeeTransparency Value);
	void __fastcall SetUpperBound(const double Value);
	void __fastcall SetUseOrigin(const bool Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall DrawRegion(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SeriesEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TSeriesRegionTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TSeriesRegionTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property bool AutoBounds = {read=FAutoBounds, write=SetAutoBounds, default=1};
	__property bool DrawBehindSeries = {read=FDrawBehindSeries, write=SetDrawBehindSeries, default=1};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property double LowerBound = {read=FLowerBound, write=SetLowerBound};
	__property double Origin = {read=FOrigin, write=SetOrigin};
	__property double UpperBound = {read=FUpperBound, write=SetUpperBound};
	__property bool UseOrigin = {read=FUseOrigin, write=SetUseOrigin, default=1};
	__property Active  = {default=1};
	__property Brush ;
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, default=16777215};
	__property Pen ;
	__property Series ;
	__property Tecanvas::TTeeTransparency Transparency = {read=FTransparency, write=SetTransparency, default=0};
};


class DELPHICLASS TSeriesRegionEditor;
class PASCALIMPLEMENTATION TSeriesRegionEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Teependlg::TButtonPen* ButtonPen1;
	Comctrls::TTabSheet* TabGradient;
	Tecanvas::TButtonColor* ButtonColor1;
	Stdctrls::TButton* Button1;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* ELower;
	Stdctrls::TEdit* EUpper;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TCheckBox* CBUseOrigin;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EOrigin;
	Stdctrls::TCheckBox* CBAutoBounds;
	Stdctrls::TCheckBox* CBBehind;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* ETransp;
	Comctrls::TUpDown* UDTransp;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBBehindClick(System::TObject* Sender);
	void __fastcall CBUseOriginClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ELowerChange(System::TObject* Sender);
	void __fastcall EUpperChange(System::TObject* Sender);
	void __fastcall EOriginChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CBAutoBoundsClick(System::TObject* Sender);
	void __fastcall ETranspChange(System::TObject* Sender);
	
public:
	bool CreatingForm;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSeriesRegionEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesRegionEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSeriesRegionEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesRegionEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeseriesregion */
using namespace Teeseriesregion;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSeriesRegion
