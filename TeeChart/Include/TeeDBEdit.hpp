// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDBEdit.pas' rev: 6.00

#ifndef TeeDBEditHPP
#define TeeDBEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
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

namespace Teedbedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBaseDBChartEditor;
class PASCALIMPLEMENTATION TBaseDBChartEditor : public Teesourceedit::TBaseSourceEditor 
{
	typedef Teesourceedit::TBaseSourceEditor inherited;
	
__published:
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	
private:
	void __fastcall FillSourceDatasets(void);
	void __fastcall FillSources(void);
	
protected:
	Db::TDataSet* __fastcall DataSet(void);
	void __fastcall FillFields(const Stdctrls::TComboBox* * Combos, const int Combos_Size);
	virtual bool __fastcall IsValid(Classes::TComponent* AComponent);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBaseDBChartEditor(Classes::TComponent* AOwner) : Teesourceedit::TBaseSourceEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBaseDBChartEditor(Classes::TComponent* AOwner, int Dummy) : Teesourceedit::TBaseSourceEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBaseDBChartEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBaseDBChartEditor(HWND ParentWindow) : Teesourceedit::TBaseSourceEditor(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeSeriesDBSource;
class PASCALIMPLEMENTATION TTeeSeriesDBSource : public Teengine::TTeeSeriesSource 
{
	typedef Teengine::TTeeSeriesSource inherited;
	
public:
	/* virtual class method */ virtual bool __fastcall Available(TMetaClass* vmt, Teengine::TCustomAxisPanel* AChart);
	/* virtual class method */ virtual bool __fastcall HasNew(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TTeeSeriesSource.Create */ inline __fastcall virtual TTeeSeriesDBSource(Classes::TComponent* AOwner) : Teengine::TTeeSeriesSource(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeSeriesSource.Destroy */ inline __fastcall virtual ~TTeeSeriesDBSource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Teesourceedit::TOnGetDesignerNamesEvent OnGetDesignerNames;

}	/* namespace Teedbedit */
using namespace Teedbedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDBEdit
