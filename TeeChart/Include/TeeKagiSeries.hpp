// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeKagiSeries.pas' rev: 6.00

#ifndef TeeKagiSeriesHPP
#define TeeKagiSeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teekagiseries
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TKagiSeries;
class PASCALIMPLEMENTATION TKagiSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	bool FAbsReversal;
	Teengine::TSeriesPointer* FBuySymbol;
	Tecanvas::TChartPen* FDownSwing;
	double FReversalAmount;
	Teengine::TSeriesPointer* FSellSymbol;
	Tecanvas::TChartPen* FUpSwing;
	double __fastcall BasePrice(void);
	int __fastcall CalcSegments(bool Draw);
	void __fastcall DrawHorizLine(const double y, const double FromValue, const double ToValue);
	void __fastcall DrawVertLine(const double x, const double FromValue, const double ToValue);
	Teengine::TChartValueList* __fastcall GetCloseValues(void);
	bool __fastcall Reversal(const double Value, const double * History, const int History_Size);
	void __fastcall SetAbsoluteReversal(const bool Value);
	void __fastcall SetBuySymbol(const Teengine::TSeriesPointer* Value);
	void __fastcall SetDownSwing(const Tecanvas::TChartPen* Value);
	void __fastcall SetReversalAmount(const double Value);
	void __fastcall SetSellSymbol(const Teengine::TSeriesPointer* Value);
	void __fastcall SetUpSwing(const Tecanvas::TChartPen* Value);
	
protected:
	virtual void __fastcall DrawAllValues(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TKagiSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TKagiSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall CountLegendItems(void);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	virtual double __fastcall MaxXValue(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	__property Teengine::TChartValueList* CloseValues = {read=GetCloseValues};
	
__published:
	__property bool AbsoluteReversal = {read=FAbsReversal, write=SetAbsoluteReversal, default=0};
	__property Teengine::TSeriesPointer* BuySymbol = {read=FBuySymbol, write=SetBuySymbol};
	__property Tecanvas::TChartPen* DownSwing = {read=FDownSwing, write=SetDownSwing};
	__property double ReversalAmount = {read=FReversalAmount, write=SetReversalAmount};
	__property Teengine::TSeriesPointer* SellSymbol = {read=FSellSymbol, write=SetSellSymbol};
	__property Tecanvas::TChartPen* UpSwing = {read=FUpSwing, write=SetUpSwing};
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
};


class DELPHICLASS TKagiSeriesEditor;
class PASCALIMPLEMENTATION TKagiSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Teependlg::TButtonPen* BUp;
	Teependlg::TButtonPen* BDown;
	Comctrls::TTabSheet* TabBuy;
	Comctrls::TTabSheet* TabSell;
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	TKagiSeries* Kagi;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TKagiSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TKagiSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TKagiSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TKagiSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teekagiseries */
using namespace Teekagiseries;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeKagiSeries
