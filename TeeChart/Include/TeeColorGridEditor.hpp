// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeColorGridEditor.pas' rev: 6.00

#ifndef TeeColorGridEditorHPP
#define TeeColorGridEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeGriEd.hpp>	// Pascal unit
#include <ExtDlgs.hpp>	// Pascal unit
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

namespace Teecolorgrideditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TColorGridEditor;
class PASCALIMPLEMENTATION TColorGridEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBSmooth;
	Teependlg::TButtonPen* ButtonPen1;
	Teependlg::TButtonPen* BGrid;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDX;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDZ;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit4;
	Comctrls::TUpDown* UDPosition;
	Tecanvas::TComboFlat* CBPlane;
	Stdctrls::TCheckBox* CBCentered;
	Stdctrls::TButton* Button2;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDTransp;
	Stdctrls::TLabel* Label4;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBCenteredClick(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall CBPlaneChange(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
	
private:
	bool Creating;
	Teesurfa::TColorGridSeries* ColorGrid;
	Teegried::TGrid3DSeriesEditor* Grid3DForm;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TColorGridEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TColorGridEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TColorGridEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TColorGridEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecolorgrideditor */
using namespace Teecolorgrideditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeColorGridEditor