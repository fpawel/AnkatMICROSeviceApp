// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeVideoPlayer.pas' rev: 6.00

#ifndef TeeVideoPlayerHPP
#define TeeVideoPlayerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeVideo.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeFilters.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teevideoplayer
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TVideoPlayerTool;
class PASCALIMPLEMENTATION TVideoPlayerTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	AnsiString FFileName;
	Tecanvas::TFilterItems* FFilters;
	bool FLoop;
	Classes::TNotifyEvent FOnFrame;
	Graphics::TPicture* FPicture;
	Graphics::TBitmap* IBitmap;
	int ICount;
	bool IPaused;
	bool IPlaying;
	Extctrls::TTimer* ITimer;
	int IEndFrame;
	Teevideo::IGetFrame* *IGetFrame;
	void *IStream;
	void *IFile;
	void __fastcall Finish(void);
	int __fastcall GetEnd(void);
	int __fastcall GetStart(void);
	void __fastcall Open(void);
	void __fastcall TimerEvent(System::TObject* Sender);
	int __fastcall GetDelay(void);
	void __fastcall SetDelay(const int Value);
	void __fastcall SetFilters(const Tecanvas::TFilterItems* Value);
	void __fastcall SetPicture(const Graphics::TPicture* Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	Graphics::TBitmap* __fastcall GetFrame(int FrameNumber)/* overload */;
	void __fastcall GetFrame(int FrameNumber, Graphics::TBitmap* &b)/* overload */;
	
public:
	__fastcall virtual TVideoPlayerTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TVideoPlayerTool(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	void __fastcall Pause(void);
	void __fastcall Play(void);
	void __fastcall Stop(void);
	__property bool Paused = {read=IPaused, nodefault};
	__property Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property bool Playing = {read=IPlaying, nodefault};
	__property int Position = {read=ICount, write=ICount, nodefault};
	__property int StartFrame = {read=GetStart, nodefault};
	__property int EndFrame = {read=GetEnd, nodefault};
	
__published:
	__property int Delay = {read=GetDelay, write=SetDelay, default=1};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property Tecanvas::TFilterItems* Filters = {read=FFilters, write=SetFilters, stored=false};
	__property bool Loop = {read=FLoop, write=FLoop, default=0};
	__property Classes::TNotifyEvent OnFrame = {read=FOnFrame, write=FOnFrame};
};


class DELPHICLASS TVideoPlayerEditor;
class PASCALIMPLEMENTATION TVideoPlayerEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EName;
	Buttons::TSpeedButton* SpeedButton1;
	Stdctrls::TButton* BPlay;
	Stdctrls::TButton* Button1;
	Stdctrls::TCheckBox* CBLoop;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* EDelay;
	Comctrls::TUpDown* UDDelay;
	Dialogs::TOpenDialog* OpenDialog1;
	Stdctrls::TLabel* LFrame;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TRadioButton* RBBack;
	Stdctrls::TRadioButton* RBOther;
	Tecanvas::TComboFlat* CBDisplay;
	Tecanvas::TComboFlat* CBItem;
	void __fastcall BPlayClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBLoopClick(System::TObject* Sender);
	void __fastcall EDelayChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ENameChange(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall RBOtherClick(System::TObject* Sender);
	void __fastcall RBBackClick(System::TObject* Sender);
	void __fastcall CBDisplayChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBItemChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Classes::TNotifyEvent OldOnFrame;
	TVideoPlayerTool* Player;
	int VideoSize;
	void __fastcall PlayerFrame(System::TObject* Sender);
	void __fastcall SetupPlay(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TVideoPlayerEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TVideoPlayerEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TVideoPlayerEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVideoPlayerEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teevideoplayer */
using namespace Teevideoplayer;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeVideoPlayer
