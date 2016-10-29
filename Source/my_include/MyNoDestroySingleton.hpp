#ifndef MY_NO_DESTROYABLE_SINGLETON_HEADER_INCLUDED_______
#define MY_NO_DESTROYABLE_SINGLETON_HEADER_INCLUDED_______

    template< typename T, typename TagT >
    struct MyNoDestroySingletonHolder
    {
        typedef T ObjectType;
        static T& Instance()
        {
            static ObjectType* pRet = 0;
            if( pRet==0 )
    	        pRet = new ObjectType;
            return *pRet;
        }
    };



#endif