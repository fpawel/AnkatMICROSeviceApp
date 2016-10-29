// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePoin3.pas' rev: 6.00

#ifndef TeePoin3HPP
#define TeePoin3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepoin3
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPoint3DSeries;
typedef void __fastcall (__closure *TSeriesClickPointer3DEvent)(TPoint3DSeries* Sender, int ValueIndex, int X, int Y);

class PASCALIMPLEMENTATION TPoint3DSeries : public Teesurfa::TCustom3DSeries 
{
	typedef Teesurfa::TCustom3DSeries inherited;
	
private:
	Tecanvas::TChartHiddenPen* FBaseLine;
	double FDepthSize;
	Teengine::TSeriesPointer* FPointer;
	TSeriesClickPointer3DEvent FOnClickPointer;
	Series::TOnGetPointerStyle FOnGetPointerStyle;
	int IOldX;
	int IOldY;
	int IOldZ;
	Tecanvas::TChartPen* __fastcall GetLinePen(void);
	void __fastcall SetBaseLine(const Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetDepthSize(const double Value);
	void __fastcall SetPointer(Teengine::TSeriesPointer* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual void __fastcall CalcZPositions(int ValueIndex);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual int __fastcall GetDepthSize(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	/* virtual class method */ virtual bool __fastcall SubGalleryStyles(TMetaClass* vmt);
	
public:
	__fastcall virtual TPoint3DSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TPoint3DSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual double __fastcall MaxZValue(void);
	
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
	__property Tecanvas::TChartHiddenPen* BaseLine = {read=FBaseLine, write=SetBaseLine};
	__property double DepthSize = {read=FDepthSize, write=SetDepthSize};
	__property Tecanvas::TChartPen* LinePen = {read=GetLinePen, write=SetPen};
	__property Teengine::TSeriesPointer* Pointer = {read=FPointer, write=SetPointer};
	__property TimesZOrder  = {default=3};
	__property XValues ;
	__property YValues ;
	__property ZValues ;
	__property TSeriesClickPointer3DEvent OnClickPointer = {read=FOnClickPointer, write=FOnClickPointer};
	__property Series::TOnGetPointerStyle OnGetPointerStyle = {read=FOnGetPointerStyle, write=FOnGetPointerStyle};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TBubble3DSeries;
class PASCALIMPLEMENTATION TBubble3DSeries : public TPoint3DSeries 
{
	typedef TPoint3DSeries inherited;
	
private:
	Teengine::TChartValueList* FRadiusValues;
	double __fastcall ApplyRadius(const double Value, Teengine::TChartValueList* AList, bool Increment);
	void __fastcall SetRadiusValues(Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall CalcZPositions(int ValueIndex);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual int __fastcall GetDepthSize(int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	/* virtual class method */ virtual bool __fastcall SubGalleryStyles(TMetaClass* vmt);
	
public:
	__fastcall virtual TBubble3DSeries(Classes::TComponent* AOwner);
	int __fastcall AddBubble(const double AX, const double AY, const double AZ, const double ARadius, const AnsiString AXLabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinZValue(void);
	
__published:
	__property ColorEachPoint  = {default=1};
	__property Teengine::TChartValueList* RadiusValues = {read=FRadiusValues, write=SetRadiusValues};
public:
	#pragma option push -w-inl
	/* TPoint3DSeries.Destroy */ inline __fastcall virtual ~TBubble3DSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepoin3 */
using namespace Teepoin3;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePoin3
