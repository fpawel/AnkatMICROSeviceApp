// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGauges.pas' rev: 6.00

#ifndef TeeGaugesHPP
#define TeeGaugesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teegauges
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum THandStyle { hsLine, hsTriangle };
#pragma option pop

class DELPHICLASS TGaugeSeries;
class PASCALIMPLEMENTATION TGaugeSeries : public Series::TCircledSeries 
{
	typedef Series::TCircledSeries inherited;
	
private:
	double FAngle;
	Teengine::TSeriesPointer* FCenter;
	int FDistance;
	Teengine::TSeriesPointer* FEndPoint;
	bool FFullRepaint;
	double FMax;
	double FMin;
	int FMinorDistance;
	THandStyle FStyle;
	Classes::TNotifyEvent FOnChange;
	#pragma pack(push, 1)
	Types::TPoint ICenter;
	#pragma pack(pop)
	
	bool FLabelsInside;
	void __fastcall CalcLinePoints(Types::TPoint &P0, Types::TPoint &P1);
	Types::TPoint __fastcall CalcPoint(const double Angle, const Types::TPoint &Center, const double RadiusX, const double RadiusY);
	void __fastcall DrawValueLine(void);
	void __fastcall SetAngle(const double Value);
	void __fastcall SetCenter(const Teengine::TSeriesPointer* Value);
	void __fastcall SetDistance(const int Value);
	void __fastcall SetMax(const double AValue);
	void __fastcall SetMin(const double AValue);
	void __fastcall SetStyle(const THandStyle Value);
	void __fastcall SetValue(const double AValue);
	void __fastcall SetFullRepaint(const bool Value);
	double __fastcall GetValue(void);
	void __fastcall SetEndPoint(const Teengine::TSeriesPointer* Value);
	int __fastcall SizePointer(Teengine::TSeriesPointer* APointer);
	void __fastcall SetMinorDistance(const int Value);
	void __fastcall SetLabelsInside(const bool Value);
	
protected:
	DYNAMIC void __fastcall AddSampleValues(int NumValues, bool OnlyMandatory = false);
	virtual void __fastcall DrawAllValues(void);
	DYNAMIC void __fastcall GalleryChanged3D(bool Is3D);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	virtual void __fastcall NotifyNewValue(Teengine::TChartSeries* Sender, int ValueIndex);
	DYNAMIC void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall SetParentChart(const Teengine::TCustomAxisPanel* Value);
	
public:
	__fastcall virtual TGaugeSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TGaugeSeries(void);
	Teengine::TChartAxis* __fastcall Axis(void);
	virtual int __fastcall Clicked(int x, int y)/* overload */;
	DYNAMIC int __fastcall NumSampleValues(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property Teengine::TSeriesPointer* Center = {read=FCenter, write=SetCenter};
	__property Circled  = {default=1};
	__property CircleGradient ;
	__property Teengine::TSeriesPointer* EndPoint = {read=FEndPoint, write=SetEndPoint};
	__property bool FullRepaint = {read=FFullRepaint, write=SetFullRepaint, default=0};
	__property double Maximum = {read=FMax, write=SetMax};
	__property double Minimum = {read=FMin, write=SetMin};
	__property int MinorTickDistance = {read=FMinorDistance, write=SetMinorDistance, default=0};
	__property int HandDistance = {read=FDistance, write=SetDistance, default=30};
	__property THandStyle HandStyle = {read=FStyle, write=SetStyle, default=0};
	__property bool LabelsInside = {read=FLabelsInside, write=SetLabelsInside, default=1};
	__property Pen ;
	__property RotationAngle  = {default=135};
	__property ShowInLegend  = {default=0};
	__property double TotalAngle = {read=FAngle, write=SetAngle};
	__property double Value = {read=GetValue, write=SetValue};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Clicked(const Types::TPoint &P){ return TChartSeries::Clicked(P); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint TeeHandDistance = 0x1e;

}	/* namespace Teegauges */
using namespace Teegauges;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGauges
