// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeCompressOHLC.pas' rev: 6.00

#ifndef TeeCompressOHLCHPP
#define TeeCompressOHLCHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeBaseFuncEdit.hpp>	// Pascal unit
#include <OHLChart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teecompressohlc
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCompressFuncEditor;
class PASCALIMPLEMENTATION TCompressFuncEditor : public Teebasefuncedit::TBaseFunctionEditor 
{
	typedef Teebasefuncedit::TBaseFunctionEditor inherited;
	
__published:
	Tecanvas::TComboFlat* CBDatePeriod;
	Stdctrls::TRadioButton* RadioDate;
	Stdctrls::TEdit* ENum;
	Stdctrls::TRadioButton* RadioPoints;
	Comctrls::TUpDown* UpDown1;
	Stdctrls::TRadioButton* RadioTime;
	Tecanvas::TComboFlat* CBTimePeriod;
	void __fastcall CBDatePeriodChange(System::TObject* Sender);
	void __fastcall RadioDateClick(System::TObject* Sender);
	void __fastcall RadioPointsClick(System::TObject* Sender);
	void __fastcall ENumChange(System::TObject* Sender);
	void __fastcall ENumClick(System::TObject* Sender);
	void __fastcall CBDatePeriodClick(System::TObject* Sender);
	void __fastcall RadioTimeClick(System::TObject* Sender);
	void __fastcall CBTimePeriodChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyFormChanges(void);
	virtual void __fastcall SetFunction(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCompressFuncEditor(Classes::TComponent* AOwner) : Teebasefuncedit::TBaseFunctionEditor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCompressFuncEditor(Classes::TComponent* AOwner, int Dummy) : Teebasefuncedit::TBaseFunctionEditor(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCompressFuncEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCompressFuncEditor(HWND ParentWindow) : Teebasefuncedit::TBaseFunctionEditor(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCompressionPeriod { ocDay, ocWeek, ocMonth, ocBiMonth, ocQuarter, ocYear, ocSecond, ocTenSecond, ocMinute, ocTwoMinutes, ocFiveMinutes, ocTenMinutes, ocFifteenMinutes, ocTwentyMinutes, ocHalfHour, ocHour, ocTwoHours, ocThreeHour, ocSixHour, ocTwelveHour };
#pragma option pop

typedef void __fastcall (__closure *TCompressGetDate)(Teengine::TTeeFunction* Sender, Teengine::TChartSeries* Source, int ValueIndex, System::TDateTime &Date);

class DELPHICLASS TCompressFunction;
class PASCALIMPLEMENTATION TCompressFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	TCompressionPeriod FCompress;
	TCompressGetDate FOnGetDate;
	void __fastcall SetCompress(const TCompressionPeriod Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	/* virtual class method */ virtual void __fastcall PrepareForGallery(TMetaClass* vmt, Teengine::TCustomAxisPanel* Chart);
	
public:
	__fastcall virtual TCompressFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	void __fastcall CompressSeries(Teengine::TChartSeries* Source, Ohlchart::TOHLCSeries* DestOHLC, Teengine::TChartSeries* Volume = (Teengine::TChartSeries*)(0x0), Teengine::TChartSeries* DestVolume = (Teengine::TChartSeries*)(0x0));
	
__published:
	__property TCompressionPeriod Compress = {read=FCompress, write=SetCompress, default=1};
	__property TCompressGetDate OnGetDate = {read=FOnGetDate, write=FOnGetDate};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCompressFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teecompressohlc */
using namespace Teecompressohlc;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeCompressOHLC
