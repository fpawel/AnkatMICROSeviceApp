// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePieEdit.pas' rev: 6.00

#ifndef TeePieEditHPP
#define TeePieEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeCircledEdit.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teepieedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPieSeriesEditor;
class PASCALIMPLEMENTATION TPieSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabOptions;
	Comctrls::TTabSheet* TabGroup;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TLabel* Label7;
	Tecanvas::TComboFlat* CBOther;
	Stdctrls::TEdit* EOtherValue;
	Stdctrls::TEdit* EOtherLabel;
	Stdctrls::TButton* Button2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CBDark3d;
	Stdctrls::TEdit* SEExpBig;
	Comctrls::TUpDown* UDExpBig;
	Stdctrls::TCheckBox* CBPatterns;
	Teependlg::TButtonPen* BPen;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDAngleSize;
	Teeedigrad::TButtonGradient* BGradient;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBMultiple;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TCheckBox* CBColorEach;
	Tecanvas::TButtonColor* BColor;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CBMarksAutoPosition;
	Stdctrls::TCheckBox* CBVertCenter;
	Stdctrls::TLabel* Label8;
	Stdctrls::TScrollBar* SBLegSize;
	Stdctrls::TLabel* Label9;
	Tecanvas::TComboFlat* CBPalette;
	Stdctrls::TLabel* Label10;
	Comctrls::TTrackBar* TBBright;
	Stdctrls::TLabel* LBright;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBDark3dClick(System::TObject* Sender);
	void __fastcall CBPatternsClick(System::TObject* Sender);
	void __fastcall CBOtherChange(System::TObject* Sender);
	void __fastcall EOtherValueChange(System::TObject* Sender);
	void __fastcall EOtherLabelChange(System::TObject* Sender);
	void __fastcall SEExpBigChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBMarksAutoPositionClick(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall CBMultipleChange(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBVertCenterClick(System::TObject* Sender);
	void __fastcall SBLegSizeChange(System::TObject* Sender);
	void __fastcall CBPaletteChange(System::TObject* Sender);
	void __fastcall TBBrightChange(System::TObject* Sender);
	
private:
	Series::TPieSeries* Pie;
	Teecirclededit::TCircledSeriesEditor* tmpCircled;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPieSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPieSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPieSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPieSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepieedit */
using namespace Teepieedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePieEdit
