// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeShapeEdi.pas' rev: 6.00

#ifndef TeeShapeEdiHPP
#define TeeShapeEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeeShape.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teeshapeedi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartShapeEditor;
class PASCALIMPLEMENTATION TChartShapeEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* LX1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* LY1;
	Stdctrls::TEdit* SEX0;
	Stdctrls::TEdit* SEX1;
	Stdctrls::TEdit* SEY0;
	Stdctrls::TEdit* SEY1;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBStyle;
	Tecanvas::TButtonColor* BShapeColor;
	Teependlg::TButtonPen* BShapePen;
	Stdctrls::TCheckBox* CBTrans;
	Stdctrls::TButton* BShapeBrush;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBUnits;
	Comctrls::TTabSheet* TabFont;
	Stdctrls::TCheckBox* CBRound;
	Teeedigrad::TButtonGradient* BGradient;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TLabel* Label5;
	Stdctrls::TMemo* MemoText;
	Extctrls::TRadioGroup* RGVertAlign;
	Extctrls::TRadioGroup* RGAlign;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDTransp;
	Stdctrls::TButton* Button1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEX0Change(System::TObject* Sender);
	void __fastcall SEY0Change(System::TObject* Sender);
	void __fastcall SEX1Change(System::TObject* Sender);
	void __fastcall SEY1Change(System::TObject* Sender);
	void __fastcall BShapeBrushClick(System::TObject* Sender);
	void __fastcall MemoTextChange(System::TObject* Sender);
	void __fastcall RGAlignClick(System::TObject* Sender);
	void __fastcall CBTransClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall CBUnitsChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBRoundClick(System::TObject* Sender);
	void __fastcall RGVertAlignClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teeedifont::TTeeFontEditor* FEditFont;
	Teeshape::TChartShape* TheSeries;
	void __fastcall EnableRound(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TChartShapeEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TChartShapeEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TChartShapeEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartShapeEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeshapeedi */
using namespace Teeshapeedi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeShapeEdi
