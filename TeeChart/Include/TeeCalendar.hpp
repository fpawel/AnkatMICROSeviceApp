// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCalendar.pas' rev: 6.00

#ifndef TeeCalendarHPP
#define TeeCalendarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecalendar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCalendarCell;
class DELPHICLASS TCalendarSeries;
class DELPHICLASS TCalendarCellUpper;
class PASCALIMPLEMENTATION TCalendarCell : public Teeprocs::TTeeShape 
{
	typedef Teeprocs::TTeeShape inherited;
	
public:
	TCalendarSeries* Parent;
	
__published:
	__property Brush ;
	__property Font ;
	__property Gradient ;
	__property Pen ;
	__property Picture ;
	__property Shadow ;
	__property Transparency  = {default=0};
	__property Transparent  = {stored=true};
	__property Visible ;
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TCalendarCell(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : Teeprocs::TTeeShape(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TCalendarCell(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCalendarCellUpper : public TCalendarCell 
{
	typedef TCalendarCell inherited;
	
private:
	bool FUpper;
	AnsiString FFormat;
	void __fastcall SetUpperCase(const bool Value);
	void __fastcall SetFormat(const AnsiString Value);
	
__published:
	__property AnsiString Format = {read=FFormat, write=SetFormat};
	__property bool UpperCase = {read=FUpper, write=SetUpperCase, default=0};
public:
	#pragma option push -w-inl
	/* TTeeCustomShape.Create */ inline __fastcall virtual TCalendarCellUpper(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : TCalendarCell(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeCustomShape.Destroy */ inline __fastcall virtual ~TCalendarCellUpper(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TCalendarChangeEvent)(TCalendarSeries* Sender, System::TDateTime &Value);

class PASCALIMPLEMENTATION TCalendarSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	System::TDateTime FDate;
	TCalendarCell* FDays;
	TCalendarCellUpper* FMonths;
	Buttons::TSpeedButton* FNextMonth;
	TCalendarChangeEvent FOnChange;
	Menus::TPopupMenu* FPopupMenu;
	Buttons::TSpeedButton* FPreviousMonth;
	TCalendarCell* FSunday;
	TCalendarCell* FToday;
	TCalendarCell* FTrailing;
	TCalendarCellUpper* FWeekDays;
	int IColumns;
	int IFirstDay;
	int IRows;
	Buttons::TSpeedButton* __fastcall CreateButton(const AnsiString ACaption, int ALeftPos);
	void __fastcall ChangeMonthMenu(System::TObject* Sender);
	Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	void __fastcall MonthClick(System::TObject* Sender);
	void __fastcall SetDate(System::TDateTime Value);
	void __fastcall SetMonths(const TCalendarCellUpper* Value);
	void __fastcall SetToday(const TCalendarCell* Value);
	void __fastcall SetDays(const TCalendarCell* Value);
	void __fastcall SetSunday(const TCalendarCell* Value);
	void __fastcall SetTrailing(const TCalendarCell* Value);
	void __fastcall SetWeekDays(const TCalendarCellUpper* Value);
	Buttons::TSpeedButton* __fastcall GetNextMonth(void);
	bool __fastcall GetNextVisible(void);
	Buttons::TSpeedButton* __fastcall GetPreviousMonth(void);
	bool __fastcall GetPreviousVisible(void);
	void __fastcall SetNextVisible(const bool Value);
	void __fastcall SetPreviousVisible(const bool Value);
	
protected:
	virtual void __fastcall DrawAllValues(void);
	void __fastcall DrawCell(int Column, int Row, const AnsiString Text);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	int __fastcall XCell(const double Column);
	int __fastcall YCell(const double Row);
	
public:
	int DayOneRow;
	int DayOneColumn;
	__fastcall virtual TCalendarSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCalendarSeries(void);
	void __fastcall CheckClick(int x, int y);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	bool __fastcall ClickedDate(int x, int y, /* out */ System::TDateTime &ADate);
	Word __fastcall Month(void);
	void __fastcall NextMonth(void);
	DYNAMIC int __fastcall NumSampleValues(void);
	void __fastcall PreviousMonth(void);
	Types::TRect __fastcall RectCell(int Column, int Row);
	int __fastcall Rows(void);
	Types::TRect __fastcall SeriesRect();
	virtual bool __fastcall UseAxis(void);
	__property int Columns = {read=IColumns, nodefault};
	__property Buttons::TSpeedButton* NextMonthButton = {read=GetNextMonth};
	__property Menus::TPopupMenu* PopupMenu = {read=GetPopupMenu};
	__property Buttons::TSpeedButton* PreviousMonthButton = {read=GetPreviousMonth};
	
__published:
	__property Active  = {default=1};
	__property Cursor  = {default=0};
	__property HorizAxis  = {default=1};
	__property ParentChart ;
	__property Pen ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property VertAxis  = {default=0};
	__property System::TDateTime Date = {read=FDate, write=SetDate};
	__property TCalendarCell* Days = {read=FDays, write=SetDays};
	__property TCalendarCellUpper* Months = {read=FMonths, write=SetMonths};
	__property bool NextButtonVisible = {read=GetNextVisible, write=SetNextVisible, default=1};
	__property bool PreviousButtonVisible = {read=GetPreviousVisible, write=SetPreviousVisible, default=1};
	__property TCalendarCell* Sunday = {read=FSunday, write=SetSunday};
	__property TCalendarCell* Today = {read=FToday, write=SetToday};
	__property TCalendarCell* Trailing = {read=FTrailing, write=SetTrailing};
	__property TCalendarCellUpper* WeekDays = {read=FWeekDays, write=SetWeekDays};
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property TCalendarChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnClick ;
	__property OnDblClick ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};



//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecalendar */
using namespace Teecalendar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCalendar
