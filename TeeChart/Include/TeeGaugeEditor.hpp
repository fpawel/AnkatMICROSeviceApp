// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGaugeEditor.pas' rev: 6.00

#ifndef TeeGaugeEditorHPP
#define TeeGaugeEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeCircledEdit.hpp>	// Pascal unit
#include <TeeGauges.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeePoEdi.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teegaugeeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGaugeSeriesEditor;
class PASCALIMPLEMENTATION TGaugeSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label11;
	Stdctrls::TCheckBox* CheckBox1;
	Stdctrls::TButton* Button2;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TCheckBox* CBInside;
	Comctrls::TTabSheet* TabSheet3;
	Teependlg::TButtonPen* BTicks;
	Teependlg::TButtonPen* BMinor;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TEdit* Edit4;
	Comctrls::TUpDown* UpDown3;
	Teependlg::TButtonPen* BLine;
	Teependlg::TButtonPen* BAxis;
	Stdctrls::TCheckBox* CheckBox4;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button3;
	Tecanvas::TComboFlat* ComboBox1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label12;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit6;
	Comctrls::TUpDown* UDAngle;
	Stdctrls::TEdit* Edit7;
	Comctrls::TUpDown* UDDist;
	Stdctrls::TEdit* Edit8;
	Comctrls::TUpDown* UDValue;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit9;
	Comctrls::TUpDown* UDMin;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit10;
	Comctrls::TUpDown* UDMax;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UpDown2;
	Stdctrls::TEdit* Edit5;
	Comctrls::TUpDown* UpDown4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* Edit11;
	Comctrls::TUpDown* UDIncrement;
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall ComboBox1Change(System::TObject* Sender);
	void __fastcall CheckBox4Click(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
	void __fastcall Edit5Change(System::TObject* Sender);
	void __fastcall Edit6Change(System::TObject* Sender);
	void __fastcall Edit7Change(System::TObject* Sender);
	void __fastcall Edit8Change(System::TObject* Sender);
	void __fastcall Edit9Change(System::TObject* Sender);
	void __fastcall Edit10Change(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBInsideClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Edit11Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Teegauges::TGaugeSeries* Gauge;
	Teecirclededit::TCircledSeriesEditor* tmpCircled;
	bool __fastcall CanModifyAxis(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TGaugeSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TGaugeSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TGaugeSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGaugeSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teegaugeeditor */
using namespace Teegaugeeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGaugeEditor
