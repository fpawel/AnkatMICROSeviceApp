// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeXML.pas' rev: 6.00

#ifndef TeeXMLHPP
#define TeeXMLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeURL.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teexml
{
//-- type declarations -------------------------------------------------------
typedef OleVariant XmlDocument;

typedef OleVariant XmlNode;

typedef OleVariant XmlNodeList;

typedef OleVariant XmlAttributeCollection;

class DELPHICLASS TTeeXMLSource;
class PASCALIMPLEMENTATION TTeeXMLSource : public Teeurl::TTeeSeriesSourceFile 
{
	typedef Teeurl::TTeeSeriesSourceFile inherited;
	
private:
	Chart::TCustomChart* FChart;
	AnsiString FSeriesNode;
	AnsiString FValueSource;
	Classes::TStrings* FXML;
	OleVariant FXMLDocument;
	OleVariant __fastcall CreateAndLoadXML();
	void __fastcall CloseXML(void);
	void __fastcall FillSeries(Classes::TStrings* AItems);
	void __fastcall LoadSeriesNode(const OleVariant &ANode);
	void __fastcall SetSeriesNode(const AnsiString Value);
	void __fastcall SetValueSource(const AnsiString Value);
	void __fastcall SetChart(const Chart::TCustomChart* Value);
	void __fastcall SetXML(const Classes::TStrings* Value);
	void __fastcall XMLError(const AnsiString Reason);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetActive(const bool Value);
	
public:
	__fastcall virtual TTeeXMLSource(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeeXMLSource(void);
	virtual void __fastcall Close(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall Editor(TMetaClass* vmt);
	virtual void __fastcall Load(void);
	__property OleVariant XMLDocument = {read=FXMLDocument};
	
__published:
	__property Active  = {default=0};
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property FileName ;
	__property LoadMode  = {default=0};
	__property Series ;
	__property AnsiString SeriesNode = {read=FSeriesNode, write=SetSeriesNode};
	__property AnsiString ValueSource = {read=FValueSource, write=SetValueSource};
	__property Classes::TStrings* XML = {read=FXML, write=SetXML};
};


class DELPHICLASS TXMLSourceEditor;
class PASCALIMPLEMENTATION TXMLSourceEditor : public Teesourceedit::TBaseSourceEditor 
{
	typedef Teesourceedit::TBaseSourceEditor inherited;
	
__published:
	Dialogs::TOpenDialog* OpenDialog1;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBSeries;
	Stdctrls::TEdit* ESource;
	Stdctrls::TCheckBox* CBActive;
	Tecanvas::TComboFlat* CBLoadMode;
	Stdctrls::TLabel* Label1;
	Buttons::TSpeedButton* SpeedButton1;
	Stdctrls::TEdit* EFile;
	Stdctrls::TRadioButton* RBFile;
	Stdctrls::TRadioButton* RBManual;
	Stdctrls::TMemo* Memo1;
	Stdctrls::TButton* Button1;
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall EFileChange(System::TObject* Sender);
	void __fastcall CBSeriesDropDown(System::TObject* Sender);
	void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall ESourceChange(System::TObject* Sender);
	void __fastcall CBActiveClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBLoadModeChange(System::TObject* Sender);
	void __fastcall RBManualClick(System::TObject* Sender);
	void __fastcall RBFileClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Memo1Change(System::TObject* Sender);
	void __fastcall Memo1Enter(System::TObject* Sender);
	void __fastcall EFileEnter(System::TObject* Sender);
	
private:
	TTeeXMLSource* DataSource;
	void __fastcall EnableApply(void);
	void __fastcall FillXMLSeries(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TXMLSourceEditor(Classes::TComponent* AOwner) : Teesourceedit::TBaseSourceEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TXMLSourceEditor(Classes::TComponent* AOwner, int Dummy) : Teesourceedit::TBaseSourceEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TXMLSourceEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TXMLSourceEditor(HWND ParentWindow) : Teesourceedit::TBaseSourceEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teexml */
using namespace Teexml;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeXML
