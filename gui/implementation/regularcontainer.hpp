#pragma once

#include "../container.hpp"

#include <functional>
#include <list>

#include "regularobject.hpp"

namespace gui
{
class RegularContainer : public virtual Container, public RegularObject
{
private:
	std::list<Object*> children;
	
public:
	RegularContainer();
	virtual ~RegularContainer();
	
	virtual void addChild(Object *obj) override;
	virtual void removeChild(Object *obj) override;
	virtual void clear() override;
	
	virtual void forEachChild(std::function<void(Object*)> func) override;
	virtual void forEachChildConst(std::function<void(const Object*)> func) const override;
	
	virtual void setVisibility(bool v) override;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual void drawContainer(const mat2 &m, const vec2 &d) const = 0;
	
	virtual void performAction(const Action &a) override;
	virtual void performContainerAction(const Action &a) = 0;
};
}
