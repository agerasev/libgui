#include "regularcontainer.hpp"

#include <media/media.h>

#include <4u/util/op.hpp>

static bool __isInside(const vec2 &t, const vec2 &b, const vec2 &p)
{
	vec2 pt = t - p;
	return _abs(pt.x()) <= b.x() && _abs(pt.y()) <= b.y();
}

using namespace gui;

RegularContainer::RegularContainer()
{
	
}

RegularContainer::~RegularContainer()
{
	
}

/* RegularContainer methodes */

void RegularContainer::addChild(Object *obj)
{
	children.push_back(obj);
	obj->setParent(this);
}

void RegularContainer::removeChild(Object *obj)
{
	children.remove(obj);
}

void RegularContainer::clear()
{
	children.clear();
}

void RegularContainer::forEachChild(std::function<void(Object*)> func)
{
	for(Object *o : children)
	{
		func(o);
	}
}

void RegularContainer::forEachChildConst(std::function<void(const Object*)> func) const
{
	for(const Object *o : children)
	{
		func(o);
	}
}

void RegularContainer::setVisibility(bool v)
{
	RegularObject::setVisibility(v);
	forEachChild([v](Object *o)
	{
		o->setVisibility(v);
	});
}

void RegularContainer::draw(const mat2 &m, const vec2 &d) const
{
	if(getVisibility())
	{
		vec2 cd = d + getOffsetPosition();
		drawContainer(m,d);
		forEachChildConst([&m,&cd](const Object *obj)
		{
			obj->draw(m,cd);
		});
	}
}

bool RegularContainer::performAction(const Action &a)
{
	bool caught = false;
	if(getVisibility())
	{
		Action na = a;
		na.position -= getPosition();
		if(na.type == Action::ENTER || na.type == Action::LEAVE)
		{
			na.type = Action::MOTION;
		}
		caught = caught || performContainerAction(a);
		forEachChild([na,&caught](Object *obj)
		{
			Action ca = na;
			
			bool now = __isInside(ca.position,obj->getOffsetBounds(),obj->getOffsetPosition());
			bool before = __isInside(ca.position - ca.value,obj->getOffsetBounds(),obj->getOffsetPosition());
			bool perform = false;
			
			if(ca.type == Action::MOTION)
			{
	#ifdef __MEDIA_TOUCHSCREEN
				if(now)
				{
					perform = true;
				}
				else
				if(before)
				{
					ca.type = Action::LEAVE;
					perform = true;
				}
	#else
				if(now)
				{
					if(before)
					{
						perform = true;
					}
					else
					{
						ca.type = Action::ENTER;
						perform = true;
					}
				}
				else
				{
					if(before)
					{
						ca.type = Action::LEAVE;
						perform = true;
					}
				}
	#endif
			}
			else
			if(now)
			{
				perform = true;
			}
			if(perform)
			{
				caught = caught || obj->performAction(ca);
			}
		});
	}
	return caught;
}
