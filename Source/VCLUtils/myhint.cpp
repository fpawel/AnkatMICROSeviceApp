//---------------------------------------------------------------------------


#pragma hdrstop

#include <forms.hpp>

#include "myhint.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TRect MyFocusHintWindow::MyCalcHintRect( const AnsiString& s)
{
    TRect rect = Bounds( 0, 0, Screen->Width, 0 );
	DrawText( Canvas->Handle, s.c_str(), -1, &rect,
    	DT_CALCRECT | DT_LEFT | DT_WORDBREAK | DT_NOPREFIX );
    const TPoint clientOrigin = hintControl_->ClientOrigin;

    OffsetRect( rect, clientOrigin.x, clientOrigin.y + hintControl_->Height + 6 );
	rect.Right+= 6;
	rect.Bottom+= 2;
	return rect;
}

void MyFocusHintWindow::Appear()
{
	if ( Screen->ActiveControl == hintControl_ ) return;
    hintControl_ = Screen->ActiveControl;
    const AnsiString sHint = GetShortHint( hintControl_->Hint );
	const TRect hintRect = MyCalcHintRect( sHint );
	ActivateHint( hintRect, sHint );
	fShowing_ = true;
}

void MyFocusHintWindow::Disappear()
{
	hintControl_ = NULL;
	::ShowWindow( Handle, SW_HIDE );
	fShowing_ = false;
}

void MyFocusHintWindow::SetShowing( bool v)
{
	if(v)
    	Appear();
    else
    	Disappear();
}

