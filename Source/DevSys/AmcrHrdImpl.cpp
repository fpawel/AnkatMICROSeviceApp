//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "AmcrHrdImpl.h"
//------------------------------------------------------------------------------
#include <algorithm>
#include <dateutils.hpp>
//------------------------------------------------------------------------------

#include "ctrlsys.h"
#include "myconv.h"
#include "AnsiStringUtils_.h"
#include "guicon.h"
#include "Unit1.h"
#include "MyVclUtils_.h"
#include "a7664adpt.h"
#include "MyExcpt.hpp"
#include "my_static_check.h"
#include "TransferManage.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
A7664Adpt& Adpt()
{ return CtrlSys::Instance().GetA7664Adpt(); }
//------------------------------------------------------------------------------
namespace AnkatMicro
{
//------------------------------------------------------------------------------
unsigned ExtractDeviceWord( unsigned char *v)
{
    return (v[0]<<8)+v[1];
}
//------------------------------------------------------------------------------
unsigned ExtractDeviceUndigned(const unsigned char* p)
{
    return (p[0]<<24)+(p[1]<<16)+(p[2]<<8)+(p[3]<<0);
}
//------------------------------------------------------------------------------
namespace Flash
{
//------------------------------------------------------------------------------
void Read( unsigned addy, unsigned char *p, unsigned len)
{
    assert(len>1 && len<33);
    const unsigned char txd[4] = { addy>>16,  addy>>8, addy, len-1 };
    Adpt().PerformTransfer( 0x42, txd, txd+4 );
    const char * rxd = Adpt().AcceptedData();
    const unsigned rxdLen = Adpt().AcceptedDataSize();
    if(rxdLen!=len) MY_THROW_( MYSPRINTF_ (
        "Ошибка считывания FLASH прибора.\n"
        "Запрошено %d байт\n"
        "Получено %d байт", len, rxdLen));
    std::copy( rxd, rxd+len, p );

    if( CtrlSys::Instance().MustShowFlasLog() )
       MyWCout( MyBuffToStr( p, p+len, "Флэш ", addy, 6 )+"\n", MY_SET_CONSOLE_YELLOW_TEXT);
}
//------------------------------------------------------------------------------
unsigned char ReadByte( unsigned addy)
{
    unsigned char ret[2] = { 0xFF } ;
    try
    {
        Flash::Read(addy, ret, 2);
    }
    catch(...)
    {
        PMyExcpt e = MY_RETHROW_;
        if( !(e->TypeOf<MyA7664Exception>() &&
            e->Message().Pos("вернул код ошибки")!=0) )
            throw;
    }
    return ret[0];
}
//------------------------------------------------------------------------------
unsigned ReadWord( unsigned addy)
{
    unsigned char v[2];
    Flash::Read(addy, v, 2);
    return ExtractDeviceWord(v);
}
//------------------------------------------------------------------------------
unsigned ReadUnsigned( unsigned addy)
{
    unsigned char v[4];
    Flash::Read(addy, v, 4);
    return ExtractDeviceUndigned(v);
}
//------------------------------------------------------------------------------
}; //namespace Flash
//------------------------------------------------------------------------------
namespace Hard
{
//------------------------------------------------------------------------------
void SetCurrentDateTime()
{
    Word AYear, AMonth, ADay, AHour, AMinute, ASecond, AMilliSecond;
    DecodeDateTime( Now(), AYear, AMonth, ADay, AHour, AMinute, ASecond, AMilliSecond);
    const unsigned char
        txd1[3] = { Int2BCD(AYear-2000),  Int2BCD(AMonth), Int2BCD(ADay) },
        txd2[3] = { Int2BCD(AHour),  Int2BCD(AMinute), Int2BCD(ASecond) };
    Adpt().PerformTransfer( 0x33, txd2, txd2+3 );
    Adpt().PerformTransfer( 0x35, txd1, txd1+3 );
}
//------------------------------------------------------------------------------
AnsiString GetSoftVersion()
{
    Adpt().PerformTransfer( 0x1, NULL, NULL );
    const char * rxd = Adpt().AcceptedData();
    const unsigned len = Adpt().AcceptedDataSize();
    if(len!=10) MY_THROW_("Ошибка формата версии ПО.");
    const AnsiString ret = AnsiString(rxd+6, 1)+"."+AnsiString(rxd+8, 2);
    MYWCOUT_("Получена версия ПО: %s\n", ret));
    return ret;
}
//------------------------------------------------------------------------------
void GetHourItem(unsigned addy, ArchItem& itm)
{
    assert( addy>=Flash::hHour0 && addy<=Flash::hHour1);
    unsigned char dt[16];
    Flash::Read( addy, dt, 16 );

    itm.dateTime = ExtractDateTime( dt[0], dt[1], dt[2], dt[3], 0 );

    itm.T = dt[4];
    itm.U = ExtractDeviceWord(dt+6);

    const double k = 0.01;

    itm.conc[0] = 10. * ExtractDeviceWord(dt+8)  * k;
    itm.conc[1] = 10. * ExtractDeviceWord(dt+10) * k;
    itm.conc[2] = 10. * ExtractDeviceWord(dt+12) * k;
    itm.conc[3] = 10. * ExtractDeviceWord(dt+14) * k;

    itm.readedFromFlash = 1;

    itm.isFF = std::count(dt,dt+16,0xFF)==16;

    itm.index = Flash::Hour::Addy2RecordIndex(addy);

    MyWCout( FormatHourItem(itm)+"\n", MY_SET_CONSOLE_VELVET_TEXT);

}
//------------------------------------------------------------------------------
void GetMinuteItem(unsigned addy, ArchItem& itm)
{
    assert( addy>=Flash::hMin0 && addy<=Flash::hMin1);
    unsigned char dt[32];
    Flash::Read( addy, dt, 32 );

    itm.dateTime = ExtractDateTime( dt[0], dt[1], dt[2], dt[3], dt[4] );

    itm.evts = dt[6];

    const double k = dt[0x0E]==0 ? 0.01 : 0.001 ;

    const double kConc = CtrlSys::Instance().KConc();

    itm.T = (char)dt[5];
    itm.conc[0] = ExtractDeviceWord(dt+0x18) * k * kConc;
    itm.conc[1] = ExtractDeviceWord(dt+0x1A) * k * kConc;
    itm.conc[2] = ExtractDeviceWord(dt+0x1C) * k * kConc;
    itm.conc[3] = ExtractDeviceWord(dt+0x1E) * k * kConc;
    itm.P       = ( (unsigned) (dt[0x0F]) )*k;

    itm.index = Flash::Minute::Addy2RecordIndex(addy);
    itm.readedFromFlash = 1;
    itm.isFF = std::count(dt,dt+32,0xFF)==32;

    MyWCout(FormatMinuteItem(itm)+"\n", MY_SET_CONSOLE_VELVET_TEXT);
}
//------------------------------------------------------------------------------
void GetSensors(Sensor *sensors)
{
    enum { CNT = 4 };
    const unsigned mainBuffAddy[CNT] = {0x0000, 0x1000, 0x2000, 0x3000};
    for( unsigned nCll=0; nCll<CNT; ++nCll )
    {
        MyWCout( MYSPRINTF_( "Обращение к контексту ячейки %d\n", nCll), MY_SET_CONSOLE_VELVET_TEXT);
        const unsigned addy0 = mainBuffAddy[nCll];
        Sensor &sensor = sensors[nCll];
        sensor.type = Flash::ReadByte(addy0)
            //+ Flash::ReadByte(addy0 + 1) - 1
            ;
        sensor.conc0 = Flash::ReadWord( addy0 + 0x02)/100.0;
        sensor.conc3 = Flash::ReadWord( addy0 + 0x04)/100.0;
        sensor.lim1 = Flash::ReadWord( addy0 + 0x10)/100.0;
        sensor.lim2 = Flash::ReadWord( addy0 + 0x12)/100.0;

        unsigned char dt[6];
        Flash::Read(addy0+0x0a, dt, 6);

        sensor.dateTime = ExtractDateTime( dt[3], dt[4], dt[5], dt[0], dt[1] );
        MyWCout( MYSPRINTF_( "ПГС0=%g, ПГС3=%g, Порог 1=%g, Порог 2=%g\n",
            sensor.conc0, sensor.conc3, sensor.lim1, sensor.lim2 ), MY_SET_CONSOLE_VELVET_TEXT);
    }
}
//------------------------------------------------------------------------------
typedef std::map<unsigned, unsigned char> FlasData;
typedef FlasData::iterator IterFlash;
//------------------------------------------------------------------------------
void UpdateFlashByAddy(unsigned addy, FlasData& flash, unsigned &count)
{
    enum {step=32};
    IterFlash iAddy = flash.find(addy);
    if( iAddy == flash.end() )
    {
        const unsigned addy__0 = (addy/step)*step;
        unsigned char dt[step];
        Flash::Read( addy__0, dt, step);
        for( unsigned n=0; n<step; ++n )
            flash[addy__0+n] = dt[n];
        iAddy = flash.find(addy);
        assert( iAddy != flash.end() );
        ++count;
    }
}

//------------------------------------------------------------------------------
/*
unsigned GetActualHandleAddy(unsigned minAddy, unsigned maxAddy, FlasData& flash, unsigned &count)
{
    if( TransferManager::Instance().IsThreadStopedOrTerminated() ) return 0;

    const unsigned addy =  (minAddy + maxAddy)/2;

    UpdateFlashByAddy(addy, flash, count);

    union
    {
        unsigned char dt[8];
        struct
        {
            unsigned d1,d2;
        } d;
    } v;
    const unsigned addy__0 = (addy/8)*8;
    for( unsigned n=0; n<8; ++n )
        v.dt[n] = flash[addy__0+n];

    if( v.d.d1!=0 && v.d.d1!=-1 && v.d.d2!=0 && v.d.d2!=-1 )
        return addy__0;
        
    if( addy<maxAddy )
    {
        const unsigned addy1 = GetActualHandleAddy(addy+1, maxAddy, flash, count);
        if(addy1!=-1) return addy1;
    }
    if( addy>minAddy )
    {
        const unsigned addy2 = GetActualHandleAddy(minAddy, addy, flash, count);
        if(addy2!=-1) return addy2;
    }
    return -1;
}
*/
unsigned GetActualHandleAddy(unsigned minAddy, unsigned maxAddy, FlasData& flash)
{
    if( TransferManager::Instance().IsThreadStopedOrTerminated() ) return 0;

    unsigned not_used;
    unsigned n_result = minAddy;
    for( ; n_result < maxAddy - 8; n_result += 8 ) {
        const unsigned n1 = n_result + 8 ;
        union
        {
            unsigned char dt[8];
            struct
            {
                unsigned d1,d2;
            } d;
        } v, v1;
        UpdateFlashByAddy(n_result, flash, not_used);
        UpdateFlashByAddy(n1, flash, not_used);

        for( unsigned i=0; i<8; ++i ) {
            v.dt[i] = flash[n_result + i];
            v1.dt[i] = flash[n1 + i];
        }

        if( v.d.d1!=-1 && v.d.d2!=-1 && v1.d.d1==-1 && v1.d.d2==-1 ) {
            break;
        }
    }
    return n_result;
}
//------------------------------------------------------------------------------
unsigned GetActualHandleAddy(unsigned minAddy, unsigned maxAddy)
{
    FlasData flash;

    const unsigned
        startMoment = ::GetTickCount(),
        ret = GetActualHandleAddy(minAddy, maxAddy, flash);


    const AnsiString s = MYSPRINTF_("Поиск дескриптора: %s, %d байт считано, %d с\n",
        Addy2Str(ret),
        flash.size(), (::GetTickCount()-startMoment)/1000 );
    MyWCout(s, MY_SET_CONSOLE_VELVET_TEXT);
    return ret;
}
//------------------------------------------------------------------------------
void GetArchiveHandle(unsigned& hHour, unsigned& hMinute)
{
    MyWCout( "Поиск дескрипторов буферов\n", MY_SET_CONSOLE_VELVET_TEXT);

    //enum { step = 8 };
    typedef union { unsigned v1[2]; unsigned char v2[8]; } AnkatMicroHandle;
    MY_STATIC_CHECK_EXT_( sizeof(AnkatMicroHandle)==8, Zhopa_sizeof_AnkatMicroHandle_not_8);


    const unsigned addy0 = GetActualHandleAddy( Flash::h0, Flash::h1);
    if(addy0<Flash::h0 || addy0>Flash::h1)
        MY_THROW_("Не найден дескриптор буфера");


    AnkatMicroHandle h;
    Flash::Read(addy0, h.v2, 8);
    
    std::reverse (h.v2, h.v2+8);

    hMinute = h.v1[1], hHour = h.v1[0];

    const AnsiString sHndl = MYSPRINTF_("мин:%s:%d час:%s:%d",
        Addy2Str(hMinute) , Flash::Minute::Addy2RecordIndex(hMinute),
        Addy2Str(hHour), Flash::Hour::Addy2RecordIndex( hHour) );
    MyWCout( sHndl+"\n", MY_SET_CONSOLE_VELVET_TEXT);

    if( hMinute<Flash::hMin0 || hMinute>Flash::hMin1 || hHour<Flash::hHour0 || hHour>Flash::hHour1)
        MY_THROW_("Недостоверный дескриптор буфера. "+sHndl);
}
//------------------------------------------------------------------------------
};//namespace Hard
//------------------------------------------------------------------------------
}; //namespace AnkatMicro
//------------------------------------------------------------------------------
