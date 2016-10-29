//---------------------------------------------------------------------------


#pragma hdrstop

#include "TaskList.h"

//vcl
#include <dialogs.hpp>

//my
#include "myformat.hpp"
#include "guicon.h"
#include "AnsiStringUtils_.h"

//------------------------------------------------------------------------------

#pragma package(smart_init)

//------------------------------------------------------------------------------
TaskList::TaskList() : mainFormThreadId_( GetCurrentThreadId() )
{}
//------------------------------------------------------------------------------
void TaskList::DebugEdit()
{
	// получить итераторы списка
    std::vector<IterT> itrs;
    {
    IterT i = body_.begin();
    for( ++i; i!=body_.end(); ++i ) itrs.push_back(i);
    }
    const unsigned sz = itrs.size();
    if( sz==0 ) return;
    AnsiString s;
    for( unsigned i = 0; i<sz; ++i )
    	s = s + AnsiString().sprintf("%d. %s\n", i+1, (*itrs[i])->What() );
    AnsiString num;
    if( !InputQuery("", s, num) ) return;
    std::vector<int> bs;
    my::CreateBitset( num.c_str(), bs );
    AnsiString sss = my::FormatBitset(bs).c_str();
    for( unsigned i=0; i<sz; ++i) if( bs[i+1] ) body_.erase(itrs[i]);
}
//------------------------------------------------------------------------------
void TaskList::Print() const
{
    // получить итераторы списка
    std::vector<CIterT> itrs;
    for( CIterT i = head_.begin(); i!=head_.end(); ++i ) itrs.push_back(i);
    for( CIterT i = body_.begin(); i!=body_.end(); ++i ) itrs.push_back(i);
    for( CIterT i = tail_.begin(); i!=tail_.end(); ++i ) itrs.push_back(i);


    if( itrs.empty() ) return;

    MyWCout( "«апланированные трансферы:\n");
    for( unsigned i = 0; i<itrs.size(); ++i )
    	MYWCOUT_("%d. %s\n", i+1, (*itrs[i])->What() ));
}
//------------------------------------------------------------------------------
void TaskList::PushBackTail( PTransfer task )
{
    	//assert( mainFormThreadId_== GetCurrentThreadId() );
    	tail_.push_back( task );
}
//------------------------------------------------------------------------------
void TaskList::PushFrontHead( PTransfer task )
{
    	//assert( mainFormThreadId_== GetCurrentThreadId() );
    	head_.push_front( task );
}
//------------------------------------------------------------------------------
void TaskList::PopFrontBody()
{
    	//assert( mainFormThreadId_!=GetCurrentThreadId() || InSendMessage()==TRUE   );
        body_.pop_front();
}
//------------------------------------------------------------------------------
void TaskList::PushBackBody( PTransfer task )
{
    //assert( mainFormThreadId_!=GetCurrentThreadId() || InSendMessage()==TRUE   );
    body_.push_back( task );
}
//------------------------------------------------------------------------------
PTransfer TaskList::FrontBody() const
{
    /*
    const bool
        isMainThread = mainFormThreadId_!=GetCurrentThreadId(),
        inSendMessage = InSendMessage()==TRUE
    ;
    */
    //assert( mainFormThreadId_!=GetCurrentThreadId() || InSendMessage()==TRUE   );
    return body_.empty() ? PTransfer() : body_.front();
}
//------------------------------------------------------------------------------
LRESULT TaskList::Merge()
{
	//assert( InSendMessage()==TRUE );
    body_.insert( body_.begin(), head_.begin(), head_.end() );
    head_.clear();
    while( !tail_.empty() )
    {
    	body_.push_back( tail_.front() );
        tail_.pop_front();
    }
	return 0;
}
//------------------------------------------------------------------------------
void TaskList::Clear()
{
	//assert( mainFormThreadId_==GetCurrentThreadId()  );
    body_.clear();
    head_.clear();
    tail_.clear();
}
//------------------------------------------------------------------------------
void TaskList::SetList( const ScenaryList& scn)
{
    this->Clear();
    for( unsigned i=0; i<scn.size(); ++i )
        head_.push_back( scn[i] );
}

const MyAbstructTransfer* TaskList::GetCurrentTask() const
{
	return body_.empty() ? NULL : body_.front().get();
}
//------------------------------------------------------------------------------
int TaskList::GetScenaryTaskIndex( const MyAbstructTransfer *task ) const
{
    return ::GetScenaryTaskIndex( GetList(), task );
}
//------------------------------------------------------------------------------
int TaskList::GetCurrentTaskIndex( ) const
{
    return GetScenaryTaskIndex( GetCurrentTask() );
}
//------------------------------------------------------------------------------
ScenaryList TaskList::GetList() const
{
	ScenaryList ret;
	#define INC_RET_WIRH_LIST_(nn)\
    for ( CIterT i=##nn##.begin(); i!=##nn##.end(); ++i ) ret.push_back( *i );
    	INC_RET_WIRH_LIST_( head_);
        INC_RET_WIRH_LIST_( body_);
        INC_RET_WIRH_LIST_( tail_);
    #undef INC_RET_WIRH_LIST_(nn)
	return ret;
}
//------------------------------------------------------------------------------
int GetScenaryTaskIndex( const ScenaryList& lst, const MyAbstructTransfer *task )
{
    for( unsigned i=0; i<lst.size(); ++i )
    	if( lst[i].get()==task )
        	return i;
    return -1;
}
