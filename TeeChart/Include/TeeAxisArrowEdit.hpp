// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAxisArrowEdit.pas' rev: 6.00

#ifndef TeeAxisArrowEditHPP
#define TeeAxisArrowEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeTools.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeAxisToolEdit.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teeaxisarrowedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAxisArrowToolEditor;
class PASCALIMPLEMENTATION TAxisArrowToolEditor : public Teeaxistooledit::TAxisToolEditor 
{
	typedef Teeaxistooledit::TAxisToolEditor inherited;
	
__published:
	Stdctrls::TButton* Button1;
	Comctrls::TUpDown* UDLength;
	Stdctrls::TEdit* ELength;
	Stdctrls::TLabel* LL;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBPos;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDScroll;
	Stdctrls::TLabel* Label4;
	Stdctrls::TCheckBox* CBInv;
	Stdctrls::TLabel* Label5;
	Comctrls::TUpDown* UDSize;
	Stdctrls::TEdit* ESize;
	Stdctrls::TLabel* Label6;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* EWidth;
	Comctrls::TUpDown* UDWidth;
	void __fastcall Button1Click(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ELC(System::TObject* Sender);
	void __fastcall CBPosChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall CBInvClick(System::TObject* Sender);
	void __fastcall ESizeChange(System::TObject* Sender);
	void __fastcall EWidthChange(System::TObject* Sender);
	
private:
	Teetools::TAxisArrowTool* AxisArrowTool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAxisArrowToolEditor(Classes::TComponent* AOwner) : Teeaxistooledit::TAxisToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAxisArrowToolEditor(Classes::TComponent* AOwner, int Dummy) : Teeaxistooledit::TAxisToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAxisArrowToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAxisArrowToolEditor(HWND ParentWindow) : Teeaxistooledit::TAxisToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeaxisarrowedit */
using namespace Teeaxisarrowedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAxisArrowEdit
