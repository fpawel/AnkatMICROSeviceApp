//---------------------------------------------------------------------------
#ifndef MY_TYPLE_AS_LOKI__GEN_SCATTERED_HIERACHY_INCLUDED___
#define  MY_TYPLE_AS_LOKI__GEN_SCATTERED_HIERACHY_INCLUDED___
//---------------------------------------------------------------------------
#include "loki\HierarchyGenerators.h"
#include "loki\TypeManip.h"
//---------------------------------------------------------------------------

namespace my
{
	// �������������� ���� (������� �������)
	template<typename T, int Ind>
    struct TupleTrait
    {
    	typedef Loki::Int2Type<Ind> Index;		// ����� ���� == Index::num_;
      	typedef T ValueType;               // ��� ����
    };

	namespace Tuples
    {
    	//-------------------------------------------------------------------------
    	// ������ TupleUnit ������������ ��� ��������� ��� ������� ��� �������� � �������
    	// �� ������ ������� ����� �����.
    	template <class T>
    	struct TupleUnit
   	 	{
      		typedef T::ValueType ValueType;
        	//enum { num_ = T::Index::num_ };
      		ValueType value_;
        	operator ValueType&() { return value_; }
        	operator const ValueType&() const { return value_; }
    	};
    };

    //-------------------------------------------------------------------------
    // ������ ������
    //-------------------------------------------------------------------------
    template<class TList, template<class> class U = Tuples::TupleUnit>
    struct Tuple
    {
    	//  [������ ����� ����� �������]
      	typedef TList FieldsList;
        //  [��� ������� ��� �������� � �������]
      	typedef Loki::GenScatterHierarchy<TList,U> ItemType;
        //  ������� ������ �� ���� ����� N [��� ������� ��� �������� � �������] item
        template<int N>
        static typename Tuples::TupleUnit<Loki::TL::TypeAtNonStrict<FieldsList,N>::Result>&
        Get(ItemType& obj)
      	{
        	return obj;
        }
        template<int N>
        static const typename Tuples::TupleUnit<Loki::TL::TypeAtNonStrict<FieldsList,N>::Result>&
        Get(const ItemType& obj)
      	{
        	return obj;
        }
    };
    namespace Tuples
    {
    	template<class TPL, int N>
    	struct FieldType
    	{
    		typedef typename Tuples::TupleUnit<Loki::TL::TypeAtNonStrict<TPL::FieldsList,N>::Result>::ValueType
        	Result;
    	};
    };




};
//---------------------------------------------------------------------------
#endif