// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCustomFuncEditor.pas' rev: 6.00

#ifndef TeeCustomFuncEditorHPP
#define TeeCustomFuncEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <TeeFunci.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teecustomfunceditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomFunctionEditor;
class PASCALIMPLEMENTATION TCustomFunctionEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EStart;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EStep;
	Stdctrls::TEdit* ENum;
	Stdctrls::TLabel* Label3;
	void __fastcall EStartChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCustomFunctionEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomFunctionEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomFunctionEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomFunctionEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecustomfunceditor */
using namespace Teecustomfunceditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCustomFuncEditor
