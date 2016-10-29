// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ImaPoint.pas' rev: 6.00

#ifndef ImaPointHPP
#define ImaPointHPP

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

namespace Imapoint
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomImagePointSeries;
typedef void __fastcall (__closure *TGetImageEvent)(TCustomImagePointSeries* Sender, int ValueIndex, Graphics::TPicture* Picture);

class PASCALIMPLEMENTATION TCustomImagePointSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Tecanvas::TTeePicture* FImagePoint;
	bool FImageTransp;
	TGetImageEvent FOnGetImage;
	void __fastcall SetImagePoint(const Tecanvas::TTeePicture* Value);
	void __fastcall SetImageTransp(const bool Value);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TCustomImagePointSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomImagePointSeries(void);
	__property Tecanvas::TTeePicture* ImagePoint = {read=FImagePoint, write=SetImagePoint};
	__property bool ImageTransparent = {read=FImageTransp, write=SetImageTransp, default=0};
	__property TGetImageEvent OnGetImage = {read=FOnGetImage, write=FOnGetImage};
};


class DELPHICLASS TImagePointSeries;
class PASCALIMPLEMENTATION TImagePointSeries : public TCustomImagePointSeries 
{
	typedef TCustomImagePointSeries inherited;
	
private:
	void __fastcall SetupFields(void);
	
public:
	__fastcall virtual TImagePointSeries(Classes::TComponent* AOwner);
	__fastcall virtual TImagePointSeries(Classes::TComponent* AOwner, Tecanvas::TTeePicture* Picture);
	
__published:
	__property ImagePoint ;
	__property ImageTransparent  = {default=1};
	__property OnGetImage ;
public:
	#pragma option push -w-inl
	/* TCustomImagePointSeries.Destroy */ inline __fastcall virtual ~TImagePointSeries(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDeltaImageStyle { disSmiles, disHands };
#pragma option pop

class DELPHICLASS TDeltaPointSeries;
class PASCALIMPLEMENTATION TDeltaPointSeries : public TCustomImagePointSeries 
{
	typedef TCustomImagePointSeries inherited;
	
private:
	Tecanvas::TTeePicture* FEqualImage;
	Tecanvas::TTeePicture* FGreaterImage;
	TDeltaImageStyle FImageStyle;
	Tecanvas::TTeePicture* FLowerImage;
	void __fastcall SetEqualImage(const Tecanvas::TTeePicture* Value);
	void __fastcall SetGreaterImage(const Tecanvas::TTeePicture* Value);
	void __fastcall SetImageStyle(const TDeltaImageStyle Value);
	void __fastcall SetLowerImage(const Tecanvas::TTeePicture* Value);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	
public:
	__fastcall virtual TDeltaPointSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TDeltaPointSeries(void);
	
__published:
	__property Tecanvas::TTeePicture* EqualImage = {read=FEqualImage, write=SetEqualImage};
	__property Tecanvas::TTeePicture* GreaterImage = {read=FGreaterImage, write=SetGreaterImage};
	__property TDeltaImageStyle ImageStyle = {read=FImageStyle, write=SetImageStyle, default=0};
	__property ImageTransparent  = {default=0};
	__property Tecanvas::TTeePicture* LowerImage = {read=FLowerImage, write=SetLowerImage};
	__property OnGetImage ;
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Imapoint */
using namespace Imapoint;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ImaPoint
