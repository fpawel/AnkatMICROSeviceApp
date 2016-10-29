#ifndef MY_ABSOLUTE_VALUE_OF_VARIABLE_HEADER_INCLUDED__________
#define MY_ABSOLUTE_VALUE_OF_VARIABLE_HEADER_INCLUDED__________

template <typename T>
T MyAbs( T t )
{
	return t>0 ? t : t * T(-1);
}



#endif