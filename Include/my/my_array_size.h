#ifndef MY_ARRAY_SIZE_H
#define MY_ARRAY_SIZE_H

template< typename T, unsigned long N > unsigned long int array_size(T(&)[N]) { return N; }
template< typename T, unsigned long N > unsigned long int array_size(const T(&)[N]) { return N; }

#endif
