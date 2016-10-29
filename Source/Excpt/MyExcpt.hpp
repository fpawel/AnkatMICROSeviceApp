//------------------------------------------------------------------------------
#ifndef MY_EXCEPTION_CERTAIN_CLASS_DECLARATION__HEADER_INCLUDED__________
#define MY_EXCEPTION_CERTAIN_CLASS_DECLARATION__HEADER_INCLUDED__________
//------------------------------------------------------------------------------
#include <SysUtils.hpp>
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
	/**
	* определение типа умного указателя на исключение
	*/
    class MyException;
	typedef boost::shared_ptr<const MyException> ConstPMyExcpt;
    typedef boost::shared_ptr<MyException> PMyExcpt;

	/**
    * Структура для инкапсуляции информации о месте возникновения исключения.
	*/
    typedef std::pair<unsigned, AnsiString> FileLine;

    /**
	* Данная функция перевозбуждает текущее исключение и возвращает созданный по
	* нему PMyExcpt. Она может быть вызвана только из блока catch. Для
	* передачи объекта location удобно использовать макрос _FLINE_.
	* Если используемая платформа предоставляет дополнительные (нестандартные)
	* возможности для получения более подробной информации о перехваченных
	* исключениях неизвестного типа, то имеет смысл написать специальную реализацию
	* данной функции, использующую эти возможности.
    */
	PMyExcpt RethrowMyException(const FileLine& location);

	/**
	* Общий базовый класс для всех исключений проекта. Все исключения должны
	* возбуждаться в виде sh_ptr<MyException>, который содержит указатель на
	* собственно исключение, производное от MyException. В принципе, отдельный
	* производный класс исключений стоит создавать только в том случае, когда у
	* пользователя должна быть возможность отличить его от "просто MyException", а
	* в остальный случаях вполне подойдет и сам MyException, означающий: "обнаружена
	* общего вида ошибка со следующим описанием".
    */
    class MyException : public boost::noncopyable
    {
    public:

    	MyException(const FileLine& loc, const AnsiString& msg, const PMyExcpt nest = PMyExcpt() );

        /** Виртуальный деструктор. */
	    virtual ~MyException(){}

	    /**
        *   Возвращает имя класса-исключения. Должна обязательно переопределяться в
	    *   производных классах.
        */
	    virtual AnsiString ClassName() const;

        /**
        *       место возникновения исключения
        */
	    const FileLine& Location() const ;

        /**
	    /*      сообщение
        */
	    const AnsiString& Message() const;

	    /**
        *       указатель на вложенное исключение, причину текущего, или 0
        */
        const MyException* Nested() const;

        /**
        *       указатель на старшее из вложенных исключений или this
        */
        const MyException* Root() const;

        /**
        *   Возвращает "полное описание" исключения, включающее имя класса и место
	    *   возникновения.
        */
	    AnsiString ToString() const;

	    /**
        *   Возвращает "полное описание" текущего исключения и всех исключений,
	    *   вложенных в него. Фактически, результаты применения ToString() к
	    *   каждому из исключений объединяются в одну строку.
        */
        AnsiString ToStringAll() const;

        /**
        *       Преобразование и проверка соответсвия типа
        */
        template<class E>
        const E* const As() const
        {
        	return dynamic_cast<const E* const>(this);
        }

        template<class E>
        bool TypeOf() const
        {
        	return As<E>();
        }
    private:
        // место возникновения исключения
	    const FileLine location_;
	    // сообщение
	    const AnsiString message_;
	    // указатель на вложенное исключение, причину текущего, или 0
	    const PMyExcpt nested_;
    };

    /**
	*		Макросс для определения классов My##THECLASS##Exception,
    *		производных от My##THEBASECLASS
	*		с единственным защищённыи конструктором
	*		My##THECLASS##Exception(const FileLine& loc, const AnsiString& msg, PMyExcpt nest)
	*/

    #define DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_NAME_(THECLASS, THEBASECLASS, THENAME )\
    class My##THECLASS##Exception : public My##THEBASECLASS\
    {\
    public:\
    	My##THECLASS##Exception(const FileLine& loc, const AnsiString& msg, PMyExcpt nest)\
        	:\
 			My##THEBASECLASS##(loc, msg, nest)\
        {}\
    	virtual ~My##THECLASS##Exception(){}\
		virtual AnsiString ClassName() const { return THENAME; }\
    }

    #define DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(THECLASS, THEBASECLASS )\
    DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_NAME_(THECLASS, THEBASECLASS, "My"#THECLASS"Exception" )

    /**
	* Макрос для упрощения создания объекта FileLine.
	*/
    namespace Private
    {
    	FileLine ExtractFileLine( unsigned line, const char* fileName );
    };


    /**
    *   Фабричный производитель MyException
	*   Предназначена для создания объектов вместо конструктора. Создает объект
	*   в свободной памяти по переданным месту исключения, сообщению и,
	*   возможно, вложенному исключению. Для передачи объекта loc удобно
	*   использовать макрос _FLINE_.
	*/
    struct MyExcptionFactory
    {

        template<class E>
        static PMyExcpt Create(const FileLine& loc, const AnsiString& msg, const PMyExcpt nest = PMyExcpt() )
        {
        	return PMyExcpt( new E(loc, msg, nest) );
        }

        template<class E,typename A>
        static PMyExcpt Create(A arg, const FileLine& loc, const AnsiString& msg, const PMyExcpt nest = PMyExcpt() )
        {
        	return PMyExcpt( new E(arg, loc, msg, nest) );
        }
    };
    #define __FILE_LINE__ Private::ExtractFileLine(__LINE__,__FILE__)

    /**
	*   Сокращение для вызова RethrowMyException(__FILE_LINE__)
	*/
    #define MY_RETHROW_ RethrowMyException(__FILE_LINE__)
    #define MY_RETHROW_NESTED_(msg) throw PMyExcpt( new MyException(__FILE_LINE__, msg, MY_RETHROW_) );

    /**
	*   Сокращение для вызова throw MyExcptionFactory::Create<MyException>(__FILE_LINE__, msg )
	*/
    #define MY_THROW_(msg) throw PMyExcpt( new MyException(__FILE_LINE__, msg ) )

    /**
	*   Сокращение для вызова
    *   throw MyExcptionFactory::Create<класс, производный от MyException>(__FILE_LINE__, msg )
	*/
    #define MY_THROW_CLASS_(cls, msg)\
    	throw MyExcptionFactory::Create<##cls##>(__FILE_LINE__, msg )

    //"%eClass" "%eMsg" "%eFile", "%eLine"
    AnsiString FormatMyException( const MyException* excpt,
        const AnsiString& format="%eMsg %eLine %eFile" );
    //--------------------------------------------------------------------------
    AnsiString FormatMyExceptionMessages( const MyException* excpt,
        const AnsiString& delim, const AnsiString& format = "%eMsg" );



//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
