#ifndef MY_NULL_FOO_H_INCLUDED____
#define MY_NULL_FOO_H_INCLUDED____
namespace my
{

	struct NullDeleter
    {
    	void operator()(void*) {}
    };

    struct EmptyVoidFoo
    {
    	void operator()() {}
    };

    struct EmptyBoolFoo
    {
    	bool operator()() { return false; }
    };


};

#endif