// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePVOFunction.pas' rev: 6.00

#ifndef TeePVOFunctionHPP
#define TeePVOFunctionHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StatChar.hpp>	// Pascal unit
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teepvofunction
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPVOFunction;
class PASCALIMPLEMENTATION TPVOFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	Statchar::TExpMovAveFunction* FExpMovAve1;
	Statchar::TExpMovAveFunction* FExpMovAve2;
	Teengine::TChartSeries* FExpSeries1;
	Teengine::TChartSeries* FExpSeries2;
	bool FPercent;
	int __fastcall GetPeriod2(void);
	void __fastcall SetPercent(const bool Value);
	void __fastcall SetPeriod2(const int Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TPVOFunction(Classes::TComponent* AOwner);
	__fastcall virtual ~TPVOFunction(void);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property bool Percentage = {read=FPercent, write=SetPercent, default=1};
	__property int Period2 = {read=GetPeriod2, write=SetPeriod2, default=26};
};


class DELPHICLASS TPVOFuncEditor;
class PASCALIMPLEMENTATION TPVOFuncEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EPeriod;
	Comctrls::TUpDown* UDPeriod;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDPeriod2;
	Stdctrls::TCheckBox* CBPercent;
	void __fastcall EPeriodChange(System::TObject* Sender);
	void __fastcall CBPercentClick(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPVOFuncEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPVOFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPVOFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPVOFuncEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepvofunction */
using namespace Teepvofunction;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePVOFunction
