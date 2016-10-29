// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSAR.pas' rev: 6.00

#ifndef TeeSARHPP
#define TeeSARHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <OHLChart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teesar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSARFunction;
class PASCALIMPLEMENTATION TSARFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	double FAF;
	double FMS;
	void __fastcall SetAF(const double Value);
	void __fastcall SetMS(const double Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC bool __fastcall IsValidSource(Teengine::TChartSeries* Value);
	
public:
	__fastcall virtual TSARFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property double AccelerationFactor = {read=FAF, write=SetAF};
	__property double MaxStep = {read=FMS, write=SetMS};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TSARFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSARFuncEditor;
class PASCALIMPLEMENTATION TSARFuncEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EAccel;
	Stdctrls::TEdit* EMaxStep;
	void __fastcall EAccelChange(System::TObject* Sender);
	void __fastcall EMaxStepChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSARFuncEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSARFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSARFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSARFuncEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesar */
using namespace Teesar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSAR
