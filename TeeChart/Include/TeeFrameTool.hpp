// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFrameTool.pas' rev: 6.00

#ifndef TeeFrameToolHPP
#define TeeFrameToolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeFilters.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teeframetool
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFrameTool;
class PASCALIMPLEMENTATION TFrameTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	Tecanvas::TTeePicture* FFrame;
	int FPaspartou;
	bool FResize;
	int FSize;
	int FStyle;
	bool IResized;
	Teefilters::TRotateFilter* IRotate;
	void __fastcall DoResizeChart(void);
	void __fastcall DrawFrame(void);
	bool __fastcall IsFrameStored(void);
	void __fastcall PaspartouChanged(System::TObject* Sender);
	void __fastcall SetFrame(const Tecanvas::TTeePicture* Value);
	void __fastcall SetResize(const bool Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetStyle(const int Value);
	void __fastcall SetPaspartou(const int Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TFrameTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TFrameTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property Brush ;
	__property Tecanvas::TTeePicture* Frame = {read=FFrame, write=SetFrame, stored=IsFrameStored};
	__property int Paspartou = {read=FPaspartou, write=SetPaspartou, nodefault};
	__property Pen ;
	__property bool ResizeChart = {read=FResize, write=SetResize, default=1};
	__property int Size = {read=FSize, write=SetSize, default=16};
	__property int Style = {read=FStyle, write=SetStyle, default=1};
};


class DELPHICLASS TFrameToolEditor;
class PASCALIMPLEMENTATION TFrameToolEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TScrollBar* SBSize;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* BBrowse;
	Stdctrls::TCheckBox* CBResize;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TButton* Button2;
	Stdctrls::TLabel* Label2;
	Stdctrls::TScrollBar* SBPasSize;
	Stdctrls::TLabel* LSize;
	Stdctrls::TLabel* LPasSize;
	Tecanvas::TComboFlat* CBStyle;
	Stdctrls::TLabel* Label3;
	Teependlg::TButtonPen* BBorder;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBChangeColor;
	Stdctrls::TGroupBox* GroupColors;
	Stdctrls::TScrollBar* SBRed;
	Stdctrls::TScrollBar* SBGreen;
	Stdctrls::TScrollBar* SBBlue;
	Stdctrls::TLabel* LRed;
	Stdctrls::TLabel* LGreen;
	Stdctrls::TLabel* LBlue;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SBSizeChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall BBrowseClick(System::TObject* Sender);
	void __fastcall CBResizeClick(System::TObject* Sender);
	void __fastcall SBPasSizeChange(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall SBRedChange(System::TObject* Sender);
	void __fastcall CBChangeColorClick(System::TObject* Sender);
	void __fastcall SBGreenChange(System::TObject* Sender);
	void __fastcall SBBlueChange(System::TObject* Sender);
	
private:
	TFrameTool* Tool;
	void __fastcall CheckColorFilter(void);
	Teefilters::TColorFilter* __fastcall ColorFilter(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFrameToolEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFrameToolEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFrameToolEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFrameToolEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeframetool */
using namespace Teeframetool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFrameTool
