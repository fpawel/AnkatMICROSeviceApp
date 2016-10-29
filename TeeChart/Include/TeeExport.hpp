// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeExport.pas' rev: 6.00

#ifndef TeeExportHPP
#define TeeExportHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeConst.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeexport
{
//-- type declarations -------------------------------------------------------
typedef char TeeSeparatorChar;

class DELPHICLASS TTeeExportFormat;
class PASCALIMPLEMENTATION TTeeExportFormat : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Teeprocs::TCustomTeePanel* FPanel;
	
protected:
	int FFilterIndex;
	void __fastcall CheckSize(void);
	virtual void __fastcall DoCopyToClipboard(void) = 0 ;
	virtual int __fastcall FileFilterIndex(void);
	virtual void __fastcall IncFileFilterIndex(int &FilterIndex);
	virtual bool __fastcall WantsFilterIndex(int Index);
	
public:
	int Height;
	int Width;
	__fastcall virtual TTeeExportFormat(void);
	__fastcall virtual ~TTeeExportFormat(void);
	void __fastcall CopyToClipboard(void);
	virtual AnsiString __fastcall Description(void) = 0 ;
	virtual AnsiString __fastcall FileExtension(void) = 0 ;
	virtual AnsiString __fastcall FileFilter(void) = 0 ;
	virtual TMetaClass* __fastcall GraphicClass(void);
	void __fastcall SaveToFile(const AnsiString FileName)/* overload */;
	/*         class method */ static void __fastcall SaveToFile(TMetaClass* vmt, Teeprocs::TCustomTeePanel* APanel, const AnsiString FileName)/* overload */;
	virtual void __fastcall SaveToStream(Classes::TStream* Stream) = 0 ;
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	__property Teeprocs::TCustomTeePanel* Panel = {read=FPanel, write=FPanel};
};


class DELPHICLASS TTeeExportFormBase;
class PASCALIMPLEMENTATION TTeeExportFormBase : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Dialogs::TSaveDialog* SaveDialogPicture;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabPicture;
	Comctrls::TTabSheet* TabData;
	Stdctrls::TGroupBox* RGFormat;
	Dialogs::TSaveDialog* SaveDialogData;
	Comctrls::TTabSheet* TabNative;
	Stdctrls::TCheckBox* CBNativeData;
	Dialogs::TSaveDialog* SaveDialogNative;
	Stdctrls::TLabel* LabelSize;
	Stdctrls::TCheckBox* CBFileSize;
	Comctrls::TPageControl* PageOptions;
	Comctrls::TTabSheet* TabOptions;
	Comctrls::TTabSheet* TabSize;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EWidth;
	Comctrls::TUpDown* UDWidth;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EHeight;
	Comctrls::TUpDown* UDHeight;
	Stdctrls::TCheckBox* CBAspect;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* BCopy;
	Stdctrls::TButton* BSave;
	Stdctrls::TButton* BSend;
	Stdctrls::TButton* BClose;
	Stdctrls::TListBox* LBFormat;
	Extctrls::TPanel* Panel2;
	Extctrls::TSplitter* SplitPic;
	Extctrls::TPanel* Panel3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* CBDelim;
	Stdctrls::TEdit* ECustom;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBLabels;
	Stdctrls::TCheckBox* CBIndex;
	Stdctrls::TCheckBox* CBHeader;
	Stdctrls::TCheckBox* CBColors;
	Stdctrls::TEdit* EQuotes;
	Extctrls::TPanel* Panel5;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBSeries;
	Extctrls::TRadioGroup* RGText;
	Extctrls::TRadioGroup* CBNativeFormat;
	Stdctrls::TButton* BViewNative;
	Stdctrls::TCheckBox* CBPicSize;
	Stdctrls::TLabel* LabelPicSize;
	Stdctrls::TCheckBox* CBUseSeriesFormat;
	Stdctrls::TLabel* Label5;
	Tecanvas::TComboFlat* SeriesValueFormat;
	Buttons::TSpeedButton* BFormat;
	void __fastcall BCopyClick(System::TObject* Sender);
	void __fastcall BSaveClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall RGFormatClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EWidthChange(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall RGTextClick(System::TObject* Sender);
	void __fastcall CBFileSizeClick(System::TObject* Sender);
	void __fastcall CBNativeDataClick(System::TObject* Sender);
	void __fastcall CBDelimChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall BSendClick(System::TObject* Sender);
	void __fastcall Panel5Resize(System::TObject* Sender);
	void __fastcall CBNativeFormatClick(System::TObject* Sender);
	void __fastcall BViewNativeClick(System::TObject* Sender);
	void __fastcall CBPicSizeClick(System::TObject* Sender);
	void __fastcall PageOptionsChange(System::TObject* Sender);
	void __fastcall CBUseSeriesFormatClick(System::TObject* Sender);
	void __fastcall BFormatClick(System::TObject* Sender);
	
private:
	bool ChangingSize;
	Classes::TStrings* Formats;
	double IAspect;
	bool __fastcall CanChangeSize(void);
	void __fastcall CheckFileSize(void);
	int __fastcall GetDataFilterIndex(void);
	TTeeExportFormat* __fastcall GuessPictureFormat(const AnsiString FileName);
	void __fastcall FreeExportFormats(void);
	AnsiString __fastcall NativeAsString();
	TTeeExportFormat* __fastcall PictureFormat(void);
	void __fastcall SaveNativeToFile(const AnsiString FileName);
	void __fastcall SavePictureToFile(const AnsiString FileName);
	
protected:
	virtual Teeprocs::TTeeExportData* __fastcall CreateData(void);
	virtual Classes::TStream* __fastcall CreateNativeStream(void);
	virtual void __fastcall DoSaveNativeToFile(const AnsiString FileName, bool IncludeData);
	virtual bool __fastcall ExistData(void);
	AnsiString __fastcall GetNativeExtension();
	AnsiString __fastcall GetNativeFilter();
	char __fastcall GetSeparator(void);
	bool __fastcall NativeAsText(void);
	virtual void __fastcall PrepareOnShow(void);
	void __fastcall SaveDataToFile(const AnsiString FileName);
	
public:
	Teeprocs::TCustomTeePanel* ExportPanel;
	AnsiString EmailName;
	AnsiString NativeFilter;
	AnsiString NativeExtension;
	AnsiString DataFilter;
	AnsiString InitDir;
	void __fastcall EnableButtons(void);
	/*         class method */ static AnsiString __fastcall GetTempFolder(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeExportFormBase(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeExportFormBase(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeExportFormBase(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeExportFormBase(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TTeeExportFormatClass;

class DELPHICLASS TTeeExportFormats;
class PASCALIMPLEMENTATION TTeeExportFormats : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TMetaClass* operator[](int Index) { return Format[Index]; }
	
private:
	HIDESBASE TMetaClass* __fastcall Get(int Index);
	
public:
	__property TMetaClass* Format[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TTeeExportFormats(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeExportFormats(void) : Classes::TList() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TTeeExportFormats* TeeExportFormats;
extern PACKAGE Graphics::TGraphic* __fastcall WithFileExtension(const AnsiString FileExtension);
extern PACKAGE void __fastcall SaveTeeToStream(Teeprocs::TCustomTeePanel* APanel, Classes::TStream* AStream);
extern PACKAGE void __fastcall SaveTeeToFile(Teeprocs::TCustomTeePanel* APanel, const AnsiString AName);
extern PACKAGE void __fastcall LoadTeeFromStream(Teeprocs::TCustomTeePanel* &APanel, Classes::TStream* AStream);
extern PACKAGE void __fastcall LoadTeeFromFile(Teeprocs::TCustomTeePanel* &APanel, const AnsiString AName);
extern PACKAGE void __fastcall TeeFillPictureDialog(Dialogs::TSaveDialog* ADialog, Teeprocs::TCustomTeePanel* APanel, Classes::TStrings* AItems);
extern PACKAGE void __fastcall RegisterTeeExportFormat(TMetaClass* AFormat);
extern PACKAGE void __fastcall UnRegisterTeeExportFormat(TMetaClass* AFormat);
extern PACKAGE void __fastcall TeeExportSavePanel(TMetaClass* AFormat, Teeprocs::TCustomTeePanel* APanel);
extern PACKAGE void __fastcall InternalTeeEmailFile(const AnsiString FileName, const AnsiString Subject = "TeeChart");
extern PACKAGE AnsiString __fastcall GetRegistryHelpPath(const AnsiString HelpFile);

}	/* namespace Teeexport */
using namespace Teeexport;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeExport
