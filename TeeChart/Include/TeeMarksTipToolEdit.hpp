// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeMarksTipToolEdit.pas' rev: 6.00

#ifndef TeeMarksTipToolEditHPP
#define TeeMarksTipToolEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeEdiSeri.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
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

namespace Teemarkstiptooledit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMarksTipToolEdit;
class PASCALIMPLEMENTATION TMarksTipToolEdit : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBMarkStyle;
	Extctrls::TRadioGroup* RGMouseAction;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EDelay;
	Comctrls::TUpDown* UDDelay;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDHideDelay;
	Stdctrls::TLabel* Label6;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBMarkStyleChange(System::TObject* Sender);
	void __fastcall RGMouseActionClick(System::TObject* Sender);
	void __fastcall EDelayChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	
private:
	Teeediseri::TFormTeeSeries* tmp;
	Teetools::TMarksTipTool* MarksTool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMarksTipToolEdit(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMarksTipToolEdit(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMarksTipToolEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMarksTipToolEdit(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teemarkstiptooledit */
using namespace Teemarkstiptooledit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeMarksTipToolEdit
