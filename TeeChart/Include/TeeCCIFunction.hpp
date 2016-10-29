// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCCIFunction.pas' rev: 6.00

#ifndef TeeCCIFunctionHPP
#define TeeCCIFunctionHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StatChar.hpp>	// Pascal unit
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <OHLChart.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Teeccifunction
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCCIFunction;
class PASCALIMPLEMENTATION TCCIFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	Teengine::TChartSeries* FAveSeries;
	double FConstant;
	Statchar::TMovingAverageFunction* FMovAve;
	Teengine::TChartSeries* FTypical;
	bool __fastcall IsConstStored(void);
	void __fastcall SetConstant(const double Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC bool __fastcall IsValidSource(Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TCCIFunction(Classes::TComponent* AOwner);
	__fastcall virtual ~TCCIFunction(void);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property double Constant = {read=FConstant, write=SetConstant, stored=IsConstStored};
};


class DELPHICLASS TCCIFuncEditor;
class PASCALIMPLEMENTATION TCCIFuncEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EConst;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EPeriod;
	Comctrls::TUpDown* UDPeriod;
	void __fastcall EConstChange(System::TObject* Sender);
	void __fastcall EPeriodChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCCIFuncEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCCIFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCCIFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCCIFuncEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeccifunction */
using namespace Teeccifunction;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCCIFunction
