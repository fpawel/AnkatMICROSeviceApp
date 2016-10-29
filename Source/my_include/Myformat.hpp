#ifndef MY_FORMAT_HEADER_INCLUDED_____________
#define MY_FORMAT_HEADER_INCLUDED_____________
//------------------------------------------------------------------------------
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
//------------------------------------------------------------------------------
namespace my
{
//------------------------------------------------------------------------------
typedef std::vector<std::string> Strings;
//------------------------------------------------------------------------------
template<typename T> std::string FormatStringList(T b, T e,
    const std::string& strHead, const std::string& strTail)
{
    typedef std::iterator_traits<T>::value_type ValueType;

    const std::string delim = strTail+", "+strHead;
    std::stringstream strm;
    strm << strHead;
    const unsigned sz = e-b;
    if( sz==0 )
    {
        if( sz>1 )
            std::copy(b, e-1, std::ostream_iterator<ValueType, char>(strm, delim.c_str() ) );
        strm << *(e-1);
    }
    strm << strTail;
    return strm.str();
}
//------------------------------------------------------------------------------
// записать в v подстроки из строки str, разделённые символом delim
template<class Container>
void GetSubStrsDelimitedByChar(Container& v, const std::string& s,
    const std::string& delim)
{
	size_t p1 = 0, p2 = 0;
	while( p2 != std::string::npos )
	{
		p2 = s.find(delim, p1);
		v.push_back( s.substr( p1, p2-p1 ).c_str() );
		p1 = p2+1;
	}
}
//------------------------------------------------------------------------------
template<typename BitsetContainer>
std::string FormatBitset( const BitsetContainer& bs)
{
    std::stringstream ret;
    bool hasChars = false;

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

        if( !hasChars )
            ret << i;
        else
            ret << " " << i;
        hasChars = true;

        if( !(++i<sz) ) break;
        if ( !static_cast<bool>(bs[i]) )
        {
            ++i;
            continue;
        }

        ret << "-";
        for( ; i<sz && static_cast<bool>(bs[i]); ++i ) ;

        ret << i-1;
    }
    return ret.str();
}
//------------------------------------------------------------------------------
bool ValidNumericChar(const char ch, bool hex)
{
	return std::isdigit(ch) || hex && (ch>='A' && ch<='F') || (ch>='a' && ch<='f');
}
//------------------------------------------------------------------------------
namespace Private
{
    std::string Normalize2CreateBitset( const std::string& ss )
    {
        std::string ret = ss;
        for( unsigned n=0; n<ret.size(); ++n )
            if(ret[n]=='-')
            {
                ret.replace(n, 1, " - ");
                n+=2;
            }
        return ret;
    }
    bool StrToIntHex( const char *pS, unsigned& val )
    {
        int len = strlen(pS), radix = 10;
        if( len==0 ) return 0;
        if( pS[len-1]=='h' )
        {
            radix = 16;
            len = len - 1;
        }


        char *pEndS = "x";
        val = strtol( pS, &pEndS, radix);
        return pEndS-pS==len;
    }
};

//------------------------------------------------------------------------------

template<typename Container>
void CreateBitset( const std::string& srcStr, Container& bs )
{
    std::stringstream sstrm( Private::Normalize2CreateBitset( srcStr) );
    while( !sstrm.eof() )
    {
        unsigned val, val_e;
        std::string s;

        sstrm >> s;
        if( sstrm.fail() || s=="-" ) return;

        lx:
        if( !Private::StrToIntHex( s.c_str(), val ) ) return;
        if( bs.size()<val+1 )
            bs.resize( val+1 );
        bs[val] = true;

        sstrm >> s;
        if( sstrm.fail() ) return;
        if( s!="-" ) goto lx;
        
        sstrm >> s;
        if( sstrm.fail() || s=="-" ) return;
        if( !Private::StrToIntHex( s.c_str(), val_e ) ) return;

        if( bs.size()<val_e+1 )
            bs.resize( val_e+1 );
        for( ++val; val<=val_e; ++val )
            bs[val] = true;
    }
}

//------------------------------------------------------------------------------
}; //namespace my
//------------------------------------------------------------------------------



#endif