// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ArrowCha.pas' rev: 6.00

#ifndef ArrowChaHPP
#define ArrowChaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Arrowcha
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TArrowSeries;
class PASCALIMPLEMENTATION TArrowSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TChartValueList* FEndXValues;
	Teengine::TChartValueList* FEndYValues;
	int FPercent;
	int __fastcall GetArrowHeight(void);
	int __fastcall GetArrowWidth(void);
	void __fastcall GetArrowPoints(int ValueIndex, Types::TPoint &P0, Types::TPoint &P1);
	Teengine::TChartValueList* __fastcall GetStartXValues(void);
	Teengine::TChartValueList* __fastcall GetStartYValues(void);
	void __fastcall SetArrowHeight(int Value);
	void __fastcall SetArrowWidth(int Value);
	void __fastcall SetEndXValues(Teengine::TChartValueList* Value);
	void __fastcall SetEndYValues(Teengine::TChartValueList* Value);
	void __fastcall SetPercent(const int Value);
	void __fastcall SetStartXValues(Teengine::TChartValueList* Value);
	void __fastcall SetStartYValues(Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	/* virtual class method */ virtual bool __fastcall CanDoExtra(TMetaClass* vmt);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TArrowSeries(Classes::TComponent* AOwner);
	int __fastcall AddArrow(const double X0, const double Y0, const double X1, const double Y1, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property XLabelsSource ;
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
	__property int ArrowHeight = {read=GetArrowHeight, write=SetArrowHeight, stored=false, nodefault};
	__property int ArrowPercent = {read=FPercent, write=SetPercent, default=50};
	__property int ArrowWidth = {read=GetArrowWidth, write=SetArrowWidth, stored=false, nodefault};
	__property Teengine::TChartValueList* EndXValues = {read=FEndXValues, write=SetEndXValues};
	__property Teengine::TChartValueList* EndYValues = {read=FEndYValues, write=SetEndYValues};
	__property Teengine::TChartValueList* StartXValues = {read=GetStartXValues, write=SetStartXValues};
	__property Teengine::TChartValueList* StartYValues = {read=GetStartYValues, write=SetStartYValues};
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TArrowSeries(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Arrowcha */
using namespace Arrowcha;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ArrowCha
