#ifndef THIS_APPLICATION_CONFIGURATION_TOOLS_HEADER_INCLUDED__________
#define THIS_APPLICATION_CONFIGURATION_TOOLS_HEADER_INCLUDED__________

/**
*		Здесь декларированы ссылки на файлы с настройками приложения
*/
#include "IniFileMacro.h"
#include <inifiles.hpp>
#include "MyModFN.hpp"
#include "..\my_include\free_types_.h"
//------------------------------------------------------------------------------
#define THIS_APPLICATION_TITLE "АНКАТ-7664МИКРО"
//------------------------------------------------------------------------------
DEFINE_NONDELETEABLE_INIFILE_EX_( Form1, "form1.ini" )
DEFINE_NONDELETEABLE_INIFILE_EX_( Graph, "graph.ini" )
DEFINE_NONDELETEABLE_INIFILE_EX_( Config, "config.ini" )
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
