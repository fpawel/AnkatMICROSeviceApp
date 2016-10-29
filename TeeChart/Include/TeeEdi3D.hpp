// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdi3D.pas' rev: 6.00

#ifndef TeeEdi3DHPP
#define TeeEdi3DHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeGalleryPanel.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teeedi3d
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTee3D;
class PASCALIMPLEMENTATION TFormTee3D : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* Tab3D;
	Comctrls::TTabSheet* TabViews;
	Stdctrls::TLabel* L13;
	Stdctrls::TLabel* L4;
	Stdctrls::TLabel* L35;
	Stdctrls::TLabel* L36;
	Stdctrls::TLabel* LZoom;
	Stdctrls::TLabel* LRotation;
	Stdctrls::TLabel* LElevation;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* LHOffset;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* LVOffset;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* LPerspec;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* LTextSize;
	Stdctrls::TCheckBox* CBView3d;
	Stdctrls::TEdit* SE3d;
	Stdctrls::TCheckBox* CBOrthogonal;
	Comctrls::TTrackBar* SBZoom;
	Comctrls::TTrackBar* SBRotation;
	Comctrls::TTrackBar* SBElevation;
	Comctrls::TTrackBar* SBHOffset;
	Comctrls::TTrackBar* SBVOffset;
	Comctrls::TUpDown* UD3D;
	Stdctrls::TCheckBox* CBZoomText;
	Comctrls::TTrackBar* SBPerspec;
	Stdctrls::TEdit* EOrthoAngle;
	Comctrls::TUpDown* UDOrthoAngle;
	Stdctrls::TCheckBox* CBClipPoints;
	Stdctrls::TEdit* ETextSize;
	Comctrls::TUpDown* UDTextSize;
	Teegallerypanel::TChartGalleryPanel* ChartGalleryPanel1;
	void __fastcall CBOrthogonalClick(System::TObject* Sender);
	void __fastcall SBZoomChange(System::TObject* Sender);
	void __fastcall SBRotationChange(System::TObject* Sender);
	void __fastcall SBElevationChange(System::TObject* Sender);
	void __fastcall CBView3dClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SBHOffsetChange(System::TObject* Sender);
	void __fastcall SBVOffsetChange(System::TObject* Sender);
	void __fastcall SE3dChange(System::TObject* Sender);
	void __fastcall CBZoomTextClick(System::TObject* Sender);
	void __fastcall SBPerspecChange(System::TObject* Sender);
	void __fastcall EOrthoAngleChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CBClipPointsClick(System::TObject* Sender);
	void __fastcall ETextSizeChange(System::TObject* Sender);
	void __fastcall ChartGalleryPanel1ChangeChart(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	
private:
	bool AllowRotation;
	bool Changing;
	Chart::TCustomChart* TheChart;
	void __fastcall CreateViewsGallery(void);
	int __fastcall GetRotation(void);
	void __fastcall RefreshOptions(void);
	void __fastcall Select3DChart(Chart::TCustomChart* AChart);
	void __fastcall SetGallery3DChart(Chart::TCustomChart* AChart);
	
public:
	bool ResetTab3D;
	__fastcall TFormTee3D(Classes::TComponent* AOwner, Chart::TCustomChart* AChart);
	void __fastcall CheckControls(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTee3D(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTee3D(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTee3D(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTee3D(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeedi3d */
using namespace Teeedi3d;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdi3D
