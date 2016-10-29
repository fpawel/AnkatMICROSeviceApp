// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePyramid.pas' rev: 6.00

#ifndef TeePyramidHPP
#define TeePyramidHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepyramid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPyramidSeries;
class PASCALIMPLEMENTATION TPyramidSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	int FSize;
	double __fastcall AcumUpTo(int UpToIndex);
	void __fastcall SetSize(const int Value);
	
protected:
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	Types::TRect __fastcall CalcSector(int ValueIndex, int &tmpZ, int &tmpX, int &tmpZ2);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	
public:
	__fastcall virtual TPyramidSeries(Classes::TComponent* AOwner);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual bool __fastcall DrawValuesForward(void);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Active  = {default=1};
	__property Brush ;
	__property ColorEachPoint  = {default=1};
	__property ColorSource ;
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
	__property int SizePercent = {read=FSize, write=SetSize, default=50};
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
	/* TChartSeries.Destroy */ inline __fastcall virtual ~TPyramidSeries(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepyramid */
using namespace Teepyramid;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePyramid
