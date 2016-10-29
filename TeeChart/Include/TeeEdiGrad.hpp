// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiGrad.pas' rev: 6.00

#ifndef TeeEdiGradHPP
#define TeeEdiGradHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeGalleryPanel.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
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

namespace Teeedigrad
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPreviewGradient;
class PASCALIMPLEMENTATION TPreviewGradient : public Teeprocs::TCustomTeePanelExtended 
{
	typedef Teeprocs::TCustomTeePanelExtended inherited;
	
protected:
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
public:
	#pragma option push -w-inl
	/* TCustomTeePanelExtended.Create */ inline __fastcall virtual TPreviewGradient(Classes::TComponent* AOwner) : Teeprocs::TCustomTeePanelExtended(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeePanelExtended.Destroy */ inline __fastcall virtual ~TPreviewGradient(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPreviewGradient(HWND ParentWindow) : Teeprocs::TCustomTeePanelExtended(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TButtonGradient;
class DELPHICLASS TTeeGradientEditor;
class PASCALIMPLEMENTATION TTeeGradientEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TScrollBar* SBBalance;
	Stdctrls::TLabel* LabelBalance;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* LRadialX;
	Stdctrls::TLabel* LRadialY;
	Comctrls::TTrackBar* TrackBar1;
	Comctrls::TTrackBar* TrackBar2;
	Stdctrls::TButton* BSwap;
	Tecanvas::TButtonColor* BStart;
	Tecanvas::TButtonColor* BEnd;
	Tecanvas::TButtonColor* BMid;
	Stdctrls::TCheckBox* CBMid;
	Extctrls::TPanel* Panel1;
	Stdctrls::TButton* BOk;
	Stdctrls::TButton* BCancel;
	Extctrls::TPanel* Panel2;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* CBDirection;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TListBox* Gallery;
	Extctrls::TPanel* Panel3;
	Extctrls::TPanel* Panel4;
	Extctrls::TPanel* Panel5;
	Extctrls::TPanel* Panel6;
	Extctrls::TPanel* Panel7;
	Comctrls::TTabSheet* TabSheet4;
	Teegallerypanel::TChartGalleryPanel* Directions;
	Comctrls::TTabSheet* TabSheet5;
	Stdctrls::TLabel* Label5;
	Stdctrls::TScrollBar* SBTransp;
	TButtonGradient* BSubEdit;
	Stdctrls::TCheckBox* CBSubVisible;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* EAngle;
	Comctrls::TUpDown* UDAngle;
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall CBDirectionChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BCancelClick(System::TObject* Sender);
	void __fastcall BSwapClick(System::TObject* Sender);
	void __fastcall CBMidClick(System::TObject* Sender);
	void __fastcall BMidClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall TrackBar1Change(System::TObject* Sender);
	void __fastcall TrackBar2Change(System::TObject* Sender);
	void __fastcall SBBalanceChange(System::TObject* Sender);
	void __fastcall BStartClick(System::TObject* Sender);
	void __fastcall BEndClick(System::TObject* Sender);
	void __fastcall GalleryClick(System::TObject* Sender);
	void __fastcall DirectionsChangeChart(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall SBTranspChange(System::TObject* Sender);
	void __fastcall CBSubVisibleClick(System::TObject* Sender);
	void __fastcall EAngleChange(System::TObject* Sender);
	
private:
	Tecanvas::TCustomTeeGradient* Backup;
	bool IModified;
	bool IOnlyStart;
	bool SettingProps;
	TPreviewGradient* Preview;
	void __fastcall CheckDirection(void);
	void __fastcall CheckVisible(void);
	bool __fastcall IsRectGradient(void);
	void __fastcall SetDirectionGradients(void);
	
protected:
	virtual void __fastcall RefreshControls(void);
	virtual void __fastcall SetPreview(void);
	
public:
	Tecanvas::TCustomTeeGradient* TheGradient;
	__fastcall TTeeGradientEditor(Classes::TComponent* AOwner, Tecanvas::TCustomTeeGradient* AGradient);
	/*         class method */ static void __fastcall DefaultGradient(TMetaClass* vmt, Tecanvas::TCustomTeeGradient* Gradient, bool IsRectGradient, int Index);
	virtual void __fastcall RefreshGradient(Tecanvas::TCustomTeeGradient* AGradient);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeGradientEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeGradientEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeGradientEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeGradientEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TButtonGradient : public Tecanvas::TTeeButton 
{
	typedef Tecanvas::TTeeButton inherited;
	
private:
	TTeeGradientEditor* FEditor;
	Classes::TNotifyEvent FOldDestroy;
	void __fastcall EditorDestroy(System::TObject* Sender);
	TTeeGradientEditor* __fastcall GetEditor(void);
	Tecanvas::TCustomTeeGradient* __fastcall GetGradient(void);
	
protected:
	virtual void __fastcall DrawSymbol(Tecanvas::TTeeCanvas* ACanvas);
	
public:
	bool OnlyStart;
	DYNAMIC void __fastcall Click(void);
	void __fastcall LinkGradient(const Tecanvas::TCustomTeeGradient* Value);
	__property TTeeGradientEditor* Editor = {read=GetEditor};
	__property Tecanvas::TCustomTeeGradient* Gradient = {read=GetGradient, write=LinkGradient};
public:
	#pragma option push -w-inl
	/* TButton.Create */ inline __fastcall virtual TButtonGradient(Classes::TComponent* AOwner) : Tecanvas::TTeeButton(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TButtonGradient(HWND ParentWindow) : Tecanvas::TTeeButton(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TButtonGradient(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeMaxSampleGradient = 0x10;
extern PACKAGE bool __fastcall EditTeeGradient(Classes::TComponent* AOwner, Tecanvas::TCustomTeeGradient* AGradient)/* overload */;
extern PACKAGE bool __fastcall EditTeeGradient(Classes::TComponent* AOwner, Tecanvas::TCustomTeeGradient* AGradient, bool OnlyStart, bool HideVisible = false)/* overload */;

}	/* namespace Teeedigrad */
using namespace Teeedigrad;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiGrad
