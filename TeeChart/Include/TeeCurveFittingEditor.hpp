// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCurveFittingEditor.pas' rev: 6.00

#ifndef TeeCurveFittingEditorHPP
#define TeeCurveFittingEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <CurvFitt.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teecurvefittingeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCurveFittingEditor;
class PASCALIMPLEMENTATION TCurveFittingEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDDegree;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDFactor;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDFirstCalc;
	Stdctrls::TEdit* Edit4;
	Comctrls::TUpDown* UDLastCalc;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* Edit5;
	Comctrls::TUpDown* UDFirst;
	Stdctrls::TEdit* Edit6;
	Comctrls::TUpDown* UDLast;
	Stdctrls::TCheckBox* CBAllCalc;
	Stdctrls::TCheckBox* CBAllDisp;
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
	void __fastcall Edit5Change(System::TObject* Sender);
	void __fastcall Edit6Change(System::TObject* Sender);
	void __fastcall CBAllCalcClick(System::TObject* Sender);
	void __fastcall CBAllDispClick(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCurveFittingEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCurveFittingEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCurveFittingEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCurveFittingEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecurvefittingeditor */
using namespace Teecurvefittingeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCurveFittingEditor
