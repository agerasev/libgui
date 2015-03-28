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

void RegularContainer::add(Object *obj)
{
	objects.push_back(obj);
}

void RegularContainer::remove(Object *obj)
{
	objects.remove(obj);
}

void RegularContainer::clear()
{
	objects.clear();
}

void RegularContainer::forEach(std::function<void(Object*)> func)
{
	for(Object *o : objects)
	{
		func(o);
	}
}

void RegularContainer::forEachConst(std::function<void(const Object*)> func) const
{
	for(const Object *o : objects)
	{
		func(o);
	}
}

void RegularContainer::draw(const mat2 &m, const vec2 &d) const
{
	vec2 cd = d + getPosition();
	drawContainer(m,d);
	forEachConst([&m,&cd](const Object *obj)
	{
		obj->draw(m,cd);
	});
}

void RegularContainer::performAction(const Action &a)
{
	Action na = a;
	na.position -= getPosition();
	if(na.type == Action::ENTER || na.type == Action::LEAVE)
	{
		na.type = Action::MOTION;
	}
	performContainerAction(a);
	forEach([na](Object *obj)
	{
		Action ca = na;
		
		bool now = __isInside(ca.position,obj->getBounds(),obj->getPosition());
		bool before = __isInside(ca.position - ca.value,obj->getBounds(),obj->getPosition());

		if(ca.type == Action::MOTION)
		{
#ifdef __MEDIA_TOUCHSCREEN
			if(now)
			{
				obj->performAction(ca);
			}
			else
			if(before)
			{
				ca.type = Action::LEAVE;
				obj->performAction(ca);
			}
#else
			if(now)
			{
				if(before)
				{
					obj->performAction(ca);
				}
				else
				{
					ca.type = Action::ENTER;
					obj->performAction(ca);
				}
			}
			else
			{
				if(before)
				{
					ca.type = Action::LEAVE;
					obj->performAction(ca);
				}
			}
#endif
		}
		else
		if(now)
		{
			obj->performAction(ca);
		}
	});
}
