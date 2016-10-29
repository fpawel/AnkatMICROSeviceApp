// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeOrgSeries.pas' rev: 6.00

#ifndef TeeOrgSeriesHPP
#define TeeOrgSeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeMargins.hpp>	// Pascal unit
#include <TeeStringsEditor.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeComma.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeConst.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeorgseries
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOrgShape;
class PASCALIMPLEMENTATION TOrgShape : public Teetools::TTextShape 
{
	typedef Teetools::TTextShape inherited;
	
__published:
	__property CustomPosition  = {default=1};
	__property Left  = {stored=false};
	__property Top  = {stored=false};
	__property TextAlignment  = {default=2};
public:
	#pragma option push -w-inl
	/* TTextShape.Create */ inline __fastcall virtual TOrgShape(Teeprocs::TCustomTeePanel* AOwner)/* overload */ : Teetools::TTextShape(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTextShape.Destroy */ inline __fastcall virtual ~TOrgShape(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOrgItem;
class DELPHICLASS TOrgSeries;
class PASCALIMPLEMENTATION TOrgItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	TOrgShape* FFormat;
	int __fastcall GetSuperior(void);
	AnsiString __fastcall GetText();
	void __fastcall SetFormat(const TOrgShape* Value);
	void __fastcall SetSuperior(const int Value);
	void __fastcall SetText(const AnsiString Value);
	
public:
	__fastcall virtual TOrgItem(Classes::TCollection* Collection);
	__fastcall virtual ~TOrgItem(void);
	TOrgItem* __fastcall AddChild(const AnsiString Text);
	TOrgItem* __fastcall AddBrother(const AnsiString Text);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TOrgSeries* __fastcall Series(void);
	__property int Superior = {read=GetSuperior, write=SetSuperior, stored=false, nodefault};
	__property AnsiString Text = {read=GetText, write=SetText, stored=false};
	
__published:
	__property TOrgShape* Format = {read=FFormat, write=SetFormat};
};


class DELPHICLASS TOrgItemCollection;
class PASCALIMPLEMENTATION TOrgItemCollection : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TOrgItem* operator[](int Index) { return Items[Index]; }
	
private:
	TOrgItem* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TOrgItem* Value);
	
public:
	__property TOrgItem* Items[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TOrgItemCollection(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TOrgItemCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSpacing;
class PASCALIMPLEMENTATION TSpacing : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FVert;
	int FHoriz;
	Teengine::TChartSeries* ISeries;
	void __fastcall SetHoriz(const int Value);
	void __fastcall SetVert(const int Value);
	
public:
	__fastcall TSpacing(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property int Horizontal = {read=FHoriz, write=SetHoriz, default=8};
	__property int Vertical = {read=FVert, write=SetVert, default=16};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSpacing(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TOrgLineStyle { lsSquared, lsDiagonal };
#pragma option pop

class PASCALIMPLEMENTATION TOrgSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
public:
	TOrgItem* operator[](int Index) { return Item[Index]; }
	
private:
	TOrgShape* FDefault;
	TOrgLineStyle FLineStyle;
	TOrgItemCollection* FNodes;
	TSpacing* FSpacing;
	#pragma pack(push, 1)
	Types::TRect IBounds;
	#pragma pack(pop)
	
	void __fastcall AddNode(const AnsiString AText);
	void __fastcall GetChilds(Classes::TList* List, int Superior, bool VisibleOnly);
	TOrgItem* __fastcall GetItem(int Index);
	void __fastcall SetDefault(const TOrgShape* Value);
	void __fastcall SetItem(int Index, const TOrgItem* Value);
	void __fastcall SetLineStyle(const TOrgLineStyle Value);
	void __fastcall SetNodes(const TOrgItemCollection* Value);
	void __fastcall SetSpacing(const TSpacing* Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall ClearLists(void);
	virtual void __fastcall DrawAllValues(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TOrgSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TOrgSeries(void);
	HIDESBASE int __fastcall Add(const AnsiString Text, int Superior = 0xffffffff)/* overload */;
	virtual int __fastcall AddXY(const double AXValue, const double AYValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	virtual void __fastcall Delete(int ValueIndex)/* overload */;
	int __fastcall FirstChild(int ValueIndex);
	DYNAMIC bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	DYNAMIC void __fastcall SwapValueIndex(int a, int b);
	virtual bool __fastcall UseAxis(void);
	__property Types::TRect Bounds = {read=IBounds};
	__property TOrgItem* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
	
__published:
	__property Active  = {default=1};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=0};
	__property Title ;
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property XLabelsSource ;
	__property Brush ;
	__property Pen ;
	__property TOrgShape* Format = {read=FDefault, write=SetDefault};
	__property TOrgItemCollection* Items = {read=FNodes, write=SetNodes};
	__property TOrgLineStyle LineStyle = {read=FLineStyle, write=SetLineStyle, default=0};
	__property TSpacing* Spacing = {read=FSpacing, write=SetSpacing};
	__property XValues ;
	__property YValues ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnGetMarkText ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Add(const double AValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000)){ return TChartSeries::Add(AValue, ALabel, AColor); }
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	inline void __fastcall  Delete(int Start, int Quantity, bool RemoveGap = false){ TChartSeries::Delete(Start, Quantity, RemoveGap); }
	
};


class DELPHICLASS TOrgSeriesEditor;
class PASCALIMPLEMENTATION TOrgSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl2;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TScrollBar* ScrollBar1;
	Stdctrls::TScrollBar* ScrollBar2;
	Teependlg::TButtonPen* ButtonPen1;
	Extctrls::TPanel* Panel3;
	Stdctrls::TListBox* LBNodes;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabText;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label9;
	Stdctrls::TMemo* Memo1;
	Tecanvas::TComboFlat* ComboFlat1;
	Tecanvas::TComboFlat* CBCursor;
	Stdctrls::TButton* Button1;
	Extctrls::TSplitter* Splitter1;
	Buttons::TSpeedButton* SpeedButton1;
	Buttons::TSpeedButton* SpeedButton2;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBAutoSize;
	Stdctrls::TLabel* Label14;
	Stdctrls::TLabel* Label15;
	Stdctrls::TEdit* ECustWidth;
	Stdctrls::TEdit* ECustHeight;
	Comctrls::TUpDown* UDWidth;
	Comctrls::TUpDown* UDHeight;
	Stdctrls::TCheckBox* CBClip;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBLineStyle;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Comctrls::TTabSheet* TabMargins;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ScrollBar1Change(System::TObject* Sender);
	void __fastcall ScrollBar2Change(System::TObject* Sender);
	void __fastcall Memo1Change(System::TObject* Sender);
	void __fastcall ComboFlat1Change(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall LBNodesClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall SpeedButton2Click(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ECustWidthChange(System::TObject* Sender);
	void __fastcall ECustHeightChange(System::TObject* Sender);
	void __fastcall CBAutoSizeClick(System::TObject* Sender);
	void __fastcall CBClipClick(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall CBLineStyleChange(System::TObject* Sender);
	void __fastcall PageControl2Change(System::TObject* Sender);
	
private:
	TOrgSeries* Series;
	Teecustomshapeeditor::TFormTeeShape* NodeEditor;
	Teemargins::TMarginsEditor* MarginsForm;
	bool IChanging;
	void __fastcall AddListNodes(TOrgSeries* Series, int Current);
	int __fastcall CurrentIndex(void);
	TOrgItem* __fastcall CurrentItem(void);
	void __fastcall SetupEditor(TOrgSeries* ASeries);
	
public:
	void __fastcall RefreshNode(int Index);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TOrgSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TOrgSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TOrgSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TOrgSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeorgseries */
using namespace Teeorgseries;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeOrgSeries
