// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiLege.pas' rev: 6.00

#ifndef TeeEdiLegeHPP
#define TeeEdiLegeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
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

namespace Teeedilege
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeLegend;
class PASCALIMPLEMENTATION TFormTeeLegend : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* L12;
	Stdctrls::TLabel* L7;
	Stdctrls::TCheckBox* CBShow;
	Stdctrls::TCheckBox* CBInverted;
	Tecanvas::TComboFlat* CBLegendStyle;
	Tecanvas::TComboFlat* CBLegStyle;
	Teependlg::TButtonPen* BDivLines;
	Comctrls::TTabSheet* TabSymbol;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBResizeChart;
	Stdctrls::TLabel* L10;
	Stdctrls::TEdit* SETopPos;
	Comctrls::TUpDown* UDTopPos;
	Stdctrls::TLabel* L1;
	Stdctrls::TEdit* SEMargin;
	Comctrls::TUpDown* UDMargin;
	Extctrls::TRadioGroup* RGPosition;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* ECustLeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* ECustTop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EVertSpacing;
	Comctrls::TUpDown* UDVertSpacing;
	Stdctrls::TCheckBox* CBCustPos;
	Stdctrls::TCheckBox* CBFontColor;
	Tecanvas::TComboFlat* CBCheckBoxes;
	Comctrls::TTabSheet* TabTitle;
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabSheet4;
	Stdctrls::TLabel* Label6;
	Stdctrls::TMemo* MemoText;
	Stdctrls::TLabel* Label7;
	Tecanvas::TComboFlat* CBTextAlign;
	Stdctrls::TCheckBox* CBTitleVisible;
	Stdctrls::TCheckBox* CBPosPercent;
	Stdctrls::TButton* Button1;
	void __fastcall SEMarginChange(System::TObject* Sender);
	void __fastcall CBLegendStyleChange(System::TObject* Sender);
	void __fastcall SETopPosChange(System::TObject* Sender);
	void __fastcall CBLegStyleChange(System::TObject* Sender);
	void __fastcall CBShowClick(System::TObject* Sender);
	void __fastcall CBResizeChartClick(System::TObject* Sender);
	void __fastcall CBInvertedClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall EVertSpacingChange(System::TObject* Sender);
	void __fastcall RGPositionClick(System::TObject* Sender);
	void __fastcall ECustLeftChange(System::TObject* Sender);
	void __fastcall ECustTopChange(System::TObject* Sender);
	void __fastcall CBCustPosClick(System::TObject* Sender);
	void __fastcall CBFontColorClick(System::TObject* Sender);
	void __fastcall CBCheckBoxesChange(System::TObject* Sender);
	void __fastcall CBTitleVisibleClick(System::TObject* Sender);
	void __fastcall CBTextAlignChange(System::TObject* Sender);
	void __fastcall MemoTextChange(System::TObject* Sender);
	void __fastcall CBPosPercentClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall PageControl2Change(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Chart::TChartLegend* FLegend;
	Teecustomshapeeditor::TFormTeeShape* ITeeObject;
	Teecustomshapeeditor::TFormTeeShape* ITitleObject;
	bool __fastcall CanChangePos(void);
	void __fastcall EnableCustomPosition(void);
	void __fastcall EnableMarginControls(void);
	void __fastcall SetLeftTop(void);
	void __fastcall SetLegend(Chart::TChartLegend* Value);
	
public:
	__fastcall virtual TFormTeeLegend(Classes::TComponent* Owner);
	__fastcall TFormTeeLegend(Classes::TComponent* Owner, Chart::TChartLegend* ALegend);
	__property Chart::TChartLegend* Legend = {read=FLegend, write=SetLegend};
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeLegend(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeLegend(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeLegend(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeedilege */
using namespace Teeedilege;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiLege
