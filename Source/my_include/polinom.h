#ifndef MY_POLINOM_CALCULATION_HEADER_INCLUDED_______
#define MY_POLINOM_CALCULATION_HEADER_INCLUDED_______

#include "my_include\free_types_.h"
#include <cassert>

struct CalculatePolinom
{
	explicit CalculatePolinom(const double* koefs, const double* koefsEnd) :
    	koefs_(koefs), koefsEnd_(koefsEnd), n_(koefsEnd_-koefs_)
    {
    	assert(n_>-1);
    }
	double operator()(double x) const
	{
    	if (n_==0) return 0;
    	double res =  koefs_[n_-1] ;
    	for (int i = n_-2; i>=0; --i)
    		res = koefs_[i]+res*x ;
    	return res;
	}
    const double* koefs_;
    const double* koefsEnd_;
    const int n_;
};

struct CalculateRational_AsCurveExpert
{
	explicit CalculateRational_AsCurveExpert(const double* koefs) : k(koefs)
    {
    }
	double operator()(double x) const
	{
 	   return (k[0]+x*k[1])/(1+k[2]*x+k[3]*x*x);
	}
    const double* k;
};



#endif