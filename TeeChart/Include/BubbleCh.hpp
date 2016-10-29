// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BubbleCh.pas' rev: 6.00

#ifndef BubbleChHPP
#define BubbleChHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Bubblech
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBubbleSeries;
class PASCALIMPLEMENTATION TBubbleSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TChartValueList* FRadiusValues;
	bool FSquared;
	double __fastcall ApplyRadius(const double Value, Teengine::TChartValueList* AList, bool Increment);
	void __fastcall SetRadiusValues(Teengine::TChartValueList* Value);
	void __fastcall SetSquared(bool Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual bool __fastcall ClickedPointer(int ValueIndex, int tmpX, int tmpY, int x, int y);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual Tecanvas::TTeeGradient* __fastcall GetGradient(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PreparePointer(int ValueIndex);
	virtual bool __fastcall IsPointInChartRect(int ValueIndex);
	
public:
	__fastcall virtual TBubbleSeries(Classes::TComponent* AOwner);
	int __fastcall AddBubble(const double AX, const double AY, const double ARadius, const AnsiString AXLabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	DYNAMIC int __fastcall NumSampleValues(void);
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinZValue(void);
	
__published:
	__property ColorEachPoint  = {default=1};
	__property Teengine::TChartValueList* RadiusValues = {read=FRadiusValues, write=SetRadiusValues};
	__property bool Squared = {read=FSquared, write=SetSquared, default=1};
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TBubbleSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Bubblech */
using namespace Bubblech;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BubbleCh
