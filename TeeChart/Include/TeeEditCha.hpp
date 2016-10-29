// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEditCha.pas' rev: 6.00

#ifndef TeeEditChaHPP
#define TeeEditChaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeNavigator.hpp>	// Pascal unit
#include <TeePrevi.hpp>	// Pascal unit
#include <TeeChartGrid.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <TeeEdiSeri.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <CheckLst.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Teeeditcha
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TChartEditorOption { ceAdd, ceDelete, ceChange, ceClone, ceDataSource, ceTitle, ceHelp, ceGroups, ceGroupAll, ceOrderSeries, ceAskDelete };
#pragma option pop

#pragma option push -b-
enum TChartEditorTab { cetMain, cetGeneral, cetAxis, cetTitles, cetLegend, cetPanel, cetPaging, cetWalls, cet3D, cetSeriesGeneral, cetSeriesMarks, cetAllSeries, cetSeriesData, cetExport, cetExportNative, cetTools, cetPrintPreview };
#pragma option pop

typedef Set<TChartEditorOption, ceAdd, ceAskDelete>  TChartEditorOptions;

typedef Set<TChartEditorTab, cetMain, cetPrintPreview>  TChartEditorHiddenTabs;

class DELPHICLASS TChartEditForm;
class PASCALIMPLEMENTATION TChartEditForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* MainPage;
	Comctrls::TTabSheet* TabChart;
	Comctrls::TPageControl* SubPage;
	Comctrls::TTabSheet* TabSeriesList;
	Comctrls::TTabSheet* TabAxis;
	Comctrls::TTabSheet* TabGeneral;
	Comctrls::TTabSheet* TabTitle;
	Comctrls::TTabSheet* TabLegend;
	Comctrls::TTabSheet* TabPanel;
	Comctrls::TTabSheet* TabPaging;
	Comctrls::TTabSheet* TabWalls;
	Comctrls::TTabSheet* TabSeries;
	Comctrls::TTabSheet* Tab3D;
	Comctrls::TTabSheet* TabData;
	Comctrls::TTabSheet* TabExport;
	Extctrls::TPanel* PanBottom;
	Stdctrls::TLabel* LabelWWW;
	Stdctrls::TButton* ButtonHelp;
	Comctrls::TTabSheet* TabTools;
	Comctrls::TTabSheet* TabPrint;
	Extctrls::TPanel* PanRight;
	Buttons::TSpeedButton* BMoveUP;
	Buttons::TSpeedButton* BMoveDown;
	Stdctrls::TButton* BAddSeries;
	Stdctrls::TButton* BDeleteSeries;
	Stdctrls::TButton* BRenameSeries;
	Stdctrls::TButton* BCloneSeries;
	Stdctrls::TButton* BChangeTypeSeries;
	Extctrls::TPanel* PanTop;
	Extctrls::TPanel* PanBot;
	Extctrls::TPanel* PanLeft;
	Extctrls::TPanel* PanClose;
	Stdctrls::TButton* BClose;
	Teechartgrid::TChartGrid* ChartGrid1;
	Extctrls::TPanel* Panel1;
	Teechartgrid::TChartGridNavigator* ChartGridNavigator1;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* SBGridText;
	Buttons::TSpeedButton* SBGridCol;
	Buttons::TSpeedButton* SBGrid3D;
	Buttons::TSpeedButton* SBGridX;
	Menus::TPopupMenu* PopupData;
	Menus::TMenuItem* Deleterow1;
	Checklst::TCheckListBox* Groups;
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* PanelGroups;
	Buttons::TSpeedButton* BAddGroup;
	Buttons::TSpeedButton* BDeleteGroup;
	Buttons::TSpeedButton* BRenameGroup;
	Comctrls::TTreeView* Tree;
	Extctrls::TSplitter* TreeSplitter;
	Menus::TMenuItem* Insertrow1;
	Teelisb::TChartListBox* LBSeries;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* EditColor1;
	Menus::TMenuItem* DefaultColor1;
	Menus::TMenuItem* Makenullpoint1;
	Menus::TMenuItem* N2;
	Menus::TMenuItem* extfont1;
	Buttons::TSpeedButton* SBCopyData;
	Menus::TPopupMenu* PopupSeries;
	Menus::TMenuItem* ViewSeriesNames1;
	Menus::TMenuItem* ViewSeriesGroups1;
	Buttons::TSpeedButton* SpeedSeries;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall SubPageChange(System::TObject* Sender);
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall BMoveUPClick(System::TObject* Sender);
	void __fastcall BMoveDownClick(System::TObject* Sender);
	void __fastcall BAddSeriesClick(System::TObject* Sender);
	void __fastcall BDeleteSeriesClick(System::TObject* Sender);
	void __fastcall BRenameSeriesClick(System::TObject* Sender);
	void __fastcall BCloneSeriesClick(System::TObject* Sender);
	void __fastcall MainPageChange(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall LBSeriesEditSeries(Teelisb::TChartListBox* Sender, int Index);
	void __fastcall LBSeriesOtherItemsChange(System::TObject* Sender);
	void __fastcall LBSeriesRefreshButtons(System::TObject* Sender);
	void __fastcall BChangeTypeSeriesClick(System::TObject* Sender);
	void __fastcall LabelWWWClick(System::TObject* Sender);
	void __fastcall ButtonHelpClick(System::TObject* Sender);
	void __fastcall MainPageChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall SubPageChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall SBGridTextClick(System::TObject* Sender);
	void __fastcall SBGridColClick(System::TObject* Sender);
	void __fastcall SBGrid3DClick(System::TObject* Sender);
	void __fastcall SBGridXClick(System::TObject* Sender);
	void __fastcall Deleterow1Click(System::TObject* Sender);
	void __fastcall GroupsClick(System::TObject* Sender);
	void __fastcall GroupsClickCheck(System::TObject* Sender);
	void __fastcall LBSeriesChangeActive(Teelisb::TChartListBox* Sender, Teengine::TCustomChartSeries* Series);
	void __fastcall GroupsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall GroupsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall BAddGroupClick(System::TObject* Sender);
	void __fastcall BRenameGroupClick(System::TObject* Sender);
	void __fastcall BDeleteGroupClick(System::TObject* Sender);
	void __fastcall TreeChange(System::TObject* Sender, Comctrls::TTreeNode* Node);
	void __fastcall TreeEditing(System::TObject* Sender, Comctrls::TTreeNode* Node, bool &AllowEdit);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall Insertrow1Click(System::TObject* Sender);
	void __fastcall CBNamesClick(System::TObject* Sender);
	void __fastcall PopupDataPopup(System::TObject* Sender);
	void __fastcall EditColor1Click(System::TObject* Sender);
	void __fastcall DefaultColor1Click(System::TObject* Sender);
	void __fastcall Makenullpoint1Click(System::TObject* Sender);
	void __fastcall extfont1Click(System::TObject* Sender);
	void __fastcall SBCopyDataClick(System::TObject* Sender);
	void __fastcall ViewSeriesNames1Click(System::TObject* Sender);
	void __fastcall SpeedSeriesMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ViewSeriesGroups1Click(System::TObject* Sender);
	void __fastcall LBSeriesRemovedSeries(Teelisb::TChartListBox* Sender, Teengine::TCustomChartSeries* Series);
	
private:
	int OldWidth;
	Chart::TCustomChart* TheChart;
	Teeprevi::TChartPreview* FPreview;
	Teesourceedit::TBaseSourceEditor* SourceEditor;
	Extctrls::TPanel* TreePanel;
	Comctrls::TTreeNode* TreeNodeSeries;
	Comctrls::TTreeNode* TreeNodeTools;
	void __fastcall AddedTool(System::TObject* Sender);
	void __fastcall DeletedTool(System::TObject* Sender);
	void __fastcall CreateToolsForm(void);
	void __fastcall AddSeriesNodes(void);
	void __fastcall AxisNotifyCustom(System::TObject* Sender);
	void __fastcall BroadCastShowEditor(Comctrls::TTabSheet* Tab);
	Teengine::TSeriesGroup* __fastcall CurrentGroup(void);
	int __fastcall DeltaGroup(void);
	void __fastcall EnableGroupButtons(void);
	void __fastcall FillGroups(void);
	void __fastcall FormSeriesEvent(Teeediseri::TFormTeeSeries* Sender, Teeprocs::TTeeEvent* Event);
	void __fastcall GridMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall InternalSetupFormSeries(void);
	void __fastcall PrepareTree(void);
	void __fastcall ReparentAxis(void);
	void __fastcall ReparentTitle(void);
	void __fastcall ReparentTools(void);
	void __fastcall ResetParentTab(Comctrls::TPageControl* PageControl);
	void __fastcall SelectTreeNodeData(System::TObject* AObject);
	void __fastcall SetChart(Chart::TCustomChart* Value);
	void __fastcall ShowHideGroups(void);
	Comctrls::TTreeNode* __fastcall TreeNodeCurrentSeries(void);
	void __fastcall TreeSelectSeries(Teengine::TChartSeries* Series);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	HIDESBASE MESSAGE void __fastcall WMHelp(Messages::TWMHelp &Message);
	
public:
	Teengine::TChartAxis* TheAxis;
	Chart::TChartTitle* TheTitle;
	Teengine::TTeeCustomTool* TheTool;
	Chart::TCustomChartWall* TheWall;
	Teengine::TChartSeries* TheSeries;
	Teengine::TChartSeries* TheEditSeries;
	int TheActivePageIndex;
	TChartEditorHiddenTabs TheHiddenTabs;
	TChartEditorOptions EditorOptions;
	bool IsDssGraph;
	Teeediseri::TFormTeeSeries* TheFormSeries;
	bool HighLightTabs;
	bool RememberPosition;
	bool RememberSize;
	void __fastcall CheckHelpFile(void);
	void __fastcall SetTabSeries(void);
	__property Chart::TCustomChart* Chart = {read=TheChart, write=SetChart};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TChartEditForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TChartEditForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TChartEditForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartEditForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef void __fastcall (*TTeeOnCreateEditor)(TChartEditForm* Editor, Comctrls::TTabSheet* Tab);

//-- var, const, procedure ---------------------------------------------------
static const Shortint teeEditMainPage = 0x0;
static const Shortint teeEditGeneralPage = 0x1;
static const Shortint teeEditAxisPage = 0x2;
static const Shortint teeEditTitlePage = 0x3;
static const Shortint teeEditLegendPage = 0x4;
static const Shortint teeEditPanelPage = 0x5;
static const Shortint teeEditPagingPage = 0x6;
static const Shortint teeEditWallsPage = 0x7;
static const Shortint teeEdit3DPage = 0x8;
#define eoAll (System::Set<TChartEditorOption, ceAdd, ceAskDelete> () << TChartEditorOption(0) << TChartEditorOption(1) << TChartEditorOption(2) << TChartEditorOption(3) << TChartEditorOption(4) << TChartEditorOption(5) << TChartEditorOption(6) << TChartEditorOption(8) << TChartEditorOption(9) << TChartEditorOption(10) )
extern PACKAGE Classes::TList* TeeOnShowEditor;
extern PACKAGE bool TeeSeriesNamesRuntime;
#define TeeMsg_RememberPosition "RememberPosition"
#define TeeMsg_RememberSize "RememberSize"
#define TeeMsg_TreeMode "TreeMode"
#define TeeMsg_TreeWidth "TreeWidth"
#define TeeMsg_DefaultTheme "DefaultTheme"
#define TeeMsg_DefaultPalette "DefaultPalette"
#define TeeMsg_SeriesGroups "SeriesGroups"
extern PACKAGE AnsiString __fastcall GetTeeChartHelpFile();

}	/* namespace Teeeditcha */
using namespace Teeeditcha;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEditCha
