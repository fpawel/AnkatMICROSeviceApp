// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGLCanvas.pas' rev: 6.00

#ifndef TeeGLCanvasHPP
#define TeeGLCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeConst.hpp>	// Pascal unit
#include <OpenGL2.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeglcanvas
{
//-- type declarations -------------------------------------------------------
typedef float GLMat[4];

#pragma pack(push, 1)
struct TGLFontCache
{
	int Offset;
	AnsiString Name;
	int Weight;
	Graphics::TFontStyles Style;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TGLFontStyle { fsNormal, fsOutline, fsBitmap };
#pragma option pop

typedef TGLFontCache TeeGLCanvas__2[11];

class DELPHICLASS TGLCanvas;
class PASCALIMPLEMENTATION TGLCanvas : public Tecanvas::TCanvas3D 
{
	typedef Tecanvas::TCanvas3D inherited;
	
private:
	Graphics::TColor FBackColor;
	Tecanvas::TCanvasBackMode FBackMode;
	int FDepth;
	int FTextAlign;
	int FWidth;
	int FHeight;
	Classes::TNotifyEvent FOnInit;
	HDC FDC;
	HGLRC HRC;
	int FX;
	int FY;
	int FZ;
	bool FIs3D;
	TGLFontCache FontCache[11];
	int INumFonts;
	bool FUseBuffer;
	Graphics::TCanvas* IDestCanvas;
	bool IDrawToBitmap;
	unsigned FSavedError;
	Opengl2::TGLUQuadric *FQuadric;
	bool IAntiAlias;
	bool IQuadricTexture;
	double __fastcall CalcZoom(void);
	void __fastcall DeleteTextures(void);
	void __fastcall DestroyGLContext(void);
	void __fastcall DoProjection(void);
	unsigned __fastcall FindTexture(Graphics::TBitmap* ABitmap);
	int __fastcall FontWeight(void);
	HDC __fastcall GetDCHandle(void);
	void __fastcall InitMatrix(void);
	void __fastcall InternalRectangle(const Types::TRect &Rect);
	Opengl2::PGLUQuadric __fastcall Quadric(void);
	void __fastcall InternalCylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D, int ConePercent);
	
protected:
	float ITransp;
	void __fastcall CreateFontOutlines(int Index);
	void __fastcall InitOpenGLFont(void);
	void __fastcall InitAmbientLight(int AmbientLight);
	void __fastcall InitLight(int Num, const float * AColor, const Tecanvas::TPoint3DFloat &Position, const Tecanvas::TPoint3DFloat &Direction, bool UseDirection, const double SpotDegrees);
	void __fastcall EndBrushBitmap(void)/* overload */;
	void __fastcall EndBrushBitmap(Graphics::TBitmap* Bitmap)/* overload */;
	void __fastcall SetBrushBitmap(void)/* overload */;
	bool __fastcall SetBrushBitmap(Graphics::TBitmap* Bitmap)/* overload */;
	void __fastcall SetDrawStyle(Tecanvas::TTeeCanvasSurfaceStyle Value);
	void __fastcall SetShininess(const double Value);
	virtual Tecanvas::TCanvasBackMode __fastcall GetBackMode(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual HDC __fastcall GetHandle(void);
	virtual bool __fastcall GetMonochrome(void);
	virtual Graphics::TColor __fastcall GetPixel(int x, int y);
	virtual Graphics::TColor __fastcall GetPixel3D(int X, int Y, int Z);
	virtual bool __fastcall GetSupports3DText(void);
	virtual bool __fastcall GetSupportsFullRotation(void);
	virtual bool __fastcall GetIsNoBMPGrid(void);
	virtual int __fastcall GetTextAlign(void);
	virtual bool __fastcall GetUseBuffer(void);
	void __fastcall SetAntiAlias(const bool Value);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual void __fastcall SetBackMode(Tecanvas::TCanvasBackMode Mode);
	virtual void __fastcall SetMonochrome(bool Value);
	void __fastcall SetPen(void)/* overload */;
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	virtual void __fastcall SetTextAlign(int Align);
	virtual void __fastcall SetUseBuffer(bool Value);
	void __fastcall TeeNormal(const int x, const int y, const int z);
	void __fastcall TeeVertex2D(const int x, const int y);
	void __fastcall TeeVertex3D(const int x, const int y, const int z);
	
public:
	Tecanvas::TTeeCanvasSurfaceStyle DrawStyle;
	int FontExtrusion;
	TGLFontStyle FontStyle;
	bool ShadeQuality;
	__fastcall TGLCanvas(void);
	__fastcall virtual ~TGLCanvas(void);
	bool __fastcall CheckGLError(void);
	void __fastcall DeleteFont(void);
	void __fastcall Repaint(void);
	virtual void __fastcall DisableRotation(void);
	virtual void __fastcall EnableRotation(void);
	void __fastcall SetMaterialColor(void);
	virtual Tecanvas::TTeeBlend* __fastcall BeginBlending(const Types::TRect &R, Tecanvas::TTeeTransparency Transparency);
	virtual void __fastcall EndBlending(Tecanvas::TTeeBlend* Blend);
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY)/* overload */;
	virtual void __fastcall Donut(int XCenter, int YCenter, int XRadius, int YRadius, const double StartAngle, const double EndAngle, const double HolePercent);
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic);
	virtual void __fastcall EraseBackground(const Types::TRect &Rect);
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	virtual void __fastcall FillRect(const Types::TRect &Rect);
	virtual void __fastcall LineTo(int X, int Y)/* overload */;
	virtual void __fastcall MoveTo(int X, int Y)/* overload */;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1)/* overload */;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3)/* overload */;
	void __fastcall SetColor(const Graphics::TColor AColor);
	void __fastcall SetPen(Graphics::TPen* APen)/* overload */;
	virtual void __fastcall StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic)/* overload */;
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text)/* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect)/* overload */;
	virtual void __fastcall ClipCube(const Types::TRect &Rect, int MinZ, int MaxZ);
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, Tecanvas::TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size)/* overload */;
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, double RotDegree);
	virtual void __fastcall UnClipRectangle(void);
	HIDESBASE Types::TPoint __fastcall Calculate2DPosition(const double x, const double y, const double z)/* overload */;
	virtual void __fastcall Calculate2DPosition(int &x, int &y, int z)/* overload */;
	virtual Types::TPoint __fastcall Calculate3DPosition(int x, int y, int z)/* overload */;
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, Tecanvas::TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect);
	virtual void __fastcall Projection(int MaxDepth, const Types::TRect &Bounds, const Types::TRect &Rect);
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect);
	virtual bool __fastcall ReDrawBitmap(void);
	virtual void __fastcall Arrow(bool Filled, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight, int Z, const double ArrowPercent)/* overload */;
	virtual void __fastcall Cone(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool Dark3D, int ConePercent);
	virtual void __fastcall Cube(int Left, int Right, int Top, int Bottom, int Z0, int Z1, bool DarkSides)/* overload */;
	virtual void __fastcall Cylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1, bool DarkCover);
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z)/* overload */;
	virtual void __fastcall LineTo3D(int X, int Y, int Z)/* overload */;
	virtual void __fastcall LineWithZ(int X0, int Y0, int X1, int Y1, int Z)/* overload */;
	virtual void __fastcall MoveTo3D(int X, int Y, int Z)/* overload */;
	virtual void __fastcall Pie3D(int XCenter, int YCenter, int XRadius, int YRadius, int Z0, int Z1, const double StartAngle, const double EndAngle, bool DarkSides, bool DrawSides, int DonutPercent = 0x0, Tecanvas::TCustomTeeGradient* Gradient = (Tecanvas::TCustomTeeGradient*)(0x0));
	virtual void __fastcall Plane3D(const Types::TPoint &A, const Types::TPoint &B, int Z0, int Z1);
	virtual void __fastcall PlaneWithZ(const Types::TPoint &P1, const Types::TPoint &P2, const Types::TPoint &P3, const Types::TPoint &P4, int Z)/* overload */;
	virtual void __fastcall PlaneFour3D(Types::TPoint * Points, int Z0, int Z1);
	virtual void __fastcall Polygon3D(const Tecanvas::TPoint3D * Points, const int Points_Size);
	virtual void __fastcall PolygonWithZ(const Types::TPoint * Points, const int Points_Size, int Z);
	virtual void __fastcall Pyramid(bool Vertical, int Left, int Top, int Right, int Bottom, int z0, int z1, bool DarkSides);
	virtual void __fastcall PyramidTrunc(const Types::TRect &R, int StartZ, int EndZ, int TruncX, int TruncZ);
	virtual void __fastcall RectangleWithZ(const Types::TRect &Rect, int Z);
	virtual void __fastcall RectangleY(int Left, int Top, int Right, int Z0, int Z1);
	virtual void __fastcall RectangleZ(int Left, int Top, int Bottom, int Z0, int Z1);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, double RotDegree);
	virtual void __fastcall Sphere(int x, int y, int z, const double Radius)/* overload */;
	HIDESBASE void __fastcall Sphere(const double x, const double y, const double z, const double Radius)/* overload */;
	virtual void __fastcall Surface3D(Tecanvas::TTeeCanvasSurfaceStyle Style, bool SameBrush, int NumXValues, int NumZValues, Tecanvas::TTeeCanvasCalcPoints CalcPoints);
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
	virtual void __fastcall Triangle3D(const Tecanvas::TPoint3D * Points, const Graphics::TColor * Colors);
	virtual void __fastcall TriangleWithZ(const Types::TPoint &P1, const Types::TPoint &P2, const Types::TPoint &P3, int Z);
	__property Classes::TNotifyEvent OnInit = {read=FOnInit, write=FOnInit};
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Arc(const int Left, const int Top, const int Right, const int Bottom, double StartAngle, double EndAngle){ TTeeCanvas::Arc(Left, Top, Right, Bottom, StartAngle, EndAngle); }
	inline void __fastcall  Ellipse(const Types::TRect &R){ TTeeCanvas::Ellipse(R); }
	inline void __fastcall  LineTo(const Types::TPoint &P){ TTeeCanvas::LineTo(P); }
	inline void __fastcall  MoveTo(const Types::TPoint &P){ TTeeCanvas::MoveTo(P); }
	inline void __fastcall  Rectangle(const Types::TRect &R, int Z){ TCanvas3D::Rectangle(R, Z); }
	inline void __fastcall  Rectangle(int X0, int Y0, int X1, int Y1, int Z){ TCanvas3D::Rectangle(X0, Y0, X1, Y1, Z); }
	inline void __fastcall  Rectangle(const Types::TRect &R){ TTeeCanvas::Rectangle(R); }
	inline void __fastcall  RoundRect(const Types::TRect &R, int X, int Y){ TTeeCanvas::RoundRect(R, X, Y); }
	inline void __fastcall  StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic, int Pos, Tecanvas::TCanvas3DPlane Plane = (Tecanvas::TCanvas3DPlane)(0x2)){ TCanvas3D::StretchDraw(Rect, Graphic, Pos, Plane); }
	inline void __fastcall  TextOut(int X, int Y, const AnsiString Text, bool AllowHtml){ TTeeCanvas::TextOut(X, Y, Text, AllowHtml); }
	inline void __fastcall  ClipRectangle(const Types::TRect &Rect, int RoundSize){ TTeeCanvas::ClipRectangle(Rect, RoundSize); }
	inline void __fastcall  Polyline(const Types::TPoint * Points, const int Points_Size, int Z){ TCanvas3D::Polyline(Points, Points_Size, Z); }
	inline Types::TPoint __fastcall  Calculate3DPosition(const Tecanvas::TPoint3D &P){ return TCanvas3D::Calculate3DPosition(P); }
	inline Types::TPoint __fastcall  Calculate3DPosition(const Types::TPoint &P, int z){ return TCanvas3D::Calculate3DPosition(P, z); }
	inline void __fastcall  Arrow(bool Filled, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight, int Z){ TCanvas3D::Arrow(Filled, FromPoint, ToPoint, ArrowWidth, ArrowHeight, Z); }
	inline void __fastcall  Arrow(bool Filled, const double ArrowPercent, const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int ArrowWidth, int ArrowHeight){ TTeeCanvas::Arrow(Filled, ArrowPercent, FromPoint, ToPoint, ArrowWidth, ArrowHeight); }
	inline void __fastcall  Cube(const Types::TRect &R, int Z0, int Z1, bool DarkSides = true){ TCanvas3D::Cube(R, Z0, Z1, DarkSides); }
	inline void __fastcall  EllipseWithZ(const Types::TRect &Rect, int Z){ TCanvas3D::EllipseWithZ(Rect, Z); }
	inline void __fastcall  LineTo3D(const Tecanvas::TPoint3D &P){ TCanvas3D::LineTo3D(P); }
	inline void __fastcall  LineWithZ(const Types::TPoint &FromPoint, const Types::TPoint &ToPoint, int Z){ TCanvas3D::LineWithZ(FromPoint, ToPoint, Z); }
	inline void __fastcall  MoveTo3D(const Tecanvas::TPoint3D &P){ TCanvas3D::MoveTo3D(P); }
	inline void __fastcall  PlaneWithZ(const Types::TPoint * P, int Z){ TCanvas3D::PlaneWithZ(P, Z); }
	
};


class DELPHICLASS TGLShape;
class PASCALIMPLEMENTATION TGLShape : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Tecanvas::TChartBrush* FBrush;
	Tecanvas::TChartPen* FPen;
	Graphics::TBitmap* IBitmap;
	void __fastcall SetBrush(const Tecanvas::TChartBrush* Value);
	void __fastcall SetPen(const Tecanvas::TChartPen* Value);
	
protected:
	void __fastcall EndBrush(void);
	void __fastcall PopMatrix(void);
	void __fastcall PrepareBrush(void)/* overload */;
	void __fastcall PrepareBrush(Tecanvas::TChartBrush* ABrush)/* overload */;
	void __fastcall PreparePen(void);
	void __fastcall PushMatrix(void);
	
public:
	TGLCanvas* Canvas;
	double Rotation;
	double Elevation;
	double Tilt;
	__fastcall virtual TGLShape(TGLCanvas* ACanvas);
	__fastcall virtual ~TGLShape(void);
	virtual void __fastcall Draw(const double X, const double Y, const double Z);
	__property Tecanvas::TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
};


typedef DynamicArray<double >  TeeGLCanvas__5;

class DELPHICLASS TGLTorus;
class PASCALIMPLEMENTATION TGLTorus : public TGLShape 
{
	typedef TGLShape inherited;
	
private:
	Classes::TNotifyEvent FOnFill;
	
public:
	double StartAngle;
	double TotalAngle;
	double Inner;
	double XRadius;
	double YRadius;
	int Rings;
	int Sides;
	Tecanvas::TChartPen* EndPen;
	Tecanvas::TChartBrush* StartSide;
	Tecanvas::TChartBrush* EndSide;
	DynamicArray<double >  Inners;
	DynamicArray<double >  SideAngles;
	int BevelFactor;
	__fastcall virtual TGLTorus(TGLCanvas* ACanvas);
	virtual void __fastcall Draw(const double X, const double Y, const double Z);
	__property Classes::TNotifyEvent OnFill = {read=FOnFill, write=FOnFill};
public:
	#pragma option push -w-inl
	/* TGLShape.Destroy */ inline __fastcall virtual ~TGLTorus(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE char *TeeOpenGLFontName;
extern PACKAGE double TeeMaterialAmbient;
extern PACKAGE double TeeMaterialDiffuse;
extern PACKAGE double TeeMaterialSpecular;
extern PACKAGE double TeeMaterialEmission;
extern PACKAGE unsigned TeeFullLightModel;
extern PACKAGE unsigned TeeLightLocal;
extern PACKAGE unsigned TeeColorPlanes;
extern PACKAGE int TeeTextAngleY;
extern PACKAGE int TeeTextAngleZ;
extern PACKAGE double TeeTextWidthFactor;
extern PACKAGE double TeeTextHeightFactor;
extern PACKAGE int TeeDefaultLightSpot;
extern PACKAGE int TeeSphereSlices;
extern PACKAGE int TeeSphereStacks;
extern PACKAGE int TeeCylinderStacks;
extern PACKAGE unsigned TeeSmoothQuality;
extern PACKAGE unsigned TeePerspectiveQuality;
extern PACKAGE bool TeeWrapTextures;
static const Byte TeeFontListRange = 0xe1;
static const Shortint TeeMaxFonts = 0xa;
extern PACKAGE void __fastcall ColorToGL(Graphics::TColor AColor, float * C);

}	/* namespace Teeglcanvas */
using namespace Teeglcanvas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGLCanvas
