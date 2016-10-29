// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePageNumTool.pas' rev: 6.00

#ifndef TeePageNumToolHPP
#define TeePageNumToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeAnnToolEdit.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepagenumtool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPageNumTool;
class PASCALIMPLEMENTATION TPageNumTool : public Teetools::TAnnotationTool 
{
	typedef Teetools::TAnnotationTool inherited;
	
private:
	Tecanvas::TChartPen* FButtonPen;
	bool FButtons;
	int FButtonWidth;
	Tecanvas::TTeeGradient* FDisabledButton;
	Tecanvas::TTeeGradient* FEnabledButton;
	AnsiString FFormat;
	bool __fastcall IsFormatStored(void);
	void __fastcall LeftTriangle(/* out */ Types::TPoint * Value);
	void __fastcall RightTriangle(/* out */ Types::TPoint * Value);
	void __fastcall SetButtons(bool Value);
	void __fastcall SetButtonWidth(int Value);
	void __fastcall SetDisabledButton(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetEnabledButton(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetFormat(const AnsiString Value);
	void __fastcall SetButtonPen(const Tecanvas::TChartPen* Value);
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DrawText(void)/* overload */;
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual AnsiString __fastcall GetText();
	virtual Types::TRect __fastcall GetTextBounds(/* out */ int &NumLines, /* out */ int &x, /* out */ int &y)/* overload */;
	virtual int __fastcall GetXOffset(void);
	
public:
	__fastcall virtual TPageNumTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TPageNumTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Tecanvas::TChartPen* ButtonPen = {read=FButtonPen, write=SetButtonPen};
	__property int ButtonWidth = {read=FButtonWidth, write=SetButtonWidth, default=12};
	__property Tecanvas::TTeeGradient* DisabledButton = {read=FDisabledButton, write=SetDisabledButton};
	__property Tecanvas::TTeeGradient* EnabledButton = {read=FEnabledButton, write=SetEnabledButton};
	__property AnsiString Format = {read=FFormat, write=SetFormat, stored=IsFormatStored};
	__property bool ShowButtons = {read=FButtons, write=SetButtons, default=1};
	
/* Hoisted overloads: */
	
protected:
	inline Types::TRect __fastcall  GetTextBounds(Teengine::TCustomAxisPanel* Panel, /* out */ int &NumLines, /* out */ int &x, /* out */ int &y){ return TAnnotationTool::GetTextBounds(Panel, NumLines, x, y); }
	inline Types::TRect __fastcall  GetTextBounds(Teengine::TCustomAxisPanel* Panel, const Types::TRect &ABounds, /* out */ int &NumLines, /* out */ int &x, /* out */ int &y){ return TAnnotationTool::GetTextBounds(Panel, ABounds, NumLines, x, y); }
	
};


class DELPHICLASS TPageNumToolEdit;
class PASCALIMPLEMENTATION TPageNumToolEdit : public Teeanntooledit::TAnnotationToolEdit 
{
	typedef Teeanntooledit::TAnnotationToolEdit inherited;
	
__published:
	Comctrls::TTabSheet* TagPaging;
	Stdctrls::TCheckBox* CBButtons;
	Stdctrls::TLabel* Label16;
	Stdctrls::TEdit* EWidth;
	Comctrls::TUpDown* UDButtonWidth;
	Teeedigrad::TButtonGradient* BEnabled;
	Teeedigrad::TButtonGradient* BDisabled;
	Teependlg::TButtonPen* BBorder;
	Extctrls::TTimer* Timer1;
	void __fastcall EWidthChange(System::TObject* Sender);
	void __fastcall CBButtonsClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPageNumToolEdit(Classes::TComponent* AOwner) : Teeanntooledit::TAnnotationToolEdit(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPageNumToolEdit(Classes::TComponent* AOwner, int Dummy) : Teeanntooledit::TAnnotationToolEdit(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPageNumToolEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPageNumToolEdit(HWND ParentWindow) : Teeanntooledit::TAnnotationToolEdit(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepagenumtool */
using namespace Teepagenumtool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePageNumTool
