//---------------------------------------------------------------------------
#ifndef MY_BOOST_DYNAMIC_BITSET_HELPER_INCLUDED___
#define MY_BOOST_DYNAMIC_BITSET_HELPER_INCLUDED___
//---------------------------------------------------------------------------
// boost
#include "boost\dynamic_bitset.hpp"
//---------------------------------------------------------------------------
// std
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
//---------------------------------------------------------------------------

namespace my
{
	std::string BitsetToStrF(boost::dynamic_bitset<> bs)
    {
    	std::stringstream ret;
        bool hasChars = false;

    	const size_t sz = bs.size();
        size_t i=0;
    	while( i<sz )
        {

            if ( !bs[i] )
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
            if ( !bs[i] )
            {
                ++i;
                continue;
            }

            ret << "-";
            for( ; i<sz && bs[i]; ++i ) ;

            ret << i-1;

        }
        return ret.str();
    }

    boost::dynamic_bitset<> StrFToBitset( const std::string& s )
    {

    	using boost::dynamic_bitset;
    	dynamic_bitset<> bs(0);
        std::stringstream ss(s);
        while( !ss.eof() )
        {
        	size_t val;
            char ch;

            ss >> ch;
            if( ss.fail() || ch=='-' ) return bs;
            ss.putback(ch);

            ss >> val;
            if( ss.fail() ) return bs;

            if( bs.size()<val+1 )
            	bs.resize( val+1 );
            bs[val] = true;

            ss >> ch;
            if( ss.fail() ) return bs;
            if( ch!='-' )
            {
            	ss.putback(ch);
                continue;
            }

            size_t val_e;
            ss >> val_e;
            if( ss.fail() ) return bs;
            if( bs.size()<val_e+1 )
            	bs.resize( val_e+1 );


            for( ++val; val<=val_e; ++val )
              	bs[val] = true;
        }
        return bs;
    }


	template<typename IntType>
	boost::dynamic_bitset<> IntToBitset(IntType n)
    {
    	int sz = sizeof(n)*8;
		boost::dynamic_bitset<> bs(sz,n);
		for( ; sz; --sz )
			if( bs[sz-1] ) break;
		bs.resize(sz);
        return bs;
    }


	template<typename IntType>
	std::string IntToBin(IntType n)
	{
		boost::dynamic_bitset<> bs = IntToBitset<IntType>(n);
        if( !bs.size() ) return "";
		std::string s;
		boost::to_string(bs,s);
		return s;
	}

	template<typename IntType, typename StrType>
	std::pair<IntType,bool> BinToInt(StrType in)
	{
		typedef std::pair<IntType,bool> ResType;
		const std::string s(in);
		for( int i=s.size(); i; --i )
			if(s[i-1]!='0'&&s[i-1]!='1') return ResType(0,false);
		return
		ResType
		(
			static_cast<IntType>(boost::dynamic_bitset<>(s).to_ulong() ),
			true
		);
	}

	template <typename Iterator>
	void ArrToBitSet( boost::dynamic_bitset<>& bs, Iterator beg, Iterator end )
	{
		const Iterator maxItr = std::max_element(beg,end);
		if(maxItr==end) return ;
		bs.resize( *maxItr+1 );
		while( beg!=end )
			bs[*beg++] = true;
	}


	template <typename Container>
	void ArrToBitSet( boost::dynamic_bitset<>& bs, Container dat )
	{
		return ArrToBitSet<Container::iterator>( bs, dat.begin(), dat.end() );
	}

	std::vector<size_t> BitSetToArr( const boost::dynamic_bitset<>& bs )
	{
		std::vector<size_t> ret( bs.count() );
		size_t idxBs = bs.find_first(), idxRet = 0;
		while( idxBs != boost::dynamic_bitset<>::npos )
		{
			ret.at(idxRet++) = idxBs;
			idxBs = bs.find_next(idxBs);
		}
		return ret;
	}

    // формировать boost::dynamic_bitset<> из произвольного буфера
    void MakeBitset(boost::dynamic_bitset<>& bs, const void *pBuff, unsigned bitsCount)
    {
    	//const unsigned buffLen = (bitsCount / 8) + (bitsCount % 8 ? 1 : 0);
    	bs.resize(bitsCount);
        unsigned byteSt=0, bitIdx=0;
        const char* p = reinterpret_cast<const char*>(pBuff);


        for( ; bitIdx<bitsCount; ++byteSt, ++p )
        {
        	const unsigned char aByte = *p;
        	for( unsigned i=0; (i<8) && bitIdx<bitsCount; ++i, ++bitIdx  )
            {
                const bool val = aByte & (1 << i);
                bs[bitIdx] = val;
            }
        }
    }

    // записать boost::dynamic_bitset<> в произвольный буфер
    void BitsetToBuff(const boost::dynamic_bitset<>& bs, void *pBuff)
    {
    	unsigned bitsCount = bs.size();


        unsigned byteSt=0, bitIdx=0;
        unsigned char* p = reinterpret_cast<unsigned char*>(pBuff);

        for( ; bitIdx<bitsCount; ++byteSt, ++p )
        {
        	for( unsigned i=0; (i<8) && bitIdx<bitsCount; ++i, ++bitIdx  )
            {
            	bs[bitIdx] && (*p |= (1 << i)) ||  (*p &= (~(1 << i)));
            }
        }
    }


};
#endif

