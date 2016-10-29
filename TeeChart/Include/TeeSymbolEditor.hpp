// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSymbolEditor.pas' rev: 6.00

#ifndef TeeSymbolEditorHPP
#define TeeSymbolEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teesymboleditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSymbolEditor;
class PASCALIMPLEMENTATION TSymbolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* L11;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* SEColWi;
	Comctrls::TUpDown* UDColWi;
	Tecanvas::TComboFlat* CBColWUnits;
	Tecanvas::TComboFlat* CBSymbolPos;
	Stdctrls::TCheckBox* CBContinuous;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TCheckBox* CBSymPen;
	Teependlg::TButtonPen* BSymPen;
	Stdctrls::TCheckBox* CBSquared;
	Teeedigrad::TButtonGradient* BSymGradient;
	Stdctrls::TButton* Button1;
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEColWiChange(System::TObject* Sender);
	void __fastcall CBColWUnitsChange(System::TObject* Sender);
	void __fastcall CBSymbolPosChange(System::TObject* Sender);
	void __fastcall CBContinuousClick(System::TObject* Sender);
	void __fastcall CBSymPenClick(System::TObject* Sender);
	void __fastcall CBSquaredClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Chart::TLegendSymbol* Symbol;
	void __fastcall EnableWidthControls(void);
	
public:
	void __fastcall RefreshSymbol(Chart::TLegendSymbol* ASymbol);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSymbolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSymbolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSymbolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSymbolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesymboleditor */
using namespace Teesymboleditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSymbolEditor
