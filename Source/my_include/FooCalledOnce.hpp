#ifndef MY_CHECK_FUNCTION_CALLED_ONLY_ONCE_MACRO_HEADER_INCLUDED__________
#define MY_CHECK_FUNCTION_CALLED_ONLY_ONCE_MACRO_HEADER_INCLUDED__________

// проверка уникальности вызова функции
#define ASSERT_FUNCTION_CALLED_ONCE__ \
static bool wasCalledOnce=false;\
assert(!wasCalledOnce);\
wasCalledOnce = true;

#endif