#ifndef MY_TUPLES_H_
#define MY_TUPLES_H_

#include "boost/tuple/tuple.hpp"
#include <system.hpp>
#include <vector>
#include <functional>
namespace my
{
typedef boost::tuples::tuple<unsigned char,AnsiString> ByteString;
typedef std::vector<ByteString> ByteStringData;

	template<int N, class BoostTuple>
	struct FieldEqualTo : std::unary_function
	<
		typename boost::tuples::element<N,BoostTuple >::type,
		bool
	>
	{
		typedef boost::tuples::element<N,BoostTuple>::type
		ValueType;
		const ValueType v_;
		explicit FieldEqualTo(ValueType v) : v_(v)
		{
		}
		inline bool operator()(BoostTuple& item) const
		{
			return boost::tuples::get<N>(item)==v_;
		}
	};

	// зарегать элемент в таблице  (byte,AnsiString)
	inline bool RegisterNewByteString( byte code, AnsiString s, ByteStringData& vec )
	{

		ByteStringData::iterator beg = vec.begin(), end = vec.end();
		FieldEqualTo<0, ByteString > pred0(code);
		FieldEqualTo<1, ByteString > pred1(s);

		while (beg != end)
		{
			if( pred0(*beg) || pred1(*beg) ) return false;
			++beg;
		}
		vec.push_back( boost::tuples::make_tuple(code,s) );
		return true;
	}




};
#endif