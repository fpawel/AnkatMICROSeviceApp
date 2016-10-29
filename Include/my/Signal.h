#ifndef MY_SOCETS_HPP_INCLUDED_
#define MY_SOCETS_HPP_INCLUDED_
//---------------------------------------------------------------------------

#include <list>
#include <vector>
#include <cassert>
#include "boost\smart_ptr.hpp"
#include "boost\noncopyable.hpp"

namespace my { namespace PubSub {
	
	template <class F> struct Helper
	{
		typedef std::list<F> List;
		typedef List::iterator Iter;

		struct Adpt0
		{
			explicit Adpt0() {}
			bool operator()( Iter itr )
			{
				return (*itr)();
			}
		};

		template<class Arg>	struct Adpt1
		{
			Arg arg_;
			explicit Adpt1( Arg arg ) : arg_(arg) {}
			bool operator()( Iter itr )
			{
				return (*itr)(arg_);
			}
		};
		template<class Arg1, class Arg2> struct Adpt2
		{
			Arg1 arg1_;
			Arg2 arg2_;
			explicit Adpt2( Arg1 arg1, Arg2 arg2 ) : arg1_(arg1), arg2_(arg2) {}
			bool operator()( Iter itr )
			{
				return (*itr)(arg1_,arg2_);
			}
		};
		template<class Arg1, class Arg2, class Arg3> struct Adpt3
		{
			Arg1 arg1_;
			Arg2 arg2_;
			Arg3 arg3_;
			explicit Adpt3( Arg1 arg1, Arg2 arg2, Arg3 arg3 ) :	arg1_(arg1),
			arg2_(arg2), arg3_(arg3) {}
			bool operator()( Iter itr )
			{
				return (*itr)(arg1_,arg2_,arg3_);
			}
		};

		template<class Arg1, class Arg2, class Arg3, class Arg4> struct Adpt4
		{
			Arg1 arg1_;
			Arg2 arg2_;
			Arg3 arg3_;
			Arg4 arg4_;
			explicit Adpt4( Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4 ) :
			arg1_(arg1), arg2_(arg2), arg3_(arg3), arg4_(arg4) {}
			bool operator()( Iter itr )
			{
				return (*itr)(arg1_,arg2_,arg3_, arg4_);
			}
		};
	};

	template <class F>
	class Signal : public boost::noncopyable
	{
		bool isProceced_;
        // тип, реализующий соединение с сокетом
        class ConnectionImpl;
        // список функторов
		typedef std::list<F> List;
        // итератор списока функторов
		typedef List::iterator Iter;
	public:
        // соединение
		typedef boost::shared_ptr<ConnectionImpl> Connection;
        // тип подписчика
        typedef typename F Handler;
	private:

		// массив соединений
		typedef std::vector<Connection> Connections;
		typedef Connections::iterator ConnectionPtr;
		Connections Connections_;

		// список функторов
		List aList_;

        // отправка сигнала
		template<class Adapt>
		void SetSignal(Adapt& adpt);

	public:

		explicit Signal() : isProceced_(false)
		{
		}

		unsigned long ConnectionsCount() { return aList_.size(); }

		void DisconnectAll();

        // установить соединение
		template<class Fun>	Connection Connect(Fun fun );
		template <class PtrObj, typename MemFn>
		Connection Connect( const PtrObj& p, MemFn memFn );

        // отправка сигнала
		void operator()();

        // отправка сигнала
		template<typename Arg>
		void operator()(Arg arg);

        // отправка сигнала
		template<typename Arg1, typename Arg2>
		void operator()(Arg1 arg1, Arg2 arg2);

        // отправка сигнала
		template<typename Arg1, typename Arg2, typename Arg3>
		void operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3);

        // отправка сигнала
		template<typename Arg1, typename Arg2, typename Arg3, typename Arg4 >
		void operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4);

	};


template <class F>
struct IsDisconnected : public std::unary_function< Signal<F>::Connection, bool>
{
	bool operator()(const Signal<F>::Connection& arg)
	{
		return !arg->Connected();
    }
};

template <class F>
class Signal<F>::ConnectionImpl  : public boost::noncopyable
{
	Helper<F>::Iter iter_;
	bool connected_;
	explicit ConnectionImpl(Iter iter) : iter_(iter), connected_(true) {}
	friend class my::PubSub::Signal;
public:
	bool Connected() const  { return connected_; }
	void Disconnect() { connected_ = false; }
};


// отправка сигнала
template <class F>
template<class Adapt>
void Signal<F>::SetSignal(Adapt& adpt)
{
	assert( !isProceced_ && "Попытка двукратного вызова Signal::SetSignal!" );
	assert( Connections_.size()==aList_.size() );

	isProceced_ = true;
	ConnectionPtr pEnd = Connections_.end(), pBeg = Connections_.begin();
    //pFirstDisconected = std::remove_if(	pBeg, pEnd,	ConnectionImpl::IsDisconected() );

	// цикл по соединениям
	for( ConnectionPtr i = pBeg; i!=pEnd; ++i )
	{
		ConnectionImpl& cnt = *(*i).get();
		try
		{
			if( cnt.connected_ )
			cnt.connected_ = !adpt( cnt.iter_ );
        }
		catch(...) // игнорировать исключения
		{
			cnt.connected_ = false;
        }
		if( !cnt.connected_ )
			aList_.erase(cnt.iter_); // удалить функтор
    }

	// удалить разъединённые соединения
	Connections_.erase
    (
		std::remove_if( Connections_.begin(), Connections_.end(), IsDisconnected<F>() ),
		Connections_.end()
    );
	isProceced_ = false;
}


template <class F>
void Signal<F>::operator()()
{
	Helper<F>::Adpt0 adpt;
	SetSignal(adpt);
}

template <class F>
template<typename Arg>
void Signal<F>::operator()(Arg arg)
{
	Helper<F>::Adpt1<Arg> adpt(arg);
	SetSignal(adpt);
}

template <class F> template<typename Arg1, typename Arg2>
void Signal<F>::operator()(Arg1 arg1, Arg2 arg2)
{
	Helper<F>::Adpt2<Arg1,Arg2> adpt(arg1,arg2);
	SetSignal(adpt);
}

template <class F> template<typename Arg1, typename Arg2, typename Arg3>
void Signal<F>::operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3)
{
	Helper<F>::Adpt3<Arg1,Arg2,Arg3> adpt(arg1,arg2,arg3);
	SetSignal(adpt);
}

template <class F> template<typename Arg1, typename Arg2, typename Arg3, typename Arg4 >
void Signal<F>::operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
{
	Helper<F>::Adpt4<Arg1,Arg2,Arg3,Arg4> adpt(arg1,arg2,arg3, arg4);
	SetSignal(adpt);
}

// разединить все соединения
template <class F>
void Signal<F>::DisconnectAll()
{
	aList_.clear();
	// цикл по соединениям
	ConnectionPtr pEnd = Connections_.end(), i = Connections_.begin();
	for( ; i!=pEnd; ++i )
		( (*i).get() )->Disconnect();
    Connections_.clear();
}


// установить соединение
template <class F> template<class Fun>
Signal<F>::Connection Signal<F>::Connect(Fun fun )
{
	aList_.push_back( F(fun) );
	Iter itr = aList_.end();
	Connection newCnt = Connection( new ConnectionImpl( --itr ) );
	Connections_.push_back(newCnt);
	return newCnt;
}

// установить соединение
template <class F> template <class PtrObj, typename MemFn>
Signal<F>::Connection Signal<F>::Connect( const PtrObj& p, MemFn memFn )
{
	aList_.push_back( F(p, memFn) );
	Iter itr = aList_.end();
	Connection newCnt = Connection( new ConnectionImpl( --itr ) );
	Connections_.push_back(newCnt);
	return newCnt;
}
	// класс-свойство, выводящий типы сокета и соединения
	// на основании типа хэндлера
	template<class H>	struct Trait
	{
		typedef H Handler;
		typedef PubSub::Signal<Handler>::Connection Connection;
		typedef PubSub::Signal<Handler> Signal;
	};


};//namespace sckt {
};//namespace my {
//---------------------------------------------------------------------------
#endif // #ifndef MY_SOCETS_HPP_INCLUDED_ #define MY_SOCETS_HPP_INCLUDED_
