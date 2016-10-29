// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDBCrossTab.pas' rev: 6.00

#ifndef TeeDBCrossTabHPP
#define TeeDBCrossTabHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeDBEdit.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <DBChart.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teedbcrosstab
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TGroupFormula { gfCount, gfSum };
#pragma option pop

class DELPHICLASS TDBCrossTabSource;
class PASCALIMPLEMENTATION TDBCrossTabSource : public Teedbedit::TTeeSeriesDBSource 
{
	typedef Teedbedit::TTeeSeriesDBSource inherited;
	
private:
	bool FCase;
	Db::TDataSet* FDataSet;
	TGroupFormula FFormula;
	AnsiString FGroup;
	bool FHideSeries;
	AnsiString FLabel;
	AnsiString FValue;
	Dbchart::TDBChartDataSource* ISource;
	void __fastcall DataSourceCheckDataSet(Db::TDataSet* ADataSet);
	void __fastcall DataSourceCloseDataSet(Db::TDataSet* ADataSet);
	void __fastcall LoadDataSet(void);
	void __fastcall RemoveSeries(void);
	void __fastcall SetDataSet(const Db::TDataSet* Value);
	void __fastcall SetFormula(const TGroupFormula Value);
	void __fastcall SetGroup(const AnsiString Value);
	void __fastcall SetLabel(const AnsiString Value);
	void __fastcall SetValue(const AnsiString Value);
	void __fastcall SetCase(const bool Value);
	
protected:
	bool KeepDataOnClose;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetActive(const bool Value);
	
public:
	__fastcall virtual TDBCrossTabSource(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBCrossTabSource(void);
	/* virtual class method */ virtual bool __fastcall Available(TMetaClass* vmt, Teengine::TCustomAxisPanel* AChart);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	/* virtual class method */ virtual bool __fastcall HasSeries(TMetaClass* vmt, Teengine::TChartSeries* ASeries);
	virtual void __fastcall Load(void);
	
__published:
	__property Active  = {default=0};
	__property bool CaseSensitive = {read=FCase, write=SetCase, default=1};
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property TGroupFormula Formula = {read=FFormula, write=SetFormula, default=1};
	__property AnsiString GroupField = {read=FGroup, write=SetGroup};
	__property bool HideSeries = {read=FHideSeries, write=FHideSeries, default=1};
	__property AnsiString LabelField = {read=FLabel, write=SetLabel};
	__property Series ;
	__property AnsiString ValueField = {read=FValue, write=SetValue};
};


class DELPHICLASS TDBChartCrossTabEditor;
class PASCALIMPLEMENTATION TDBChartCrossTabEditor : public Teedbedit::TBaseDBChartEditor 
{
	typedef Teedbedit::TBaseDBChartEditor inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBAgg;
	Tecanvas::TComboFlat* CBValue;
	Tecanvas::TComboFlat* CBGroup;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBLabels;
	Stdctrls::TCheckBox* CBActive;
	Stdctrls::TCheckBox* CBCase;
	Stdctrls::TCheckBox* CBHide;
	Extctrls::TPanel* PanelButtons;
	Extctrls::TPanel* Panel2;
	Stdctrls::TButton* BOK;
	HIDESBASE void __fastcall CBSourcesChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	void __fastcall CBAggChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBActiveClick(System::TObject* Sender);
	void __fastcall CBCaseClick(System::TObject* Sender);
	void __fastcall CBHideClick(System::TObject* Sender);
	
private:
	TDBCrossTabSource* DataSource;
	void __fastcall EnableCombos(void);
	
public:
	DYNAMIC void __fastcall Translate(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDBChartCrossTabEditor(Classes::TComponent* AOwner) : Teedbedit::TBaseDBChartEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDBChartCrossTabEditor(Classes::TComponent* AOwner, int Dummy) : Teedbedit::TBaseDBChartEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDBChartCrossTabEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBChartCrossTabEditor(HWND ParentWindow) : Teedbedit::TBaseDBChartEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall FillDataSet(Db::TDataSet* ADataSet, Teengine::TChartSeries* ASeries, const AnsiString AGroupField, const AnsiString ALabelField, const AnsiString AValueField, TGroupFormula GroupFormula);

}	/* namespace Teedbcrosstab */
using namespace Teedbcrosstab;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDBCrossTab
