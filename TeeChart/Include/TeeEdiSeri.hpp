// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiSeri.pas' rev: 6.00

#ifndef TeeEdiSeriHPP
#define TeeEdiSeriHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeMargins.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeeChartGrid.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teeediseri
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeSeries;
typedef void __fastcall (__closure *TNotifyTeeEvent)(TFormTeeSeries* Sender, Teeprocs::TTeeEvent* Event);

class PASCALIMPLEMENTATION TFormTeeSeries : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBPersistent;
	Comctrls::TPageControl* PageSeries;
	Comctrls::TTabSheet* TheTabSheet;
	Comctrls::TTabSheet* TabGeneral;
	Stdctrls::TGroupBox* GB5;
	Stdctrls::TLabel* L27;
	Stdctrls::TCheckBox* CBShowInLegend;
	Tecanvas::TComboFlat* CBCursor;
	Stdctrls::TGroupBox* GB2;
	Stdctrls::TLabel* L15;
	Stdctrls::TLabel* L21;
	Stdctrls::TEdit* EPercentFormat;
	Comctrls::TTabSheet* TabMarks;
	Comctrls::TTabSheet* TabDataSource;
	Stdctrls::TGroupBox* GBHorizAxis;
	Tecanvas::TComboFlat* CBHorizAxis;
	Stdctrls::TCheckBox* CBXDateTime;
	Stdctrls::TGroupBox* GBVertAxis;
	Tecanvas::TComboFlat* CBVertAxis;
	Stdctrls::TCheckBox* CBYDateTime;
	Comctrls::TPageControl* PageControlMarks;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TCheckBox* CBMarksVisible;
	Stdctrls::TCheckBox* CBMarkClip;
	Stdctrls::TLabel* L23;
	Stdctrls::TEdit* SEMarksAngle;
	Comctrls::TUpDown* UDMarksAngle;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EMarksEvery;
	Comctrls::TUpDown* UDEvery;
	Stdctrls::TCheckBox* CBMultiLine;
	Stdctrls::TLabel* LSort;
	Tecanvas::TComboFlat* CBSort;
	Tecanvas::TComboFlat* CBSeries;
	Extctrls::TImage* ImageSeries;
	Stdctrls::TLabel* LabelSeriesClass;
	Extctrls::TPanel* Panel1;
	Tecanvas::TComboFlat* CBFormat;
	Extctrls::TPanel* Panel2;
	Extctrls::TPanel* PanTop;
	Tecanvas::TComboFlat* CBDataSourcestyle;
	Stdctrls::TLabel* LDepth;
	Stdctrls::TEdit* EDepth;
	Comctrls::TUpDown* UDDepth;
	Stdctrls::TCheckBox* CBDepth;
	Stdctrls::TCheckBox* CBAllVisible;
	Extctrls::TPaintBox* PaintBox1;
	Extctrls::TPanel* Panel3;
	Tecanvas::TComboFlat* RGMarkStyle;
	Stdctrls::TLabel* Label1;
	Stdctrls::TButton* NewDataButton;
	Stdctrls::TButton* EditDataButton;
	Stdctrls::TButton* DeleteDataButton;
	Teechartgrid::TChartGrid* ChartGrid1;
	Teechartgrid::TChartGridNavigator* ChartGridNavigator1;
	Extctrls::TPanel* PanelRandomSource;
	Extctrls::TPanel* PanelSeriesSource;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ESamples;
	Stdctrls::TCheckBox* CBSamplesDefault;
	Stdctrls::TButton* BApplyRandom;
	Comctrls::TTabSheet* TabSheet2;
	Teependlg::TButtonPen* BMarkLinCol;
	Stdctrls::TLabel* L32;
	Stdctrls::TEdit* SEArrowLength;
	Comctrls::TUpDown* UDArrowsLength;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EArrowDist;
	Comctrls::TUpDown* UDArrowDist;
	Stdctrls::TButton* BCalloutPointer;
	Stdctrls::TLabel* Label11;
	Tecanvas::TComboFlat* CBHead;
	Stdctrls::TLabel* Label12;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDHeadSize;
	Extctrls::TTimer* Timer1;
	Comctrls::TTabSheet* TabSymbol;
	Stdctrls::TCheckBox* CBZDateTime;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button3;
	Stdctrls::TCheckBox* CBShowInEditor;
	Stdctrls::TLabel* Label5;
	Tecanvas::TComboFlat* CBSeriesSource;
	Stdctrls::TButton* BApplySource;
	Stdctrls::TButton* BClearSource;
	Stdctrls::TLabel* Label6;
	Tecanvas::TComboFlat* CBTextAlign;
	Comctrls::TTabSheet* TabMargins;
	Stdctrls::TCheckBox* CBFontSeriesColor;
	void __fastcall EPercentFormatChange(System::TObject* Sender);
	void __fastcall PageSeriesChange(System::TObject* Sender);
	void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall RGMarkStyleClick(System::TObject* Sender);
	void __fastcall CBPersistentClick(System::TObject* Sender);
	void __fastcall CBYDateTimeClick(System::TObject* Sender);
	void __fastcall CBXDateTimeClick(System::TObject* Sender);
	void __fastcall CBDataSourcestyleChange(System::TObject* Sender);
	void __fastcall CBShowInLegendClick(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	void __fastcall SEArrowLengthChange(System::TObject* Sender);
	void __fastcall CBMarkClipClick(System::TObject* Sender);
	void __fastcall CBMarksVisibleClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEMarksAngleChange(System::TObject* Sender);
	void __fastcall CBHorizAxisChange(System::TObject* Sender);
	void __fastcall CBVertAxisChange(System::TObject* Sender);
	void __fastcall EMarksEveryChange(System::TObject* Sender);
	void __fastcall CBMultiLineClick(System::TObject* Sender);
	void __fastcall CBSortChange(System::TObject* Sender);
	void __fastcall CBFormatChange(System::TObject* Sender);
	void __fastcall PageSeriesChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall CBDepthClick(System::TObject* Sender);
	void __fastcall EDepthChange(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall CBAllVisibleClick(System::TObject* Sender);
	void __fastcall PaintBox1Paint(System::TObject* Sender);
	void __fastcall PaintBox1Click(System::TObject* Sender);
	void __fastcall CBSamplesDefaultClick(System::TObject* Sender);
	void __fastcall ESamplesChange(System::TObject* Sender);
	void __fastcall BApplyRandomClick(System::TObject* Sender);
	void __fastcall EArrowDistChange(System::TObject* Sender);
	void __fastcall BCalloutPointerClick(System::TObject* Sender);
	void __fastcall CBHeadChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall ChartGrid1SetEditText(System::TObject* Sender, int ACol, int ARow, const AnsiString Value);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall CBZDateTimeClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall CBShowInEditorClick(System::TObject* Sender);
	void __fastcall CBSeriesSourceChange(System::TObject* Sender);
	void __fastcall BApplySourceClick(System::TObject* Sender);
	void __fastcall BClearSourceClick(System::TObject* Sender);
	void __fastcall PageControlMarksChange(System::TObject* Sender);
	void __fastcall CBTextAlignChange(System::TObject* Sender);
	void __fastcall CBFontSeriesColorClick(System::TObject* Sender);
	
private:
	Teengine::TCustomAxisPanel* TheChart;
	bool CreatingForm;
	bool ChangingPage;
	Teemargins::TMarginsEditor* IMarksMargins;
	Teecustomshapeeditor::TFormTeeShape* IMarksObject;
	Teecustomshapeeditor::TFormTeeShape* IMarksSymbol;
	Teengine::TChartSeries* LastSeries;
	TNotifyTeeEvent FOnTeeEvent;
	Forms::TForm* __fastcall AddToTab(Forms::TForm* AForm, Comctrls::TTabSheet* ATab, Classes::TPersistent* AObject);
	bool __fastcall AllSeriesMarksVisible(void);
	bool __fastcall CanModifySeries(void);
	bool __fastcall CheckCanClose(void);
	void __fastcall CheckCBSamples(void);
	void __fastcall DestroyDataSourceForm(void);
	void __fastcall EnableMultiLine(void);
	void __fastcall FillAxis(Classes::TStrings* Items, bool Horizontal);
	Teengine::TChartValueList* __fastcall FindZList(void);
	void __fastcall SetTabDataSource(void);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
protected:
	void __fastcall CreateDataSourceForm(void);
	
public:
	Teengine::TChartSeries* TheSeries;
	bool IsDssGraph;
	bool ShowTabDataSource;
	bool ShowTabGeneral;
	bool ShowTabMarks;
	Teesourceedit::TBaseSourceEditor* DataSourceStyle;
	Teelisb::TChartListBox* TheListBox;
	void __fastcall DestroySeriesForms(void);
	void __fastcall FillAxes(void);
	/*         class method */ static Forms::TCustomForm* __fastcall InsertSeriesForm(TMetaClass* vmt, Controls::TControl* AParent, TMetaClass* EditorClass, int Position, const AnsiString EditorTabName, Classes::TPersistent* AnObject);
	/*         class method */ static Teecustomshapeeditor::TFormTeeShape* __fastcall MarkSymbolsForm(TMetaClass* vmt, Classes::TComponent* AOwner, Teengine::TSeriesMarksSymbol* Symbol, Controls::TWinControl* AParent = (Controls::TWinControl*)(0x0));
	void __fastcall SetCBSeries(void);
	__property TNotifyTeeEvent OnTeeEvent = {read=FOnTeeEvent, write=FOnTeeEvent};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeSeries(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeSeries(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeSeries(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeSeries(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


typedef void __fastcall (*TOnCreateEditSeries)(TFormTeeSeries* Sender, Chart::TCustomChart* AChart);

typedef void __fastcall (__closure *TOnCreateEditSeriesObj)(TFormTeeSeries* Sender, Chart::TCustomChart* AChart);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TOnCreateEditSeries InternalOnCreateEditSeries;
extern PACKAGE TOnCreateEditSeriesObj InternalOnCreateEditSeriesObj;
extern PACKAGE void __fastcall EditSeriesDialog(Classes::TComponent* AOwner, Teengine::TChartSeries* ASeries);
extern PACKAGE TMetaClass* __fastcall SeriesEditorForm(Teengine::TChartSeries* Series);

}	/* namespace Teeediseri */
using namespace Teeediseri;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiSeri
