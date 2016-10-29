//---------------------------------------------------------------------------
#ifndef MY_LOCKING_FLAG_H_INCLUDED____
#define MY_LOCKING_FLAG_H_INCLUDED____
//---------------------------------------------------------------------------

// boost
#include "boost\noncopyable.hpp"
namespace my
{
	template<class T>
	class CheckNoDoubleCall : public boost::noncopyable
    {
    	static bool isCreated_;
    public:
    	CheckNoDoubleCall()
        {
        	if( isCreated_ )
            	T::OnInfringement();
        	isCreated_ = true;
        }

        template<typename Arg>
        CheckNoDoubleCall(const Arg& arg)
        {
        	if( isCreated_ )
            	T::OnInfringement(arg);
        	isCreated_ = true;
        }

        template<typename Arg1,typename Arg2>
        CheckNoDoubleCall(const Arg1& arg1, const Arg2& arg2)
        {
        	if( isCreated_ )
            	T::OnInfringement(arg1,arg2);
        	isCreated_ = true;
        }

        template<typename Arg1,typename Arg2,typename Arg3,typename Arg4>
        CheckNoDoubleCall(const Arg1& arg1, const Arg2& arg2,
        	const Arg3& arg3, const Arg4& arg4)
        {
        	if( isCreated_ )
            	T::OnInfringement(arg1,arg2,arg3,arg4);
        	isCreated_ = true;
        }

        ~CheckNoDoubleCall()
        {
        	isCreated_ = false;
        }
    };
    template<class T>
    bool CheckNoDoubleCall<T>::isCreated_;

};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
