//---------------------------------------------------------------------------

#ifndef MyExeptionImplH
#define MyExeptionImplH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"

//std
//#include <vector>

//my
#include "MyExcpt.hpp"
    

    /**
	*		MyExternalException
	*		ќбщий базовый класс дл€ инкапсул€ции исключений, €вл€ющихс€ внешними по
	*		отношению к иерархии, порождаемой MyException.
	*/
    DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(External, Exception );
	/**
	*      »сключение дл€ инкапсул€ции std::exception и классов, производных от него.
	*/
    DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(Std, ExternalException );
    /**
	*  »сключение дл€ инкапсул€ции Exception из VCL и классов, производных от него.
	*/
    DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(VCL, ExternalException );
    /**
	*  »сключение дл€ инкапсул€ции Exception из VCL и классов, производных от него.
	*/
    DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(AccessViolation, ExternalException );
    /**
	*  	»сключение дл€ информировани€ о внешнем исключении, тип которого не удалось
    *	определить.
	*/
    DECLARATE_AND_DEFINE_MY_EXCEPTION_CLASS_(Unknown, ExternalException );

    

#endif
