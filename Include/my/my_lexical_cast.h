#ifndef MY_LEXICAL_CAST
#define MY_LEXICAL_CAST
//---------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <string>

std::ostream& operator<<(std::ostream& stream, AnsiString s)
{
    stream << s.c_str();
    return stream;
}

std::istream& operator>>(std::istream& stream, AnsiString& s)
{
    std::string stdString;
    stream >> stdString;
    s = stdString.c_str();
    return stream;
}

namespace my
{

template<typename Target, typename Source>
Target lexical_cast( Source arg )
{
	std::stringstream interpreter;
	Target result;
	if( !(interpreter << arg) || !(interpreter >> result) ||
	!(interpreter >> std::ws).eof())
	{
		//ShowMessage("Плохое лексическое преобразование!");
		throw std::runtime_error("Плохое лексическое преобразование!");
	}
	return result;
}

template<typename Target, typename Source>
bool check_lexical_cast(Target dest,  Source src)
{
	std::stringstream interpreter;
	return ( (interpreter << src) && (interpreter >> dest) && (interpreter >> std::ws).eof() );
}

};

//---------------------------------------------------------------------------
#endif