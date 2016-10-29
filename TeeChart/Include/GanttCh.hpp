// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GanttCh.pas' rev: 6.00

#ifndef GanttChHPP
#define GanttChHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ganttch
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGanttSeries;
class PASCALIMPLEMENTATION TGanttSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TChartValueList* FEndValues;
	Teengine::TChartValueList* FNextTask;
	Tecanvas::TChartPen* __fastcall GetConnectingPen(void);
	Teengine::TChartValueList* __fastcall GetStartValues(void);
	void __fastcall SetConnectingPen(Tecanvas::TChartPen* Value);
	void __fastcall SetEndValues(Teengine::TChartValueList* Value);
	void __fastcall SetNextTask(Teengine::TChartValueList* Value);
	void __fastcall SetStartValues(Teengine::TChartValueList* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual bool __fastcall ClickedPointer(int ValueIndex, int tmpX, int tmpY, int x, int y);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TGanttSeries(Classes::TComponent* AOwner);
	int __fastcall AddGantt(const double AStart, const double AEnd, const double AY, const AnsiString AXLabel = "");
	int __fastcall AddGanttColor(const double AStart, const double AEnd, const double AY, const AnsiString AXLabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual int __fastcall AddXY(const double AXValue, const double AYValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxXValue(void);
	
__published:
	__property ColorEachPoint  = {default=1};
	__property Tecanvas::TChartPen* ConnectingPen = {read=GetConnectingPen, write=SetConnectingPen};
	__property Teengine::TChartValueList* StartValues = {read=GetStartValues, write=SetStartValues};
	__property Teengine::TChartValueList* EndValues = {read=FEndValues, write=SetEndValues};
	__property Teengine::TChartValueList* NextTask = {read=FNextTask, write=SetNextTask};
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TGanttSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ganttch */
using namespace Ganttch;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GanttCh
