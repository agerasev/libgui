#include "object.hpp"

using namespace gui;

Object::Object()
{
	
}

Object::~Object()
{
	
}

void Object::setId(const std::string &s)
{
	id = s;
}

std::string Object::getId() const
{
	return id;
}

void Object::setBounds(const vec2 &b)
{
	bounds = b;
}

void Object::setPosition(const vec2 &p)
{
	position = p;
}

vec2 Object::getBounds() const
{
	return bounds;
}

vec2 Object::getPosition() const
{
	return position;
}

void Object::setParent(const Container *c)
{
	parent = c;
}

const Container *Object::getParent() const
{
	return parent;
}


void Object::setAttribute(const std::string &key, const std::string &value)
{
	auto ret = attrib.insert(std::pair<std::string,std::string>(key,value));
	if(!ret.second)
	{
		attrib[key] = value;
	}
}

std::string Object::getAttribute(const std::string &key) const
{
	auto iterator = attrib.find(key);
	if(iterator == attrib.end())
	{
		return std::string("");
	}
	return iterator->second;
}
