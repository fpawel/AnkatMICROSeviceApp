#ifndef MY_SIMPLE_FUNCTORS_H_INCLUDED___
#define MY_SIMPLE_FUNCTORS_H_INCLUDED___

namespace my
{
	struct NullDeleter { void operator()(void const *) const {}	};

};// namespace my
//-----------------------------------------------------------------------------/
#endif
