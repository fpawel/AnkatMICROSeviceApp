// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAxisScrollEdit.pas' rev: 6.00

#ifndef TeeAxisScrollEditHPP
#define TeeAxisScrollEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeAxisToolEdit.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teeaxisscrolledit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAxisScrollEditor;
class PASCALIMPLEMENTATION TAxisScrollEditor : public Teeaxistooledit::TAxisToolEditor 
{
	typedef Teeaxistooledit::TAxisToolEditor inherited;
	
__published:
	Stdctrls::TCheckBox* CBInverted;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBInvertedClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAxisScrollEditor(Classes::TComponent* AOwner) : Teeaxistooledit::TAxisToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAxisScrollEditor(Classes::TComponent* AOwner, int Dummy) : Teeaxistooledit::TAxisToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAxisScrollEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAxisScrollEditor(HWND ParentWindow) : Teeaxistooledit::TAxisToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeaxisscrolledit */
using namespace Teeaxisscrolledit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAxisScrollEdit
