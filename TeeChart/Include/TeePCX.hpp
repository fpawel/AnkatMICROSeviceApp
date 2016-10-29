// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePCX.pas' rev: 6.00

#ifndef TeePCXHPP
#define TeePCXHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teepcx
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPCXOptions;
class PASCALIMPLEMENTATION TPCXOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPCXOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPCXOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPCXOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPCXOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TPCXExportFormat;
class PASCALIMPLEMENTATION TPCXExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	TPCXOptions* FProperties;
	Graphics::TBitmap* __fastcall Bitmap(void);
	void __fastcall CheckProperties(void);
	
protected:
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TPCXExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TPCXExportFormat(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teepcx */
using namespace Teepcx;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePCX
