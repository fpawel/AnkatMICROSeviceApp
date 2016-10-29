// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBmpOptions.pas' rev: 6.00

#ifndef TeeBmpOptionsHPP
#define TeeBmpOptionsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teebmpoptions
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBMPOptions;
class DELPHICLASS TBMPExportFormat;
class PASCALIMPLEMENTATION TBMPExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	Tecanvas::TFilterItems* FFilters;
	TBMPOptions* FProperties;
	void __fastcall CheckProperties(void);
	Graphics::TBitmap* __fastcall InternalGetBitmap(void);
	
protected:
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	__fastcall virtual TBMPExportFormat(void);
	__fastcall virtual ~TBMPExportFormat(void);
	Graphics::TBitmap* __fastcall Bitmap(void);
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	virtual TMetaClass* __fastcall GraphicClass(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
};


class PASCALIMPLEMENTATION TBMPOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBMono;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBColors;
	Stdctrls::TButton* Button1;
	Stdctrls::TGroupBox* GroupBox1;
	Teefilters::TImageFiltered* ImageFiltered1;
	void __fastcall CBMonoClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CBColorsChange(System::TObject* Sender);
	
private:
	void __fastcall Preview(void);
	
protected:
	TBMPExportFormat* IFormat;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TBMPOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TBMPOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TBMPOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TBMPOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeSaveToBitmap(Teeprocs::TCustomTeePanel* APanel, const WideString FileName, const Types::TRect &R);

}	/* namespace Teebmpoptions */
using namespace Teebmpoptions;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBmpOptions
