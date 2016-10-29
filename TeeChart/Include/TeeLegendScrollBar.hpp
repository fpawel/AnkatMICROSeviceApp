// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLegendScrollBar.pas' rev: 6.00

#ifndef TeeLegendScrollBarHPP
#define TeeLegendScrollBarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeeTools.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teelegendscrollbar
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollThumbStyle { stsCustom, stsThumb1, stsThumb2, stsThumb3, stsThumb4 };
#pragma option pop

class DELPHICLASS TScrollBarThumb;
class PASCALIMPLEMENTATION TScrollBarThumb : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Tecanvas::TChartBrush* FBrush;
	Tecanvas::TTeeGradient* FGradient;
	Tecanvas::TTeePicture* FImage;
	int FSize;
	TScrollThumbStyle FStyle;
	Teengine::TTeeCustomTool* IScroll;
	void __fastcall SetBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetImage(const Tecanvas::TTeePicture* Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetStyle(const TScrollThumbStyle Value);
	
public:
	__fastcall TScrollBarThumb(Teengine::TTeeCustomTool* AOwner);
	__fastcall virtual ~TScrollBarThumb(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Tecanvas::TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Tecanvas::TTeePicture* Image = {read=FImage, write=SetImage};
	__property int Size = {read=FSize, write=SetSize, default=0};
	__property TScrollThumbStyle Style = {read=FStyle, write=SetStyle, default=0};
};


#pragma option push -b-
enum TTeeScrollBarDrawStyle { dsAlways, dsWhenNeeded };
#pragma option pop

class DELPHICLASS TTeeScrollBar;
typedef void __fastcall (__closure *TSetPositionEvent)(TTeeScrollBar* Sender, int Value);

class PASCALIMPLEMENTATION TTeeScrollBar : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	#pragma pack(push, 1)
	Types::TPoint P1;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint P2;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint P3;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint P4;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint P5;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint P6;
	#pragma pack(pop)
	
	TTeeScrollBarDrawStyle FDrawStyle;
	int FInitial;
	int ThumbBegin;
	int ThumbEnd;
	TScrollBarThumb* FThumb;
	Extctrls::TTimer* FTimer;
	Classes::TNotifyEvent FOnScrolled;
	bool FInThumb;
	bool FInDec;
	bool FInInc;
	bool FirstTime;
	#pragma pack(push, 1)
	Types::TPoint OldPoint;
	#pragma pack(pop)
	
	bool FHorizontal;
	Controls::TBevelCut FBevel;
	#pragma pack(push, 1)
	Types::TRect R;
	#pragma pack(pop)
	
	bool FAutoRepeat;
	int FSize;
	Tecanvas::TChartBrush* FArrowBrush;
	int FPosition;
	TSetPositionEvent FOnSetPosition;
	Tecanvas::TTeeGradient* FGradient;
	Classes::TNotifyEvent FOnChangeSize;
	int FMinSize;
	bool FDecOutline;
	bool FIncOutline;
	void __fastcall ApplyScroll(double Delta, bool ActivateTimer);
	bool __fastcall ClickedDec(const Types::TPoint &P);
	bool __fastcall ClickedInc(const Types::TPoint &P);
	bool __fastcall ClickedThumb(const Types::TPoint &P);
	Types::TRect __fastcall DecRectangle();
	void __fastcall DoScroll(void);
	void __fastcall DoTimer(System::TObject* Sender);
	void __fastcall DrawDecArrow(void);
	void __fastcall DrawDecOutline(void);
	void __fastcall DrawIncArrow(void);
	void __fastcall DrawIncOutline(void);
	Graphics::TColor __fastcall GetBackColor(void);
	Tecanvas::TChartBrush* __fastcall GetThumbBrush(void);
	int __fastcall GetThumbSize(void);
	void __fastcall HideDecOutline(void);
	void __fastcall HideIncOutline(void);
	Types::TRect __fastcall IncRectangle();
	void __fastcall MouseMove(int X, int Y);
	void __fastcall MouseUp(void);
	void __fastcall PrepareOutline(void);
	void __fastcall ProcessClick(const Types::TPoint &P);
	void __fastcall SetArrowBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetBackColor(const Graphics::TColor Value);
	void __fastcall SetBevel(const Controls::TBevelCut Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetHorizontal(const bool Value);
	void __fastcall SetMinSize(const int Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetThumb(const TScrollBarThumb* Value);
	void __fastcall SetThumbBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetThumbSize(const int Value);
	Types::TRect __fastcall ThumbRectangle();
	
protected:
	int Max;
	int ThumbLength;
	virtual double __fastcall CalcDelta(int A, int B);
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	virtual void __fastcall ChartMouseEvent(Teengine::TChartMouseEvent AEvent, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual int __fastcall CurrentCount(void);
	virtual int __fastcall DeltaMain(void);
	virtual int __fastcall GetPosition(void);
	void __fastcall Draw(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetPosition(int Value);
	virtual bool __fastcall ShouldDraw(Types::TRect &R);
	virtual int __fastcall TotalCount(void);
	
public:
	__fastcall virtual TTeeScrollBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeeScrollBar(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	Types::TRect __fastcall MainRectangle();
	Types::TRect __fastcall ScrollRectangle();
	__property bool Horizontal = {read=FHorizontal, write=SetHorizontal, default=0};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	
__published:
	__property Active  = {default=1};
	__property Tecanvas::TChartBrush* ArrowBrush = {read=FArrowBrush, write=SetArrowBrush};
	__property bool AutoRepeat = {read=FAutoRepeat, write=FAutoRepeat, default=1};
	__property Graphics::TColor BackColor = {read=GetBackColor, write=SetBackColor, nodefault};
	__property Controls::TBevelCut Bevel = {read=FBevel, write=SetBevel, default=2};
	__property Brush ;
	__property TTeeScrollBarDrawStyle DrawStyle = {read=FDrawStyle, write=FDrawStyle, nodefault};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property int InitialDelay = {read=FInitial, write=FInitial, default=250};
	__property int MinThumbSize = {read=FMinSize, write=SetMinSize, default=4};
	__property Pen ;
	__property int Size = {read=FSize, write=SetSize, default=18};
	__property TScrollBarThumb* Thumb = {read=FThumb, write=SetThumb};
	__property Tecanvas::TChartBrush* ThumbBrush = {read=GetThumbBrush, write=SetThumbBrush};
	__property int ThumbSize = {read=GetThumbSize, write=SetThumbSize, default=0};
	__property Classes::TNotifyEvent OnChangeSize = {read=FOnChangeSize, write=FOnChangeSize};
	__property Classes::TNotifyEvent OnScrolled = {read=FOnScrolled, write=FOnScrolled};
	__property TSetPositionEvent OnSetPosition = {read=FOnSetPosition, write=FOnSetPosition};
};


class DELPHICLASS TLegendScrollBar;
class PASCALIMPLEMENTATION TLegendScrollBar : public TTeeScrollBar 
{
	typedef TTeeScrollBar inherited;
	
private:
	Chart::TCustomChartLegend* L;
	bool __fastcall HasPaging(void);
	void __fastcall LegendCalcSize(Chart::TCustomChartLegend* Sender, int &ASize);
	void __fastcall SetLegendEvent(Chart::TLegendCalcSize Value);
	
protected:
	virtual int __fastcall CurrentCount(void);
	virtual int __fastcall DeltaMain(void);
	virtual int __fastcall GetPosition(void);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	virtual void __fastcall SetPosition(int Value);
	virtual bool __fastcall ShouldDraw(Types::TRect &R);
	virtual int __fastcall TotalCount(void);
	
public:
	__fastcall virtual ~TLegendScrollBar(void);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TTeeScrollBar.Create */ inline __fastcall virtual TLegendScrollBar(Classes::TComponent* AOwner) : TTeeScrollBar(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TScrollbarEditor;
class PASCALIMPLEMENTATION TScrollbarEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TButton* Button1;
	Teeedigrad::TButtonGradient* BThumbGrad;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TCheckBox* CBAuto;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDSize;
	Stdctrls::TEdit* Edit2;
	Comctrls::TUpDown* UDDelay;
	Teependlg::TButtonPen* ButtonPen1;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button3;
	Tecanvas::TButtonColor* ButtonColor1;
	Teeedigrad::TButtonGradient* BGradient;
	Stdctrls::TLabel* Label4;
	Stdctrls::TEdit* Edit3;
	Comctrls::TUpDown* UDThumbSize;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TButton* BBrowse;
	Stdctrls::TButton* BFilters;
	Stdctrls::TLabel* Label1;
	Tecanvas::TComboFlat* ComboBox1;
	Tecanvas::TComboFlat* CBStyle;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall ComboBox1Change(System::TObject* Sender);
	void __fastcall CBAutoClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall Edit3Change(System::TObject* Sender);
	void __fastcall BFiltersClick(System::TObject* Sender);
	void __fastcall BBrowseClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	
private:
	TTeeScrollBar* TeeScroll;
	void __fastcall EnableFilters(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TScrollbarEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TScrollbarEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TScrollbarEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TScrollbarEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint DefaultScrollBarSize = 0x12;

}	/* namespace Teelegendscrollbar */
using namespace Teelegendscrollbar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLegendScrollBar
