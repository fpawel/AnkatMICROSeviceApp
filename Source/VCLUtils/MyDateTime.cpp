//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "MyDateTime.h"
//------------------------------------------------------------------------------
#include <DateUtils.hpp>
#include "AnsiStringUtils_.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
AnsiString FormatDateTimeRange( TDateTime dateTime1, TDateTime dateTime2 )
{
    Word AYear1, AMonth1, ADay1, AHour1, AMinute1, ASecond, AMilliSecond,
        AYear2, AMonth2, ADay2, AHour2, AMinute2;

    DecodeDate(dateTime1, AYear1, AMonth1, ADay1);
    DecodeDate(dateTime2, AYear2, AMonth2, ADay2);
    return AYear1==AYear2 && AMonth1==AMonth2 && ADay1==ADay2 ?
        MYSPRINTF_("%s %s-%s",
            FormatDateTime( "dd.mm.yy", dateTime1),
            FormatDateTime( "hh:nn", dateTime1),
            FormatDateTime( "hh:nn", dateTime2) ) :
        MYSPRINTF_("%s-%s",
            FormatDateTime( "dd.mm.yy, hh:nn", dateTime1),
            FormatDateTime( "dd.mm.yy, hh:nn", dateTime2) );
}
//------------------------------------------------------------------------------
TDateTime ExcludeDateTimeField(TDateTime dtTm, unsigned ex)
{
    Word AYear, AMonth, ADay, AHour, AMinute, ASecond, AMilliSecond;
    DecodeDateTime(dtTm, AYear, AMonth, ADay, AHour, AMinute, ASecond, AMilliSecond);
    using namespace IgnoreTime;

    if( ex ) AMilliSecond = 0;
    if( ex >= sec ) ASecond = 0;
    if( ex >= minute ) AMinute = 0;
    if( ex >= hour ) AHour = 0;

    return EncodeDateTime(AYear, AMonth, ADay, AHour, AMinute, ASecond, AMilliSecond);
}
//------------------------------------------------------------------------------
TValueRelationship MyCompareDateTimeRange(TDateTime dtTm, TDateTime dateTime1, TDateTime dateTime2,
    unsigned ex)
{
    dtTm = ExcludeDateTimeField(dtTm, ex);
    dateTime1 = ExcludeDateTimeField(dateTime1, ex);
    dateTime2 = ExcludeDateTimeField(dateTime2, ex);

    const TValueRelationship
        rel1 = CompareDateTime(dtTm,dateTime1),
        rel2 = CompareDateTime(dtTm,dateTime2);
    if(rel1==EqualsValue || rel2==EqualsValue)
        return EqualsValue;
    if(rel1==LessThanValue)
        return LessThanValue;
    return GreaterThanValue;
}
//------------------------------------------------------------------------------
TValueRelationship MyCompareDateTime(TDateTime dateTime1, TDateTime dateTime2, unsigned ex)
{
    dateTime1 = ExcludeDateTimeField(dateTime1, ex);
    dateTime2 = ExcludeDateTimeField(dateTime2, ex);
    return CompareDateTime(dateTime1, dateTime2);
}
