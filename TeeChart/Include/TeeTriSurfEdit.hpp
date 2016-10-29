// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTriSurfEdit.pas' rev: 6.00

#ifndef TeeTriSurfEditHPP
#define TeeTriSurfEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTriSurface.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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

namespace Teetrisurfedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTriSurfaceSeriesEditor;
class PASCALIMPLEMENTATION TTriSurfaceSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* Button2;
	Stdctrls::TButton* Button3;
	Teependlg::TButtonPen* Button1;
	Stdctrls::TCheckBox* CBFastBrush;
	Stdctrls::TCheckBox* CBHide;
	Stdctrls::TEdit* ETransp;
	Comctrls::TUpDown* UDTransp;
	Stdctrls::TLabel* LHeight;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBFastBrushClick(System::TObject* Sender);
	void __fastcall CBHideClick(System::TObject* Sender);
	void __fastcall ETranspChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Teetrisurface::TTriSurfaceSeries* Surface;
	Forms::TCustomForm* Grid3DForm;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTriSurfaceSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTriSurfaceSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTriSurfaceSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTriSurfaceSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teetrisurfedit */
using namespace Teetrisurfedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTriSurfEdit
