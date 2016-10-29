// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGalleryAlternate.pas' rev: 6.00

#ifndef TeeGalleryAlternateHPP
#define TeeGalleryAlternateHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <TeeGalleryPanel.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teegalleryalternate
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeGalleryForm;
class PASCALIMPLEMENTATION TTeeGalleryForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teegallerypanel::TChartGalleryPanel* ChartGalleryPanel1;
	Teelisb::TChartListBox* ChartListBox1;
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* Panel1;
	Tecanvas::TComboFlat* CBPage;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CB3D;
	Stdctrls::TCheckBox* CBSmooth;
	Extctrls::TPanel* PanelBottom;
	Extctrls::TPanel* Panel3;
	Stdctrls::TButton* BOK;
	Stdctrls::TButton* BCancel;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall ChartListBox1Click(System::TObject* Sender);
	void __fastcall CBPageChange(System::TObject* Sender);
	void __fastcall CB3DClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall ChartGalleryPanel1SelectedChart(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	Chart::TChart* Chart;
	TMetaClass*OldClass;
	void __fastcall CreateChartList(const AnsiString APage);
	void __fastcall CreateGallery(TMetaClass* AClass);
	void __fastcall FillGalleryPages(Classes::TStrings* AItems);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeGalleryForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeGalleryForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeGalleryForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeGalleryForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teegalleryalternate */
using namespace Teegalleryalternate;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGalleryAlternate
