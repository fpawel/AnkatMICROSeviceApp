// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFuncEdit.pas' rev: 6.00

#ifndef TeeFuncEditHPP
#define TeeFuncEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSourceEdit.hpp>	// Pascal unit
#include <TeeEdiPeri.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeSelectList.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teefuncedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeFuncEditor;
class PASCALIMPLEMENTATION TTeeFuncEditor : public Teesourceedit::TBaseSourceEditor 
{
	typedef Teesourceedit::TBaseSourceEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSource;
	Comctrls::TTabSheet* TabOptions;
	Extctrls::TPanel* PanSingle;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBSingle;
	Stdctrls::TLabel* LValues;
	Tecanvas::TComboFlat* CBValues;
	Stdctrls::TButton* BNone;
	Extctrls::TTimer* Timer1;
	Extctrls::TTimer* Timer2;
	Buttons::TSpeedButton* SpeedButton1;
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall CBSourcesChange(System::TObject* Sender);
	void __fastcall BApplyClick(System::TObject* Sender);
	void __fastcall CBSingleChange(System::TObject* Sender);
	void __fastcall BNoneClick(System::TObject* Sender);
	void __fastcall CBValuesChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall Timer2Timer(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	
private:
	bool Filling;
	Forms::TForm* IOptions;
	Teeselectlist::TSelectListForm* ISources;
	void __fastcall FillSeries(void);
	void __fastcall TryCreateNewFunction(void);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
public:
	Teengine::TChartSeries* TheSeries;
	TMetaClass* __fastcall FunctionClass(void);
	/*         class method */ static void __fastcall SetValueListCombo(TMetaClass* vmt, Teengine::TChartSeries* Series, Tecanvas::TComboFlat* Combo);
	DYNAMIC void __fastcall Translate(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeFuncEditor(Classes::TComponent* AOwner) : Teesourceedit::TBaseSourceEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teesourceedit::TBaseSourceEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeFuncEditor(HWND ParentWindow) : Teesourceedit::TBaseSourceEditor(ParentWindow) { }
	#pragma option pop
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall FillSeriesSources(Classes::TStrings* AItems, Classes::TStrings* AItems2, Teengine::TChartSeries* TheSeries, bool AddCurrent);

}	/* namespace Teefuncedit */
using namespace Teefuncedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFuncEdit
