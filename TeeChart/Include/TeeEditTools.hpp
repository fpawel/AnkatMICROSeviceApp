// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEditTools.pas' rev: 6.00

#ifndef TeeEditToolsHPP
#define TeeEditToolsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Teeedittools
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeTools;
class PASCALIMPLEMENTATION TFormTeeTools : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TListBox* LBTools;
	Extctrls::TPanel* PanelToolEditor;
	Extctrls::TPanel* PTop;
	Stdctrls::TButton* BAdd;
	Stdctrls::TButton* BDelete;
	Stdctrls::TCheckBox* CBActive;
	Extctrls::TPanel* PBottom;
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* BMoveUp;
	Buttons::TSpeedButton* BMoveDown;
	Stdctrls::TCheckBox* CBShowInEditor;
	Buttons::TSpeedButton* BClone;
	Menus::TPopupMenu* PopupMenu1;
	void __fastcall LBToolsClick(System::TObject* Sender);
	void __fastcall BDeleteClick(System::TObject* Sender);
	void __fastcall CBActiveClick(System::TObject* Sender);
	void __fastcall BAddClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BMoveUpClick(System::TObject* Sender);
	void __fastcall BMoveDownClick(System::TObject* Sender);
	void __fastcall LBToolsDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall CBShowInEditorClick(System::TObject* Sender);
	void __fastcall BCloneClick(System::TObject* Sender);
	
private:
	Teengine::TTeeCustomTool* __fastcall CurrentTool(void);
	void __fastcall DeleteForm(void);
	void __fastcall EnableButtons(void);
	void __fastcall FillAndSet(void);
	void __fastcall FillTools(void);
	void __fastcall SwapTool(int A, int B);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	
protected:
	Classes::TNotifyEvent OnAdded;
	Classes::TNotifyEvent OnDeleted;
	virtual Teengine::TTeeCustomTool* __fastcall CloneTool(Teengine::TTeeCustomTool* Tool);
	virtual Teengine::TTeeCustomTool* __fastcall GetNewTool(void);
	
public:
	Teengine::TChartTools* Tools;
	void __fastcall Reload(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeTools(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeTools(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeTools(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeTools(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeedittools */
using namespace Teeedittools;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEditTools
