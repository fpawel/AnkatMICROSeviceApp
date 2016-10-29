#ifndef MY_ABSTRUCT_TREE_H_INCLUDED___
#define MY_ABSTRUCT_TREE_H_INCLUDED___

#include <vector>
#include <set>
//#include <functional>
#include <cassert>

#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"

#include "Loki\Functor.h"


#include "SimpleFoo_.h"

namespace my
{
	namespace Private
    {
    	template<class T> struct DefaultIO_Tree
        {
        protected:
        	~DefaultIO_Tree() {}
            template<class M>
            bool IOFoo(M m,const T& )
            {
            }

            void IOFoo1( );
        };

    };


	template
    <
    	class T,
        template <class> class IO = Private::DefaultIO_Tree
    > class Tree;

    template<class T, template <class> class IO = Private::DefaultIO_Tree>
    struct TreeTrait
    {
    	typedef typename Tree<T,IO> TreeType;
    	typedef boost::shared_ptr< TreeType > PTree;
    };



template<class T, template <class> class IO>
class Tree : public IO<T>, public boost::noncopyable
{


public:
	typedef typename IO IOStrategyType;
    typedef T ValueType;

    //реализаци€ вовда/вывода в ини-файл
    class SaveIniFoo;
    friend class SaveIniFoo;

    class ReadIniHlpr;
    friend class ReadIniHlpr;

private:
	typedef TreeTrait<T,IO>::PTree P;
    typedef std::vector<P> Items;

    // папа
    P parent_;
    // дети
    Items items_;
    // данные
    T dat_;
    //
    P this_;
public:
    Tree(P par = P(), T dat = T() );

    P Parent() { return P(parent_.get(),my::NullDeleter()); }

    ~Tree()
    {
    	T dt = Dat();
    	int a = 0;
        const Tree* p = this;
        p = NULL;
    }

    // данные
    T& Dat() { return dat_; }
    // имеютс€ ли ветви
    bool HasChld() const { return !items_.empty(); }
    // колличество ветвей
    size_t ChldsCount() const { return items_.size(); }
    // ветвь номер idx
    P ChldAt(size_t idx ) const { return items_.at(idx); }
    // массив ветвей
    std::pair<P*,P*> Childs() { return std::make_pair(items_.begin(),items_.end()); }
    // ветвь, удовлетвор€юща€ условию foo, или 0
    template<class F>  P FindChild(F foo);
    // ветвь дерева (даннае==val), или 0
    P GetChild(const T& val);

    // удалить ветвь
    bool DeleteChild(P tree);

   	// создать и добавить ветвь
    P CreateChild(T dat = T());

    // добавить ветвь
    P AddChild(P tree);

    // получить( создать, если отсутствует) поддерево
    template<typename DatIter>
    P GetSubTree( DatIter i, DatIter end )
    {
        P tree = this_;
    	for( ; i!=end; ++i)
        {
        	PTree nextTree = tree->GetChild(*i);
            if( !nextTree )
            	nextTree = tree->CreateChild(*i);
            assert(nextTree);
            tree = nextTree;
        }
        return tree;
    }

    // обход дерева вверх
    template<class F> void GoTop( F foo );

    // обход дерева вниз
    template<class F> void GoDown( F foo );

    // получить корень
    P GetRoot() const;


    template<class F> bool Save(F foo)
    {
    	foo(this_);
    	const P *i = items_.begin(), *e = items_.end();
    	for( ; i!=e; ++i )
    		(*i)->Save(foo);
    	return true;
    }
};

	template
    <
    	class T,
        template<class> class IO,
        class F
    >
    struct UnaryPred
    {
    	F foo_;
        UnaryPred(F foo) : foo_(foo) {}
    	bool operator() (const typename Tree<T,IO>::P& p)
        {
        	return foo_(p->Dat());
        }
    };

    template<class T, template <class> class IO>
    struct UnaryEmpty { void operator() (const typename Tree<T,IO>::P&) {} };


	template<class T, template <class> class IO> Tree<T,IO>::Tree(P par, T dat)
    	: parent_(par), dat_(dat), this_(this,my::NullDeleter())
    {
    	GoTop( UnaryEmpty<T,IO>() );
    	T dt = Dat();
        int a = 0;
    }

    template<class T, template <class> class IO>
    template<class F>  typename Tree<T,IO>::P Tree<T,IO>::FindChild(F foo)
    {
    	P *e = items_.end(), *fnd = std::find_if( items_.begin(), e, UnaryPred<T,IO,F>(foo) );
        if(fnd==e) return P();
        return P( (*fnd).get(), my::NullDeleter() );
    }
    // ветвь дерева (даннае==val), или 0
    template<class T,template <class> class IO>
    typename Tree<T,IO>::P Tree<T,IO>::GetChild(const T& val)
    {
    	return FindChild(std::bind1st(std::equal_to<T>(),val));
    }

    // удалить ветвь
    template<class T, template <class> class IO>
    bool Tree<T,IO>::DeleteChild(Tree<T,IO>::P tree)
    {
    	Iter
        e = items_.end(), fnd = std::find( items_.begin(), e, tree );
        if (fnd==e) return false;
        //(*fnd)->items_.clear();
        items_.erase(fnd);
        //fnd->reset();
        return true;
    }

    // добавить поддерево
    template<class T, template <class> class IO>
    typename Tree<T,IO>::P Tree<T,IO>::AddChild(typename Tree<T,IO>::P tree)
    {
    	tree->parent_ = P( this, my::NullDeleter() );
    	items_.push_back( tree  );
        return P( items_.back().get(),my::NullDeleter() );
    }

    // создать и добавить поддерево
    template<class T, template <class> class IO>
    typename Tree<T,IO>::P Tree<T,IO>::CreateChild(T dat)
    {
    	items_.push_back( P(new Tree( P( this, my::NullDeleter() ) ,dat)) );
        return P( items_.back().get(),my::NullDeleter() );
    }

    // обход дерева вверх
    template<class T, template <class> class IO>
    template<class F> void Tree<T,IO>::GoTop( F foo )
    {
    	typedef std::set<P> Set_1;
        typedef Set_1::iterator Iter_1;
        Set_1 aSet;

    	for ( P tree = this_; tree; tree = tree->Parent()  )
        {
        	std::pair<Iter_1,bool> ins = aSet.insert(tree);
            assert(ins.second);
    		foo(tree);
        }
    }

    // обход дерева вниз
    template<class T, template <class> class IO>
    template<class F> void Tree<T,IO>::GoDown( F foo )
    {
    	foo(this_);
        P *e = items_.end(), *i = items_.begin();
        for( ; i!=e; ++i ) (*i)->GoDown<F>( foo );
    }

    // получить корень
    template<class T, template <class> class IO>
    typename Tree<T,IO>::P Tree<T,IO>::GetRoot() const
    {
    	P root = this_;
    	for ( P tree = this_->Parent(); tree; root = tree, tree = tree->Parent()  );
        return root;

    }

    namespace Private
    {

    template<class T>
    void DefaultIO_Tree<T>::IOFoo1()
    {
    	typedef typename DefaultIO_Tree<T> ThisType;
        typedef typename TreeTrait<T>::TreeType TreeType;

    	const TreeType* tree = static_cast<const TreeType*>(this);
        assert(tree);

    }

    };

};// namespace my
//-----------------------------------------------------------------------------/




#endif
