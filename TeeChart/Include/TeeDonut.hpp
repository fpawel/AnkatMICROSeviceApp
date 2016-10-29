// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeDonut.pas' rev: 6.00

#ifndef TeeDonutHPP
#define TeeDonutHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Series.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedonut
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDonutSeries;
class PASCALIMPLEMENTATION TDonutSeries : public Series::TPieSeries 
{
	typedef Series::TPieSeries inherited;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TDonutSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property DonutPercent  = {default=50};
public:
	#pragma option push -w-inl
	/* TPieSeries.Destroy */ inline __fastcall virtual ~TDonutSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeDefaultDonutPercent = 0x32;

}	/* namespace Teedonut */
using namespace Teedonut;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeDonut
