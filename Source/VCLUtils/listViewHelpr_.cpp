//---------------------------------------------------------------------------
#include <cassert>
#include <algorithm>

#pragma hdrstop

#include "listViewHelpr_.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


namespace Lv
{

int ItemIndex( TListView* lv )
{
	TListItem *lItem = lv->Selected;
	return lItem==NULL ? -1 : lItem->Index;
}

void Set(TListView* lv, unsigned cl, unsigned ro, const AnsiString& s)
{
    TListItem& itm = *lv->Items->Item[ro];
    if(cl==0) itm.Caption = s; else itm.SubItems->Strings[cl-1] = s;
}

AnsiString Get(TListView* lv, unsigned cl, unsigned ro)
{
    assert( (int)cl<lv->Columns->Count );
    assert( (int)ro<lv->Items->Count );

    TListItem& itm = *lv->Items->Item[ro];
    if(cl==0) return  itm.Caption;
    assert((int)cl-1<itm.SubItems->Count);
    return  itm.SubItems->Strings[cl-1];
}

unsigned GetColTextWidth( TListView* lv, unsigned n )
{
    assert( (int)n<lv->Columns->Count );
    unsigned ret = lv->StringWidth( lv->Column[n]->Caption )+15;

    for( int i=0; i<lv->Items->Count; ++i )
        if((int)n-1<lv->Items->Item[i]->SubItems->Count)
        ret = std::max( ret, 15+lv->StringWidth( Get(lv, n, i) ) );
            
    return ret;
}

bool GetColVis(TListView* lv, unsigned n)
{
    assert( (int)n<lv->Columns->Count );
    const int ret = lv->Column[n]->Width;
    return ret>0;
}
void SetColVis(TListView* lv, unsigned n, bool v)
{
    const unsigned defW = GetColTextWidth( lv, n );
    TListColumn& clmn = *lv->Column[n];
    clmn.Width = v ? defW : 0;
}
//---------------------------------------------------------------------------
AnsiString GetColsVisInfo(TListView* lv)
{
    AnsiString ret;
    const AnsiString s[] =  { "0", "1" };
    for( int cl=0; cl<lv->Columns->Count; ++cl )
        ret = ret + s[ GetColVis(lv, cl) ];
    return ret;
}
//---------------------------------------------------------------------------
void SetColsVisInfo(TListView* lv, const AnsiString& s)
{
    const int len = s.Length(), clCnt = lv->Columns->Count, vv = std::min(len, clCnt);
    for( int cl=0; cl<vv; ++cl )
        SetColVis(lv, cl, s[cl+1]!='0');
}
//---------------------------------------------------------------------------
void SetByTtl(TListView* lv, const AnsiString& ttl, int row, const AnsiString& s)
{
    for( int i=0; i<lv->Columns->Count; ++i ) if( lv->Column[i]->Caption==ttl)
    {
        Set(lv, i, row, s);
        return;
    }
}
//---------------------------------------------------------------------------
AnsiString GetByTtl(TListView* lv, const AnsiString& ttl, int row)
{
    for( int i=0; i<lv->Columns->Count; ++i )
        if( lv->Column[i]->Caption==ttl)
            return Get(lv, i, row);
    return "";
}
//---------------------------------------------------------------------------


}; // namespace Lv
