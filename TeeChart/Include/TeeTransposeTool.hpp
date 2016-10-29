// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTransposeTool.pas' rev: 6.00

#ifndef TeeTransposeToolHPP
#define TeeTransposeToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Teetransposetool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGridTransposeTool;
class PASCALIMPLEMENTATION TGridTransposeTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	Teesurfa::TCustom3DGridSeries* FSeries;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	void __fastcall Transpose(void);
	
__published:
	__property Active  = {default=1};
	__property Teesurfa::TCustom3DGridSeries* Series = {read=FSeries, write=FSeries};
public:
	#pragma option push -w-inl
	/* TCustomChartElement.Create */ inline __fastcall virtual TGridTransposeTool(Classes::TComponent* AOwner) : Teengine::TTeeCustomTool(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartElement.Destroy */ inline __fastcall virtual ~TGridTransposeTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGridTransposeToolEdit;
class PASCALIMPLEMENTATION TGridTransposeToolEdit : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBSeries;
	Stdctrls::TButton* BTranspose;
	void __fastcall CBSeriesChange(System::TObject* Sender);
	void __fastcall BTransposeClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	TGridTransposeTool* Tool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TGridTransposeToolEdit(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TGridTransposeToolEdit(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TGridTransposeToolEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGridTransposeToolEdit(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teetransposetool */
using namespace Teetransposetool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTransposeTool
