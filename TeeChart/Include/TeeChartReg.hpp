// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeChartReg.pas' rev: 6.00

#ifndef TeeChartRegHPP
#define TeeChartRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <PropertyCategories.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teechartreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeClassProperty;
class PASCALIMPLEMENTATION TTeeClassProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
protected:
	int __fastcall GetObject(void);
	
public:
	virtual AnsiString __fastcall GetValue();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTeeClassProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTeeClassProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartClassProperty;
class PASCALIMPLEMENTATION TChartClassProperty : public TTeeClassProperty 
{
	typedef TTeeClassProperty inherited;
	
protected:
	void __fastcall InternalEditPage(Chart::TCustomChart* AChart, int APage);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartClassProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TTeeClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartClassProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartCompEditor;
class PASCALIMPLEMENTATION TChartCompEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
protected:
	virtual Chart::TCustomChart* __fastcall Chart(void);
	
public:
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual AnsiString __fastcall GetVerb(int Index);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TChartCompEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TChartCompEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartSeriesEditor;
class PASCALIMPLEMENTATION TChartSeriesEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual AnsiString __fastcall GetVerb(int Index);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TChartSeriesEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TChartSeriesEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartPenProperty;
class PASCALIMPLEMENTATION TChartPenProperty : public TChartClassProperty 
{
	typedef TChartClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartPenProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TChartClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartPenProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartBrushProperty;
class PASCALIMPLEMENTATION TChartBrushProperty : public TChartClassProperty 
{
	typedef TChartClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartBrushProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TChartClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartBrushProperty(void) { }
	#pragma option pop
	
};


typedef IDesigner TTeeDesigner;
;

typedef void __fastcall (*TTeeEditSeriesProc)(Teengine::TChartSeries* ASeries, Designintf::_di_IDesigner ADesigner);

typedef void __fastcall (*TTeeChartEditorHook)(Designintf::_di_IDesigner ADesigner, Teengine::TCustomSeriesList* AList, TTeeEditSeriesProc EditSeriesProc, Teengine::TSeriesGroup* AGroup = (Teengine::TSeriesGroup*)(0x0));

typedef void __fastcall (*TTeeDesignOptionsHook)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TTeeChartEditorHook TeeChartEditorHook;
extern PACKAGE TTeeDesignOptionsHook TeeDesignOptionsHook;
extern PACKAGE void __fastcall EditChartDesign(Chart::TCustomChart* AChart);
extern PACKAGE void __fastcall EditSeriesProc(Teengine::TChartSeries* ASeries, Designintf::_di_IDesigner ADesigner);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Teechartreg */
using namespace Teechartreg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeChartReg
