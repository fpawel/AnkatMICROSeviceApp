// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeWorldSeries.pas' rev: 6.00

#ifndef TeeWorldSeriesHPP
#define TeeWorldSeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeChartGrid.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <TeeMapSeriesEdit.hpp>	// Pascal unit
#include <TeeMapSeries.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeworldseries
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TWorldMap { wmWorld, wmAfrica, wmAsia, wmAustralia, wmCentralAmerica, wmEurope, wmEurope15, wmEurope27, wmSpain, wmMiddleEast, wmNorthAmerica, wmSouthAmerica, wmUSA, wmUSAHawaiiAlaska };
#pragma option pop

class DELPHICLASS TWorldSeries;
class PASCALIMPLEMENTATION TWorldSeries : public Teemapseries::TMapSeries 
{
	typedef Teemapseries::TMapSeries inherited;
	
private:
	TWorldMap FMap;
	bool InGallery;
	void __fastcall LoadMapShapes(void);
	/*         class method */ static Classes::TStringList* __fastcall LoadStrings(TMetaClass* vmt, const AnsiString AName);
	/*         class method */ static unsigned __fastcall ResourceHandle(TMetaClass* vmt, const AnsiString AName);
	void __fastcall SetMap(const TWorldMap Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	/* virtual class method */ virtual void __fastcall CreateSubGallery(TMetaClass* vmt, Teengine::TChartSubGalleryProc AddSubChart);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	/* virtual class method */ virtual void __fastcall SetSubGallery(TMetaClass* vmt, Teengine::TChartSeries* ASeries, int Index);
	
public:
	__fastcall virtual TWorldSeries(Classes::TComponent* AOwner);
	/*         class method */ static void __fastcall AddCities(TMetaClass* vmt, Teengine::TChartSeries* DestSeries);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	DYNAMIC void __fastcall FillSampleValues(int NumValues = 0x0);
	/*         class method */ static void __fastcall LoadMapFromResource(TMetaClass* vmt, Teemapseries::TMapSeries* Series, const AnsiString ShpName, const AnsiString ShxName);
	
__published:
	__property TWorldMap Map = {read=FMap, write=SetMap, default=0};
	__property Shapes  = {stored=false};
public:
	#pragma option push -w-inl
	/* TMapSeries.Destroy */ inline __fastcall virtual ~TWorldSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWorldSeriesEditor;
class PASCALIMPLEMENTATION TWorldSeriesEditor : public Teemapseriesedit::TMapSeriesEditor 
{
	typedef Teemapseriesedit::TMapSeriesEditor inherited;
	
__published:
	Stdctrls::TLabel* Label7;
	Tecanvas::TComboFlat* CBMap;
	void __fastcall CBMapChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TWorldSeriesEditor(Classes::TComponent* AOwner) : Teemapseriesedit::TMapSeriesEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TWorldSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Teemapseriesedit::TMapSeriesEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TWorldSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TWorldSeriesEditor(HWND ParentWindow) : Teemapseriesedit::TMapSeriesEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeworldseries */
using namespace Teeworldseries;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeWorldSeries
