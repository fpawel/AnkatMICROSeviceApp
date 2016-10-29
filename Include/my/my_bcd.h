#ifndef MY_BCD_H_INCLUDED_
#define MY_BCD_H_INCLUDED_
//---------------------------------------------------------------------------
#include "bin_nums.h"
#include <math.h>
#include <SysUtils.hpp>
#define MAX_BCD4_FLOAT 999999

//---------------------------------------------------------------------------
//ѕреобразование двоично-дес€тичного упакованного числа в вещественное
bool TryBCDToFloat(const byte* const bcd, double& res)
{
	for(int i=1;i<4;++i)
		if ( (bcd[i] & 0xF0)>0xA0 || (bcd[i] & 0x0F)>0x0A )
			return false;
	AnsiString s = IntToHex(bcd[1],2)+IntToHex(bcd[2],2)+IntToHex(bcd[3],2);
	int zap = bcd[0] & 0x0F, sign = bcd[0] & 0xF0;
	if (zap)
		s.Insert('.', 6-zap+1 );
	if (sign == 0x80)
		s.Insert('-',1);
	char * ii;
	res = strtod(s.c_str(),&ii);
	return true;
}
//---------------------------------------------------------------------------
// ”паковать число в BCD
void FloatToBCD(double val, byte* res)
{
	double absVal = val;
	res[0] = 0;
	if (val<0)
	{
			res[0] = 0x80;
			absVal *= -1;
	};
	assert(absVal<MAX_BCD4_FLOAT && "Ќе возможно преобразовать в BCD число, большее чем 999999! ");

	int zap = 0;
	if (val!=0)
	{
		int n = FormatFloat(".000000",absVal).Pos(',');
		zap = 7-n;   //позици€ зап€той
		if (zap<0) zap = 0;
		else
			if (zap>6) zap = 6;
	}
	absVal *= std::pow((double)10,zap);
	AnsiString s = FormatFloat("000000",absVal);
	res[0] += zap;
	res[1] = StrToInt(s[1])*16+StrToInt(s[2]);
	res[2] = StrToInt(s[3])*16+StrToInt(s[4]);
	res[3] = StrToInt(s[5])*16+StrToInt(s[6]);
}
//---------------------------------------------------------------------------






//---------------------------------------------------------------------------
#endif