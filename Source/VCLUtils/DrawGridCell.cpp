//---------------------------------------------------------------------------
#include <map>
#include <set>

//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
// loki
#include <loki\Functor.h>
#include "loki\singleton.h"
//---------------------------------------------------------------------------
#include "boost\tuple\tuple.hpp"
#include "boost\tuple\tuple_comparison.hpp"
#include "boost\bind.hpp"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// my
#include "my_include\Nullfoo.h"
#include "SGrdHlpr.h"
#include "myGeomtr.h"
#include "MouseEvt.h"
#include "DrawGridCell.h"
#include "AnsiStringUtils_.h"

using boost::tuples::tuple;
using boost::tuples::make_tuple;
using boost::tuples::tie;

using boost::tuples::Left;
using boost::tuples::Top;
using boost::tuples::Right;
using boost::tuples::Bottom;

#pragma package(smart_init)

namespace my
{
	void OpenModuleDrawGridCellLibrary();
	void CloseModuleDrawGridCellLibrary();
};
// для инициализации и финализации модуля
DEFINE_MY_MODULE_INSTANCE_(DrawGridCell, my::OpenModuleDrawGridCellLibrary,
	my::CloseModuleDrawGridCellLibrary );

namespace my
{
// цвет линий сетки по умолчанию
const TColor defLineClr = 0x00BCBCBC;
//---------------------------------------------------------------------------
//       Отрисовка ячеек
//---------------------------------------------------------------------------
struct DefaultFoo
{
	void AfterSetCellCanvas( TStringGrid*,int,int,MyGridCellState, TRect, int&, int&)
    {}
	void AfterDraw(TStringGrid*, int,int, MyGridCellState, TRect)
    {}
    bool BeforDrawLine(TStringGrid*,int,int,MyGridCellState,unsigned, TRect)
    {return true;}
    void OnCellBoundChange( TStringGrid*, int, int)
    {}
    void OnDeterminateColumnWidth( TStringGrid*, int, int, bool&)
    {}
};

typedef tuple
    <
    	unsigned int,
        unsigned int,
        unsigned int,
        unsigned int
    > Rct ;

//---------------------------------------------------------------------------
typedef struct CellDrawDataTag
{
	boost::shared_ptr<TFont> font_;
    boost::shared_ptr<TBrush> brush_;

    const unsigned col_;
    const unsigned row_;
    TStringGrid* grd_;

    explicit CellDrawDataTag( TStringGrid* grd, unsigned col, unsigned row );

    void __fastcall OnChange(TObject *Sender )
	{
		grd_->Cells[col_][row_] = grd_->Cells[col_][row_];
	}

} CellDrawData;
//---------------------------------------------------------------------------
typedef boost::shared_ptr<CellDrawData> PCellDrawData;
typedef std::map< IntPair, CellDrawData > CellDrawDataMap;

typedef std::map< int, CellDrawData > RowDrawDataMap;
//---------------------------------------------------------------------------


class DrawGridCellManager::Impl : public boost::noncopyable
{


public:
	explicit Impl(TStringGrid* grd, bool mustRegisterOnMouseOccurrence);

    // методы отрисовки
	DrawCellFoo::AfterSetCanvas afterSetCanvas_;
    DrawCellFoo::AfterDraw afterDraw_;
    DrawCellFoo::BeforDrawLine beforDrawLine_;
    DrawCellFoo::OnCellBoundChange onColSizing_, onRowSizing_;
    DrawCellFoo::OnDeterminateColumnWidth onDeterminateColumnWidth_;

    TStringGrid *Grd() { return grd_; }

    void EraseCellCustomDraw( unsigned col, unsigned row );
    void EraseRowCustomDraw( unsigned row );

    // получить ссылку на объект типа CellDrawData для ячейки [col, row]
    // если нет, создать
    CellDrawData& GetCellCustomDrawDataReference( unsigned col, unsigned row );

    CellDrawData& GetRowCustomDrawDataReference( unsigned row );

    void SetDrawClp(int l, int t, int r, int b);
    void SetRowPanel(int row );
    
    // получить регион
    bool GetRegion( int col, int row, Rct& rct) const;


    void SetHotCell(std::pair<int,int> newHotCell);

    // ячейка под курсором
	std::pair<int,int> GetHotCell() const    {    	return  hotCell_;    }

private:
    DefaultFoo defaultFoo_;

	// зареганный грид
    TStringGrid* grd_;

	// карта регионов
    typedef std::vector<Rct> Rcts;
    Rcts rcts_;
    std::set<int> rowPanels_;

    // карта клиентсой отрисовки
    CellDrawDataMap cellCustomDrawDataMap_;
    RowDrawDataMap rowCustomDrawDataMap_;

    // ячейка под курсором
    std::pair<int,int> hotCell_;

    // изначальный обработчик
    TMouseMoveEvent origMouseMoveEvent_;

    //
    std::map<int,int> tmpColWidths_;

    void __fastcall Draw(TObject* sender, int ACol, int ARow, const TRect& Rect, TGridDrawState State);
    void OnMouseEnterLeave( TWinControl* ctrl, bool isEntered)
	{
    	assert( dynamic_cast<TStringGrid*>(ctrl)==grd_ );
        if( !isEntered )
        	SetHotCell( std::make_pair(-1, -1) );
	}
    void __fastcall NewOnMouseMove(TObject* Sender, TShiftState Shift, int X, int Y);

    void PerformCustomDrawData(int col, int row);

};
//---------------------------------------------------------------------------
DrawGridCellManager::Impl::Impl(TStringGrid* grd, bool mustRegisterOnMouseOccurrence) :
    	defaultFoo_(), grd_(grd),
        afterSetCanvas_(&(defaultFoo_.AfterSetCellCanvas)),
        afterDraw_(&(defaultFoo_.DefaultFoo::AfterDraw)),
        beforDrawLine_(&(defaultFoo_.DefaultFoo::BeforDrawLine)),
        onColSizing_(&(defaultFoo_.DefaultFoo::OnCellBoundChange)),
        onRowSizing_(&(defaultFoo_.DefaultFoo::OnCellBoundChange)),
        onDeterminateColumnWidth_( &(defaultFoo_.DefaultFoo::OnDeterminateColumnWidth) ),
        hotCell_(-1,-1),
        origMouseMoveEvent_( grd_->OnMouseMove )
{
    grd_->OnDrawCell = Draw;
    grd_->DefaultDrawing  = false;
    grd->GridLineWidth = 0;
    if( mustRegisterOnMouseOccurrence )
    {
        grd_->OnMouseMove = NewOnMouseMove;
        RegisterOnMouseOccurrence( grd_, &OnMouseEnterLeave  );
    }
}
//---------------------------------------------------------------------------
void DrawGridCellManager::Impl::EraseCellCustomDraw( unsigned col, unsigned row )
{
        cellCustomDrawDataMap_.erase( std::make_pair(col,row) );
        Grd::RedrawCell(grd_, col, row);
}
void DrawGridCellManager::Impl::EraseRowCustomDraw( unsigned row )
{
        rowCustomDrawDataMap_.erase( row );
        Grd::RedrawRow(grd_, row);
}

//---------------------------------------------------------------------------
void DrawGridCellManager::Impl::SetHotCell(std::pair<int,int> newHotCell)
{
		if( newHotCell == hotCell_ ) return;
        const int
        oldCl = hotCell_.first, oldRo=hotCell_.second,
        newCl = newHotCell.first, newRo=newHotCell.second;

        if( oldCl!=-1 && oldRo!=-1 )
    		grd_->Cells[oldCl][oldRo]=grd_->Cells[oldCl][oldRo];
    	if( newCl!=-1 && newRo!=-1 )
    		grd_->Cells[newCl][newRo]=grd_->Cells[newCl][newRo];
        hotCell_ = newHotCell;
}

void __fastcall DrawGridCellManager::Impl::NewOnMouseMove(TObject* Sender, TShiftState Shift, int X, int Y)
{
	grd_->ShowHint = 0;
    grd_->ShowHint = 1;
    	int cl = -1, ro=-1;
    	grd_->MouseToCell(X, Y, cl, ro);
    	SetHotCell( std::make_pair(cl, ro) );
    	if( origMouseMoveEvent_!=NULL ) origMouseMoveEvent_(Sender, Shift, X, Y);

}

bool DrawGridCellManager::Impl::GetRegion( int col, int row, Rct& rct) const
{
	/*
	if( col>grd_->FixedCols-1 && rowPanels_.find( row )!= rowPanels_.end() )
    {
    	rct = Rct( grd_->FixedCols, row, grd_->ColCount-1, row);
        return true;
    }
    */
    if( rowPanels_.find( row )!= rowPanels_.end() )
    {
    	rct = Rct( 0, row, grd_->ColCount-1, row);
        return true;
    }

    using boost::bind;
    using boost::tuples::PointInRect;
	Rcts::const_iterator  end = rcts_.end(), itr =
    std::find_if
    (
    	rcts_.begin(), end,
        bind( PointInRect<unsigned>,make_tuple(col,row),_1 )
    );
    const bool ret = itr!=end;
    if(ret) rct = *itr;
    return itr!=end;
}
//---------------------------------------------------------------------------
MyGridCellState MakeMyGridCellState(TGridDrawState State, bool isHotCell)
{
	MyGridCellState myGridState = mygdNone;

    if( State.Contains(gdFixed) )
        		myGridState += mygdFixed;
    if( State.Contains(gdSelected) )
        		myGridState += mygdSelected;
    if( State.Contains(gdFocused) )
        		myGridState += mygdFocused;
    if( isHotCell )
        	myGridState += mygdHot;
    return myGridState;
}


void __fastcall DrawGridCellManager::Impl::Draw(TObject* sender, int ACol, int ARow,
const TRect& Rect, TGridDrawState State)
{
		#define CELLS grd_->Cells
	TCanvas &cnv = *grd_->Canvas;
        assert(grd_ == dynamic_cast<TStringGrid*>(sender) );
		AnsiString cellText; 	// рисуемый текст
		TRect textRect;			// рисуемый прямоугольник
        const Grd::Cell cell(grd_,ACol,ARow);
        const bool
        //isFixed = Grd::IsCellFixed(cell),
        isHotCell = (std::make_pair(ACol,ARow)==hotCell_);
        MyGridCellState myGridState = MakeMyGridCellState(State, isHotCell);

		// проверить наличее региона для ячейки
        Rct rgn;
        const bool isCellInRgn = GetRegion(ACol,ARow, rgn);
		if( isCellInRgn )
		{
        	// формировать параметры отрисовки региона
			const TRect
            r1 = grd_->CellRect( Left(rgn), Top(rgn) ),
            r2 = grd_->CellRect( Right(rgn), Bottom(rgn) );

			textRect.Top = r1.Top;
			textRect.Left = r1.Left;
			textRect.right = r2.right;
			textRect.bottom = r2.bottom;

            cellText = grd_->Cells[Left(rgn)][Top(rgn)];
            myGridState |= mygdRgn;

		} else
		{
        	// формировать параметры отрисовки ячейки
			cellText = CELLS[ACol][ARow];
			textRect = Rect;
		}

        // установить параметры отрисовки
        PerformCustomDrawData(ACol, ARow);

        if( isHotCell )
        	cnv.Font->Style = cnv.Font->Style + (TFontStyles() << fsUnderline);

		cnv.Pen->Color   = defLineClr;
        cnv.Pen->Width = -1;

		// параметры
		int
		textW = cnv.TextWidth( cellText ),   	//ширина текста
		textH  = cnv.TextHeight( cellText ); 	//высота текста

        //автоподбор ширины колонки
        bool enableDeterminateColWidth = !isCellInRgn;
        onDeterminateColumnWidth_( grd_, ACol, ARow, enableDeterminateColWidth );
		if( enableDeterminateColWidth && !isCellInRgn )
		{
			if ( textW+10>grd_->ColWidths[ACol] )
			grd_->ColWidths[ACol] = textW+10;
		}

        if( !enableDeterminateColWidth && (textW+3 > textRect.Width() ) )
        {
        	/*
        	const int
            	w1 = cnv.TextWidth( "..." ),
            	len = cellText.Length();
        	const AnsiString origCellText = cellText;
            cellText = "";
            for( int i=0; i<len; ++i )
            {
            	const AnsiString s1 = cellText + AnsiString(origCellText[i+1]);
            	if( cnv.TextWidth(s1)+w1+3 > textRect.Width() )
                	break;
                cellText = s1;
            }
            cellText = cellText + "...";
            */
            cellText = CutCellText(cellText, cnv, textRect.Width());
        }

        // позиция левого верхнего угла прямоугольника с текстом
        const TPoint txtLT = GetCenterPosition( textRect, textW, textH );
        int txtX = txtLT.x, txtY = txtLT.y;
        afterSetCanvas_(grd_, ACol, ARow, myGridState, textRect, txtX,  txtY );

		// вывод текста
		cnv.TextRect(Rect, txtX,  txtY,  cellText	);

		// обрамление
        cnv.MoveTo(textRect.Left,textRect.Bottom);
        #pragma warn -8037
    	if( beforDrawLine_(grd_, ACol, ARow, myGridState, GridLineT::left,  textRect) )
        	cnv.LineTo(textRect.Left,textRect.Top);
        if( beforDrawLine_(grd_, ACol, ARow, myGridState, GridLineT::top,  textRect) )
        	cnv.LineTo(textRect.Right-1,textRect.Top);
    	#pragma warn +8037


        if( ACol==my::Grd::GetLastVisCol(grd_) )
        	cnv.LineTo(Rect.Right-1,Rect.Bottom);

        if(ARow==my::Grd::GetLastVisRow(grd_) )
        {
        	cnv.MoveTo(Rect.Right,Rect.Bottom-1);
        	cnv.LineTo(Rect.Left,Rect.Bottom-1);
		}

		// отказ от отрисовки фикседов по умолчанию
        //grd_->DefaultDrawing  = !isFixed;
        
    	afterDraw_(grd_, ACol, ARow, myGridState, textRect);

        //cnv.Assign(tmpCanvas.get());
		#undef CELLS grd_->Cells
	// диспетчерезация события "изменилась длина колонки"
    if( tmpColWidths_[ACol]!=grd_->ColWidths[ACol] )
    {
    	onColSizing_(grd_, ACol, tmpColWidths_[ACol] );
        tmpColWidths_[ACol] = grd_->ColWidths[ACol];
    }

}
//---------------------------------------------------------------------------
void DrawGridCellManager::Impl::PerformCustomDrawData(int ACol, int ARow)
{
	TCanvas &cnv = *grd_->Canvas;
	const CellDrawDataMap::const_iterator pCellCustomDrawData =
    cellCustomDrawDataMap_.find( std::make_pair(ACol,ARow) );

    if( pCellCustomDrawData!=cellCustomDrawDataMap_.end() )
    {
    	cnv.Brush->Assign( pCellCustomDrawData->second.brush_.get() );
        cnv.Font->Assign( pCellCustomDrawData->second.font_.get() );
    } else
    {
		const RowDrawDataMap::const_iterator pRowCustomDrawData =
        rowCustomDrawDataMap_.find( ARow );

        if( pRowCustomDrawData!=rowCustomDrawDataMap_.end() )
        {
        	cnv.Brush->Assign( pRowCustomDrawData->second.brush_.get() );
            cnv.Font->Assign( pRowCustomDrawData->second.font_.get() );
        } else
        {
        	cnv.Brush->Assign( grd_->Brush );
            cnv.Font->Assign( grd_->Font );
            cnv.Brush->Color = Grd::IsCellFixed(Grd::Cell(grd_,ACol,ARow)) ? grd_->FixedColor : grd_->Color;
        }
    }
}

void DrawGridCellManager::Impl::SetDrawClp(int l, int t, int r, int b )
{
	assert( !(r<l) && !(b<t));

	typedef Rcts::const_iterator IterC;
	IterC end = rcts_.end(), beg = rcts_.begin();
    const Rct rect(l,t,r,b);

	// проверить, не пересекается ли рект с другими ректами в карте
    const bool areRectsNotIntersected =
    std::find_if
    (
    	beg, end,
    	boost::bind(boost::tuples::AreRectsIntersected<unsigned>,rect,_1)
    )==end;
    assert( areRectsNotIntersected && "Cliped regions are intersected!");
	rcts_.push_back( rect );
}

void DrawGridCellManager::Impl::SetRowPanel(int row )
{
	rowPanels_.insert(row);
}

//---------------------------------------------------------------------------
// получить ссылку на объект типа CellDrawData для ячейки [col, row]
// если нет, создать
CellDrawData& DrawGridCellManager::Impl::GetCellCustomDrawDataReference( unsigned col, unsigned row )
{
	const IntPair cell(col,row);


    const CellDrawDataMap::iterator pCellCustomDrawData =
        cellCustomDrawDataMap_.find( cell );
    if( pCellCustomDrawData!=cellCustomDrawDataMap_.end() )
    	return pCellCustomDrawData->second;
    // вставить новый обект в карту
    const CellDrawDataMap::value_type insertedValue(cell, CellDrawData( grd_, col, row ) );
    const std::pair<CellDrawDataMap::iterator,bool> ins =
    cellCustomDrawDataMap_.insert(insertedValue);
    assert(ins.second);
    CellDrawData& ret = ins.first->second;

    ret.font_->OnChange = ret.OnChange;
    ret.brush_->OnChange = ret.OnChange;
    return ret;
}

CellDrawData& DrawGridCellManager::Impl::GetRowCustomDrawDataReference( unsigned row )
{
    const RowDrawDataMap::iterator pRowCustomDrawData =
        rowCustomDrawDataMap_.find( row );
    if( pRowCustomDrawData!=rowCustomDrawDataMap_.end() )
    	return pRowCustomDrawData->second;
    // вставить новый обект в карту
    const RowDrawDataMap::value_type insertedValue(row, CellDrawData( grd_, 0, row ) );
    const std::pair<RowDrawDataMap::iterator,bool> ins =
    	rowCustomDrawDataMap_.insert(insertedValue);
    assert(ins.second);
    CellDrawData& ret = ins.first->second;

    ret.font_->OnChange = ret.OnChange;
    ret.brush_->OnChange = ret.OnChange;
    return ret;
}

void DrawGridCellManager::SetDrawClp(int l, int t, int r, int b )
{
	impl_->SetDrawClp(l, t, r, b );
}

void DrawGridCellManager::SetRowPanel(int row )
{
	impl_->SetRowPanel( row );
}

void DrawGridCellManager::SetAfterSetCanvasFoo(DrawCellFoo::AfterSetCanvas foo)
{
    impl_->afterSetCanvas_ = foo;
}

void DrawGridCellManager::SetAfterDrawFoo(DrawCellFoo::AfterDraw foo)
{
    impl_->afterDraw_ = foo;
}

void DrawGridCellManager::SetBeforDrawLineFoo(DrawCellFoo::BeforDrawLine foo)
{
    impl_->beforDrawLine_ = foo;
}

void DrawGridCellManager::SetOnColSizingFoo(DrawCellFoo::OnCellBoundChange foo)
{
	impl_->onColSizing_ = foo;
}

void DrawGridCellManager::SetOnDeterminateColumnWidthFoo(DrawCellFoo::OnDeterminateColumnWidth foo)
{
	impl_->onDeterminateColumnWidth_ = foo;
}

//--------------------------------------------------------------------------------
typedef boost::shared_ptr<DrawGridCellManager> PDrawGridCellManager;
typedef std::map<TStringGrid*, PDrawGridCellManager > AssocGrdMan;
struct AssociatedGridsT
{
	AssocGrdMan assocGrdMan_;
    void Add(TStringGrid *grd, const DrawGridCellManager *grdMan)
    {
    	PDrawGridCellManager pGrdMan( const_cast<DrawGridCellManager*>(grdMan), my::NullDeleter() );
    	assocGrdMan_.insert( std::make_pair(grd, pGrdMan ) );
    }
    DrawGridCellManager& Get(TStringGrid *grd)
    {
    	const AssocGrdMan::iterator e = assocGrdMan_.end(),
        i = assocGrdMan_.find(grd);
        assert(i!=e);
        return *( i->second.get() );
    }

    void Del(TStringGrid *grd)
    {
    	assocGrdMan_.erase(grd);
    }
};
typedef Loki::SingletonHolder
<
	AssociatedGridsT,
    Loki::CreateUsingNew,
    Loki::NoDestroy
> AssociatedGrids;


// получить менеджер отрисовки для заданной таблицы
DrawGridCellManager& DrawGridCellManager::GetDrawCellManager( TStringGrid* grd )
{
	AssociatedGridsT& assoc = AssociatedGrids::Instance();
    return assoc.Get(grd);
}

//
void UnregisterDrawCellManager( TStringGrid* grd )
{
    AssociatedGridsT& assoc = AssociatedGrids::Instance();
    return assoc.Del(grd);
}

//--------------------------------------------------------------------------------
DrawGridCellManager::DrawGridCellManager(TStringGrid* grd,
	bool mustRegisterOnMouseOccurrence) : impl_( PImpl( new Impl(grd, mustRegisterOnMouseOccurrence) ) )
{
	AssociatedGridsT& assoc = AssociatedGrids::Instance();
    assoc.Add(grd,this);
}

DrawGridCellManager::~DrawGridCellManager()
{
	AssociatedGridsT& assoc = AssociatedGrids::Instance();
    assoc.Del( impl_->Grd() );
}


// ячейка под курсором
std::pair<int,int> DrawGridCellManager::GetHotCell() const
{
	return impl_->GetHotCell();
}

// получить (создать, если нет) клиентские данные отрисовки
TFont& DrawGridCellManager::GetCellCustomDrawFont(unsigned col, unsigned row)
{
    return *(impl_->GetCellCustomDrawDataReference(col,row).font_.get() );
}

// получить (создать, если нет) клиентские данные отрисовки
TBrush& DrawGridCellManager::GetCellCustomDrawBrush( unsigned col, unsigned row )
{
	return *(impl_->GetCellCustomDrawDataReference(col,row).brush_.get() );
}

TBrush& DrawGridCellManager::GetRowCustomDrawBrush( unsigned row )
{
	return *(impl_->GetRowCustomDrawDataReference(row).brush_.get() );
}

// удалить клиентские данные отрисовки
void DrawGridCellManager::EraseCellCustomDraw( unsigned col, unsigned row )
{
    impl_->EraseCellCustomDraw( col, row );
}

void DrawGridCellManager::EraseRowCustomDraw( unsigned row )
{
    impl_->EraseRowCustomDraw( row );
}

CellDrawDataTag::CellDrawDataTag( TStringGrid* grd, unsigned col, unsigned row ) :
	col_(col), row_(row), grd_(grd),
    font_ (new  TFont ), brush_( new TBrush )

{
	font_->Assign(grd->Font);
    brush_->Assign(grd->Brush);
    if ( Grd::IsCellFixed( Grd::Cell(grd,col,row))  )
    	brush_->Color = grd->FixedColor;
}

AutoRedrawCellHelper::AutoRedrawCellHelper( TStringGrid* grd, unsigned col, unsigned row ) :
	col_(col), row_(row), dgcMan_( AssociatedGrids::Instance().Get(grd) )
{
}

TFont& AutoRedrawCellHelper::GetFont() const
{
	return dgcMan_.GetCellCustomDrawFont( col_, row_ );
}

TBrush& AutoRedrawCellHelper::GetBrush() const
{
	return dgcMan_.GetCellCustomDrawBrush( col_, row_ );
}

AutoRedrawCellHelper::~AutoRedrawCellHelper()
{
	dgcMan_.EraseCellCustomDraw( col_, row_ );
}

void OpenModuleDrawGridCellLibrary()
{
	// проверка уникальности вызова функции
	ASSERT_FUNCTION_CALLED_ONCE__;
}
void CloseModuleDrawGridCellLibrary()
{
	// проверка уникальности вызова функции
	ASSERT_FUNCTION_CALLED_ONCE__;
    //delete &my::AssociatedGrids::Instance();
}

};//namespace my
////////////////////////////////////////////////////////////////////////////////
