// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAnnToolEdit.pas' rev: 6.00

#ifndef TeeAnnToolEditHPP
#define TeeAnnToolEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeMargins.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeanntooledit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAnnotationToolEdit;
class PASCALIMPLEMENTATION TAnnotationToolEdit : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabText;
	Stdctrls::TLabel* Label1;
	Stdctrls::TMemo* MemoText;
	Comctrls::TTabSheet* TabPosition;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBPos;
	Stdctrls::TCheckBox* CBCustPos;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* ECustLeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TEdit* ECustTop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBTextAlign;
	Comctrls::TTabSheet* TabCallout;
	Teependlg::TButtonPen* BCalloutPen;
	Stdctrls::TButton* BCalloutPointer;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* EX;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* EY;
	Stdctrls::TLabel* Label8;
	Stdctrls::TEdit* EZ;
	Tecanvas::TComboFlat* CBCursor;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* Label10;
	Stdctrls::TEdit* EArrowDist;
	Comctrls::TUpDown* UDArrowDist;
	Stdctrls::TLabel* Label11;
	Tecanvas::TComboFlat* CBHead;
	Stdctrls::TLabel* Label12;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDHeadSize;
	Stdctrls::TLabel* Label13;
	Tecanvas::TComboFlat* CBUnits;
	Comctrls::TTabSheet* TabSize;
	Stdctrls::TLabel* Label14;
	Stdctrls::TLabel* Label15;
	Stdctrls::TEdit* ECustWidth;
	Stdctrls::TEdit* ECustHeight;
	Comctrls::TUpDown* UDWidth;
	Comctrls::TUpDown* UDHeight;
	Stdctrls::TCheckBox* CBAutoSize;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TCheckBox* CBClip;
	Stdctrls::TButton* Button1;
	Comctrls::TTabSheet* TabMargins;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EFormatChange(System::TObject* Sender);
	void __fastcall CBPosChange(System::TObject* Sender);
	void __fastcall ECustLeftChange(System::TObject* Sender);
	void __fastcall CBCustPosClick(System::TObject* Sender);
	void __fastcall ECustTopChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBTextAlignChange(System::TObject* Sender);
	void __fastcall BCalloutPointerClick(System::TObject* Sender);
	void __fastcall EXChange(System::TObject* Sender);
	void __fastcall EYChange(System::TObject* Sender);
	void __fastcall EZChange(System::TObject* Sender);
	void __fastcall CBCursorChange(System::TObject* Sender);
	void __fastcall EArrowDistChange(System::TObject* Sender);
	void __fastcall CBHeadChange(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall CBUnitsChange(System::TObject* Sender);
	void __fastcall CBAutoSizeClick(System::TObject* Sender);
	void __fastcall ECustWidthChange(System::TObject* Sender);
	void __fastcall ECustHeightChange(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall CBClipClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teecustomshapeeditor::TFormTeeShape* ShapeForm;
	Teemargins::TMarginsEditor* MarginsForm;
	bool __fastcall CanChangePos(void);
	bool __fastcall CanChangeSize(void);
	void __fastcall EnableCustomPosition(void);
	void __fastcall EnableCustomSize(void);
	
protected:
	Teetools::TAnnotationTool* Tool;
	
public:
	void __fastcall RefreshControls(Teetools::TAnnotationTool* ATool);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAnnotationToolEdit(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAnnotationToolEdit(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAnnotationToolEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAnnotationToolEdit(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeanntooledit */
using namespace Teeanntooledit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAnnToolEdit
