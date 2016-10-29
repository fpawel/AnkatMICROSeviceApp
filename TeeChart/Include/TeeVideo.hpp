// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeVideo.pas' rev: 6.00

#ifndef TeeVideoHPP
#define TeeVideoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFilters.hpp>	// Pascal unit
#include <TeeProCo.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teevideo
{
//-- type declarations -------------------------------------------------------
typedef void *PAVIFile;

typedef void *PAVIStream;

#pragma pack(push, 1)
struct TAviStreamInfoA
{
	unsigned fccType;
	unsigned fccHandler;
	unsigned dwFlags;
	unsigned dwCaps;
	Word wPriority;
	Word wLanguage;
	unsigned dwScale;
	unsigned dwRate;
	unsigned dwStart;
	unsigned dwLength;
	unsigned dwInitialFrames;
	unsigned dwSuggestedBufferSize;
	unsigned dwQuality;
	unsigned dwSampleSize;
	Types::TRect rcFrame;
	unsigned dwEditCount;
	unsigned dwFormatChangeCount;
	char szName[64];
} ;
#pragma pack(pop)

struct TAVICompressOptions;
typedef TAVICompressOptions *PAVICompressOptions;

#pragma pack(push, 1)
struct TAVICompressOptions
{
	unsigned fccType;
	unsigned fccHandler;
	unsigned dwKeyFrameEvery;
	unsigned dwQuality;
	unsigned dwBytesPerSecond;
	unsigned dwFlags;
	void *lpFormat;
	unsigned cbFormat;
	void *lpParms;
	unsigned cbParms;
	unsigned dwInterleaveEvery;
} ;
#pragma pack(pop)

class DELPHICLASS TVideoTool;
class PASCALIMPLEMENTATION TVideoTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	int FCount;
	int FDuration;
	AnsiString FFileName;
	AnsiString FFourCC;
	Classes::TNotifyEvent FOnNewFrame;
	Classes::TNotifyEvent FOnStart;
	Classes::TNotifyEvent FOnStop;
	int FQuality;
	bool FRecording;
	void *IFile;
	#pragma pack(push, 1)
	TAviStreamInfoA IStream;
	#pragma pack(pop)
	
	void *IPStream;
	void *ICompStream;
	tagBITMAPINFO *IPInInfo;
	#pragma pack(push, 1)
	TAVICompressOptions AviCompressoptions;
	#pragma pack(pop)
	
	void __fastcall AddFrame(Graphics::TBitmap* Bitmap);
	void __fastcall Clean(void);
	void __fastcall CreateStream(void);
	void __fastcall InitStreamFormat(Graphics::TBitmap* Bitmap);
	void __fastcall PrepareBitmapHeader(tagBITMAPINFOHEADER &Header);
	void __fastcall SetCompression(const AnsiString Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TVideoTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TVideoTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	void __fastcall GetCompressors(const Classes::TStrings* List);
	void __fastcall ShowCompressorOptions(Controls::TWinControl* Parent);
	void __fastcall StartRecording(const AnsiString FileName);
	void __fastcall StopRecording(void);
	__property int FrameCount = {read=FCount, nodefault};
	__property bool IsRecording = {read=FRecording, nodefault};
	
__published:
	__property AnsiString Compression = {read=FFourCC, write=SetCompression};
	__property int CompressionQuality = {read=FQuality, write=FQuality, default=8000};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property int FrameDuration = {read=FDuration, write=FDuration, default=50};
	__property Classes::TNotifyEvent OnNewFrame = {read=FOnNewFrame, write=FOnNewFrame};
	__property Classes::TNotifyEvent OnStart = {read=FOnStart, write=FOnStart};
	__property Classes::TNotifyEvent OnStop = {read=FOnStop, write=FOnStop};
};


class DELPHICLASS TVideoToolEditor;
class PASCALIMPLEMENTATION TVideoToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TScrollBar* SBMsec;
	Tecanvas::TComboFlat* CBCompress;
	Tecanvas::TComboFlat* CBQuality;
	Stdctrls::TButton* BEdit;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TButton* BStart;
	Stdctrls::TButton* BStop;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* EFile;
	Buttons::TSpeedButton* SpeedButton1;
	Dialogs::TOpenDialog* OpenDialog1;
	Stdctrls::TLabel* LFrameCap;
	Stdctrls::TLabel* LFrame;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SBMsecChange(System::TObject* Sender);
	void __fastcall BStartClick(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall EFileChange(System::TObject* Sender);
	void __fastcall BStopClick(System::TObject* Sender);
	void __fastcall CBQualityChange(System::TObject* Sender);
	void __fastcall CBCompressChange(System::TObject* Sender);
	void __fastcall BEditClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBCompressDropDown(System::TObject* Sender);
	
private:
	bool CompressFilled;
	TVideoTool* Video;
	Classes::TNotifyEvent OldNewFrame;
	void __fastcall SetLabelFrame(void);
	void __fastcall SetupProgress(void);
	void __fastcall VideoNewFrame(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TVideoToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TVideoToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TVideoToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVideoToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


struct TAVIFILEINFOA;
typedef TAVIFILEINFOA *PAVIFILEINFOA;

#pragma pack(push, 4)
struct TAVIFILEINFOA
{
	unsigned dwMaxBytesPerSec;
	unsigned dwFlags;
	unsigned dwCaps;
	unsigned dwStreams;
	unsigned dwSuggestedBufferSize;
	unsigned dwWidth;
	unsigned dwHeight;
	unsigned dwScale;
	unsigned dwRate;
	unsigned dwLength;
	unsigned dwEditCount;
	char szFileType[64];
} ;
#pragma pack(pop)

typedef void *PVOID;

class DELPHICLASS IGetFrame;
typedef IGetFrame* *PGetFrame;

#pragma pack(push, 1)
class PASCALIMPLEMENTATION IGetFrame : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void * __stdcall GetFrame(unsigned lPos) = 0 ;
	virtual HRESULT __stdcall _Begin(unsigned lStart, unsigned lEnd, unsigned lRate) = 0 ;
	virtual HRESULT __stdcall _End(void) = 0 ;
	virtual HRESULT __stdcall SetFormat(Windows::PBitmapInfoHeader lpbi, void * lpBits, int x, int y, int dx, int dy) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall IGetFrame(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~IGetFrame(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Shortint AVIERR_OK = 0x0;
static const unsigned AVIERR_UNSUPPORTED = 0x80044065;
static const unsigned AVIERR_BADFORMAT = 0x80044066;
static const unsigned AVIERR_MEMORY = 0x80044067;
static const unsigned AVIERR_INTERNAL = 0x80044068;
static const unsigned AVIERR_BADFLAGS = 0x80044069;
static const unsigned AVIERR_BADPARAM = 0x8004406a;
static const unsigned AVIERR_BADSIZE = 0x8004406b;
static const unsigned AVIERR_BADHANDLE = 0x8004406c;
static const unsigned AVIERR_FILEREAD = 0x8004406d;
static const unsigned AVIERR_FILEWRITE = 0x8004406e;
static const unsigned AVIERR_FILEOPEN = 0x8004406f;
static const unsigned AVIERR_COMPRESSOR = 0x80044070;
static const unsigned AVIERR_NOCOMPRESSOR = 0x80044071;
static const unsigned AVIERR_READONLY = 0x80044072;
static const unsigned AVIERR_NODATA = 0x80044073;
static const unsigned AVIERR_BUFFERTOOSMALL = 0x80044074;
static const unsigned AVIERR_CANTCOMPRESS = 0x80044075;
static const unsigned AVIERR_USERABORT = 0x800440c6;
static const unsigned AVIERR_ERROR = 0x800440c7;
static const int StreamTypeVIDEO = 0x73646976;
static const int StreamTypeAUDIO = 0x73647561;
extern PACKAGE void __stdcall (*AVIFileExit)(void);
extern PACKAGE HRESULT __stdcall (*AVIFileGetStream)(void * pfile, void * &ppavi, unsigned fccType, unsigned lParam);
extern PACKAGE void __stdcall (*AVIFileInit)(void);
extern PACKAGE HRESULT __stdcall (*AVIFileOpen)(void * &ppfile, char * szFile, unsigned uMode, void * lpHandler);
extern PACKAGE unsigned __stdcall (*AVIFileRelease)(void * pfile);
extern PACKAGE HRESULT __stdcall (*AVIFileInfo)(void * pfile, PAVIFILEINFOA pfi, unsigned lSize);
extern PACKAGE void * __stdcall (*AVIStreamGetFrame)(PGetFrame pg, unsigned lPos);
extern PACKAGE HRESULT __stdcall (*AVIStreamGetFrameClose)(PGetFrame pg);
extern PACKAGE PGetFrame __stdcall (*AVIStreamGetFrameOpen)(void * pavi, Windows::PBitmapInfoHeader lpbiWanted);
extern PACKAGE unsigned __stdcall (*AVIStreamLength)(void * pavi);
extern PACKAGE unsigned __stdcall (*AVIStreamRelease)(void * pavi);
extern PACKAGE unsigned __stdcall (*AVIStreamStart)(void * pavi);
extern PACKAGE unsigned __stdcall (*AVIStreamInfo)(void * pavi, TAviStreamInfoA &psi, unsigned lSize);
extern PACKAGE void __fastcall AviCheck(const HRESULT ErrorCode);
extern PACKAGE bool __fastcall InitVideoForWindows(void);

}	/* namespace Teevideo */
using namespace Teevideo;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeVideo
