// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGriEd.pas' rev: 6.00

#ifndef TeeGriEdHPP
#define TeeGriEdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeChartGrid.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
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

namespace Teegried
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGrid3DSeriesEditor;
class PASCALIMPLEMENTATION TGrid3DSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSingle;
	Tecanvas::TButtonColor* BColor;
	Comctrls::TTabSheet* TabRange;
	Tecanvas::TButtonColor* BFromColor;
	Tecanvas::TButtonColor* BMidColor;
	Tecanvas::TButtonColor* BToColor;
	Stdctrls::TCheckBox* CheckBox1;
	Stdctrls::TButton* Button1;
	Comctrls::TTabSheet* TabPalette;
	Stdctrls::TButton* BRemove;
	Extctrls::TTimer* Timer1;
	Stdctrls::TButton* Button2;
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabPaletteSteps;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* SEPalette;
	Comctrls::TUpDown* UDPalette;
	Stdctrls::TCheckBox* CBUseMin;
	Stdctrls::TEdit* EPaletteMin;
	Stdctrls::TEdit* EPaletteStep;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDLegendEvery;
	Extctrls::TPanel* Panel1;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* LDepth;
	Stdctrls::TEdit* SEXGrid;
	Comctrls::TUpDown* UDXGrid;
	Stdctrls::TEdit* SEZGrid;
	Comctrls::TUpDown* UDZGrid;
	Stdctrls::TEdit* EDepth;
	Comctrls::TUpDown* UDDepth;
	Stdctrls::TCheckBox* CBIrreg;
	Teechartgrid::TChartGrid* ChartGrid1;
	Stdctrls::TLabel* Label8;
	Extctrls::TPanel* Panel2;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBPalStyle;
	Stdctrls::TLabel* Label7;
	Tecanvas::TComboFlat* CBPalettes;
	Stdctrls::TButton* Button3;
	Menus::TPopupMenu* PopupMenu1;
	Menus::TMenuItem* Invert1;
	Stdctrls::TButton* Button4;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEZGridChange(System::TObject* Sender);
	void __fastcall SEPaletteChange(System::TObject* Sender);
	void __fastcall EDepthChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBIrregClick(System::TObject* Sender);
	void __fastcall CBPalStyleChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall CBUseMinClick(System::TObject* Sender);
	void __fastcall EPaletteMinChange(System::TObject* Sender);
	void __fastcall EPaletteStepChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall BMidColorClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall BRemoveClick(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall CBPalettesChange(System::TObject* Sender);
	void __fastcall ChartGrid1ChangeColor(System::TObject* Sender);
	void __fastcall ChartGrid1EditingCell(Teechartgrid::TCustomChartGrid* Sender, int ACol, int ARow, bool &Allow);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Invert1Click(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	
private:
	Teengine::TChartSeries* PaletteSeries;
	Teesurfa::TCustom3DPaletteSeries* Grid3D;
	void __fastcall CheckMidColor(void);
	bool __fastcall EditGradientColors(Graphics::TColor &AStart, Graphics::TColor &AMid, Graphics::TColor &AEnd, bool HideTabColors);
	void __fastcall SetCustomPalette(void);
	void __fastcall UpdatePalette(void);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
protected:
	bool Creating;
	
public:
	/*         class method */ static void __fastcall ApplyPalette(TMetaClass* vmt, Teesurfa::TCustom3DPaletteSeries* Series, int Index);
	void __fastcall RefreshControls(Teesurfa::TCustom3DPaletteSeries* AGrid);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TGrid3DSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TGrid3DSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TGrid3DSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGrid3DSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Forms::TCustomForm* __fastcall TeeInsertGrid3DForm(Controls::TControl* AParent, Teesurfa::TCustom3DPaletteSeries* AGrid3D);

}	/* namespace Teegried */
using namespace Teegried;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGriEd
