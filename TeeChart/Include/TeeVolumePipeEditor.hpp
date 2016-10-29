// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeVolumePipeEditor.pas' rev: 6.00

#ifndef TeeVolumePipeEditorHPP
#define TeeVolumePipeEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeVolumePipe.hpp>	// Pascal unit
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

namespace Teevolumepipeeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TVolumePipeSeriesEditor;
class PASCALIMPLEMENTATION TVolumePipeSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* ButtonPen1;
	Stdctrls::TButton* Button1;
	Teependlg::TButtonPen* ButtonPen2;
	Stdctrls::TCheckBox* CheckBox1;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CheckGradient;
	Tecanvas::TComboFlat* CBDirection;
	Stdctrls::TLabel* Label2;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall BGradientClick(System::TObject* Sender);
	void __fastcall CheckGradientClick(System::TObject* Sender);
	void __fastcall CBDirectionChange(System::TObject* Sender);
	
private:
	Teevolumepipe::TVolumePipeSeries* VolumePipe;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TVolumePipeSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TVolumePipeSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TVolumePipeSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVolumePipeSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teevolumepipeeditor */
using namespace Teevolumepipeeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeVolumePipeEditor
