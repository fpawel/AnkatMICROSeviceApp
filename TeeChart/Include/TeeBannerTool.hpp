// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBannerTool.pas' rev: 6.00

#ifndef TeeBannerToolHPP
#define TeeBannerToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeAnnToolEdit.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teebannertool
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollDirection { sdRightLeft, sdLeftRight };
#pragma option pop

class DELPHICLASS TBannerTool;
class PASCALIMPLEMENTATION TBannerTool : public Teetools::TAnnotationTool 
{
	typedef Teetools::TAnnotationTool inherited;
	
private:
	int FBlinkOff;
	int FBlinkOn;
	TScrollDirection FScrollDir;
	Extctrls::TTimer* IBlink;
	bool IDraw;
	Extctrls::TTimer* IScroll;
	int IXPos;
	void __fastcall DoBlink(System::TObject* Sender);
	void __fastcall DoScroll(System::TObject* Sender);
	bool __fastcall GetBlink(void);
	bool __fastcall GetScroll(void);
	int __fastcall GetScrollDelay(void);
	void __fastcall SetBlink(const bool Value);
	void __fastcall SetBlinkOff(const int Value);
	void __fastcall SetBlinkOn(const int Value);
	void __fastcall SetScroll(const bool Value);
	void __fastcall SetScrollDelay(const int Value);
	void __fastcall SetScrollDir(const TScrollDirection Value);
	
protected:
	virtual int __fastcall GetXOffset(void);
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TBannerTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TBannerTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property bool Blink = {read=GetBlink, write=SetBlink, default=0};
	__property int BlinkDelayOff = {read=FBlinkOff, write=SetBlinkOff, default=1000};
	__property int BlinkDelayOn = {read=FBlinkOn, write=SetBlinkOn, default=1000};
	__property int ScrollDelay = {read=GetScrollDelay, write=SetScrollDelay, default=50};
	__property TScrollDirection ScrollDirection = {read=FScrollDir, write=SetScrollDir, default=0};
	__property bool Scroll = {read=GetScroll, write=SetScroll, default=1};
};


class DELPHICLASS TBannerEditor;
class PASCALIMPLEMENTATION TBannerEditor : public Teeanntooledit::TAnnotationToolEdit 
{
	typedef Teeanntooledit::TAnnotationToolEdit inherited;
	
__published:
	Comctrls::TTabSheet* TabBanner;
	Stdctrls::TCheckBox* CBScroll;
	Stdctrls::TLabel* Label16;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDDelay;
	Stdctrls::TCheckBox* CBBlink;
	Stdctrls::TLabel* Label17;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDBlinkOn;
	Stdctrls::TLabel* Label18;
	Stdctrls::TEdit* Edit4;
	Comctrls::TUpDown* UDBlinkOff;
	Stdctrls::TLabel* Label19;
	Tecanvas::TComboFlat* CBDirection;
	void __fastcall CBScrollClick(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBBlinkClick(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall Edit4Change(System::TObject* Sender);
	void __fastcall CBDirectionChange(System::TObject* Sender);
	
private:
	TBannerTool* Banner;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBannerEditor(Classes::TComponent* AOwner) : Teeanntooledit::TAnnotationToolEdit(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBannerEditor(Classes::TComponent* AOwner, int Dummy) : Teeanntooledit::TAnnotationToolEdit(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBannerEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBannerEditor(HWND ParentWindow) : Teeanntooledit::TAnnotationToolEdit(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teebannertool */
using namespace Teebannertool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBannerTool
