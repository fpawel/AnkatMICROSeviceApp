//---------------------------------------------------------------------------
#ifndef uChartHelperH
#define uChartHelperH
//---------------------------------------------------------------------------
//vcl
#include <Series.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
//std
#include <utility>
#include <vector>

// boost
#include "boost\noncopyable.hpp"
//#include "boost\shared_ptr.hpp"

//my
#include "application\myiostream.h"

#include "free_types_.h"

typedef std::vector<TChartSeries*> MyChartSeriesList;

bool IsPointInChartRect( TChart* chrt, int x, int y );

struct ChartAxisOrders
{
	double minX, minY, maxX, maxY;
};

ChartAxisOrders GetChartAxisOrders(TChart *chrt, TVertAxis, THorizAxis);

void NormalizeChartX(TChart *chrt);
void NormalizeChartY(TChart *chrt );

std::pair<double,double> GetYLimits(TChart *chrt);
std::pair<double,double> GetYLimitsOfSeries(TChartSeries* ser);

void SetAxisMin( TChartAxis* axis, double val );
void SetAxisMax( TChartAxis* axis, double val );
void SetAxisOrders( TChartAxis* axis, double minV, double maxV );

TChartSeries* GetFirstActiveChartSeries(TChart *chrt);

// получить индекс y по x или -1
int GetYValueChartSeries(TChartSeries* ser, double x);

void DrawSeriesValuesPoints(TChartSeries* ser, TColor clr, unsigned radius);

enum AxOrdr_ { ax_Max = true, ax_Min = false } ;
void IncAxOrder( TChartAxis *ax, AxOrdr_ ordr, bool inc );

//void ClearAndDeleteTChartSeries( TChart *chrt );

///////////////////////////////////////////////////////////////////////////////
// ѕомошник дл€ отображени€ курсора графика
///////////////////////////////////////////////////////////////////////////////
void SetDrawingCrossHairPen(TChart *chrt, int width = 1);
void DrawCrossHair(TChart *chrt, int ax, int ay, TColor horClr, TColor verClr);

void DrawSeriesXMarks(TChartSeries* ser, TChartAxis* ax, const VDouble& marks,
	const VDouble& x0, const VDouble& x1, const std::vector<AnsiString>& strs );

TColor GetNextSeriesColor( TChart *chrt );
void ClearAndDeleteTChartSeries( TChart *chrt );
//------------------------------------------------------------------------------
bool MySaveTChartToFile( const AnsiString &fn, TChart* chrt, const AnsiString& note );
bool MySaveTChartToTextFile( const AnsiString &fn, TChart* chrt );
bool MyLoadTChartFromFile( const AnsiString &fn, TChart* chrt, AnsiString& note );
MyChartSeriesList StoreChartSeriesList( TChart *chrt );
//------------------------------------------------------------------------------
void ClearChartInXInterval(TChart *chrt, double xMin, double xMax);
//------------------------------------------------------------------------------

class CrossHairHelper : public boost::noncopyable
{
public:

	explicit CrossHairHelper( TChart* chrt );

    void OnMouseMove(int x, int y);

    void Hide()
    {
		if(x_==-1) return;
		DrawCross( x_, y_ );
    	x_=-1;
	}

    void Reset() { x_ = -1; }

    void (__closure *OnMouseOcurence)(bool);

    void SetSeries( TChartSeries* ser ) { ser_ = ser; }
    void SetColor( TColor color ) { color_= color; }

private:
	TChart* chrt_;
    TChartSeries* ser_;
    TCanvas3D* cnv_;
    // позици€
    int x_, y_;

    TColor color_;

	void OnChartMouseOcurence( TWinControl* chrt, bool isEntered)
    {
    	if( !isEntered ) Hide();
        if( OnMouseOcurence ) OnMouseOcurence( isEntered );
    }

    void DrawCross(int ax, int ay)
    {
    	SetDrawingCrossHairPen(chrt_);
        DrawCrossHair(chrt_, ax, ay, color_, color_);
    }
};


//---------------------------------------------------------------------------
#endif
