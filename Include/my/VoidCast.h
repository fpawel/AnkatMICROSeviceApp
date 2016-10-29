// 10:09 4 сентября 2007 г.
//---------------------------------------------------------------------------
#ifndef MY_VOID_CAST_HELPER_LIST_INCLUDED___
#define MY_VOID_CAST_HELPER_LIST_INCLUDED___
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
//---------------------------------------------------------------------------
#include "Nullfoo.h"
//---------------------------------------------------------------------------

namespace my
{
	template<class T>
	class VoidCastListT
    {
		typedef boost::shared_ptr<T> HoldT;
    	typedef std::vector<HoldT> Dat;
		typedef Dat::iterator Iter;
    	Dat dat_;
		//---------------------------------------------------------------------------
        // преобразовать адресс в HoldT
        Iter VoidToIter(const void* obj)
		{

        	Dat::iterator e = dat_.end(),
        	i = dat_.begin();
        	for( ; i!=e; ++i )
        		if( i->get()==obj )
            		break;
        	return i;
		}
    public:
    	void Clear()
        {
        	dat_.clear();
        }

		//---------------------------------------------------------------------------
        // Получить T* из адресса. Предусловие: [ this->Add(pT); ]
        T* GetPtr(const void* pObj)
		{
        	Dat::iterator e = dat_.end(),
        	i = VoidToIter(pObj);
            assert(i!=e && "VoidCastListT::GetPtr: Wrong index of object!");
            return i->get();
		}
        //---------------------------------------------------------------------------
        // Получить HoldT из адресса. Предусловие: [ this->Add(pT); ]
        HoldT GetSharedPtr(const void* pObj)
		{
        	Dat::iterator e = dat_.end(),
        	i = VoidToIter(pObj);
            return i!=e ? *i : HoldT();
		}
		//---------------------------------------------------------------------------
		// Удалить  T* из списка. Предусловие: T*  в списке
        void Remove(const T* pT)
		{
    		Dat::iterator e = dat_.end(), i = VoidToIter(pT);
        	assert (i!=e && "VoidCastListT::Remove: Wrong index of object!");
        	dat_.erase(i);
		}
        //---------------------------------------------------------------------------
        // Добавить в список Предусловие: shTs не в списке
        void Add( HoldT shT )
		{        	
        	Dat::iterator e = dat_.end(),
        	i = VoidToIter(shT.get());
            assert(i==e && "VoidCastListT::Add: object already exists!");
			dat_.push_back( shT );
		}
    };
};

#endif



