// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGally.pas' rev: 6.00

#ifndef TeeGallyHPP
#define TeeGallyHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeGalleryPanel.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teegally
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeGallery;
class PASCALIMPLEMENTATION TTeeGallery : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* P1;
	Stdctrls::TCheckBox* CB3D;
	Comctrls::TTabControl* TabPages;
	Comctrls::TTabControl* TabTypes;
	Teegallerypanel::TChartGalleryPanel* ChartGalleryPanel1;
	Stdctrls::TCheckBox* CBSmooth;
	Tecanvas::TComboFlat* CBPalette;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	void __fastcall CB3DClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall TabPagesChange(System::TObject* Sender);
	void __fastcall TabTypesChange(System::TObject* Sender);
	void __fastcall ChartGalleryPanel1SelectedChart(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall CBPaletteChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	bool OnlyFunctions;
	int __fastcall SelectedPaletteIndex(void);
	void __fastcall SetPalette(int Index);
	
public:
	void __fastcall HideButtons(void);
	void __fastcall HideFunctions(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeGallery(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeGallery(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeGallery(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeGallery(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define TeeMsg_RememberGallerySize "RememberGallerySize"
extern PACKAGE bool __fastcall GetChartGalleryClass(Classes::TComponent* AOwner, Teengine::TChartSeries* OldSeries, bool ShowFunctions, TMetaClass* &tmpClass, bool &Show3D, TMetaClass* &tmpFunctionClass, bool CheckValidSeries, int &SubIndex, int &ColorPaletteIndex);
extern PACKAGE Teengine::TChartSeries* __fastcall CreateNewSeriesGallery(Classes::TComponent* AOwner, Teengine::TCustomAxisPanel* AChart)/* overload */;
extern PACKAGE Teengine::TChartSeries* __fastcall CreateNewSeriesGallery(Classes::TComponent* AOwner, Teengine::TChartSeries* OldSeries, Teengine::TCustomAxisPanel* tmpChart, bool AllowSameType, bool CheckSeries, int &SubIndex)/* overload */;
extern PACKAGE void __fastcall ChangeSeriesTypeGallery(Classes::TComponent* AOwner, Teengine::TChartSeries* &tmpSeries);
extern PACKAGE void __fastcall ChangeAllSeriesGallery(Classes::TComponent* AOwner, Chart::TCustomChart* AChart);
extern PACKAGE TMetaClass* __fastcall GetChartGalleryFunction(Classes::TComponent* AOwner);

}	/* namespace Teegally */
using namespace Teegally;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGally
