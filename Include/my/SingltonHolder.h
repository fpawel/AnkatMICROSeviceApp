#include <assert.h>
#include <algorithm>
//---------------------------------------------------------------------------

#ifndef SingltonHolderH
#define SingltonHolderH





namespace Private
{
	template <typename T>
	struct Deleter
	{
		static void Delete(T* pObj) { delete pObj; }
	};

    class LifetimeTracker
    {
    public:
        LifetimeTracker( unsigned int x):longevity_(x) {}
        virtual ~LifetimeTracker() = 0;            
		friend inline bool Compare( unsigned int longevity, const LifetimeTracker* p)
        { return p->longevity_ < longevity; }
	private:
        unsigned int longevity_;
    };
    inline LifetimeTracker::~LifetimeTracker() {}
	

    template <typename T>
    class ConcreteLifetimeTracker : public LifetimeTracker
    {
    public:
        ConcreteLifetimeTracker(T* p, unsigned int longevity):
             LifetimeTracker(longevity),
             pTracked_(p)
        {}
        ~ConcreteLifetimeTracker() { delete pTracked_; }
    private:
        T* pTracked_;
    };

    typedef LifetimeTracker** TrackerArray;
    extern TrackerArray pTrackerArray;
    extern unsigned int elements;
    const size_t oneElement = sizeof(LifetimeTracker*);




    static void AtExitFn()
    {
        assert(elements > 0 && pTrackerArray !=0 );
        //выбираем вершину стека
        LifetimeTracker* pTop = pTrackerArray[elements - 1];
        //удаляем этот объект из стека
        --elements;
        pTrackerArray = (TrackerArray) std::realloc(pTrackerArray, elements * oneElement);
        delete pTop;
    }
}

//Получает ссылку на объект любого типа и целочисленное значение - продолжительность жизни
template <typename T>
void SetLongevity(T* pDynObject, unsigned int longevity )
{
	using namespace Private;
	using namespace std;

	TrackerArray pNewArray = static_cast<TrackerArray>
    (
       std::realloc(pTrackerArray, (elements+1) * oneElement )
    );

	if (!pNewArray) throw std::bad_alloc();
    LifetimeTracker* p = new ConcreteLifetimeTracker<T>(pDynObject, longevity);
    pTrackerArray = pNewArray;
	//TrackerArray pos;
    TrackerArray pos = upper_bound( pTrackerArray,
		                            pTrackerArray + elements,
								    longevity,
								    Compare);
    copy_backward( pos, pTrackerArray + elements, pTrackerArray + elements +1);
    *pos = p;
    ++elements;
    std::atexit(AtExitFn);
}
/*
					В файле реализации:

//Обявления статических переменных из файла my\SingltonHolder.h
Private::TrackerArray Private::pTrackerArray = NULL;
unsigned int Private::elements = 0;

*/


//---------------------------------------------------------------------------
#endif
