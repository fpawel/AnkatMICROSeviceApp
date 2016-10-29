#ifndef MY_DIFFERENCE_ITERATOR_HEADER_INCLUDED____
#define MY_DIFFERENCE_ITERATOR_HEADER_INCLUDED____

namespace my
{

template <class T, class R, class P, unsigned N>
struct DiffIterator
  : public boost::random_access_iterator_helper<
     DiffIterator<T,R,P,N>, T, std::ptrdiff_t, P, R>
{
  	typedef DiffIterator SelfT;
  	typedef R Reference;
  	typedef std::ptrdiff_t Distance;

public:
  	explicit DiffIterator(P i =0) : _i(i)  	{}
  	DiffIterator(const SelfT& x) : _i(x._i) { }
  	SelfT& operator=(const SelfT& x)  	{_i = x._i; return *this;}
  	Reference operator*() const { return *_i; }
  	SelfT& operator++()    { _i+=N; return *this; }
  	SelfT& operator--()    { _i-=N; return *this; }
  	SelfT& operator+=(Distance n) { _i += (n*N); return *this; }
  	SelfT& operator-=(Distance n) { _i -= (n*N); return *this; }
  	bool operator==(const SelfT& x) const {return _i == x._i    }
  	bool operator<(const SelfT& x) const { return _i < x._i; }

  	friend Distance operator-(const SelfT& x, const SelfT& y)
  	{ return (  x._i - y._i )  / N; }
protected:
  	P _i;
};

};//namespace my

#endif
