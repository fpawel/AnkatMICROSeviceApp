// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePNG.pas' rev: 6.00

#ifndef TeePNGHPP
#define TeePNGHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepng
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeePNGOptions;
class DELPHICLASS TPNGExportFormat;
#pragma pack(push, 4)
struct TPicData
{
	Classes::TMemoryStream* Stream;
	void *APtr;
	int BLineWidth;
	int LineWidth;
	int Width;
	int Height;
} ;
#pragma pack(pop)

class PASCALIMPLEMENTATION TPNGExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
private:
	int FCompression;
	Graphics::TPixelFormat FPixel;
	TPicData PicData;
	Byte *RowPtrs;
	Byte SaveBuf[8193];
	void __fastcall CheckProperties(void);
	void __fastcall SetCompression(const int Value);
	
protected:
	TTeePNGOptions* FProperties;
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	__fastcall virtual TPNGExportFormat(void);
	Graphics::TBitmap* __fastcall Bitmap(void);
	__property int Compression = {read=FCompression, write=SetCompression, nodefault};
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	__property Graphics::TPixelFormat PixelFormat = {read=FPixel, write=FPixel, nodefault};
	virtual void __fastcall SaveToStream(Classes::TStream* AStream);
	void __fastcall SaveToStreamCompression(Classes::TStream* AStream, int CompressionLevel);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TPNGExportFormat(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTeePNGOptions : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UpDown1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	
private:
	TPNGExportFormat* IFormat;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeePNGOptions(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeePNGOptions(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeePNGOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeePNGOptions(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeSaveToPNG(Teeprocs::TCustomTeePanel* APanel, const WideString AFileName, int AWidth = 0x0, int AHeight = 0x0);

}	/* namespace Teepng */
using namespace Teepng;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePNG
