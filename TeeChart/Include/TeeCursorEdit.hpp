// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCursorEdit.pas' rev: 6.00

#ifndef TeeCursorEditHPP
#define TeeCursorEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
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
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecursoredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCursorToolEditor;
class PASCALIMPLEMENTATION TCursorToolEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Teependlg::TButtonPen* BPen;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CBZ;
	Stdctrls::TCheckBox* CBSnap;
	Tecanvas::TComboFlat* CBSnapStyle;
	Stdctrls::TLabel* Label5;
	Tecanvas::TComboFlat* CBStyle;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBFollow;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EPixels;
	Comctrls::TUpDown* UDClick;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDHorizSize;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDVertSize;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* Label10;
	Stdctrls::TEdit* EScope;
	Comctrls::TUpDown* UDScope;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* CBScopeStyle;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall CBSnapClick(System::TObject* Sender);
	void __fastcall CBFollowClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBZClick(System::TObject* Sender);
	void __fastcall EPixelsChange(System::TObject* Sender);
	void __fastcall CBSnapStyleChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall EScopeChange(System::TObject* Sender);
	void __fastcall CBScopeStyleChange(System::TObject* Sender);
	
private:
	Teetools::TCursorTool* CursorTool;
	void __fastcall EnableSnap(void);
	void __fastcall EnableScope(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCursorToolEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCursorToolEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCursorToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCursorToolEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecursoredit */
using namespace Teecursoredit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCursorEdit
