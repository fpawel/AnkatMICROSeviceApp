// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCustomShapeEditor.pas' rev: 6.00

#ifndef TeeCustomShapeEditorHPP
#define TeeCustomShapeEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBackImage.hpp>	// Pascal unit
#include <TeeShadowEditor.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teecustomshapeeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeShape;
class PASCALIMPLEMENTATION TFormTeeShape : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PC1;
	Comctrls::TTabSheet* TabFormat;
	Tecanvas::TButtonColor* BBackColor;
	Stdctrls::TButton* Button6;
	Stdctrls::TCheckBox* CBTransparent;
	Comctrls::TTabSheet* TabGradient;
	Comctrls::TTabSheet* TabText;
	Comctrls::TTabSheet* TabShadow;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EShadowTransp;
	Comctrls::TUpDown* UDShadowTransp;
	Comctrls::TTabSheet* TabImage;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBBevel;
	Stdctrls::TEdit* EBevWidth;
	Comctrls::TUpDown* UDBevW;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* CBRound;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* ERoundSize;
	Comctrls::TUpDown* UDRoundSize;
	Teependlg::TButtonPen* Button4;
	void __fastcall BColorClick(System::TObject* Sender);
	void __fastcall CBRoundClick(System::TObject* Sender);
	void __fastcall BBrushClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBTransparentClick(System::TObject* Sender);
	void __fastcall CBBevelChange(System::TObject* Sender);
	void __fastcall EBevWidthChange(System::TObject* Sender);
	void __fastcall EShadowTranspChange(System::TObject* Sender);
	void __fastcall CBVisibleChecked(System::TObject* Sender);
	void __fastcall ERoundSizeChange(System::TObject* Sender);
	void __fastcall PC1Change(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teeedifont::TTeeFontEditor* FFontEditor;
	Teeedigrad::TTeeGradientEditor* FGradientEditor;
	Teebackimage::TBackImageEditor* FImageEditor;
	Teeshadoweditor::TTeeShadowEditor* FShadowEditor;
	void __fastcall EnableBevel(void);
	
public:
	Teeprocs::TTeeCustomShape* TheShape;
	__fastcall virtual TFormTeeShape(Classes::TComponent* AOwner);
	/*         class method */ static TFormTeeShape* __fastcall CreateForm(TMetaClass* vmt, Classes::TComponent* AOwner, Teeprocs::TTeeCustomShape* AShape, Controls::TWinControl* AParent = (Controls::TWinControl*)(0x0));
	void __fastcall RefreshControls(Teeprocs::TTeeCustomShape* AShape);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeShape(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeShape(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeShape(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TFormTeeShape* __fastcall InsertTeeObjectForm(Comctrls::TPageControl* APageControl, Teeprocs::TTeeCustomShape* AShape);
extern PACKAGE void __fastcall EditTeeCustomShape(Classes::TComponent* AOwner, Teeprocs::TTeeCustomShape* AShape, bool HideText = false);

}	/* namespace Teecustomshapeeditor */
using namespace Teecustomshapeeditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCustomShapeEditor
