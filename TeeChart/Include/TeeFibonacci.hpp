// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFibonacci.pas' rev: 6.00

#ifndef TeeFibonacciHPP
#define TeeFibonacciHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeToolSeriesEdit.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teefibonacci
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TFibonacciStyle { fsArc, fsFan };
#pragma option pop

class DELPHICLASS TFibonacciItem;
class PASCALIMPLEMENTATION TFibonacciItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Tecanvas::TChartPen* FPen;
	double FValue;
	void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetValue(const double Value);
	
public:
	__fastcall virtual TFibonacciItem(Classes::TCollection* Collection);
	__fastcall virtual ~TFibonacciItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property double Value = {read=FValue, write=SetValue};
};


class DELPHICLASS TFibonacciLevels;
class DELPHICLASS TFibonacciTool;
typedef DynamicArray<double >  TeeFibonacci__4;

class PASCALIMPLEMENTATION TFibonacciTool : public Teengine::TTeeCustomToolSeries 
{
	typedef Teengine::TTeeCustomToolSeries inherited;
	
private:
	TFibonacciStyle FDrawStyle;
	double FEndX;
	double FEndY;
	int FLabelsAngle;
	Tecanvas::TTeeFont* FLabelFont;
	TFibonacciLevels* FLevels;
	bool FShowLabels;
	double FStartX;
	double FStartY;
	Tecanvas::TChartPen* FTrendPen;
	DynamicArray<double >  IDefaultFab;
	#pragma pack(push, 1)
	Types::TPoint ISp;
	#pragma pack(pop)
	
	void __fastcall ClipDrawingRegion(void);
	void __fastcall SetDrawStyle(const TFibonacciStyle Value);
	void __fastcall SetEndX(const double Value);
	void __fastcall SetEndY(const double Value);
	void __fastcall SetLabelsAngle(const int Value);
	void __fastcall SetLabelsFont(const Tecanvas::TTeeFont* Value);
	void __fastcall SetShowLabels(const bool Value);
	void __fastcall SetStartX(const double Value);
	void __fastcall SetStartY(const double Value);
	void __fastcall SetTrendPen(const Tecanvas::TChartPen* Value);
	void __fastcall SetLevels(const TFibonacciLevels* Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	void __fastcall DrawLevel(int Index);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TFibonacciTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TFibonacciTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Types::TPoint __fastcall AxisPoint(const double X, const double Y);
	void __fastcall CreateDefaultLevels(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	double __fastcall Radius(void);
	
__published:
	__property Active  = {default=1};
	__property TFibonacciStyle DrawStyle = {read=FDrawStyle, write=SetDrawStyle, default=0};
	__property double EndX = {read=FEndX, write=SetEndX};
	__property double EndY = {read=FEndY, write=SetEndY};
	__property int LabelsAngle = {read=FLabelsAngle, write=SetLabelsAngle, default=90};
	__property Tecanvas::TTeeFont* LabelsFont = {read=FLabelFont, write=SetLabelsFont};
	__property TFibonacciLevels* Levels = {read=FLevels, write=SetLevels};
	__property Pen ;
	__property Series ;
	__property bool ShowLabels = {read=FShowLabels, write=SetShowLabels, default=1};
	__property double StartX = {read=FStartX, write=SetStartX};
	__property double StartY = {read=FStartY, write=SetStartY};
	__property Tecanvas::TChartPen* TrendPen = {read=FTrendPen, write=SetTrendPen};
};


class PASCALIMPLEMENTATION TFibonacciLevels : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TFibonacciItem* operator[](int Index) { return Level[Index]; }
	
private:
	TFibonacciTool* ITool;
	TFibonacciItem* __fastcall Get(int Index);
	void __fastcall Put(int Index, const TFibonacciItem* Value);
	
public:
	__property TFibonacciItem* Level[int Index] = {read=Get, write=Put/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TFibonacciLevels(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TFibonacciLevels(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFibonacciEditor;
class PASCALIMPLEMENTATION TFibonacciEditor : public Teetoolseriesedit::TSeriesToolEditor 
{
	typedef Teetoolseriesedit::TSeriesToolEditor inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Extctrls::TPanel* Panel2;
	Extctrls::TRadioGroup* RGStyle;
	Teependlg::TButtonPen* BTrendPen;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TEdit* EXStart;
	Stdctrls::TEdit* EYStart;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* EXEnd;
	Stdctrls::TEdit* EYEnd;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* BRemoveLevel;
	Stdctrls::TButton* Button3;
	Stdctrls::TGroupBox* GBLevels;
	Stdctrls::TEdit* ELevel;
	Comctrls::TUpDown* UDLevel;
	Stdctrls::TEdit* ELevelValue;
	Teependlg::TButtonPen* BLevelPen;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TCheckBox* CBLabels;
	Stdctrls::TButton* Button2;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* EAngle;
	Comctrls::TUpDown* UDAngle;
	HIDESBASE void __fastcall FormShow(System::TObject* Sender);
	void __fastcall RGStyleClick(System::TObject* Sender);
	void __fastcall CBLabelsClick(System::TObject* Sender);
	void __fastcall EXStartChange(System::TObject* Sender);
	void __fastcall EYStartChange(System::TObject* Sender);
	void __fastcall EXEndChange(System::TObject* Sender);
	void __fastcall EYEndChange(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ELevelChange(System::TObject* Sender);
	void __fastcall BRemoveLevelClick(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall EAngleChange(System::TObject* Sender);
	
private:
	TFibonacciTool* Fibonacci;
	void __fastcall SetLevel(int Index);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFibonacciEditor(Classes::TComponent* AOwner) : Teetoolseriesedit::TSeriesToolEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFibonacciEditor(Classes::TComponent* AOwner, int Dummy) : Teetoolseriesedit::TSeriesToolEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFibonacciEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFibonacciEditor(HWND ParentWindow) : Teetoolseriesedit::TSeriesToolEditor(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teefibonacci */
using namespace Teefibonacci;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFibonacci
