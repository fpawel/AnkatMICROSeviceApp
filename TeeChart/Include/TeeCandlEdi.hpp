// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCandlEdi.pas' rev: 6.00

#ifndef TeeCandlEdiHPP
#define TeeCandlEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeComma.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <CandleCh.hpp>	// Pascal unit
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

namespace Teecandledi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCandleEditor;
class PASCALIMPLEMENTATION TCandleEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Tecanvas::TButtonColor* BUpColor;
	Tecanvas::TButtonColor* BDownColor;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBColorStyle;
	Teeedigrad::TButtonGradient* BUpGradient;
	Teeedigrad::TButtonGradient* BDownGradient;
	Stdctrls::TLabel* Label1;
	Extctrls::TRadioGroup* RGStyle;
	Stdctrls::TEdit* SEWidth;
	Stdctrls::TCheckBox* CBShowOpen;
	Stdctrls::TCheckBox* CBShowClose;
	Teependlg::TButtonPen* Button1;
	Comctrls::TUpDown* UDWidth;
	Stdctrls::TCheckBox* CBDraw3D;
	Stdctrls::TCheckBox* CBDark3D;
	Teependlg::TButtonPen* BHighLow;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	void __fastcall SEWidthChange(System::TObject* Sender);
	void __fastcall CBShowOpenClick(System::TObject* Sender);
	void __fastcall CBShowCloseClick(System::TObject* Sender);
	void __fastcall CBDraw3DClick(System::TObject* Sender);
	void __fastcall CBDark3DClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBColorStyleChange(System::TObject* Sender);
	
private:
	Candlech::TCandleSeries* Candle;
	void __fastcall RefreshControls(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCandleEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCandleEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCandleEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCandleEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecandledi */
using namespace Teecandledi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCandlEdi
