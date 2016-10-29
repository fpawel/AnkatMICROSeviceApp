// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeBezie.pas' rev: 6.00

#ifndef TeeBezieHPP
#define TeeBezieHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teebezie
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TBezierStyle { bsWindows, bsBezier3, bsBezier4 };
#pragma option pop

class DELPHICLASS TBezierSeries;
class PASCALIMPLEMENTATION TBezierSeries : public Series::TCustomSeries 
{
	typedef Series::TCustomSeries inherited;
	
private:
	TBezierStyle FBezierStyle;
	int FNumBezierPoints;
	void __fastcall SetBezierPoints(int Value);
	void __fastcall SetBezierStyle(const TBezierStyle Value);
	
protected:
	virtual void __fastcall DrawAllValues(void);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	
public:
	__fastcall virtual TBezierSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Active  = {default=1};
	__property ColorEachPoint  = {default=0};
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
	__property TBezierStyle BezierStyle = {read=FBezierStyle, write=SetBezierStyle, default=0};
	__property LinePen ;
	__property int NumBezierPoints = {read=FNumBezierPoints, write=SetBezierPoints, default=32};
	__property Pointer ;
	__property XValues ;
	__property YValues ;
	__property OnClickPointer ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TBezierSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teebezie */
using namespace Teebezie;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeBezie
