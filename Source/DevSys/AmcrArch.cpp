//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "AmcrArch.h"
#include "MyExcpt.hpp"
#include "guicon.h"
#include "TransferManage.h"
//------------------------------------------------------------------------------
#include <math>
#include <DateUtils.hpp>

#include "AnsiStringUtils_.h"
#include "MySynchronize.h"


//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------

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
AnsiString FormatDateTimeRange( TDateTime dateTime1, TDateTime dateTime2 )
{
    Word AYear1, AMonth1, ADay1, AHour1, AMinute1, ASecond, AMilliSecond,
        AYear2, AMonth2, ADay2, AHour2, AMinute2;

    DecodeDate(dateTime1, AYear1, AMonth1, ADay1);
    DecodeDate(dateTime2, AYear2, AMonth2, ADay2);

    DecodeTime(dateTime1, AHour1, AMinute1, ASecond, AMilliSecond);
    DecodeTime(dateTime2, AHour2, AMinute2, ASecond, AMilliSecond);

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
TDateTime ExcludeDateTimeField(TDateTime dtTm, unsigned ex )
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
    unsigned ex = 0)
{
    dtTm = ExcludeDateTimeField(dtTm, ex);
    dateTime1 = ExcludeDateTimeField(dateTime1, ex);
    dateTime2 = ExcludeDateTimeField(dateTime2, ex);

    AnsiString
        sdtTm = DateTimeToStr(dtTm),
        sdateTime1 = DateTimeToStr(dateTime1),
        sdateTime2 = DateTimeToStr(dateTime2);

    if(dtTm<dateTime1)
        return LessThanValue;
    else if(dtTm>dateTime2)
        return GreaterThanValue;
    else
        return EqualsValue;
}
//------------------------------------------------------------------------------
TValueRelationship MyCompareDateTime(TDateTime dateTime1, TDateTime dateTime2, unsigned ex = 0)
{
    dateTime1 = ExcludeDateTimeField(dateTime1, ex);
    dateTime2 = ExcludeDateTimeField(dateTime2, ex);
    return CompareDateTime(dateTime1, dateTime2);
}

//------------------------------------------------------------------------------
namespace AnkatMicro
{
//------------------------------------------------------------------------------
LRESULT ArchiveImpl::SetSignalGetArchItem1(const ArchItem& itm)
{
    signalGetArchItem_.Signal1(itm);
    return 0;
}
//------------------------------------------------------------------------------
void ArchiveImpl::SetSignalGetArchItem(const ArchItem& itm)
{
    my::Synchronize1( &SetSignalGetArchItem1, itm, __FILE_LINE__ );
}
//------------------------------------------------------------------------------
boost::shared_ptr<void> ArchiveImpl::ConnectOnGetArchItem( NotifyGetArchItemFooT method )
{
    return signalGetArchItem_.GetConnections().AutoConnect(method);

}
//------------------------------------------------------------------------------
void ArchiveImpl::SetHandle(unsigned handle)
{
    Clear();
    InitializeIndexes(handle);
    MYWCOUT_("idxEnd_=%d, idx0_=%d\n",idxEnd_, idx0_));
}
//------------------------------------------------------------------------------
void ArchiveImpl::Clear()
{
    ArchItem itm;
    itm.dateTime = 0;
    itm.readedFromFlash =0;
    itm.index = -1;
    arch_.clear();
    arch_.resize( MaxLen(), itm );

    idxEnd_ = 0;
    idx0_ = 0;
}
//------------------------------------------------------------------------------
void ArchiveImpl::ReadItem(unsigned idx)
{
    GetItemFromHard( RecordIndex2Addy(idx), arch_[idx]);
    SetSignalGetArchItem( arch_[idx] );
}
//------------------------------------------------------------------------------
bool IsCorruptedIArchtem( const ArchItem &itm )
{
    const bool ret = !itm.isFF && itm.dateTime.Val==0;
    return ret;
}
//------------------------------------------------------------------------------
const ArchItem& ArchiveImpl::GetItemByIndex(unsigned idx )
{
    assert( idx<arch_.size()  );
    const ArchItem &ret = arch_[idx];
    if( !ret.readedFromFlash )
        ReadItem(idx);
    return ret;
}
//------------------------------------------------------------------------------
void ArchiveImpl::InitializeIndexes(unsigned handle)
{
    MYWCOUT_("Поиск границ массива \"%s\":%d\n", What(), Addy2RecordIndex(handle) ));

    using namespace Flash;
    idxEnd_ = IncIdx( Addy2RecordIndex(handle), -10 );
    idx0_ = 0;
    // утоть индекс конца списка
    
    for( int i=0; i<100; ++i )
    {
        const unsigned idx = IncIdx( idxEnd_, 1);
        GetItemByIndex( idxEnd_ );
        GetItemByIndex( idx );
        const bool
            isValidEnd = IsValidItem(arch_[idxEnd_]),
            isValidNextEnd = IsValidItem(arch_[idx]);
        if( isValidEnd && !isValidNextEnd )
            return;
        if( isValidEnd && isValidNextEnd &&
            arch_[idxEnd_].dateTime.Val !=0 &&
            arch_[idx].dateTime.Val != 0 &&
            arch_[idxEnd_].dateTime>arch_[idx].dateTime)
        {
            if( idxEnd_!=MaxLen()-1)
                idx0_ = idx;
            return;
        }
        idxEnd_ = IncIdx( idxEnd_, 1);
    }

    if( !IsValidItem(arch_[idxEnd_]) )
        MY_THROW_( What()+": не обнаружен действительный элемент.");
}
//------------------------------------------------------------------------------
unsigned ArchiveImpl::FindDateTimeMidle(unsigned i0, unsigned i1, TDateTime dateTime1, TDateTime dateTime2)
{
    if(i0>=i1) return i0;
    dateTime1 = ExcludeDateTimeField(dateTime1, IgnoreTime::sec);
    dateTime2 = ExcludeDateTimeField(dateTime2, IgnoreTime::sec);
    if( TransferManager::Instance().IsThreadStopedOrTerminated() ) return -1;
    const ArchItem &itm0 = GetItemByIndex(i0), &itm1 = GetItemByIndex(i1);

    if( IsCorruptedIArchtem(itm0) ) return FindDateTimeMidle(i0+1, i1, dateTime1, dateTime2);
    if( IsCorruptedIArchtem(itm1) ) return FindDateTimeMidle(i0, i1+1, dateTime1, dateTime2);

    const double
        dtTm0 = arch_[i0].dateTime.Val,
        dtTm1 = arch_[i1].dateTime.Val;

    if( MyCompareDateTimeRange(dtTm0, dateTime1, dateTime2)==EqualsValue ) return i0;
    if( MyCompareDateTimeRange(dtTm1, dateTime1, dateTime2)==EqualsValue ) return i1;
    if(i1==i0+1) return i0;

    unsigned i_ = (i0+i1)/2;
    for( ; IsCorruptedIArchtem(GetItemByIndex( i_ )); ++i_ ) ;
    if(i_==i1) return i1;

    const double dtTm_ = arch_[i_].dateTime.Val;

    AnsiString
        sdtTm_ = DateTimeToStr(dtTm_),
        sdtTm0 = DateTimeToStr(dtTm0),
        sdtTm1 = DateTimeToStr(dtTm1),
        sdateTime1 = DateTimeToStr(dateTime1),
        sdateTime2 = DateTimeToStr(dateTime2);

    const TValueRelationship relVal = MyCompareDateTimeRange(dtTm_, dateTime1, dateTime2);
    if( relVal==EqualsValue ) return i_;
    if( relVal==LessThanValue )
        return FindDateTimeMidle(i_, i1, dateTime1, dateTime2 );
    if( relVal==GreaterThanValue )
        return FindDateTimeMidle(i0, i_, dateTime1, dateTime2 );
    return -1;
}
//------------------------------------------------------------------------------
std::pair<unsigned,unsigned> ArchiveImpl::FindDateTime(TDateTime dateTime1, TDateTime dateTime2)
{
    TransferManagerT &tmngr = TransferManager::Instance();

    

    const AnsiString
        sDtTm = FormatDateTimeRange( dateTime1, dateTime2),
        strSearch = MYSPRINTF_( "%s: поиск %s", What(), sDtTm );
    MYWCOUT_("%s\n", strSearch ));

    tmngr.HideTopPanel();
    tmngr.ShowTopPanel(strSearch+". Определение границ...");

    unsigned
        idx0 = FindDateTimeMidle(0, idxEnd_, dateTime1, dateTime1 ),
        idx1 = FindDateTimeMidle(0, idxEnd_, dateTime2, dateTime2 );
    if(idx0==-1)
        idx0 = FindDateTimeMidle(idxEnd_, MaxLen()-1, dateTime1, dateTime1 );
    if(idx1==-1)
        idx1 = FindDateTimeMidle(idxEnd_, MaxLen()-1, dateTime2, dateTime2 );
    MYWCOUT_("%s: idx0=%d idx1=%d\n", strSearch, idx0, idx1 ));

    tmngr.HideTopPanel();


    if(idx0==-1 || idx1==-1) return std::make_pair(-1,-1);

    const TDateTime
        dateTime1End = GetItem(idx0).dateTime,
        dateTime2End = GetItem(idx1).dateTime;
    const unsigned count = std::abs( (int)idx1-(int)idx0);
    const AnsiString
        sDtTmEnd = FormatDateTimeRange( dateTime1End, dateTime2End),
        msg = MYSPRINTF_( "%s: считывание %d элементов %s...",
        What(), count, sDtTmEnd);

    tmngr.ShowTopPanel( msg, true);
    tmngr.SetTopPanelProgress( 0, count, 0 );

    for( unsigned idx=idx0; idx!=idx1 && !tmngr.IsThreadStopedOrTerminated() ; idx = IncIdx(idx,1) )
    {
        const unsigned prevIdx = IncIdx(idx,-1);
        GetItemByIndex(idx);
        GetItemByIndex(prevIdx);
        ArchItem &itm = arch_.at(idx), &prev = arch_.at(prevIdx);
        if(prev.dateTime.Val!=0 && itm.dateTime.Val==0)
        {
            AnsiString s = DateTimeToStr(prev.dateTime);
            itm.dateTime = prev.dateTime;
        }
        tmngr.SetTopPanelProgress( -2 );
    }

    return std::make_pair(idx0,idx1);
}
//------------------------------------------------------------------------------
}; //namespace AnkatMicro
//------------------------------------------------------------------------------


