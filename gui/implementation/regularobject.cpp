#include "regularobject.hpp"

using namespace gui;

RegularObject::RegularObject()
{
	
}

RegularObject::~RegularObject()
{
	
}

void RegularObject::setId(const std::string &s)
{
	id = s;
}

std::string RegularObject::getId() const
{
	return id;
}

void RegularObject::setBounds(const vec2 &b)
{
	bounds = b;
}

void RegularObject::setPosition(const vec2 &p)
{
	position = p;
}

void RegularObject::setRelativeBounds(const vec2 &rb)
{
	rel_bounds = rb;
}

void RegularObject::setRelativePosition(const vec2 &rp)
{
	rel_position = rp;
}

vec2 RegularObject::getBounds() const
{
	return bounds;
}

vec2 RegularObject::getPosition() const
{
	return position;
}

vec2 RegularObject::getRelativeBounds() const
{
	return rel_bounds;
}

vec2 RegularObject::getRelativePosition() const
{
	return rel_position;
}

vec2 RegularObject::getOffsetBounds() const
{
	if(getParent())
	{
		return bounds + 0.5*(getParent()->getOffsetBounds() & rel_bounds);
	}
	return bounds;
}

vec2 RegularObject::getOffsetPosition() const
{
	if(getParent())
	{
		return position + 0.5*(getParent()->getOffsetBounds() & rel_position);
	}
	return position;
}

void RegularObject::setParent(const Object *c)
{
	parent = c;
}

const Object *RegularObject::getParent() const
{
	return parent;
}


void RegularObject::setAttribute(const std::string &key, const std::string &value)
{
	auto ret = attrib.insert(std::pair<std::string,std::string>(key,value));
	if(!ret.second)
	{
		attrib[key] = value;
	}
}

std::string RegularObject::getAttribute(const std::string &key) const
{
	auto iterator = attrib.find(key);
	if(iterator == attrib.end())
	{
		return std::string("");
	}
	return iterator->second;
}

void RegularObject::setVisibility(bool v)
{
	visible = v;
}

bool RegularObject::getVisibility() const
{
	return visible;
}
