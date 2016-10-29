// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeExcelSource.pas' rev: 6.00

#ifndef TeeExcelSourceHPP
#define TeeExcelSourceHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeURL.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeexcelsource
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeExcelSource;
class PASCALIMPLEMENTATION TTeeExcelSource : public Teeurl::TTeeSeriesSourceFile 
{
	typedef Teeurl::TTeeSeriesSourceFile inherited;
	
private:
	Variant FExcel;
	AnsiString FLabelsFrom;
	AnsiString FLabelsTo;
	AnsiString FRangeFrom;
	AnsiString FRangeTo;
	AnsiString FWorkSheet;
	bool FRunning;
	OleVariant WorkBook;
	void __fastcall OpenWorkBook(void);
	void __fastcall SetLabelsFrom(const AnsiString Value);
	void __fastcall SetLabelsTo(const AnsiString Value);
	void __fastcall SetRangeFrom(const AnsiString Value);
	void __fastcall SetRangeTo(const AnsiString Value);
	void __fastcall SetWorkSheet(const AnsiString Value);
	
public:
	virtual void __fastcall Close(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	virtual void __fastcall Load(void);
	
__published:
	__property Active  = {default=0};
	__property FileName ;
	__property AnsiString LabelsFrom = {read=FLabelsFrom, write=SetLabelsFrom};
	__property AnsiString LabelsTo = {read=FLabelsTo, write=SetLabelsTo};
	__property AnsiString RangeFrom = {read=FRangeFrom, write=SetRangeFrom};
	__property AnsiString RangeTo = {read=FRangeTo, write=SetRangeTo};
	__property Series ;
	__property AnsiString WorkSheet = {read=FWorkSheet, write=SetWorkSheet};
public:
	#pragma option push -w-inl
	/* TTeeSeriesSource.Create */ inline __fastcall virtual TTeeExcelSource(Classes::TComponent* AOwner) : Teeurl::TTeeSeriesSourceFile(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeSeriesSource.Destroy */ inline __fastcall virtual ~TTeeExcelSource(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExcelSourceForm;
class PASCALIMPLEMENTATION TExcelSourceForm : public Teesourceedit::TBaseSourceEditor 
{
	typedef Teesourceedit::TBaseSourceEditor inherited;
	
__published:
	Stdctrls::TLabel* LabelFile;
	Stdctrls::TEdit* EFileName;
	Stdctrls::TLabel* LabelSheet;
	Tecanvas::TComboFlat* CBWorkSheet;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EValFrom;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EValTo;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* ELabFrom;
	Stdctrls::TEdit* ELabTo;
	Dialogs::TOpenDialog* OpenDialog1;
	Stdctrls::TButton* Button1;
	void __fastcall CBWorkSheetChange(System::TObject* Sender);
	void __fastcall EFileNameChange(System::TObject* Sender);
	void __fastcall EValFromChange(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	void __fastcall CheckControls(void);
	void __fastcall FillWorkSheets(void);
	
public:
	TTeeExcelSource* DataSource;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TExcelSourceForm(Classes::TComponent* AOwner) : Teesourceedit::TBaseSourceEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TExcelSourceForm(Classes::TComponent* AOwner, int Dummy) : Teesourceedit::TBaseSourceEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TExcelSourceForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TExcelSourceForm(HWND ParentWindow) : Teesourceedit::TBaseSourceEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeexcelsource */
using namespace Teeexcelsource;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeExcelSource
