// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeClockEditor.pas' rev: 6.00

#ifndef TeeClockEditorHPP
#define TeeClockEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeePolarEditor.hpp>	// Pascal unit
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

namespace Teeclockeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClockEditor;
class PASCALIMPLEMENTATION TClockEditor : public Teepolareditor::TPolarSeriesEditor 
{
	typedef Teepolareditor::TPolarSeriesEditor inherited;
	
__published:
	Stdctrls::TCheckBox* CBRoman;
	Teependlg::TButtonPen* BHour;
	Teependlg::TButtonPen* BMinute;
	Teependlg::TButtonPen* BSecond;
	Teependlg::TButtonPen* BRadius;
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBRomanClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClockEditor(Classes::TComponent* AOwner) : Teepolareditor::TPolarSeriesEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClockEditor(Classes::TComponent* AOwner, int Dummy) : Teepolareditor::TPolarSeriesEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClockEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TClockEditor(HWND ParentWindow) : Teepolareditor::TPolarSeriesEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeclockeditor */
using namespace Teeclockeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeClockEditor
