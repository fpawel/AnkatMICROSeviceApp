//---------------------------------------------------------------------------
#ifndef winRS232H
#define winRS232H
//---------------------------------------------------------------------------
//#include <windows.h>
//---------------------------------------------------------------------------
// vcl
#include <system.hpp>

// std
#include <string>
#include <vector>
//---------------------------------------------------------------------------
//#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
//---------------------------------------------------------------------------
#include "CommSets.h"
#include "..\my_include\myport.hpp"

//---------------------------------------------------------------------------
namespace my
{
namespace RS232
{
	// получить описание ошибки ввода-вывода СОМ-порта
	std::string ErrorsMaskToStr( DWORD commErrorsMask );
    
	// содержить ли маска критическую ошибку COM-порта
	bool HasMaskCriticalError( DWORD commErrorsMask );

    // получить дескриптор порта
    void* CreatePortHandle(unsigned idx);

    void SetConfig( void *hComm, const COMMCONFIG& commConfig );
    COMMCONFIG GetConfig( void *hComm  );

    COMMPROP GetProperties(void* hComm);
    void SetTxDRxDBuffsSizes( void* hComm, DWORD txdSize, DWORD rxdSize );

    //--------------------------------------------------------------------------
    // Класс "СОМ-порт"
    //--------------------------------------------------------------------------
    class Port : public MyPort
    {

    public:
    	explicit Port();
        virtual ~Port();
        //----------------------------------------------------------------------
        // управление портом
        //----------------------------------------------------------------------
        // Получить количество байтов в приёмнике.
    	// Если произошла ошибка приёма-передачи, возбудить исключение CommException
    	virtual int GetRxDSize();
    	virtual void Purge();

        virtual AnsiString Description() const;

        virtual void SaveSettingsToIniFile(Inifiles::TIniFile*, const AnsiString& sekt);
        virtual void LoadSettingsFromIniFile(Inifiles::TIniFile*, const AnsiString& sekt);

        void EscapeComm( DWORD dwFunc );

    	const Setings& GetSettings() const;
        void SetSettings(const Setings& sets);
        void SetSettingsDefault();

        AnsiString GetPortName() const;
        void SetPortName(const AnsiString&);

        void SetDCB(const DCB& dcb);
        void SetTimeOuts( const COMMTIMEOUTS& timeOuts );
        void SetBuffsSizes(DWORD txdBuffSize, DWORD rxdBuffSize);

        COMMTIMEOUTS ReciveTimeOuts();
        DCB ReciveDCB();

        	// показать диалог для установки конфигурации порта
        	// hwnd - окно, для которого диалог станет модальным
        	// getFromSystem: если false, инициализировать диалог
        	// текущими установками порта, иначе установками,
        	// полученными с помощью GetCommConfig
        void SetupDialog(HWND hwnd, bool getFromSystem );

        bool IsHandleCreated() const;

    private:
        void* hComm_;
        //unsigned portIdx_;
        AnsiString portName_;
        // установки порта
        Setings sets_;

        bool mustApplyDCB_, mustApplyTimeOuts_, mustApplyBuffsSizes_;

        struct OpenTemporaryHelper
        {
        	void*& hComm_;
            const bool wasOpened_;
        	OpenTemporaryHelper(void*& hComm, const AnsiString& portName);
            ~OpenTemporaryHelper();
        };
        void ApplyBuffsSizes();
        void ApplyDCB();
        void ApplyTimeOuts();

        virtual void Open();
        virtual void Close();
        virtual int PerformWrite( void* pBuff, int count );
    	virtual int PerformRead(  void* pBuff, int count );
    };// Класс "СОМ-порт"
    //--------------------------------------------------------------------------
};// namespace Comm
};//namespace my

#endif
