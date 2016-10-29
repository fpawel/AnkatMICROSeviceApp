#ifndef MY_IS_FIELD_EQUAL_TO_H_INCLUDED_____
#define MY_IS_FIELD_EQUAL_TO_H_INCLUDED_____

namespace my
{
	template<int N, typename ArgT, typename BoostTuple>
	bool IsFieldEqualTo(const ArgT& arg, const BoostTuple& tpl )
	{
		return boost::tuples::get<N>()==arg_;		
	}
};
#endif