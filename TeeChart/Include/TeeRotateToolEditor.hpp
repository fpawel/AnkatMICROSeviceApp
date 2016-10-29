// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeRotateToolEditor.pas' rev: 6.00

#ifndef TeeRotateToolEditorHPP
#define TeeRotateToolEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teerotatetooleditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TRotateToolEditor;
class PASCALIMPLEMENTATION TRotateToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Teependlg::TButtonPen* BOutline;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* LabelInertia;
	Stdctrls::TCheckBox* CBInverted;
	Tecanvas::TComboFlat* CBStyle;
	Tecanvas::TComboFlat* CBButton;
	Stdctrls::TEdit* ESpeed;
	Comctrls::TUpDown* UDSpeed;
	Stdctrls::TScrollBar* SBInertia;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* CBCursor;
	Stdctrls::TGroupBox* GroupBox1;
	Extctrls::TImage* ImageCursor;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBInvertedClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall CBButtonChange(System::TObject* Sender);
	void __fastcall ESpeedChange(System::TObject* Sender);
	void __fastcall SBInertiaChange(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	
private:
	Teetools::TRotateTool* Tool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TRotateToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TRotateToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TRotateToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TRotateToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teerotatetooleditor */
using namespace Teerotatetooleditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeRotateToolEditor
