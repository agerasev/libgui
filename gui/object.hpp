#pragma once

#include <string>

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

#include "action.hpp"

namespace gui
{
class Container;

class Object
{
public:
	virtual ~Object() {}
	
	virtual void setId(const std::string &s) = 0;
	virtual std::string getId() const = 0;
	
	virtual void setBounds(const vec2 &b) = 0;
	virtual void setPosition(const vec2 &p) = 0;
	
	virtual vec2 getBounds() const = 0;
	virtual vec2 getPosition() const = 0;
	
	virtual void setParent(const Container *c) = 0;
	virtual const Container *getParent() const = 0;
	
	virtual void setAttribute(const std::string &key, const std::string &value) = 0;
	virtual std::string getAttribute(const std::string &key) const = 0;
	
	virtual void performAction(const Action &a) = 0;
	
	virtual void setVisibility(bool v) = 0;
	virtual bool getVisibility() const = 0;
	
	virtual void draw(const mat2 &m = unimat2, const vec2 &d = nullivec2) const = 0;
};
}
