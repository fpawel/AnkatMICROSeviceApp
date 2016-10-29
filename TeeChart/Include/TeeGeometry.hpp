// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGeometry.pas' rev: 6.00

#ifndef TeeGeometryHPP
#define TeeGeometryHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Math.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teegeometry
{
//-- type declarations -------------------------------------------------------
typedef Byte *PByte;

typedef Word *PWord;

typedef int *PInteger;

typedef float *PFloat;

typedef double *PDouble;

typedef Extended *PExtended;

typedef void * *PPointer;

typedef Byte TByteVector[65536];

typedef Byte *PByteVector;

typedef Word TWordVector[65536];

typedef Word *PWordVector;

typedef int TIntVector[65536];

typedef int *PIntVector;

typedef float TFloatVector[65536];

typedef float *PFloatVector;

typedef double TDblVector[65536];

typedef double *PDblVector;

typedef Byte THomogeneousByteVector[4];

typedef Byte *PHomogeneousByteVector;

typedef Byte TVector4b[4];

typedef Word THomogeneousWordVector[4];

typedef Word *PHomogeneousWordVector;

typedef Word TVector4w[4];

typedef int THomogeneousIntVector[4];

typedef int *PHomogeneousIntVector;

typedef int TVector4i[4];

typedef float THomogeneousFltVector[4];

typedef float *PHomogeneousFltVector;

typedef float TVector4f[4];

typedef double THomogeneousDblVector[4];

typedef double *PHomogeneousDblVector;

typedef double TVector4d[4];

typedef Extended THomogeneousExtVector[4];

typedef Extended *PHomogeneousExtVector;

typedef Extended TVector4e[4];

typedef void *THomogeneousPtrVector[4];

typedef void * *PHomogeneousPtrVector;

typedef void *TVector4p[4];

typedef Byte TAffineByteVector[3];

typedef Byte *PAffineByteVector;

typedef Byte TVector3b[3];

typedef Word TAffineWordVector[3];

typedef Word *PAffineWordVector;

typedef Word TVector3w[3];

typedef int TAffineIntVector[3];

typedef int *PAffineIntVector;

typedef int TVector3i[3];

typedef float TAffineFltVector[3];

typedef float *PAffineFltVector;

typedef float TVector3f[3];

typedef double TAffineDblVector[3];

typedef double *PAffineDblVector;

typedef double TVector3d[3];

typedef Extended TAffineExtVector[3];

typedef Extended *PAffineExtVector;

typedef Extended TVector3e[3];

typedef void *TAffinePtrVector[3];

typedef void * *PAffinePtrVector;

typedef void *TVector3p[3];

typedef float *PVector;

typedef float TVector[4];

typedef float *PHomogeneousVector;

typedef float THomogeneousVector[4];

typedef float *PAffineVector;

typedef float TAffineVector[3];

typedef float TVectorArray[65536][3];

typedef float *PVectorArray;

typedef Byte THomogeneousByteMatrix[4][4];

typedef Byte TMatrix4b[4][4];

typedef Word THomogeneousWordMatrix[4][4];

typedef Word TMatrix4w[4][4];

typedef int THomogeneousIntMatrix[4][4];

typedef int TMatrix4i[4][4];

typedef float THomogeneousFltMatrix[4][4];

typedef float TMatrix4f[4][4];

typedef double THomogeneousDblMatrix[4][4];

typedef double TMatrix4d[4][4];

typedef Extended THomogeneousExtMatrix[4][4];

typedef Extended TMatrix4e[4][4];

typedef Byte TAffineByteMatrix[3][3];

typedef Byte TMatrix3b[3][3];

typedef Word TAffineWordMatrix[3][3];

typedef Word TMatrix3w[3][3];

typedef int TAffineIntMatrix[3][3];

typedef int TMatrix3i[3][3];

typedef float TAffineFltMatrix[3][3];

typedef float TMatrix3f[3][3];

typedef double TAffineDblMatrix[3][3];

typedef double TMatrix3d[3][3];

typedef Extended TAffineExtMatrix[3][3];

typedef Extended TMatrix3e[3][3];

typedef float *PMatrix;

typedef float TMatrix[4][4];

typedef float *PHomogeneousMatrix;

typedef float THomogeneousMatrix[4][4];

typedef float *PAffineMatrix;

typedef float TAffineMatrix[3][3];

#pragma pack(push, 4)
struct TQuaternion
{
	
	union
	{
		struct 
		{
			float Vector[4];
			
		};
		struct 
		{
			float Axis[3];
			float Angle;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TRectangle
{
	int Left;
	int Top;
	int Width;
	int Height;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TTransType { ttScaleX, ttScaleY, ttScaleZ, ttShearXY, ttShearXZ, ttShearYZ, ttRotateX, ttRotateY, ttRotateZ, ttTranslateX, ttTranslateY, ttTranslateZ, ttPerspectiveX, ttPerspectiveY, ttPerspectiveZ, ttPerspectiveW };
#pragma option pop

typedef Extended TTransformations[16];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE float XVector[3];
extern PACKAGE float YVector[3];
extern PACKAGE float ZVector[3];
extern PACKAGE float NullVector[3];
extern PACKAGE float IdentityMatrix[4][4];
extern PACKAGE float EmptyMatrix[4][4];
static const Extended EPSILON = 1.000000E-100;
static const Extended EPSILON2 = 1.000000E-50;
extern PACKAGE float __fastcall VectorLength(const float * V, const int V_Size);
extern PACKAGE float __fastcall VectorAngle(const float * V1, const float * V2);
extern PACKAGE bool __fastcall PointInPolygon(const float * xp, const int xp_Size, const float * yp, const int yp_Size, const float x, const float y);
extern PACKAGE TQuaternion __fastcall QuaternionConjugate(const TQuaternion &Q);
extern PACKAGE TQuaternion __fastcall QuaternionFromPoints(const float * V1, const float * V2);
extern PACKAGE TQuaternion __fastcall QuaternionMultiply(const TQuaternion &qL, const TQuaternion &qR);
extern PACKAGE void __fastcall QuaternionToPoints(const TQuaternion &Q, float * ArcFrom, float * ArcTo);
extern PACKAGE float __fastcall VectorNorm(const float * V, const int V_Size);
extern PACKAGE float __fastcall VectorNormalize(const float * V, const int V_Size);
extern PACKAGE void __fastcall VectorScale(const float * V, const int V_Size, const float Factor);
extern PACKAGE void __fastcall VectorNegate(const float * V, const int V_Size);
extern PACKAGE float __fastcall VectorDotProduct(const float * V1, const float * V2);
extern PACKAGE float __fastcall VectorAffineDotProduct(const float * V1, const float * V2);
extern PACKAGE float __fastcall MatrixAffineDeterminant(const float * M);
extern PACKAGE void __fastcall MatrixAdjoint(float * M);
extern PACKAGE float __fastcall MatrixDeterminant(const float * M);
extern PACKAGE void __fastcall MatrixScale(float * M, const float Factor);
extern PACKAGE void __fastcall MatrixInvert(float * M);
extern PACKAGE void __fastcall MatrixTranspose(float * M);
extern PACKAGE void __fastcall MatrixAffineTranspose(float * M);
extern PACKAGE TQuaternion __fastcall QuaternionSlerp(const TQuaternion &QStart, const TQuaternion &QEnd, int Spin, float t);
extern PACKAGE bool __fastcall MatrixDecompose(const float * M, Extended * Tran);

}	/* namespace Teegeometry */
using namespace Teegeometry;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGeometry
