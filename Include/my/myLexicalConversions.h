//---------------------------------------------------------------------------
#ifndef MY_LEXICAL_CONVERSIONS_H_INCLUDED_
#define MY_LEXICAL_CONVERSIONS_H_INCLUDED_
//---------------------------------------------------------------------------
#include <sstream>
#include <system.hpp>
#include <iterator>
#include <string>
#include <iomanip>

inline std::ostream& operator<<(std::ostream& stream, AnsiString s)
{
	stream << s.c_str();
	return stream;
}

inline std::istream& operator>>(std::istream& stream, AnsiString& s)
{
	std::string stdString;
	stream >> stdString;
	s = stdString.c_str();
	return stream;
}

namespace my
{
	template< typename Iterator >
	AnsiString HexArrToStr( Iterator beg, Iterator end )
	{
		using std::ios;
		std::stringstream sstr;
		ios::fmtflags flags = sstr.flags() | ios::hex | ios::uppercase;
		sstr << setiosflags( flags ) << std::setbase(16);
		std::copy(beg, end,	std::ostream_iterator<int>(sstr," ") );
		AnsiString s = sstr.str().c_str();
		return AnsiString(sstr.str().c_str());
	}

	template< typename Iterator >
	AnsiString IntArrToStr( Iterator beg, Iterator end )
	{
		using std::ios;
		std::stringstream sstr;
		std::copy(beg, end,	std::ostream_iterator<int>(sstr," ") );
		AnsiString s = sstr.str().c_str();
		return AnsiString(sstr.str().c_str());
	}


	template< typename Container >
	void StrToIntArr( Container& dat, const char* const s )
	{
		std::stringstream sstr( s );
		std::copy(std::istream_iterator<int>(sstr),
			std::istream_iterator<int>(),
			std::back_inserter(dat) );
	}
	AnsiString RplcT4kZap( AnsiString s )
	{
		if( const int pos = s.Pos('.') )
			s[pos] = ',';
		return s;
	}

};



//---------------------------------------------------------------------------
#endif// #ifndef MY_LEXICAL_CONVERSIONS_H_INCLUDED_
//---------------------------------------------------------------------------
