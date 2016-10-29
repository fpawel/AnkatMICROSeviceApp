// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCalendarEditor.pas' rev: 6.00

#ifndef TeeCalendarEditorHPP
#define TeeCalendarEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeCalendar.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teecalendareditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCalendarSeriesEditor;
class PASCALIMPLEMENTATION TCalendarSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Teependlg::TButtonPen* ButtonPen1;
	Stdctrls::TCheckBox* CBWeekDays;
	Stdctrls::TCheckBox* CBWeekUpper;
	Stdctrls::TCheckBox* CBTrailing;
	Stdctrls::TCheckBox* CBToday;
	Comctrls::TTabSheet* TabSheet2;
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabSheet3;
	Comctrls::TPageControl* PageControl3;
	Comctrls::TTabSheet* TabSheet4;
	Comctrls::TPageControl* PageControl4;
	Comctrls::TTabSheet* TabSheet5;
	Comctrls::TPageControl* PageControl5;
	Comctrls::TTabSheet* TabSheet6;
	Comctrls::TPageControl* PageControl6;
	Stdctrls::TCheckBox* CBMonths;
	Comctrls::TTabSheet* TabSheet7;
	Comctrls::TPageControl* PageControl7;
	Stdctrls::TCheckBox* CBMonthUpper;
	Stdctrls::TCheckBox* CBPrevious;
	Stdctrls::TCheckBox* CBNext;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBWeekDaysClick(System::TObject* Sender);
	void __fastcall CBWeekUpperClick(System::TObject* Sender);
	void __fastcall CBTrailingClick(System::TObject* Sender);
	void __fastcall CBTodayClick(System::TObject* Sender);
	void __fastcall CBMonthsClick(System::TObject* Sender);
	void __fastcall CBMonthUpperClick(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall CheckBox2Click(System::TObject* Sender);
	void __fastcall PageControl2Change(System::TObject* Sender);
	void __fastcall PageControl7Change(System::TObject* Sender);
	void __fastcall PageControl6Change(System::TObject* Sender);
	void __fastcall PageControl5Change(System::TObject* Sender);
	void __fastcall PageControl4Change(System::TObject* Sender);
	void __fastcall PageControl3Change(System::TObject* Sender);
	
private:
	Teecustomshapeeditor::TFormTeeShape* IDays;
	Teecustomshapeeditor::TFormTeeShape* ISunday;
	Teecustomshapeeditor::TFormTeeShape* IToday;
	Teecustomshapeeditor::TFormTeeShape* ITrailing;
	Teecustomshapeeditor::TFormTeeShape* IMonths;
	Teecustomshapeeditor::TFormTeeShape* IWeekDays;
	Teecalendar::TCalendarSeries* Calendar;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCalendarSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCalendarSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCalendarSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCalendarSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecalendareditor */
using namespace Teecalendareditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCalendarEditor
