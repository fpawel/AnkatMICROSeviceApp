// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDBSumEdit.pas' rev: 6.00

#ifndef TeeDBSumEditHPP
#define TeeDBSumEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeDBEdit.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedbsumedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDBChartSumEditor;
class PASCALIMPLEMENTATION TDBChartSumEditor : public Teedbedit::TBaseDBChartEditor 
{
	typedef Teedbedit::TBaseDBChartEditor inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBAgg;
	Tecanvas::TComboFlat* CBValue;
	Tecanvas::TComboFlat* CBGroup;
	Tecanvas::TComboFlat* CBTimeStep;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBSort;
	Tecanvas::TComboFlat* CBSortType;
	Extctrls::TPanel* PanelButtons;
	Extctrls::TPanel* Panel2;
	Stdctrls::TButton* BOK;
	void __fastcall CBAggChange(System::TObject* Sender);
	void __fastcall CBGroupChange(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall CBSourcesChange(System::TObject* Sender);
	void __fastcall CBSortChange(System::TObject* Sender);
	void __fastcall CBSortTypeChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	void __fastcall CheckCount(void);
	void __fastcall EnableCombos(void);
	void __fastcall EnableTimeStep(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDBChartSumEditor(Classes::TComponent* AOwner) : Teedbedit::TBaseDBChartEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDBChartSumEditor(Classes::TComponent* AOwner, int Dummy) : Teedbedit::TBaseDBChartEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDBChartSumEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBChartSumEditor(HWND ParentWindow) : Teedbedit::TBaseDBChartEditor(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TDBSummarySource;
class PASCALIMPLEMENTATION TDBSummarySource : public Teedbedit::TTeeSeriesDBSource 
{
	typedef Teedbedit::TTeeSeriesDBSource inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	/* virtual class method */ virtual bool __fastcall HasSeries(TMetaClass* vmt, Teengine::TChartSeries* ASeries);
public:
	#pragma option push -w-inl
	/* TTeeSeriesSource.Create */ inline __fastcall virtual TDBSummarySource(Classes::TComponent* AOwner) : Teedbedit::TTeeSeriesDBSource(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeSeriesSource.Destroy */ inline __fastcall virtual ~TDBSummarySource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall TeeDBSummaryEditor(Classes::TComponent* AOwner, Teengine::TChartSeries* ASeries);

}	/* namespace Teedbsumedit */
using namespace Teedbsumedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDBSumEdit
