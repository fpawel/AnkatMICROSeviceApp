// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAreaEdit.pas' rev: 6.00

#ifndef TeeAreaEditHPP
#define TeeAreaEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Teeareaedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAreaSeriesEditor;
class PASCALIMPLEMENTATION TAreaSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Extctrls::TRadioGroup* RGMultiArea;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CBUseOrigin;
	Stdctrls::TEdit* EOrigin;
	Comctrls::TUpDown* UDOrigin;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TCheckBox* CBStairs;
	Teependlg::TButtonPen* BAreaLinesPen;
	Teependlg::TButtonPen* BAreaLinePen;
	Stdctrls::TCheckBox* CBInvStairs;
	Stdctrls::TButton* BPattern;
	Stdctrls::TButton* Button1;
	Stdctrls::TGroupBox* GroupBox5;
	Stdctrls::TEdit* ETransp;
	Comctrls::TUpDown* UDTransp;
	Stdctrls::TCheckBox* CBDark3D;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBColorEach;
	Tecanvas::TButtonColor* BAreaColor;
	Stdctrls::TGroupBox* GroupBox4;
	Tecanvas::TComboFlat* CBNulls;
	Stdctrls::TGroupBox* GroupBox6;
	Stdctrls::TEdit* EGroup;
	Comctrls::TUpDown* UDGroup;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGMultiAreaClick(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall CBStairsClick(System::TObject* Sender);
	void __fastcall CBInvStairsClick(System::TObject* Sender);
	void __fastcall CBUseOriginClick(System::TObject* Sender);
	void __fastcall EOriginChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BPatternClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ETranspChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBNullsChange(System::TObject* Sender);
	void __fastcall CBDark3DClick(System::TObject* Sender);
	void __fastcall EGroupChange(System::TObject* Sender);
	
private:
	Series::TAreaSeries* Area;
	Forms::TCustomForm* PointerForm;
	Forms::TCustomForm* FGradientForm;
	void __fastcall EnableOrigin(void);
	Graphics::TColor __fastcall GetAreaColor(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAreaSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAreaSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAreaSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAreaSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeareaedit */
using namespace Teeareaedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAreaEdit
