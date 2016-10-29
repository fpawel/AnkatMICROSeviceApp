// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSmithEdit.pas' rev: 6.00

#ifndef TeeSmithEditHPP
#define TeeSmithEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSmith.hpp>	// Pascal unit
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

namespace Teesmithedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSmithSeriesEdit;
class PASCALIMPLEMENTATION TSmithSeriesEdit : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBC;
	Stdctrls::TCheckBox* CBR;
	Teependlg::TButtonPen* BCPen;
	Teependlg::TButtonPen* BRPen;
	Teependlg::TButtonPen* BCircle;
	Stdctrls::TCheckBox* CBColorEach;
	Teependlg::TButtonPen* BBorder;
	Stdctrls::TButton* BCFont;
	Stdctrls::TButton* BRFont;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EImag;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBCClick(System::TObject* Sender);
	void __fastcall CBRClick(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall BCFontClick(System::TObject* Sender);
	void __fastcall BRFontClick(System::TObject* Sender);
	void __fastcall EImagChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
public:
	Forms::TCustomForm* CircledForm;
	Teesmith::TSmithSeries* Smith;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSmithSeriesEdit(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSmithSeriesEdit(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSmithSeriesEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSmithSeriesEdit(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesmithedit */
using namespace Teesmithedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSmithEdit
