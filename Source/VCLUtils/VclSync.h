//---------------------------------------------------------------------------
#ifndef MY_VCL_THREAD_SYNCRONIZATION_UTLITYS_HEADER_INCLUDED________________
#define MY_VCL_THREAD_SYNCRONIZATION_UTLITYS_HEADER_INCLUDED________________
//---------------------------------------------------------------------------
// boost
//---------------------------------------------------------------------------
// std
//---------------------------------------------------------------------------
// vcl
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
//my
#include "MySynchronize.h"

struct VCLSyncHelper
{
	LRESULT SetText( TEdit* ed, const AnsiString& s ) const 
    {
    	ed->Text = s;
        return 0;
    }

    LRESULT SetCaption( TLabel* ed, const AnsiString& s ) const
    {
    	ed->Caption = s;
        return 0;
    }
};

void SyncSetTEdit( TEdit* ed, const AnsiString& s )
{
	VCLSyncHelper h;
	my::Synchronize2( &h.SetText, ed, s );
}

void SyncSetTLabel( TLabel* ed, const AnsiString& s )
{
	VCLSyncHelper h;
	my::Synchronize2( &h.SetCaption, ed, s );
}
	
#endif