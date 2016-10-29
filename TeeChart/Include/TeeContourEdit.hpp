// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeContourEdit.pas' rev: 6.00

#ifndef TeeContourEditHPP
#define TeeContourEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
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

namespace Teecontouredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TContourSeriesEditor;
class PASCALIMPLEMENTATION TContourSeriesEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CBAutoLevels;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* SENum;
	Comctrls::TUpDown* UDNum;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Extctrls::TShape* SHColor;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* ELevel;
	Comctrls::TUpDown* UDLevel;
	Stdctrls::TEdit* EValue;
	Teependlg::TButtonPen* BLevelPen;
	Stdctrls::TCheckBox* cbDefaultPen;
	Teependlg::TButtonPen* Button2;
	Stdctrls::TCheckBox* CBColorEach;
	Stdctrls::TCheckBox* CBSmooth;
	Stdctrls::TCheckBox* CBInterpolate;
	Stdctrls::TCheckBox* CBFill;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBMarksSegments;
	Stdctrls::TCheckBox* CBMarksColor;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Tecanvas::TButtonColor* BMarksColor;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDDensity;
	Comctrls::TUpDown* UDMargin;
	Stdctrls::TCheckBox* CBMarks;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDTransp;
	Comctrls::TTabSheet* TabPointer;
	Stdctrls::TCheckBox* CBEmpty;
	Stdctrls::TScrollBar* SBLevel;
	Teependlg::TButtonPen* BFrame;
	Comctrls::TTabSheet* TabSheet4;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* SEYPos;
	Stdctrls::TCheckBox* CBYPosLevel;
	Stdctrls::TCheckBox* CBBottom;
	Stdctrls::TCheckBox* CBOverlap;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall SENumChange(System::TObject* Sender);
	void __fastcall CBYPosLevelClick(System::TObject* Sender);
	void __fastcall SEYPosChange(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall CBAutoLevelsClick(System::TObject* Sender);
	void __fastcall SHColorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ELevelChange(System::TObject* Sender);
	void __fastcall EValueChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BLevelPenClick(System::TObject* Sender);
	void __fastcall cbDefaultPenClick(System::TObject* Sender);
	void __fastcall CBSmoothClick(System::TObject* Sender);
	void __fastcall CBInterpolateClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBFillClick(System::TObject* Sender);
	void __fastcall CBMarksColorClick(System::TObject* Sender);
	void __fastcall CBMarksSegmentsClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall CBMarksClick(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall CBEmptyClick(System::TObject* Sender);
	void __fastcall SBLevelChange(System::TObject* Sender);
	void __fastcall CBBottomClick(System::TObject* Sender);
	void __fastcall CBOverlapClick(System::TObject* Sender);
	
private:
	Teesurfa::TContourSeries* Contour;
	bool CreatingForm;
	Forms::TCustomForm* Grid3DForm;
	void __fastcall CheckBottom(void);
	void __fastcall DoCreateAutoLevels(void);
	Teesurfa::TContourLevel* __fastcall Level(void);
	void __fastcall SetLevel(void);
	Graphics::TColor __fastcall VisualColor(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TContourSeriesEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TContourSeriesEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TContourSeriesEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TContourSeriesEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecontouredit */
using namespace Teecontouredit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeContourEdit
