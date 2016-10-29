// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCustEdit.pas' rev: 6.00

#ifndef TeeCustEditHPP
#define TeeCustEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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

namespace Teecustedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomSeriesEditor;
class PASCALIMPLEMENTATION TCustomSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* BLineBorder;
	Tecanvas::TButtonColor* BLineColor;
	Stdctrls::TGroupBox* GBStair;
	Stdctrls::TCheckBox* CBStairs;
	Stdctrls::TCheckBox* CBInvStairs;
	Stdctrls::TCheckBox* CBColorEach;
	Stdctrls::TCheckBox* CBDark3D;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBStack;
	Stdctrls::TLabel* LHeight;
	Stdctrls::TEdit* EHeight;
	Comctrls::TUpDown* UDHeight;
	Stdctrls::TCheckBox* CBClick;
	Stdctrls::TButton* BBrush;
	Teependlg::TButtonPen* BOutline;
	Stdctrls::TCheckBox* CheckBox1;
	Stdctrls::TButton* Button1;
	Teeedigrad::TButtonGradient* BGradient;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBNulls;
	Stdctrls::TLabel* LTransp;
	Comctrls::TTrackBar* TBTransp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBStairsClick(System::TObject* Sender);
	void __fastcall CBInvStairsClick(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall CBDark3DClick(System::TObject* Sender);
	void __fastcall CBStackChange(System::TObject* Sender);
	void __fastcall EHeightChange(System::TObject* Sender);
	void __fastcall CBClickClick(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall BLineColorClick(System::TObject* Sender);
	void __fastcall BLineBorderClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBNullsChange(System::TObject* Sender);
	void __fastcall TBTranspChange(System::TObject* Sender);
	
private:
	Forms::TCustomForm* PointerForm;
	Series::TCustomSeries* TheSeries;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCustomSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecustedit */
using namespace Teecustedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCustEdit
