#ifndef MY_DIFFERENCE_ITERATOR_HEADER_INCLUDED____
#define MY_DIFFERENCE_ITERATOR_HEADER_INCLUDED____

#include "boost/operators.hpp"  // for boost::random_access_iterator_helper

namespace my
{

template <class T, class R, class P>
struct DiffNIterator
  : public boost::random_access_iterator_helper<
     DiffNIterator<T,R,P>, T, std::ptrdiff_t, P, R>
{
  	typedef DiffNIterator SelfT;
  	typedef R Reference;
  	typedef std::ptrdiff_t Distance;

public:
  	explicit DiffNIterator(P i =0, Distance n = 0) : i_(i), n_(n)
    	{}
  	DiffNIterator(const SelfT& x) : i_(x.i_), n_(x.n_)
    	{ }
  	SelfT& operator=(const SelfT& x)
    	{i_ = x.i_; n_ = x.n_; return *this;}
  	Reference operator*() const
    	{ return *i_; }
  	SelfT& operator++()
    	{ i_+=n_; return *this; }
  	SelfT& operator--()
    	{ i_-=n_; return *this; }
  	SelfT& operator+=(Distance n)
    	{ i_ += (n*n_); return *this; }
  	SelfT& operator-=(Distance n)
    	{ i_ -= (n*n_); return *this; }
  	bool operator==(const SelfT& x) const
    	{return i_ == x.i_;    }
  	bool operator<(const SelfT& x) const
    	{ return i_ < x.i_; }

  	friend Distance operator-(const SelfT& x, const SelfT& y)
  	{ return (  x.i_ - y.i_ )  / x.n_; }
protected:
  	P i_;
    Distance n_;
};

template <class T, class R, class P, unsigned N>
struct DiffIterator
  : public boost::random_access_iterator_helper<
     DiffIterator<T,R,P,N>, T, std::ptrdiff_t, P, R>
{
  	typedef DiffIterator SelfT;
  	typedef R Reference;
  	typedef std::ptrdiff_t Distance;

public:
  	explicit DiffIterator(P i =0) : i_(i)
    	{}
  	DiffIterator(const SelfT& x) : i_(x.i_)
    	{ }
  	SelfT& operator=(const SelfT& x)
    	{i_ = x.i_; return *this;}
  	Reference operator*() const
    	{ return *i_; }
  	SelfT& operator++()
    	{ i_+=N; return *this; }
  	SelfT& operator--()
    	{ i_-=N; return *this; }
  	SelfT& operator+=(Distance n)
    	{ i_ += (n*N); return *this; }
  	SelfT& operator-=(Distance n)
    	{ i_ -= (n*N); return *this; }
  	bool operator==(const SelfT& x) const
    	{return i_ == x.i_;    }
  	bool operator<(const SelfT& x) const
    	{ return i_ < x.i_; }

  	friend Distance operator-(const SelfT& x, const SelfT& y)
  	{ return (  x.i_ - y.i_ )  / N; }
protected:
  	P i_;
};

};//namespace my

#endif
