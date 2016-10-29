// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeColorBandEdit.pas' rev: 6.00

#ifndef TeeColorBandEditHPP
#define TeeColorBandEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeAxisToolEdit.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
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
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecolorbandedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TColorBandToolEditor;
class PASCALIMPLEMENTATION TColorBandToolEditor : public Teeaxistooledit::TAxisToolEditor 
{
	typedef Teeaxistooledit::TAxisToolEditor inherited;
	
__published:
	Stdctrls::TButton* BPattern;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EStart;
	Stdctrls::TCheckBox* CBStart;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EEnd;
	Stdctrls::TCheckBox* CBEnd;
	Comctrls::TTabSheet* TabSheet2;
	Teeedigrad::TButtonGradient* BGradient;
	Tecanvas::TButtonColor* ButtonColor1;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* ETrans;
	Comctrls::TUpDown* UDTrans;
	Stdctrls::TCheckBox* CBDrawBehind;
	Stdctrls::TCheckBox* CBBeforeAxes;
	Stdctrls::TLabel* Label5;
	Tecanvas::TComboFlat* CBCursor;
	Teependlg::TButtonPen* BStart;
	Teependlg::TButtonPen* BEnd;
	Stdctrls::TCheckBox* CBStartActive;
	Stdctrls::TCheckBox* CBEndActive;
	Comctrls::TTabSheet* TabPic;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BPatternClick(System::TObject* Sender);
	void __fastcall EStartChange(System::TObject* Sender);
	void __fastcall EEndChange(System::TObject* Sender);
	void __fastcall ETransChange(System::TObject* Sender);
	void __fastcall CBDrawBehindClick(System::TObject* Sender);
	void __fastcall CBStartClick(System::TObject* Sender);
	void __fastcall CBEndClick(System::TObject* Sender);
	void __fastcall CBBeforeAxesClick(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	void __fastcall CBStartActiveClick(System::TObject* Sender);
	void __fastcall CBEndActiveClick(System::TObject* Sender);
	
private:
	Teetools::TColorBandTool* ColorBandTool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TColorBandToolEditor(Classes::TComponent* AOwner) : Teeaxistooledit::TAxisToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TColorBandToolEditor(Classes::TComponent* AOwner, int Dummy) : Teeaxistooledit::TAxisToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TColorBandToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TColorBandToolEditor(HWND ParentWindow) : Teeaxistooledit::TAxisToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecolorbandedit */
using namespace Teecolorbandedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeColorBandEdit
