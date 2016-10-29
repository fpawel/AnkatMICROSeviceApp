// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBoxPlotEditor.pas' rev: 6.00

#ifndef TeeBoxPlotEditorHPP
#define TeeBoxPlotEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeBoxPlot.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teeboxploteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBoxSeriesEditor;
class PASCALIMPLEMENTATION TBoxSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* BMedian;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EPos;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ELength;
	Teependlg::TButtonPen* BWhisker;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ELengthChange(System::TObject* Sender);
	void __fastcall EPosChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Forms::TCustomForm* BoxPointerForm;
	Forms::TCustomForm* ExtrPointerForm;
	Forms::TCustomForm* MildPointerForm;
	Teeboxplot::TCustomBoxSeries* Box;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBoxSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBoxSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBoxSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBoxSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeboxploteditor */
using namespace Teeboxploteditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBoxPlotEditor
