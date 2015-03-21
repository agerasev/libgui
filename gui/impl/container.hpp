#pragma once

#include "../container.hpp"

#include <functional>
#include <list>

#include "object.hpp"

namespace gui
{
class RegularContainer : public virtual Container, public RegularObject
{
private:
	std::list<Object*> objects;
	
public:
	RegularContainer();
	virtual ~RegularContainer();
	
	virtual void add(Object *obj) override;
	virtual void remove(Object *obj) override;
	virtual void clear() override;
	
	virtual void forEach(std::function<void(Object*)> func) override;
	virtual void forEachConst(std::function<void(const Object*)> func) const override;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual void drawContainer(const mat2 &m, const vec2 &d) const = 0;
	
	virtual void performAction(const Action &a) override;
	virtual void performContainerAction(const Action &a) = 0;
};
}
