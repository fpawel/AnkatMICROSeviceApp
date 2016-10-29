// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBrushDlg.pas' rev: 6.00

#ifndef TeeBrushDlgHPP
#define TeeBrushDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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

namespace Teebrushdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBrushDialog;
class PASCALIMPLEMENTATION TBrushDialog : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TListBox* LStyle;
	Extctrls::TPanel* PanelOk;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button3;
	Extctrls::TPanel* Panel1;
	Extctrls::TImage* ImageMetal;
	Extctrls::TImage* ImageWood;
	Extctrls::TImage* ImageStone;
	Extctrls::TImage* ImageClouds;
	Extctrls::TImage* ImageGrass;
	Extctrls::TImage* ImageFire;
	Extctrls::TImage* ImageSnow;
	Tecanvas::TButtonColor* BColor;
	Stdctrls::TGroupBox* GroupBox2;
	Extctrls::TImage* Image1;
	Stdctrls::TButton* Button1;
	Tecanvas::TButtonColor* BBackColor;
	Stdctrls::TCheckBox* CBTransp;
	Extctrls::TSplitter* Splitter1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall LStyleClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBTranspClick(System::TObject* Sender);
	void __fastcall BBackColorClick(System::TObject* Sender);
	void __fastcall LStyleDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Tecanvas::TChartBrush* BackupBrush;
	void __fastcall CheckImageButton(void);
	Graphics::TBitmap* __fastcall GetInternalBrush(int Index);
	void __fastcall RedrawShape(void);
	
public:
	Tecanvas::TChartBrush* TheBrush;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBrushDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBrushDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBrushDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBrushDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditTeeFont(Classes::TComponent* AOwner, Graphics::TFont* AFont);
extern PACKAGE bool __fastcall EditChartBrush(Classes::TComponent* AOwner, Tecanvas::TChartBrush* ChartBrush);
extern PACKAGE AnsiString __fastcall TeeGetPictureFileName(Classes::TComponent* AOwner);
extern PACKAGE void __fastcall TeeLoadClearImage(Classes::TComponent* AOwner, Graphics::TPicture* AImage);
extern PACKAGE void __fastcall GetTeeBrush(int Index, Graphics::TBitmap* ABitmap);

}	/* namespace Teebrushdlg */
using namespace Teebrushdlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBrushDlg
