// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEdiAxis.pas' rev: 6.00

#ifndef TeeEdiAxisHPP
#define TeeEdiAxisHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeCustomShapeEditor.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeEdiFont.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
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

namespace Teeediaxis
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFormTeeAxis;
class PASCALIMPLEMENTATION TFormTeeAxis : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageAxis;
	Comctrls::TTabSheet* TabScales;
	Comctrls::TTabSheet* TabTitle;
	Comctrls::TTabSheet* TabLabels;
	Comctrls::TTabSheet* TabTicks;
	Stdctrls::TLabel* L28;
	Stdctrls::TLabel* L29;
	Teependlg::TButtonPen* BAxisPen;
	Teependlg::TButtonPen* BTickPen;
	Teependlg::TButtonPen* BTickInner;
	Stdctrls::TEdit* SEAxisTickLength;
	Stdctrls::TEdit* SEInnerTicksLength;
	Stdctrls::TCheckBox* CBTickOnLabels;
	Comctrls::TUpDown* UDInnerTicksLength;
	Comctrls::TUpDown* UDAxisTickLength;
	Comctrls::TTabSheet* TabPositions;
	Stdctrls::TLabel* Label41;
	Stdctrls::TLabel* Label42;
	Stdctrls::TLabel* Label43;
	Stdctrls::TEdit* EPos;
	Stdctrls::TEdit* EStart;
	Stdctrls::TEdit* EEnd;
	Comctrls::TUpDown* UDPos;
	Comctrls::TUpDown* UDStart;
	Comctrls::TUpDown* UDEnd;
	Comctrls::TTabSheet* TabMinorTicks;
	Stdctrls::TLabel* L31;
	Stdctrls::TEdit* SEMinorCount;
	Comctrls::TUpDown* UDMinorCount;
	Teependlg::TButtonPen* BMinorGrid;
	Stdctrls::TCheckBox* CBOtherSide;
	Stdctrls::TCheckBox* CBHorizAxis;
	Comctrls::TPageControl* PageTitle;
	Comctrls::TTabSheet* TabTitleStyle;
	Stdctrls::TLabel* L14;
	Stdctrls::TEdit* ETitle;
	Stdctrls::TLabel* L3;
	Stdctrls::TEdit* SETitleAngle;
	Comctrls::TUpDown* UDTitleAngle;
	Stdctrls::TLabel* L9;
	Stdctrls::TEdit* SETitleSize;
	Comctrls::TUpDown* UDTitleSize;
	Stdctrls::TCheckBox* CBTitleVisible;
	Comctrls::TPageControl* PageLabels;
	Comctrls::TTabSheet* TabLabStyle;
	Stdctrls::TCheckBox* CBLabels;
	Stdctrls::TCheckBox* CBMultiline;
	Stdctrls::TCheckBox* CBOnAxis;
	Stdctrls::TCheckBox* CBRoundFirst;
	Stdctrls::TEdit* SELabelsSize;
	Stdctrls::TLabel* L26;
	Stdctrls::TLabel* L23;
	Stdctrls::TEdit* SELabelsAngle;
	Comctrls::TUpDown* UDLabelsAngle;
	Comctrls::TUpDown* UDLabelsSize;
	Stdctrls::TLabel* L20;
	Stdctrls::TEdit* SESepar;
	Comctrls::TUpDown* UDSepar;
	Comctrls::TTabSheet* TabLabelsFont;
	Extctrls::TPanel* Panel1;
	Comctrls::TTabSheet* TabLabFormat;
	Stdctrls::TLabel* LabelAxisFormat;
	Tecanvas::TComboFlat* CBFormat;
	Stdctrls::TCheckBox* CBExpo;
	Stdctrls::TCheckBox* CBLabelAlign;
	Extctrls::TSplitter* Splitter1;
	Extctrls::TPanel* Panel2;
	Buttons::TSpeedButton* BAdd;
	Buttons::TSpeedButton* BDelete;
	Extctrls::TPanel* Panel4;
	Stdctrls::TCheckBox* CBShow;
	Stdctrls::TCheckBox* CBAxisBeh;
	Stdctrls::TLabel* Label1;
	Stdctrls::TListBox* LBAxes;
	Stdctrls::TLabel* LabelZ;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDZ;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TCheckBox* CBAutoMax;
	Stdctrls::TButton* BAxisMax;
	Stdctrls::TLabel* LAxisMax;
	Stdctrls::TCheckBox* CBAutoMin;
	Stdctrls::TButton* BAxisMin;
	Stdctrls::TLabel* LAxisMin;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* EMinOff;
	Comctrls::TUpDown* UDMinOff;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* EMaxOff;
	Comctrls::TUpDown* UDMaxOff;
	Stdctrls::TLabel* Label7;
	Tecanvas::TComboFlat* CBPosUnits;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBLabelStyle;
	Stdctrls::TCheckBox* CBAlternate;
	Stdctrls::TButton* Button1;
	Teependlg::TButtonPen* BTickMinor;
	Stdctrls::TLabel* L30;
	Stdctrls::TEdit* SEAxisMinorTickLen;
	Comctrls::TUpDown* UDAxisMinorTickLen;
	Teependlg::TButtonPen* BAxisGrid;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDGridZ;
	Stdctrls::TCheckBox* CBGridCentered;
	Stdctrls::TLabel* Label8;
	Stdctrls::TEdit* EMarksEvery;
	Comctrls::TUpDown* UDEvery;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TButton* BIncre;
	Stdctrls::TLabel* L6;
	Stdctrls::TLabel* LAxisIncre;
	Comctrls::TTabSheet* TabSheet4;
	Stdctrls::TCheckBox* CBAutomatic;
	Stdctrls::TCheckBox* CBLogarithmic;
	Stdctrls::TCheckBox* CBVisible;
	Stdctrls::TCheckBox* CBInverted;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ELogBase;
	Stdctrls::TCheckBox* LogE;
	Stdctrls::TCheckBox* CBShowAll;
	Stdctrls::TCheckBox* CBMinRound;
	Stdctrls::TCheckBox* CBMaxRound;
	Comctrls::TTabSheet* TabTitleFormat;
	Comctrls::TPageControl* PageTitleFormat;
	Stdctrls::TLabel* Label9;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDMinorC;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall SEAxisTickLengthChange(System::TObject* Sender);
	void __fastcall CBAutomaticClick(System::TObject* Sender);
	void __fastcall ETitleChange(System::TObject* Sender);
	void __fastcall BAxisMaxClick(System::TObject* Sender);
	void __fastcall BAxisMinClick(System::TObject* Sender);
	void __fastcall BIncreClick(System::TObject* Sender);
	void __fastcall CBLogarithmicClick(System::TObject* Sender);
	void __fastcall SEInnerTicksLengthChange(System::TObject* Sender);
	void __fastcall SEAxisMinorTickLenChange(System::TObject* Sender);
	void __fastcall SEMinorCountChange(System::TObject* Sender);
	void __fastcall CBAutoMaxClick(System::TObject* Sender);
	void __fastcall CBInvertedClick(System::TObject* Sender);
	void __fastcall SETitleAngleChange(System::TObject* Sender);
	void __fastcall SETitleSizeChange(System::TObject* Sender);
	void __fastcall CBLabelsClick(System::TObject* Sender);
	void __fastcall SELabelsAngleChange(System::TObject* Sender);
	void __fastcall RGLabelStyleClick(System::TObject* Sender);
	void __fastcall SELabelsSizeChange(System::TObject* Sender);
	void __fastcall CBOnAxisClick(System::TObject* Sender);
	void __fastcall SESeparChange(System::TObject* Sender);
	void __fastcall CBRoundFirstClick(System::TObject* Sender);
	void __fastcall CBTickOnLabelsClick(System::TObject* Sender);
	void __fastcall CBGridCenteredClick(System::TObject* Sender);
	void __fastcall CBMultilineClick(System::TObject* Sender);
	void __fastcall PageAxisChange(System::TObject* Sender);
	void __fastcall CBShowClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageAxisChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall EPosChange(System::TObject* Sender);
	void __fastcall EStartChange(System::TObject* Sender);
	void __fastcall EEndChange(System::TObject* Sender);
	void __fastcall LBAxesClick(System::TObject* Sender);
	void __fastcall BAddClick(System::TObject* Sender);
	void __fastcall CBOtherSideClick(System::TObject* Sender);
	void __fastcall BDeleteClick(System::TObject* Sender);
	void __fastcall CBHorizAxisClick(System::TObject* Sender);
	void __fastcall ELogBaseChange(System::TObject* Sender);
	void __fastcall CBTitleVisibleClick(System::TObject* Sender);
	void __fastcall CBFormatChange(System::TObject* Sender);
	void __fastcall CBExpoClick(System::TObject* Sender);
	void __fastcall CBAxisBehClick(System::TObject* Sender);
	void __fastcall CBLabelAlignClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall EMinOffChange(System::TObject* Sender);
	void __fastcall EMaxOffChange(System::TObject* Sender);
	void __fastcall LogEClick(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall CBPosUnitsChange(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall CBAlternateClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall EMarksEveryChange(System::TObject* Sender);
	void __fastcall CBShowAllClick(System::TObject* Sender);
	void __fastcall CBMinRoundClick(System::TObject* Sender);
	void __fastcall CBMaxRoundClick(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall PageTitleFormatChange(System::TObject* Sender);
	void __fastcall PageLabelsChange(System::TObject* Sender);
	void __fastcall PageTitleChange(System::TObject* Sender);
	
private:
	bool CreatingForm;
	bool IChangingAuto;
	Teeedifont::TTeeFontEditor* ILabelsFont;
	Teecustomshapeeditor::TFormTeeShape* ITitleEditor;
	void __fastcall SetAxisIndex(void);
	void __fastcall SetAxisScales(void);
	void __fastcall EnableLogBaseControls(void);
	void __fastcall EditAxisMaxMin(const AnsiString ATitle, Stdctrls::TCheckBox* ACheckBox, bool IsMax);
	
public:
	Teengine::TChartAxis* TheAxis;
	Classes::TNotifyEvent NotifyCustom;
	__fastcall TFormTeeAxis(Classes::TComponent* Owner, Teengine::TChartAxis* AAxis);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeAxis(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeAxis(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeAxis(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeAxis(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeAddAxes(Teengine::TCustomAxisPanel* AChart, Classes::TStrings* AList, bool AddDepth);

}	/* namespace Teeediaxis */
using namespace Teeediaxis;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEdiAxis
