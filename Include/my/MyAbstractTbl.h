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
    // характеристика поля (столбца таблицы)
    template<typename T, int Ind>
    struct FieldTrait
    {
      	typedef Int2Type<Ind> Index;		// Номер поля == Index::num_;
      	typedef T value_type;               // тип поля
    };
    //-------------------------------------------------------------------------
    // typedef Loki::GenScatterHierarchy<TList, FieldTuple> [Тип объекта для хранения в таблице]
    //-------------------------------------------------------------------------
    // typedef TList [список типов полей таблицы]
    //-------------------------------------------------------------------------
    // typeid([список типов полей таблицы])==typeid(Loki::TypeList).
    //-------------------------------------------------------------------------

    /**    					ПРИМЕР 1
    
    	Все типы в TList должны быть конкретизациями FieldTrait.
    	Пример:
        #include "MyAbstractTbl.h"
        typedef FieldTrait<int,0> Int0;						// тип поля 0
      	typedef FieldTrait<int,1> Int1;                   	// тип поля 1
      	typedef FieldTrait<int,2> Int2;                   	// тип поля 2
      	typedef TYPELIST_3( Int0, Int1, Int2 ) IntIntInt; 	// список полей
    */
    //-------------------------------------------------------------------------
    // Кортеж FieldTuple предназначен для генерации [Тип объекта для хранения в таблице]
    // на основе [список типов полей таблицы].
    // Тип T ( конкретизация для "template <class T> struct FieldTuple" )
    // должен иметь открытый подтип T::value_type,
    // например, FieldTrait
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
    // typedef TableTrait<[список типов полей таблицы]> [характеристика таблицы]
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
    	//  [список типов полей таблицы]
      	typedef TList FieldsList;
        //  [Тип объекта для хранения в таблице]
      	typedef Loki::GenScatterHierarchy<TList,FT> ItemType;
        //  Вернуть ссылку на поле номер N [Тип объекта для хранения в таблице] item
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


    /**					ПРИМЕР 2

        #include "MyAbstractTbl.h"
        #include <assert.h>
        typedef FieldTrait<int,0> Int0;						// тип поля 0
      	typedef FieldTrait<int,1> Int1;                   	// тип поля 1
      	typedef FieldTrait<int,2> Int2;                   	// тип поля 2
      	typedef TYPELIST_3( Int0, Int1, Int2 ) IntIntInt; 	// [список типов полей таблицы]
        typedef MyTableTrait::ItemType ItemType;			// получить [Тип объекта для хранения в таблице]
        //................//
        ItemType item;
    	MyTableTrait::Field<0>(item) = 111;          		// заносим в строку таблицы значения
    	MyTableTrait::Field<1>(item) = 222;                 // работает благодаря operator value_type&()
    	MyTableTrait::Field<2>(item) = 333;
    	int                                                 // считываем значения из строки таблицы
        tmp = MyTableTrait::Field<0>(item);                 // работает благодаря operator value_type&()
    	assert( tmp == 111 );
    	tmp = MyTableTrait::Field<1>(item);
    	assert( tmp == 222 );
    	tmp = MyTableTrait::Field<2>(item);
    	assert( tmp == 333 );								// ОК!
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