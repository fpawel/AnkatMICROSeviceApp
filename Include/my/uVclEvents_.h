/*
	Модуль для управления событиями компонентов VCL.
	Позволяет подписывать функторы на определённые пользователем
	события определённых компонентов
*/

//---------------------------------------------------------------------------
#ifndef uVclEvents_H
#define uVclEvents_H
//---------------------------------------------------------------------------
#include <map>
//#include "boost\smart_ptr.hpp"
#include "my\MySocets.hpp"
#include "loki\Functor.h"
#include <Controls.hpp>
#include <boost/noncopyable.hpp>
namespace Vcl
{
	// перчисление идентификаторов VCL событий
	namespace EventsId
	{
		enum { Click, DblClick, SetEditText, Popup };
	};

	// Свойство, предназначенное для выведения из типа свойства
	// обработчика  VCL события следующих типов:
	// - пользовательский обработчик-подписчик
	// - сокет VCL события
	// - соединение с сокетом
	template<class PT>	struct VclEventTraits;

	template<> struct VclEventTraits<TNotifyEvent>
	{
		typedef Loki::Functor<bool, TYPELIST_1(	TObject*)> Handler;
		typedef my::sckt::Socket<Handler> Socket;
		typedef Socket::Conection Conection;
	};
	template<> struct VclEventTraits<TSetEditEvent>
	{
		typedef Loki::Functor<bool, TYPELIST_4(	TObject*,
		int, int, const AnsiString)> Handler;
		typedef my::sckt::Socket<Handler> Socket;
		typedef Socket::Conection Conection;
	};

	// список соответствия идентификатора VCL-события типу VCL-свойства
	typedef TYPELIST_4
	(
		TNotifyEvent, 			// Click
		TNotifyEvent, 			// DblClick
		TSetEditEvent,			// SetEditText
		TNotifyEvent 			// Popup
	) UserHandlerTypes;

	// Свойство, предназначенное для выведения из идентификатора VCL события следующих типов:
	// - пользовательский обработчик-подписчик
	// - сокет VCL события
	// - соединение с сокетом
	template<int N>	struct EventTrait
	{
		typedef typename Loki::TL::TypeAtNonStrict<UserHandlerTypes,N>::Result
		EventProperty;
		typedef typename VclEventTraits<EventProperty>::Handler
		Handler;
		typedef my::sckt::Socket<Handler> Socket;
		typedef Socket::Conection Conection;
	};

	// Адаптер для получения свойства VCL события,
	// определяемого идентификатором int N
	template<int N>	struct EventPropertyAdaptor
	{
		template<class T>
		static typename EventTrait<N>::EventProperty Get(T* ctrl);
		template<class T, class P>
		static void Set(T* ctrl, P prop);
	};

	#define EVENT_PROPERTY_ADAPTOR_MACRO_DEFINED___
	#include "EventAdaptorMacros.h"
	#undef DECLARE_EVENT_PROPERTY_ADAPTOR_(name)
	#undef EVENT_PROPERTY_ADAPTOR_MACRO_DEFINED___

	template<class PT>	struct MainHandler;
	template<> class MainHandler<TNotifyEvent> : public boost::noncopyable
	{
		template<int N> friend class MyEvent;
		VclEventTraits<TNotifyEvent>::Socket& sckt_;
		TNotifyEvent original_;
		explicit MainHandler(VclEventTraits<TNotifyEvent>::Socket& sckt,
			const TNotifyEvent orig	) :
			sckt_(sckt), original_(orig)
		{
		}
		void __fastcall OnEvent(TObject* sender)
		{
			if (original_) original_(sender);
			sckt_.Signal(sender);
		}
	};

	template<> class MainHandler<TSetEditEvent> : public boost::noncopyable
	{
		template<int N> friend class MyEvent;
		VclEventTraits<TSetEditEvent>::Socket& sckt_;
		TSetEditEvent original_;
		explicit MainHandler(VclEventTraits<TSetEditEvent>::Socket& sckt,
			const TSetEditEvent orig	) :
			sckt_(sckt), original_(orig)
		{
		}
		void __fastcall OnEvent(TObject* sender, int ACol, int ARow, AnsiString Value)
		{
			if (original_) original_(sender, ACol, ARow, Value);
			sckt_.Signal(sender, ACol, ARow, Value);
		}
	};


	template<int N>
	class MyEvent : public EventTrait<N>, boost::noncopyable
	{
		template<int N>	friend class EventHolder;
		typedef typename EventPropertyAdaptor<N> Adaptor;
		EventTrait<N>::EventProperty original_;
		EventTrait<N>::Socket sckt_;
		typedef typename EventTrait<N>::EventProperty Prop;
		typedef typename EventTrait<N>::Conection Conection;
		typedef typename EventTrait<N>::Handler Handler;
		typename MainHandler< Prop > mainHnd_;

		template<class T>
		explicit MyEvent(T* obj) :
			original_( Adaptor::Get<T>(obj) ),
			mainHnd_(sckt_, original_)
		{
			Adaptor::Set(obj, &mainHnd_.OnEvent );
		}
		Conection Conect(Handler hnd)
		{
			return sckt_.Conect(hnd);
		}
	};

	template<int N>	class EventHolder : public boost::noncopyable
	{
		EventHolder() {}
		typedef typename MyEvent<N>* PEvent;
		typedef typename EventTrait<N>::Conection Conection;
		typedef typename EventTrait<N>::Handler Handler;

		typedef std::map<TObject*,PEvent> Association;
		typedef Association::iterator Iter;

		Association assoc_;

	public:
		static EventHolder& Instance()
		{
			static EventHolder& obj = * new EventHolder;
			return obj;
		}
		template<class T> Conection Conect(T* ctrl, Handler hnd)
		{
			TObject* obj = dynamic_cast<TObject*>(ctrl);
			assert(obj && "EventHolder<N>::Conect<T>(T* ctrl, Handler hnd): ctrl не перобразован в TObject*! " );
			Iter end = assoc_.end(), itr = assoc_.find(obj);
			PEvent pEv;
			if(itr==end)
			{
				pEv = new MyEvent<N>(ctrl);
				std::pair<Iter,bool> ins = assoc_.insert( Association::value_type(obj,pEv) );
				assert( ins.second && "EventHolder<N>::Conect<T>(T* ctrl, Handler hnd): ctrl не вставлен в кару assoc_! " );
				itr = ins.first;
			} else pEv = itr->second;
			return pEv->Conect(hnd);
		}
	};

	template<int N, class T>
	typename EventTrait<N>::Conection Subscribe(T* obj, typename EventTrait<N>::Handler hnd )
	{
		return EventHolder<N>::Instance().Conect<T>(obj,hnd);
	}
};
#define MY_EVENT_HOLDER(name) Vcl::EventHolder<Vcl::EventsId::##name>::Instance()

//---------------------------------------------------------------------------
#endif // #ifndef uVclEvents_H
