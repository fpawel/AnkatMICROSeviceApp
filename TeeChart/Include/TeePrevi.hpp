// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePrevi.pas' rev: 6.00

#ifndef TeePreviHPP
#define TeePreviHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeePreviewPanel.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
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

namespace Teeprevi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartPreview;
class PASCALIMPLEMENTATION TChartPreview : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Tecanvas::TComboFlat* CBPrinters;
	Stdctrls::TLabel* Label1;
	Extctrls::TPanel* Panel2;
	Extctrls::TRadioGroup* Orientation;
	Stdctrls::TGroupBox* GBMargins;
	Stdctrls::TEdit* SETopMa;
	Stdctrls::TEdit* SELeftMa;
	Stdctrls::TEdit* SEBotMa;
	Stdctrls::TEdit* SERightMa;
	Stdctrls::TGroupBox* ChangeDetailGroup;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Comctrls::TUpDown* UDLeftMa;
	Comctrls::TUpDown* UDTopMa;
	Comctrls::TUpDown* UDRightMa;
	Comctrls::TUpDown* UDBotMa;
	Teepreviewpanel::TTeePreviewPanel* TeePreviewPanel1;
	Comctrls::TTrackBar* Resolution;
	Extctrls::TPanel* PanelMargins;
	Stdctrls::TButton* BReset;
	Stdctrls::TCheckBox* ShowMargins;
	Extctrls::TPanel* PanelOptions;
	Stdctrls::TCheckBox* CBProp;
	Stdctrls::TCheckBox* CBBitmap;
	Extctrls::TPanel* PanelClose;
	Stdctrls::TButton* BClose;
	Extctrls::TPanel* Panel3;
	Stdctrls::TButton* BSetupPrinter;
	Stdctrls::TButton* BPrint;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BSetupPrinterClick(System::TObject* Sender);
	void __fastcall CBPrintersChange(System::TObject* Sender);
	void __fastcall OrientationClick(System::TObject* Sender);
	void __fastcall SETopMaChange(System::TObject* Sender);
	void __fastcall SERightMaChange(System::TObject* Sender);
	void __fastcall SEBotMaChange(System::TObject* Sender);
	void __fastcall SELeftMaChange(System::TObject* Sender);
	void __fastcall ShowMarginsClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BResetClick(System::TObject* Sender);
	void __fastcall BPrintClick(System::TObject* Sender);
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall CBPropClick(System::TObject* Sender);
	void __fastcall TeePreviewPanel1ChangeMargins(System::TObject* Sender, bool DisableProportional, const Types::TRect &NewMargins);
	void __fastcall TrackBar1Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBBitmapClick(System::TObject* Sender);
	void __fastcall Panel1Resize(System::TObject* Sender);
	
private:
	bool ChangingMargins;
	bool ChangingProp;
	#pragma pack(push, 1)
	Types::TRect OldMargins;
	#pragma pack(pop)
	
	Teenavigator::TCustomTeeNavigator* PageNavigator1;
	void __fastcall Navigator1ButtonClicked(Teenavigator::TTeeNavigateBtn Index);
	void __fastcall ResetMargins(void);
	void __fastcall CheckOrientation(void);
	void __fastcall ChangeMargin(Comctrls::TUpDown* UpDown, int &APos, int OtherSide);
	
public:
	TMetaClass*PageNavigatorClass;
	Dialogs::TPrinterSetupDialog* PrinterSetupDialog1;
	void __fastcall HideCloseButton(void);
	Teepreviewpanel::TTeePreviewPanel* __fastcall PreviewPanel(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TChartPreview(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TChartPreview(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TChartPreview(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartPreview(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool TeeChangePaperOrientation;
extern PACKAGE void __fastcall TeePreview(Classes::TComponent* AOwner, Teeprocs::TCustomTeePanel* APanel);

}	/* namespace Teeprevi */
using namespace Teeprevi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePrevi
