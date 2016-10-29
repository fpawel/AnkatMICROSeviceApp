#ifndef MY_WINDOWS_UTILS_HEADER_INCLUDED__________
#define MY_WINDOWS_UTILS_HEADER_INCLUDED__________

#include <windows.h>


void MyEmulatePressKey( int Key )
{
	::keybd_event(Key, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	::keybd_event(Key, 0, KEYEVENTF_EXTENDEDKEY,0);
	::keybd_event(Key, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

#endif
