// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEmfOptions.pas' rev: 6.00

#ifndef TeeEmfOptionsHPP
#define TeeEmfOptionsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teeemfoptions
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEMFOptions;
class PASCALIMPLEMENTATION TEMFOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBEnhanced;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TEMFOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TEMFOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TEMFOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TEMFOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TEMFExportFormat;
class PASCALIMPLEMENTATION TEMFExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	TEMFOptions* FProperties;
	bool __fastcall GetEnhanced(void);
	void __fastcall SetEnhanced(const bool Value);
	
protected:
	virtual void __fastcall DoCopyToClipboard(void);
	virtual int __fastcall FileFilterIndex(void);
	virtual void __fastcall IncFileFilterIndex(int &FilterIndex);
	virtual bool __fastcall WantsFilterIndex(int Index);
	
public:
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	virtual TMetaClass* __fastcall GraphicClass(void);
	Graphics::TMetafile* __fastcall Metafile(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property bool Enhanced = {read=GetEnhanced, write=SetEnhanced, nodefault};
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TEMFExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TEMFExportFormat(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeemfoptions */
using namespace Teeemfoptions;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEmfOptions
