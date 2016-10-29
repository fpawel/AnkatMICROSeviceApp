//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "alchemy.h"
//------------------------------------------------------------------------------
#include <Algorithm>
#include <cassert>
#include <math>
//------------------------------------------------------------------------------
#include <SysUtils.hpp>
//------------------------------------------------------------------------------
#include "bcd_.h"
#include "guicon.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
int MyFRound(double number)
{
    const double
        down = std::floor(number),
        up = std::ceil(number),
        dDown = std::fabs(number-down),
        dUp = std::fabs(number-up);
    return dDown<dUp ? down : up;
}
//------------------------------------------------------------------------------
double MyPiecewiseLinearInterpolation1Value( const XY* tbl, const XY* tblEnd, double x )
{
    if( x>=(tblEnd-1)->first )
        return (tblEnd-1)->second;
    if( x<=tbl->first )
        return tbl->second;

    const XY* p2 = std::lower_bound( tbl, tblEnd, std::make_pair( x, 0.0) );
    assert( p2>tbl && p2<=(tblEnd-1) );
    const XY* p1 = p2-1;

    const double
        &x1 = p1->first, &y1 = p1->second, &x2 = p2->first, &y2 = p2->second,
        b = (y2-y1)/(x2-x1),
        a = y1-b*x1;
    return a + b*x;

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/*
void  MakeIbgSrcTbl2( double I20, double I50, XY f[] )
{
    std::copy( def_T_F, def_T_F+8, f);
    f[t20] = XY( 20, I20);
    f[t50] = XY( 50, I50);

    double
        &I_40 = f[t_40].second,
        &I_20 = f[t_20].second,
        &I0 = f[t0].second,
        //&I20 = f[t20].second,
        &I30 = f[t30].second,
        &I40 = f[t40].second,
        &I45 = f[t45].second;
        //&I50 = f[t50].second,
    const double d = std::fabs(I50-I20);
    const bool
        sign_d = I50-I20>0, les01 = d<100;
    if( ( (I50>=0)&&(I20>=0)||(I50<=0)&&(I20<=0) ) && !les01 )
    {
        I_40 = 0;
        I_20 = I20*0.2;
        I0 = I20*0.5;
        I40 = (I50 - I20)*0.5 + I20;
        I45 = (I50 - I40)*0.5 + I40;
        I30 = (I40 - I20)*0.5 + I20;
    }
    else if( les01 && I20>0 )
    {
        I_40 = 0;
        I_20 = I20*0.6;
        I0 = I20*0.9;
        I40 = (I50 - I20)*0.5 + I20;
        I45 = (I50 - I40)*0.5 + I40;
        I30 = (I40 - I20)*0.5 + I20;
    }
    else if( !les01 && I20<0 )
    {
        I_40 = 0;
        I_20 = I20*0.6;
        I0 = I20*0.9;
        I40 = (I50 - I20)*0.5 + I20;
        I45 = (I50 - I40)*0.5 + I40;
        I30 = (I40 - I20)/3.0 + I20;
    }
    else if( I50>=0 && I20>=0 && sign_d && les01 || I50<=0 && I20<=0 && !sign_d && les01 )
    {
        I_40 = 0;
        I_20 = I20*0.3;
        I0 = I20*0.75;
        I40 = I50;
        I45 = I50;
        I30 = I50;
    }
}
//------------------------------------------------------------------------------
void MakeIbgSrcTbl3( double I_20, double I20, double I50,
    XY f[] )
{   
    std::copy( def_T_F, def_T_F+8, f);
    f[t_20] = XY(-20, I_20);
    f[t20] = XY( 20, I20);
    f[t50] = XY( 50, I50);
    double
        &I_40 = f[t_40].second,
        //&I_20 = f[t_20].second,
        &I0 = f[t0].second,
        //&I20 = f[t20].second,
        &I30 = f[t30].second,
        &I40 = f[t40].second,
        &I45 = f[t45].second;
        //&I50 = f[t50].second,
    const double d = std::fabs(I50-I20);
    const bool
        sign_d = I50-I20>0, les01 = d<100;
    if( ( (I50>=0)&&(I20>=0)||(I50<=0)&&(I20<=0) ) && !les01 )
    {
        I_40 = I_20-0.5*(I20-I_20);
        I0 = I20-0.5*(I20-I_20);
        I40 = (I50 - I20)*0.5 + I20;
        I45 = (I50 - I40)*0.5 + I40;
        I30 = (I40 - I20)*0.5 + I20;
    }
    else if( les01 && I20>0 )
    {
        I_40 = I_20-0.5*(I20-I_20);
        I0 = I20-0.5*(I20-I_20);
        I40 = (I50 - I20)*0.5 + I20;
        I45 = (I50 - I40)*0.5 + I40;
        I30 = (I40 - I20)*0.5 + I20;
    }

    else if( !les01 && I20<0 )
    {
        I_40 = I_20-0.5*(I20-I_20);
        I0 = I20-0.5*(I20-I_20);
        I40 = (I50 - I20)*0.5 + I20;
        I45 = (I50 - I40)*0.5 + I40;
        I30 = (I40 - I20)/3.0 + I20;
    }
    else if( I50>=0 && I20>=0 && sign_d && les01 || I50<=0 && I20<=0 && !sign_d && les01 )
    {
        I_40 = I_20-0.5*(I20-I_20);
        I0 = I20-0.5*(I20-I_20);
        I40 = I50;
        I45 = I50;
        I30 = I50;
    }
}
*/
void  MakeIbgSrcTbl2( double I20, double I50, XY f[] )
{
    std::copy( def_T_F, def_T_F+8, f);
    f[t20] = XY( 20, I20);
    f[t50] = XY( 50, I50);

    double
        &I_40 = f[t_40].second,
        &I_20 = f[t_20].second,
        &I0 = f[t0].second,
        //&I20 = f[t20].second,
        &I30 = f[t30].second,
        &I40 = f[t40].second,
        &I45 = f[t45].second;
        //&I50 = f[t50].second,
    I_40 = 0;
    I_20 = I20*0.2;
    I0 = I20*0.5;
    I40 = (I50 - I20)*0.5 + I20;
    I45 = (I50 - I40)*0.5 + I40;
    I30 = (I40 - I20)*0.5 + I20;
}
//------------------------------------------------------------------------------
void MakeIbgSrcTbl3( double I_20, double I20, double I50,
    XY f[] )
{
    std::copy( def_T_F, def_T_F+8, f);
    f[t_20] = XY(-20, I_20);
    f[t20] = XY( 20, I20);
    f[t50] = XY( 50, I50);
    double
        &I_40 = f[t_40].second,
        //&I_20 = f[t_20].second,
        &I0 = f[t0].second,
        //&I20 = f[t20].second,
        &I30 = f[t30].second,
        &I40 = f[t40].second,
        &I45 = f[t45].second;
        //&I50 = f[t50].second,
    I_40 = I_20-0.5*(I20-I_20);
    I0 = I20-0.5*(I20-I_20);
    I40 = (I50 - I20)*0.5 + I20;
    I45 = (I50 - I40)*0.5 + I40;
    I30 = (I40 - I20)*0.5 + I20;
}
//------------------------------------------------------------------------------
void  MakeKsnsSrcTbl2( double K20, double K50, XY *f )
{
    std::copy( def_T_F, def_T_F+8, f);
    f[t20] = XY( 20, K20);
    f[t50] = XY( 50, K50);
    double
        &K_40 = f[t_40].second,
        &K_20 = f[t_20].second,
        &K0 = f[t0].second,
        //&I20 = f[t20].second,
        &K30 = f[t30].second,
        &K40 = f[t40].second,
        &K45 = f[t45].second;
        //&I50 = f[t50].second,
    K_40 = 30;
    K_20 = 58;
    K0 = 82;
    K40 = (K50-K20)*0.5+K20;
    K30 = (K40-K20)*0.5+K20;
    K45 = (K50-K40)*0.5+K40;
}
//------------------------------------------------------------------------------
void  MakeKsnsSrcTbl3( double K_20, double K20, double K50, XY *f )
{
    std::copy( def_T_F, def_T_F+8, f);
    f[t20] = XY( 20, K20);
    f[t50] = XY( 50, K50);
    f[t_20] = XY( -20, K_20);
    double
        &K_40 = f[t_40].second,
        //&K_20 = f[t_20].second,
        &K0 = f[t0].second,
        //&I20 = f[t20].second,
        &K30 = f[t30].second,
        &K40 = f[t40].second,
        &K45 = f[t45].second;
        //&I50 = f[t50].second,
    if(K_20>=0.45*K20)
    {
        K0 = (K20-K_20)*0.5+K_20;
        K_40 = 2*K_20-K0;
        K40 = (K50-K20)*0.5+K20;
        K30 = (K40-K20)*0.5+K20;
        K45 = (K50-K40)*0.5+K40;
    }
    else if( K_20>0 )
    {
        K_40 = 2*K_20-K0+1.2*(45-K_20)/( 0.43429*std::log(K_20) );
        K0 = (K20-K_20)*0.5+K_20;
        K40 = (K50-K20)*0.5+K20;
        K30 = (K40-K20)*0.5+K20;
        K45 = (K50-K40)*0.5+K40;
    }

    
}
//------------------------------------------------------------------------------


namespace ECCFlash
{
//------------------------------------------------------------------------------
int ExtractIbg( int T, const unsigned char* buff )
{
    unsigned addy;
    if(T>=0)
    {
        if( T>124 ) T=124;
        addy = 0x0100 + T*2;
    }
    else
    {
        T = T * -1;
        if( T>124 ) T=124;
        addy = T*2;
    }
    union
    {
        short int ret;
        unsigned char p[4];
    };
    ret = 0;
    p[0] = buff[addy];
    p[1] = buff[addy+1];
    return ret;
}
//------------------------------------------------------------------------------
int ExtractKsns( int T, const unsigned char* buff )
{
    unsigned addy;
    if(T>=0)
    {
        if( T>124 ) T=124;
        addy = 0x0500 + T*2;
    }
    else
    {
        T = T * -1;
        if( T>124 ) T=124;
        addy =0x0400 +  T*2;
    }
    union
    {
        short int ret;
        unsigned char p[4];
    };
    ret = 0;
    p[0] = buff[addy];
    p[1] = buff[addy+1];
    return ret;
}
//------------------------------------------------------------------------------
void ExtractIbgKsnsSource( const unsigned char *buff, XY T_Ibg[], XY T_Ksns[] )
{
    for( unsigned i=0; i<8; ++i )
    {
        const int
            T   = def_T_F[i].first,
            Ibg = ExtractIbg( T, buff ),
            Ksns = ExtractKsns( T, buff )
        ;
        T_Ibg[i] = XY( T, Ibg );
        T_Ksns[i] = XY( T, Ksns );
    }
}
//------------------------------------------------------------------------------
void AddIbg( const XY T_Ibg[], unsigned char* buff)
{
    int temperature = 0;
    for( unsigned addy=0; addy<=0x00F8; addy+=2, --temperature )
    {
        const int v = MyFRound( MyPiecewiseLinearInterpolation1Value(
            T_Ibg, T_Ibg+8, temperature ) );
        buff[addy + 0] = v;
        buff[addy + 1] = v>>8;
    }
    temperature = 0;
    for( unsigned addy=0x0100; addy<=0x01F8; addy+=2, ++temperature )
    {
        const int v = MyFRound( MyPiecewiseLinearInterpolation1Value(
            T_Ibg, T_Ibg+8, temperature ) );
        buff[addy + 0] = v;
        buff[addy + 1] = v>>8;
    }
}
//------------------------------------------------------------------------------
void AddKsns( const XY T_Ksns[], unsigned char* buff)
{
    int temperature = 0;
    for( unsigned addy=0x0400; addy<=0x04F8; addy+=2, --temperature )
    {
        const int v = MyFRound( MyPiecewiseLinearInterpolation1Value(
            T_Ksns, T_Ksns+8, temperature ) );
        buff[addy + 0] = v;
        buff[addy + 1] = v>>8;
    }
    temperature = 0;
    for( unsigned addy=0x0500; addy<=0x05F8; addy+=2, ++temperature )
    {
        const int v = MyFRound( MyPiecewiseLinearInterpolation1Value(
            T_Ksns, T_Ksns+8, temperature ) );
        buff[addy + 0] = v;
        buff[addy + 1] = v>>8;
    }
}
//------------------------------------------------------------------------------
void AddSource( const XY T_Ibg[], const XY T_Ksns[], unsigned char* buff)
{
    unsigned addy = 0x0710;
    buff[addy++] = 8;
    for( unsigned i=0; i<8; ++i )
    {
        const int T = MyFRound( T_Ibg[i].first );
        buff[addy + 0] = T;
        buff[addy + 1] = T >> 8;
        addy+=2;
    }
    for( unsigned i=0; i<8; ++i )
    {
        const int Ibg = MyFRound( T_Ibg[i].second );
        buff[addy + 0] = Ibg;
        buff[addy + 1] = Ibg >> 8;
        addy+=2;
    }
    for( unsigned i=0; i<8; ++i )
    {
        const int Ksns = MyFRound( T_Ksns[i].second );
        buff[addy + 0] = Ksns;
        buff[addy + 1] = Ksns >> 8;
        addy+=2;
    }
}
//------------------------------------------------------------------------------
enum
{
    ECC_TYPE_STR_LEN = 50
};
void AddECCInfo(const ECCInfo& ecc, unsigned char* buff)
{
    buff[0x0700] = 0x42;
    FloatToBCD( ecc.number, buff+0x0701);
    //FloatToBCD( ecc.Ibg20,  buff+0x0705);
    //FloatToBCD( ecc.Ksns20, buff+0x0709);
    Word Year, Month, Day;
    DecodeDate( ecc.manufactureDate, Year, Month, Day);
    Year = Year-2000;
    buff[0x070D] = Day;
    buff[0x070E] = Month;
    buff[0x070F] = Year;

    buff[0x0600] = ecc.gas;
    buff[0x060A] = ecc.units;
    FloatToBCD( ecc.scale_min, buff+0x0602);
    FloatToBCD( ecc.scale_max, buff+0x0606);

    FloatToBCD( ecc.scale_max, buff+0x0606);
    unsigned char *s1 = buff+0x060B;
    const unsigned char* s2 =  (const unsigned char*)ecc.type.c_str();
    const unsigned len = std::min( ECC_TYPE_STR_LEN-1, ecc.type.Length() );
    std::copy( s2, s2+len, s1 );
    *(s1 + len) = 0;

}
//------------------------------------------------------------------------------
void ExtractECCInfo(ECCInfo& ecc, unsigned char* buff)
{
    buff[0x0700] = 0x42;
    ecc.number = BCDToFloatDef(buff+0x0701, 0);
    const Word
        Day = buff[0x070D],
        Month = buff[0x070E],
        Year = 2000 + buff[0x070F];
    if( !TryEncodeDate( Year, Month, Day, ecc.manufactureDate) )
        ecc.manufactureDate = 0;
    ecc.gas = buff[0x0600];
    ecc.units = buff[0x060A];
    ecc.scale_min = BCDToFloatDef(buff+0x0602, 0);
    ecc.scale_max = BCDToFloatDef(buff+0x0606, 0);
    unsigned char *s1 = buff+0x060B, s2[ECC_TYPE_STR_LEN+1] = {0};
    std::copy(s1, s1+ECC_TYPE_STR_LEN, s2);
    s2[ECC_TYPE_STR_LEN] = 0;
    ecc.type = AnsiString( (const char*) s2 );

}
//------------------------------------------------------------------------------
}; //namespace ECCFlash
//------------------------------------------------------------------------------
void TestAlchemy1()
{
    const XY f[10] =
    {
        XY(0,0),
        XY(1,1),
        XY(2,4),
        XY(3,9),
        XY(4,16),
        XY(5,25),
        XY(6,36),
        XY(7,49),
        XY(8,64),
        XY(9,81)
    };
    #define PRINT_(nn) MYWCOUT_( "f[%g]=%g\n", nn, \
        MyPiecewiseLinearInterpolation1Value( f, f+10, nn ) ));
    PRINT_( -1.0 );
    PRINT_( 0.0 );
    PRINT_(0.5);
    PRINT_(2.5);
    PRINT_(3.5);
    PRINT_(4.5);
    PRINT_(5.5);

    PRINT_(6.0);
    PRINT_(7.0);
    PRINT_(8.0);

    PRINT_(9.0);
    PRINT_(10.0);
    #undef PRINT_

    #define PRINT_(nn) MYWCOUT_( "MyFRound(%g)=%d\n", nn, MyFRound( nn ) ));
    PRINT_( -1.1 );
    PRINT_( -2.2 );
    PRINT_( 3.3 );
    PRINT_( 3.7 );
    PRINT_( 7.49 );
    PRINT_( 7.51 );
    #undef PRINT_
}
//------------------------------------------------------------------------------

