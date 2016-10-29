#ifndef MY_T_STRING_GRID_CELL_HEADER_INCLUDED___
#define MY_T_STRING_GRID_CELL_HEADER_INCLUDED___

#include <utility>

typedef std::pair< TStringGrid*, std::pair<int,int> > GrdCell;
GrdCell MakeGrdCell(TStringGrid *grd, int col, int row)
{
    return std::make_pair( grd, std::make_pair(col,row) );
}


#endif