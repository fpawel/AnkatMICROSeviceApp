//------------------------------------------------------------------------------
#ifndef MY_ABSTRUCT_COMMUNICATION_PORT_HEADER_INCLUDED__________
#define MY_ABSTRUCT_COMMUNICATION_PORT_HEADER_INCLUDED__________
//------------------------------------------------------------------------------
#include <system.hpp>
#include "boost\noncopyable.hpp"
//------------------------------------------------------------------------------
    namespace Inifiles
    {
        class TIniFile;
    };

	// интерфейс для канала приёмопередачи
	class MyPort : public boost::noncopyable
	{
    typedef void (__closure *TNotifyChange)(unsigned, const MyPort&, const void*, int);
	public:
        enum {stConnect, stDisconnect, stWrite, stRead};

        explicit MyPort() : isConnected_(0), notifyChange_(NULL)
        {}

        virtual ~MyPort() {}

		virtual AnsiString Description() const = 0;
        
        virtual bool ConnectionWasBreaked() const { return false; }

        void Connect()
        {
            Open();
            isConnected_ = 1;
            if(notifyChange_) notifyChange_(stConnect, *this, NULL, 0);
        }
        void Disconnect()
        {
            Close();
            isConnected_ = 0;
            if(notifyChange_) notifyChange_(stDisconnect, *this, NULL, 0);
        }

        int Write(void* p, int n)
        {
            const int ret = PerformWrite(p, n);
            if(notifyChange_) notifyChange_(stWrite, *this, p, ret);
			return ret;
        }

		int Read(void* p, int n)
        {
            const int ret = PerformRead(p, n);
            if(notifyChange_) notifyChange_(stRead, *this, p, ret);
			return ret;
        }



        bool IsConnected() const { return isConnected_; }
        void SetNotifyChange(TNotifyChange notifyChange) { notifyChange_ = notifyChange; }

        virtual void SaveSettingsToIniFile(Inifiles::TIniFile*, const AnsiString& sekt) {}
        virtual void LoadSettingsFromIniFile(Inifiles::TIniFile*, const AnsiString& sekt) {}



		virtual int GetRxDSize() = 0;
		virtual void Purge() = 0;
    private:
        bool isConnected_;
        TNotifyChange notifyChange_;
        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual int PerformWrite(void*, int) = 0;
		virtual int PerformRead(void*, int) = 0;

	};



#endif
