#pragma once

#include <functional>
#include <list>

#include "object.hpp"

namespace gui 
{
class Container : public Object
{
private:
	std::list<Object*> objects;
	
public:
	Container();
	virtual ~Container();
	
	void add(Object *obj);
	void remove(Object *obj);
	void clear();
	
	void forEach(std::function<void(Object*)> func);
	void forEachConst(std::function<void(const Object*)> func) const;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual void drawContainer(const mat2 &m, const vec2 &d) const = 0;
	
	virtual void performAction(const Action &a) override;
	virtual void performContainerAction(const Action &a) = 0;
};
}
