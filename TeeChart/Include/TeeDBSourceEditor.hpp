// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDBSourceEditor.pas' rev: 6.00

#ifndef TeeDBSourceEditorHPP
#define TeeDBSourceEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSelectList.hpp>	// Pascal unit
#include <TeeDBEdit.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedbsourceeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDBChartSourceEditor;
class PASCALIMPLEMENTATION TDBChartSourceEditor : public Teedbedit::TBaseDBChartEditor 
{
	typedef Teedbedit::TBaseDBChartEditor inherited;
	
__published:
	void __fastcall BApplyClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall CBSourcesChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Dbctrls::TDBNavigator* INavig;
	Teeselectlist::TSelectListForm* ISources;
	HIDESBASE void __fastcall FillFields(void);
	Db::TDataSource* __fastcall DataSource(void);
	void __fastcall OnChangeSources(System::TObject* Sender);
	
protected:
	virtual bool __fastcall IsValid(Classes::TComponent* AComponent);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDBChartSourceEditor(Classes::TComponent* AOwner) : Teedbedit::TBaseDBChartEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDBChartSourceEditor(Classes::TComponent* AOwner, int Dummy) : Teedbedit::TBaseDBChartEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDBChartSourceEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBChartSourceEditor(HWND ParentWindow) : Teedbedit::TBaseDBChartEditor(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TSingleRecordSeriesSource;
class PASCALIMPLEMENTATION TSingleRecordSeriesSource : public Teedbedit::TTeeSeriesDBSource 
{
	typedef Teedbedit::TTeeSeriesDBSource inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	/* virtual class method */ virtual bool __fastcall HasSeries(TMetaClass* vmt, Teengine::TChartSeries* ASeries);
public:
	#pragma option push -w-inl
	/* TTeeSeriesSource.Create */ inline __fastcall virtual TSingleRecordSeriesSource(Classes::TComponent* AOwner) : Teedbedit::TTeeSeriesDBSource(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeSeriesSource.Destroy */ inline __fastcall virtual ~TSingleRecordSeriesSource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teedbsourceeditor */
using namespace Teedbsourceeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDBSourceEditor
