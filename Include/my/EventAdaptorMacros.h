#ifdef EVENT_PROPERTY_ADAPTOR_MACRO_DEFINED___
	#define DECLARE_EVENT_PROPERTY_ADAPTOR_(name) \
	template<>	struct EventPropertyAdaptor<EventsId::##name> \
	{\
		template<class T> \
		static EventTrait<EventsId::##name>::EventProperty Get(T* ctrl) \
		{ \
			return ctrl->On##name; \
		} \
		template<class T, class P> 	static void Set(T* ctrl, P prop) \
		{ \
			ctrl->On##name = prop; \
		} \
	}; \
	typedef EventPropertyAdaptor<EventsId::##name> On##name##Adaptor;

	DECLARE_EVENT_PROPERTY_ADAPTOR_(Click);
	DECLARE_EVENT_PROPERTY_ADAPTOR_(DblClick);
	DECLARE_EVENT_PROPERTY_ADAPTOR_(SetEditText);
	DECLARE_EVENT_PROPERTY_ADAPTOR_(Popup);

#elif
	#undef DECLARE_EVENT_PROPERTY_ADAPTOR_(name)
#endif
