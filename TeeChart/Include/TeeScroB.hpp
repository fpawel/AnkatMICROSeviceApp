// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeScroB.pas' rev: 6.00

#ifndef TeeScroBHPP
#define TeeScroBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teescrob
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollBarAxis { sbDefault, sbOther, sbBoth };
#pragma option pop

class DELPHICLASS TChartScrollBar;
class PASCALIMPLEMENTATION TChartScrollBar : public Stdctrls::TScrollBar 
{
	typedef Stdctrls::TScrollBar inherited;
	
private:
	TScrollBarAxis FAxis;
	Chart::TCustomChart* FChart;
	bool FInverted;
	Classes::TNotifyEvent FOldOnPageChange;
	Classes::TNotifyEvent FOldOnScroll;
	Classes::TNotifyEvent FOldOnUndoZoom;
	Classes::TNotifyEvent FOldOnZoom;
	int FPageSize;
	bool IScrollAxes;
	bool __fastcall HasPaging(void);
	void __fastcall ChartOnPageChange(System::TObject* Sender);
	void __fastcall ChartOnScroll(System::TObject* Sender);
	void __fastcall ChartOnUndoZoom(System::TObject* Sender);
	void __fastcall ChartOnZoom(System::TObject* Sender);
	void __fastcall CalcTotals(Teengine::TChartAxis* Axis, double &AMin, double &AMax);
	void __fastcall SetChart(Chart::TCustomChart* Value);
	void __fastcall SetInverted(bool Value);
	HIDESBASE void __fastcall SetPageSize(int Value);
	
protected:
	int __fastcall AssociatedSeries(Teengine::TChartAxis* Axis);
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TChartScrollBar(Classes::TComponent* AOwner);
	void __fastcall RecalcPosition(bool ScrollAxes = true);
	
__published:
	__property Align  = {default=0};
	__property TScrollBarAxis Axis = {read=FAxis, write=FAxis, default=2};
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property Enabled  = {default=0};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=0};
	__property LargeChange  = {default=500};
	__property Max  = {default=30000};
	__property SmallChange  = {default=50};
	__property int PageSize = {read=FPageSize, write=SetPageSize, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartScrollBar(HWND ParentWindow) : Stdctrls::TScrollBar(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TChartScrollBar(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word TeeMaxScrollPos = 0x7530;

}	/* namespace Teescrob */
using namespace Teescrob;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeScroB
