// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCircledEdit.pas' rev: 6.00

#ifndef TeeCircledEditHPP
#define TeeCircledEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
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

namespace Teecirclededit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCircledSeriesEditor;
class PASCALIMPLEMENTATION TCircledSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabOptions;
	Comctrls::TTabSheet* TabRadius;
	Comctrls::TTabSheet* TabShadow;
	Stdctrls::TLabel* Label1;
	Stdctrls::TCheckBox* CBCircled;
	Stdctrls::TCheckBox* CB3D;
	Stdctrls::TEdit* Edit1;
	Tecanvas::TButtonColor* BBack;
	Stdctrls::TCheckBox* CBTransp;
	Teeedigrad::TButtonGradient* BGradient;
	Comctrls::TUpDown* UDRot;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* Edit2;
	Stdctrls::TCheckBox* CBAutoXR;
	Stdctrls::TEdit* Edit3;
	Stdctrls::TCheckBox* CBAutoYR;
	Comctrls::TUpDown* UDY;
	Comctrls::TUpDown* UDX;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBCircledClick(System::TObject* Sender);
	void __fastcall SERotationChange(System::TObject* Sender);
	void __fastcall SEXRadiusChange(System::TObject* Sender);
	void __fastcall SEYRadiusChange(System::TObject* Sender);
	void __fastcall CBAutoXRClick(System::TObject* Sender);
	void __fastcall CBAutoYRClick(System::TObject* Sender);
	void __fastcall CB3DClick(System::TObject* Sender);
	void __fastcall BBackClick(System::TObject* Sender);
	void __fastcall CBTranspClick(System::TObject* Sender);
	void __fastcall BGradientClick(System::TObject* Sender);
	
private:
	Series::TCircledSeries* Circled;
	bool CreatingForm;
	
public:
	/*         class method */ static TCircledSeriesEditor* __fastcall CreateForm(TMetaClass* vmt, Forms::TCustomForm* AForm, const Series::TCircledSeries* Circled);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCircledSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCircledSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCircledSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCircledSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecirclededit */
using namespace Teecirclededit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCircledEdit
