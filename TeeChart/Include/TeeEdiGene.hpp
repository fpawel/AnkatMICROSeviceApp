// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiGene.pas' rev: 6.00

#ifndef TeeEdiGeneHPP
#define TeeEdiGeneHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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

namespace Teeedigene
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeGeneral;
class PASCALIMPLEMENTATION TFormTeeGeneral : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* LSteps;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CBAllowZoom;
	Stdctrls::TCheckBox* CBAnimatedZoom;
	Stdctrls::TEdit* SEAniZoomSteps;
	Comctrls::TUpDown* UDAniZoomSteps;
	Teependlg::TButtonPen* BZoomPen;
	Stdctrls::TButton* BZoomColor;
	Stdctrls::TEdit* EMinPix;
	Comctrls::TUpDown* UDMinPix;
	Comctrls::TTabSheet* TabSheet2;
	Extctrls::TRadioGroup* RGPanning;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBDir;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBZoomMouse;
	Stdctrls::TLabel* Label4;
	Tecanvas::TComboFlat* CBScrollMouse;
	Stdctrls::TCheckBox* CBUpLeft;
	Comctrls::TTabSheet* TabCursor;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* CBCursor;
	Stdctrls::TGroupBox* GroupBox1;
	Extctrls::TImage* ImageCursor;
	Comctrls::TTabSheet* TabFont;
	Stdctrls::TListBox* LBFonts;
	Extctrls::TPanel* Panel1;
	Extctrls::TPanel* PanelFont;
	Extctrls::TSplitter* Splitter1;
	Stdctrls::TButton* BLoad;
	Dialogs::TOpenDialog* OpenDialog1;
	void __fastcall CBAllowZoomClick(System::TObject* Sender);
	void __fastcall CBAnimatedZoomClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGPanningClick(System::TObject* Sender);
	void __fastcall SEAniZoomStepsChange(System::TObject* Sender);
	void __fastcall BZoomColorClick(System::TObject* Sender);
	void __fastcall EMinPixChange(System::TObject* Sender);
	void __fastcall CBDirChange(System::TObject* Sender);
	void __fastcall CBZoomMouseChange(System::TObject* Sender);
	void __fastcall CBScrollMouseChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	void __fastcall CBUpLeftClick(System::TObject* Sender);
	void __fastcall LBFontsClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormDeactivate(System::TObject* Sender);
	void __fastcall LBFontsKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall BLoadClick(System::TObject* Sender);
	
private:
	Tecanvas::TTeeFont* IBackup;
	Tecanvas::TTeeFont* IFont;
	Teeedifont::TTeeFontEditor* IFontEditor;
	Classes::TNotifyEvent OldChange;
	void __fastcall ChangeCursor(Controls::TCursor ACursor);
	void __fastcall ChangedFont(System::TObject* Sender);
	void __fastcall EnableZoomControls(void);
	void __fastcall FillFonts(void);
	void __fastcall ResetIFont(void);
	Tecanvas::TTeeFont* __fastcall SelectedFont(int Index);
	
public:
	Chart::TCustomChart* TheChart;
	__fastcall TFormTeeGeneral(Classes::TComponent* Owner, Chart::TCustomChart* AChart);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeGeneral(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeGeneral(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeGeneral(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeGeneral(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TChartPageNavigator;
class PASCALIMPLEMENTATION TChartPageNavigator : public Teenavigator::TCustomTeeNavigator 
{
	typedef Teenavigator::TCustomTeeNavigator inherited;
	
private:
	Chart::TCustomChart* __fastcall GetChart(void);
	void __fastcall SetChart(const Chart::TCustomChart* Value);
	
protected:
	DYNAMIC void __fastcall BtnClick(Teenavigator::TTeeNavigateBtn Index);
	virtual void __fastcall DoTeeEvent(Teeprocs::TTeeEvent* Event);
	virtual void __fastcall SetPanel(const Teeprocs::TCustomTeePanel* Value);
	
public:
	virtual void __fastcall EnableButtons(void);
	virtual int __fastcall PageCount(void);
	virtual void __fastcall Print(void);
	
__published:
	__property Chart::TCustomChart* Chart = {read=GetChart, write=SetChart};
	__property OnButtonClicked ;
public:
	#pragma option push -w-inl
	/* TCustomTeeNavigator.Create */ inline __fastcall virtual TChartPageNavigator(Classes::TComponent* AOwner) : Teenavigator::TCustomTeeNavigator(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeeNavigator.Destroy */ inline __fastcall virtual ~TChartPageNavigator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartPageNavigator(HWND ParentWindow) : Teenavigator::TCustomTeeNavigator(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ChartPreview(Classes::TComponent* AOwner, Teeprocs::TCustomTeePanel* TeePanel);

}	/* namespace Teeedigene */
using namespace Teeedigene;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiGene
