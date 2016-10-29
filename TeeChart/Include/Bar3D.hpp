// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Bar3D.pas' rev: 6.00

#ifndef Bar3DHPP
#define Bar3DHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Bar3d
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBar3DSeries;
class PASCALIMPLEMENTATION TBar3DSeries : public Series::TBarSeries 
{
	typedef Series::TBarSeries inherited;
	
private:
	Teengine::TChartValueList* FOffsetValues;
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	void __fastcall SetOffsetValues(Teengine::TChartValueList* Value);
	/* virtual class method */ virtual bool __fastcall SubGalleryStack(TMetaClass* vmt);
	
public:
	__fastcall virtual TBar3DSeries(Classes::TComponent* AOwner);
	HIDESBASE int __fastcall AddBar(const double AX, const double AY, const double AOffset, const AnsiString AXLabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual double __fastcall GetOriginValue(int ValueIndex);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall PointOrigin(int ValueIndex, bool SumAll);
	
__published:
	__property Teengine::TChartValueList* OffsetValues = {read=FOffsetValues, write=SetOffsetValues};
public:
	#pragma option push -w-inl
	/* TCustomBarSeries.Destroy */ inline __fastcall virtual ~TBar3DSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Bar3d */
using namespace Bar3d;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Bar3D
