// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiPage.pas' rev: 6.00

#ifndef TeeEdiPageHPP
#define TeeEdiPageHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeeEdiGene.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teeedipage
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeePage;
class PASCALIMPLEMENTATION TFormTeePage : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* L17;
	Stdctrls::TEdit* SEPointsPerPage;
	Stdctrls::TCheckBox* CBScaleLast;
	Stdctrls::TLabel* LabelPages;
	Comctrls::TUpDown* UDPointsPerPage;
	Stdctrls::TCheckBox* CBPageLegend;
	Teeedigene::TChartPageNavigator* ChartPageNavigator1;
	Stdctrls::TCheckBox* CBPageNum;
	Stdctrls::TCheckBox* CBAutoScale;
	Stdctrls::TCheckBox* CBNoPages;
	Stdctrls::TButton* BEditTool;
	void __fastcall SEPointsPerPageChange(System::TObject* Sender);
	void __fastcall CBScaleLastClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBPageLegendClick(System::TObject* Sender);
	void __fastcall CBPageNumClick(System::TObject* Sender);
	void __fastcall ChartPageNavigator1ButtonClicked(Teenavigator::TTeeNavigateBtn Index);
	void __fastcall CBAutoScaleClick(System::TObject* Sender);
	void __fastcall CBNoPagesClick(System::TObject* Sender);
	void __fastcall BEditToolClick(System::TObject* Sender);
	
private:
	Chart::TCustomChart* __fastcall Chart(void);
	Teengine::TTeeCustomTool* __fastcall PageNumTool(bool CreateTool);
	void __fastcall SetEditTool(void);
	void __fastcall SetNoPages(void);
	
public:
	__fastcall TFormTeePage(Classes::TComponent* Owner, Chart::TCustomChart* AChart);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeePage(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeePage(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeePage(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeePage(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeedipage */
using namespace Teeedipage;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiPage
