#ifndef MY_DRAW_VCL_TSTRINGGRID_CELL_DEFINITIONS_HEADER_INCLUDED__________
#define MY_DRAW_VCL_TSTRINGGRID_CELL_DEFINITIONS_HEADER_INCLUDED__________

// vcl
#include <grids.hpp>

const TColor
    clBlednoSirenevyj = 0x0ECF0EC;

enum MyGridCellState
{
	mygdNone 		= 		0,
	mygdSelected 	= 		0x01 << 0,
    mygdFocused		=		0x01 << 1,
    mygdFixed		=		0x01 << 2,
    mygdHot			=		0x01 << 3,
    mygdRgn			=		0x01 << 4
};


#endif
