// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGridBandToolEdit.pas' rev: 6.00

#ifndef TeeGridBandToolEditHPP
#define TeeGridBandToolEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeeDraw3D.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeAxisToolEdit.hpp>	// Pascal unit
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

namespace Teegridbandtooledit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGridBandToolEdit;
class PASCALIMPLEMENTATION TGridBandToolEdit : public Teeaxistooledit::TAxisToolEditor 
{
	typedef Teeaxistooledit::TAxisToolEditor inherited;
	
__published:
	Comctrls::TTabControl* TabControl1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TButton* BBand1;
	Teedraw3d::TDraw3D* Draw3D1;
	Tecanvas::TButtonColor* ButtonColor1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UpDown1;
	Teeedigrad::TButtonGradient* ButtonGradient1;
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BBand1Click(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Draw3D1AfterDraw(System::TObject* Sender);
	void __fastcall ButtonColor1Click(System::TObject* Sender);
	void __fastcall Draw3D1Click(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall TabControl1Change(System::TObject* Sender);
	void __fastcall ButtonGradient1Click(System::TObject* Sender);
	
private:
	Teetools::TGridBandTool* GridBand;
	Teetools::TGridBandBrush* __fastcall Band(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TGridBandToolEdit(Classes::TComponent* AOwner) : Teeaxistooledit::TAxisToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TGridBandToolEdit(Classes::TComponent* AOwner, int Dummy) : Teeaxistooledit::TAxisToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TGridBandToolEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGridBandToolEdit(HWND ParentWindow) : Teeaxistooledit::TAxisToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teegridbandtooledit */
using namespace Teegridbandtooledit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGridBandToolEdit
