// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CurvFitt.pas' rev: 6.00

#ifndef CurvFittHPP
#define CurvFittHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <StatChar.hpp>	// Pascal unit
#include <TeePoly.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Curvfitt
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTypeFitting { cfPolynomial };
#pragma option pop

class DELPHICLASS TCustomFittingFunction;
class PASCALIMPLEMENTATION TCustomFittingFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	int FFactor;
	int FFirstPoint;
	int FFirstCalcPoint;
	int FLastPoint;
	int FLastCalcPoint;
	int FPolyDegree;
	TTypeFitting FTypeFitting;
	Extended IAnswerVector[20];
	double IMinYValue;
	void __fastcall SetFactor(const int Value);
	void __fastcall SetFirstCalcPoint(int Value);
	void __fastcall SetFirstPoint(int Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	void __fastcall SetLastCalcPoint(int Value);
	void __fastcall SetLastPoint(int Value);
	void __fastcall SetPolyDegree(int Value);
	void __fastcall SetTypeFitting(TTypeFitting Value);
	
protected:
	double __fastcall GetAnswerVector(int Index);
	virtual void __fastcall AddFittedPoints(Teengine::TChartSeries* Source);
	__property int Factor = {read=FFactor, write=SetFactor, nodefault};
	
public:
	__fastcall virtual TCustomFittingFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	double __fastcall GetCurveYValue(Teengine::TChartSeries* Source, const double X);
	__property double AnswerVector[int Index] = {read=GetAnswerVector};
	__property int FirstCalcPoint = {read=FFirstCalcPoint, write=SetFirstCalcPoint, default=-1};
	__property int FirstPoint = {read=FFirstPoint, write=SetFirstPoint, default=-1};
	__property int LastCalcPoint = {read=FLastCalcPoint, write=SetLastCalcPoint, default=-1};
	__property int LastPoint = {read=FLastPoint, write=SetLastPoint, default=-1};
	__property int PolyDegree = {read=FPolyDegree, write=SetPolyDegree, default=5};
	__property TTypeFitting TypeFitting = {read=FTypeFitting, write=SetTypeFitting, default=0};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomFittingFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCurveFittingFunction;
class PASCALIMPLEMENTATION TCurveFittingFunction : public TCustomFittingFunction 
{
	typedef TCustomFittingFunction inherited;
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
__published:
	__property Factor  = {default=1};
	__property FirstCalcPoint  = {default=-1};
	__property FirstPoint  = {default=-1};
	__property LastCalcPoint  = {default=-1};
	__property LastPoint  = {default=-1};
	__property PolyDegree  = {default=5};
	__property TypeFitting  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomFittingFunction.Create */ inline __fastcall virtual TCurveFittingFunction(Classes::TComponent* AOwner) : TCustomFittingFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCurveFittingFunction(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTrendStyle { tsNormal, tsLogarithmic, tsExponential };
#pragma option pop

class DELPHICLASS TCustomTrendFunction;
class PASCALIMPLEMENTATION TCustomTrendFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	TTrendStyle IStyle;
	int ICount;
	double SumX;
	double SumXY;
	double SumY;
	double SumX2;
	double SumY2;
	bool __fastcall CalculateValues(Teengine::TChartSeries* Source, int FirstIndex, int LastIndex);
	
protected:
	virtual void __fastcall CalculatePeriod(Teengine::TChartSeries* Source, const double tmpX, int FirstIndex, int LastIndex);
	virtual void __fastcall CalculateAllPoints(Teengine::TChartSeries* Source, Teengine::TChartValueList* NotMandatorySource);
	
public:
	__fastcall virtual TCustomTrendFunction(Classes::TComponent* AOwner);
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int First, int Last);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
	bool __fastcall CalculateTrend(double &m, double &b, Teengine::TChartSeries* Source, int FirstIndex, int LastIndex);
	double __fastcall Coefficient(Teengine::TChartSeries* Source, int FirstIndex, int LastIndex);
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomTrendFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTrendFunction;
class PASCALIMPLEMENTATION TTrendFunction : public TCustomTrendFunction 
{
	typedef TCustomTrendFunction inherited;
	
public:
	#pragma option push -w-inl
	/* TCustomTrendFunction.Create */ inline __fastcall virtual TTrendFunction(Classes::TComponent* AOwner) : TCustomTrendFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TTrendFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TExpTrendFunction;
class PASCALIMPLEMENTATION TExpTrendFunction : public TCustomTrendFunction 
{
	typedef TCustomTrendFunction inherited;
	
public:
	__fastcall virtual TExpTrendFunction(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TExpTrendFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCorrelationFunction;
class PASCALIMPLEMENTATION TCorrelationFunction : public TCustomTrendFunction 
{
	typedef TCustomTrendFunction inherited;
	
protected:
	virtual void __fastcall CalculatePeriod(Teengine::TChartSeries* Source, const double tmpX, int FirstIndex, int LastIndex);
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int First, int Last);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TCustomTrendFunction.Create */ inline __fastcall virtual TCorrelationFunction(Classes::TComponent* AOwner) : TCustomTrendFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCorrelationFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Curvfitt */
using namespace Curvfitt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CurvFitt
