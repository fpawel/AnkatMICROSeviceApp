//------------------------------------------------------------------------------
#ifndef task_H
#define task_H
//------------------------------------------------------------------------------
//std
#include <deque>

//my
#include "MyAbstructTransfer.hpp"
#include "MyExcpt.hpp"
//------------------------------------------------------------------------------


    class SingleAction : public NamedTransfer
    {
    public:
        explicit SingleAction(const AnsiString& what) : NamedTransfer(what) {}
        virtual ~SingleAction() {}
    private:
        virtual bool HandleBeginTransfer() { return true; }
        virtual bool HandleEndTransfer() { return false; }
    };


    class InitializeDevice : public SingleAction
    {
    public:
        explicit InitializeDevice();
        virtual ~InitializeDevice() {}
    private:
        virtual void Perform();
    };

    class ReadArchiveTask : public SingleAction
    {
    public:
        explicit ReadArchiveTask(bool isHour, TDateTime dtTm1, TDateTime dtTm2);
        virtual ~ReadArchiveTask() {}
    private:
        const TDateTime dtTm1_, dtTm2_;
        const bool isHour_; 
        virtual void Perform();
        
    };


    class FromIndex2IndexTemplate : public SingleAction
    {
    public:
        typedef void (__closure *FooT)(unsigned);

        explicit FromIndex2IndexTemplate(unsigned i0, unsigned i1, FooT foo);
        virtual ~FromIndex2IndexTemplate() {}
    private:
        const unsigned i0_, i1_;
        const FooT foo_;
        virtual void Perform();
    };
    
    class SetDateTimeAction : public SingleAction
    {
    public:
        explicit SetDateTimeAction() : SingleAction("Установка даты и времени") {}
        virtual ~SetDateTimeAction() {}
    private:
        virtual void Perform();
    };




//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------

