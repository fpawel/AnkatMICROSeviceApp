//------------------------------------------------------------------------------
#include <fstream>
#include <vector>

#pragma hdrstop

#include "btsBuffGrdFmt.h"
#include "AnsiStringUtils_.h"

//------------------------------------------------------------------------------

#pragma package(smart_init)
//------------------------------------------------------------------------------
namespace BytesPoolGrd
{
//------------------------------------------------------------------------------
void FormatFlashDumpStringGrid( TStringGrid* grd, unsigned maxAddy )
{
    enum{ cols = 16 };
    grd->Hide();
    grd->RowCount = maxAddy / cols + 2;
    grd->ColCount = cols+1;
    for (unsigned j=1; j!=cols; ++j) grd->Cells[j][grd->RowCount-1] = "";

    for (int i=0; i<=maxAddy; i+=cols)
    	grd->Cells[0][i / cols + 1 ] = IntToHex(i,4);

    grd->FixedRows = 1;
    grd->FixedCols = 1;
  	for (int i=0; i<cols; ++i)
    	grd->Cells[i+1][0] = IntToHex(i,2);

    grd->DefaultColWidth = 30;
    grd->ColWidths[0] = 50;
    grd->Show();
}
//------------------------------------------------------------------------------
void ShowByte(TStringGrid *grd, unsigned addy, unsigned char val)
{
    const unsigned cols = grd->ColCount-1;
    grd->Cells[1+addy % cols ][ 1 + addy / cols] = MYSPRINTF_( "%2.2X", val );
}
void ClearAddy(TStringGrid *grd, unsigned addy )
{
    const unsigned cols = grd->ColCount-1;
    grd->Cells[1+addy % cols ][ 1 + addy / cols] = "";
}
unsigned char GetByte(TStringGrid *grd, unsigned addy)
{
    const unsigned cols = grd->ColCount-1;
    const MyInt v = MyStrToInt( grd->Cells[1+addy % cols ][ 1 + addy / cols], 16 );
    const unsigned val = v.first;
    return ( v.second && v.first>-1 && v.first<256 ? val : 0xFF );
}
//------------------------------------------------------------------------------
void ShowDump(TStringGrid *grd, unsigned addy, unsigned count, const unsigned char *pPool)
{
    for( unsigned i = 0; i<count; ++i )
        ShowByte(grd, addy+i, *(pPool+i));
}
void ShowClearedDump(TStringGrid *grd, unsigned addy, unsigned count )
{
    for( unsigned i = 0; i<count; ++i )
        ClearAddy(grd, addy+i );
}
//------------------------------------------------------------------------------
void ExtractDump(TStringGrid *grd, unsigned addy, unsigned count, unsigned char *pPool)
{
    for( unsigned i = 0; i<count; ++i, ++addy, ++pPool)
        *pPool = GetByte(grd, addy);

}
//------------------------------------------------------------------------------
void SaveFile(const char* fn, const unsigned char *pPool, unsigned poolSize)
{
    std::ofstream out( fn, std::ios::out | std::ios::binary );
    out.write( (const char*) pPool, poolSize );
    out.close();
}
void SaveFile( TStringGrid *grd, const char* fn )
{
    const unsigned poolSize = (grd->RowCount-1)*16;
    std::vector<unsigned char> pool(poolSize, 0xFF);
    unsigned char *pPool = &pool.at(0);
    ExtractDump( grd, 0, poolSize, pPool );
    SaveFile( fn, pPool, poolSize);
}

void LoadFile( TStringGrid *grd, const char* fn )
{
    const unsigned poolSize = (grd->RowCount-1)*16;
    std::vector<unsigned char> pool(poolSize, 0xFF);
    unsigned char *pPool = &pool.at(0);

    std::ifstream in( fn, std::ios::in | std::ios::binary | std::ios::ate );
    const unsigned
        fileSize = in.tellg(),
        count1 = std::min( poolSize,fileSize )
    ;

    in.seekg(0,std::ios::beg);
	in.read( (char*) pPool, count1 );
    in.close();

    ShowDump(grd, 0, count1, pPool);
    if(count1<poolSize)
        ShowClearedDump(grd, count1, poolSize-count1 );
}

}; // namespace BytesPoolGrd
//------------------------------------------------------------------------------
