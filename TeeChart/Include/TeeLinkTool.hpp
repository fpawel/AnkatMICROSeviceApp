// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLinkTool.pas' rev: 6.00

#ifndef TeeLinkToolHPP
#define TeeLinkToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeAnnToolEdit.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
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

namespace Teelinktool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLinkTool;
class PASCALIMPLEMENTATION TLinkTool : public Teetools::TAnnotationTool 
{
	typedef Teetools::TAnnotationTool inherited;
	
private:
	AnsiString FHint;
	AnsiString FURL;
	AnsiString IOldHint;
	void __fastcall SetHint(const AnsiString Value);
	void __fastcall SetURL(const AnsiString Value);
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DrawText(void)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TLinkTool(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Cursor  = {default=-21};
	__property AnsiString Hint = {read=FHint, write=SetHint};
	__property AnsiString URL = {read=FURL, write=SetURL};
public:
	#pragma option push -w-inl
	/* TAnnotationTool.Destroy */ inline __fastcall virtual ~TLinkTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLinkToolEditor;
class PASCALIMPLEMENTATION TLinkToolEditor : public Teeanntooledit::TAnnotationToolEdit 
{
	typedef Teeanntooledit::TAnnotationToolEdit inherited;
	
__published:
	Comctrls::TTabSheet* TabLink;
	Stdctrls::TLabel* Label16;
	Stdctrls::TEdit* EURL;
	Stdctrls::TLabel* Label17;
	Stdctrls::TEdit* EHint;
	Stdctrls::TLabel* Label18;
	Stdctrls::TEdit* EText;
	Extctrls::TTimer* Timer1;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EURLChange(System::TObject* Sender);
	void __fastcall EHintChange(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall ETextChange(System::TObject* Sender);
	
private:
	TLinkTool* Link;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLinkToolEditor(Classes::TComponent* AOwner) : Teeanntooledit::TAnnotationToolEdit(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLinkToolEditor(Classes::TComponent* AOwner, int Dummy) : Teeanntooledit::TAnnotationToolEdit(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLinkToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLinkToolEditor(HWND ParentWindow) : Teeanntooledit::TAnnotationToolEdit(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teelinktool */
using namespace Teelinktool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLinkTool
