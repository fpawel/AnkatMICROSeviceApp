// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeChartBook.pas' rev: 6.00

#ifndef TeeChartBookHPP
#define TeeChartBookHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeComma.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
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

namespace Teechartbook
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartBook;
typedef void __fastcall (__closure *TNewChartEvent)(TChartBook* Sender, Chart::TCustomChart* Chart);

typedef void __fastcall (__closure *TDeleteChartEvent)(TChartBook* Sender, Chart::TCustomChart* Chart, bool &Delete);

class PASCALIMPLEMENTATION TChartBook : public Comctrls::TPageControl 
{
	typedef Comctrls::TPageControl inherited;
	
private:
	bool FToolbar;
	Menus::TMenuItem* MenuToolbar;
	Menus::TMenuItem* DeleteItem;
	TDeleteChartEvent FOnDelete;
	TNewChartEvent FOnNew;
	void __fastcall CheckTab(Comctrls::TTabSheet* ATab);
	void __fastcall CheckToolbar(const bool Value);
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Messages::TMessage &Message);
	void __fastcall CreateChart(Comctrls::TTabSheet* ATab);
	Teecomma::TTeeCommander* __fastcall CreateToolBar(Chart::TCustomChart* AChart);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall EditClick(System::TObject* Sender);
	Chart::TCustomChart* __fastcall HasChart(Comctrls::TTabSheet* ATab);
	void __fastcall NewClick(System::TObject* Sender);
	void __fastcall Popup(System::TObject* Sender);
	void __fastcall RenameClick(System::TObject* Sender);
	void __fastcall SetToolbar(const bool Value);
	void __fastcall ToolbarClick(System::TObject* Sender);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall UpdateActivePage(void);
	
public:
	__fastcall virtual TChartBook(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartBook(void);
	Chart::TCustomChart* __fastcall ActiveChart(void);
	Teecomma::TTeeCommander* __fastcall ActiveToolbar(void);
	Chart::TCustomChart* __fastcall AddChart(void);
	
__published:
	__property PopupMenu  = {stored=false};
	__property bool ShowToolbar = {read=FToolbar, write=SetToolbar, default=0};
	__property TabPosition  = {default=1};
	__property TDeleteChartEvent OnDeleteChart = {read=FOnDelete, write=FOnDelete};
	__property TNewChartEvent OnNewChart = {read=FOnNew, write=FOnNew};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartBook(HWND ParentWindow) : Comctrls::TPageControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teechartbook */
using namespace Teechartbook;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeChartBook
