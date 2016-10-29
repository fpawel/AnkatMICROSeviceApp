//---------------------------------------------------------------------------
#ifndef MY_T_STRING_GRID_HELPER_INCLUDED__
#define MY_T_STRING_GRID_HELPER_INCLUDED__
//---------------------------------------------------------------------------
#include <Grids.hpp>
#include "boost/tuple/tuple.hpp"
namespace my
{
	using boost::tuples::tuple;
	using boost::tuples::make_tuple;
	using boost::tuples::tie;
	//---------------------------------------------------------------------------
	//       ”точнени€ типов дл€ работы с €чейками таблиц TStringGrid
	//---------------------------------------------------------------------------
	//  €чейка таблицы
	typedef boost::tuples::tuple<TStringGrid*, int, int > Cell;
	//  столбец таблицы
	typedef boost::tuples::tuple<TStringGrid*, int > Col;
	typedef tuple<int,int,int,int, AnsiString> GridRegion;
	typedef boost::tuples::tuple<int, int, int, int > Region;

	TRect RectOfGridRegion(const GridRegion& region)
	{
		return TRect( region.get<0>(), region.get<1>(), region.get<2>(), region.get<3>() );
	}

	TRect RegionToTRect(const Region& region)
	{
		return TRect( region.get<0>(), region.get<1>(), region.get<2>(), region.get<3>() );
	}
	//---------------------------------------------------------------------------
	// ѕопадает ли €чейка col,row в фиксированную область таблицы
	bool FixedCell(int col, int row, const TStringGrid* grd)
	{
		return col < grd->FixedCols || row < grd->FixedRows;
	}
	//---------------------------------------------------------------------------
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
	std::pair<int,int> HotCell(TStringGrid* grd)
	{
		tagPOINT* pt = new tagPOINT;
		GetCursorPos(pt);
		TPoint point = grd->ScreenToClient( TPoint(pt->x, pt->y) );
		delete pt;

		std::pair<int,int> cell(-1,-1);
		grd->MouseToCell(point.x, point.y, cell.first, cell.second);
		return cell;
	}
	//---------------------------------------------------------------------------
	bool IsCellInEditMode( const TStringGrid* grd, int col, int row )
	{
		return grd->EditorMode && grd->Col == col && grd->Row==row;
	}
	void SetCellIfNotEdited(TStringGrid* grd, int col, int row, AnsiString val)
	{
		if( !IsCellInEditMode( grd, col, row  ) )
		grd->Cells[col][row] = val;
	}
   	// ќтрисовать €чейку col,row в таблице g
	void RedrawCell(TStringGrid* g, int col, int row)
	{
		SetCellIfNotEdited( g, col, row, g->Cells[col][row] );
	}


	// ќтрисовать пр€моугольник left, top, right, bottom в таблице g
	void RedrawRect(TStringGrid* g, int left, int top, int right, int bottom)
	{
		if (!g) return;
		int cl = right, ro;
		for ( ; cl >= left; --cl) for ( ro = bottom; ro >= top; --ro)
		g->Cells[cl][ro] = g->Cells[cl][ro];
	}
	//---------------------------------------------------------------------------
	// ¬озвращает видимый пр€моугольник нефиксированных €чеек таблицы
	Region VisRegion( TStringGrid* g)
	{
		int topRow = g->TopRow, visRows = g->VisibleRowCount,
			leftCol = g->LeftCol, visCols = g->VisibleColCount;
		return make_tuple( leftCol, topRow, leftCol+visCols, topRow+visRows );
	}
	void ClearTStringGrid( TStringGrid* grd, int cl0 = 0, int ro0 = 0 )
	{
		const int cc = grd->ColCount, rc = grd->RowCount;
		for( int cl = cl0; cl<cc; ++cl ) for( int ro = ro0; ro<rc; ++ro )
			grd->Cells[cl][ro] = "";
	}

}; // namespace my
//---------------------------------------------------------------------------
#endif // #ifndef MY_T_STRING_GRID_HELPER_INCLUDED__
