// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ImageBar.pas' rev: 6.00

#ifndef ImageBarHPP
#define ImageBarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <TeeFilters.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Imagebar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TImageBarSeries;
class PASCALIMPLEMENTATION TImageBarSeries : public Series::TBarSeries 
{
	typedef Series::TBarSeries inherited;
	
private:
	Tecanvas::TTeePicture* FImage;
	bool FImageTiled;
	bool FImageTransp;
	void __fastcall DrawTiled(const Types::TRect &R, bool StartFromTop);
	void __fastcall SetImage(const Tecanvas::TTeePicture* Value);
	void __fastcall SetImageTiled(const bool Value);
	void __fastcall SetImageTransp(const bool Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	
public:
	__fastcall virtual TImageBarSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TImageBarSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	
__published:
	__property Tecanvas::TTeePicture* Image = {read=FImage, write=SetImage};
	__property bool ImageTiled = {read=FImageTiled, write=SetImageTiled, default=0};
	__property bool ImageTransparent = {read=FImageTransp, write=SetImageTransp, default=0};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall LoadBitmapFromResourceName(Graphics::TBitmap* ABitmap, const AnsiString ResName);

}	/* namespace Imagebar */
using namespace Imagebar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ImageBar
