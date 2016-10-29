// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeHistoEdit.pas' rev: 6.00

#ifndef TeeHistoEditHPP
#define TeeHistoEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StatChar.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teehistoedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THistogramSeriesEditor;
class PASCALIMPLEMENTATION THistogramSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBColorEach;
	Tecanvas::TButtonColor* BAreaColor;
	Teependlg::TButtonPen* BAreaLinesPen;
	Teependlg::TButtonPen* BAreaLinePen;
	Stdctrls::TButton* Button1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDTransp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Statchar::THistogramSeries* TheSeries;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual THistogramSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual THistogramSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~THistogramSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THistogramSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teehistoedit */
using namespace Teehistoedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeHistoEdit
