#ifndef MY_INTERVAL_UTILS_HEADER_INCLUDED________
#define MY_INTERVAL_UTILS_HEADER_INCLUDED________

//------------------------------------------------------------------------------
namespace my
{
//------------------------------------------------------------------------------
    namespace Private
    {
        template <typename T>
        std::pair<T,T> NormalizeInterval(T v1, T v2)
        {
            return std::make_pair( std::min(v1,v2), std::max(v1,v2) );
        }


        template <typename ArrayOfInterval, typename Interval>
        void AddIntervalToSortedArrayOfIntervals(ArrayOfInterval& arrayOfIntervals,
            Interval& interval, unsigned delimValue)
        {
            Interval::first_type fst = interval.first;
            for( Interval::first_type i = interval.first; i<=interval.second; ++i)
            {
                if ( i && !(i % delimValue) )
                {
                    arrayOfIntervals.push_back( NormalizeInterval(fst,i-1) );
                   fst = i;
                }
            }
            arrayOfIntervals.push_back( NormalizeInterval( fst, interval.second ) );
        }
    };



template <typename ArrayOfInterval, typename BitSet>
void ExteractArrayOfInterval(const BitSet& bs, ArrayOfInterval& intervals)
{
    intervals.clear();
    if( bs.empty() ) return;
    const size_t sz = bs.size();
    size_t i=0;
    while( i<sz )
    {
        if ( !static_cast<bool>(bs[i]) )
        {
            ++i;
            continue;
        }
        if( !(i<sz) ) break;
        intervals.push_back( std::make_pair( i, i) );


        if( !(++i<sz) ) break;

        if ( !static_cast<bool>(bs[i]) )
        {
            ++i;
            continue;
        }
        for( ; i<sz && static_cast<bool>(bs[i]); ++i ) ;
        intervals.back().second = i-1;
    }
}

template <typename ArrayOfInterval>
void NormalizeArrayOfInterval( ArrayOfInterval& intervals, unsigned delimValue )
{
    ArrayOfInterval normalizedIntervals;
    std::sort( intervals.begin(), intervals.end() ); 

    for( ArrayOfInterval::const_iterator i = intervals.begin(); i!=intervals.end(); ++i )
        Private::AddIntervalToSortedArrayOfIntervals( normalizedIntervals, *i, delimValue);

    intervals = normalizedIntervals;
}

template <typename ArrayOfInterval>
unsigned SummarySizeOfIntervals( const ArrayOfInterval& intervals )
{
    unsigned ret = 0;
    for( ArrayOfInterval::const_iterator i = intervals.begin(); i!=intervals.end(); ++i )
        ret += (i->second-i->first);
    return ret;
}

//------------------------------------------------------------------------------
}; // namespace my
//------------------------------------------------------------------------------
#endif