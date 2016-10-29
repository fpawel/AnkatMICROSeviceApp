//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <windows.h>
//---------------------------------------------------------------------------
//#include <vector>
//#include <cassert>
//#include <stdexcept>

#pragma hdrstop
//---------------------------------------------------------------------------

//loki
#include "Loki\threads.h"

#include "myThread.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace my
{
	using boost::shared_ptr;

    //------------------------------------------------------------------------//
    // Наследник TTread. Принимает в конструкторе и запоминает адрес своей
    // потоковой продцедуры
    //------------------------------------------------------------------------//
    class TMyVCLThread : public TThread
    {
    	// тип потоковой подцедуры для TThread
    	typedef void __fastcall (__closure *TThreadProcedure)(void);

    	const TThreadProcedure proc_;
        virtual void __fastcall Execute(void)
        {
        	proc_();
        }
    public:
    	TMyVCLThread(TThreadProcedure proc) : TThread(true), proc_(proc)
        {
        }
    };


    class MyThreadState : public boost::noncopyable
    {
    private:
    	typedef Loki::ObjectLevelLockable<MyThreadState> GuardThis;
    #define GUARD_THIS_ const GuardThis::Lock guard(guard_);
    public:
    	explicit MyThreadState() :
        	guard_(),
        	terminated_(true), stoped_(true)
        {
        }
    	void SetTerminated(bool val) const
        {
        	GUARD_THIS_;
            terminated_ = val;
        }
        void SetTerminatedStoped(bool terminated, bool stoped) const
        {
        	GUARD_THIS_;
            terminated_ = terminated;
            stoped_= stoped;
        }
        bool GetTerminated() const
        {
        	GUARD_THIS_;
            return terminated_;
        }
        bool GetStoped() const
        {
        	GUARD_THIS_;
            return stoped_;
        }
    #undef GUARD_THIS_
    private:
    	const GuardThis guard_;
    	mutable bool terminated_, stoped_;
    };


    //------------------------------------------------------------------------//
    // Определени реализации класса my::Thread
    //------------------------------------------------------------------------//
    //				Реализация содержит:
    //		- данные для вызова WIN API функций управления потоками;
    //		- потоковую продцедуру, общую для всех потоков ( статический метод );
    //		- потоковый функтор
    //    	- функтор, работающий при остановке потока
    //------------------------------------------------------------------------//
	class Thread::Impl : public boost::noncopyable
    {
    public:
    	explicit Impl( ThreadProcedureT threadProcedure, TThreadPriority priority ) :
        	threadProcedure_(threadProcedure),
            my_thr_(), state_(), priority_( priority )
        {

        }
        // Деструктор реализации
        ~Impl()
        {
        	
            if(WasStoped()) return;
            Kill();
        }
        void WaitFor()
        {
            if( my_thr_ ) my_thr_->WaitFor();
        }
        //--------------------------------------------------------------------//
        void SetPriority(TThreadPriority tp)
    	{
        	priority_ = tp;
            if( my_thr_ ) my_thr_->Priority = priority_;
    	}
        //--------------------------------------------------------------------//
        TThreadPriority GetPriority() const { return priority_; }
        //--------------------------------------------------------------------//
        bool WasStoped()const { return state_.GetStoped() ; }
        bool IsTerminated()const { return state_.GetTerminated(); }
        //--------------------------------------------------------------------//
        // прерывание потока
        void Stop()
    	{
        	if( state_.GetStoped() ) return;
        	state_.SetTerminated(true);
            my_thr_->WaitFor();
        }
        //--------------------------------------------------------------------//
        void Kill()
        {   
        	// прерывание потока
            DWORD dEC = 0;
			GetExitCodeThread((void*)my_thr_->Handle, &dEC);
			TerminateThread( (void*)my_thr_->Handle, dEC	);
            // остановка потока
            my_thr_->Terminate();
    		my_thr_->WaitFor();
    		my_thr_.reset();
        }
        //--------------------------------------------------------------------//
		void Terminate()
		{   
			if( state_.GetStoped() ) return;
			Kill();
            state_.SetTerminatedStoped(true,true);
		}
        //--------------------------------------------------------------------//
        // Запустить поток
    	void Run()
		{
            if( !state_.GetStoped() ) return;
            assert( state_.GetTerminated() );
            // создать работающий поток
            my_thr_.reset( new TMyVCLThread( &this->MyThreadProc ) );
            my_thr_->Priority = priority_;
            my_thr_->Resume();

		}
    	//--------------------------------------------------------------------//
        // Потоковая продцедура
        void __fastcall MyThreadProc()
    	{
        	state_.SetTerminatedStoped(false,false);
            assert(my_thr_);
            try
            {
            	threadProcedure_();
            }
            catch(...)
            {
            // игнорировать исключения в threadFoo_()
            }
            state_.SetTerminatedStoped(true,true);
    	}

    private:
        const ThreadProcedureT threadProcedure_;
		boost::shared_ptr<TMyVCLThread> my_thr_;
        MyThreadState state_;
        TThreadPriority priority_;
    };

    //------------------------------------------------------------------------//
    // Конструктор интерфейсного класса my::Thread
    Thread::Thread( ThreadProcedureT threadProcedure, TThreadPriority priority ):
    	impl_( new Thread::Impl(threadProcedure, priority)  )
    {
    }
    //------------------------------------------------------------------------//
    Thread::~Thread()
    {   
    }
    //------------------------------------------------------------------------//
    void Thread::Run()
    {
    	if( !WasStoped() ) return;
    	impl_->Run();
    }
    //------------------------------------------------------------------------//
    void Thread::Stop()
    {
    	impl_->Stop();
    }
    //------------------------------------------------------------------------//
    #ifdef USE_MY_THREAD_TERMINATE__
    void Thread::Terminate()
    {
    	impl_->Terminate();
    }
    #endif
    //------------------------------------------------------------------------//
    bool Thread::WasStoped()const { return impl_->WasStoped(); }
    //------------------------------------------------------------------------//
    bool Thread::IsTerminated() const { return impl_->IsTerminated(); }
    //------------------------------------------------------------------------//
    void Thread::SetPriority(TThreadPriority tp)
    {
    	impl_->SetPriority(tp);
    }
    //------------------------------------------------------------------------//
    TThreadPriority Thread::GetPriority() const
    {
    	return impl_->GetPriority();
    }

    void Thread::WaitFor()
    {
        impl_->WaitFor();
    }






};// namespace my
