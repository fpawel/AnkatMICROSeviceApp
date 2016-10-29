//---------------------------------------------------------------------------
#ifndef uMyStaticThreadH
#define uMyStaticThreadH
//---------------------------------------------------------------------------

#include "boost\smart_ptr.hpp"
#include <boost/noncopyable.hpp>
#include <Loki\Functor.h>
#include "MySocets.hpp"
//---------------------------------------------------------------------------


namespace my
{
	using boost::shared_ptr;
	namespace Thr
	{
		typedef Loki::Functor<void, TYPELIST_1(bool&) > Proc;
	};


	template <int N, class AFunctor> DWORD WINAPI ThreadProc(LPVOID);

	template <int N, class AFunctor> class StaticThread : public boost::noncopyable
	{
		friend DWORD WINAPI ThreadProc<N,AFunctor>(LPVOID pHnd);

		StaticThread(const StaticThread&);
		StaticThread& operator=(const StaticThread&);

		shared_ptr<SECURITY_ATTRIBUTES> sA_;
		shared_ptr<DWORD> notUsed1_;
		HANDLE hnd_;
		bool terminated_;

		my::sckt::Socket<AFunctor> socket_;


		StaticThread() : terminated_(true)
		{
			int a = 0;
		}
	public:
		~StaticThread()
		{
			Stop();
		}

		static StaticThread& Instance()
		{
			static StaticThread obj;
			return obj;
		}

		void Run()
		{
			if( !terminated_ ) return;
			sA_ = shared_ptr<SECURITY_ATTRIBUTES>(new SECURITY_ATTRIBUTES);
			notUsed1_ = shared_ptr<DWORD>(new DWORD) ;
			terminated_ = false;

			sA_->bInheritHandle = true;
			sA_->lpSecurityDescriptor = NULL;
			sA_->nLength = sizeof(sA_);

			hnd_ = CreateThread(sA_.get(), 0, ThreadProc<N,AFunctor>, NULL, 0,
			notUsed1_.get() );
		}
		void Stop()
		{
			terminated_ = true;
			DWORD dEC = 0;
			GetExitCodeThread(hnd_, &dEC);
			TerminateThread(hnd_,dEC	);
		}

		void UnsubscribeAll()
		{
			//Stop();
			socket_.DisconectAll();
		}


		bool Terminated() { return terminated_; }

		my::sckt::Socket<AFunctor>::Conection Subscribe(AFunctor proc)
		{
			return socket_.Conect(proc);
		}

		void WaitForEnd( unsigned milliseconds = INFINITE )
		{
			while( WaitForSingleObject(hnd_,milliseconds)!=WAIT_OBJECT_0) ;
        }

	};

	template <int N, class AFunctor> DWORD WINAPI ThreadProc(LPVOID)
	{
		//const int n = N;
		StaticThread<N,AFunctor>& thr = StaticThread<N,AFunctor>::Instance();
		while(!thr.terminated_)
		{
			if( !thr.socket_.ConectionsCount() )
				thr.terminated_ = true;
			else
				thr.socket_.Signal();
		}
		return 0;
	}


};
//---------------------------------------------------------------------------
#endif
