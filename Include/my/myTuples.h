//---------------------------------------------------------------------------
#ifndef MY_TYPLE_AS_LOKI__GEN_SCATTERED_HIERACHY_INCLUDED___
#define  MY_TYPLE_AS_LOKI__GEN_SCATTERED_HIERACHY_INCLUDED___
//---------------------------------------------------------------------------
#include "loki\HierarchyGenerators.h"
#include "loki\TypeManip.h"
//---------------------------------------------------------------------------

namespace my
{
	// характеристика поля (столбца таблицы)
	template<typename T, int Ind>
    struct TupleTrait
    {
    	typedef Loki::Int2Type<Ind> Index;		// Номер поля == Index::num_;
      	typedef T ValueType;               // тип поля
    };

	namespace Tuples
    {
    	//-------------------------------------------------------------------------
    	// Кортеж TupleUnit предназначен для генерации Тип объекта для хранения в кортеже
    	// на основе списока типов полей.
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
    // Щаблон кортеж
    //-------------------------------------------------------------------------
    template<class TList, template<class> class U = Tuples::TupleUnit>
    struct Tuple
    {
    	//  [список типов полей таблицы]
      	typedef TList FieldsList;
        //  [Тип объекта для хранения в таблице]
      	typedef Loki::GenScatterHierarchy<TList,U> ItemType;
        //  Вернуть ссылку на поле номер N [Тип объекта для хранения в таблице] item
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