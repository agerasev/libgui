#pragma once

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

#include "action.hpp"

namespace gui
{
class Object
{
public:
	Object();
	virtual ~Object();
	
	virtual void setBounds(const mat2 &b);
	virtual void setPosition(const vec2 &p);
	
	virtual mat2 getBounds() const;
	virtual vec2 getPosition() const;
	
	virtual void performAction(const Action &a);
	
	virtual void draw(const mat2 &m, const vec2 &d) const;
};
}
