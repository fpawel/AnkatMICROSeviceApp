// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeEditPro.pas' rev: 6.00

#ifndef TeeEditProHPP
#define TeeEditProHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeeditpro
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartImage;
class PASCALIMPLEMENTATION TChartImage : public Graphics::TGraphic 
{
	typedef Graphics::TGraphic inherited;
	
private:
	Chart::TChart* FChart;
	bool FCustom;
	Chart::TChart* __fastcall GetChart(void);
	void __fastcall SetChart(const Chart::TChart* Value);
	
protected:
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall Draw(Graphics::TCanvas* ACanvas, const Types::TRect &Rect);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TChartImage(void);
	__fastcall virtual ~TChartImage(void);
	void __fastcall Clear(void);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall SaveToFile(const AnsiString Filename);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Chart::TChart* Chart = {read=GetChart, write=SetChart};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall SaveChartDialog(Chart::TCustomChart* AChart);
extern PACKAGE void __fastcall EditOneSeries(Controls::TControl* AOwner, Teengine::TChartSeries* ASeries);

}	/* namespace Teeeditpro */
using namespace Teeeditpro;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeEditPro
