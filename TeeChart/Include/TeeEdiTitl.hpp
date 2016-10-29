// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiTitl.pas' rev: 6.00

#ifndef TeeEdiTitlHPP
#define TeeEdiTitlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeedititl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeTitle;
class PASCALIMPLEMENTATION TFormTeeTitle : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControlTitle;
	Comctrls::TTabSheet* TabSheet1;
	Extctrls::TPanel* Panel1;
	Tecanvas::TComboFlat* CBTitles;
	Stdctrls::TMemo* MText;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* ECustLeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TEdit* ECustTop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TCheckBox* CBCustPos;
	Extctrls::TPanel* Panel2;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TCheckBox* CBAdjust;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBAlign;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDMargin;
	Extctrls::TPanel* Panel3;
	Stdctrls::TButton* Button1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall MTextChange(System::TObject* Sender);
	void __fastcall CBAdjustClick(System::TObject* Sender);
	void __fastcall CBTitlesChange(System::TObject* Sender);
	void __fastcall CBCustPosClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ECustLeftChange(System::TObject* Sender);
	void __fastcall ECustTopChange(System::TObject* Sender);
	void __fastcall CBAlignChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall PageControlTitleChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	bool AssigningText;
	bool CreatingForm;
	Chart::TCustomChart* TheChart;
	Teecustomshapeeditor::TFormTeeShape* ITeeObject;
	bool __fastcall CanChangeCust(void);
	void __fastcall EnableCustomPosition(void);
	void __fastcall SetTitleControls(void);
	
public:
	Chart::TChartTitle* TheTitle;
	__fastcall TFormTeeTitle(Classes::TComponent* Owner, Chart::TCustomChart* AChart, Chart::TChartTitle* ATitle);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeTitle(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeTitle(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeTitle(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeTitle(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeedititl */
using namespace Teeedititl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiTitl
