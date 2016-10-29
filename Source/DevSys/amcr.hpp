//------------------------------------------------------------------------------
#ifndef ANKAT_MICRO_DEFINITIONS_HEADER_INCLUDED_______
#define ANKAT_MICRO_DEFINITIONS_HEADER_INCLUDED_______
//------------------------------------------------------------------------------
#include <system.hpp>
#include <map>

namespace AnkatMicro
{
    namespace Evt
    {
        namespace Mask{ enum {
            //выключение питания			0x40
            off = 0x40,

            // заряд аккумулятора			0x20
            charge = 0x20,

            // низкое напряжение аккум.		0x10
            low_bat = 0x10,

            no_use = 0x08,

            // перепрограммирование		    0x04
            reprom = 0x04,

            // сработал WatchDog			0x02
            wdt = 0x02,

            // включение питания			0x01
            on = 0x01
        }; };

        namespace Bit{ enum {
            on, wdt, reprom, no_use1, low_bat, charge, off,  no_use2, count
        };};

        const char * const cpt[Bit::count] =
        {
            "включение питания",
            "сработал WatchDog",
            "перепрограммирование",
            "зарезервировано",
            "низкое напряжение аккумулятора",
            "заряд аккумулятора",
            "выключение питания",
            "зарезервировано"
        };

        AnsiString ToStr(unsigned n)
        {
            return n<Bit::count ? cpt[n] : "";
        }
    };

//------------------------------------------------------------------------------
    struct ArchItem
    {
        TDateTime dateTime;
        double T, U, P, conc[4];
        unsigned evts;
        bool readedFromFlash, isFF;
        unsigned index;
    };
    typedef ArchItem* PArchItem;
    //--------------------------------------------------------------------------
    AnsiString FormatHourItem(const ArchItem& itm);
    AnsiString FormatMinuteItem(const ArchItem& itm);
    AnsiString FormatItem(const ArchItem& itm);
    bool IsMinuteMinuteEvent(const ArchItem& itm, unsigned n);
    //--------------------------------------------------------------------------
    struct CellContext
    {
        unsigned type;
        TDateTime dateTime;
        double conc0, conc3, lim1, lim2;
    };
    //--------------------------------------------------------------------------
    namespace Gas
    {
        typedef enum {O2,CO,NO,NO2,SO2,H2S,HCl,NH3,CL2,RSH,NO_FLASH,
        CO2_2,
		CO2_5,
		CO2_10,
        C3H8,
		summCH,
		CH4,
        COUNT} GasType;
        AnsiString Caption(unsigned idx);
        AnsiString units(unsigned idx);
    };
    //--------------------------------------------------------------------------
    namespace Hard
    {
        void GetCellContext(CellContext *cellContext);
        void SetCurrentDateTime();
        AnsiString GetSoftVersion();
        void GetHourItem(unsigned addy, ArchItem& itm);
        void GetMinuteItem(unsigned addy, ArchItem& itm);
        void GetArchiveHandle(unsigned& hHour, unsigned& hMinute);
    };
    //--------------------------------------------------------------------------
    namespace Flash
    {
    //--------------------------------------------------------------------------
        enum
        {
            h0     = 0x00004000,
            h1     = 0x00005FFF,

            hMin0  = 0x00008000,
            hMin1  = 0x002FFFFF,

            hHour0 = 0x00300000,
            hHour1 = 0x0037FFFF,

            hEnd   = 0x00380000
        };
        //----------------------------------------------------------------------
        template<unsigned SizeOfRecord, unsigned Addy0, unsigned AddyEnd>
        struct Array
        {
            enum
            {
                Len =  (AddyEnd+1-Addy0)/SizeOfRecord
            };
            static unsigned Addy2RecordIndex(unsigned addy)
            {
                return (addy-Addy0)/SizeOfRecord;
            }
            static unsigned RecordIndex2Addy(unsigned idx)
            {
                return Addy0 + SizeOfRecord*idx;;
            }
            static unsigned IncIdx(unsigned idx, unsigned count )
            {
                while (count>Len) count+=Len;
                return (idx + count)%Len;
            }

            static unsigned RecordIndexOffset2Addy(unsigned idx0, unsigned offset)
            {
                return RecordIndex2Addy( IncIdx(idx0, offset) );
            }


            static bool IsValidAddy(unsigned addy)
            {
                return addy>=Addy0 && addy<=AddyEnd;
            }
            static void GetItem(unsigned addy, ArchItem& itm);
        }; // template<unsigned SizeOfRecord, unsigned Addy0, unsigned AddyEnd> struct Array
        //----------------------------------------------------------------------
        typedef Array<16, hHour0, hHour1> Hour;
        typedef Array<32, hMin0, hMin1> Minute;
        //----------------------------------------------------------------------
        template<> void Hour::GetItem(unsigned addy, ArchItem& itm)
        {
            Hard::GetHourItem(addy, itm);
        }
        template<> void Minute::GetItem(unsigned addy, ArchItem& itm)
        {
            Hard::GetMinuteItem(addy, itm);
        }
        //----------------------------------------------------------------------

        void Read( unsigned addy, unsigned char *p, unsigned len);
        unsigned char ReadByte( unsigned addy);
        unsigned ReadWord( unsigned addy);
        unsigned ReadUnsigned( unsigned addy);
        //----------------------------------------------------------------------
    };// namespace Flash
    //--------------------------------------------------------------------------
    namespace ArchLen
    {
        enum
        {
            Hour    = Flash::Hour::Len,
            Minute  = Flash::Minute::Len
        };
    };
    //--------------------------------------------------------------------------

    template <typename T> bool IsValidItem(const T& itm)
    {
        return itm.readedFromFlash && itm.dateTime.Val!=0;
    }
    //--------------------------------------------------------------------------
    unsigned char Int2BCD(unsigned v);
    //--------------------------------------------------------------------------
    unsigned BCD2Int(unsigned char v );
    //--------------------------------------------------------------------------
    AnsiString Addy2Str(unsigned addy);
    //--------------------------------------------------------------------------
    TDateTime ExtractDateTime(unsigned char year, unsigned char month, unsigned char day,
    unsigned char hour, unsigned char mimute );
    //--------------------------------------------------------------------------
    typedef std::map< TDateTime, AnkatMicro::ArchItem> ArchMapT;

//------------------------------------------------------------------------------
}; //namespace AnkatMicro
//------------------------------------------------------------------------------




#endif