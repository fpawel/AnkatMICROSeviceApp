//---------------------------------------------------------------------------
#ifndef bin_numsH
#define bin_numsH


#include <functional>
#include <assert>
//---------------------------------------------------------------------------
//������������ � Val ��� ����� bit � b
template <class X> void Setbit(X& b, bool val, unsigned bitIdx)
{
   	val && (b |= (1 << bitIdx)) ||  (b &= (~(1 << bitIdx)));
}
//---------------------------------------------------------------------------
//����������  ��� ����� bit � b
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


