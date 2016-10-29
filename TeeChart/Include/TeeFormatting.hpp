// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFormatting.pas' rev: 6.00

#ifndef TeeFormattingHPP
#define TeeFormattingHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeformatting
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormatEditor;
class PASCALIMPLEMENTATION TFormatEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* PanelOK;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Stdctrls::TGroupBox* GroupBox1;
	Tecanvas::TComboFlat* CBCustom;
	Tecanvas::TComboFlat* CBDate;
	Stdctrls::TRadioButton* RBDate;
	Stdctrls::TRadioButton* RBCustom;
	Stdctrls::TRadioButton* RBGeo;
	Tecanvas::TComboFlat* CBGeo;
	Extctrls::TPanel* Panel2;
	Stdctrls::TRadioButton* RBInteger;
	Stdctrls::TCheckBox* CBPercent;
	Stdctrls::TCheckBox* CBThousands;
	Stdctrls::TCheckBox* CBCurrency;
	Stdctrls::TCheckBox* CBFixedDecimals;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UpDown2;
	void __fastcall RadioGroup1Click(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBDateChange(System::TObject* Sender);
	void __fastcall CBCustomChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBPercentClick(System::TObject* Sender);
	void __fastcall CBThousandsClick(System::TObject* Sender);
	void __fastcall CBGeoChange(System::TObject* Sender);
	void __fastcall RBIntegerClick(System::TObject* Sender);
	
private:
	bool tmpChanging;
	void __fastcall AddDate(const AnsiString S);
	void __fastcall AddGeo(const AnsiString S);
	
public:
	AnsiString Format;
	bool IsDate;
	bool IsGeo;
	AnsiString __fastcall TheFormat();
	/*         class method */ static AnsiString __fastcall Change(TMetaClass* vmt, Classes::TComponent* AOwner, const AnsiString AFormat, bool AllowDates = true);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormatEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormatEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormatEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormatEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeformatting */
using namespace Teeformatting;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFormatting
