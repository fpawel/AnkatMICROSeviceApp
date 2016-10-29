// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeColorLineEditor.pas' rev: 6.00

#ifndef TeeColorLineEditorHPP
#define TeeColorLineEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeAxisToolEdit.hpp>	// Pascal unit
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

namespace Teecolorlineeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TColorLineToolEditor;
class PASCALIMPLEMENTATION TColorLineToolEditor : public Teeaxistooledit::TAxisToolEditor 
{
	typedef Teeaxistooledit::TAxisToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EValue;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CBAllowDrag;
	Stdctrls::TCheckBox* CBDragRepaint;
	Stdctrls::TCheckBox* CBNoLimitDrag;
	Stdctrls::TCheckBox* CBDrawBehind;
	Stdctrls::TCheckBox* CBDraw3D;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBStyle;
	void __fastcall EValueChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBAllowDragClick(System::TObject* Sender);
	void __fastcall CBDragRepaintClick(System::TObject* Sender);
	void __fastcall CBNoLimitDragClick(System::TObject* Sender);
	void __fastcall CBDrawBehindClick(System::TObject* Sender);
	void __fastcall CBDraw3DClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teetools::TColorLineTool* ColorLineTool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TColorLineToolEditor(Classes::TComponent* AOwner) : Teeaxistooledit::TAxisToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TColorLineToolEditor(Classes::TComponent* AOwner, int Dummy) : Teeaxistooledit::TAxisToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TColorLineToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TColorLineToolEditor(HWND ParentWindow) : Teeaxistooledit::TAxisToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecolorlineeditor */
using namespace Teecolorlineeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeColorLineEditor
