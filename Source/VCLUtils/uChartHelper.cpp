//---------------------------------------------------------------------------
// std
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------
#pragma hdrstop

#include "uChartHelper.h"

#include "MouseEvt.h"
#include "AnsiStringUtils_.h"
#include "my_include\my_array_size.h"
#include "crc16.h"
#include "..\my_include\win\WinErr.hpp"
//#include "uFrmWait.h"
//my
#include "MyExcpt.hpp"
#include "MyWinExcpt.hpp"

#include <DateUtils.hpp>
#include "MyFileCtrl.h"

//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
const uInt16 MY_CRC16_OFFSET = 0x7AE2;
const AnsiString FILE_GRAPH_HEAD_STRING = "C08A218C-73CD-4CB8-8E7D-DF2E6958C3B8";
//------------------------------------------------------------------------------
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorFileStream, WindowsException );
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorFileWrite, ErrorFileStreamException );
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorFileRead, ErrorFileStreamException );
//------------------------------------------------------------------------------
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorGraphFileFormat, Exception );
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorGraphFileHeadString, ErrorGraphFileFormatException );
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorRecordCRC16, ErrorGraphFileFormatException );
DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(ErrorRecordFloatFormat, ErrorGraphFileFormatException );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#define STRM_WRITE_(OOSTRM, vv) Private::WriteFStrm( OOSTRM, reinterpret_cast<const char*>(&##vv##), sizeof(##vv##) )
#define STRM_READ_( IISTRM, vv) Private::ReadFStrm( IISTRM, reinterpret_cast<char*>(&##vv##), sizeof(##vv##) )
//------------------------------------------------------------------------------
namespace Private
{
	//--------------------------------------------------------------------------
	uInt16 crc16_;
    //--------------------------------------------------------------------------
	template<class FStrmT, typename CharT>
	FStrmT& WriteFStrm( FStrmT& fstrm, const CharT* p, unsigned len )
    {
    	fstrm.write( p, len );
        crc16_ = CalculateCRC16( reinterpret_cast<const unsigned char*>(p), len, crc16_ );
        if( fstrm.fail() )
        	MY_THROW_CLASS_(MyErrorFileWriteException, "Ошибка записи в файл.");
        	//throw ErrorFileWrite();
        return fstrm;
    }
    //--------------------------------------------------------------------------
    template<class FStrmT, typename CharT>
	FStrmT& ReadFStrm( FStrmT& fstrm, CharT* p, unsigned len )
    {
    	fstrm.read( p, len );
        crc16_ = CalculateCRC16( reinterpret_cast<const unsigned char*>(p),
        	len, crc16_ );
        if( fstrm.fail() )
        	MY_THROW_CLASS_(MyErrorFileReadException, "Ошибка считывания из файла.");
        	//throw ErrorFileRead();
        return fstrm;
    }
    //--------------------------------------------------------------------------
    template<class FStrmT>
    unsigned GetNextDataBlockLength(FStrmT& strm )
    {
    	unsigned len;
        strm.read( reinterpret_cast<char*>(&len), sizeof(len) );
    	const unsigned pos1 = strm.tellg();
    	strm.seekg(0, std::ios::end);
    	const unsigned pos2 = strm.tellg();
    	strm.seekg(pos1, std::ios::beg);
    	const unsigned strmSize = pos2-pos1;
        if(strmSize<len)
        	//throw ErrorGraphFileFormat();
            MY_THROW_CLASS_(MyErrorGraphFileFormatException, "Неверный формат файла.");
        return len;

    }
    //--------------------------------------------------------------------------
    void WriteStr(std::ostream& ostrm, const AnsiString& s)
    {
    	//const char *pStr = s.c_str();
        const unsigned len = s.Length();
        STRM_WRITE_(ostrm, len);
    	WriteFStrm( ostrm, s.c_str(), s.Length() );
    }
    //--------------------------------------------------------------------------
    AnsiString ReadStr(std::istream& ostrm )
    {
    	const unsigned len = GetNextDataBlockLength(ostrm);
    	std::vector<char> strChars(len+1, '\0');
        char *pStr = &strChars.at(0);
    	ReadFStrm( ostrm, pStr, len );
        return AnsiString( pStr, len );
    }
};
//---------------------------------------------------------------------------

void SetAxisMin( TChartAxis* axis, double val )
{
	if( GetFirstActiveChartSeries( dynamic_cast<TChart*>(axis->ParentChart) )==NULL ) return;
    if( val > axis->Maximum ) return;
    axis->Automatic  = false;
    axis->AutomaticMinimum = false;
    axis->SetMinMax( val, axis->Maximum );
}
//---------------------------------------------------------------------------
void SetAxisMax( TChartAxis* axis, double val )
{
	if( GetFirstActiveChartSeries( dynamic_cast<TChart*>(axis->ParentChart) )==NULL ) return;
    if( val < axis->Minimum ) return;
    axis->Automatic  = false;
    axis->AutomaticMaximum = false;
    axis->SetMinMax( axis->Minimum, val );
}
//---------------------------------------------------------------------------
void SetAxisOrders( TChartAxis* axis, double minV, double maxV )
{
	if( GetFirstActiveChartSeries( dynamic_cast<TChart*>(axis->ParentChart) )==NULL ) return;
	if( !(minV<maxV) ) return;
    using std::min;
    using std::max;
    const double
    vMin = min( min( axis->Minimum, minV ), min( axis->Maximum, maxV ) ),
    vMax = max( max( axis->Minimum, minV ), max( axis->Maximum, maxV ) );
    axis->Minimum = vMin;
    axis->Maximum = vMax;
    axis->Minimum = minV;
    axis->Maximum = maxV;
}

TChartSeries* GetFirstActiveChartSeries(TChart *chrt)
{
	for( int i=0; i<chrt->SeriesCount(); ++i )
    {
    	TChartSeries* ser = chrt->Series[i];
    	if( ser->Active ) return ser;
    }
    return NULL;
}

//---------------------------------------------------------------------------
bool IsPointInChartRect( TChart* chrt, int x, int y )
{
	//return PtInRect( chrt->ChartRect, TPoint(x-chrt->Width3D,y+chrt->Height3D)  );
    return PtInRect( (RECT*)&chrt->ChartRect, Point(x-chrt->Width3D,y+chrt->Height3D));
}
//---------------------------------------------------------------------------
TChartSeries* GetFirstActiveChartSeriesWithAxis(TChart *chrt, TVertAxis verAx, THorizAxis horAx)
{
	for( int i=0; i<chrt->SeriesCount(); ++i )
    {
    	TChartSeries* ser = chrt->Series[i];
    	if( ser->Active && ser->VertAxis==verAx && ser->HorizAxis==horAx ) return ser;
    }
    return NULL;
}
//---------------------------------------------------------------------------
ChartAxisOrders GetChartAxisOrders(TChart *chrt, TVertAxis verAx, THorizAxis horAx)
{
	ChartAxisOrders ret;
    ret.minX = 0;    ret.maxX = 0;    ret.minY = 0;    ret.maxY = 0;
    if( chrt==NULL || chrt->SeriesCount()==0 ) return ret;

    TChartSeries *actvSer = GetFirstActiveChartSeriesWithAxis(chrt, verAx, horAx);
    if(actvSer==NULL) return ret;

    ret.minX = actvSer->MinXValue();
    ret.maxX = actvSer->MaxXValue();
    ret.minY = actvSer->MinYValue();
    ret.maxY = actvSer->MaxYValue();
   	for( int i=0; i<chrt->SeriesCount(); ++i )
    {
        TChartSeries *ser = chrt->Series[i];
        if(!ser->Active || ser->Count()==0 ||
            ser->VertAxis!=verAx ||
            ser->HorizAxis!=horAx ) continue;
    	const double
        	serMinX = ser->MinXValue(),
            serMaxX = ser->MaxXValue(),
            serMinY = ser->MinYValue(),
            serMaxY = ser->MaxYValue();
        if( serMinX<ret.minX ) ret.minX = serMinX;
        if( serMaxX>ret.maxX ) ret.maxX = serMaxX;
        if( serMinY<ret.minY ) ret.minY = serMinY;
        if( serMaxY>ret.maxY ) ret.maxY = serMaxY;
    }
    return ret;
}
//---------------------------------------------------------------------------
void NormalizeChartX(TChart *chrt)
{
    const ChartAxisOrders
        ordrs1 = GetChartAxisOrders(chrt, aLeftAxis, aBottomAxis),
        ordrs2 = GetChartAxisOrders(chrt, aRightAxis, aBottomAxis)
        ;
    TChartAxis *xAx = chrt->BottomAxis;
    const bool
        isRightGraph = ordrs2.minX!=ordrs2.maxX!=0,
        isLeftGraph = ordrs1.minX!=ordrs1.maxX!=0;
    double
        x1 = std::min( ordrs1.minX, ordrs2.minX),
        x2 = std::max( ordrs1.maxX, ordrs2.maxX);
    if( isRightGraph && !isLeftGraph )
    {
        x1 = ordrs2.minX;
        x2 = ordrs2.maxX;
    }
    if( !isRightGraph && isLeftGraph )
    {
        x1 = ordrs1.minX;
        x2 = ordrs1.maxX;
    }
    const double d = (x2-x1)*0.1;
    xAx->SetMinMax( x1-d, x2+d );
}
//---------------------------------------------------------------------------
void NormalizeChartY(TChart *chrt)
{
    TChartAxis *yAx1 = chrt->LeftAxis, *yAx2 = chrt->RightAxis;
    const ChartAxisOrders
        ordrs1 = GetChartAxisOrders(chrt, aLeftAxis, aBottomAxis),
        ordrs2 = GetChartAxisOrders(chrt, aRightAxis, aBottomAxis)
        ;
    double y1 = ordrs1.minY, y2 = ordrs1.maxY, d = (y2-y1)*0.1;
    yAx1->SetMinMax( y1-d, y2+d );
    y1 = ordrs2.minY, y2 = ordrs2.maxY, d = (y2-y1)*0.1;
    yAx2->SetMinMax( y1-d, y2+d );
}
//------------------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////////
// ???????? ??? ??????????? ??????? ???????
///////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
void SetDrawingCrossHairPen(TChart *chrt, int width)
{
    TPen& pen = *chrt->Canvas->Pen;
    pen.Style = psSolid;
    pen.Mode = pmXor;
    pen.Width = width;
}
//------------------------------------------------------------------------------
void DrawCrossHair(TChart *chrt, int ax, int ay, TColor horClr, TColor verClr)
{
	const TColor
    chrtClr = chrt->BackColor,
    bsClr = chrtClr==clTeeColor ? clBtnFace : chrtClr;
    TCanvas3D &cnv = *chrt->Canvas;
    TPen& pen = *cnv.Pen;

    pen.Color = (TColor)(horClr ^ ColorToRGB(bsClr));
    cnv.MoveTo(chrt->ChartRect.Left+chrt->Width3D, ay);
    cnv.LineTo(ax,ay);

    if(verClr!=0)
    {
    	pen.Color = (TColor)(verClr ^ ColorToRGB(bsClr) );
        cnv.MoveTo(ax, chrt->ChartRect.Top );
      	cnv.LineTo(ax, chrt->ChartRect.Bottom-chrt->Height3D);
    }
}
//------------------------------------------------------------------------------
CrossHairHelper::CrossHairHelper( TChart* chrt ) :
	chrt_(chrt), color_(clBlue),
    cnv_( chrt_->Canvas ), x_(-1), y_(-1),
    OnMouseOcurence(NULL)
{
	my::RegisterOnMouseOccurrence(chrt_, &OnChartMouseOcurence );
}
//------------------------------------------------------------------------------
void CrossHairHelper::OnMouseMove(int x, int y )
{
	Hide();

    if( ser_==NULL )
    	ser_ = GetFirstActiveChartSeries(chrt_);
    if( ser_==NULL || !IsPointInChartRect( chrt_, x, y ) )
    	return;

	double serX, serY;
	ser_->GetCursorValues(serX, serY);
    // ???????? ?????? y ?? x ??? -1
	const int yIdx = GetYValueChartSeries(ser_, serX);
    if( yIdx==-1 ) return;
    serY = ser_->YValue[yIdx];
    serX = ser_->XValue[yIdx];

    x_ = ser_->CalcXPosValue(serX);
    y_ = ser_->CalcYPosValue(serY);
    DrawCross(x_,y_);
}
//------------------------------------------------------------------------------
void IncAxOrder( TChartAxis *ax, AxOrdr_ ordr, bool inc )
{
	const double step = (ax->Maximum - ax->Minimum)*0.01*(inc ? 1 : -1);
    if(ordr==ax_Min)
    {
    	ax->AutomaticMinimum = 0;
    	ax->Minimum = ax->Minimum + step;
    }
    else
    {
    	ax->AutomaticMaximum = 0;
    	ax->Maximum = ax->Maximum + step;
    }
}
//------------------------------------------------------------------------------

std::pair<double,double> GetYLimitsOfSeries(TChartSeries* ser)
{
    const int count = ser->Count(), i1 = ser->FirstValueIndex, i2 = ser->LastValueIndex;
    if( count==0 || i1==-1 || i2==-1) return std::make_pair(0,0);

    std::pair<double,double> ret(ser->YValue[i1], ser->YValue[i2] );
    for( int vIdx = i1; vIdx<i2; ++vIdx )
    {
        const double serY = ser->YValue[vIdx];
        if( serY<=ret.first ) ret.first = serY;
        if( serY>=ret.second ) ret.second = serY;
    }
    return ret;;
}

void DrawSeriesValuesPoints(TChartSeries* ser, TColor clr, unsigned radius)
{
    TChart* chrt = static_cast<TChart*>(ser->ParentChart);
    TCanvas3D* cnv = chrt->Canvas;

	const TColor brshClr = cnv->Brush->Color,
    penClr = cnv->Pen->Color;
    cnv->Brush->Color = clr;
    cnv->Pen->Color = clr;
    for ( int t=ser->FirstValueIndex; t<=ser->LastValueIndex; ++t )
   	{
    	const int xPos=ser->CalcXPos( t ), yPos = ser->CalcYPos( t );
        cnv->Ellipse(xPos-radius,yPos-radius, xPos+radius, yPos+radius);
    }
    cnv->Brush->Color = brshClr;
    cnv->Pen->Color = penClr;
}

// ???????? ?????? y ?? x ??? -1
int GetYValueChartSeries(TChartSeries* ser, double x)
{
	for( int i=1; i<ser->Count(); ++i )
    {
    	const int i1 = i-1, i2 = i;
        const double x1 = ser->XValue[i1], x2 = ser->XValue[i2];
    	if( x1<=x && x2>=x )
        {
        	const double d1 = x-x1, d2 = x2 - x;
            return d1<d2 ? i1 : i2;
        }
    }
    return -1;
}

TColor GetNextSeriesColor( TChart *chrt )
{
	const TColor baseClrs[] = { clRed, clBlue, clMaroon, clGreen, clNavy, clBlack,
    	clPurple, clFuchsia, clTeal, clOlive, clLime };
    const unsigned
    	baseClrsCount = array_size(baseClrs),
    	seriesCount = chrt->SeriesCount();
    return baseClrs[ seriesCount % baseClrsCount ];
}
//------------------------------------------------------------------------------

void MySaveTChartSeries( std::ostream &strm,
	TChartSeries* ser )
{
	Private::WriteStr( strm, ser->Title );
    const bool extractDateTime = ser->XValues->DateTime;
    STRM_WRITE_(strm, extractDateTime);
    const TColor seriesColor = ser->SeriesColor;
    STRM_WRITE_(strm, seriesColor);
    const unsigned pointsCount = ser->Count();
    STRM_WRITE_(strm, pointsCount);
    for( unsigned nPt=0; nPt<pointsCount; ++nPt )
    {
    	const double x = ser->XValues->Value[nPt], y = ser->YValues->Value[nPt];
        STRM_WRITE_(strm, x);
        STRM_WRITE_(strm, y);
    }
}
void MySaveTChartToFile_throw( const AnsiString &fn, TChart* chrt, const AnsiString& note )
{
	std::ofstream strm( fn.c_str(), std::ios::binary );
    const AutoCloseFileStreamHelper<std::ofstream> acfstrm(strm);
    Private::crc16_ = MY_CRC16_OFFSET;

    Private::WriteStr( strm, FILE_GRAPH_HEAD_STRING );
    Private::WriteStr( strm, note );
    Private::WriteStr( strm, chrt->LeftAxis->AxisValuesFormat );
    Private::WriteStr( strm, chrt->BottomAxis->AxisValuesFormat );

    const unsigned seriesCount = chrt->SeriesCount();
    STRM_WRITE_(strm, seriesCount);

    std::vector<TChartSeries*> series(seriesCount, NULL);

    for( unsigned nSeries=0; nSeries<seriesCount; ++nSeries )
    {
    	TChartSeries *ser = chrt->Series[nSeries];
        if(ser==NULL) continue;
        #define SAVE_SERIES_TYPE_IF_IT_IS_(ss) \
        if( T##ss##Series *##ss##Series = dynamic_cast<T##ss##Series*>(ser) )\
            Private::WriteStr( strm, #ss )

        SAVE_SERIES_TYPE_IF_IT_IS_(FastLine); else
        SAVE_SERIES_TYPE_IF_IT_IS_(Point); else
        continue;
        MySaveTChartSeries( strm, ser );
        #undef SAVE_SERIES_TYPE_IF_IT_IS_(ss)
    }
    STRM_WRITE_(strm, Private::crc16_);
}

bool MySaveTChartToTextFile( const AnsiString &fn, TChart* chrt  )
{
	//boost::shared_ptr<TFrmWait> formWait( new TFrmWait(NULL) );
    //formWait->Show();
    //formWait->Repaint();
    try
    {
    	MySaveTChartToFile_throw( fn, chrt, "" );
        return true;
    }
    catch( const PMyExcpt &excpt )
    {
    	const MyErrorFileStreamException *eFileStream = excpt->As<MyErrorFileStreamException>();
    	if( eFileStream==NULL )
        	throw;
        const AnsiString
        	dlgTtl = "Ошибка обращения к файлу!",
            errMsg = fn+"\n"+eFileStream->Message();
        //formWait.reset();
        ::MessageBox( Application->Handle, errMsg.c_str(), dlgTtl.c_str(), MB_OK |
        	MB_APPLMODAL | MB_ICONERROR );
        return false;
    }
}
//------------------------------------------------------------------------------


void ClearTChartSeries( TChart *chrt )
{
	while( chrt->SeriesCount()>0 )
    	chrt->Series[0]->ParentChart = NULL;
}
//------------------------------------------------------------------------------

MyChartSeriesList StoreChartSeriesList( TChart *chrt )
{
	MyChartSeriesList ret;
	for( unsigned i=0; i<(unsigned)chrt->SeriesCount(); ++i )
    	ret.push_back( chrt->Series[i] );
    return ret;
}
//------------------------------------------------------------------------------
void RestoreChartSeriesList( TChart *chrt, const MyChartSeriesList &oldChartSeriesList )
{
	ClearTChartSeries( chrt );
    for( unsigned i=0; i<oldChartSeriesList.size(); ++i )
    	oldChartSeriesList[i]->ParentChart = chrt;
}
//------------------------------------------------------------------------------
void DeleteSeriesOfChartSeriesList( const MyChartSeriesList &chartSeriesList )
{
    for( unsigned i=0; i<chartSeriesList.size(); ++i )
    	delete chartSeriesList[i];
}
//------------------------------------------------------------------------------
void MyLoadTChartSeries( std::istream &strm, TChartSeries* ser )
{
	//ser->XValues->DateTime = true;
    ser->ParentChart = NULL;
	ser->Clear();
    ser->Title = Private::ReadStr( strm );

    bool extractDateTime = 0;
    STRM_READ_(strm, extractDateTime);
    ser->XValues->DateTime = extractDateTime;

    TColor seriesColor;
    STRM_READ_(strm, seriesColor);
    ser->SeriesColor = seriesColor;

    unsigned pointsCount;
    STRM_READ_(strm, pointsCount);

    for( unsigned nPt=0; nPt<pointsCount; ++nPt )
    {
    	double x, y;
        STRM_READ_(strm, x);
        STRM_READ_(strm, y);
        try
        {
        	ser->AddXY(x,y);
        }
        catch(...)
        {
        	MY_THROW_CLASS_(MyErrorGraphFileFormatException, "Неверный формат файла.");
        }
    }
}
//------------------------------------------------------------------------------
MyChartSeriesList MyLoadTChartFromFile_throw( const AnsiString &fn,
    AnsiString& note, AnsiString& leftAxisValuesFormat, AnsiString& bottomAxisValuesFormat,
    TChart *chrt )
{
	MyChartSeriesList seriesList;

	std::ifstream strm( fn.c_str(), std::ios::binary );
    if( strm.fail() )
    	//throw ErrorFileStream();
        MY_THROW_CLASS_(MyErrorFileStreamException, "Ошибка обращения к файлу.");

    const AutoCloseFileStreamHelper<std::ifstream> acfstrm(strm);
    Private::crc16_ = MY_CRC16_OFFSET;
    const AnsiString fileGraphHeadString =  Private::ReadStr( strm );
    if(fileGraphHeadString!=FILE_GRAPH_HEAD_STRING)
    	//throw ErrorGraphFileFormat();
        MY_THROW_CLASS_(MyErrorGraphFileFormatException, "Неверный формат файла.");

    note = Private::ReadStr( strm );
    leftAxisValuesFormat   = Private::ReadStr( strm );
    bottomAxisValuesFormat = Private::ReadStr( strm );

    unsigned seriesCount;
    STRM_READ_(strm, seriesCount);

    for( unsigned nSeries=0; nSeries<seriesCount; ++nSeries )
    {
        TChartSeries *ser = NULL;
        const AnsiString seriesType =  Private::ReadStr( strm );

        #define LOAD_SERIES_TYPE_IF_IT_IS_(ss) \
        if(seriesType==#ss)\
            ser = new T##ss##Series(chrt)
        LOAD_SERIES_TYPE_IF_IT_IS_(FastLine); else
        LOAD_SERIES_TYPE_IF_IT_IS_(Point);
        #undef LOAD_SERIES_TYPE_IF_IT_IS_(ss)
        if(ser==0)
            MY_THROW_CLASS_(MyErrorGraphFileFormatException, "Неверный тип графика.");
    	MyLoadTChartSeries( strm, ser );
        seriesList.push_back( ser );
    }
    return  seriesList;
}
//------------------------------------------------------------------------------
bool MyLoadTChartFromFile( const AnsiString &fn, TChart* chrt, AnsiString& note  )
{
	//boost::shared_ptr<TFrmWait> formWait( new TFrmWait(NULL) );
    //formWait->Show();
    //formWait->Repaint();
    MyChartSeriesList oldChartSeriesList = StoreChartSeriesList( chrt ), newChartSeriesList;
    ClearTChartSeries( chrt );
    try
    {
        AnsiString leftAxisValuesFormat, bottomAxisValuesFormat;
    	newChartSeriesList = MyLoadTChartFromFile_throw( fn, note,
            leftAxisValuesFormat, bottomAxisValuesFormat, chrt );
        DeleteSeriesOfChartSeriesList( oldChartSeriesList );
        RestoreChartSeriesList( chrt, newChartSeriesList );
        chrt->LeftAxis->AxisValuesFormat = leftAxisValuesFormat;
        chrt->BottomAxis->AxisValuesFormat = bottomAxisValuesFormat;
        return true;
    }
    catch( const PMyExcpt &excpt )
    {
        //formWait.reset();
        chrt->Repaint();
        const AnsiString errMsg = fn+"\n"+excpt->Message();
    	::MessageBox( Application->Handle, errMsg.c_str(), "Ошибка обращения к файлу!", MB_OK |
        	MB_APPLMODAL | MB_ICONERROR );

        DeleteSeriesOfChartSeriesList( newChartSeriesList );
        RestoreChartSeriesList( chrt, oldChartSeriesList );
        chrt->Repaint();
        return false;
    }
}
//------------------------------------------------------------------------------
void ClearChartInXInterval(TChart *chrt, double xMin, double xMax)
{
    for( int nSer=0; nSer<chrt->SeriesCount(); ++nSer )
    {
    	TChartSeries *ser = chrt->Series[nSer];
        for( int nPt=0; nPt<ser->Count(); ++nPt )
        {
        	const double x = ser->XValues->Value[nPt], y = ser->YValues->Value[nPt];
            if( x>=xMin && x<=xMax )
            	ser->Delete(nPt--);
        }
    }
}

