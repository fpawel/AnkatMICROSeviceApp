// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeData.pas' rev: 6.00

#ifndef TeeDataHPP
#define TeeDataHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teedata
{
//-- type declarations -------------------------------------------------------
struct TSeriesPoint;
typedef TSeriesPoint *PSeriesPoint;

#pragma pack(push, 1)
struct TSeriesPoint
{
	Graphics::TColor Color;
	double X;
	double Values[11];
	AnsiString ALabel;
} ;
#pragma pack(pop)

typedef TSeriesPoint TSeriesPoints[1];

typedef TSeriesPoint *PSeriesPoints;

struct TRecInfo;
typedef TRecInfo *PRecInfo;

#pragma pack(push, 1)
struct TRecInfo
{
	int Bookmark;
	Db::TBookmarkFlag BookmarkFlag;
} ;
#pragma pack(pop)

class DELPHICLASS TTeeDataSet;
class PASCALIMPLEMENTATION TTeeDataSet : public Db::TDataSet 
{
	typedef Db::TDataSet inherited;
	
private:
	Classes::TList* FBookMarks;
	int FCurRec;
	int FLastBookmark;
	int IAllocated;
	void __fastcall DoCreateField(const AnsiString AFieldName, Db::TFieldType AType, int ASize);
	int __fastcall RecBufSize(void);
	
protected:
	void __fastcall AddSeriesFields(Teengine::TChartSeries* Series, bool PrefixSeriesName = false);
	virtual char * __fastcall AllocRecordBuffer(void);
	void __fastcall DoAddSeriesPoint(const TSeriesPoint &Buffer, Teengine::TChartSeries* Series);
	virtual void __fastcall DoFillBuffer(char * Buffer) = 0 ;
	void __fastcall FillSeriesBuffer(TSeriesPoint &Buffer, Teengine::TChartSeries* Series);
	virtual void __fastcall FreeRecordBuffer(char * &Buffer);
	virtual void __fastcall GetBookmarkData(char * Buffer, void * Data);
	virtual Db::TBookmarkFlag __fastcall GetBookmarkFlag(char * Buffer);
	virtual int __fastcall GetRecNo(void);
	virtual Db::TGetResult __fastcall GetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	bool __fastcall GetSeriesBuffer(int FieldIndex, TSeriesPoint &Active, void * Buffer, Teengine::TChartSeries* Series);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalFirst(void);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalSetToRecord(char * Buffer);
	virtual bool __fastcall IsCursorOpen(void);
	void __fastcall PostToSeries(Teengine::TChartSeries* Series, const TSeriesPoint &Buffer);
	virtual int __fastcall RecInfoOfs(void) = 0 ;
	virtual void __fastcall SetBookmarkData(char * Buffer, void * Data);
	virtual void __fastcall SetBookmarkFlag(char * Buffer, Db::TBookmarkFlag Value);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual void __fastcall SetRecNo(int Value);
	void __fastcall SetSeriesBuffer(int FieldIndex, const TSeriesPoint &Active, void * Buffer, Teengine::TChartSeries* Series);
	
__published:
	__property Active  = {default=0};
	__property AutoCalcFields  = {default=1};
	__property BeforeOpen ;
	__property AfterOpen ;
	__property BeforeClose ;
	__property AfterClose ;
	__property BeforeInsert ;
	__property AfterInsert ;
	__property BeforeEdit ;
	__property AfterEdit ;
	__property BeforePost ;
	__property AfterPost ;
	__property BeforeCancel ;
	__property AfterCancel ;
	__property BeforeDelete ;
	__property AfterDelete ;
	__property BeforeScroll ;
	__property AfterScroll ;
	__property AfterRefresh ;
	__property BeforeRefresh ;
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnNewRecord ;
	__property OnPostError ;
public:
	#pragma option push -w-inl
	/* TDataSet.Create */ inline __fastcall virtual TTeeDataSet(Classes::TComponent* AOwner) : Db::TDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataSet.Destroy */ inline __fastcall virtual ~TTeeDataSet(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	
};


class DELPHICLASS TSeriesDataSet;
class PASCALIMPLEMENTATION TSeriesDataSet : public TTeeDataSet 
{
	typedef TTeeDataSet inherited;
	
private:
	Teengine::TChartSeries* FSeries;
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
protected:
	virtual void __fastcall DoFillBuffer(char * Buffer);
	virtual Word __fastcall GetRecordSize(void);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual bool __fastcall IsCursorOpen(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall RecInfoOfs(void);
	virtual void __fastcall SetSeries(Teengine::TChartSeries* ASeries);
	
public:
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	
__published:
	__property Teengine::TChartSeries* Series = {read=FSeries, write=SetSeries, stored=true};
public:
	#pragma option push -w-inl
	/* TDataSet.Create */ inline __fastcall virtual TSeriesDataSet(Classes::TComponent* AOwner) : TTeeDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataSet.Destroy */ inline __fastcall virtual ~TSeriesDataSet(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	
public:
	inline bool __fastcall  GetFieldData(int FieldNo, void * Buffer){ return TDataSet::GetFieldData(FieldNo, Buffer); }
	inline bool __fastcall  GetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ return TDataSet::GetFieldData(Field, Buffer, NativeFormat); }
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


class DELPHICLASS TChartDataSet;
class PASCALIMPLEMENTATION TChartDataSet : public TTeeDataSet 
{
	typedef TTeeDataSet inherited;
	
private:
	Chart::TCustomChart* FChart;
	void __fastcall CalcFieldSeries(int Field, int &Index, int &Series);
	void __fastcall SetChart(Chart::TCustomChart* Value);
	void __fastcall TeeEvent(Teeprocs::TTeeEvent* Event);
	
protected:
	virtual void __fastcall DoFillBuffer(char * Buffer);
	virtual int __fastcall GetRecordCount(void);
	virtual Word __fastcall GetRecordSize(void);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual bool __fastcall IsCursorOpen(void);
	virtual int __fastcall RecInfoOfs(void);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	
public:
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	
__published:
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
public:
	#pragma option push -w-inl
	/* TDataSet.Create */ inline __fastcall virtual TChartDataSet(Classes::TComponent* AOwner) : TTeeDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataSet.Destroy */ inline __fastcall virtual ~TChartDataSet(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	
public:
	inline bool __fastcall  GetFieldData(int FieldNo, void * Buffer){ return TDataSet::GetFieldData(FieldNo, Buffer); }
	inline bool __fastcall  GetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ return TDataSet::GetFieldData(Field, Buffer, NativeFormat); }
	
private:
	void *__ITeeEventListener;	/* Teeprocs::ITeeEventListener */
	
public:
	operator ITeeEventListener*(void) { return (ITeeEventListener*)&__ITeeEventListener; }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Byte MaxLabelLen = 0x80;

}	/* namespace Teedata */
using namespace Teedata;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeData
