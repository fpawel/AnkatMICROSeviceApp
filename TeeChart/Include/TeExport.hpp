// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeExport.pas' rev: 6.00

#ifndef TeExportHPP
#define TeExportHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Buttons.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
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

namespace Teexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeExportForm;
class PASCALIMPLEMENTATION TTeeExportForm : public Teeexport::TTeeExportFormBase 
{
	typedef Teeexport::TTeeExportFormBase inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	
protected:
	virtual Teeprocs::TTeeExportData* __fastcall CreateData(void);
	virtual void __fastcall DoSaveNativeToFile(const AnsiString FileName, bool IncludeData);
	virtual bool __fastcall ExistData(void);
	virtual Classes::TStream* __fastcall CreateNativeStream(void);
	virtual void __fastcall PrepareOnShow(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeExportForm(Classes::TComponent* AOwner) : Teeexport::TTeeExportFormBase(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeExportForm(Classes::TComponent* AOwner, int Dummy) : Teeexport::TTeeExportFormBase(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeExportForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeExportForm(HWND ParentWindow) : Teeexport::TTeeExportFormBase(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeExport(Classes::TComponent* AOwner, Teeprocs::TCustomTeePanel* APanel, AnsiString InitialDir)/* overload */;
extern PACKAGE void __fastcall TeeExport(Classes::TComponent* AOwner, Teeprocs::TCustomTeePanel* APanel)/* overload */;
extern PACKAGE void __fastcall TeeSavePanel(TMetaClass* AFormat, Teeprocs::TCustomTeePanel* APanel);
extern PACKAGE void __fastcall TeeEmailFile(const AnsiString FileName, const AnsiString Subject = "TeeChart");

}	/* namespace Teexport */
using namespace Teexport;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeExport
