// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSeriesAnimEdit.pas' rev: 6.00

#ifndef TeeSeriesAnimEditHPP
#define TeeSeriesAnimEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeTools.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeseriesanimedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSeriesAnimToolEditor;
class PASCALIMPLEMENTATION TSeriesAnimToolEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Stdctrls::TLabel* Label2;
	Stdctrls::TScrollBar* SBSteps;
	Stdctrls::TLabel* Label3;
	Stdctrls::TCheckBox* CBStartMin;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EStart;
	Stdctrls::TButton* Button1;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDEvery;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* ComboFlat1;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDDelay;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CBStartMinClick(System::TObject* Sender);
	void __fastcall EStartChange(System::TObject* Sender);
	void __fastcall SBStepsChange(System::TObject* Sender);
	HIDESBASE void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall ComboFlat1Change(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall Edit2Change(System::TObject* Sender);
	
private:
	Teetools::TSeriesAnimationTool* AnimTool;
	void __fastcall StopAnimation(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSeriesAnimToolEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesAnimToolEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSeriesAnimToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesAnimToolEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeseriesanimedit */
using namespace Teeseriesanimedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSeriesAnimEdit
