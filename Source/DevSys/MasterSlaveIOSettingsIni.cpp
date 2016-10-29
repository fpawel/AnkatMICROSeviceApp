//---------------------------------------------------------------------------


#pragma hdrstop

#include "MasterSlaveIOSettingsIni.h"

#include <inifiles.hpp>

//---------------------------------------------------------------------------

#pragma package(smart_init)

//------------------------------------------------------------------------------

#define WRITE_DELAY_ID "��������_������_����"
#define TIME_OUT_ID "�������_��������_������_����"
#define TRANSFER_REPEAT_COUNT "����������_��������_�������"
#define RXD_FRAME_SILENT_TIME "������������_��������_�������_�����_����"
#define MUST_I_LOG_COMPORT_DATA "������"

void LoadMasterSlaveIOSettingsFromFile(MasterSlaveIOSettings& sets_,
    Inifiles::TIniFile* ini_, const char sekt_[])
{
    //port_->LoadSettingsFromIniFile(ini_, sekt_);
    sets_.tmWriteDelay_ = ini_->ReadInteger(sekt_, WRITE_DELAY_ID, 50);
    sets_.timeOut_      = ini_->ReadInteger(sekt_, TIME_OUT_ID, 1000);
    sets_.silentTime_   = ini_->ReadInteger(sekt_, RXD_FRAME_SILENT_TIME, 10);
    sets_.repeatCount_  = ini_->ReadInteger(sekt_, TRANSFER_REPEAT_COUNT, 0);
    sets_.mustLogData_  = ini_->ReadBool(sekt_, MUST_I_LOG_COMPORT_DATA, false);
}
//------------------------------------------------------------------------------
void SaveMasterSlaveIOSettingsToFile(const MasterSlaveIOSettings& sets_,
    Inifiles::TIniFile* ini_, const char sekt_[])
{
    //port_->SaveSettingsToIniFile(ini_, sekt_);
    ini_->WriteInteger( sekt_, TIME_OUT_ID, sets_.timeOut_ );
    ini_->WriteInteger( sekt_, RXD_FRAME_SILENT_TIME, sets_.silentTime_ );
    ini_->WriteInteger( sekt_, WRITE_DELAY_ID, sets_.tmWriteDelay_ );
    ini_->WriteBool( sekt_, MUST_I_LOG_COMPORT_DATA, sets_.mustLogData_ );
	ini_->WriteInteger( sekt_, TRANSFER_REPEAT_COUNT,  sets_.repeatCount_ );
}