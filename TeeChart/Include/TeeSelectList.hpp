// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSelectList.pas' rev: 6.00

#ifndef TeeSelectListHPP
#define TeeSelectListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeselectlist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSelectListForm;
class PASCALIMPLEMENTATION TSelectListForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TListBox* FromList;
	Stdctrls::TListBox* ToList;
	Extctrls::TPanel* Panel1;
	Buttons::TSpeedButton* BMoveUP;
	Buttons::TSpeedButton* BMoveDown;
	Extctrls::TPanel* Panel2;
	Stdctrls::TLabel* L22;
	Stdctrls::TLabel* L24;
	Extctrls::TPanel* Panel3;
	Stdctrls::TButton* BRightOne;
	Stdctrls::TButton* BRightAll;
	Stdctrls::TButton* BLeftOne;
	Stdctrls::TButton* BLeftAll;
	Extctrls::TSplitter* Splitter1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BMoveUPClick(System::TObject* Sender);
	void __fastcall ToListDblClick(System::TObject* Sender);
	void __fastcall FromListDblClick(System::TObject* Sender);
	void __fastcall BLeftAllClick(System::TObject* Sender);
	void __fastcall BRightAllClick(System::TObject* Sender);
	void __fastcall BLeftOneClick(System::TObject* Sender);
	void __fastcall BRightOneClick(System::TObject* Sender);
	void __fastcall ToListClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	HIDESBASE void __fastcall Changed(void);
	
public:
	Classes::TNotifyEvent OnChange;
	void __fastcall EnableButtons(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSelectListForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSelectListForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSelectListForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSelectListForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeselectlist */
using namespace Teeselectlist;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSelectList
