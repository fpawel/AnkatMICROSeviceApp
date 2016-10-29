#ifndef MY_TRANSFER_SIGNALS_DECLARATION_HEADER_INCLUDED
#define MY_TRANSFER_SIGNALS_DECLARATION_HEADER_INCLUDED

#include "..\VCLUtils\VCLSignal.h"
#include "..\my_include\free_types_.h"
#include "MyExcpt.hpp"

typedef my::VCLSignal::Signal<TVoid_IntStrMthd> TReportStateSignal;
//------------------------------------------------------------------------------
typedef void (__closure *TNotifyException)( const PMyExcpt& );
typedef my::VCLSignal::Signal<TNotifyException> TNotifyExceptionSignal;
//------------------------------------------------------------------------------





#endif