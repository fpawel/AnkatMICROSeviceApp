// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSurfaceTool.pas' rev: 6.00

#ifndef TeeSurfaceToolHPP
#define TeeSurfaceToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
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

namespace Teesurfacetool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSurfaceNearestTool;
class PASCALIMPLEMENTATION TSurfaceNearestTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	Graphics::TColor FCell;
	Graphics::TColor FColumn;
	Graphics::TColor FRow;
	Classes::TNotifyEvent FOnSelect;
	void __fastcall SetCell(const Graphics::TColor Value);
	void __fastcall SetColumn(const Graphics::TColor Value);
	void __fastcall SetRow(const Graphics::TColor Value);
	
protected:
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetSeries(const Teengine::TChartSeries* Value);
	
public:
	int SelectedCell;
	__fastcall virtual TSurfaceNearestTool(Classes::TComponent* AOwner);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	void __fastcall GetRowCol(double &Row, double &Col);
	
__published:
	__property Active  = {default=1};
	__property Graphics::TColor CellColor = {read=FCell, write=SetCell, default=255};
	__property Graphics::TColor ColumnColor = {read=FColumn, write=SetColumn, default=32768};
	__property Graphics::TColor RowColor = {read=FRow, write=SetRow, default=16711680};
	__property Series ;
	__property Classes::TNotifyEvent OnSelectCell = {read=FOnSelect, write=FOnSelect};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TSurfaceNearestTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSurfaceNearest;
class PASCALIMPLEMENTATION TSurfaceNearest : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Tecanvas::TButtonColor* ButtonColor1;
	Tecanvas::TButtonColor* ButtonColor2;
	Tecanvas::TButtonColor* ButtonColor3;
	Stdctrls::TCheckBox* CheckBox1;
	Stdctrls::TCheckBox* CheckBox2;
	Stdctrls::TCheckBox* CheckBox3;
	Stdctrls::TCheckBox* CheckBox4;
	Stdctrls::TCheckBox* CheckBox5;
	Stdctrls::TCheckBox* CheckBox6;
	void __fastcall CheckBox1Click(System::TObject* Sender);
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CheckBox2Click(System::TObject* Sender);
	void __fastcall CheckBox3Click(System::TObject* Sender);
	void __fastcall ButtonColor1Click(System::TObject* Sender);
	void __fastcall ButtonColor2Click(System::TObject* Sender);
	void __fastcall ButtonColor3Click(System::TObject* Sender);
	HIDESBASE void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall CheckBox4Click(System::TObject* Sender);
	void __fastcall CheckBox5Click(System::TObject* Sender);
	void __fastcall CheckBox6Click(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSurfaceNearest(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSurfaceNearest(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSurfaceNearest(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSurfaceNearest(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teesurfacetool */
using namespace Teesurfacetool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSurfaceTool
