// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeExpAveFuncEdit.pas' rev: 6.00

#ifndef TeeExpAveFuncEditHPP
#define TeeExpAveFuncEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <StatChar.hpp>	// Pascal unit
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

namespace Teeexpavefuncedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TExpAveFuncEditor;
class PASCALIMPLEMENTATION TExpAveFuncEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBAlign;
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall CBAlignChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TExpAveFuncEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TExpAveFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TExpAveFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TExpAveFuncEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeexpavefuncedit */
using namespace Teeexpavefuncedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeExpAveFuncEdit
