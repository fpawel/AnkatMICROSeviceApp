#ifndef MY_STR_UTILS_H_INCLUDED_
#define MY_STR_UTILS_H_INCLUDED_
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
typedef std::vector<std::string> Strings;
// записать в v подстроки из строки str, разделённые символом delim
template<class Container>
void GetSubStrsDelimitedByChar(Container& v, std::string s, const char delim)
{
	size_t p1 = 0, p2 = 0;
	while( p2 != std::string::npos )
	{
		p2 = s.find(delim, p1);
		v.push_back( s.substr( p1, p2-p1 ).c_str() );
		p1 = p2+1;
	}
}



//---------------------------------------------------------------------------
#endif
