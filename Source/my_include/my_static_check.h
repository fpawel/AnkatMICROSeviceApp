#ifndef MY_STATIC_CHECK_INC_
#define MY_STATIC_CHECK_INC_

namespace my
{
////////////////////////////////////////////////////////////////////////////////
// Helper structure for the STATIC_CHECK macro
////////////////////////////////////////////////////////////////////////////////

    template<int> struct CompileTimeError;
    template<> struct CompileTimeError<true> {};
}

////////////////////////////////////////////////////////////////////////////////
// macro STATIC_CHECK
// Invocation: STATIC_CHECK(expr, id)
// where:
// expr is a compile-time integral or pointer expression
// id is a C++ identifier that does not need to be defined
// If expr is zero, id will appear in a compile-time error message.
////////////////////////////////////////////////////////////////////////////////

#define MY_STATIC_CHECK_EXT_(expr, msg) \
    { my::CompileTimeError<((expr) != 0)> ERROR_##msg; (void)ERROR_##msg; }

#define MY_STATIC_CHECK(expr, msg)\
namespace MyAssumptions\
{\
	void StaticCheck_##msg()\
    {\
    	MY_STATIC_CHECK_EXT_(expr, Err_##msg);\
    }\
};




#endif // MY_STATIC_CHECK_INC_
