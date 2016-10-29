// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSeriesTextEd.pas' rev: 6.00

#ifndef TeeSeriesTextEdHPP
#define TeeSeriesTextEdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeURL.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teeseriestexted
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSeriesTextField;
typedef void __fastcall (__closure *TSeriesTextGetValue)(TSeriesTextField* Field, const AnsiString Text, double &Value);

class PASCALIMPLEMENTATION TSeriesTextField : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	int FFieldIndex;
	AnsiString FFieldName;
	TSeriesTextGetValue FOnGetValue;
	void __fastcall SetFieldIndex(const int Value);
	
protected:
	System::TObject* Data;
	
__published:
	__property int FieldIndex = {read=FFieldIndex, write=SetFieldIndex, nodefault};
	__property AnsiString FieldName = {read=FFieldName, write=FFieldName};
	__property TSeriesTextGetValue OnGetValue = {read=FOnGetValue, write=FOnGetValue};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TSeriesTextField(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TSeriesTextField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesTextFields;
class PASCALIMPLEMENTATION TSeriesTextFields : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TSeriesTextField* operator[](int Index) { return Items[Index]; }
	
private:
	TSeriesTextField* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TSeriesTextField* Value);
	
public:
	__property TSeriesTextField* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TSeriesTextFields(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TSeriesTextFields(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesTextSource;
class PASCALIMPLEMENTATION TSeriesTextSource : public Teeurl::TTeeSeriesSourceFile 
{
	typedef Teeurl::TTeeSeriesSourceFile inherited;
	
private:
	TSeriesTextFields* FFields;
	int FHeader;
	AnsiString FSeparator;
	Classes::TStrings* FText;
	void __fastcall SetFields(const TSeriesTextFields* Value);
	void __fastcall SetText(const Classes::TStrings* Value);
	
public:
	__fastcall virtual TSeriesTextSource(Classes::TComponent* AOwner);
	__fastcall virtual ~TSeriesTextSource(void);
	TSeriesTextField* __fastcall AddField(const AnsiString AName, int AIndex);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	virtual void __fastcall LoadFromStream(Classes::TStream* AStream);
	void __fastcall LoadFromStrings(Classes::TStrings* AStrings);
	
__published:
	__property Active  = {default=0};
	__property int HeaderLines = {read=FHeader, write=FHeader, default=0};
	__property TSeriesTextFields* Fields = {read=FFields, write=SetFields};
	__property AnsiString FieldSeparator = {read=FSeparator, write=FSeparator};
	__property FileName ;
	__property Series ;
	__property Classes::TStrings* Text = {read=FText, write=SetText};
};


class DELPHICLASS TSeriesTextEditor;
class PASCALIMPLEMENTATION TSeriesTextEditor : public Teesourceedit::TBaseSourceEditor 
{
	typedef Teesourceedit::TBaseSourceEditor inherited;
	
__published:
	Dialogs::TOpenDialog* OpenDialog1;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UpDown1;
	Grids::TStringGrid* StringGrid1;
	Tecanvas::TComboFlat* CBSeries;
	Tecanvas::TComboFlat* CBSep;
	Comctrls::TTabSheet* TabSheet2;
	Buttons::TSpeedButton* BBrowse;
	Stdctrls::TRadioButton* RBFile;
	Stdctrls::TEdit* EFile;
	Stdctrls::TRadioButton* RBWeb;
	Stdctrls::TEdit* EWeb;
	Stdctrls::TButton* ButtonLoad;
	Extctrls::TPanel* PanBot;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TMemo* MemoText;
	Stdctrls::TRadioButton* RBManual;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ButtonLoadClick(System::TObject* Sender);
	void __fastcall RBFileClick(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	void __fastcall EFileChange(System::TObject* Sender);
	void __fastcall EWebChange(System::TObject* Sender);
	void __fastcall CBSepChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall StringGrid1SetEditText(System::TObject* Sender, int ACol, int ARow, const AnsiString Value);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall MemoTextChange(System::TObject* Sender);
	void __fastcall RBManualClick(System::TObject* Sender);
	
private:
	bool InternalSource;
	void __fastcall HideSeriesCombo(void);
	Teengine::TChartSeries* __fastcall SelectedSeries(void);
	void __fastcall SetOptions(void);
	
public:
	TSeriesTextSource* DataSource;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSeriesTextEditor(Classes::TComponent* AOwner) : Teesourceedit::TBaseSourceEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesTextEditor(Classes::TComponent* AOwner, int Dummy) : Teesourceedit::TBaseSourceEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSeriesTextEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesTextEditor(HWND ParentWindow) : Teesourceedit::TBaseSourceEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const char TeeDefaultFieldSeparator = '\x2c';
extern PACKAGE void __fastcall TeeEditSeriesTextSource(TSeriesTextSource* ASource);

}	/* namespace Teeseriestexted */
using namespace Teeseriestexted;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSeriesTextEd
