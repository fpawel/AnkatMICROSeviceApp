// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeToolsGallery.pas' rev: 6.00

#ifndef TeeToolsGalleryHPP
#define TeeToolsGalleryHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teetoolsgallery
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeToolsGallery;
class PASCALIMPLEMENTATION TTeeToolsGallery : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* P1;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* BOk;
	Stdctrls::TButton* BCan;
	Comctrls::TTabControl* TabControl1;
	Stdctrls::TListBox* LBTool;
	Extctrls::TPanel* Panel2;
	Stdctrls::TMemo* MemoDesc;
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* PanelDemos;
	Extctrls::TSplitter* Splitter2;
	Stdctrls::TCheckBox* CBView3D;
	Stdctrls::TLabel* LabelClass;
	Extctrls::TPanel* Panel3;
	Extctrls::TPanel* Panel4;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall LBToolDblClick(System::TObject* Sender);
	void __fastcall LBToolDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall TabControl1Change(System::TObject* Sender);
	void __fastcall LBToolClick(System::TObject* Sender);
	
private:
	void __fastcall FillTools(void);
	TMetaClass* __fastcall ToolAtIndex(int AIndex);
	void __fastcall View3DClick(System::TObject* Sender);
	
public:
	TMetaClass* __fastcall SelectedTool(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeToolsGallery(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeToolsGallery(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeToolsGallery(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeToolsGallery(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


typedef void __fastcall (*TToolsGalleryHook)(TTeeToolsGallery* Gallery);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TToolsGalleryHook ToolsGalleryHook;
extern PACKAGE void __fastcall TeeDrawTool(Stdctrls::TListBox* AList, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State, Teengine::TTeeCustomTool* ATool);

}	/* namespace Teetoolsgallery */
using namespace Teetoolsgallery;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeToolsGallery
