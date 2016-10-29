#ifndef MY_NUMERIC_CONVERSIONS_HEADER_INCLUDED_____________
#define MY_NUMERIC_CONVERSIONS_HEADER_INCLUDED_____________

#include <sstream>
#include <system.hpp>


AnsiString MyFloatToStr(float v)
{
	std::stringstream strm;
    strm << v;
    return strm.str().c_str();
}

double MyFloatToDouble(float v)
{
	std::stringstream strm;
    strm << v;
    strm.seekg(0, std::ios::beg);
    double res = 0;
    strm >> res;
    return res;
}

float MyDoubleToFloat(double v)
{
	std::stringstream strm;
    strm << v;
    strm.seekg(0, std::ios::beg);
    float res = 0;
    strm >> res;
    return res;
}

#endif