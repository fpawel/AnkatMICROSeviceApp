// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeSpline.pas' rev: 6.00

#ifndef TeeSplineHPP
#define TeeSplineHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teespline
{
//-- type declarations -------------------------------------------------------
typedef double TDataType;

#pragma pack(push, 1)
struct TVertex
{
	double X;
	double Y;
} ;
#pragma pack(pop)

typedef DynamicArray<TVertex >  T2DPointList;

typedef DynamicArray<TVertex >  TVertexList;

typedef DynamicArray<bool >  TKnuckleList;

typedef DynamicArray<double >  TMatrixRow;

typedef DynamicArray<DynamicArray<double > >  TeeSpline__2;

class DELPHICLASS TBSpline;
class PASCALIMPLEMENTATION TBSpline : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	DynamicArray<DynamicArray<double > >  Matrix;
	int FNoPoints;
	int FCapacity;
	DynamicArray<TVertex >  FPointList;
	DynamicArray<TVertex >  FVertexList;
	DynamicArray<bool >  FKnuckleList;
	bool FBuild;
	int FNoVertices;
	bool FInterpolated;
	int FFragments;
	void __fastcall ClearVertexList(void);
	void __fastcall FSetBuild(bool Val);
	void __fastcall SetCapacity(int NewCapacity);
	void __fastcall FSetInterpolated(const bool Value);
	void __fastcall FSetFragments(const int Value);
	TVertex __fastcall FGetPoint(int Index);
	void __fastcall FSetPoint(int Index, const TVertex &Value);
	bool __fastcall FGetKnuckle(int Index);
	void __fastcall FSetKnuckle(int Index, bool Value);
	int __fastcall FGetNumberOfVertices(void);
	void __fastcall FInterpolate(void);
	void __fastcall FPhantomPoints(void);
	
public:
	__fastcall TBSpline(void);
	__fastcall virtual ~TBSpline(void);
	void __fastcall AddPoint(const double X, const double Y);
	void __fastcall Clear(void);
	__property int Count = {read=FNoPoints, nodefault};
	TVertex __fastcall Value(const double Parameter);
	void __fastcall Rebuild(void);
	__property bool Build = {read=FBuild, write=FSetBuild, nodefault};
	__property int Fragments = {read=FFragments, write=FSetFragments, nodefault};
	__property bool Interpolated = {read=FInterpolated, write=FSetInterpolated, nodefault};
	__property int NumberOfVertices = {read=FGetNumberOfVertices, nodefault};
	__property TVertex Point[int Index] = {read=FGetPoint, write=FSetPoint};
	__property bool Knuckle[int Index] = {read=FGetKnuckle, write=FSetKnuckle};
};


class DELPHICLASS TSmoothingFunction;
class PASCALIMPLEMENTATION TSmoothingFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
private:
	bool FInterpolate;
	int FFactor;
	void __fastcall SetFactor(const int Value);
	void __fastcall SetInterpolate(const bool Value);
	
protected:
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TSmoothingFunction(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall AddPoints(Teengine::TChartSeries* Source);
	
__published:
	__property bool Interpolate = {read=FInterpolate, write=SetInterpolate, default=1};
	__property int Factor = {read=FFactor, write=SetFactor, default=4};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TSmoothingFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word MaxFragments = 0x258;
static const Word MaxResults = 0x262;
static const Byte MaxCalcSteps = 0x96;
static const Extended MaxError = 1.000000E-05;
static const Shortint MaxIterations = 0x50;
static const Shortint VerticesIncrement = 0x5;

}	/* namespace Teespline */
using namespace Teespline;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeSpline
