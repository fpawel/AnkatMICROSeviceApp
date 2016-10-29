//---------------------------------------------------------------------------
#ifndef MY_IOSTREAM_EXTENSION_HEADER_INCLUDED____
#define MY_IOSTREAM_EXTENSION_HEADER_INCLUDED____
//---------------------------------------------------------------------------
//std
#include <iostream>
#include <algorithm>
#include <iterator>

// boost
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
#include "boost\io\ios_state.hpp"

//vcl
#include <SysUtils.hpp>

namespace Private
{
	// для инициализации ядра std::ios_base
	const std::ios_base::Init myIosBaseInit;
	const std::ios_base::_Loc_init myIosBaseLocInit;
};

/*
//------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& strm, const AnsiString& s )
{
	strm << s.c_str();
    return strm;
}
//------------------------------------------------------------------------------
std::istream& operator>>(std::istream& strm, AnsiString& s )
{
    std::string ss;
	strm >> ss;
    s = ss.c_str();
    return strm;
}
//------------------------------------------------------------------------------
*/
//------------------------------------------------------------------------------

template<class StreamType>
class AutoCloseFileStreamHelper : public boost::noncopyable
{
public:
    explicit AutoCloseFileStreamHelper( StreamType& strm ) : strm_(strm)
    {}
    ~AutoCloseFileStreamHelper()
    {
        strm_.close();
    }
private:
    StreamType& strm_;

};

std::size_t GetStreamSize(std::istream& strm)
{
	const std::size_t posG = strm.tellg();

	strm.seekg(0, std::ios::beg);
    const std::size_t pos1 = strm.tellg();

    strm.seekg(0, std::ios::end);
    const std::size_t pos2 = strm.tellg();

    strm.seekg(posG, std::ios::beg);

    return pos2-pos1;
}

std::string GetStringOfInputStream(std::istream& sstrm)
{
	std::string s2,s3;
    sstrm >> s2;
    sstrm >> s3;
    for( ; !sstrm.fail(); sstrm >> s3 )
    	if( !s3.empty() )
        	s2 += " "+s3;
    return s2;

}


////////////////////////////////////////////////////////////////////////////////
//				Манипуляторы
////////////////////////////////////////////////////////////////////////////////
namespace myIO
{

class AutoQuote : public boost::noncopyable
{
public:
	AutoQuote( std::ostream& strm, const std::string& s ) : strm_(strm), s_(s)
    {
    	strm_ << "<" << s_ << ">\n";

    }
    ~AutoQuote()
    {
    	strm_<< "<\\" << s_ << ">\n";
    }
private:
	std::ostream& strm_;
	const std::string s_;

};
//------------------------------------------------------------------------------

//---------------------------------------------------------------------------
template<typename Iter, typename OutT> struct OutVecHlpr
{
	typedef OutT OutType;
	const Iter b_, e_;
    const char *delim_;

    template<class I>
    explicit OutVecHlpr(I b, I e, const char *delim) :
    	b_(b), e_( e ), delim_(delim)
    {}

    template <class Container>
    OutVecHlpr(const Container& container, const char *delim) :
    	b_( container.begin() ), e_( container.end() ), delim_(delim)
    {}
};
//---------------------------------------------------------------------------
typedef OutVecHlpr< const double*,			double > OutDoubleVec;
typedef OutVecHlpr< const int*, 			int > OutIntVec;
typedef OutVecHlpr< const unsigned*, 		int > OutUnsignedVec;
typedef OutVecHlpr< const unsigned char*, 	int > OutByteVec;
//---------------------------------------------------------------------------
template<typename Iter, typename OutT>
std::ostream& OutMyArray(std::ostream& strm, const Iter b, const Iter e, const char *delim)
{
	strm << "[";
    if( b!=e )
    {
    	std::copy(b, e-1, std::ostream_iterator<OutT, char>(strm,delim) );
        const OutT vv = *(e-1);
        strm << vv;
    }
    strm << "]";
    return strm;
}
//---------------------------------------------------------------------------
template<typename Iter, typename OutT> std::ostream&
operator<<(std::ostream& strm, const typename OutVecHlpr<typename Iter, typename OutT>& hlpr )
{
    return OutMyArray<Iter, OutT>(strm, hlpr.b_, hlpr.e_, hlpr.delim_);
}
//---------------------------------------------------------------------------
struct LongLine
{
	const int sz_;
    const char c_;
    explicit LongLine(int sz, char c) : sz_(sz), c_(c) {}
};
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& strm, const LongLine& o )
{
	const boost::io::ios_flags_saver  ifs( strm );
    strm.width( o.sz_ );
    strm.fill( o.c_ );
    strm << o.c_;
    return strm;
}
//---------------------------------------------------------------------------
std::ostream& Time( std::ostream& strm )
{
	strm << "<" << TimeToStr( Now() ).c_str() << ">";
    return strm;
}
//---------------------------------------------------------------------------
std::ostream& DateTime( std::ostream& strm )
{
	strm << "<" << FormatDateTime("c", Now()).c_str() << ">";
    return strm;
}
//---------------------------------------------------------------------------
}; //namespace myIO
//---------------------------------------------------------------------------

#ifdef _DEBUG
#define LOG_CURENT_LIFETIME_QUOTES(s) const myIO::AutoQuote qteCout( std::cout, s );
#else
#define LOG_CURENT_LIFETIME_QUOTES(s)
#endif

#define LOG_FOO_LIFETIME_QUOTES LOG_CURENT_LIFETIME_QUOTES(__FUNC__);
boost::shared_ptr<void> MakeMyLogQuote( const char *s )
{
	return boost::shared_ptr<void>( new myIO::AutoQuote(std::cout, s) );
}

#endif