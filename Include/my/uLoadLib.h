#ifndef MY_LOAD_LIBRARY_H_INCLUDED___
#define MY_LOAD_LIBRARY_H_INCLUDED___
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"
//---------------------------------------------------------------------------
#include <windows.h>
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
#include "Loki\TypeList.h"
#include "Loki\EmptyType.h"
//---------------------------------------------------------------------------
#include "uMyExeptionBaseClass.h"
//---------------------------------------------------------------------------
namespace my
{
	struct FreeLibraryFoo
    {
    	void operator()(void *ptr)
        {
        	FreeLibrary(ptr);
        }
    };

	template<class TL, class TR = Loki::EmptyType >
	class Library : public boost::noncopyable
    {
        typedef typename Library<TL,TR> SelfType;
    	//friend  void boost::checked_delete( SelfType*);

        boost::shared_ptr<void> hnd_;
        std::vector<void*> foo_;

    public:

        Library() : hnd_(), foo_ ()
        {
        	Load();
        }

        void Load( const char* const fn, const char* const fooNames[], unsigned fooCount )
        {
        	hnd_.reset( LoadLibrary( fn ), FreeLibraryFoo() );
            if( !hnd_ )
            	throw my::PMyExcptFactory::Create<MyException>(GET_FLINE_,
        		std::string("Невозможно открыть библиотеку ")+fn);

            foo_ .resize( fooCount );
            for( unsigned i=0; i<fooCount; ++i )
            {
            	foo_.at(i) = GetProcAddress(hnd_.get(), fooNames[i]);
                // проверить foo_[i] и, если 0, сообщить об ошибке
                if( foo_.at(i)==NULL )
                {
                	const std::string msg =
                    std::string("Невозможно получить адресс функции \"")+
                    fooNames[i]+"\" в библиотеке "+fn;
                	throw my::PMyExcptFactory::Create<MyException>(GET_FLINE_, msg);
                }
            }
        }
        void Load()
        {
        	Load( TR::fn_, TR::fooNames_, Loki::TL::Length<TL>::value-1 );
        }

		template<unsigned N> typename Loki::TL::TypeAt<TL,N+1>::Result Foo() const
        {
       		return reinterpret_cast< Loki::TL::TypeAt<TL,N+1>::Result >(foo_[N]);
    	}
    };




};



//---------------------------------------------------------------------------
#endif