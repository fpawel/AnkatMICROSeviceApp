// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MyPoint.pas' rev: 6.00

#ifndef MyPointHPP
#define MyPointHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mypoint
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMyPointSeries;
class PASCALIMPLEMENTATION TMyPointSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Tecanvas::TChartPen* FLinesPen;
	void __fastcall SetLinesPen(Tecanvas::TChartPen* Value);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TMyPointSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyPointSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Tecanvas::TChartPen* LinesPen = {read=FLinesPen, write=SetLinesPen};
};


class DELPHICLASS TBarJoinSeries;
class PASCALIMPLEMENTATION TBarJoinSeries : public Series::TBarSeries 
{
	typedef Series::TBarSeries inherited;
	
private:
	Tecanvas::TChartPen* FJoinPen;
	#pragma pack(push, 1)
	Types::TRect OldBarBounds;
	#pragma pack(pop)
	
	bool IFirstPoint;
	void __fastcall SetJoinPen(const Tecanvas::TChartPen* Value);
	
protected:
	virtual void __fastcall DoBeforeDrawChart(void);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TBarJoinSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TBarJoinSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	DYNAMIC int __fastcall NumSampleValues(void);
	
__published:
	__property Tecanvas::TChartPen* JoinPen = {read=FJoinPen, write=SetJoinPen};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mypoint */
using namespace Mypoint;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MyPoint
