// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeJPEG.pas' rev: 6.00

#ifndef TeeJPEGHPP
#define TeeJPEGHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <jpeg.hpp>	// Pascal unit
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

namespace Teejpeg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeJPEGOptions;
class PASCALIMPLEMENTATION TTeeJPEGOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBGray;
	Extctrls::TRadioGroup* RGPerf;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EQuality;
	Comctrls::TUpDown* UpDown1;
	void __fastcall FormCreate(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeJPEGOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeJPEGOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeJPEGOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeJPEGOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TJPEGExportFormat;
class PASCALIMPLEMENTATION TJPEGExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	void __fastcall CheckProperties(void);
	int __fastcall GetQuality(void);
	void __fastcall SetQuality(const int Value);
	
protected:
	TTeeJPEGOptions* FProperties;
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	__fastcall virtual ~TJPEGExportFormat(void);
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	virtual TMetaClass* __fastcall GraphicClass(void);
	Jpeg::TJPEGImage* __fastcall Jpeg(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property int Quality = {read=GetQuality, write=SetQuality, default=95};
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TJPEGExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jpeg::TJPEGImage* __fastcall TeeGetJPEGImageParams(Teeprocs::TCustomTeePanel* APanel, const Jpeg::TJPEGDefaults &Params, int Left, int Top, int Width, int Height);
extern PACKAGE void __fastcall TeeSaveToJPEGFile(Teeprocs::TCustomTeePanel* APanel, const WideString FileName, Word Gray, Jpeg::TJPEGPerformance Performance, int Quality, int AWidth, int AHeight);
extern PACKAGE void __fastcall TeeSaveToJPEG(Teeprocs::TCustomTeePanel* APanel, const WideString FileName, int AWidth, int AHeight);

}	/* namespace Teejpeg */
using namespace Teejpeg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeJPEG
