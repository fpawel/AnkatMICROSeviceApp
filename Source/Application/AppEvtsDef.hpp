#ifndef APPLICATON_EVENTS_JOURNAL_DEFINITIONS_HEADER_INCLUDED_____
#define APPLICATON_EVENTS_JOURNAL_DEFINITIONS_HEADER_INCLUDED_____

#include <vector>
#include <dateutils.hpp>

//---------------------------------------------------------------------------
struct MyEvt
{
    TDateTime date_;
    unsigned number_;
    AnsiString id_, content_, note_;
    bool showMessage_;
};
typedef std::vector<MyEvt> MyEvts;

bool operator==( const MyEvt& lhs, const MyEvt& rhs )
{
    const bool ret =
        lhs.date_ == rhs.date_ &&
        lhs.number_ == rhs.number_
    ;
    return ret;
}


bool operator<( const MyEvt& lhs, const MyEvt& rhs )
{
    if( lhs.date_<rhs.date_ )
        return true;
    else
    {
        if( lhs.date_>rhs.date_ )
            return false;
        else
            return lhs.number_<rhs.number_;
    }
}

//---------------------------------------------------------------------------

#endif
