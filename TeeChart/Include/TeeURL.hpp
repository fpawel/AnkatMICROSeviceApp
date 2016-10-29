// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeURL.pas' rev: 6.00

#ifndef TeeURLHPP
#define TeeURLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeurl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomChartLink;
class PASCALIMPLEMENTATION TCustomChartLink : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Chart::TCustomChart* FChart;
	void __fastcall SetChart(const Chart::TCustomChart* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomChartLink(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomChartLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeSeriesSourceFile;
class PASCALIMPLEMENTATION TTeeSeriesSourceFile : public Teengine::TTeeSeriesSource 
{
	typedef Teengine::TTeeSeriesSource inherited;
	
private:
	AnsiString FFileName;
	void __fastcall SetFileName(const AnsiString Value);
	
public:
	virtual void __fastcall Load(void);
	void __fastcall LoadFromFile(const AnsiString AFileName);
	virtual void __fastcall LoadFromStream(Classes::TStream* AStream);
	void __fastcall LoadFromURL(const AnsiString AURL);
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
public:
	#pragma option push -w-inl
	/* TTeeSeriesSource.Create */ inline __fastcall virtual TTeeSeriesSourceFile(Classes::TComponent* AOwner) : Teengine::TTeeSeriesSource(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TTeeSeriesSource.Destroy */ inline __fastcall virtual ~TTeeSeriesSourceFile(void) { }
	#pragma option pop
	
};


class DELPHICLASS TImportChart;
class PASCALIMPLEMENTATION TImportChart : public TCustomChartLink 
{
	typedef TCustomChartLink inherited;
	
private:
	bool FKeepPosition;
	bool FKeepSize;
	Classes::TNotifyEvent FOnLoaded;
	Classes::TNotifyEvent FOnLoading;
	void __fastcall CheckChart(void);
	void __fastcall CheckPosition(const Types::TRect &Rect);
	
public:
	__fastcall virtual TImportChart(Classes::TComponent* AOwner);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(const Classes::TStream* Stream);
	void __fastcall LoadFromURL(const AnsiString URL);
	
__published:
	__property Chart ;
	__property bool KeepPosition = {read=FKeepPosition, write=FKeepPosition, default=1};
	__property bool KeepSize = {read=FKeepSize, write=FKeepSize, default=1};
	__property Classes::TNotifyEvent OnLoaded = {read=FOnLoaded, write=FOnLoaded};
	__property Classes::TNotifyEvent OnLoading = {read=FOnLoading, write=FOnLoading};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TImportChart(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartWebSource;
class PASCALIMPLEMENTATION TChartWebSource : public TImportChart 
{
	typedef TImportChart inherited;
	
private:
	AnsiString FURL;
	
public:
	__fastcall virtual TChartWebSource(Classes::TComponent* AOwner);
	void __fastcall Execute(void);
	
__published:
	__property AnsiString URL = {read=FURL, write=FURL};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TChartWebSource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE unsigned TeeWinInetDLL;
extern PACKAGE void __fastcall LoadChartFromURL(Chart::TCustomChart* &AChart, const AnsiString URL);
extern PACKAGE HRESULT __fastcall DownloadURL(char * AURL, Classes::TStream* ToStream);
extern PACKAGE AnsiString __fastcall TeeURLErrorMessage(int ErrorCode);
extern PACKAGE bool __fastcall TeeIsURL(AnsiString St);

}	/* namespace Teeurl */
using namespace Teeurl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeURL
