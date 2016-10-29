// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDesignOptions.pas' rev: 6.00

#ifndef TeeDesignOptionsHPP
#define TeeDesignOptionsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeeEditCha.hpp>	// Pascal unit
#include <TeeGalleryPanel.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeTranslate.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedesignoptions
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOptionsForm;
class PASCALIMPLEMENTATION TOptionsForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabLanguage;
	Comctrls::TTabSheet* TabGallery;
	Comctrls::TTabSheet* TabEditor;
	Comctrls::TTabSheet* TabNewChart;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TButton* Button1;
	Stdctrls::TCheckBox* CBSmooth;
	Stdctrls::TCheckBox* CBSize;
	Stdctrls::TCheckBox* CBPosition;
	Stdctrls::TCheckBox* CBTree;
	Stdctrls::TButton* Button4;
	Extctrls::TPanel* Panel1;
	Extctrls::TPanel* Panel2;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button3;
	Extctrls::TRadioGroup* RGGalleryMode;
	Extctrls::TPanel* Panel3;
	Stdctrls::TLabel* LabelTheme;
	Stdctrls::TListBox* LBTheme;
	Extctrls::TPanel* Panel4;
	Extctrls::TPanel* Panel5;
	Teefilters::TImageFiltered* ImageFiltered1;
	Tecanvas::TComboFlat* CBPalette;
	Stdctrls::TCheckBox* CBGallerySize;
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall LBThemeClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall CBPaletteChange(System::TObject* Sender);
	
private:
	int OldLang;
	void __fastcall ChangeLangLabel(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TOptionsForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TOptionsForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TOptionsForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TOptionsForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int TeeNewChartTheme;
extern PACKAGE int TeeNewChartPalette;

}	/* namespace Teedesignoptions */
using namespace Teedesignoptions;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDesignOptions
