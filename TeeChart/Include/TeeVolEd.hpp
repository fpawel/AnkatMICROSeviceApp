// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeVolEd.pas' rev: 6.00

#ifndef TeeVolEdHPP
#define TeeVolEdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <CandleCh.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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

namespace Teevoled
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TVolumeSeriesEditor;
class PASCALIMPLEMENTATION TVolumeSeriesEditor : public Teependlg::TPenDialog 
{
	typedef Teependlg::TPenDialog inherited;
	
__published:
	Stdctrls::TCheckBox* CBColorEach;
	Stdctrls::TCheckBox* CBUseOrigin;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EOrigin;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	HIDESBASE void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall CBUseOriginClick(System::TObject* Sender);
	void __fastcall EOriginChange(System::TObject* Sender);
	
private:
	Candlech::TVolumeSeries* TheSeries;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TVolumeSeriesEditor(Classes::TComponent* AOwner) : Teependlg::TPenDialog(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TVolumeSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Teependlg::TPenDialog(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TVolumeSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVolumeSeriesEditor(HWND ParentWindow) : Teependlg::TPenDialog(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teevoled */
using namespace Teevoled;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeVolEd
