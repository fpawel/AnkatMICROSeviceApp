//---------------------------------------------------------------------------
#ifndef myGeomtrH
#define myGeomtrH
//---------------------------------------------------------------------------
// #include <types.hpp>
//---------------------------------------------------------------------------
#include <utility>
#include <Types.hpp>
//---------------------------------------------------------------------------
#include "boost\tuple\tuple.hpp"
#include "boost\tuple\tuple_comparison.hpp"

TPoint GetCenterPosition( TRect rect, int w, int h )
{
    return
	    TPoint( rect.left+static_cast<int>( ( rect.Width() - w ) / 2),
			rect.Top+static_cast<int>( ( rect.Height() - h ) / 2) );
}

namespace boost
{
	namespace tuples
    {
		template<typename T>
    	T Left(const typename tuple<T,T,T,T>& rect)
    	{
    		return rect.get<0>();
    	}

        template<typename T>
    	T Top(const typename tuple<T,T,T,T>& rect)
    	{
    		return rect.get<1>();
    	}

        template<typename T>
    	T Right(const typename tuple<T,T,T,T>& rect)
    	{
    		return rect.get<2>();
    	}

        template<typename T>
    	T Bottom(const typename tuple<T,T,T,T>& rect)
    	{
    		return rect.get<3>();
    	}

        template<typename T>
    	typename tuple<T,T> LeftTop(const typename tuple<T,T,T,T>& rect)
    	{
    		return make_tuple( Left(rect), Top(rect) );
    	}

        template<typename T>
    	typename tuple<T,T> RightBottom(const typename tuple<T,T,T,T>& rect)
    	{
    		return make_tuple( Right(rect), Bottom(rect) );
    	}

        template<typename T>
    	typename tuple<T,T> LeftBottom(const typename tuple<T,T,T,T>& rect)
    	{
    		return make_tuple( Left(rect), Bottom(rect) );
    	}

        template<typename T>
    	typename tuple<T,T> RightTop(const typename tuple<T,T,T,T>& rect)
    	{
    		return make_tuple( Right(rect), Top(rect) );
    	}


        template<typename T>
    	T X(const typename tuple<T,T>& pt)
    	{
    		return pt.get<0>();
    	}

        template<typename T>
    	T Y(const typename tuple<T,T>& pt)
    	{
    		return pt.get<1>();
    	}

        template<typename T>
        bool PointInRect( const typename tuple<T,T>& pt,
        	const typename tuple<T,T,T,T>& rect)
        {
        	return
            X(pt)>=Left(rect) && X(pt)<=Right(rect) &&
            	Y(pt)>=Top(rect) && Y(pt)<=Bottom(rect);
        }

        template<typename T>
        bool PointInsideRect( const typename tuple<T,T>& pt,
        	const typename tuple<T,T,T,T>& rect)
        {
        	return
            X(pt)>Left(rect) && X(pt)<Right(rect) &&
            	Y(pt)>Top(rect) && Y(pt)<Bottom(rect);
        }

        template<typename T>
        bool AreRectsIntersected(const typename tuple<T,T,T,T>& lhs,
        	const typename tuple<T,T,T,T>& rhs)
		{
    		return
            PointInRect( LeftTop(lhs), rhs ) ||
            PointInRect( LeftBottom(lhs), rhs ) ||
            PointInRect( RightTop(lhs), rhs ) ||
            PointInRect( RightBottom(lhs), rhs )
            ;
		}


    };
};

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
