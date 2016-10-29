// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeOpenGL.pas' rev: 6.00

#ifndef TeeOpenGLHPP
#define TeeOpenGLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeGLCanvas.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeopengl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGLPosition;
class PASCALIMPLEMENTATION TGLPosition : public Tecanvas::TFloatXYZ 
{
	typedef Tecanvas::TFloatXYZ inherited;
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLPosition(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TGLPosition(void) : Tecanvas::TFloatXYZ() { }
	#pragma option pop
	
};


class DELPHICLASS TGLLight;
class DELPHICLASS TTeeOpenGL;
class DELPHICLASS TGLLightSource;
class PASCALIMPLEMENTATION TGLLight : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Graphics::TColor FColor;
	bool FVisible;
	TTeeOpenGL* IOwner;
	
protected:
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetVisible(bool Value);
	
public:
	__fastcall TGLLight(TTeeOpenGL* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall GLColor(float * Value);
	
__published:
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=12632256};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLLight(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TGLLightSource : public TGLLight 
{
	typedef TGLLight inherited;
	
private:
	TGLPosition* FDirection;
	bool FFixedPos;
	TGLPosition* FPosition;
	double FSpotDegrees;
	bool FUseDirection;
	void __fastcall SetFixed(const bool Value);
	void __fastcall SetSpotDegrees(const double Value);
	void __fastcall SetUseDirection(const bool Value);
	
protected:
	void __fastcall SetDirection(const TGLPosition* Value);
	void __fastcall SetPosition(const TGLPosition* Value);
	
public:
	__fastcall TGLLightSource(TTeeOpenGL* AOwner);
	__fastcall virtual ~TGLLightSource(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TGLPosition* Direction = {read=FDirection, write=SetDirection};
	__property bool FixedPosition = {read=FFixedPos, write=SetFixed, default=0};
	__property TGLPosition* Position = {read=FPosition, write=SetPosition};
	__property double SpotDegrees = {read=FSpotDegrees, write=SetSpotDegrees};
	__property bool UseDirection = {read=FUseDirection, write=SetUseDirection, default=0};
};


class PASCALIMPLEMENTATION TTeeOpenGL : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	int FAmbientLight;
	bool FAntialias;
	int FFontExtrusion;
	bool FFontOutlines;
	TGLLightSource* FLight0;
	TGLLightSource* FLight1;
	TGLLightSource* FLight2;
	bool FShadeQuality;
	double FShininess;
	Teeprocs::TCustomTeePanel* FTeePanel;
	Tecanvas::TTeeCanvasSurfaceStyle FDrawStyle;
	Classes::TNotifyEvent FOnInit;
	Classes::TNotifyEvent FOnRepaint;
	void __fastcall Activate(void);
	void __fastcall Changed(System::TObject* Sender);
	Teeglcanvas::TGLCanvas* __fastcall GetCanvas(void);
	void __fastcall OnCanvasInit(System::TObject* Sender);
	void __fastcall SetActive(bool Value);
	void __fastcall SetAmbientLight(int Value);
	void __fastcall SetAntialias(bool Value);
	void __fastcall SetDoubleProperty(double &Variable, const double Value);
	void __fastcall SetDrawStyle(const Tecanvas::TTeeCanvasSurfaceStyle Value);
	void __fastcall SetFontExtrusion(int Value);
	void __fastcall SetFontOutlines(bool Value);
	void __fastcall SetLightSource0(TGLLightSource* Value);
	void __fastcall SetLightSource1(TGLLightSource* Value);
	void __fastcall SetLightSource2(TGLLightSource* Value);
	void __fastcall SetShadeQuality(bool Value);
	void __fastcall SetShininess(const double Value);
	void __fastcall SetTeePanel(Teeprocs::TCustomTeePanel* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall Repaint(void);
	
public:
	__fastcall virtual TTeeOpenGL(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeeOpenGL(void);
	__property Teeglcanvas::TGLCanvas* Canvas = {read=GetCanvas};
	__property TGLLightSource* Light0 = {read=FLight0};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property int AmbientLight = {read=FAmbientLight, write=SetAmbientLight, nodefault};
	__property bool Antialias = {read=FAntialias, write=SetAntialias, default=0};
	__property Tecanvas::TTeeCanvasSurfaceStyle DrawStyle = {read=FDrawStyle, write=SetDrawStyle, default=0};
	__property int FontExtrusion = {read=FFontExtrusion, write=SetFontExtrusion, default=0};
	__property bool FontOutlines = {read=FFontOutlines, write=SetFontOutlines, default=0};
	__property TGLLightSource* Light = {read=FLight0, write=SetLightSource0};
	__property TGLLightSource* Light1 = {read=FLight1, write=SetLightSource1};
	__property TGLLightSource* Light2 = {read=FLight2, write=SetLightSource2};
	__property bool ShadeQuality = {read=FShadeQuality, write=SetShadeQuality, default=1};
	__property double Shininess = {read=FShininess, write=SetShininess};
	__property Teeprocs::TCustomTeePanel* TeePanel = {read=FTeePanel, write=SetTeePanel};
	__property Classes::TNotifyEvent OnInit = {read=FOnInit, write=FOnInit};
	__property Classes::TNotifyEvent OnRepaint = {read=FOnRepaint, write=FOnRepaint};
};



//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeopengl */
using namespace Teeopengl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeOpenGL
