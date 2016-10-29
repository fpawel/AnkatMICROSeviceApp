// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGanttEdi.pas' rev: 6.00

#ifndef TeeGanttEdiHPP
#define TeeGanttEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <GanttCh.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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

namespace Teeganttedi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGanttSeriesEditor;
class PASCALIMPLEMENTATION TGanttSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* SEPointVertSize;
	Teependlg::TButtonPen* BConnLines;
	Comctrls::TUpDown* UDPointVertSize;
	Stdctrls::TGroupBox* GPLine;
	Tecanvas::TButtonColor* BColor;
	Stdctrls::TCheckBox* CBColorEach;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UpDown1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEPointVertSizeChange(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Forms::TCustomForm* PointerForm;
	Ganttch::TGanttSeries* TheSeries;
	void __fastcall RefreshShape(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TGanttSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TGanttSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TGanttSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGanttSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeganttedi */
using namespace Teeganttedi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGanttEdi
