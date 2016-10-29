#ifndef MY_BOOST_SPIRIT_BASED_CALCULATOR_WITH_VARIABLES_HEADER_INCLUDED__________
#define MY_BOOST_SPIRIT_BASED_CALCULATOR_WITH_VARIABLES_HEADER_INCLUDED__________

/**
*		Ёкспорт
*/
typedef void* HCalculator;
#define MYCALCDLLEXPORT extern "C" __import
MYCALCDLLEXPORT bool MyCalculateSimpleExpression(char* expression, double* result, const char** stop);
MYCALCDLLEXPORT HCalculator CreateMyCalculator();
MYCALCDLLEXPORT void DeleteMyCalculator(HCalculator hCalculator);
MYCALCDLLEXPORT bool MyCalculateExpressionWithVariables
( 
	HCalculator hCalculator, 
	const char* expression, 
	const char** pStop,
	double* pResult, 
	bool* pHasGotResult
);
#undef MYCALCDLLEXPORT 

#endif