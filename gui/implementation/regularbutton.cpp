#include "regularbutton.hpp"

using namespace gui;

RegularButton::RegularButton()
{
	
}

RegularButton::~RegularButton()
{
	
}

void RegularButton::setCallback(std::function<void(Button*)> func)
{
	callback = func;
}

std::function<void(Button*)> RegularButton::getCallback() const
{
	return callback;
}

void RegularButton::setColor(const vec4 &c)
{
	color = c;
}

vec4 RegularButton::getColor() const
{
	return color;
}

vec4 RegularButton::getCurrentColor() const
{
	return color;
}

void RegularButton::performClick()
{
	if(callback)
	{
		callback(this);
	}
}
