#ifndef CLLCNTXT_HPP_HEADER_INCLUDED_______
#define CLLCNTXT_HPP_HEADER_INCLUDED_______
//------------------------------------------------------------------------------
namespace AnkatMicro
{
//------------------------------------------------------------------------------
typedef enum {GAZ_O2=0,GAZ_CO,GAZ_NO,GAZ_NO2,GAZ_SO2,GAZ_H2S,GAZ_HCl,GAZ_NH3,GAZ_CL2,GAZ_RSH,GAZ_ERR} GasType;

typedef struct KTableItemTag{
		short K_TM;
		short K_TA;
		} KTableItem;
//------------------------------------------------------------------------------
/* Descriptor of cell in ROM */
typedef struct CellContextTag
{
	unsigned char	kCell;
	unsigned char	kStep;
	unsigned short	kMin;
	unsigned short	kMax;	   	// 4
	short	kiMin;			   	// 6
	short	kiMax;			   	// 8
	unsigned short	kTime;		// 10 time of last calibrate
	unsigned int	kDate;		// 12 date of last calibrate
	unsigned char	kFt;		// --
	unsigned char	kFk;		// --
	unsigned short	kP1;		// 16
	unsigned short	kP2;		// 18
	KTableItem		kTk[20];
	union
    {
        char k_Kchar[16];
        float	k_Kfloat[4];
    } k_Korr;
	unsigned short	k_CRC;
} CellContext;
//------------------------------------------------------------------------------
}; //namespace AnkatMicro
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
