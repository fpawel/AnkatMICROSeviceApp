//------------------------------------------------------------------------------
#ifndef MyDateTimeH
#define MyDateTimeH
//------------------------------------------------------------------------------
#include <system.hpp>
#include <Types.hpp>



namespace IgnoreTime
{
    enum
    {
        ms          = (unsigned)(1 << 0),
        sec         = (unsigned)(1 << 1),
        minute      = (unsigned)(1 << 2),
        hour        = (unsigned)(1 << 3)
    };
};
TDateTime ExcludeDateTimeField(TDateTime dtTm, unsigned exclude);

TValueRelationship MyCompareDateTimeRange(TDateTime dtTm, TDateTime dateTime1,
    TDateTime dateTime2, unsigned exclude=0);

TValueRelationship MyCompareDateTime(TDateTime dateTime1, TDateTime dateTime2, unsigned exclude=0);

AnsiString FormatDateTimeRange( TDateTime dateTime1, TDateTime dateTime2 );





//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
