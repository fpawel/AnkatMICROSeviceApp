// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePreviewPanelEditor.pas' rev: 6.00

#ifndef TeePreviewPanelEditorHPP
#define TeePreviewPanelEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeePreviewPanel.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teepreviewpaneleditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormPreviewPanelEditor;
class PASCALIMPLEMENTATION TFormPreviewPanelEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TCheckBox* CBAllowMove;
	Stdctrls::TCheckBox* CBAllowResize;
	Stdctrls::TCheckBox* CBDragImage;
	Stdctrls::TCheckBox* CBAsBitmap;
	Stdctrls::TCheckBox* CBShowImage;
	Tecanvas::TButtonColor* BPaperColor;
	Extctrls::TRadioGroup* RGOrientation;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* Button1;
	Teependlg::TButtonPen* Button2;
	Comctrls::TTabSheet* TabShadow;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBAllowMoveClick(System::TObject* Sender);
	void __fastcall CBAllowResizeClick(System::TObject* Sender);
	void __fastcall CBDragImageClick(System::TObject* Sender);
	void __fastcall CBAsBitmapClick(System::TObject* Sender);
	void __fastcall CBShowImageClick(System::TObject* Sender);
	void __fastcall RGOrientationClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Teepreviewpanel::TTeePreviewPanel* TeePreviewPanel1;
	
public:
	__fastcall TFormPreviewPanelEditor(Classes::TComponent* AOwner, Teepreviewpanel::TTeePreviewPanel* APanel);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormPreviewPanelEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormPreviewPanelEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormPreviewPanelEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormPreviewPanelEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepreviewpaneleditor */
using namespace Teepreviewpaneleditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePreviewPanelEditor
