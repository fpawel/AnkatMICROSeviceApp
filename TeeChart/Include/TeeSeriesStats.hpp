// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSeriesStats.pas' rev: 6.00

#ifndef TeeSeriesStatsHPP
#define TeeSeriesStatsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teeseriesstats
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSeriesStatsTool;
class PASCALIMPLEMENTATION TSeriesStatsTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Teengine::TTeeFunction* __fastcall GetStatFunction(TMetaClass* FuncType);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	void __fastcall Statistics(Classes::TStrings* Lines);
	
__published:
	__property Active  = {default=1};
	__property Series ;
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TSeriesStatsTool(Classes::TComponent* AOwner) : Teengine::TTeeCustomToolSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TSeriesStatsTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesStatsEditor;
class PASCALIMPLEMENTATION TSeriesStatsEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CheckBox1;
	Stdctrls::TCheckBox* CheckBox2;
	Stdctrls::TButton* Button1;
	Stdctrls::TMemo* Memo1;
	Stdctrls::TButton* Button2;
	Stdctrls::TCheckBox* CheckBox3;
	Stdctrls::TButton* Button3;
	Stdctrls::TCheckBox* CheckBox4;
	Stdctrls::TButton* Button4;
	Stdctrls::TCheckBox* CheckBox5;
	Stdctrls::TButton* Button5;
	Stdctrls::TCheckBox* CheckBox6;
	Stdctrls::TButton* Button6;
	HIDESBASE void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CheckBox1Click(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CheckBox2Click(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CheckBox3Click(System::TObject* Sender);
	void __fastcall CheckBox4Click(System::TObject* Sender);
	void __fastcall CheckBox5Click(System::TObject* Sender);
	void __fastcall CheckBox6Click(System::TObject* Sender);
	
private:
	void __fastcall CheckFunction(Stdctrls::TCheckBox* ABox, TMetaClass* AFunctionClass);
	void __fastcall EnableControls(void);
	void __fastcall RefreshInfo(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSeriesStatsEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesStatsEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSeriesStatsEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesStatsEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeseriesstats */
using namespace Teeseriesstats;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSeriesStats
