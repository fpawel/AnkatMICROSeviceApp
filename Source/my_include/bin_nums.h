//---------------------------------------------------------------------------
#ifndef bin_numsH
#define bin_numsH

#include <assert>
//---------------------------------------------------------------------------
//устанавливет в Val бит номер bit в b
template <class X> void Setbit(X& b, bool val, unsigned bitIdx)
{
   	val && (b |= (1 << bitIdx)) ||  (b &= (~(1 << bitIdx)));
}
//---------------------------------------------------------------------------
//возвращает  бит номер bit в b
template <class X> bool Getbit(X b, unsigned bitIdx)
{
	return  b & (1 << bitIdx);
}
//---------------------------------------------------------------------------
template <class X>  void Invertbit(X& b, unsigned bitIdx)
{
    Setbit<X>(b, !Getbit<X>(b, bit), bit);
}
//---------------------------------------------------------------------------
template<typename T> void IntToBitset64( T beg, T end, unsigned val )
{
	for( unsigned i=0; beg!=end && i<32; ++i )
    	*(beg++) = Getbit<unsigned>(val,i);
}
//---------------------------------------------------------------------------
template<typename T> unsigned Bitset64ToInt( T beg, T end )
{
	unsigned ret = 0;
    for( unsigned i=0; beg!=end && i<32; ++i ) Setbit<unsigned>(ret, *(beg++), i);
    return ret;
}
//---------------------------------------------------------------------------


template<typename F> void MyAnalyseBits( unsigned val, unsigned idx0, unsigned idx1, F foo )
{
	for( unsigned i=0; i<32 && idx0<idx1; ++i, ++idx0 )
    	foo( idx0, Getbit<unsigned>(val,i) );
}
typedef void (__closure *TAnalyseBitFoo)(unsigned num, bool val);
//---------------------------------------------------------------------------
template<typename F> unsigned MyGetIntByBitNum( unsigned idx0, unsigned idx1, F foo )
{
	unsigned ret = 0;
	for( unsigned i=0; i<32 && idx0<idx1; ++i, ++idx0 )
    	Setbit<unsigned>(ret, foo(idx0), i);
    return ret;
}
typedef bool (__closure *TGetBitByNumFoo)(unsigned num);

#endif


