// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTranslate.pas' rev: 6.00

#ifndef TeeTranslateHPP
#define TeeTranslateHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teetranslate
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAskLanguage;
class PASCALIMPLEMENTATION TAskLanguage : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TListBox* LBLangs;
	Stdctrls::TLabel* Label1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall OKBtnClick(System::TObject* Sender);
	void __fastcall LBLangsDblClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAskLanguage(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAskLanguage(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAskLanguage(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAskLanguage(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef TStringList TLanguageStrings;
;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall TeeAskLanguage(void);
extern PACKAGE bool __fastcall TeeCanTranslate(AnsiString &S, AnsiString &HotKeyList);
extern PACKAGE AnsiString __fastcall TeeTranslateString(const AnsiString Text);
extern PACKAGE void __fastcall TeeTranslateAControl(Controls::TControl* AControl, const Controls::TControl* * ExcludedChilds, const int ExcludedChilds_Size);
extern PACKAGE int __fastcall TeeLanguageRegistry(void);
extern PACKAGE void __fastcall TeeLanguageSaveRegistry(int LanguageNum);

}	/* namespace Teetranslate */
using namespace Teetranslate;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTranslate
