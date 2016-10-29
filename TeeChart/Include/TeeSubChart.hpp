// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSubChart.pas' rev: 6.00

#ifndef TeeSubChartHPP
#define TeeSubChartHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdit.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teesubchart
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSubChart;
class PASCALIMPLEMENTATION TSubChart : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Chart::TChart* FChart;
	Teengine::TTeeCustomTool* ITool;
	Types::TRect __fastcall GetBounds();
	Chart::TChart* __fastcall GetChart(void);
	int __fastcall GetHeight(void);
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	int __fastcall GetWidth(void);
	void __fastcall ReadChart(Classes::TStream* Stream);
	void __fastcall SetChart(const Chart::TChart* Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall WriteChart(Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
public:
	__fastcall virtual TSubChart(Classes::TCollection* Collection)/* overload */;
	__fastcall virtual ~TSubChart(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Types::TRect Bounds = {read=GetBounds};
	
__published:
	__property Chart::TChart* Chart = {read=GetChart, write=SetChart, stored=false};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
};


class DELPHICLASS TChartCollection;
class PASCALIMPLEMENTATION TChartCollection : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TSubChart* operator[](int Index) { return Items[Index]; }
	
private:
	TSubChart* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TSubChart* Value);
	
public:
	Chart::TChart* __fastcall AddChart(const AnsiString AName = "");
	__property TSubChart* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TChartCollection(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TChartCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSubChartTool;
class PASCALIMPLEMENTATION TSubChartTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	TChartCollection* FCharts;
	void __fastcall SetCharts(const TChartCollection* Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TSubChartTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TSubChartTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property TChartCollection* Charts = {read=FCharts, write=SetCharts};
};


class DELPHICLASS TSubChartEditor;
class PASCALIMPLEMENTATION TSubChartEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Stdctrls::TListBox* LBCharts;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabPosition;
	Comctrls::TTabSheet* TabChart;
	Stdctrls::TLabel* LLeft;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TLabel* LTop;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TLabel* LWidth;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDWidth;
	Stdctrls::TLabel* LHeight;
	Stdctrls::TEdit* Edit4;
	Comctrls::TUpDown* UDHeight;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* BUp;
	Buttons::TSpeedButton* BDown;
	Extctrls::TPanel* Panel3;
	Stdctrls::TButton* BAdd;
	Stdctrls::TButton* BDelete;
	Stdctrls::TButton* BRename;
	Extctrls::TPanel* Panel4;
	Extctrls::TPanel* Panel5;
	Stdctrls::TCheckBox* CBTransp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall LBChartsClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BAddClick(System::TObject* Sender);
	void __fastcall BDeleteClick(System::TObject* Sender);
	void __fastcall BUpClick(System::TObject* Sender);
	void __fastcall BDownClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall BRenameClick(System::TObject* Sender);
	void __fastcall CBTranspClick(System::TObject* Sender);
	
private:
	Teeedit::TChartEditorPanel* ChartEditor;
	TSubChartTool* Tool;
	TSubChart* __fastcall CurrentChart(void);
	AnsiString __fastcall CurrentChartName();
	void __fastcall EnableButtons(void);
	void __fastcall SwapChart(int A, int B);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSubChartEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSubChartEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSubChartEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSubChartEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesubchart */
using namespace Teesubchart;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSubChart
