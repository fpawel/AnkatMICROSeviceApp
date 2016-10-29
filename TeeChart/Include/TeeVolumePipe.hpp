// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeVolumePipe.pas' rev: 6.00

#ifndef TeeVolumePipeHPP
#define TeeVolumePipeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teevolumepipe
{
//-- type declarations -------------------------------------------------------
typedef Types::TPoint TTrapeziumPoints[4];

typedef DynamicArray<Types::TPoint >  TeeVolumePipe__2;

class DELPHICLASS TVolumePipeSeries;
class PASCALIMPLEMENTATION TVolumePipeSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	DynamicArray<Types::TPoint >  IPolyList;
	int IMin;
	int IMax;
	int IDiff;
	Tecanvas::TCustomTeeGradient* FGradient;
	Types::TPoint BoundingPoints[4];
	Tecanvas::TChartPen* FLinesPen;
	int FConePercent;
	double totalVals;
	int totalPxArea;
	int lastX;
	int lastYDisp;
	int leftWall;
	int rightWall;
	int overallWidth;
	void __fastcall GetBoundingRectangle(void);
	int __fastcall GetMaxMarkHeight(void);
	void __fastcall SetConePercent(const int Value);
	void __fastcall SetGradient(const Tecanvas::TCustomTeeGradient* Value);
	void __fastcall SetLinesPen(const Tecanvas::TChartPen* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	int __fastcall CalcSegment(int Counter, const double Val);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	void __fastcall PaintGradient(const Types::TPoint * poly, Graphics::TColor PointColor, Graphics::TColor BrushColor);
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	
public:
	__fastcall virtual TVolumePipeSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TVolumePipeSeries(void);
	virtual int __fastcall Clicked(int X, int Y)/* overload */;
	DYNAMIC int __fastcall NumSampleValues(void);
	virtual bool __fastcall UseAxis(void);
	
__published:
	__property Active  = {default=1};
	__property Brush ;
	__property Color ;
	__property ColorEachPoint  = {default=1};
	__property ColorSource ;
	__property int ConePercent = {read=FConePercent, write=SetConePercent, default=30};
	__property Cursor  = {default=0};
	__property Depth  = {default=-1};
	__property Tecanvas::TCustomTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Tecanvas::TChartPen* LinesPen = {read=FLinesPen, write=SetLinesPen};
	__property Marks ;
	__property ParentChart ;
	__property Pen ;
	__property DataSource ;
	__property PercentFormat ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
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
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teevolumepipe */
using namespace Teevolumepipe;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeVolumePipe
