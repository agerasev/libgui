#pragma once

#include <string>
#include <map>

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

#include "action.hpp"

namespace gui
{
class Container;

class Object
{
private:
	std::string id;
	
	const Container *parent = nullptr;
	std::map<std::string,std::string> attrib;
	
	vec2 bounds = nullvec2;
	vec2 position = nullvec2;
	
public:
	Object();
	virtual ~Object();
	
	void setId(const std::string &s);
	std::string getId() const;
	
	void setBounds(const vec2 &b);
	void setPosition(const vec2 &p);
	
	vec2 getBounds() const;
	vec2 getPosition() const;
	
	void setParent(const Container *c);
	const Container *getParent() const;
	
	void setAttribute(const std::string &key, const std::string &value);
	std::string getAttribute(const std::string &key) const;
	
	virtual void performAction(const Action &a) = 0;
	
	virtual void draw(const mat2 &m = unimat2, const vec2 &d = nullivec2) const = 0;
};
}
