//------------------------------------------------------------------------------
#ifndef CommSetsH
#define CommSetsH
//------------------------------------------------------------------------------
#include <windows.h>
//------------------------------------------------------------------------------
#include <utility>
#include <iostream>
#include <vector>
//------------------------------------------------------------------------------
#include <system.hpp>
//------------------------------------------------------------------------------
// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"
//------------------------------------------------------------------------------
namespace my
{
	namespace RS232
	{

    	// размер буфферов ввода/вывода по умолчанию
    	enum { defaultIOBuffSize = 1024 };

        enum {sysCBRScount = 15};
        const unsigned cbrs[sysCBRScount] = { CBR_110, CBR_300, CBR_600,
        	CBR_1200, CBR_2400, CBR_4800, CBR_9600, CBR_14400, CBR_19200,
            CBR_38400, CBR_56000, CBR_57600, CBR_115200, CBR_128000, CBR_256000 };

        const unsigned setblBaudRates[] = { 75, 110, 134, 150, 300, 600, 1200,
        1800, 2400, 4800, 7200, 9600, 14400, 19200, 38400, 56000, 57600, 115200,
        128000 };

        void InitDCB(DCB& dcb);
		void SetDefaultDCB(DCB& dcb);
    	void SetDefaultCommTimeOuts(COMMTIMEOUTS& commTimeOuts);

        const DCB& GetDefaultDCB();
    	const COMMTIMEOUTS& GetDefaultCommTimeOuts();

    	// свойства COM-порта
        struct Setings
    	{
        	DWORD txdBuffSize_, rxdBuffSize_;
        	DCB dcb_;
        	COMMTIMEOUTS timeOuts_;
        	explicit Setings();
    	};

        std::ostream& operator<<( std::ostream& strm, const my::RS232::Setings& sets );

        // информации о портах, предсавленных в системе
    	std::vector<AnsiString> SystemPorts();

        // предсавлен ли порт № idx в системе
    	bool IsPortPresentedInSystem(const AnsiString&);

        // сохранить установки порта idx в дефолтном ini файле
        void SaveSetingsInCustomIni( const AnsiString&, const Setings& srcSets );

        // записать установки порта idx из дефолтного ini файла
    	void LoadSetingsFromCustomIni( const AnsiString&, Setings& dstSets );

        // определить доступные скорости обмена для открытого порта
        void CheckAvaliableBoudRates(void *hComm);
        
	};
};
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
