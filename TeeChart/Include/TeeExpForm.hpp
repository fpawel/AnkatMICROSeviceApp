// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeExpForm.pas' rev: 6.00

#ifndef TeeExpFormHPP
#define TeeExpFormHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEditCha.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSelectList.hpp>	// Pascal unit
#include <TeeConst.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeGalleryPanel.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <FileCtrl.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teeexpform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeDlgWizard;
class PASCALIMPLEMENTATION TTeeDlgWizard : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl;
	Comctrls::TTabSheet* TabStyle;
	Comctrls::TTabSheet* TableName;
	Stdctrls::TLabel* Label3;
	Comctrls::TTabSheet* Buttons;
	Stdctrls::TLabel* Label2;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label4;
	Comctrls::TTabSheet* TabSheet2;
	Extctrls::TPanel* Panel1;
	Extctrls::TPanel* Panel2;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* cbLabelsFields;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabPreviewChart;
	Extctrls::TPanel* Panel7;
	Stdctrls::TCheckBox* CB3DOption;
	Stdctrls::TCheckBox* CBShowLegendOption;
	Stdctrls::TCheckBox* CBShowMarksOption;
	Extctrls::TPanel* Panel8;
	Extctrls::TPanel* Panel4;
	Extctrls::TImage* Image2;
	Stdctrls::TLabel* LabelURL;
	Extctrls::TPanel* Panel5;
	Stdctrls::TButton* PrevButton;
	Stdctrls::TButton* NextButton;
	Stdctrls::TButton* CancelBtn;
	Teegallerypanel::TChartGalleryPanel* tmpGallery;
	Extctrls::TRadioGroup* RGDatabase;
	Tecanvas::TComboFlat* CBAlias;
	Stdctrls::TLabel* Label5;
	Tecanvas::TComboFlat* CBTables;
	Extctrls::TImage* Image1;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TLabel* LabelDBStyle;
	Buttons::TSpeedButton* SpeedButton1;
	Stdctrls::TCheckBox* CBColorEach;
	Stdctrls::TLabel* LabelAlias;
	Tecanvas::TComboFlat* CBDBStyle;
	Comctrls::TTabSheet* TabFile;
	Buttons::TSpeedButton* BBrowse;
	Stdctrls::TRadioButton* RBFile;
	Stdctrls::TEdit* EFile;
	Stdctrls::TRadioButton* RBWeb;
	Stdctrls::TEdit* EWeb;
	Stdctrls::TLabel* Label1;
	Dialogs::TOpenDialog* OpenDialog1;
	Extctrls::TPanel* Panel3;
	Extctrls::TRadioGroup* RG3D;
	Stdctrls::TCheckBox* CBSmooth;
	Stdctrls::TButton* BTheme;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CancelClick(System::TObject* Sender);
	void __fastcall PrevClick(System::TObject* Sender);
	void __fastcall NextClick(System::TObject* Sender);
	void __fastcall Image1Click(System::TObject* Sender);
	void __fastcall CB3DOptionClick(System::TObject* Sender);
	void __fastcall CBShowLegendOptionClick(System::TObject* Sender);
	void __fastcall CBShowMarksOptionClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall LabelURLClick(System::TObject* Sender);
	void __fastcall RG3DClick(System::TObject* Sender);
	void __fastcall tmpGallerySelectedChart(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall CBTablesChange(System::TObject* Sender);
	void __fastcall CBAliasChange(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall CBDBStyleChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall BBrowseClick(System::TObject* Sender);
	void __fastcall RBFileClick(System::TObject* Sender);
	void __fastcall EFileChange(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall BThemeClick(System::TObject* Sender);
	
private:
	AnsiString LastFolder;
	AnsiString BackupDir;
	Teeselectlist::TSelectListForm* IFields;
	TMetaClass*ThemeClass;
	int NewChartPalette;
	void __fastcall ChangeGalleryPalette(void);
	void __fastcall CheckPreviewOptions(void);
	void __fastcall CreatePreviewChart(void);
	void __fastcall RefreshAlias(void);
	void __fastcall RefreshButtons(void);
	void __fastcall TryChangeFolder(const AnsiString S);
	
public:
	Chart::TChart* PreviewChart;
	void __fastcall CopyPreviewChart(Chart::TCustomChart* &Chart);
	void __fastcall CreateSeries(Classes::TComponent* AOwner, Chart::TCustomChart* AChart, bool ShowData);
	void __fastcall LoadChart(Chart::TCustomChart* &Chart);
	bool __fastcall StyleBDE(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeDlgWizard(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeDlgWizard(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeDlgWizard(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeDlgWizard(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define TeeMsg_WizardTable1 "Table1"
extern PACKAGE bool __fastcall TeeSelectFolder(const AnsiString Caption, const AnsiString Root, AnsiString &Folder);

}	/* namespace Teeexpform */
using namespace Teeexpform;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeExpForm
