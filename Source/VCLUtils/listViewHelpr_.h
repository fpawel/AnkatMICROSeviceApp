//---------------------------------------------------------------------------
#ifndef listViewHelpr_H
#define listViewHelpr_H
//---------------------------------------------------------------------------
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
namespace Lv
{
	int ItemIndex( TListView* lv );

    void Set(TListView* lv, unsigned cl, unsigned ro, const AnsiString&);
    AnsiString Get(TListView* lv, unsigned cl, unsigned ro);

    bool GetColVis(TListView* lv, unsigned n);
    void SetColVis(TListView* lv, unsigned n, bool v);

    template<typename T>
    void SetRow( TListView* lv, const int ro, T str, T strEnd)
    {
    	for( int cl=0; cl<lv->Columns->Count && str!=strEnd ; ++cl, ++str )
        	Set(lv, cl, ro, *str );
    }

    AnsiString GetColsVisInfo(TListView* lv);
    void SetColsVisInfo(TListView* lv, const AnsiString&);

    void SetByTtl(TListView* lv, const AnsiString& ttl, int row, const AnsiString& s);
    AnsiString GetByTtl(TListView* lv, const AnsiString& ttl, int row);

};


//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
