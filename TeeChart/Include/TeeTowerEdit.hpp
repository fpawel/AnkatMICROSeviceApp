// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTowerEdit.pas' rev: 6.00

#ifndef TeeTowerEditHPP
#define TeeTowerEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
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

namespace Teetoweredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTowerSeriesEditor;
class PASCALIMPLEMENTATION TTowerSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* ButtonPen1;
	Stdctrls::TButton* Button1;
	Stdctrls::TCheckBox* CBDark3D;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBOrigin;
	Stdctrls::TEdit* EOrigin;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBStyle;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDDepth;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDWidth;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDTransp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CBDark3DClick(System::TObject* Sender);
	void __fastcall CBOriginClick(System::TObject* Sender);
	void __fastcall EOriginChange(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Teesurfa::TTowerSeries* Tower;
	Forms::TCustomForm* Grid3DForm;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTowerSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTowerSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTowerSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTowerSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teetoweredit */
using namespace Teetoweredit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTowerEdit
