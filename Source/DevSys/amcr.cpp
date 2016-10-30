
#pragma hdrstop
#include "amcr.h"
#include "AnsiStringUtils_.h"

#pragma package(smart_init)

#include "my_static_check.h"
#include "bin_nums.h"

#include <SysUtils.hpp>
#include <DateUtils.hpp>


namespace AnkatMicro
{
MY_STATIC_CHECK( ArchLen::Hour==32768, Zhopa_sizeof_ArchLenHour);
MY_STATIC_CHECK( ArchLen::Minute==97280, Zhopa_sizeof_ArchLenMinute);

namespace Gas
{
    

    const char *gas[COUNT] ={ "O2", "CO", "NO", "NO2", "SO2", "H2S", "HCl", "NH3", "CL2", "RSH", "Ex",
		"CO2",
		"ÑÎ2",
		"ÑÎ2",
		"Ñ3H8",
		"ñóììà ÑH",
		"ÑH4"
	};
    AnsiString Caption(unsigned idx)
    {
        return idx<COUNT ? gas[idx] : "";
    }

    const char
        *ob_dol = "% îá.ä.",
        *mgm3 = "ìã/ì3",
        *percent_nkpr = "% ÍÊÏÐ";

    const char *_units[COUNT] =
    {   ob_dol, mgm3, mgm3, mgm3, mgm3, mgm3, mgm3,  mgm3, mgm3, mgm3, "",
		ob_dol,
		ob_dol,
		ob_dol,
		percent_nkpr,
		percent_nkpr,
		percent_nkpr
	};

    AnsiString units(unsigned idx)
    {
        return idx<COUNT ? _units[idx] : "";
    }


};

unsigned char Int2BCD(unsigned v)
{
    const unsigned v1 = v%10, v2 = v/10;
    return (v2<<4) + v1;
}

unsigned BCD2Int(unsigned char v )
{
    const AnsiString s = AnsiString( v>>4)+AnsiString(v&0x0F);
    return StrToInt( s );
}

AnsiString Addy2Str(unsigned addy)
{
    return IntToHex( (int)addy,6);
}

TDateTime ExtractDateTime(unsigned char year, unsigned char month, unsigned char day,
    unsigned char hour, unsigned char mimute )
{
    const Word
        AYear=2000 + BCD2Int(year),
        AMonth=BCD2Int(month),
        ADay=BCD2Int(day),
        AHour=BCD2Int(hour & 0x7F),
        AMinute=BCD2Int(mimute), ASecond=0, AMilliSecond=0;
    TDateTime ret;
    if( !TryEncodeDateTime( AYear, AMonth, ADay, AHour, AMinute, ASecond, AMilliSecond, ret) )
        ret.Val = 0;

    return ret;
}

AnsiString FormatItem(const ArchItem& itm)
{
    return MYSPRINTF_("[%d], %s", itm.index, itm.isFF ? AnsiString("FF") : MyFormatDateTime(itm.dateTime) );
}

AnsiString FormatHourItem(const ArchItem& itm)
{
    return "×àñ"+FormatItem(itm);
}

bool IsMinuteMinuteEvent(const ArchItem& itm, unsigned n)
{
    assert(n<AnkatMicro::Evt::Bit::count);
    return Getbit(itm.evts, n);
}

AnsiString FormatMinuteItemEvetnts(const ArchItem& itm)
{
    using namespace AnkatMicro::Evt;
    AnsiString s;
    for( unsigned i=0; i<AnkatMicro::Evt::Bit::count; ++i )
        if( IsMinuteMinuteEvent(itm, i) )
            s = s + ToStr(i)+" ";
    return s;
}


AnsiString FormatMinuteItem(const ArchItem& itm)
{
    AnsiString s = "Ìèí."+FormatItem(itm);

    if(!itm.isFF)
        s.cat_sprintf
        (
            " T=%g\"Ñ P=%g C1=%g C2=%g C3=%g C4=%g ",
            itm.T, itm.P, itm.conc[0], itm.conc[1], itm.conc[2], itm.conc[3]
        ) +  FormatMinuteItemEvetnts(itm) ;
    return  s;
}

}; //namespace AnkatMicro

