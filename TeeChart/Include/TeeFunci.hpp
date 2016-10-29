// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFunci.pas' rev: 6.00

#ifndef TeeFunciHPP
#define TeeFunciHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teefunci
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAddTeeFunction;
class PASCALIMPLEMENTATION TAddTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TAddTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TAddTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TManySeriesTeeFunction;
class PASCALIMPLEMENTATION TManySeriesTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
	
public:
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TManySeriesTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TManySeriesTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSubtractTeeFunction;
class PASCALIMPLEMENTATION TSubtractTeeFunction : public TManySeriesTeeFunction 
{
	typedef TManySeriesTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TSubtractTeeFunction(Classes::TComponent* AOwner) : TManySeriesTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TSubtractTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMultiplyTeeFunction;
class PASCALIMPLEMENTATION TMultiplyTeeFunction : public TManySeriesTeeFunction 
{
	typedef TManySeriesTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TMultiplyTeeFunction(Classes::TComponent* AOwner) : TManySeriesTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMultiplyTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDivideTeeFunction;
class PASCALIMPLEMENTATION TDivideTeeFunction : public TManySeriesTeeFunction 
{
	typedef TManySeriesTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TDivideTeeFunction(Classes::TComponent* AOwner) : TManySeriesTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TDivideTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS THighTeeFunction;
class PASCALIMPLEMENTATION THighTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual THighTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~THighTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLowTeeFunction;
class PASCALIMPLEMENTATION TLowTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TLowTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TLowTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAverageTeeFunction;
class PASCALIMPLEMENTATION TAverageTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FIncludeNulls;
	void __fastcall SetIncludeNulls(const bool Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TAverageTeeFunction(Classes::TComponent* AOwner);
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
	
__published:
	__property bool IncludeNulls = {read=FIncludeNulls, write=SetIncludeNulls, default=1};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TAverageTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomTeeFunction;
typedef void __fastcall (__closure *TCalculateEvent)(TCustomTeeFunction* Sender, const double x, double &y);

class PASCALIMPLEMENTATION TCustomTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	TCalculateEvent FCalculate;
	int FNumPoints;
	double FStartX;
	double FX;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TCustomTeeFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	__property double X = {read=FX, write=FX};
	
__published:
	__property int NumPoints = {read=FNumPoints, write=FNumPoints, nodefault};
	__property double StartX = {read=FStartX, write=FStartX};
	__property TCalculateEvent OnCalculate = {read=FCalculate, write=FCalculate};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomSortedFunction;
class PASCALIMPLEMENTATION TCustomSortedFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
protected:
	bool FIncludeNulls;
	DynamicArray<double >  tmp;
	int ICount;
	void __fastcall AddValue(const double Value, int Index);
	void __fastcall SetIncludeNulls(const bool Value);
	virtual double __fastcall CalcResult(void);
	
public:
	__fastcall virtual TCustomSortedFunction(Classes::TComponent* AOwner);
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
	__property bool IncludeNulls = {read=FIncludeNulls, write=SetIncludeNulls, default=1};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomSortedFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMedianTeeFunction;
class PASCALIMPLEMENTATION TMedianTeeFunction : public TCustomSortedFunction 
{
	typedef TCustomSortedFunction inherited;
	
protected:
	virtual double __fastcall CalcResult(void);
	
__published:
	__property IncludeNulls  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomSortedFunction.Create */ inline __fastcall virtual TMedianTeeFunction(Classes::TComponent* AOwner) : TCustomSortedFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMedianTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TModeTeeFunction;
class PASCALIMPLEMENTATION TModeTeeFunction : public TCustomSortedFunction 
{
	typedef TCustomSortedFunction inherited;
	
protected:
	virtual double __fastcall CalcResult(void);
	
__published:
	__property IncludeNulls  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomSortedFunction.Create */ inline __fastcall virtual TModeTeeFunction(Classes::TComponent* AOwner) : TCustomSortedFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TModeTeeFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teefunci */
using namespace Teefunci;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFunci
