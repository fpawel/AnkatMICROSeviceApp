#ifndef MY_GLOABAL_VARIABLES_OF_MODULE_DECLARATION_MACROS_HEADER_INCLUDED_____
#define MY_GLOABAL_VARIABLES_OF_MODULE_DECLARATION_MACROS_HEADER_INCLUDED_____
#include <cassert>

// проверка уникальности вызова функции
#define ASSERT_FUNCTION_CALLED_ONCE__ \
static bool wasCalledOnce=false;\
assert(!wasCalledOnce);\
wasCalledOnce = true;

// OpenModule() - инициализаци€
// —loseModule() - деинициализаци€
// эти методы объ€вл€ютс€ макросом, определ€ютс€ в cpp файле

// ¬ файле Library.h
#define DECLARE_MY_MODULE_INSTANCE_(modulName)\
namespace Private##modulName##Library\
{\
	class Module##modulName##Library\
    {\
    public:\
		Module##modulName##Library()\
        {\
			if (count_++ == 0)\
            {\
				ASSERT_FUNCTION_CALLED_ONCE__;\
                OpenModule();\
            }\
		}\
		~Module##modulName##Library()\
        {\
			if (--count_ == 0)\
            {\
            	ASSERT_FUNCTION_CALLED_ONCE__;\
				CloseModule();\
            }\
		}\
    private:\
		static int count_;\
		static void OpenModule();\
		static void CloseModule();\
	};\
	static Module##modulName##Library instance##modulName##Library_;\
};

// ¬ файле Library.сpp

// ƒелаетс€ перед выполнением вычислений в единице трансл€ции
#define DEFINE_MY_MODULE_INSTANCE_(modulName, InitializeFoo, FinalizeFoo )\
namespace Private##modulName##Library\
{\
	int Module##modulName##Library::count_ = 0;\
    void Module##modulName##Library::OpenModule()\
	{\
    	InitializeFoo##();\
	}\
	void Module##modulName##Library::CloseModule()\
	{\
    	FinalizeFoo##();\
	}\
};

////////////////////////////////////////////////////////////////////////////////
// пример
////////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
// .h
//------------------------------------------------------------------------------
// дл€ инициализации и финализации модул€
// DECLARE_MY_MODULE_INSTANCE_(Libraryname);

//------------------------------------------------------------------------------
// 	.cpp
//------------------------------------------------------------------------------
//	перед выполнением вычислений в единице трансл€ции
// 	namespace NamespaceName
// 	{
//		void Initialize();
//    	void Finalize();
//	};
// дл€ инициализации и финализации модул€
// DEFINE_MY_MODULE_INSTANCE_(Libraryname, NamespaceName::Initialize, NamespaceName::Finalize);






#endif