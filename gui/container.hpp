#pragma once

#include <functional>

#include "object.hpp"

namespace gui 
{
class Container : public virtual Object
{
public:
	virtual ~Container() {}
	
	virtual void addChild(Object *obj) = 0;
	virtual void removeChild(Object *obj) = 0;
	virtual void clear() = 0;
	
	virtual void forEachChild(std::function<void(Object*)> func) = 0;
	virtual void forEachChildConst(std::function<void(const Object*)> func) const = 0;
};
}
