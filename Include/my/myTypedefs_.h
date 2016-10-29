#ifndef MY_TYPEDEFS_H
#define MY_TYPEDEFS_H
#include <vector>
#include <system.hpp>
typedef std::vector<unsigned char> VInt8;
typedef std::vector<int> VInt;
namespace my
{
	typedef void 		__fastcall (__closure *Void_Closure_Void)	();
	typedef AnsiString 	__fastcall (__closure *String_Closure_Void)	();
	typedef void 		__fastcall (__closure *Void_Closure_String)	(AnsiString);
};


#endif