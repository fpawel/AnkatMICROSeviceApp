//---------------------------------------------------------------------------
#ifndef MY_ABSTRACT_TABLE
#define MY_ABSTRACT_TABLE
//---------------------------------------------------------------------------
#include <loki\HierarchyGenerators.h>
#include <functional>
//---------------------------------------------------------------------------

	template<int A>
    struct Int2Type
    {
    	enum { num_=A };
    };
    // �������������� ���� (������� �������)
    template<typename T, int Ind>
    struct FieldTrait
    {
      	typedef Int2Type<Ind> Index;		// ����� ���� == Index::num_;
      	typedef T value_type;               // ��� ����
    };
    //-------------------------------------------------------------------------
    // typedef Loki::GenScatterHierarchy<TList, FieldTuple> [��� ������� ��� �������� � �������]
    //-------------------------------------------------------------------------
    // typedef TList [������ ����� ����� �������]
    //-------------------------------------------------------------------------
    // typeid([������ ����� ����� �������])==typeid(Loki::TypeList).
    //-------------------------------------------------------------------------

    /**    					������ 1
    
    	��� ���� � TList ������ ���� ��������������� FieldTrait.
    	������:
        #include "MyAbstractTbl.h"
        typedef FieldTrait<int,0> Int0;						// ��� ���� 0
      	typedef FieldTrait<int,1> Int1;                   	// ��� ���� 1
      	typedef FieldTrait<int,2> Int2;                   	// ��� ���� 2
      	typedef TYPELIST_3( Int0, Int1, Int2 ) IntIntInt; 	// ������ �����
    */
    //-------------------------------------------------------------------------
    // ������ FieldTuple ������������ ��� ��������� [��� ������� ��� �������� � �������]
    // �� ������ [������ ����� ����� �������].
    // ��� T ( ������������� ��� "template <class T> struct FieldTuple" )
    // ������ ����� �������� ������ T::value_type,
    // ��������, FieldTrait
    template <class T>
    struct FieldTuple
    {
      	typedef T::value_type value_type;
        //enum { num_ = T::Index::num_ };
      	value_type value_;
        operator value_type&() { return value_; }
        operator const value_type&() const { return value_; }

        void operator=(value_type v)
        {
        	value_ = v;
        }
        
    };
    //-------------------------------------------------------------------------
    // typedef TableTrait<[������ ����� ����� �������]> [�������������� �������]
    //-------------------------------------------------------------------------
    template<class Tbl, int N>
    struct GetFieldType
    {
    	typedef typename FieldTuple<Loki::TL::TypeAtNonStrict<Tbl::FieldsList,N>::Result> TupleType;
    	typedef typename TupleType::value_type ValueType;
    };

    template<class TList, template<class> class FT = FieldTuple>
    struct TableTrait
    {
    	//  [������ ����� ����� �������]
      	typedef TList FieldsList;
        //  [��� ������� ��� �������� � �������]
      	typedef Loki::GenScatterHierarchy<TList,FT> ItemType;
        //  ������� ������ �� ���� ����� N [��� ������� ��� �������� � �������] item
        template<int N>
        static typename FieldTuple<Loki::TL::TypeAtNonStrict<FieldsList,N>::Result>&
        Field(ItemType& obj)
      	{
        	return obj;
        }
        template<int N>
        static const typename FieldTuple<Loki::TL::TypeAtNonStrict<FieldsList,N>::Result>&
        Field(const ItemType& obj)
      	{
        	return obj;
        }
    };


    /**					������ 2

        #include "MyAbstractTbl.h"
        #include <assert.h>
        typedef FieldTrait<int,0> Int0;						// ��� ���� 0
      	typedef FieldTrait<int,1> Int1;                   	// ��� ���� 1
      	typedef FieldTrait<int,2> Int2;                   	// ��� ���� 2
      	typedef TYPELIST_3( Int0, Int1, Int2 ) IntIntInt; 	// [������ ����� ����� �������]
        typedef MyTableTrait::ItemType ItemType;			// �������� [��� ������� ��� �������� � �������]
        //................//
        ItemType item;
    	MyTableTrait::Field<0>(item) = 111;          		// ������� � ������ ������� ��������
    	MyTableTrait::Field<1>(item) = 222;                 // �������� ��������� operator value_type&()
    	MyTableTrait::Field<2>(item) = 333;
    	int                                                 // ��������� �������� �� ������ �������
        tmp = MyTableTrait::Field<0>(item);                 // �������� ��������� operator value_type&()
    	assert( tmp == 111 );
    	tmp = MyTableTrait::Field<1>(item);
    	assert( tmp == 222 );
    	tmp = MyTableTrait::Field<2>(item);
    	assert( tmp == 333 );								// ��!
    */

    template<typename Tbl, int N>
    struct FieldEqualTo : std::unary_function<Tbl::ItemType,bool>
    {
    	typedef GetFieldType<Tbl,N>::ValueType ValueType;
        const ValueType v_;
    	explicit FieldEqualTo(ValueType v) : v_(v)
        {
        }
    	inline bool operator()(Tbl::ItemType& item) const
    	{
        	return Tbl::Field<N>(item).value_==v_;
    	}
    };
//---------------------------------------------------------------------------
#endif