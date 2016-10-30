//------------------------------------------------------------------------------
#ifndef AmcrArchH
#define AmcrArchH
//------------------------------------------------------------------------------

#include "amcr.h"
#include "..\my_include\MyNoDestroySingleton.hpp"

#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

#include "..\VCLUtils\VCLSignal.h"


#include <vector>


AnsiString FormatDateTimeRange( TDateTime dateTime1, TDateTime dateTime2 );

namespace AnkatMicro
{
//------------------------------------------------------------------------------
    typedef void (__closure *NotifyGetArchItemFooT)( const ArchItem& );
    typedef my::VCLSignal::Signal<NotifyGetArchItemFooT> NotifyGetArchItemSignalT;


    class ArchiveImpl : public boost::noncopyable
    {

    public:
        virtual ~ArchiveImpl() {}
        virtual AnsiString What() const = 0;

        void SetHandle(unsigned handle);

        void ReadItem(unsigned idx);

        const ArchItem& GetItem(unsigned idx) const { return arch_.at(idx); }

        std::pair<unsigned,unsigned> FindDateTime(TDateTime dateTime1, TDateTime dateTime2);

        boost::shared_ptr<void> ConnectOnGetArchItem( NotifyGetArchItemFooT);

        virtual unsigned IncIdx(unsigned idx, unsigned count ) const = 0;
        virtual unsigned MaxLen() const = 0;

        std::vector<ArchItem> arch_;
        unsigned idxEnd_, idx0_;
        const ArchItem& GetItemByIndex(unsigned idx );
        
    private:

        NotifyGetArchItemSignalT signalGetArchItem_;

        void Clear();
        void InitializeIndexes(unsigned addy);

        unsigned FindDateTimeMidle(unsigned i0, unsigned i1, TDateTime dateTime1, TDateTime dateTime2);



        LRESULT SetSignalGetArchItem1(const ArchItem&);
        void SetSignalGetArchItem(const ArchItem&);

        virtual unsigned Addy2RecordIndex(unsigned addy) const = 0;
        virtual unsigned RecordIndex2Addy(unsigned addy) const = 0;

        virtual bool IsValidAddy(unsigned addy) const = 0;
        virtual void GetItemFromHard( unsigned addy, ArchItem& ret) const = 0;
    };


    template<class FlashArray>
    class ConcreteArchiveImpl : public ArchiveImpl
    {
    private:
        virtual unsigned MaxLen() const
        {
            return FlashArray::Len;
        }
        virtual unsigned Addy2RecordIndex(unsigned addy) const
        {
            return FlashArray::Addy2RecordIndex(addy);
        }
        virtual unsigned RecordIndex2Addy(unsigned addy) const
        {
            return FlashArray::RecordIndex2Addy(addy);
        }

        virtual unsigned IncIdx(unsigned idx, unsigned count ) const
        {
            return FlashArray::IncIdx(idx, count );
        }

        virtual bool IsValidAddy(unsigned addy) const
        {
            return FlashArray::IsValidAddy(addy);
        }

        virtual void GetItemFromHard( unsigned addy, ArchItem& ret) const
        {
            FlashArray::GetItem(addy, ret);
        }

        virtual AnsiString What() const { return What_(); }

        AnsiString What_() const;

    };
    //--------------------------------------------------------------------------
    typedef ConcreteArchiveImpl<Flash::Hour> HourArchImpl;
    typedef ConcreteArchiveImpl<Flash::Minute> MinuteArchImpl;
    //--------------------------------------------------------------------------
    template<> AnsiString HourArchImpl::What_() const
    {
        return "Часовой архив";
    }
    template<> AnsiString MinuteArchImpl::What_() const
    {
        return "Минутный архив";
    }
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    struct HourArchTag {}; struct MinuteArchTag {};
    //--------------------------------------------------------------------------
    typedef MyNoDestroySingletonHolder<HourArchImpl, HourArchTag> HourArch;
    typedef MyNoDestroySingletonHolder<MinuteArchImpl, MinuteArchTag> MinuteArch;
    //--------------------------------------------------------------------------

//------------------------------------------------------------------------------
}; //namespace AnkatMicro
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
