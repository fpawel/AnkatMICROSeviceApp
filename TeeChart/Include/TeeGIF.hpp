// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGIF.pas' rev: 6.00

#ifndef TeeGIFHPP
#define TeeGIFHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <GIFImage.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teegif
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeGIFOptions;
class PASCALIMPLEMENTATION TTeeGIFOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TRadioGroup* RGCompression;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBDither;
	Stdctrls::TLabel* Label2;
	Tecanvas::TComboFlat* CBReduction;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeGIFOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeGIFOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeGIFOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeGIFOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TGIFExportFormat;
class PASCALIMPLEMENTATION TGIFExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	void __fastcall CheckProperties(void);
	
protected:
	TTeeGIFOptions* FProperties;
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	virtual TMetaClass* __fastcall GraphicClass(void);
	Gifimage::TGIFImage* __fastcall GIF(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TGIFExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TGIFExportFormat(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teegif */
using namespace Teegif;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGIF
