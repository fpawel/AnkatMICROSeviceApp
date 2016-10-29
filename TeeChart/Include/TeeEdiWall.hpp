// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiWall.pas' rev: 6.00

#ifndef TeeEdiWallHPP
#define TeeEdiWallHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeShadowEditor.hpp>	// Pascal unit
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
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
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeediwall
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeWall;
class PASCALIMPLEMENTATION TFormTeeWall : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TTabControl* TabSubWalls;
	Stdctrls::TLabel* L33;
	Tecanvas::TButtonColor* BWallColor;
	Teependlg::TButtonPen* BWallPen;
	Stdctrls::TButton* BWallBrush;
	Stdctrls::TEdit* SEWallSize;
	Stdctrls::TCheckBox* CBTransp;
	Comctrls::TUpDown* UDWallSize;
	Stdctrls::TCheckBox* CBDark3D;
	Teeedigrad::TButtonGradient* BGradient;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDTransp;
	Extctrls::TPanel* Panel1;
	Stdctrls::TCheckBox* CBView3dWalls;
	Stdctrls::TCheckBox* CBAutoHide;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EAllSize;
	Comctrls::TUpDown* UDAllSize;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDStart;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDEnd;
	Stdctrls::TButton* BImage;
	Stdctrls::TButton* BShadow;
	void __fastcall TabSubWallsChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBView3dWallsClick(System::TObject* Sender);
	void __fastcall BWallBrushClick(System::TObject* Sender);
	void __fastcall SEWallSizeChange(System::TObject* Sender);
	void __fastcall CBTranspClick(System::TObject* Sender);
	void __fastcall CBDark3DClick(System::TObject* Sender);
	void __fastcall BGradientClick(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall CBAutoHideClick(System::TObject* Sender);
	void __fastcall EAllSizeChange(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall BImageClick(System::TObject* Sender);
	void __fastcall BShadowClick(System::TObject* Sender);
	
private:
	bool SettingAllSize;
	Chart::TCustomChartWall* TheWall;
	void __fastcall SetWallControls(void);
	Chart::TCustomChart* __fastcall TheChart(void);
	
public:
	__fastcall TFormTeeWall(Classes::TComponent* AOwner, Chart::TCustomChartWall* AWall);
	void __fastcall RefreshControls(Chart::TCustomChartWall* Wall);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeWall(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeWall(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeWall(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeWall(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeediwall */
using namespace Teeediwall;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiWall
