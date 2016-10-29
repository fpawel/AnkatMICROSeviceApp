// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiPane.pas' rev: 6.00

#ifndef TeeEdiPaneHPP
#define TeeEdiPaneHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teeedipane
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeePanel;
class PASCALIMPLEMENTATION TFormTeePanel : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabBack;
	Comctrls::TTabSheet* TabBorders;
	Comctrls::TTabSheet* TabGradient;
	Stdctrls::TLabel* L19;
	Stdctrls::TLabel* L2;
	Stdctrls::TEdit* SEPanelBor;
	Stdctrls::TEdit* SEPanelWi;
	Comctrls::TUpDown* UDPanelWi;
	Comctrls::TUpDown* UDPanelBor;
	Tecanvas::TButtonColor* BPanelColor;
	Comctrls::TTabSheet* TabShadow;
	Stdctrls::TCheckBox* CBColorDef;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* ERound;
	Comctrls::TUpDown* UDRound;
	Tecanvas::TComboFlat* CBInner;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBOuter;
	Teependlg::TButtonPen* BBorder;
	Comctrls::TTabSheet* TabImage;
	Stdctrls::TCheckBox* CBImageInside;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TGroupBox* GBMargins;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* SETopMa;
	Stdctrls::TEdit* SELeftMa;
	Stdctrls::TEdit* SEBotMa;
	Stdctrls::TEdit* SERightMa;
	Comctrls::TUpDown* UDTopMa;
	Comctrls::TUpDown* UDRightMa;
	Comctrls::TUpDown* UDLeftMa;
	Comctrls::TUpDown* UDBotMa;
	Tecanvas::TComboFlat* CBMarUnits;
	void __fastcall SEPanelWiChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBImageInsideClick(System::TObject* Sender);
	void __fastcall SEPanelBorChange(System::TObject* Sender);
	void __fastcall BPanelColorClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBColorDefClick(System::TObject* Sender);
	void __fastcall ERoundChange(System::TObject* Sender);
	void __fastcall CBInnerChange(System::TObject* Sender);
	void __fastcall CBOuterChange(System::TObject* Sender);
	void __fastcall CBMarUnitsChange(System::TObject* Sender);
	void __fastcall SERightMaChange(System::TObject* Sender);
	void __fastcall SETopMaChange(System::TObject* Sender);
	void __fastcall SEBotMaChange(System::TObject* Sender);
	void __fastcall SELeftMaChange(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	
private:
	bool Changing;
	Teeedigrad::TTeeGradientEditor* FGradientEditor;
	void __fastcall AdjustMarginMinMax(void);
	int __fastcall ChangeMargin(Comctrls::TUpDown* UpDown, int APos, int OtherSide);
	void __fastcall CheckColorDef(void);
	
public:
	Teeprocs::TCustomTeePanelExtended* ThePanel;
	__fastcall TFormTeePanel(Classes::TComponent* Owner, Teeprocs::TCustomTeePanelExtended* APanel);
	/*         class method */ static TFormTeePanel* __fastcall InsertAt(TMetaClass* vmt, Classes::TComponent* AOwner, Controls::TWinControl* AParent, Teeprocs::TCustomTeePanelExtended* APanel);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeePanel(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeePanel(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeePanel(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeePanel(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeedipane */
using namespace Teeedipane;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiPane
