// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAxisToolEdit.pas' rev: 6.00

#ifndef TeeAxisToolEditHPP
#define TeeAxisToolEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeaxistooledit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAxisToolEditor;
class PASCALIMPLEMENTATION TAxisToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* BPen;
	Tecanvas::TComboFlat* CBAxis;
	Stdctrls::TLabel* Label1;
	Extctrls::TPanel* PanelTop;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBAxisChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	int __fastcall DepthAxesOffset(void);
	
protected:
	Teengine::TTeeCustomToolAxis* AxisTool;
	bool IncludeDepthAxes;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TAxisToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAxisToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAxisToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAxisToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeaxistooledit */
using namespace Teeaxistooledit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAxisToolEdit
