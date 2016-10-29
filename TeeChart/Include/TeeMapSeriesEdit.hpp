// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeMapSeriesEdit.pas' rev: 6.00

#ifndef TeeMapSeriesEditHPP
#define TeeMapSeriesEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <TeeChartGrid.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeMapSeries.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
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

namespace Teemapseriesedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMapSeriesEditor;
class PASCALIMPLEMENTATION TMapSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabGlobal;
	Stdctrls::TButton* BMapBrush;
	Comctrls::TTabSheet* TabShapes;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabFormat;
	Stdctrls::TCheckBox* CBGlobalPen;
	Stdctrls::TButton* BBrush;
	Stdctrls::TCheckBox* CBGlobalBrush;
	Teeedigrad::TButtonGradient* BGradient;
	Comctrls::TTabSheet* TabData;
	Extctrls::TSplitter* Splitter1;
	Teependlg::TButtonPen* ButtonPen1;
	Teependlg::TButtonPen* ButtonPen2;
	Extctrls::TPanel* Panel1;
	Tecanvas::TButtonColor* ButtonColor1;
	Teechartgrid::TChartGrid* ChartGrid1;
	Teechartgrid::TChartGridNavigator* ChartGridNavigator1;
	Teelisb::TChartListBox* ChartListBox1;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* SBDelete;
	Buttons::TSpeedButton* SBAdd;
	Stdctrls::TCheckBox* CBDefaultColor;
	Stdctrls::TCheckBox* CBClosed;
	Comctrls::TTabSheet* TabValues;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EText;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EditZ;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* ShapeIndex;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* ETransp;
	Comctrls::TUpDown* UDTransp;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDMapTransp;
	Stdctrls::TCheckBox* CBTransp;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* EPointSize;
	Comctrls::TUpDown* UDPointSize;
	Comctrls::TTabSheet* TabShadow;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BMapBrushClick(System::TObject* Sender);
	void __fastcall ETextChange(System::TObject* Sender);
	void __fastcall ChartListBox1Click(System::TObject* Sender);
	void __fastcall CBGlobalPenClick(System::TObject* Sender);
	void __fastcall CBGlobalBrushClick(System::TObject* Sender);
	void __fastcall BGradientClick(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	void __fastcall EditZChange(System::TObject* Sender);
	void __fastcall ButtonPen2Click(System::TObject* Sender);
	void __fastcall ButtonColor1Click(System::TObject* Sender);
	void __fastcall PageControl2Change(System::TObject* Sender);
	void __fastcall SBDeleteClick(System::TObject* Sender);
	void __fastcall SBAddClick(System::TObject* Sender);
	void __fastcall ChartGrid1SetEditText(System::TObject* Sender, int ACol, int ARow, const AnsiString Value);
	void __fastcall ChartListBox1ChangeColor(Teelisb::TChartListBox* Sender, Teengine::TCustomChartSeries* Series);
	void __fastcall CBDefaultColorClick(System::TObject* Sender);
	void __fastcall CBClosedClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall ETranspChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall ChartListBox1ChangeActive(Teelisb::TChartListBox* Sender, Teengine::TCustomChartSeries* Series);
	void __fastcall CBTranspClick(System::TObject* Sender);
	void __fastcall EPointSizeChange(System::TObject* Sender);
	
private:
	bool ChangingText;
	Forms::TCustomForm* Grid3DForm;
	void __fastcall CheckDefaultColor(void);
	void __fastcall EnableTabs(void);
	void __fastcall FillShapes(void);
	Teemapseries::TTeePolygon* __fastcall SelectedShape(void);
	
protected:
	Teemapseries::TMapSeries* Map;
	
public:
	System::TObject* InitialShape;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TMapSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TMapSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TMapSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMapSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teemapseriesedit */
using namespace Teemapseriesedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeMapSeriesEdit
