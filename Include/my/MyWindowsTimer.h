//---------------------------------------------------------------------------
#ifndef MY_WINDOWS_TIMER_INCLUDED___
#define MY_WINDOWS_TIMER_INCLUDED___
//---------------------------------------------------------------------------
#include <loki\Functor.h>

namespace my
{
	// callback-функция таймера
	typedef Loki::Functor <	unsigned int > OnTimerFunctor;

	// установить время callback-вызова функции onTimer
	unsigned int SetMyTimer( OnTimerFunctor onTimer, unsigned long timeOut );

	

}; // namespace my





//---------------------------------------------------------------------------
#endif // #ifndef MY_WINDOWS_TIMER_INCLUDED___