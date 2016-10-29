#ifndef MY_USER_DOUBLE_VAL_H_INCLUDED___
#define MY_USER_DOUBLE_VAL_H_INCLUDED___

#include <utility>
#include <SysUtils.hpp>
typedef std::pair<double,bool> UsrDouble;

inline UsrDouble StrToUsrDouble( AnsiString s )
{
	const int pos = s.Pos('.');
	if(pos) s[pos] = ',';
	UsrDouble ret;
	ret.second = TryStrToFloat( s,ret.first );
	return ret;
}

#endif
