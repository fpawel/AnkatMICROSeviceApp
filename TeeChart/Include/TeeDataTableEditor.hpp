// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDataTableEditor.pas' rev: 6.00

#ifndef TeeDataTableEditorHPP
#define TeeDataTableEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeeSymbolEditor.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeDataTableTool.hpp>	// Pascal unit
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

namespace Teedatatableeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDataTableEditor;
class PASCALIMPLEMENTATION TDataTableEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Teependlg::TButtonPen* ButtonPen1;
	Comctrls::TTabSheet* TabSheet3;
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabSheet4;
	Comctrls::TTabSheet* TabSymbol;
	Stdctrls::TCheckBox* CBLegVisible;
	Comctrls::TTabSheet* TabText;
	Teependlg::TButtonPen* ButtonPen2;
	Comctrls::TTabSheet* TabLegendText;
	Stdctrls::TCheckBox* CBInverted;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TCheckBox* CBAutoPos;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDLeft;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TCheckBox* CBFontColor;
	Stdctrls::TCheckBox* CBOtherSide;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBAutoPosClick(System::TObject* Sender);
	void __fastcall CBLegVisibleClick(System::TObject* Sender);
	void __fastcall CBInvertedClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBFontColorClick(System::TObject* Sender);
	void __fastcall CBOtherSideClick(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teedatatabletool::TDataTableTool* Table;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDataTableEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDataTableEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDataTableEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDataTableEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teedatatableeditor */
using namespace Teedatatableeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDataTableEditor
