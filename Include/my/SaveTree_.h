#ifndef MY_SAVE_MY_ABSTRUCT_TREE_H_INCLUDED___
#define MY_SAVE_MY_ABSTRUCT_TREE_H_INCLUDED___

#include <cassert>
#include <map>

#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"

#include "my\Tree_.h"
#include "my\myLexicalConversions.h"

#include "CstmIni_.h"



namespace my
{

    template<class T, template <class> class IO>
    class Tree<T,IO>::SaveIniFoo
    {
        PIni ini_;
    public:
    	explicit SaveIniFoo( PIni ini ) : ini_(ini) {}
        void operator()( const Tree::P tree )
        {

        	const Tree<T,IO>::P par = tree->parent_;
			const AnsiString
            sect = IntToStr(reinterpret_cast<long>(tree.get()));

            if (par)
    			ini_->WriteInteger( sect, "par", reinterpret_cast<long>(par.get()) );
            ini_->WriteString( sect, "dat", tree->dat_ );
        }
    };



    template<class T, template <class> class IO>
    class Tree<T,IO>::ReadIniHlpr : public boost::noncopyable
    {

    public:
    	typedef std::map<long, typename TreeTrait<T,IO>::PTree> AssocTree;
		typedef AssocTree::iterator AssocIter;
    private:

    public:

        static bool MakeAssocTreeMap(PIni ini, AssocTree& assoc)
		{
			PList skts = PList( new TStringList );
    		ini->ReadSections(skts.get());
    		const unsigned sz = skts->Count;
    		if(sz==0) return false;
    		for ( unsigned i=0; i<sz; ++i )
    		{
    			const long id = StrToIntDef(skts->Strings[i],-1);
        		if(id<0) return false;

        		const std::pair<AssocIter,bool>
        		ins = assoc.insert( std::make_pair(id,  Tree<T,IO>::P(new Tree<T,IO>) ) );
    			if( !ins.second ) return false;
    		}
    		return sz;
		}
        static Tree<T,IO>::P Read( PIni ini  )
        {
        	Tree<T,IO>::P ret;
        	AssocTree assoc;

            if( !MakeAssocTreeMap(ini, assoc) )
            	return Tree<T,IO>::P();

        	AssocIter i = assoc.begin(), e = assoc.end();
    		for ( ; i!=e; ++i)
    		{
    			PTree p = i->second;
        		const long id = i->first;
        		const AnsiString sect = IntToStr(id);
        		const AnsiString dt = ini->ReadString(sect,"dat","");
        		const long parId = ini->ReadInteger(sect,"par",-1);
        		p->dat_ = dt;

        		if(parId<0)
        		{
        			if(ret) return Tree<T,IO>::P();
        			ret = p;
            		continue;
        		}
        		AssocIter fnd = assoc.find( parId );
        		assert(fnd!=e);
        		PTree par = fnd->second;

        		p->parent_.reset( par.get(), my::NullDeleter() );
        		par->items_.push_back( PTree(p) );
    		}
    		return ret;
        }
    };

};// namespace my
//-----------------------------------------------------------------------------/


template<class E, class T, class Y>
    std::basic_ostream<E, T>& operator<< (std::basic_ostream<E, T> & os,
    boost::shared_ptr<my::Tree<Y> > const & tree)
    {
    	return os << "Жопа2";
    }



#endif
