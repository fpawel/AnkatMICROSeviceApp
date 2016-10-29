//---------------------------------------------------------------------------
#ifndef myThreadH
#define myThreadH

//---------------------------------------------------------------------------
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
//---------------------------------------------------------------------------

//vcl
#include <Classes.hpp>

#define USE_MY_THREAD_TERMINATE__

namespace my
{
    typedef void __fastcall (__closure *ThreadProcedureT )();

	class Thread : public boost::noncopyable
    {   
    	class Impl;
    	boost::shared_ptr <Impl> impl_;
        
    public:
    	explicit Thread( ThreadProcedureT, TThreadPriority priority = tpNormal);
        ~Thread();        

    	void Run();
        void Stop();

        bool WasStoped() const;
        bool IsTerminated() const;

        void SetPriority(TThreadPriority);
        TThreadPriority GetPriority() const;
        
        void Terminate();
        void WaitFor();
    };


};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
