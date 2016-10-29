// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePDFCanvas.pas' rev: 6.00

#ifndef TeePDFCanvasHPP
#define TeePDFCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Math.hpp>	// Pascal unit
#include <TeeExport.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <jpeg.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepdfcanvas
{
//-- type declarations -------------------------------------------------------
struct TFontData;
typedef TFontData *PFontData;

#pragma pack(push, 1)
struct TFontData
{
	Types::TRect FontBBox;
	int FirstChar;
	int LastChar;
	int CapHeight;
	int Ascent;
	int Descent;
	int MaxWidth;
	int AvgWidth;
	int ItalicAngle;
	int DigAspX;
	int DigAspY;
	int CharWidths[256];
} ;
#pragma pack(pop)

#pragma option push -b-
enum TImageType { itJPEG, itBitmap, itUnknown };
#pragma option pop

class DELPHICLASS TTeePDFImageListEntry;
class PASCALIMPLEMENTATION TTeePDFImageListEntry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Graphics::TGraphic* FGraphic;
	int FHeight;
	int FObjectNumber;
	int FWidth;
	void __fastcall DefineImageData(void);
	int __fastcall GetDataLength(void);
	TImageType __fastcall GetImageType(void);
	void __fastcall SetObjectNumber(const int Value);
	
public:
	__fastcall TTeePDFImageListEntry(Graphics::TGraphic* AGraphic);
	__fastcall virtual ~TTeePDFImageListEntry(void);
	void __fastcall WriteDataToStream(Classes::TStream* AStream);
	__property int DataLength = {read=GetDataLength, nodefault};
	__property int Height = {read=FHeight, nodefault};
	__property TImageType ImageType = {read=GetImageType, nodefault};
	__property int ObjectNumber = {read=FObjectNumber, write=SetObjectNumber, nodefault};
	__property int Width = {read=FWidth, nodefault};
};


class DELPHICLASS TTeePDFImageList;
class PASCALIMPLEMENTATION TTeePDFImageList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* IImageList;
	bool __fastcall EqualImages(Graphics::TGraphic* i1, Graphics::TGraphic* i2);
	int __fastcall GetCount(void);
	TTeePDFImageListEntry* __fastcall GetImageEntry(int Index);
	
public:
	__fastcall TTeePDFImageList(void);
	__fastcall virtual ~TTeePDFImageList(void);
	int __fastcall AddItem(Graphics::TGraphic* AGraphic);
	int __fastcall Find(Graphics::TGraphic* AGraphic);
	__property TTeePDFImageListEntry* Items[int Index] = {read=GetImageEntry};
	__property int ItemsCount = {read=GetCount, nodefault};
};


class DELPHICLASS TTeePDFFontListEntry;
class PASCALIMPLEMENTATION TTeePDFFontListEntry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	#pragma pack(push, 1)
	TFontData FFontData;
	#pragma pack(pop)
	
	AnsiString FPDFName;
	int FObjectNumber;
	void __fastcall DefineFontData(Graphics::TFont* AFont);
	void __fastcall SetObjectNumber(const int Value);
	
public:
	__fastcall TTeePDFFontListEntry(Graphics::TFont* AFont);
	__property AnsiString PDFName = {read=FPDFName};
	__property int ObjectNumber = {read=FObjectNumber, write=SetObjectNumber, nodefault};
	__property TFontData FontData = {read=FFontData};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeePDFFontListEntry(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeePDFFontList;
class PASCALIMPLEMENTATION TTeePDFFontList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* IFontList;
	TTeePDFFontListEntry* __fastcall GetFontEntry(int Index);
	int __fastcall GetCount(void);
	
public:
	__fastcall TTeePDFFontList(void);
	__fastcall virtual ~TTeePDFFontList(void);
	__property TTeePDFFontListEntry* Items[int Index] = {read=GetFontEntry};
	__property int ItemsCount = {read=GetCount, nodefault};
	int __fastcall AddItem(Graphics::TFont* AFont, HDC AHandle);
	int __fastcall Find(Graphics::TFont* AFont);
};


class DELPHICLASS TPDFChartObject;
class PASCALIMPLEMENTATION TPDFChartObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FContents;
	TTeePDFFontList* FFontArray;
	TTeePDFImageList* FImageArray;
	int __fastcall GetLength(void);
	
public:
	__fastcall TPDFChartObject(void);
	__fastcall virtual ~TPDFChartObject(void);
	void __fastcall SaveToStream(Classes::TStream* AStream);
	__property Classes::TStream* Contents = {read=FContents};
	__property int Length = {read=GetLength, nodefault};
	__property TTeePDFFontList* FontArray = {read=FFontArray};
	__property TTeePDFImageList* ImageArray = {read=FImageArray};
};


class DELPHICLASS TTeePDFPage;
class PASCALIMPLEMENTATION TTeePDFPage : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int IObjCount;
	int CatalogNum;
	int ParentNum;
	int ResourceNum;
	AnsiString tmpSt;
	Classes::TStringList* OffsetList;
	TPDFChartObject* FChartObject;
	int XRefPos;
	int FPageHeight;
	int FPageWidth;
	void __fastcall AddToOffset(int Offset);
	void __fastcall SetPageHeight(const int Value);
	void __fastcall SetPageWidth(const int Value);
	void __fastcall WriteHeader(Classes::TStream* AStream);
	void __fastcall WriteInfo(Classes::TStream* AStream);
	void __fastcall WriteTTFonts(Classes::TStream* AStream);
	void __fastcall WriteImages(Classes::TStream* AStream);
	void __fastcall WriteResources(Classes::TStream* AStream);
	void __fastcall WritePages(Classes::TStream* AStream);
	void __fastcall WritePage(Classes::TStream* AStream);
	void __fastcall WriteCatalog(Classes::TStream* AStream);
	void __fastcall WriteXRef(Classes::TStream* AStream);
	void __fastcall WriteTrailer(Classes::TStream* AStream);
	
public:
	__fastcall TTeePDFPage(void);
	__fastcall virtual ~TTeePDFPage(void);
	void __fastcall SaveToStream(Classes::TStream* AStream);
	__property int PageWidth = {read=FPageWidth, write=SetPageWidth, nodefault};
	__property int PageHeight = {read=FPageHeight, write=SetPageHeight, nodefault};
	__property TPDFChartObject* ChartObject = {read=FChartObject};
};


class DELPHICLASS TPDFCanvas;
class PASCALIMPLEMENTATION TPDFCanvas : public Tecanvas::TTeeCanvas3D 
{
	typedef Tecanvas::TTeeCanvas3D inherited;
	
private:
	Graphics::TColor FBackColor;
	Tecanvas::TCanvasBackMode FBackMode;
	int FTextAlign;
	int IWidth;
	int IHeight;
	double FX;
	double FY;
	AnsiString tmpSt;
	bool FEmbeddedFonts;
	Classes::TStream* FCStream;
	TPDFChartObject* FContents;
	int IClipStack;
	Graphics::TPenStyle IPenStyle;
	int IPenWidth;
	AnsiString __fastcall BrushProperties();
	void __fastcall ChangedPen(System::TObject* Sender);
	AnsiString __fastcall FontProperties(Tecanvas::TTeeFont* Font, int &FontIndex);
	AnsiString __fastcall InternalBezCurve(const double ax1, const double ay1, const double ax2, const double ay2, const double ax3, const double ay3);
	void __fastcall InternalDrawArc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, bool MoveTo0, bool DrawPie);
	void __fastcall InternalDrawImage(const double sx, const double sy, const double tx, const double ty, int ImageIndex);
	void __fastcall InternalRect(const Types::TRect &Rect, bool UsePen, bool IsRound);
	AnsiString __fastcall PenProperties();
	AnsiString __fastcall PointToStr(double X, double Y);
	int __fastcall SelectFont(Graphics::TFont* Font);
	int __fastcall SelectImage(Graphics::TGraphic* Graphic);
	void __fastcall SetEmbeddedFonts(const bool Value);
	AnsiString __fastcall SetPenStyle(Graphics::TPenStyle PenStyle);
	AnsiString __fastcall TextToPDFText(const AnsiString AText);
	AnsiString __fastcall TheBounds();
	void __fastcall TranslateVertCoord(double &Y);
	
protected:
	virtual void __fastcall SetTextAlign(int Align);
	virtual int __fastcall GetTextAlign(void);
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual Tecanvas::TCanvasBackMode __fastcall GetBackMode(void);
	virtual bool __fastcall GetMonochrome(void);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual void __fastcall SetBackMode(Tecanvas::TCanvasBackMode Mode);
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	virtual bool __fastcall GetIsNoBMPGrid(void);
	
public:
	__fastcall TPDFCanvas(TPDFChartObject* AChartObject);
	__fastcall virtual ~TPDFCanvas(void);
	virtual Types::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, Tecanvas::TView3DOptions* A3DOptions, Graphics::TColor ABackColor, bool Is3D, const Types::TRect &UserRect);
	virtual void __fastcall AssignVisiblePenColor(Graphics::TPen* APen, Graphics::TColor AColor);
	virtual Tecanvas::TTeeBlend* __fastcall BeginBlending(const Types::TRect &R, Tecanvas::TTeeTransparency Transparency);
	virtual void __fastcall EndBlending(Tecanvas::TTeeBlend* Blend);
	void __fastcall WriteToStream(Classes::TStream* AStream);
	virtual int __fastcall TextWidth(const AnsiString St)/* overload */;
	virtual int __fastcall TextHeight(const AnsiString St)/* overload */;
	virtual void __fastcall Arc(const int Left, const int Top, const int Right, const int Bottom, const int StartX, const int StartY, const int EndX, const int EndY)/* overload */;
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic);
	virtual void __fastcall FillRect(const Types::TRect &Rect);
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	virtual void __fastcall LineTo(int X, int Y)/* overload */;
	virtual void __fastcall MoveTo(int X, int Y)/* overload */;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1)/* overload */;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3)/* overload */;
	virtual void __fastcall StretchDraw(const Types::TRect &Rect, Graphics::TGraphic* Graphic)/* overload */;
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text)/* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect)/* overload */;
	virtual void __fastcall ClipRectangle(const Types::TRect &Rect, int RoundSize)/* overload */;
	virtual void __fastcall UnClipRectangle(void);
	virtual void __fastcall GradientFill(const Types::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor EndColor, Tecanvas::TGradientDirection Direction, int Balance = 0x32, int RadialX = 0x0, int RadialY = 0x0);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, double RotDegree);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, double RotDegree);
	virtual void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size);
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, const Types::TRect &UserRect);
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z)/* overload */;
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
	__property bool EmbeddedFonts = {read=FEmbeddedFonts, write=SetEmbeddedFonts, default=0};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  TextWidth(const WideString St){ return TTeeCanvas::TextWidth(St); }
	inline int __fastcall  TextHeight(const WideString St){ return TTeeCanvas::TextHeight(St); }
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
	inline void __fastcall  EllipseWithZ(const Types::TRect &Rect, int Z){ TCanvas3D::EllipseWithZ(Rect, Z); }
	
};


class DELPHICLASS TPDFExportFormat;
class PASCALIMPLEMENTATION TPDFExportFormat : public Teeexport::TTeeExportFormat 
{
	typedef Teeexport::TTeeExportFormat inherited;
	
protected:
	virtual void __fastcall DoCopyToClipboard(void);
	
public:
	virtual AnsiString __fastcall Description();
	virtual AnsiString __fastcall FileExtension();
	virtual AnsiString __fastcall FileFilter();
	TTeePDFPage* __fastcall PDFPage(void);
	TPDFChartObject* __fastcall ChartObject(void);
	virtual Forms::TForm* __fastcall Options(bool Check = true);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TTeeExportFormat.Create */ inline __fastcall virtual TPDFExportFormat(void) : Teeexport::TTeeExportFormat() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeExportFormat.Destroy */ inline __fastcall virtual ~TPDFExportFormat(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall WriteStringToStream(Classes::TStream* Stream, const AnsiString S);
extern PACKAGE void __fastcall TeeSaveToPDFFile(Teeprocs::TCustomTeePanel* APanel, const WideString FileName, int AWidth = 0x0, int AHeight = 0x0);

}	/* namespace Teepdfcanvas */
using namespace Teepdfcanvas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePDFCanvas
