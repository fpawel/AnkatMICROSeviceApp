/*
	Определение обобщённой фабрики интерфейсов
*/

#ifndef MY_FACTORY_H
#define MY_FACTORY_H
#include <map>
//#include <assert>
//---------------------------------------------------------------------------
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
//---------------------------------------------------------------------------


namespace my
{
template
<
	class AbstractProduct,
    typename IdintifierType,
    typename ProductCreator = AbstractProduct (*)()
>
class Factory : public boost::noncopyable
{
    typedef std::map<IdintifierType, ProductCreator> IdToProductMap;
    IdToProductMap associations_;

    inline IdToProductMap::const_iterator GetItem(const IdintifierType& id)
    {
    	IdToProductMap::const_iterator i = associations_.find(id), end = associations_.end();
        assert(i!=end && "Неизвестный идентификатор!");
        return i;
    }
public:
	Factory()
    {
    	int a = 0;
    }
    ~Factory()
    {
    	int a = 0;
    }

    bool Register(const IdintifierType& id, ProductCreator creator)
    {
    	return associations_.insert( IdToProductMap::value_type(id, creator) ).second ;
    }
    template<typename P>
    AbstractProduct Create(const IdintifierType& id, P param)
    {
        return (GetItem(id)->second)(param);
    }

};

};// namespace my
#endif