// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePointFigure.pas' rev: 6.00

#ifndef TeePointFigureHPP
#define TeePointFigureHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <OHLChart.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepointfigure
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<int >  TeePointFigure__2;

class DELPHICLASS TPointFigureSeries;
class PASCALIMPLEMENTATION TPointFigureSeries : public Ohlchart::TOHLCSeries 
{
	typedef Ohlchart::TOHLCSeries inherited;
	
private:
	double FBoxSize;
	Teengine::TSeriesPointer* FDown;
	DynamicArray<int >  FInversions;
	double FReversal;
	Teengine::TSeriesPointer* FUp;
	void __fastcall DrawColumn(Teengine::TSeriesPointer* Pointer, double FromValue, const double ToValue, int tmpX);
	void __fastcall SetBoxSize(const double Value);
	void __fastcall SetDown(const Teengine::TSeriesPointer* Value);
	void __fastcall SetReversal(const double Value);
	void __fastcall SetUp(const Teengine::TSeriesPointer* Value);
	
protected:
	int __fastcall CalcMaxColumns(bool Draw = false);
	virtual void __fastcall DrawAllValues(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TPointFigureSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TPointFigureSeries(void);
	virtual int __fastcall CountLegendItems(void);
	int __fastcall GetInversionColumn(int Index);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, Teengine::TLegendTextStyle LegendTextStyle);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	
__published:
	__property double BoxSize = {read=FBoxSize, write=SetBoxSize};
	__property Teengine::TSeriesPointer* DownSymbol = {read=FDown, write=SetDown};
	__property double ReversalAmount = {read=FReversal, write=SetReversal};
	__property Teengine::TSeriesPointer* UpSymbol = {read=FUp, write=SetUp};
	__property Active  = {default=1};
	__property Brush ;
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property Pen ;
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


class DELPHICLASS TPointFigureEditor;
class PASCALIMPLEMENTATION TPointFigureEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EBoxSize;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EReversal;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EBoxSizeChange(System::TObject* Sender);
	void __fastcall EReversalChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Forms::TCustomForm* UpForm;
	Forms::TCustomForm* DownForm;
	TPointFigureSeries* PointFigure;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPointFigureEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPointFigureEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPointFigureEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPointFigureEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepointfigure */
using namespace Teepointfigure;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePointFigure
