#ifndef MY_FREE_AND_NULL_HEADER_INCLUDED__________
#define MY_FREE_AND_NULL_HEADER_INCLUDED__________

template<class T> void FreeAndNULL(T*& p)
{
    delete p;
    p = NULL;
}

#endif