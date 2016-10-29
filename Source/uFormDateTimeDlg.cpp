//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <dateutils.hpp>

#include "uFormDateTimeDlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDateTimeDlg *FormDateTimeDlg;
//---------------------------------------------------------------------------
__fastcall TFormDateTimeDlg::TFormDateTimeDlg(TComponent* Owner, TDateTime dtTm1, TDateTime dtTm2)
    : TForm(Owner)
{
    DateTimePicker5->Date = dtTm1;
    DateTimePicker1->Time = dtTm1;
    DateTimePicker2->Date = dtTm2;
    DateTimePicker3->Time = dtTm2;    
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
TFormDateTimeDlg::Interval TFormDateTimeDlg::GetResult()
{
    Word AYear1, AMonth1, ADay1, AHour1, AMinute1, ASecond, AMilliSecond,
        AYear2, AMonth2, ADay2, AHour2, AMinute2;

    DecodeDate(DateTimePicker5->Date, AYear1, AMonth1, ADay1);
    DecodeDate(DateTimePicker2->Date, AYear2, AMonth2, ADay2);
    DecodeTime(DateTimePicker1->Time, AHour1, AMinute1, ASecond, AMilliSecond);
    DecodeTime(DateTimePicker3->Time, AHour2, AMinute2, ASecond, AMilliSecond);
    return std::make_pair(
        EncodeDateTime(AYear1, AMonth1, ADay1, AHour1, AMinute1, 0, 0),
        EncodeDateTime(AYear2, AMonth2, ADay2, AHour2, AMinute2, 0, 0) );

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

