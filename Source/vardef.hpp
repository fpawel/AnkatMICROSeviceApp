//------------------------------------------------------------------------------
#ifndef DEVICE_CALCULATION_VARIABLE_DEFINITION_HEADER_INCLUDED
#define DEVICE_CALCULATION_VARIABLE_DEFINITION_HEADER_INCLUDED
//------------------------------------------------------------------------------
//std
#include <vector>
#include <utility>
//------------------------------------------------------------------------------
//vcl
#include <system.hpp>
//#include <grids.hpp>
//------------------------------------------------------------------------------
AnsiString ModbusChanalVariable(unsigned code);
AnsiString ModbusChanalUnits(unsigned code);
std::pair<double,double> ModbusChanalScale(unsigned code);






//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------