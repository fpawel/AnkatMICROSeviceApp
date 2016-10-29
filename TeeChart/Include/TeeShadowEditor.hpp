// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeShadowEditor.pas' rev: 6.00

#ifndef TeeShadowEditorHPP
#define TeeShadowEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teeshadoweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeShadowEditor;
class PASCALIMPLEMENTATION TTeeShadowEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* LTransp;
	Tecanvas::TButtonColor* BShadowColor;
	Stdctrls::TEdit* EShadowTransp;
	Comctrls::TUpDown* UDShadowTransp;
	Stdctrls::TButton* BOK;
	Stdctrls::TCheckBox* CBSmooth;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDShadowSize;
	Stdctrls::TEdit* EVertSize;
	Comctrls::TUpDown* UDShaVert;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TLabel* Label2;
	Comctrls::TTrackBar* TBBlur;
	Comctrls::TTrackBar* TBColor;
	Stdctrls::TCheckBox* CBClip;
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EShadowTranspChange(System::TObject* Sender);
	void __fastcall EVertSizeChange(System::TObject* Sender);
	void __fastcall BOKClick(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall TBBlurChange(System::TObject* Sender);
	void __fastcall TBColorChange(System::TObject* Sender);
	void __fastcall BShadowColorClick(System::TObject* Sender);
	void __fastcall CBClipClick(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Tecanvas::TTeeShadow* Shadow;
	Word H;
	Word L;
	Word S;
	bool __fastcall CanChange(void);
	
public:
	void __fastcall RefreshControls(Tecanvas::TTeeShadow* AShadow);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeShadowEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeShadowEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeShadowEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeShadowEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditTeeShadow(Classes::TComponent* AOwner, Tecanvas::TTeeShadow* AShadow);
extern PACKAGE TTeeShadowEditor* __fastcall InsertTeeShadowEditor(Comctrls::TTabSheet* ATab);

}	/* namespace Teeshadoweditor */
using namespace Teeshadoweditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeShadowEditor
