//---------------------------------------------------------------------------
#ifndef TaskListH
#define TaskListH
//---------------------------------------------------------------------------

//std
#include <vector>
#include <list>
#include <algorithm>


// my
#include "MyAbstructTransfer.hpp"

// windows
#include <basetsd.h>

template<class T> struct CheckPTransferClass
{
    bool operator()(const PTransfer& task) const
    {
        return dynamic_cast<T*>( task.get() )!=NULL;
    }
};

struct CheckPTransferAsAddress
{
	explicit CheckPTransferAsAddress(const void *address) : address_(address)
    {}
    bool operator()(const PTransfer& task) const
    {
        return task.get()==address_;
    }
    const void *address_;
};

class TaskList : public boost::noncopyable
{
public:
	explicit TaskList();
    ScenaryList GetList() const;
    void SetList( const ScenaryList& );
    void PushBackTail( PTransfer task );
    void PushFrontHead( PTransfer task );
    void PopFrontBody();
    void PushBackBody( PTransfer task );
    PTransfer FrontBody() const;
    LRESULT Merge();
    void DebugEdit();

    void Print() const;

    void Clear();

    #define ERASE_IN_LIST_(nn) nn.erase( std::remove_if(nn.begin(), nn.end(), pred ), nn.end() )
    #define  ERASE_IN_LISTs_ ERASE_IN_LIST_(body_); ERASE_IN_LIST_(head_); ERASE_IN_LIST_(tail_);
    template<class T> void EraseTasksOfClass()
    {
        const CheckPTransferClass<T> pred;
        ERASE_IN_LISTs_;
    }

    void EraseTask( const MyAbstructTransfer* p )
    {
        const CheckPTransferAsAddress pred(p);
        ERASE_IN_LISTs_;
    }
     #undef ERASE_IN_LIST_(nn)
     #undef ERASE_IN_LISTs_

    template<class T> unsigned CountTasksOfClass() const
    {
        const CheckPTransferClass<T> pred;
        unsigned ret = 0;

        #define INC_RET_WIRH_LIST_(nn) ret += std::count_if(nn.begin(), nn.end(), pred )
        INC_RET_WIRH_LIST_( body_);
        INC_RET_WIRH_LIST_( head_);
        INC_RET_WIRH_LIST_( tail_);
        #undef INC_RET_WIRH_LIST_(nn)
        return ret;
    }

    const bool IsEmpty() const
    {
    	return body_.empty() &&  head_.empty() && tail_.empty();
    }


    const MyAbstructTransfer* GetCurrentTask() const;

    int GetScenaryTaskIndex( const MyAbstructTransfer *task ) const;
    int GetCurrentTaskIndex( ) const;

private:
	typedef std::list<PTransfer> ListT;
    typedef ListT::iterator IterT;
    typedef ListT::const_iterator CIterT;

    ListT body_, head_, tail_;
    const DWORD mainFormThreadId_;

};

int GetScenaryTaskIndex( const ScenaryList& lst, const MyAbstructTransfer *task );





#endif
//---------------------------------------------------------------------------
