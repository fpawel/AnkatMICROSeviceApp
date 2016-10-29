// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeMargins.pas' rev: 6.00

#ifndef TeeMarginsHPP
#define TeeMarginsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teemargins
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMarginsEditor;
class PASCALIMPLEMENTATION TMarginsEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TRadioGroup* RGUnits;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* ELeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ETop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* ERight;
	Comctrls::TUpDown* UDRight;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EBottom;
	Comctrls::TUpDown* UDBottom;
	void __fastcall RGUnitsClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ELeftChange(System::TObject* Sender);
	void __fastcall ETopChange(System::TObject* Sender);
	void __fastcall ERightChange(System::TObject* Sender);
	void __fastcall EBottomChange(System::TObject* Sender);
	
private:
	Teengine::TMargins* Margins;
	
public:
	void __fastcall RefreshControls(const Teengine::TMargins* AMargins);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMarginsEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMarginsEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMarginsEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMarginsEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teemargins */
using namespace Teemargins;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeMargins
