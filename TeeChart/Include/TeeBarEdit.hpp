// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBarEdit.pas' rev: 6.00

#ifndef TeeBarEditHPP
#define TeeBarEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
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

namespace Teebaredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBarSeriesEditor;
class PASCALIMPLEMENTATION TBarSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* LStyle;
	Tecanvas::TComboFlat* CBBarStyle;
	Stdctrls::TButton* BBarBrush;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TCheckBox* CBColorEach;
	Tecanvas::TButtonColor* BBarColor;
	Stdctrls::TButton* BGradient;
	Teependlg::TButtonPen* BTickLines;
	Stdctrls::TCheckBox* CBDarkBar;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* SEBarwidth;
	Stdctrls::TEdit* SEBarOffset;
	Comctrls::TUpDown* UDBarWidth;
	Comctrls::TUpDown* UDBarOffset;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDDepth;
	Stdctrls::TCheckBox* CBBarSideMargins;
	Stdctrls::TCheckBox* CBMarksAutoPosition;
	Comctrls::TTabSheet* TabShadow;
	Comctrls::TTabSheet* TabSheet3;
	Teependlg::TButtonPen* BBarPen;
	Stdctrls::TLabel* LBevel;
	Stdctrls::TEdit* EBevel;
	Comctrls::TUpDown* UDBevel;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDDarkPen;
	Stdctrls::TLabel* LTransp;
	Comctrls::TTrackBar* TBTransp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEBarwidthChange(System::TObject* Sender);
	void __fastcall CBBarStyleChange(System::TObject* Sender);
	void __fastcall BBarBrushClick(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall CBDarkBarClick(System::TObject* Sender);
	void __fastcall CBBarSideMarginsClick(System::TObject* Sender);
	void __fastcall SEBarOffsetChange(System::TObject* Sender);
	void __fastcall CBMarksAutoPositionClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BGradientClick(System::TObject* Sender);
	void __fastcall EBevelChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall TBTranspChange(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Series::TCustomBarSeries* Bar;
	Forms::TCustomForm* FStackEditor;
	void __fastcall AddStackBarEditor(void);
	void __fastcall CheckControls(void);
	void __fastcall RefreshShape(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBarSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBarSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBarSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBarSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teebaredit */
using namespace Teebaredit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBarEdit
