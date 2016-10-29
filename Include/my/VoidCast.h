// 10:09 4 �������� 2007 �.
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
        // ������������� ������ � HoldT
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
        // �������� T* �� �������. �����������: [ this->Add(pT); ]
        T* GetPtr(const void* pObj)
		{
        	Dat::iterator e = dat_.end(),
        	i = VoidToIter(pObj);
            assert(i!=e && "VoidCastListT::GetPtr: Wrong index of object!");
            return i->get();
		}
        //---------------------------------------------------------------------------
        // �������� HoldT �� �������. �����������: [ this->Add(pT); ]
        HoldT GetSharedPtr(const void* pObj)
		{
        	Dat::iterator e = dat_.end(),
        	i = VoidToIter(pObj);
            return i!=e ? *i : HoldT();
		}
		//---------------------------------------------------------------------------
		// �������  T* �� ������. �����������: T*  � ������
        void Remove(const T* pT)
		{
    		Dat::iterator e = dat_.end(), i = VoidToIter(pT);
        	assert (i!=e && "VoidCastListT::Remove: Wrong index of object!");
        	dat_.erase(i);
		}
        //---------------------------------------------------------------------------
        // �������� � ������ �����������: shTs �� � ������
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



