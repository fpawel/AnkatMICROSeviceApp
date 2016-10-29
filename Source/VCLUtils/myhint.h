//---------------------------------------------------------------------------
#ifndef myhintH
#define myhintH
//---------------------------------------------------------------------------
#include <Controls.hpp>

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"


class MyFocusHintWindow : public THintWindow
{
public:
	explicit MyFocusHintWindow();
	void SetShowing( bool );
    bool GetShowing( ) const { return fShowing_; }
private:
	bool fShowing_;
	TControl* hintControl_;


	TRect MyCalcHintRect( const AnsiString& ) ;
	void Appear();
	void Disappear();
};






#endif
