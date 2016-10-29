//---------------------------------------------------------------------------
#ifndef btsBuffGrdFmtH
#define btsBuffGrdFmtH
//---------------------------------------------------------------------------
#include <grids.hpp>
//---------------------------------------------------------------------------
#define CHIP_24LC64_MAX_ADDY 0x1FFF
namespace BytesPoolGrd
{
    void FormatFlashDumpStringGrid( TStringGrid* grd, unsigned maxAddy );
    void ShowByte(TStringGrid *grd, unsigned addy, unsigned char val);
    void ShowDump(TStringGrid *grd, unsigned addy, unsigned count, const unsigned char *pPool);
    void SaveFile( TStringGrid *grd, const char* fn );
    void LoadFile( TStringGrid *grd, const char* fn );
    void ExtractDump(TStringGrid *grd, unsigned addy, unsigned count, unsigned char *pPool);

    
};

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
