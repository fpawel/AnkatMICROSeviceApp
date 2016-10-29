// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeTagCloud.pas' rev: 6.00

#ifndef TeeTagCloudHPP
#define TeeTagCloudHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEdiGrad.hpp>	// Pascal unit
#include <TeeBrushDlg.hpp>	// Pascal unit
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeChartGrid.hpp>	// Pascal unit
#include <TeeSurfa.hpp>	// Pascal unit
#include <TeeGriEd.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teetagcloud
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTagCloudSeries;
typedef void __fastcall (__closure *TDrawTagEvent)(TTagCloudSeries* Sender, int ValueIndex);

#pragma option push -b-
enum TTagCloudOrder { toText, toValue, toNone };
#pragma option pop

typedef DynamicArray<Types::TRect >  TeeTagCloud__2;

class PASCALIMPLEMENTATION TTagCloudSeries : public Teesurfa::TCustom3DPaletteSeries 
{
	typedef Teesurfa::TCustom3DPaletteSeries inherited;
	
private:
	AnsiString FFilter;
	Tecanvas::TTeeFont* FFont;
	Tecanvas::TTeeGradient* FGradient;
	int FSeparation;
	TDrawTagEvent FOnDrawTag;
	void __fastcall SetFilter(const AnsiString Value);
	void __fastcall SetFont(const Tecanvas::TTeeFont* Value);
	void __fastcall SetGradient(const Tecanvas::TTeeGradient* Value);
	void __fastcall SetSeparation(const int Value);
	bool __fastcall ShouldDraw(int ValueIndex);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DrawAllValues(void);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	DynamicArray<Types::TRect >  Positions;
	__fastcall virtual TTagCloudSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TTagCloudSeries(void);
	int __fastcall AddTag(const AnsiString Text, const double Value);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual int __fastcall Clicked(int X, int Y)/* overload */;
	int __fastcall GetTagFontSize(int ValueIndex);
	void __fastcall Sort(TTagCloudOrder SortBy, Teengine::TChartListOrder Order = (Teengine::TChartListOrder)(0x1));
	virtual bool __fastcall UseAxis(void);
	
__published:
	__property AnsiString Filter = {read=FFilter, write=SetFilter};
	__property Tecanvas::TTeeFont* Font = {read=FFont, write=SetFont};
	__property Tecanvas::TTeeGradient* Gradient = {read=FGradient, write=SetGradient};
	__property int TagSeparation = {read=FSeparation, write=SetSeparation, default=5};
	__property Active  = {default=1};
	__property ColorSource ;
	__property Cursor  = {default=0};
	__property HorizAxis  = {default=1};
	__property Marks ;
	__property ParentChart ;
	__property DataSource ;
	__property PercentFormat ;
	__property SeriesColor ;
	__property ShowInLegend  = {default=1};
	__property Title ;
	__property ValueFormat ;
	__property VertAxis  = {default=0};
	__property XLabelsSource ;
	__property AfterDrawValues ;
	__property BeforeDrawValues ;
	__property OnAfterAdd ;
	__property OnBeforeAdd ;
	__property OnClearValues ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnGetMarkText ;
	__property OnMouseEnter ;
	__property OnMouseLeave ;
	__property Brush ;
	__property EndColor  = {default=16777215};
	__property MidColor  = {default=536870911};
	__property LegendEvery  = {default=1};
	__property Pen ;
	__property PaletteMin ;
	__property PaletteStep ;
	__property PaletteSteps  = {default=32};
	__property PaletteStyle  = {default=0};
	__property StartColor  = {default=8388608};
	__property UseColorRange  = {default=1};
	__property UsePalette  = {default=0};
	__property UsePaletteMin  = {default=0};
	__property XValues ;
	__property YValues ;
	__property TDrawTagEvent OnDrawTag = {read=FOnDrawTag, write=FOnDrawTag};
	__property OnGetColor ;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS TTagCloudEditor;
class PASCALIMPLEMENTATION TTagCloudEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabFont;
	Comctrls::TTabSheet* TabOptions;
	Stdctrls::TLabel* Label1;
	Stdctrls::TEdit* EFilter;
	Stdctrls::TCheckBox* CBClip;
	Teependlg::TButtonPen* ButtonPen1;
	Comctrls::TTabSheet* TabGradient;
	Stdctrls::TButton* Button1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* ESep;
	Comctrls::TUpDown* UDSep;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall EFilterChange(System::TObject* Sender);
	void __fastcall CBClipClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ESepChange(System::TObject* Sender);
	
private:
	TTagCloudSeries* TagCloud;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTagCloudEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTagCloudEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTagCloudEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTagCloudEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teetagcloud */
using namespace Teetagcloud;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeTagCloud
