// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSHP.pas' rev: 6.00

#ifndef TeeSHPHPP
#define TeeSHPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeMapSeries.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeshp
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TSHPHeader
{
	int FileCode;
	int Unused1;
	int Unused2;
	int Unused3;
	int Unused4;
	int Unused5;
	int FileLength;
	int Version;
	int ShapeType;
	double XMin;
	double YMin;
	double XMax;
	double YMax;
	double ZMin;
	double ZMax;
	double MMin;
	double MMax;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TSHPRecordHeader
{
	int RecordNumber;
	int RecordLength;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Shortint SHP_NULL = 0x0;
static const Shortint SHP_POINT = 0x1;
static const Shortint SHP_POLYLINE = 0x3;
static const Shortint SHP_POLYGON = 0x5;
static const Shortint SHP_MULTIPOINT = 0x8;
static const Shortint SHP_POINTZ = 0xb;
static const Shortint SHP_POLYLINEZ = 0xd;
static const Shortint SHP_POLYGONZ = 0xf;
static const Shortint SHP_MULTIPOINTZ = 0x12;
static const Shortint SHP_POINTM = 0x15;
static const Shortint SHP_POLYLINEM = 0x17;
static const Shortint SHP_POLYGONM = 0x19;
static const Shortint SHP_MULTIPOINTM = 0x1c;
static const Shortint SHP_MULTIPATCH = 0x1f;
static const int TeeSHPMaxRandom = 0xf4240;
extern PACKAGE void __fastcall LoadMap(Teemapseries::TMapSeries* Series, Classes::TStream* ShpStream, Classes::TStream* ShxStream, Db::TDataSet* Table = (Db::TDataSet*)(0x0), const AnsiString FieldName = "", const AnsiString FieldValue = "", bool ClearSeries = true)/* overload */;
extern PACKAGE void __fastcall LoadMap(Teemapseries::TMapSeries* Series, const AnsiString FileName, Db::TDataSet* Table = (Db::TDataSet*)(0x0), const AnsiString FieldName = "", const AnsiString FieldValue = "", bool ClearSeries = true)/* overload */;

}	/* namespace Teeshp */
using namespace Teeshp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSHP
