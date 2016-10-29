// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDrawLineEditor.pas' rev: 6.00

#ifndef TeeDrawLineEditorHPP
#define TeeDrawLineEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teedrawlineeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDrawLineEdit;
class PASCALIMPLEMENTATION TDrawLineEdit : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label11;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBButton;
	Stdctrls::TCheckBox* CBEnable;
	Stdctrls::TCheckBox* CBSelect;
	Stdctrls::TEdit* EPixels;
	Comctrls::TUpDown* UDClick;
	Stdctrls::TCheckBox* CBSelectNew;
	Teependlg::TButtonPen* BPen;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBStyle;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBButtonChange(System::TObject* Sender);
	void __fastcall CBEnableClick(System::TObject* Sender);
	void __fastcall CBSelectClick(System::TObject* Sender);
	void __fastcall EPixelsChange(System::TObject* Sender);
	void __fastcall CBSelectNewClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	
private:
	Teetools::TDrawLineTool* Draw;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDrawLineEdit(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDrawLineEdit(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDrawLineEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDrawLineEdit(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teedrawlineeditor */
using namespace Teedrawlineeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDrawLineEditor
