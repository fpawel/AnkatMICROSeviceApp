// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeStore.pas' rev: 6.00

#ifndef TeeStoreHPP
#define TeeStoreHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teestore
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TProcTeeCheckError)(const AnsiString Message);

class DELPHICLASS TSeriesData;
class PASCALIMPLEMENTATION TSeriesData : public Teeprocs::TTeeExportData 
{
	typedef Teeprocs::TTeeExportData inherited;
	
private:
	Chart::TCustomChart* FChart;
	bool FIncludeColors;
	bool FIncludeIndex;
	bool FIncludeHeader;
	bool FIncludeLabels;
	Teengine::TChartSeries* FSeries;
	bool FUseSeriesFormat;
	AnsiString FValueFormat;
	Teengine::TeeFormatFlag IFormat;
	void __fastcall Prepare(void);
	
protected:
	virtual void __fastcall GuessSeriesFormat(void);
	int __fastcall MaxSeriesCount(void);
	virtual AnsiString __fastcall PointToString(int Index);
	
public:
	__fastcall virtual TSeriesData(Chart::TCustomChart* AChart, Teengine::TChartSeries* ASeries);
	virtual AnsiString __fastcall AsString();
	AnsiString __fastcall ValueToString(Teengine::TChartSeries* ASeries, const double Value);
	__property Chart::TCustomChart* Chart = {read=FChart, write=FChart};
	__property Teengine::TChartSeries* Series = {read=FSeries, write=FSeries};
	
__published:
	__property bool IncludeColors = {read=FIncludeColors, write=FIncludeColors, default=0};
	__property bool IncludeHeader = {read=FIncludeHeader, write=FIncludeHeader, default=0};
	__property bool IncludeIndex = {read=FIncludeIndex, write=FIncludeIndex, default=0};
	__property bool IncludeLabels = {read=FIncludeLabels, write=FIncludeLabels, default=1};
	__property bool UseSeriesFormat = {read=FUseSeriesFormat, write=FUseSeriesFormat, default=0};
	__property AnsiString ValueFormat = {read=FValueFormat, write=FValueFormat};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSeriesData(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesDataText;
class PASCALIMPLEMENTATION TSeriesDataText : public TSeriesData 
{
	typedef TSeriesData inherited;
	
private:
	char FTextDelimiter;
	AnsiString FTextQuotes;
	
protected:
	virtual void __fastcall GuessSeriesFormat(void);
	virtual AnsiString __fastcall PointToString(int Index);
	
public:
	__fastcall virtual TSeriesDataText(Chart::TCustomChart* AChart, Teengine::TChartSeries* ASeries);
	virtual AnsiString __fastcall AsString();
	
__published:
	__property char TextDelimiter = {read=FTextDelimiter, write=FTextDelimiter, default=9};
	__property AnsiString TextQuotes = {read=FTextQuotes, write=FTextQuotes};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSeriesDataText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesDataXML;
class PASCALIMPLEMENTATION TSeriesDataXML : public TSeriesData 
{
	typedef TSeriesData inherited;
	
private:
	AnsiString FEncoding;
	bool __fastcall IsEncodingStored(void);
	
public:
	__fastcall virtual TSeriesDataXML(Chart::TCustomChart* AChart, Teengine::TChartSeries* ASeries);
	virtual AnsiString __fastcall AsString();
	
__published:
	__property AnsiString Encoding = {read=FEncoding, write=FEncoding, stored=IsEncodingStored};
	__property IncludeHeader  = {default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSeriesDataXML(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesDataHTML;
class PASCALIMPLEMENTATION TSeriesDataHTML : public TSeriesData 
{
	typedef TSeriesData inherited;
	
protected:
	virtual AnsiString __fastcall PointToString(int Index);
	
public:
	bool FirstSeriesLabels;
	virtual AnsiString __fastcall AsString();
public:
	#pragma option push -w-inl
	/* TSeriesData.Create */ inline __fastcall virtual TSeriesDataHTML(Chart::TCustomChart* AChart, Teengine::TChartSeries* ASeries) : TSeriesData(AChart, ASeries) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSeriesDataHTML(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesDataXLS;
class PASCALIMPLEMENTATION TSeriesDataXLS : public TSeriesData 
{
	typedef TSeriesData inherited;
	
public:
	DYNAMIC void __fastcall SaveToStream(Classes::TStream* AStream);
public:
	#pragma option push -w-inl
	/* TSeriesData.Create */ inline __fastcall virtual TSeriesDataXLS(Chart::TCustomChart* AChart, Teengine::TChartSeries* ASeries) : TSeriesData(AChart, ASeries) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSeriesDataXLS(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define TeeTextLineSeparator "\r\n"
extern PACKAGE void __fastcall LoadChartFromStreamCheck(Chart::TCustomChart* &AChart, Classes::TStream* AStream, TProcTeeCheckError ACheckError = 0x0, bool TryReadData = false);
extern PACKAGE void __fastcall LoadChartFromStream(Chart::TCustomChart* &AChart, Classes::TStream* AStream);
extern PACKAGE AnsiString __fastcall TeeCheckExtension(const AnsiString AFileName);
extern PACKAGE void __fastcall LoadChartFromFileCheck(Chart::TCustomChart* &AChart, const AnsiString AName, TProcTeeCheckError ACheckError);
extern PACKAGE void __fastcall LoadChartFromFile(Chart::TCustomChart* &AChart, const AnsiString AFileName);
extern PACKAGE void __fastcall ConvertTeeFileToText(const AnsiString InputFile, const AnsiString OutputFile);
extern PACKAGE void __fastcall ConvertTeeFileToBinary(const AnsiString InputFile, const AnsiString OutputFile);
extern PACKAGE void __fastcall SaveChartToStream(Chart::TCustomChart* AChart, Classes::TStream* AStream, bool IncludeData = true, bool TextFormat = false);
extern PACKAGE void __fastcall SaveChartToXMLStream(Chart::TCustomChart* AChart, Classes::TStream* AStream, bool IncludeData = true, bool XMLHeader = true);
extern PACKAGE void __fastcall SaveChartToFile(Chart::TCustomChart* AChart, const AnsiString AFileName, bool IncludeData = true, bool TextFormat = false);
extern PACKAGE void __fastcall SaveChartToXMLFile(Chart::TCustomChart* AChart, const AnsiString AFileName, bool IncludeData = true, bool XMLHeader = true);

}	/* namespace Teestore */
using namespace Teestore;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeStore
