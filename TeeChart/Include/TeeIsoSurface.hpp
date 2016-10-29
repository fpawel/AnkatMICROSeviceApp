// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeIsoSurface.pas' rev: 6.00

#ifndef TeeIsoSurfaceHPP
#define TeeIsoSurfaceHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeSurfEdit.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeisosurface
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIsoSurfaceEditor;
class PASCALIMPLEMENTATION TIsoSurfaceEditor : public Teesurfedit::TSurfaceSeriesEditor 
{
	typedef Teesurfedit::TSurfaceSeriesEditor inherited;
	
__published:
	Teependlg::TButtonPen* BBandsPen;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TIsoSurfaceEditor(Classes::TComponent* AOwner) : Teesurfedit::TSurfaceSeriesEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TIsoSurfaceEditor(Classes::TComponent* AOwner, int Dummy) : Teesurfedit::TSurfaceSeriesEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TIsoSurfaceEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIsoSurfaceEditor(HWND ParentWindow) : Teesurfedit::TSurfaceSeriesEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeisosurface */
using namespace Teeisosurface;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeIsoSurface
