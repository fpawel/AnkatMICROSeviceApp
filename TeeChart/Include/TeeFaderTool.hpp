// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFaderTool.pas' rev: 6.00

#ifndef TeeFaderToolHPP
#define TeeFaderToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
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

namespace Teefadertool
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TFaderStyle { fsFadeIn, fsFadeOut };
#pragma option pop

class DELPHICLASS TFaderTool;
class PASCALIMPLEMENTATION TFaderTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	Graphics::TColor FColor;
	int FDelay;
	Classes::TNotifyEvent FOnStop;
	double FSpeed;
	TFaderStyle FStyle;
	Graphics::TBitmap* IDest;
	Extctrls::TTimer* ITimer;
	double ITransp;
	bool IInitial;
	void __fastcall DoTimer(System::TObject* Sender);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TFaderTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TFaderTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	void __fastcall Start(void);
	void __fastcall Stop(void);
	
__published:
	__property Graphics::TColor Color = {read=FColor, write=FColor, default=0};
	__property int InitialDelay = {read=FDelay, write=FDelay, default=100};
	__property double Speed = {read=FSpeed, write=FSpeed};
	__property TFaderStyle Style = {read=FStyle, write=FStyle, default=0};
	__property Classes::TNotifyEvent OnStop = {read=FOnStop, write=FOnStop};
};


class DELPHICLASS TFaderEditor;
class PASCALIMPLEMENTATION TFaderEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TButton* BStart;
	Stdctrls::TButton* BReset;
	Stdctrls::TScrollBar* SBSpeed;
	Tecanvas::TButtonColor* ButtonColor1;
	Extctrls::TRadioGroup* RGStyle;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDDelay;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall BStartClick(System::TObject* Sender);
	void __fastcall SBSpeedChange(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall BResetClick(System::TObject* Sender);
	
private:
	TFaderTool* Tool;
	Classes::TNotifyEvent OldOnStop;
	void __fastcall FaderStop(System::TObject* Sender);
	void __fastcall SetLabelSpeed(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFaderEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFaderEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFaderEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFaderEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teefadertool */
using namespace Teefadertool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFaderTool
