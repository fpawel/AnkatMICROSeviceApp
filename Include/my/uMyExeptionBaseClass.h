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
    * ��������� ��� ������������ ���������� � ����� ������������� ����������.
	*/
	struct FileLine
	{
		/** ��� ����� */
		const char* fName_;
		/** ����� ������ */
		int line_;
		/**
		* ������� ������ �� ���������� ����� ����� � ������.
		*/
		explicit FileLine(const char* f, int l) : fName_(f), line_(l) {}
    };

    /**
	* ������ ��� ��������� �������� ������� FileLine.
	*/
	#define GET_FLINE_ my::FileLine(__FILE__, __LINE__)

	/**
	* ����� ������� ����� ��� ���� ���������� �������. ��� ���������� ������
	* ������������ � ���� sh_ptr<MyException>, ������� �������� ��������� ��
	* ���������� ����������, ����������� �� MyException. � ��������, ���������
	* ����������� ����� ���������� ����� ��������� ������ � ��� ������, ����� �
	* ������������ ������ ���� ����������� �������� ��� �� "������ MyException", �
	* � ��������� ������� ������ �������� � ��� MyException, ����������: "����������
	* ������ ���� ������ �� ��������� ���������".
	*/
    class MyException;

    /**
	* ����������� ���� ������ ��������� �� ����������
	*/
	typedef boost::shared_ptr<MyException> PMyExcpt;


    struct PMyExcptFactory
    {
    	/**
        * ��������� ������������� MyException
		* ������������� ��� �������� �������� ������ ������������. ������� ������
		* � ��������� ������ �� ���������� ����� ����������, ��������� �,
		* ��������, ���������� ����������. ��� �������� ������� loc ������
		* ������������ ������ _FLINE_.
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
	* ���������� MyException
    */

	class MyException : public boost::noncopyable
	{
    	friend struct PMyExcptFactory;
    	/** ����� ������������� ���������� */
		const FileLine location_;
		/** ��������� */
		const std::string message_;
		/** ��������� �� ��������� ����������, ������� ��������, ��� 0 */
		const PMyExcpt nested_;

	protected:
		/**
		* ���������� �����������. ��� �������� �������� ���������� ������������
		* ������� newMyException().
		*/
		MyException(const FileLine& loc, const std::string& msg, PMyExcpt nest);
	public:
		/**
		* ����������� ����������.
		*/
		virtual ~MyException(){}
		/**
		* ���������� ��� ������-����������. ������ ����������� ���������������� �
		* ����������� �������.
		*/
		virtual std::string ClassName() const;

		/**
		* ���������� "������ ��������" ����������, ���������� ��� ������ � �����
		* �������������.
		*/
		std::string ToString() const;

		/**
		* ���������� "������ ��������" �������� ���������� � ���� ����������,
		* ��������� � ����. ����������, ���������� ���������� ToString() �
		* ������� �� ���������� ������������ � ���� ������.
		*/
		std::string ToStringAll() const;

		/**
		* ������� ������� ��� �������� �������� �� ������� ���������� �����������
		* ������ E (��� ����������� �� ����). ���������� ��������� ���������
		* �������������� ���� � ������ �������������� ������.
		*/
		template<class E>
		E* Is() { return dynamic_cast<E*>(this); }

		/**
		* ������� ������� ��� �������� �������� �� ������� ����������� ����������
		* ����������� ������ E (��� ����������� �� ����). ���������� ���������
		* ��������� �������������� ���� � ������ �������������� ������.
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
	* ����� ������� ����� ��� ������������ ����������, ���������� �������� ��
	* ��������� � ��������, ����������� MyException.
	*/
    struct MyExternalExceptionName { static std::string GetName(); };
    typedef MyConcreteException<MyException,MyExternalExceptionName> MyExternalException;

	/**
	* ���������� ��� ������������ std::exception � �������, ����������� �� ����.
	*/
    struct MyStdExceptionName  { static std::string GetName(); };
    typedef MyConcreteException<MyExternalException,MyStdExceptionName> MyStdException;

    /**
	* ���������� ��� ������������ Exception �� VCL � �������, ����������� �� ����.
	*/
    struct MyVCLExceptionName  { static std::string GetName(); };
    typedef MyConcreteException<MyExternalException,MyVCLExceptionName> MyVCLException;


	/**
	* ���������� ��� �������������� � ������� ����������, ��� �������� �� �������
	* ����������.
	*/
    struct MyUnknownExceptionName  { static std::string GetName(); };
    typedef MyConcreteException<MyExternalException,MyUnknownExceptionName> MyUnknownException;



/**
 * ������ ������� �������������� ������� ���������� � ���������� ��������� ��
 * ���� PMyExcpt. ��� ����� ���� ������� ������ �� ����� catch. ���
 * �������� ������� location ������ ������������ ������ _FLINE_.
 * ���� ������������ ��������� ������������� �������������� (�������������)
 * ����������� ��� ��������� ����� ��������� ���������� � �������������
 * ����������� ������������ ����, �� ����� ����� �������� ����������� ����������
 * ������ �������, ������������ ��� �����������.
 */
PMyExcpt ConvertCurrentExeptionToMyException(const FileLine& location);



}; // namespace my

#endif
