#pragma once

#include "object.hpp"

namespace gui 
{
class Container : public Object
{
public:
	class iterator
	{
	public:
		virtual Object *operator *();
		virtual iterator operator ++();
		virtual bool operator ==(const iterator &i) const;
		virtual bool operator !=(const iterator &i) const;
	};
	
	class const_iterator
	{
		virtual const Object *operator *();
		virtual const_iterator operator ++();
		virtual bool operator ==(const const_iterator &i) const;
		virtual bool operator !=(const const_iterator &i) const;
	};
	
public:
	Container();
	virtual ~Container();
	
	void add(Object *obj);
	void remove(Object *obj);
	void clear();
	
	virtual iterator begin();
	virtual iterator end();
	virtual const_iterator cbegin() const;
	virtual const_iterator cend() const;
};
}
