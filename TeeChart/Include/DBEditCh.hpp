// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBEditCh.pas' rev: 6.00

#ifndef DBEditChHPP
#define DBEditChHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeeDBEdit.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeEdiSeri.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbeditch
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDBChartEditor;
class PASCALIMPLEMENTATION TDBChartEditor : public Teedbedit::TBaseDBChartEditor 
{
	typedef Teedbedit::TBaseDBChartEditor inherited;
	
__published:
	Forms::TScrollBox* GroupFields;
	Stdctrls::TLabel* LLabels;
	Tecanvas::TComboFlat* CBLabelsField;
	void __fastcall CBLabelsFieldChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	HIDESBASE void __fastcall CBSourcesChange(System::TObject* Sender);
	
private:
	Stdctrls::TLabel* LabelValues[16];
	Stdctrls::TCheckBox* CBDateTime[16];
	void __fastcall CBValuesChange(System::TObject* Sender);
	void __fastcall SetFields(void);
	void __fastcall SetTextItemIndex(Tecanvas::TComboFlat* Combo);
	
protected:
	virtual bool __fastcall IsValid(Classes::TComponent* AComponent);
	
public:
	Tecanvas::TComboFlat* CBValues[16];
	DYNAMIC void __fastcall Translate(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDBChartEditor(Classes::TComponent* AOwner) : Teedbedit::TBaseDBChartEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDBChartEditor(Classes::TComponent* AOwner, int Dummy) : Teedbedit::TBaseDBChartEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDBChartEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBChartEditor(HWND ParentWindow) : Teedbedit::TBaseDBChartEditor(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetSeriesSource;
class PASCALIMPLEMENTATION TDataSetSeriesSource : public Teedbedit::TTeeSeriesDBSource 
{
	typedef Teedbedit::TTeeSeriesDBSource inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	/* virtual class method */ virtual bool __fastcall HasSeries(TMetaClass* vmt, Teengine::TChartSeries* ASeries);
public:
	#pragma option push -w-inl
	/* TTeeSeriesSource.Create */ inline __fastcall virtual TDataSetSeriesSource(Classes::TComponent* AOwner) : Teedbedit::TTeeSeriesDBSource(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeSeriesSource.Destroy */ inline __fastcall virtual ~TDataSetSeriesSource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxValueSources = 0x10;

}	/* namespace Dbeditch */
using namespace Dbeditch;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBEditCh
