// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeThemes.pas' rev: 6.00

#ifndef TeeThemesHPP
#define TeeThemesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeTools.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teethemes
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDefaultTheme;
class PASCALIMPLEMENTATION TDefaultTheme : public Chart::TChartTheme 
{
	typedef Chart::TChartTheme inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	void __fastcall ChangeSeries(Teengine::TChartSeries* Series);
	void __fastcall ChangeWall(Chart::TChartWall* Wall, Graphics::TColor AColor);
	void __fastcall ResetGradient(Tecanvas::TTeeGradient* Gradient);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TDefaultTheme(Chart::TCustomChart* AChart) : Chart::TChartTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TDefaultTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExcelTheme;
class PASCALIMPLEMENTATION TExcelTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TExcelTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TExcelTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClassicTheme;
class PASCALIMPLEMENTATION TClassicTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TClassicTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TClassicTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBusinessTheme;
class PASCALIMPLEMENTATION TBusinessTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TBusinessTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TBusinessTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebTheme;
class PASCALIMPLEMENTATION TWebTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TWebTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TWebTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowsXPTheme;
class PASCALIMPLEMENTATION TWindowsXPTheme : public TBusinessTheme 
{
	typedef TBusinessTheme inherited;
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TWindowsXPTheme(Chart::TCustomChart* AChart) : TBusinessTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TWindowsXPTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBlueSkyTheme;
class PASCALIMPLEMENTATION TBlueSkyTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TBlueSkyTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TBlueSkyTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFactsTheme;
class PASCALIMPLEMENTATION TFactsTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
private:
	Teetools::TGridBandTool* FBands;
	Teetools::TGridBandTool* __fastcall GetBands(void);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
	__property Teetools::TGridBandTool* Bands = {read=GetBands};
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TFactsTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TFactsTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRandomTheme;
class PASCALIMPLEMENTATION TRandomTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
protected:
	virtual void __fastcall ChangeAxis(Teengine::TChartAxis* Axis);
	bool __fastcall RandomBoolean(void);
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
	/*         class method */ static Graphics::TColor __fastcall RandomColor(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TRandomTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TRandomTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOperaTheme;
class PASCALIMPLEMENTATION TOperaTheme : public TDefaultTheme 
{
	typedef TDefaultTheme inherited;
	
public:
	virtual void __fastcall Apply(void);
	virtual AnsiString __fastcall Description();
public:
	#pragma option push -w-inl
	/* TChartTheme.Create */ inline __fastcall virtual TOperaTheme(Chart::TCustomChart* AChart) : TDefaultTheme(AChart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TOperaTheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS TThemesList;
class PASCALIMPLEMENTATION TThemesList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TMetaClass* operator[](int Index) { return Theme[Index]; }
	
private:
	TMetaClass* __fastcall GetTheme(int Index);
	
public:
	__property TMetaClass* Theme[int Index] = {read=GetTheme/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TThemesList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TThemesList(void) : Classes::TList() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TThemesList* ChartThemes;
extern PACKAGE void __fastcall ApplyChartTheme(TMetaClass* Theme, Chart::TCustomChart* Chart)/* overload */;
extern PACKAGE void __fastcall ApplyChartTheme(TMetaClass* Theme, Chart::TCustomChart* Chart, int PaletteIndex)/* overload */;
extern PACKAGE void __fastcall RegisterChartThemes(TMetaClass* * Themes, const int Themes_Size);

}	/* namespace Teethemes */
using namespace Teethemes;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeThemes
