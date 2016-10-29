// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFLineEdi.pas' rev: 6.00

#ifndef TeeFLineEdiHPP
#define TeeFLineEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Series.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeflineedi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFastLineSeriesEditor;
class PASCALIMPLEMENTATION TFastLineSeriesEditor : public Teependlg::TPenDialog 
{
	typedef Teependlg::TPenDialog inherited;
	
__published:
	Stdctrls::TCheckBox* CBDrawAll;
	Stdctrls::TGroupBox* GBStair;
	Stdctrls::TCheckBox* CBStairs;
	Stdctrls::TCheckBox* CBInvStairs;
	Tecanvas::TComboFlat* CBNulls;
	Stdctrls::TLabel* Label2;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall CBDrawAllClick(System::TObject* Sender);
	void __fastcall CBStairsClick(System::TObject* Sender);
	void __fastcall CBInvStairsClick(System::TObject* Sender);
	void __fastcall CBNullsChange(System::TObject* Sender);
	
private:
	Series::TFastLineSeries* FastLine;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFastLineSeriesEditor(Classes::TComponent* AOwner) : Teependlg::TPenDialog(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFastLineSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Teependlg::TPenDialog(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFastLineSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFastLineSeriesEditor(HWND ParentWindow) : Teependlg::TPenDialog(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeflineedi */
using namespace Teeflineedi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFLineEdi
