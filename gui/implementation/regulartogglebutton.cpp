#include "regulartogglebutton.hpp"

using namespace gui;

RegularToggleButton::RegularToggleButton()
{
	
}

RegularToggleButton::~RegularToggleButton()
{
	
}

void RegularToggleButton::setCallback(std::function<void(ToggleButton*)> func)
{
	callback = func;
}

std::function<void(ToggleButton*)> RegularToggleButton::getCallback() const
{
	return callback;
}

void RegularToggleButton::setState(bool st)
{
	state = st;
}

bool RegularToggleButton::getState() const
{
	return state;
}

void RegularToggleButton::setColor(const vec4 &c)
{
	color = c;
}

vec4 RegularToggleButton::getColor() const
{
	return color;
}

void RegularToggleButton::setToggleColor(const vec4 &c)
{
	toggle_color = c;
}

vec4 RegularToggleButton::getToggleColor() const
{
	return toggle_color;
}

vec4 RegularToggleButton::getCurrentColor() const
{
	if(state)
	{
		return toggle_color;
	}
	return color;
}

void RegularToggleButton::performClick()
{
	state = !state;
	callback(this);
}

