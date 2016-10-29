// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFiltersEditor.pas' rev: 6.00

#ifndef TeeFiltersEditorHPP
#define TeeFiltersEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeeDraw3D.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <CheckLst.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teefilterseditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormItem;
class PASCALIMPLEMENTATION TFormItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString PropName;
	Classes::TNotifyEvent OnChange;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TFormItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TFormItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFormItems;
class PASCALIMPLEMENTATION TFormItems : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TFormItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TFormItem* __fastcall Get(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property TFormItem* Items[int Index] = {read=Get/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TFormItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TFormItems(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TFormCreator;
class PASCALIMPLEMENTATION TFormCreator : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Controls::TWinControl* FParent;
	Classes::TNotifyEvent FOnChange;
	bool IChanging;
	int IPosY;
	TFormItem* __fastcall AddItem(const AnsiString PropName, Classes::TNotifyEvent AOnChange = 0x0);
	void __fastcall ChangeProp(System::TObject* Sender, const Variant &Value);
	void __fastcall CheckBoxChanged(System::TObject* Sender);
	void __fastcall ColorChanged(System::TObject* Sender);
	void __fastcall ComboChanged(System::TObject* Sender);
	void __fastcall EditChanged(System::TObject* Sender);
	void __fastcall ScrollChanged(System::TObject* Sender);
	
public:
	System::TObject* Instance;
	TFormItems* Items;
	__fastcall virtual TFormCreator(Classes::TComponent* AOwner);
	__fastcall virtual ~TFormCreator(void);
	Stdctrls::TCheckBox* __fastcall AddCheckBox(const AnsiString PropName, const AnsiString ACaption, Classes::TNotifyEvent OnChange = 0x0);
	Stdctrls::TButton* __fastcall AddColor(const AnsiString PropName, const AnsiString ACaption);
	Stdctrls::TComboBox* __fastcall AddCombo(const AnsiString PropName);
	Stdctrls::TEdit* __fastcall AddInteger(const AnsiString PropName, const AnsiString ACaption, int AMin, int AMax);
	Stdctrls::TScrollBar* __fastcall AddScroll(const AnsiString PropName, int AMin, int AMax);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
private:
	void *__IFormCreator;	/* Tecanvas::IFormCreator */
	
public:
	operator IFormCreator*(void) { return (IFormCreator*)&__IFormCreator; }
	
};


class DELPHICLASS TFiltersEditor;
class PASCALIMPLEMENTATION TFiltersEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* Panel1;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* BAdd;
	Buttons::TSpeedButton* BDelete;
	Buttons::TSpeedButton* BMoveUp;
	Buttons::TSpeedButton* BMoveDown;
	Checklst::TCheckListBox* Filters;
	Teedraw3d::TDraw3D* Image;
	Menus::TPopupMenu* MenuFilters;
	Menus::TPopupMenu* PopupMenu1;
	Menus::TMenuItem* Scaled1;
	Extctrls::TPanel* Panel3;
	Extctrls::TPanel* Panel4;
	Stdctrls::TButton* BOK;
	Stdctrls::TCheckBox* CBPreview;
	Stdctrls::TCheckBox* CBScaled;
	Comctrls::TPageControl* PageProps;
	Comctrls::TTabSheet* Properties;
	Comctrls::TTabSheet* TabRegion;
	Extctrls::TSplitter* Splitter2;
	Extctrls::TTimer* Timer1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* ELeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ETop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EWidth;
	Comctrls::TUpDown* UDWidth;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EHeight;
	Comctrls::TUpDown* UDHeight;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FiltersClick(System::TObject* Sender);
	void __fastcall BAddClick(System::TObject* Sender);
	void __fastcall FiltersClickCheck(System::TObject* Sender);
	void __fastcall BDeleteClick(System::TObject* Sender);
	void __fastcall BMoveUpClick(System::TObject* Sender);
	void __fastcall BMoveDownClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ImageResize(System::TObject* Sender);
	void __fastcall Scaled1Click(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBPreviewClick(System::TObject* Sender);
	void __fastcall CBScaledClick(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall ELeftChange(System::TObject* Sender);
	void __fastcall ETopChange(System::TObject* Sender);
	void __fastcall EWidthChange(System::TObject* Sender);
	void __fastcall EHeightChange(System::TObject* Sender);
	
private:
	Tecanvas::TFilterItems* Backup;
	TFormCreator* Creator;
	Graphics::TBitmap* IBitmap;
	bool IChanging;
	void __fastcall ClearProperties(void);
	void __fastcall ChangedProperties(System::TObject* Sender);
	int __fastcall CompareMenus(int a, int b);
	Tecanvas::TTeeFilter* __fastcall CurrentFilter(void);
	void __fastcall EnableButtons(void);
	void __fastcall FilterSelected(System::TObject* Sender);
	void __fastcall Preview(bool ReuseBitmap = false);
	void __fastcall Swap(int A, int B);
	void __fastcall SwapMenus(int a, int b);
	
public:
	Classes::TNotifyEvent Changed;
	Tecanvas::TFilterItems* FilterItems;
	Graphics::TGraphic* Picture;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFiltersEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFiltersEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFiltersEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFiltersEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ShowFiltersEditor(Classes::TComponent* AOwner, Graphics::TGraphic* APicture, Tecanvas::TFilterItems* AFilters)/* overload */;
extern PACKAGE bool __fastcall ShowFiltersEditor(Classes::TComponent* AOwner, Tecanvas::TTeePicture* APicture)/* overload */;

}	/* namespace Teefilterseditor */
using namespace Teefilterseditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFiltersEditor
