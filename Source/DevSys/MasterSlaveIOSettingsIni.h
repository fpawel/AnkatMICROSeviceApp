//---------------------------------------------------------------------------
#ifndef MasterSlaveIOSettingsIniH
#define MasterSlaveIOSettingsIniH
//---------------------------------------------------------------------------
#include "MasterSlaveIOSettings.hpp"

namespace Inifiles
{
    class TIniFile;
};

void SaveMasterSlaveIOSettingsToFile(const MasterSlaveIOSettings&,
    Inifiles::TIniFile*, const char sektion[]);

void LoadMasterSlaveIOSettingsFromFile(MasterSlaveIOSettings&,
    Inifiles::TIniFile*, const char sektion[]);


#endif
