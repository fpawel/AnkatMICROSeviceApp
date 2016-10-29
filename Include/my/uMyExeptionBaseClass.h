//---------------------------------------------------------------------------

#ifndef uMyExeptionBaseClassH
#define uMyExeptionBaseClassH
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
//---------------------------------------------------------------------------

namespace my
{
	/**
    * Структура для инкапсуляции информации о месте возникновения исключения.
	*/
	struct FileLine
	{
		/** имя файла */
		const char* fName_;
		/** номер строки */
		int line_;
		/**
		* Создает объект по переданным имени файла и строке.
		*/
		explicit FileLine(const char* f, int l) : fName_(f), line_(l) {}
    };

    /**
	* Макрос для упрощения создания объекта FileLine.
	*/
	#define GET_FLINE_ my::FileLine(__FILE__, __LINE__)

	/**
	* Общий базовый класс для всех исключений проекта. Все исключения должны
	* возбуждаться в виде sh_ptr<MyException>, который содержит указатель на
	* собственно исключение, производное от MyException. В принципе, отдельный
	* производный класс исключений стоит создавать только в том случае, когда у
	* пользователя должна быть возможность отличить его от "просто MyException", а
	* в остальный случаях вполне подойдет и сам MyException, означающий: "обнаружена
	* общего вида ошибка со следующим описанием".
	*/
    class MyException;

    /**
	* определение типа умного указателя на исключение
	*/
	typedef boost::shared_ptr<MyException> PMyExcpt;


    struct PMyExcptFactory
    {
    	/**
        * Фабричный производитель MyException
		* Предназначена для создания объектов вместо конструктора. Создает объект
		* в свободной памяти по переданным месту исключения, сообщению и,
		* возможно, вложенному исключению. Для передачи объекта loc удобно
		* использовать макрос _FLINE_.
		*/
        template<class E>
        static PMyExcpt Create(const FileLine& loc, const std::string& msg, const PMyExcpt nest = PMyExcpt() )
        {
        	return PMyExcpt( new E(loc, msg, nest) );
        }

        template<class E,typename A>
        static PMyExcpt Create(A arg, const FileLine& loc, const std::string& msg, const PMyExcpt nest = PMyExcpt() )
        {
        	return PMyExcpt( new E(arg, loc, msg, nest) );
        }
    };


    /**
	* Декларация MyException
    */

	class MyException : public boost::noncopyable
	{
    	friend struct PMyExcptFactory;
    	/** место возникновения исключения */
		const FileLine location_;
		/** сообщение */
		const std::string message_;
		/** указатель на вложенное исключение, причину текущего, или 0 */
		const PMyExcpt nested_;

	protected:
		/**
		* Защищенный конструктор. Для создания объектов необходимо использовать
		* функцию newMyException().
		*/
		MyException(const FileLine& loc, const std::string& msg, PMyExcpt nest);
	public:
		/**
		* Виртуальный деструктор.
		*/
		virtual ~MyException(){}
		/**
		* Возвращает имя класса-исключения. Должна обязательно переопределяться в
		* производных классах.
		*/
		virtual std::string ClassName() const;

		/**
		* Возвращает "полное описание" исключения, включающее имя класса и место
		* возникновения.
		*/
		std::string ToString() const;

		/**
		* Возвращает "полное описание" текущего исключения и всех исключений,
		* вложенных в него. Фактически, результаты применения ToString() к
		* каждому из исключений объединяются в одну строку.
		*/
		std::string ToStringAll() const;

		/**
		* Удобная функция для проверки является ли текущее исключение исключением
		* класса E (или производным от него). Возвращает ненулевой указатель
		* запрашиваемого типа в случае положительного ответа.
		*/
		template<class E>
		E* Is() { return dynamic_cast<E*>(this); }

		/**
		* Удобная функция для проверки является ли текущее константное исключение
		* исключением класса E (или производным от него). Возвращает ненулевой
		* указатель запрашиваемого типа в случае положительного ответа.
		*/
		template<class E>
		const E* Is() const { return dynamic_cast<const E*>(this); }
	};



    template<class Base, class Namer>
    class MyConcreteException : public Base
    {
    	friend struct PMyExcptFactory;
    protected:
    	MyConcreteException(const FileLine& loc, const std::string& msg, PMyExcpt nest) :
 		Base(loc, msg, nest)
        {
		}
    public:
    	virtual ~MyConcreteException(){}
		virtual std::string ClassName() const { return Namer::GetName(); }
    };

    /**
    *			MyExternalException
	* Общий базовый класс для инкапсуляции исключений, являющихся внешними по
	* отношению к иерархии, порождаемой MyException.
	*/
    struct MyExternalExceptionName { static std::string GetName(); };
    typedef MyConcreteException<MyException,MyExternalExceptionName> MyExternalException;

	/**
	* Исключение для инкапсуляции std::exception и классов, производных от него.
	*/
    struct MyStdExceptionName  { static std::string GetName(); };
    typedef MyConcreteException<MyExternalException,MyStdExceptionName> MyStdException;

    /**
	* Исключение для инкапсуляции Exception из VCL и классов, производных от него.
	*/
    struct MyVCLExceptionName  { static std::string GetName(); };
    typedef MyConcreteException<MyExternalException,MyVCLExceptionName> MyVCLException;


	/**
	* Исключение для информирования о внешнем исключении, тип которого не удалось
	* определить.
	*/
    struct MyUnknownExceptionName  { static std::string GetName(); };
    typedef MyConcreteException<MyExternalException,MyUnknownExceptionName> MyUnknownException;



/**
 * Данная функция перевозбуждает текущее исключение и возвращает созданный по
 * нему PMyExcpt. Она может быть вызвана только из блока catch. Для
 * передачи объекта location удобно использовать макрос _FLINE_.
 * Если используемая платформа предоставляет дополнительные (нестандартные)
 * возможности для получения более подробной информации о перехваченных
 * исключениях неизвестного типа, то имеет смысл написать специальную реализацию
 * данной функции, использующую эти возможности.
 */
PMyExcpt ConvertCurrentExeptionToMyException(const FileLine& location);



}; // namespace my

#endif
