// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePenDlg.pas' rev: 6.00

#ifndef TeePenDlgHPP
#define TeePenDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teependlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPenDialog;
class PASCALIMPLEMENTATION TPenDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TEdit* SEWidth;
	Stdctrls::TLabel* LWidth;
	Stdctrls::TButton* BOk;
	Stdctrls::TButton* BCancel;
	Comctrls::TUpDown* UDWidth;
	Stdctrls::TLabel* LStyle;
	Tecanvas::TComboFlat* CBStyle;
	Tecanvas::TButtonColor* BColor;
	Tecanvas::TComboFlat* CBEndStyle;
	Stdctrls::TLabel* LSpace;
	Stdctrls::TEdit* ESpace;
	Comctrls::TUpDown* UDSpace;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SEWidthChange(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall BCancelClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall CBStyleDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBEndStyleChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall ESpaceChange(System::TObject* Sender);
	
private:
	Tecanvas::TChartPen* BackupPen;
	bool ModifiedPen;
	void __fastcall EnablePenStyle(void);
	
public:
	Graphics::TPen* ThePen;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPenDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPenDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPenDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPenDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TButtonPen;
class PASCALIMPLEMENTATION TButtonPen : public Tecanvas::TTeeButton 
{
	typedef Tecanvas::TTeeButton inherited;
	
private:
	TPenDialog* FEditor;
	Classes::TNotifyEvent FOldDestroy;
	void __fastcall EditorDestroy(System::TObject* Sender);
	Tecanvas::TChartPen* __fastcall GetPen(void);
	TPenDialog* __fastcall GetEditor(void);
	
protected:
	virtual void __fastcall DrawSymbol(Tecanvas::TTeeCanvas* ACanvas);
	
public:
	bool HideColor;
	DYNAMIC void __fastcall Click(void);
	void __fastcall LinkPen(Tecanvas::TChartPen* APen);
	__property TPenDialog* Editor = {read=GetEditor};
	__property Tecanvas::TChartPen* Pen = {read=GetPen, write=LinkPen};
public:
	#pragma option push -w-inl
	/* TButton.Create */ inline __fastcall virtual TButtonPen(Classes::TComponent* AOwner) : Tecanvas::TTeeButton(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TButtonPen(HWND ParentWindow) : Tecanvas::TTeeButton(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TButtonPen(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define TeeFormBorderStyle (Forms::TFormBorderStyle)(0)
extern PACKAGE void __fastcall PositionToCenter(const Forms::TForm* Form);
extern PACKAGE Forms::TForm* __fastcall TeeCreateForm(TMetaClass* FormClass, Classes::TComponent* AOwner);
extern PACKAGE bool __fastcall EditChartPen(Classes::TComponent* AOwner, Tecanvas::TChartPen* ChartPen, bool HideColor = false);
extern PACKAGE void __fastcall ShowControls(bool Show, const Controls::TControl* * AControls, const int AControls_Size);
extern PACKAGE bool __fastcall TeeYesNo(const AnsiString Message, Controls::TControl* Owner = (Controls::TControl*)(0x0));
extern PACKAGE bool __fastcall TeeYesNoDelete(const AnsiString Message, Controls::TControl* Owner = (Controls::TControl*)(0x0));
extern PACKAGE void __fastcall AddFormTo(Forms::TForm* AForm, Controls::TWinControl* AParent)/* overload */;
extern PACKAGE void __fastcall AddFormTo(Forms::TForm* AForm, Controls::TWinControl* AParent, int ATag)/* overload */;
extern PACKAGE void __fastcall AddFormTo(Forms::TForm* AForm, Controls::TWinControl* AParent, Classes::TPersistent* ATag)/* overload */;
extern PACKAGE void __fastcall AddDefaultValueFormats(Classes::TStrings* AItems);
extern PACKAGE void __fastcall TeeLoadArrowBitmaps(Graphics::TBitmap* AUp, Graphics::TBitmap* ADown);
extern PACKAGE void __fastcall MoveList(Stdctrls::TCustomListBox* Source, Stdctrls::TCustomListBox* Dest);
extern PACKAGE void __fastcall MoveListAll(Classes::TStrings* Source, Classes::TStrings* Dest);
extern PACKAGE bool __fastcall TeeIdentToCursor(const AnsiString AName, int &ACursor);
extern PACKAGE Controls::TCursor __fastcall TeeSetCursor(Controls::TCursor ACursor, const AnsiString S);
extern PACKAGE bool __fastcall TeeCursorToIdent(int ACursor, AnsiString &AName);
extern PACKAGE void __fastcall TeeFillCursors(Tecanvas::TComboFlat* ACombo, Controls::TCursor ACursor);
extern PACKAGE void __fastcall TeePreviewCursor(Controls::TCursor ACursor, Graphics::TPicture* APicture);
extern PACKAGE void __fastcall TeeScaleForm(Forms::TForm* AForm);

}	/* namespace Teependlg */
using namespace Teependlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePenDlg
