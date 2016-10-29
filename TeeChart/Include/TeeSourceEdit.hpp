// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSourceEdit.pas' rev: 6.00

#ifndef TeeSourceEditHPP
#define TeeSourceEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teesourceedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBaseSourceEditor;
class PASCALIMPLEMENTATION TBaseSourceEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* LLabel;
	Tecanvas::TComboFlat* CBSources;
	Extctrls::TPanel* Pan;
	Extctrls::TPanel* PanelApply;
	Stdctrls::TButton* BApply;
	void __fastcall CBSourcesChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall FormCreate(System::TObject* Sender);
	
protected:
	Chart::TCustomChart* Chart;
	Teengine::TChartSeries* TheSeries;
	bool SkipValidation;
	void __fastcall AddComponentDataSource(const Classes::TComponent* AComponent, Classes::TStrings* AItems, bool AddCurrent);
	void __fastcall CheckReplaceSource(Teengine::TTeeSeriesSource* NewSource);
	virtual bool __fastcall IsValid(Classes::TComponent* AComponent);
	
public:
	DYNAMIC void __fastcall Translate(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBaseSourceEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBaseSourceEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBaseSourceEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBaseSourceEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TAddComponentDataSource)(const Classes::TComponent* AComponent, Classes::TStrings* AItems, bool AddCurrent);

typedef void __fastcall (*TOnGetDesignerNamesEvent)(TAddComponentDataSource AProc, Teengine::TChartSeries* ASeries, Classes::TStrings* AItems, bool AddCurrent);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesourceedit */
using namespace Teesourceedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSourceEdit
