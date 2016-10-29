//---------------------------------------------------------------------------
#include <Map>
//---------------------------------------------------------------------------

#pragma hdrstop

#include "SGrdHlpr.h"

//my
#include "myformat.hpp"
#include "dlg\uFormGridColsDlg.h"

// loki
#include "loki\singleton.h"
//#include "MyExeption.h"
#include "MyVclUtils_.h"

//vcl
#include <Clipbrd.hpp>
#include "DrawGridCell.h"
#include "AnsiStringUtils_.h"






//---------------------------------------------------------------------------

#pragma package(smart_init)

namespace my
{
namespace Grd
{
	// ¬џбран ли диапазон
    bool IsRangeSelected( const TStringGrid* g )
    {
    	#pragma warn -8037
    	return g->Selection.Top!=g->Selection.Bottom || g->Selection.Left!=g->Selection.Right;
        #pragma warn +8037
    }

    //---------------------------------------------------------------------------
    //  €чейка таблицы
    Cell::Cell( TStringGrid* grd, int col, int row ) :
    	grd_(grd), col_(col), row_(row)
    {
    }

    void SetTxt(Cell& cell, const AnsiString& s)
    {
    	cell.grd_->Cells[cell.col_][cell.row_] = s;
    }
    AnsiString GetTxt(const Cell& cell)
    {
    	return cell.grd_->Cells[cell.col_][cell.row_];
    }

    //---------------------------------------------------------------------------
	// ѕопадает ли €чейка col,row в фиксированную область таблицы
    bool IsCellFixed(const Cell& cell)
	{
		return cell.col_ < cell.grd_->FixedCols || cell.row_ < cell.grd_->FixedRows;
	}
    //---------------------------------------------------------------------------
    bool IsCellInEditMode( const Cell& cell )
	{
		return 	cell.grd_->EditorMode &&
        		cell.grd_->Col == cell.col_ &&
                cell.grd_->Row == cell.row_;
	}
	//---------------------------------------------------------------------------
    void SetCellIfNotEdited(Cell cell, AnsiString val)
	{
		if( !IsCellInEditMode(cell) )
        	SetTxt(cell, val);
	}
    //---------------------------------------------------------------------------
    // ќтрисовать €чейку col,row в таблице g
    void RedrawCell(TStringGrid* grd, int col, int row)
    {
    	RedrawCell( Cell(grd,col,row) );
    }

	void RedrawCell(Cell cell)
	{
		SetCellIfNotEdited( cell, GetTxt(cell) );
	}

    void RedrawRow(TStringGrid* grd, int row)
    {
    #pragma warn -8012
    	for( unsigned cl=0; cl<grd->ColCount; ++cl )
        	RedrawCell(grd, cl, row);
    #pragma warn +8012
    }


    void RedrawCol(TStringGrid* grd, int col)
    {
    	for( int ro=0; ro<grd->RowCount; ++ro )
        	RedrawCell(grd, col, ro);
    }

    void RedrawGrid(TStringGrid* grd )
    {
    #pragma warn -8012
    	for( unsigned ro=0; ro<grd->RowCount; ++ro )
    	for( unsigned cl=0; cl<grd->ColCount; ++cl )
        	RedrawCell(grd, cl, ro);
    #pragma warn +8012
    }

	// ¬озвращает видимый пр€моугольник нефиксированных €чеек таблицы
	TRect VisRect(TStringGrid* g)
	{
		int topRow = g->TopRow, visRows = g->VisibleRowCount,
			leftCol = g->LeftCol, visCols = g->VisibleColCount;
		return TRect( leftCol, topRow, leftCol+visCols, topRow+visRows );
	}

	//---------------------------------------------------------------------------
	// сделать таблицу редактируемой или нет
	void SetEditing(TStringGrid* grd, bool fl)
	{
		if (fl) grd->Options<<goEditing ;
		else grd->Options>>goEditing;
	}
	//---------------------------------------------------------------------------
	// заполнена ли строка
	bool FilledRow( TStringGrid* grd, int row)
	{
		int colCount = grd->ColCount;
		for (int i=0; i<colCount; ++i)
		if (grd->Cells[i][row]=="") return false;
		return true;
	}
	//---------------------------------------------------------------------------
	// €чейка под курсором
	TPoint HotCell(TStringGrid* grd)
	{
		TPoint pt;
		GetCursorPos(&pt);
		TPoint point = grd->ScreenToClient( pt );

        int col,row;
		grd->MouseToCell(point.x, point.y, col, row);
		return TPoint(col,row);
	}
	//---------------------------------------------------------------------------





	// ќтрисовать пр€моугольник left, top, right, bottom в таблице g
	void RedrawRect(TStringGrid* grd, TRect rect)
	{
    	const int
        minCol = std::max(0,rect.left),
        minRow = std::max(0,rect.top),
        maxCol = std::min(grd->ColCount-1,rect.right),
        maxRow = std::min(grd->RowCount-1,rect.bottom);

    	Cell cell(grd,minCol,minRow);
		for ( cell.col_=minCol; cell.col_ <= maxCol; ++cell.col_)
        	for ( cell.row_=minRow; cell.row_ <= maxRow; ++cell.row_)
            	RedrawCell(cell);

	}
	//---------------------------------------------------------------------------

	void ClearTStringGrid( TStringGrid* grd, int cl0, int ro0 )
	{
		const int cc = grd->ColCount, rc = grd->RowCount;
		for( int cl = cl0; cl<cc; ++cl ) for( int ro = ro0; ro<rc; ++ro )
			grd->Cells[cl][ro] = "";
	}
    #pragma warn -8037
    void ClearSelection(const TStringGrid* grd)
    {
    	const unsigned
        minCol = grd->Selection.Left,		maxCol = grd->Selection.Right,
  		minRow = grd->Selection.Top,  		maxRow = grd->Selection.Bottom;

    	AnsiString sBuff;
        for( unsigned ro=minRow; ro<=maxRow; ++ro ) if( grd->RowHeights[ro] )
        {
        	for( unsigned cl=minCol; cl<=maxCol; ++cl ) if (grd->ColWidths[cl]>0)
            	grd->Cells[cl][ro] = "";
        }
    }

    AnsiString GetErasedLastChar( const AnsiString& ss, char ch )
    {
        const int len = ss.Length();
        if( len==0 ) return ss;
        return ( ss[len]==ch ) ? ss.SubString(1,len-1) : ss;
    }

    AnsiString GetFormatedVisibleText( const TStringGrid* grd,
    	unsigned col_from, unsigned col_to,
        unsigned row_from, unsigned row_to)
    {
    	AnsiString s;
  		for ( unsigned ro=row_from; ro<=row_to; ++ro ) if (grd->RowHeights[ro]>0)
        {
        	for ( unsigned cl=col_from; cl<=col_to; ++cl )
            	if (grd->ColWidths[cl]>0) s = s + grd->Cells[cl][ro]+"\t";
            s = GetErasedLastChar( s, '\t' ) + "\n";
        }

  		return s = GetErasedLastChar( s, '\n' );

    }

//------------------------------------------------------------------------------
// вызвать диалог дл€ настройуи видимых столбцов
//------------------------------------------------------------------------------
void SetupVisibleColsOnMouseDownRow0(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y, unsigned titleNum)
{
	TStringGrid* grd = static_cast<TStringGrid*>(Sender);
    // €чейка под курсором
	const TPoint hotCell = my::Grd::HotCell(grd);
	if( Button==mbLeft && hotCell.y==0 )
    {
        boost::shared_ptr<TFormGridColsDlg> dlg( new TFormGridColsDlg(NULL, grd, true, titleNum) );
        dlg->ShowModal();
    }
}
//------------------------------------------------------------------------------
void SetupVisibleRows(TStringGrid* grd, unsigned titleNum)
{
	boost::shared_ptr<TFormGridColsDlg> dlg( new TFormGridColsDlg(NULL, grd, false, titleNum) );
    dlg->ShowModal();
}


void SetupVisibleRowsOnMouseDownCol0(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y, unsigned titleNum)
{
    TStringGrid* grd = static_cast<TStringGrid*>(Sender);
    // €чейка под курсором
	const TPoint hotCell = my::Grd::HotCell(grd);
	if( Button==mbLeft && hotCell.x==0 )
    {
        boost::shared_ptr<TFormGridColsDlg> dlg( new TFormGridColsDlg(NULL, grd, false, titleNum) );
        dlg->ShowModal();
    }
}

//------------------------------------------------------------------------------
	bool GetColVis( const TStringGrid* grd, unsigned col )
    {
    	return grd->ColWidths[col]!=0;
    }
    void SetColVis(const TStringGrid* grd, unsigned col, bool vis)
    {
    	if( vis!=GetColVis(grd,col) )
    	grd->ColWidths[col] = vis ? grd->DefaultColWidth : 0;
    }
//---------------------------------------------------------------------------
    void SetRowVis(const TStringGrid* grd, unsigned row, bool vis)
    {
    	grd->RowHeights[row]  = vis ? grd->DefaultRowHeight : 0;
    }
//---------------------------------------------------------------------------
    AnsiString GetVisColsInfo(TStringGrid* grd)
    {
    	AnsiString ret;
        const AnsiString sTrue = "1", sFalse = "0";
    	for( int cl=0; cl<grd->ColCount; ++cl )
        	ret = ret + ( grd->ColWidths[cl] ? sTrue : sFalse );
        return ret;
    }
//---------------------------------------------------------------------------
    void SetVisColsInfo(TStringGrid* grd, const AnsiString& s)
    {
    	const int len = s.Length(), clCnt = grd->ColCount, vv = std::min(len, clCnt);
    	for( int cl=0; cl<vv; ++cl )
        {
        	const bool vis = s[cl+1]!='0';
        	SetColVis(grd, cl, vis);
        }
    }
//---------------------------------------------------------------------------
    AnsiString GetVisRowsInfo(TStringGrid* grd)
    {
    	AnsiString ret;
        const AnsiString sTrue = "1", sFalse = "0";
    	for( int ro=0; ro<grd->RowCount; ++ro )
        	ret = ret + ( grd->RowHeights[ro] ? sTrue : sFalse );
        return ret;
    }
//---------------------------------------------------------------------------
    void SetVisRowsInfo(TStringGrid* grd, const AnsiString& s)
    {
    	const int len = s.Length(), roCnt = grd->RowCount, vv = std::min(len, roCnt);
    	for( int ro=0; ro<vv; ++ro )
        {
        	const bool vis = s[ro+1]!='0';
        	SetRowVis(grd, ro, vis);
        }
    }
 //---------------------------------------------------------------------------
    // копировать в буфер
    void CopyCellsToClipboard( const TStringGrid* grd )
    {
    	const unsigned
        minCol = grd->Selection.Left,		maxCol = grd->Selection.Right,
  		minRow = grd->Selection.Top,  		maxRow = grd->Selection.Bottom;

        MyCopyTextToClipboard( GetFormatedVisibleText(grd, minCol, maxCol, minRow, maxRow) );
        /*
        const WideString wsGrdContent = sGrdContent;

        const unsigned
        	strLen = wsGrdContent.Length(),
        	buffSize = (strLen+1)*sizeof(wchar_t);

        HGLOBAL hMem = ::GlobalAlloc(GMEM_MOVEABLE,  buffSize );

        wchar_t *pOut = (wchar_t*) ::GlobalLock(hMem), *pIn = wsGrdContent.c_bstr();
        std::copy(pIn, pIn + strLen, pOut);
        pOut[strLen] = L'\0';

        ::GlobalUnlock(hMem);
        ::OpenClipboard( NULL );
        ::EmptyClipboard();
        ::SetClipboardData( CF_UNICODETEXT, hMem);

        ::CloseClipboard();
        */
    }
//---------------------------------------------------------------------------
    typedef std::vector<AnsiString> MyStringList;
    void GetSubStrsDelimitedByOneOf(MyStringList& v, const std::string& s,
        const std::vector< std::string>& delims)
    {
        using std::string::npos;
	    unsigned p1 = 0, p2 = 0;
	    while( p2 != npos )
	    {
            unsigned p3 = npos;
            for( unsigned i=0; p3==npos && i<delims.size(); ++i )
                p3 = s.find(delims[i], p1);
		    p2 = p3;
            const std::string toPushBack = s.substr( p1, p2-p1 );
		    v.push_back( toPushBack.c_str() );
		    p1 = p2+1;
	    }
    }


    typedef std::vector<MyStringList> MyStringLists;
    MyStringLists FormatClipboard()
    {
        MyStringLists ret;
        TClipboard& clpBrd = *Clipboard();
    	if ( !clpBrd.HasFormat(CF_TEXT) ) return ret;
        MyStringList lines;
        std::vector< std::string> delims;
        delims.push_back("\n");
        delims.push_back("\r\n");
        delims.push_back("\r");
        GetSubStrsDelimitedByOneOf(lines, clpBrd.AsText.c_str(), delims);
        delims.clear();
        delims.push_back("\t");
        for( unsigned i=0; i<lines.size(); ++i )
        {
            MyStringList line;
            GetSubStrsDelimitedByOneOf(line, lines[i].c_str(), delims);
            ret.push_back(line);
        }
        return ret;
    }


    void PastCellsFromClipboard(const TStringGrid* grd)
    {
    	TClipboard& clpBrd = *Clipboard();
    	if ( !clpBrd.HasFormat(CF_TEXT) ) return;
        const unsigned roCnt = (unsigned)grd->RowCount, clCnt = (unsigned)grd->ColCount;
        const MyStringLists clipBoardStrs = FormatClipboard();

        unsigned ro = grd->Row;
        for( unsigned nLine=0; nLine<clipBoardStrs.size(); ++nLine )
        {
        	while (grd->RowHeights[ro]==0 && ro<roCnt) ++ro;
      		if (ro>=roCnt) break;

            unsigned cl = (unsigned)grd->Col;
    		for ( unsigned nStr=0; nStr<clipBoardStrs[nLine].size(); ++nStr)
    		{
        		while ( grd->ColWidths[cl]==0 && cl<clCnt) ++cl;
        		if (cl >= clCnt) break;
                grd->Cells[cl][ro] = clipBoardStrs[nLine][nStr];
        		++cl;
    		}
    		++ro;
        }
    }

    #pragma warn +8037
//---------------------------------------------------------------------------
struct MenuToGrdMapT
{
    std::map<TMenuItem*,TStringGrid*> menuToGrd_;
};
//---------------------------------------------------------------------------
typedef Loki::SingletonHolder
<
    MenuToGrdMapT,
    Loki::CreateUsingNew,
    Loki::NoDestroy
> MenuToGrdMap;
//---------------------------------------------------------------------------
struct PMRowsHlprT
{
    std::map<TPopupMenu*,TNotifyEvent> pmToOnPopup_;
    void __fastcall OnClick(TObject* sender)
    {
        TMenuItem* itm = static_cast<TMenuItem*>(sender);
        const int idx = itm->MenuIndex;
        assert(idx>-1);
        TStringGrid *grd = MenuToGrdMap::Instance().menuToGrd_[itm];
        assert(grd);
        itm->Checked = !itm->Checked;
        my::Grd::SetRowVis(grd, idx, itm->Checked);
    }

    void __fastcall OnPopup(TObject* sender)
    {
        TPopupMenu* pm = static_cast<TPopupMenu*>(sender);
    	TStringGrid *grd = static_cast<TStringGrid*>( pm->PopupComponent );
    	for( int ro=0; ro<grd->RowCount; ++ro )
            pm->Items->Items[ro]->Checked = grd->RowHeights[ro];
        TNotifyEvent onPopup = pmToOnPopup_[pm];
        if(onPopup) onPopup(sender);
    }
};


struct PMColsHlprT
{
    std::map<TPopupMenu*,TNotifyEvent> pmToOnPopup_;

    void __fastcall SelectAll(TObject* sender)
    {
        TMenuItem* itm = static_cast<TMenuItem*>(sender);
        TStringGrid *grd = MenuToGrdMap::Instance().menuToGrd_[itm];
        itm->Checked = !itm->Checked;
        for( int cl=0; cl<grd->ColCount; ++cl )
            my::Grd::SetColVis(grd, cl, itm->Checked);
    }

    void __fastcall OnClick(TObject* sender)
    {
        TMenuItem* itm = static_cast<TMenuItem*>(sender);
        const int idx = itm->MenuIndex;
        assert(idx>-1);
        TStringGrid *grd = MenuToGrdMap::Instance().menuToGrd_[itm];
        assert(grd);
        itm->Checked = !itm->Checked;
        my::Grd::SetColVis(grd, idx, itm->Checked);
    }
    void __fastcall OnPopup(TObject* sender)
    {
        TPopupMenu* pm = static_cast<TPopupMenu*>(sender);
    	TStringGrid *grd = static_cast<TStringGrid*>( pm->PopupComponent );
        bool allVis = true;
    	for( int cl=0; cl<grd->ColCount; ++cl )
        {
            pm->Items->Items[cl]->Checked = grd->ColWidths[cl];
            allVis &= pm->Items->Items[cl]->Checked;
        }
        pm->Items->Items[grd->ColCount+1]->Checked = allVis;

        TNotifyEvent onPopup = pmToOnPopup_[pm];
        if(onPopup) onPopup(sender);
    }
};

struct PMCopyHlpr
{
    void __fastcall OnClick(TObject* sender)
    {
        TMenuItem* itm = static_cast<TMenuItem*>(sender);
        TStringGrid *grd = MenuToGrdMap::Instance().menuToGrd_[itm];
        assert(grd);
        CopyCellsToClipboard( grd );
    }
};
struct PMPastHlpr
{
    void __fastcall OnClick(TObject* sender)
    {
        TMenuItem* itm = static_cast<TMenuItem*>(sender);
        TStringGrid *grd = MenuToGrdMap::Instance().menuToGrd_[itm];
        assert(grd);
        PastCellsFromClipboard( grd );
    }
};
//---------------------------------------------------------------------------
void TieWithColsVisiblePopup( TStringGrid* grd, TNotifyEvent onPopup )
{
    static PMColsHlprT hndl_;

    TPopupMenu* pm = GetPopupMenu( grd );
    pm->OnPopup = hndl_.OnPopup;
    for( int cl=0; cl<grd->ColCount; ++cl )
    {
        TMenuItem *itm = new TMenuItem(pm);
    	pm->Items->Add( itm );
        itm->Caption = grd->Cells[cl][0];
        itm->OnClick =  hndl_.OnClick;
        MenuToGrdMap::Instance().menuToGrd_[itm] = grd;
    }

    TMenuItem *itm = new TMenuItem(pm);
    pm->Items->Add( itm );
    itm->Caption = "-";

    itm = new TMenuItem(pm);
    pm->Items->Add( itm );
    itm->Caption = "ѕоказать все";
    itm->OnClick =  hndl_.SelectAll;
    MenuToGrdMap::Instance().menuToGrd_[itm] = grd;

    hndl_.pmToOnPopup_[pm] = onPopup;
}
//---------------------------------------------------------------------------
void TieWithRowsVisiblePopup( TStringGrid* grd, TNotifyEvent onPopup )
{
    static PMRowsHlprT hndl_;

    TPopupMenu* pm = GetPopupMenu( grd );
    pm->OnPopup = hndl_.OnPopup;
    for( int ro=0; ro<grd->RowCount; ++ro )
    {
        	TMenuItem *itm = new TMenuItem(pm);
    		pm->Items->Add( itm );
        	itm->Caption = grd->Cells[0][ro];
            itm->OnClick =  hndl_.OnClick;
            MenuToGrdMap::Instance().menuToGrd_[itm] = grd;
    }
    hndl_.pmToOnPopup_[pm] = onPopup;
}
//---------------------------------------------------------------------------
    void DeleteRow(TStringGrid* grd, int row, int count)
    {
    	const int oldRC = grd->RowCount, cC = grd->ColCount;

        for( int ro=row; ro<oldRC; ++ro )
        	for( int cl=0; cl<cC; ++cl )
            	grd->Cells[cl][ro] = grd->Cells[cl][ro + count];

        for( int ro=oldRC-count; ro<oldRC; ++ro )
        	for( int cl=0; cl<cC; ++cl )
            	grd->Cells[cl][ro] = "";
        grd->RowCount = grd->RowCount - count;
    }
    void DeleteCol(TStringGrid* grd, int col, int count)
    {
    	const int oldCC = grd->ColCount, rC = grd->RowCount;

        for( int cl=col; cl<oldCC; ++cl )
        	for( int ro=0; ro<rC; ++ro )
            	grd->Cells[cl][ro] = grd->Cells[cl+count][ro];

        for( int cl=oldCC-count; cl<oldCC; ++cl )
        	for( int ro=0; ro<rC; ++ro )
            	grd->Cells[cl][ro] = "";
        grd->ColCount = grd->ColCount - count;
    }
//---------------------------------------------------------------------------
void SetCellByTtl(TStringGrid *grd, const AnsiString& ttl, int row, const AnsiString& s)
{
    const int col = grd->Rows[0]->IndexOf(ttl);
    if(col>-1) grd->Cells[col][row] = s;
}
//---------------------------------------------------------------------------
AnsiString GetCellByTtl(TStringGrid *grd, const AnsiString& ttl, int row)
{
    const int col = grd->Rows[0]->IndexOf(ttl);
    return col>-1 ? grd->Cells[col][row] : AnsiString("");
}
//---------------------------------------------------------------------------
TPopupMenu* GetPopupMenu(TStringGrid *grd)
{

    TPopupMenu* pm = grd->PopupMenu;
    if(pm==NULL)
    {
        pm = new TPopupMenu( grd->Owner );
        grd->PopupMenu = pm;
    }
    return pm;
}
//---------------------------------------------------------------------------
void AddCopyItemToPopupMenu(TStringGrid *grd)
{
    static PMCopyHlpr hndl_;
    TPopupMenu *pm = GetPopupMenu(grd);

    TMenuItem *menu = new TMenuItem(grd);
    //menu->Caption = "-";
    //pm->Items->Add(menu);

    //menu = new TMenuItem(grd);
    menu->Caption = " опировать";
    MenuToGrdMap::Instance().menuToGrd_[menu] = grd;
    pm->Items->Add(menu);
    menu->OnClick =  hndl_.OnClick;
    menu->ShortCut = ShortCut( Word('C'), TShiftState() << ssCtrl );
}
void AddPastItemToPopupMenu(TStringGrid *grd)
{
    static PMPastHlpr hndl_;
    TPopupMenu *pm = GetPopupMenu(grd);

    TMenuItem *menu = new TMenuItem(grd);
    //menu->Caption = "-";
    //pm->Items->Add(menu);

    //menu = new TMenuItem(grd);
    menu->Caption = "¬ставить";
    MenuToGrdMap::Instance().menuToGrd_[menu] = grd;
    pm->Items->Add(menu);
    menu->OnClick =  hndl_.OnClick;
    menu->ShortCut = ShortCut( Word('V'), TShiftState() << ssCtrl );
}
//---------------------------------------------------------------------------
unsigned GetRowsHeight(TStringGrid *grd)
{
    int ht = 0;
    for( int i=0; i<grd->RowCount; ++i )
        ht += grd->RowHeights[i];
    return ht;
}

bool IsRowSelected( TStringGrid *grd, int row )
{
	DrawGridCellManager& dgcm = DrawGridCellManager::GetDrawCellManager( grd );
    const bool ret = dgcm.GetRowCustomDrawBrush( row).Color != unselectedRowColor;
	if(ret) dgcm.EraseRowCustomDraw( row );
	return ret;
}

void SelectRow( TStringGrid *grd, int ro, bool v )
{
	DrawGridCellManager& dgcm = DrawGridCellManager::GetDrawCellManager( grd );
    if( v )	dgcm.EraseRowCustomDraw( ro);
    else
    {
    	dgcm.GetRowCustomDrawBrush(ro).Color = unselectedRowColor;
        RedrawRow(grd, ro);
    }
}

void InveertRowselection( TStringGrid *grd, int row )
{
	SelectRow( grd, row, !IsRowSelected( grd, row ) );
}

void InvertRowSelectionOfSelection(TStringGrid *grd)
{
	const TGridRect sel = grd->Selection;
    bool oneIsSelected = 0;
    for( int ro=sel.Top; ro<=sel.Bottom; ++ro )
    	oneIsSelected |= IsRowSelected( grd, ro );
    for( int ro=sel.Top; ro<=sel.Bottom; ++ro )
    	SelectRow( grd, ro, !oneIsSelected );
}

AnsiString RowsSelectionInfoToStr(TStringGrid *grd)
{
	const int rc = grd->RowCount;
	if( rc==0 ) return "";
    const unsigned sz = rc - 1;
	std::vector<int> rsNfo( sz );
    for( unsigned i=0; i<sz; ++i )
    	rsNfo[i] = IsRowSelected( grd, i+1 );
    return my::FormatBitset( rsNfo ).c_str();

}

void SetRowsSelectionInfo(TStringGrid *grd, const AnsiString& strRsNfo)
{
	const int rc = grd->RowCount;
	if( rc==0 ) return;
	std::vector<int> rsNfo;
    my::CreateBitset( strRsNfo.c_str(), rsNfo );
    rsNfo.resize(rc-1,false);
    const int sz = rsNfo.size();
    for( int i=0; i<rc-1; ++i )
    	if( i<sz && rsNfo[i]==false )
 	   		SelectRow( grd, i+1, false );
}

AnsiString ColWidthsToStr(TStringGrid *grd)
{
	AnsiString ret;
    for( int cl=0; cl<grd->ColCount; ++cl )
    	ret = ret + IntToStr( grd->ColWidths[cl] )+" ";
    return ret;
}

void SetColWidthsAsStr(TStringGrid *grd, const AnsiString& strColWidth)
{
	std::stringstream sstr( strColWidth.c_str() );

    int width = 0;
    sstr >> width;
    for( int col = 0; !sstr.fail() && col<grd->ColCount; sstr >> width, ++col )
    	grd->ColWidths[col] = width;
}




}; // namespace Grd
}; // namespace my
