#ifndef MY_VCL_SIGNALS_HEADER_INCLUDED_____
#define MY_VCL_SIGNALS_HEADER_INCLUDED_____
//---------------------------------------------------------------------------
#include <algorithm>
//#include <list>
#include <vector>
#include <cassert>

#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

namespace my { namespace VCLSignal {

	//--------------------------------------------------------------------------
	template<class F>
    struct FooEql
    {
    	explicit FooEql( F f ) : foo_(f) {}
        bool operator() (F f) const{ return f==foo_; }
        const F foo_;
    };
    //--------------------------------------------------------------------------
    template <class F> struct FooCall
	{
		struct Adpt0
		{
			explicit Adpt0() {}
			void operator()( const F& f ) const
			{	f();	}
		};

		template<class Arg>	struct Adpt1
		{
			const Arg arg_;
			explicit Adpt1( Arg arg ) : arg_(arg) {}
			void operator()( F f ) const
			{
				return f(arg_);
			}
		};
		template<class Arg1, class Arg2> struct Adpt2
		{
			const Arg1 arg1_;
			const Arg2 arg2_;
			explicit Adpt2( Arg1 arg1, Arg2 arg2 ) : arg1_(arg1), arg2_(arg2) {}
			void operator()( F f ) const
			{
				return f(arg1_,arg2_);
			}
		};
		template<class Arg1, class Arg2, class Arg3> struct Adpt3
		{
			const Arg1 arg1_;
			const Arg2 arg2_;
			const Arg3 arg3_;
			explicit Adpt3( Arg1 arg1, Arg2 arg2, Arg3 arg3 ) :	arg1_(arg1),
			arg2_(arg2), arg3_(arg3) {}
			void operator()( F f ) const
			{
				return f(arg1_,arg2_,arg3_);
			}
		};

		template<class Arg1, class Arg2, class Arg3, class Arg4> struct Adpt4
		{
			const Arg1 arg1_;
			const Arg2 arg2_;
			const Arg3 arg3_;
			const Arg4 arg4_;
			explicit Adpt4( Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4 ) :
			arg1_(arg1), arg2_(arg2), arg3_(arg3), arg4_(arg4) {}
			void operator()( F f ) const
			{
				return f(arg1_,arg2_,arg3_, arg4_);
			}
		};
	};
    //--------------------------------------------------------------------------
	template <class F>
	class Signal : public boost::noncopyable
	{
	public:
        // тип подписчика
        typedef typename F Handler;
        //----------------------------------------------------------------------
        class Connections
        {
        public:
        	// список функторов
			typedef std::vector<F> ConnectionsList;

            // колличество соединений
			unsigned long ConnectionsCount() const { return connections_.size(); }
			void DisconnectAll() { connections_.clear(); }
			void Connect(F fun ) { connections_.push_back( fun ); }
			void Disconnect(F fun )
        	{
        		connections_.erase(
                	std::remove_if(connections_.begin(), connections_.end(), FooEql<F>(fun) ),
                    connections_.end()
                    );
        	}
            ConnectionsList GetListCopy() const { return connections_; }

            class Auto : public boost::noncopyable
        	{
        	public:
            	explicit Auto(const Connections& connections, F fun) :
            		connections_(const_cast<Connections&>(connections)), fun_(fun)
            	{ connections_.Connect(fun_); }
            	~Auto()
            	{ connections_.Disconnect(fun_); }
        	private:
        		mutable Connections& connections_;
            	F fun_;
        	};

            boost::shared_ptr<Auto> AutoConnect(F fun)
            { return boost::shared_ptr<Auto>( new Auto(*this, fun) ); }

        private:
        	ConnectionsList connections_;
        };
        //----------------------------------------------------------------------
        Connections& GetConnections() { return connectionsList_; }
        
	private:

		// список функторов
		Connections connectionsList_;
        //----------------------------------------------------------------------
        // отправка сигнала
		template<class Adapt>
		void SetSignal(const Adapt& adpt)
        {
            /*
        	static bool isProceced_ = false;;
			assert( !isProceced_ && "Попытка двукратного вызова Signal::SetSignal!" );
			isProceced_ = true;
            */
            const Connections::ConnectionsList cnctns = connectionsList_.GetListCopy();
            std::for_each(cnctns.begin(), cnctns.end(), adpt);
			//isProceced_ = false;
		}
	public:
        // отправка сигнала
		void Signal0()
        {
        	const FooCall<F>::Adpt0 adpt;
            SetSignal(adpt);
        }
        //----------------------------------------------------------------------
		template<typename Arg> void Signal1(Arg arg)
        {
        	const FooCall<F>::Adpt1<Arg> adpt(arg);
            SetSignal(adpt);
        }
        //----------------------------------------------------------------------
		template<typename Arg1, typename Arg2> void Signal2(Arg1 arg1, Arg2 arg2)
        {
        	const FooCall<F>::Adpt2<Arg1,Arg2> adpt(arg1,arg2);
        	SetSignal(adpt);
        }
        //----------------------------------------------------------------------
		template<typename Arg1, typename Arg2, typename Arg3>
		void Signal3(Arg1 arg1, Arg2 arg2, Arg3 arg3)
        {
        	const FooCall<F>::Adpt3<Arg1,Arg2,Arg3> adpt(arg1,arg2,arg3);
            SetSignal(adpt);
        }
        //----------------------------------------------------------------------
		template<typename Arg1, typename Arg2, typename Arg3, typename Arg4 >
		void Signal4(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4) const
        {
        	const FooCall<F>::Adpt4<Arg1,Arg2,Arg3,Arg4> adpt(arg1,arg2,arg3, arg4);
			SetSignal(adpt);
		}
        //----------------------------------------------------------------------
	}; // class Signal
};//namespace sckt {
};//namespace my {
//---------------------------------------------------------------------------
#endif // #ifndef MY_SOCETS_HPP_INCLUDED_ #define MY_SOCETS_HPP_INCLUDED_
