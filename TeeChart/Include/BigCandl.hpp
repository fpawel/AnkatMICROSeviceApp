// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BigCandl.pas' rev: 6.00

#ifndef BigCandlHPP
#define BigCandlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <CandleCh.hpp>	// Pascal unit
#include <OHLChart.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
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

namespace Bigcandl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBigCandleSeries;
class PASCALIMPLEMENTATION TBigCandleSeries : public Candlech::TCandleSeries 
{
	typedef Candlech::TCandleSeries inherited;
	
private:
	int FHorizGap;
	int FVertGap;
	
protected:
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	void __fastcall SetHorizGap(int Value);
	void __fastcall SetVertGap(int Value);
	
public:
	__fastcall virtual TBigCandleSeries(Classes::TComponent* AOwner);
	
__published:
	__property int HorizGap = {read=FHorizGap, write=SetHorizGap, nodefault};
	__property int VertGap = {read=FVertGap, write=SetVertGap, nodefault};
public:
	#pragma option push -w-inl
	/* TCandleSeries.Destroy */ inline __fastcall virtual ~TBigCandleSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Bigcandl */
using namespace Bigcandl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BigCandl
