// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeInspector.pas' rev: 6.00

#ifndef TeeInspectorHPP
#define TeeInspectorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeinspector
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TInspectorItemStyle { iiBoolean, iiString, iiSelection, iiColor, iiPen, iiGradient, iiBrush, iiFont, iiImage, iiButton, iiInteger, iiDouble };
#pragma option pop

typedef void __fastcall (__closure *TGetItemProc)(const AnsiString S, System::TObject* AObject = (System::TObject*)(0x0));

class DELPHICLASS TInspectorItem;
typedef void __fastcall (__closure *TGetInspectorItems)(TInspectorItem* Sender, TGetItemProc Proc);

typedef void __fastcall (__closure *TGetItemIndex)(TInspectorItem* Sender, int &Index);

typedef void __fastcall (__closure *TSetItemIndex)(TInspectorItem* Sender, int Index);

class DELPHICLASS TTeeInspector;
class PASCALIMPLEMENTATION TInspectorItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FCaption;
	System::TObject* FData;
	bool FEnabled;
	bool FExpanded;
	System::TObject* FOwner;
	TInspectorItemStyle FStyle;
	Variant FValue;
	bool FVisible;
	System::TObject* IData;
	TInspectorItem* IParent;
	Classes::TNotifyEvent FOnChange;
	TGetItemIndex FOnGetItemIndex;
	TGetInspectorItems FOnGetItems;
	TSetItemIndex FOnSetItemIndex;
	HIDESBASE void __fastcall Changed(void);
	void __fastcall RebuildInspector(void);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetValue(const Variant &Value);
	void __fastcall SetData(const System::TObject* Value);
	void __fastcall SetStyle(const TInspectorItemStyle Value);
	
protected:
	void __fastcall FillItems(Classes::TStrings* Items);
	virtual int __fastcall GetSelectedIndex(Classes::TStrings* Items);
	int __fastcall StyleToInt(void);
	
public:
	__fastcall virtual TInspectorItem(Classes::TCollection* Collection);
	TTeeInspector* __fastcall Inspector(void);
	__property System::TObject* Data = {read=FData, write=SetData};
	__property System::TObject* Owner = {read=FOwner, write=FOwner};
	__property TInspectorItem* Parent = {read=IParent, write=IParent};
	
__published:
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property bool Expanded = {read=FExpanded, write=FExpanded, nodefault};
	__property TInspectorItemStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Variant Value = {read=FValue, write=SetValue};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TGetItemIndex OnGetItemIndex = {read=FOnGetItemIndex, write=FOnGetItemIndex};
	__property TGetInspectorItems OnGetItems = {read=FOnGetItems, write=FOnGetItems};
	__property TSetItemIndex OnSetItemIndex = {read=FOnSetItemIndex, write=FOnSetItemIndex};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TInspectorItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInspectorItems;
class PASCALIMPLEMENTATION TInspectorItems : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TInspectorItem* operator[](int Index) { return Item[Index]; }
	
private:
	TInspectorItem* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TInspectorItem* Value);
	
protected:
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	TTeeInspector* Inspector;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, System::TObject* AData)/* overload */;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, System::TObject* AData, Classes::TNotifyEvent AOnChange)/* overload */;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, Classes::TNotifyEvent AOnChange)/* overload */;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, const Variant &InitialValue, Classes::TNotifyEvent AOnChange)/* overload */;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, const Variant &InitialValue)/* overload */;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, const Variant &InitialValue, System::TObject* AData, Classes::TNotifyEvent AOnChange)/* overload */;
	HIDESBASE TInspectorItem* __fastcall Add(TInspectorItemStyle AStyle, const AnsiString ACaption, const Variant &InitialValue, System::TObject* AData)/* overload */;
	__property TInspectorItem* Item[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TInspectorItems(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TInspectorItems(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComboFlatGrid;
class PASCALIMPLEMENTATION TComboFlatGrid : public Tecanvas::TComboFlat 
{
	typedef Tecanvas::TComboFlat inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMFocusChanged(Controls::TCMFocusChanged &Message);
public:
	#pragma option push -w-inl
	/* TComboFlat.Create */ inline __fastcall virtual TComboFlatGrid(Classes::TComponent* AOwner) : Tecanvas::TComboFlat(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomComboBox.Destroy */ inline __fastcall virtual ~TComboFlatGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TComboFlatGrid(HWND ParentWindow) : Tecanvas::TComboFlat(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TEditGrid;
class PASCALIMPLEMENTATION TEditGrid : public Stdctrls::TEdit 
{
	typedef Stdctrls::TEdit inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMFocusChanged(Controls::TCMFocusChanged &Message);
public:
	#pragma option push -w-inl
	/* TCustomEdit.Create */ inline __fastcall virtual TEditGrid(Classes::TComponent* AOwner) : Stdctrls::TEdit(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TEditGrid(HWND ParentWindow) : Stdctrls::TEdit(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TEditGrid(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInspectorHeader;
class PASCALIMPLEMENTATION TInspectorHeader : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Graphics::TFont* FFont;
	bool FVisible;
	void __fastcall CanvasChanged(System::TObject* Sender);
	void __fastcall SetFont(const Graphics::TFont* Value);
	void __fastcall SetVisible(const bool Value);
	
public:
	TTeeInspector* Inspector;
	__fastcall TInspectorHeader(void);
	__fastcall virtual ~TInspectorHeader(void);
	void __fastcall Update(void);
	
__published:
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


class PASCALIMPLEMENTATION TTeeInspector : public Grids::TStringGrid 
{
	typedef Grids::TStringGrid inherited;
	
private:
	TInspectorHeader* FHeader;
	TInspectorItems* FItems;
	Classes::TNotifyEvent FOnExpandCollapse;
	TComboFlatGrid* IComboGrid;
	TEditGrid* IEditGrid;
	bool __fastcall CanDrawEllipsi(int ARow);
	int __fastcall CellType(int ARow);
	int __fastcall ClickedCross(int X, int Y);
	void __fastcall ComboChange(System::TObject* Sender);
	void __fastcall ComboKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall CreateCombo(void);
	void __fastcall CreateEdit(void);
	void __fastcall DrawCross(const Types::TRect &R, bool Plus);
	void __fastcall EditChange(System::TObject* Sender);
	void __fastcall EditKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall ExpandCollapse(int ARow);
	void __fastcall HideCombos(void);
	void __fastcall InternalSetHeader(void);
	Types::TRect __fastcall ItemCrossRect(const Types::TRect &R);
	int __fastcall ItemOffset(int ARow);
	int __fastcall MinRow(void);
	void __fastcall SetComboIndex(void);
	void __fastcall SetHeader(const TInspectorHeader* Value);
	void __fastcall SetItems(const TInspectorItems* Value);
	bool __fastcall ValidRow(int ARow);
	
protected:
	void __fastcall AddComboItem(const AnsiString S, System::TObject* AObject);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	void __fastcall DoPositionCombos(bool WhenVisible);
	TInspectorItem* __fastcall Item(int ARow);
	virtual bool __fastcall ItemExpandable(int ARow);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	int __fastcall RecalcRowCount(void);
	DYNAMIC void __fastcall Resize(void);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	DYNAMIC void __fastcall TopLeftChanged(void);
	
public:
	__fastcall virtual TTeeInspector(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeeInspector(void);
	void __fastcall Clear(void);
	void __fastcall Rebuild(void);
	void __fastcall SetProperties(const Menus::TPopupMenu* AMenu);
	__property Classes::TNotifyEvent OnExpandCollapse = {read=FOnExpandCollapse, write=FOnExpandCollapse};
	
__published:
	__property TInspectorItems* Items = {read=FItems, write=SetItems};
	__property Color  = {default=-2147483633};
	__property ColCount  = {default=2};
	__property DefaultColWidth  = {default=82};
	__property DefaultRowHeight  = {default=19};
	__property FixedCols  = {default=0};
	__property GridLineWidth  = {default=0};
	__property RowCount  = {default=1};
	__property TInspectorHeader* Header = {read=FHeader, write=SetHeader};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeInspector(HWND ParentWindow) : Grids::TStringGrid(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeinspector */
using namespace Teeinspector;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeInspector
