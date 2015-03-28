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

vec2 RegularObject::getBounds() const
{
	return bounds;
}

vec2 RegularObject::getPosition() const
{
	return position;
}

void RegularObject::setParent(const Container *c)
{
	parent = c;
}

const Container *RegularObject::getParent() const
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
