//---------------------------------------------------------------------------
#ifndef bin_numsH
#define bin_numsH


#include <functional>
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


#endif


