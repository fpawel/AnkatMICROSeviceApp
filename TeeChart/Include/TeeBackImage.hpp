// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBackImage.pas' rev: 6.00

#ifndef TeeBackImageHPP
#define TeeBackImageHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teebackimage
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBackImageEditor;
class PASCALIMPLEMENTATION TBackImageEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TRadioGroup* RGBitmap;
	Stdctrls::TButton* BBrowse;
	Stdctrls::TCheckBox* CBTransp;
	Stdctrls::TButton* Button1;
	Extctrls::TBevel* Bevel1;
	Extctrls::TImage* Image1;
	Stdctrls::TGroupBox* GBPosition;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* ELeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TEdit* ETop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TLabel* LabelSize;
	Stdctrls::TLabel* LabelExt;
	Extctrls::TPanel* PanelButtons;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button3;
	void __fastcall RGBitmapClick(System::TObject* Sender);
	void __fastcall BBrowseClick(System::TObject* Sender);
	void __fastcall CBTranspClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ELeftChange(System::TObject* Sender);
	void __fastcall ETopChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	Tecanvas::TTeePicture* Image;
	void __fastcall EnableImageControls(void);
	void __fastcall SetBrowseCaption(void);
	
public:
	void __fastcall RefreshControls(Tecanvas::TTeePicture* AImage);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBackImageEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBackImageEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBackImageEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBackImageEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TBackImageEditor* __fastcall InsertImageEditor(Comctrls::TTabSheet* ATab);
extern PACKAGE bool __fastcall EditTeePicture(Classes::TComponent* AOwner, Tecanvas::TTeePicture* APicture);

}	/* namespace Teebackimage */
using namespace Teebackimage;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBackImage
