#pragma once

#include <functional>

#include "object.hpp"

namespace gui 
{
class Container : public virtual Object
{
public:
	Container() {}
	virtual ~Container() {}
	
	virtual void add(Object *obj) = 0;
	virtual void remove(Object *obj) = 0;
	virtual void clear() = 0;
	
	virtual void forEach(std::function<void(Object*)> func) = 0;
	virtual void forEachConst(std::function<void(const Object*)> func) const = 0;
	
	virtual void draw(const mat2 &m, const vec2 &d) const = 0;
	virtual void drawContainer(const mat2 &m, const vec2 &d) const = 0;
	
	virtual void performAction(const Action &a) = 0;
	virtual void performContainerAction(const Action &a) = 0;
};
}
