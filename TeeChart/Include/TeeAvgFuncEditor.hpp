// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAvgFuncEditor.pas' rev: 6.00

#ifndef TeeAvgFuncEditorHPP
#define TeeAvgFuncEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeEdiPeri.hpp>	// Pascal unit
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

namespace Teeavgfunceditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAverageFuncEditor;
class PASCALIMPLEMENTATION TAverageFuncEditor : public Teeediperi::TTeeFunctionEditor 
{
	typedef Teeediperi::TTeeFunctionEditor inherited;
	
__published:
	Stdctrls::TCheckBox* CBNulls;
	void __fastcall CBNullsClick(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAverageFuncEditor(Classes::TComponent* AOwner) : Teeediperi::TTeeFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAverageFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teeediperi::TTeeFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAverageFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAverageFuncEditor(HWND ParentWindow) : Teeediperi::TTeeFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeavgfunceditor */
using namespace Teeavgfunceditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAvgFuncEditor
