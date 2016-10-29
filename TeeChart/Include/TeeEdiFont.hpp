// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiFont.pas' rev: 6.00

#ifndef TeeEdiFontHPP
#define TeeEdiFontHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBackImage.hpp>	// Pascal unit
#include <TeeShadowEditor.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teeedifont
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeFontEditor;
class PASCALIMPLEMENTATION TTeeFontEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* PanelButtons;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TButton* Button3;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* ESize;
	Comctrls::TUpDown* UDSize;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBItalic;
	Stdctrls::TCheckBox* CBBold;
	Stdctrls::TCheckBox* CBStrike;
	Stdctrls::TCheckBox* CBUnder;
	Tecanvas::TButtonColor* BColor;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EInter;
	Comctrls::TUpDown* UDInter;
	Teependlg::TButtonPen* BOutline;
	Stdctrls::TCheckBox* CBOutGrad;
	Comctrls::TTabSheet* TabShadow;
	Comctrls::TTabSheet* TabGradient;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBName;
	Comctrls::TTabSheet* TabPicture;
	void __fastcall BFontClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EInterChange(System::TObject* Sender);
	void __fastcall CBOutGradClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall ESizeChange(System::TObject* Sender);
	void __fastcall CBItalicClick(System::TObject* Sender);
	void __fastcall CBBoldClick(System::TObject* Sender);
	void __fastcall CBStrikeClick(System::TObject* Sender);
	void __fastcall CBUnderClick(System::TObject* Sender);
	void __fastcall CBNameChange(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	
private:
	Tecanvas::TTeeFont* Backup;
	Tecanvas::TTeeFont* TheFont;
	Teeedigrad::TTeeGradientEditor* FGradientEditor;
	Teebackimage::TBackImageEditor* FPicEditor;
	Teeshadoweditor::TTeeShadowEditor* FShadowEditor;
	void __fastcall CheckStyle(Stdctrls::TCheckBox* Check, Graphics::TFontStyle Value);
	void __fastcall RefreshBasicProps(void);
	
public:
	void __fastcall RefreshControls(Tecanvas::TTeeFont* AFont);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeFontEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeFontEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeFontEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeFontEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef void __fastcall (*TTeeAddFontNames)(Classes::TStrings* Items);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TTeeAddFontNames TeeAddFontNames;
extern PACKAGE TTeeFontEditor* __fastcall InsertTeeFontEditor(Comctrls::TTabSheet* ATab);
extern PACKAGE bool __fastcall EditTeeFontEx(Classes::TComponent* AOwner, Tecanvas::TTeeFont* AFont);

}	/* namespace Teeedifont */
using namespace Teeedifont;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiFont
