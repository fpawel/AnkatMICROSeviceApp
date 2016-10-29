// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeHighLowLine.pas' rev: 6.00

#ifndef TeeHighLowLineHPP
#define TeeHighLowLineHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <ErrorBar.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
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

namespace Teehighlowline
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THighLowLineSeries;
class PASCALIMPLEMENTATION THighLowLineSeries : public Errorbar::TBaseHighLowSeries 
{
	typedef Errorbar::TBaseHighLowSeries inherited;
	
private:
	Teengine::TSeriesPointer* FHighPointer;
	Teengine::TSeriesPointer* FLowPointer;
	void __fastcall SetHighPointer(const Teengine::TSeriesPointer* Value);
	void __fastcall SetLowPointer(const Teengine::TSeriesPointer* Value);
	
protected:
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual THighLowLineSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~THighLowLineSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	
__published:
	__property Teengine::TSeriesPointer* HighPointer = {read=FHighPointer, write=SetHighPointer};
	__property Teengine::TSeriesPointer* LowPointer = {read=FLowPointer, write=SetLowPointer};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


class DELPHICLASS THighLowLineEditor;
class PASCALIMPLEMENTATION THighLowLineEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Teependlg::TButtonPen* BPen;
	Stdctrls::TCheckBox* CBColorEach;
	Tecanvas::TButtonColor* BColor;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	
private:
	THighLowLineSeries* HighLow;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual THighLowLineEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual THighLowLineEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~THighLowLineEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THighLowLineEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teehighlowline */
using namespace Teehighlowline;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeHighLowLine
