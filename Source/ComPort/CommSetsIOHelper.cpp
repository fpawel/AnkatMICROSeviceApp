//---------------------------------------------------------------------------

#include <windows.h>
#include <winspool.h>
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
// my
#include "CommSetsIOHelper.h"
#include "MyDCBHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
namespace my
{
namespace RS232
{
    //---------------------------------------------------------------------------
    // им€ файла
	const char* const iniFileName = "MyCommPortsSetings.ini";
    //---------------------------------------------------------------------------
    void SaveSetings( const Setings& srcSets, TCustomIniFile* pIni,
    	const AnsiString& sktName )
    {
        const AnsiString sekt( sktName );
#define WRITE_INI(id,val) pIni->WriteString(sekt, id, AnsiString().sprintf("%u",val) );
        for( unsigned idx=0; idx<DCB_FIELDS_COUNT; ++idx )
        {
        	const DWORD val = GetDCBField(srcSets.dcb_, idx);
            WRITE_INI(GetDCBFieldName(idx), val);
        }
#define SAVE_TIME_OUT_FIELD(name) WRITE_INI( ""#name, srcSets.timeOuts_.##name )
        SAVE_TIME_OUT_FIELD(ReadIntervalTimeout);
        SAVE_TIME_OUT_FIELD(ReadTotalTimeoutMultiplier);
        SAVE_TIME_OUT_FIELD(ReadTotalTimeoutConstant);
        SAVE_TIME_OUT_FIELD(WriteTotalTimeoutMultiplier);
        SAVE_TIME_OUT_FIELD(WriteTotalTimeoutConstant);
#undef SAVE_TIME_OUT_FIELD(name)
		WRITE_INI("txdBuffSize", srcSets.txdBuffSize_ );
        WRITE_INI("rxdBuffSize", srcSets.rxdBuffSize_ );
#undef WRITE_INI(id,val)
    }
    void LoadSetings( Setings& dstSets, TCustomIniFile* pIni, const AnsiString& sktName )
    {
        const AnsiString sekt( sktName );
        const DCB defDcb = GetDefaultDCB();
        const COMMTIMEOUTS defTimeOuts = GetDefaultCommTimeOuts();

        for( unsigned idx=0; idx<DCB_FIELDS_COUNT; ++idx )
        SetDCBField
        (
        	pIni->ReadInteger( sekt, GetDCBFieldName(idx),GetDCBField(defDcb, idx)),
            dstSets.dcb_,idx
        );
#define SET_TIME_OUT_FIELD(name) dstSets.timeOuts_.##name=pIni->ReadInteger(sekt,""#name, defTimeOuts.##name )
		SET_TIME_OUT_FIELD(ReadIntervalTimeout);
        SET_TIME_OUT_FIELD(ReadTotalTimeoutMultiplier);
        SET_TIME_OUT_FIELD(ReadTotalTimeoutConstant);
        SET_TIME_OUT_FIELD(WriteTotalTimeoutMultiplier);
        SET_TIME_OUT_FIELD(WriteTotalTimeoutConstant);
#undef SET_TIME_OUT_FIELD(name)
		dstSets.txdBuffSize_ = pIni->ReadInteger(sekt, "txdBuffSize", defaultIOBuffSize );
        dstSets.rxdBuffSize_ = pIni->ReadInteger(sekt, "rxdBuffSize", defaultIOBuffSize );
    }
    //---------------------------------------------------------------------------

    // сохранить установки порта idx в дефолтном ini файле
    // объ€вление в CommSets.h
    void SaveSetingsInCustomIni( const AnsiString& portName, const Setings& srcSets )
    {
        if( portName.IsEmpty() ) return;
    	// открытый ини-файл дл€ записи/считывани€ установок
    	boost::shared_ptr<TIniFile> defIniFile(new TIniFile(iniFileName) ) ;
    	SaveSetings( srcSets, defIniFile.get(), portName.c_str() );
    }
    //---------------------------------------------------------------------------
    // записать установки порта idx из дефолтного ini файла
    // объ€вление в CommSets.h
    void LoadSetingsFromCustomIni( const AnsiString& portName, Setings& dstSets )
    {
        if( portName.IsEmpty() ) return;
    	// открытый ини-файл дл€ записи/считывани€ установок
    	boost::shared_ptr<TIniFile> defIniFile(new TIniFile(iniFileName)) ;
    	LoadSetings( dstSets, defIniFile.get(), portName.c_str() );
    }
};
};
