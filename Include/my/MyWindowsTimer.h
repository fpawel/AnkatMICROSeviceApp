//---------------------------------------------------------------------------
#ifndef MY_WINDOWS_TIMER_INCLUDED___
#define MY_WINDOWS_TIMER_INCLUDED___
//---------------------------------------------------------------------------
#include <loki\Functor.h>

namespace my
{
	// callback-������� �������
	typedef Loki::Functor <	unsigned int > OnTimerFunctor;

	// ���������� ����� callback-������ ������� onTimer
	unsigned int SetMyTimer( OnTimerFunctor onTimer, unsigned long timeOut );

	

}; // namespace my





//---------------------------------------------------------------------------
#endif // #ifndef MY_WINDOWS_TIMER_INCLUDED___