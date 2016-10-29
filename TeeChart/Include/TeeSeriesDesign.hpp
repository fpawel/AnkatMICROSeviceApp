// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSeriesDesign.pas' rev: 6.00

#ifndef TeeSeriesDesignHPP
#define TeeSeriesDesignHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeChartReg.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProCo.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeLisB.hpp>	// Pascal unit
#include <ToolWnds.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
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

namespace Teeseriesdesign
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeDesignerList;
class PASCALIMPLEMENTATION TTeeDesignerList : public Designintf::TDesignerSelections 
{
	typedef Designintf::TDesignerSelections inherited;
	
public:
	#pragma option push -w-inl
	/* TDesignerSelections.Create */ inline __fastcall virtual TTeeDesignerList(void) : Designintf::TDesignerSelections() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignerSelections.Copy */ inline __fastcall TTeeDesignerList(const Designintf::_di_IDesignerSelections Selections) : Designintf::TDesignerSelections(Selections) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignerSelections.Destroy */ inline __fastcall virtual ~TTeeDesignerList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesEditor;
class PASCALIMPLEMENTATION TSeriesEditor : public Designwindows::TDesignWindow 
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Menus::TPopupMenu* LocalMenu;
	Menus::TMenuItem* AddItem;
	Menus::TMenuItem* DeleteItem;
	Menus::TMenuItem* SelectAllItem;
	Menus::TMenuItem* CloneItem;
	Menus::TMenuItem* Change1;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* Edit1;
	Menus::TMenuItem* Title1;
	Comctrls::TToolBar* ToolBar1;
	Comctrls::TToolButton* SBAdd;
	Comctrls::TToolButton* SBDelete;
	Comctrls::TToolButton* ToolButton3;
	Comctrls::TToolButton* TBMoveUp;
	Comctrls::TToolButton* TBMoveDown;
	Comctrls::TToolButton* ToolButton6;
	Comctrls::TToolButton* SBEdit;
	Controls::TImageList* ImageList1;
	Menus::TMenuItem* N2;
	Menus::TMenuItem* MoveUp1;
	Menus::TMenuItem* MoveDown1;
	Teelisb::TChartListBox* ChartListBox1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall AListBoxKeyPress(System::TObject* Sender, char &Key);
	void __fastcall SelectAllItemClick(System::TObject* Sender);
	void __fastcall LocalMenuPopup(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CloneItemClick(System::TObject* Sender);
	void __fastcall Change1Click(System::TObject* Sender);
	void __fastcall ChartListBox1Click(System::TObject* Sender);
	void __fastcall ChartListBox1DblClickSeries(Teelisb::TChartListBox* Sender, int Index);
	void __fastcall Title1Click(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SBAddClick(System::TObject* Sender);
	void __fastcall SBDeleteClick(System::TObject* Sender);
	void __fastcall SBEditClick(System::TObject* Sender);
	void __fastcall TBMoveUpClick(System::TObject* Sender);
	void __fastcall TBMoveDownClick(System::TObject* Sender);
	
private:
	Teechartreg::TTeeEditSeriesProc FEditSeriesProc;
	void __fastcall CheckChangedSeries(Classes::TPersistent* AItem);
	void __fastcall CheckDelete(void);
	void __fastcall EnableButtons(void);
	void __fastcall UpdateDisplay(void);
	void __fastcall UpdateCaption(void);
	void __fastcall UpdateSelection(void);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component);
	
public:
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem);
	virtual void __fastcall ItemInserted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem);
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TSeriesEditor(Classes::TComponent* AOwner) : Designwindows::TDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesEditor(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeShowSeriesEditor(Designintf::_di_IDesigner ADesigner, Teengine::TCustomSeriesList* AList, Teechartreg::TTeeEditSeriesProc EditSeriesProc, Teengine::TSeriesGroup* AGroup = (Teengine::TSeriesGroup*)(0x0));

}	/* namespace Teeseriesdesign */
using namespace Teeseriesdesign;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSeriesDesign
