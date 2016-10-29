// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePolarEditor.pas' rev: 6.00

#ifndef TeePolarEditorHPP
#define TeePolarEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeePolar.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
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

namespace Teepolareditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPolarSeriesEditor;
class PASCALIMPLEMENTATION TPolarSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CBAngleLabels;
	Stdctrls::TCheckBox* CBLabelsRot;
	Stdctrls::TCheckBox* CBClockWise;
	Stdctrls::TCheckBox* CBInside;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EMargin;
	Comctrls::TUpDown* UDMargin;
	Stdctrls::TLabel* LAngleInc;
	Stdctrls::TLabel* Label8;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CBClose;
	Stdctrls::TEdit* SEAngleInc;
	Stdctrls::TEdit* SERadiusInc;
	Teependlg::TButtonPen* BPen;
	Teependlg::TButtonPen* BPiePen;
	Stdctrls::TButton* BBrush;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDTransp;
	Tecanvas::TButtonColor* BColor;
	Stdctrls::TCheckBox* CBColorEach;
	Comctrls::TTabSheet* TabFont;
	Extctrls::TTimer* Timer1;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBNulls;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BPenClick(System::TObject* Sender);
	void __fastcall CBCloseClick(System::TObject* Sender);
	void __fastcall SEAngleIncChange(System::TObject* Sender);
	void __fastcall SERadiusIncChange(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	void __fastcall CBAngleLabelsClick(System::TObject* Sender);
	void __fastcall CBLabelsRotClick(System::TObject* Sender);
	void __fastcall CBClockWiseClick(System::TObject* Sender);
	void __fastcall CBInsideClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall EMarginChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall CBNullsChange(System::TObject* Sender);
	
private:
	Forms::TCustomForm* PointerForm;
	Teeedifont::TTeeFontEditor* IFontEditor;
	Forms::TCustomForm* FCircledForm;
	void __fastcall EnableLabels(void);
	
protected:
	Teepolar::TCustomPolarSeries* Polar;
	virtual void __fastcall HideAngleInc(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPolarSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPolarSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPolarSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPolarSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepolareditor */
using namespace Teepolareditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePolarEditor
