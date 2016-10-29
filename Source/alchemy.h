//------------------------------------------------------------------------------
#ifndef alchemyH
#define alchemyH
//------------------------------------------------------------------------------
#include <utility>
#include <system.hpp>
//------------------------------------------------------------------------------
typedef std::pair<double,double> XY;
//------------------------------------------------------------------------------
enum
    {
        t_40, t_20, t0, t20, t30, t40, t45, t50
    };
//------------------------------------------------------------------------------
const XY def_T_F[8] =
{
    XY(-40, 0),
    XY(-20, 0),
    XY(  0, 0),
    XY( 20, 0),
    XY( 30, 0),
    XY( 40, 0),
    XY( 45, 0),
    XY( 50, 0)
};
//------------------------------------------------------------------------------
double MyPiecewiseLinearInterpolation1Value( const XY* tbl, const XY* tblEnd, double x );
int MyFRound(double number);
//------------------------------------------------------------------------------
void  MakeIbgSrcTbl2( double I20, double I50, XY *f );
void  MakeIbgSrcTbl3( double I_20, double I20, double I50, XY* f );
void  MakeKsnsSrcTbl2( double K20, double K50, XY *f );
void  MakeKsnsSrcTbl3( double K_20, double K20, double K50, XY *f );
//------------------------------------------------------------------------------
struct ECCInfo
{
    double number, scale_min, scale_max;
    TDateTime manufactureDate;
    unsigned gas, units;
    AnsiString type;
};
//------------------------------------------------------------------------------
namespace ECCFlash
{
    void AddIbg( const XY T_Ibg[], unsigned char* buff);
    void AddKsns( const XY T_Ibg[], unsigned char* buff);
    void AddSource( const XY T_Ibg[], const XY T_Ksns[], unsigned char* buff);
    void AddECCInfo(const ECCInfo& ecc, unsigned char* buff);
    int ExtractIbg( int T, const unsigned char* buff );
    int ExtractKsns( int T, const unsigned char* buff );
    void ExtractIbgKsnsSource( const unsigned char *buff, XY *T_Ibg, XY *T_Ksns );
    void ExtractECCInfo(ECCInfo& ecc, unsigned char* buff);

}; //namespace ECCFlash
//------------------------------------------------------------------------------
void TestAlchemy1();
//------------------------------------------------------------------------------

#endif
