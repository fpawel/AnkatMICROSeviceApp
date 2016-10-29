// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeThemeEditor.pas' rev: 6.00

#ifndef TeeThemeEditorHPP
#define TeeThemeEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeDraw3D.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeeThemes.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teethemeeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartThemeSelector;
class PASCALIMPLEMENTATION TChartThemeSelector : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Extctrls::TSplitter* Splitter1;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Chart::TChart* PreviewChart;
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TListBox* LBThemes;
	Extctrls::TPanel* Panel2;
	Extctrls::TPanel* Panel3;
	Stdctrls::TButton* BOK;
	Stdctrls::TButton* Button2;
	Stdctrls::TCheckBox* CheckBox1;
	Teetools::TRotateTool* ChartTool1;
	Extctrls::TPanel* Panel4;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBPalette;
	Stdctrls::TCheckBox* CBScale;
	Teedraw3d::TDraw3D* ScaledChart;
	void __fastcall LBThemesClick(System::TObject* Sender);
	void __fastcall BOKClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall Panel4Resize(System::TObject* Sender);
	void __fastcall CBPaletteChange(System::TObject* Sender);
	void __fastcall CBScaleClick(System::TObject* Sender);
	void __fastcall ScaledChartAfterDraw(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	
private:
	void __fastcall CheckScale(void);
	void __fastcall InitPreviewChart(void);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	
public:
	Chart::TCustomChart* Chart;
	TMetaClass* __fastcall SelectedTheme(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TChartThemeSelector(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TChartThemeSelector(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TChartThemeSelector(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartThemeSelector(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall AddChartThemes(Classes::TStrings* Items);
extern PACKAGE TMetaClass* __fastcall ChartThemeSelector(Chart::TCustomChart* AChart);
extern PACKAGE void __fastcall ShowThemesEditor(bool Value);

}	/* namespace Teethemeeditor */
using namespace Teethemeeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeThemeEditor
