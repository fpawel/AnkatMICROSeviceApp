// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiPeri.pas' rev: 6.00

#ifndef TeeEdiPeriHPP
#define TeeEdiPeriHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teeediperi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeFunctionEditor;
class PASCALIMPLEMENTATION TTeeFunctionEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Stdctrls::TEdit* ENum;
	Stdctrls::TButton* BChange;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBAlign;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBStyle;
	Stdctrls::TLabel* Label3;
	void __fastcall BChangeClick(System::TObject* Sender);
	void __fastcall ENumChange(System::TObject* Sender);
	void __fastcall CBAlignChange(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeFunctionEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeFunctionEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeFunctionEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeFunctionEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeediperi */
using namespace Teeediperi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiPeri
