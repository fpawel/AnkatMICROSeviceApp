//---------------------------------------------------------------------------
#ifndef modbus_H
#define modbus_H
//---------------------------------------------------------------------------
#include "..\my_include\free_types_.h"
class ModbusAdapter;

/**
*		Базовый класс для исключений модуля
*/
class MyAP430ModbusException;

/**
*		Записать 4 байта
*		throw PMyAP430ModbusException
*/
void WriteModbus4Bytes(  ModbusAdapter&, unsigned slave, unsigned cmd, const unsigned char* dt );
/**
*		Записать число
*/
void WriteModbusFloat(  ModbusAdapter&, unsigned slave, unsigned cmd, double val );
void WriteBPS21M( ModbusAdapter& protocol, unsigned slave, unsigned nDevice,
    unsigned cmdCode, bool high1_low0, double val );




/**
*		Считать массив вщественных чисел
*		throw PMyAP430ModbusException
*/
double ReadModbusFloat(  ModbusAdapter&, const unsigned slave, unsigned regAddr );
double ReadModbusFloat(  ModbusAdapter& protocol, const unsigned slave, unsigned regAddr );

struct ModbusValue1T
{
    double conc;
    bool porog1, porog2;
};
ModbusValue1T ReadModbusValue1(  ModbusAdapter& protocol, const unsigned slave, unsigned regAddr );


void ReadModbusRegistersData(  ModbusAdapter&, unsigned addy, unsigned regNum, unsigned regCount );
unsigned ReadModbusUnsigned(ModbusAdapter& protocol, unsigned addy, unsigned regNum);

void WriteCoef(ModbusAdapter& modbus, unsigned addy, unsigned coefNum, double value);

double ReadKef(ModbusAdapter& modbus, unsigned addy, unsigned coefNum);

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
