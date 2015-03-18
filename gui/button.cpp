#include "button.hpp"

#include <media/media.h>
#include <graphics/graphics.h>

using namespace gui;

Button::Button()
{
	
}

Button::~Button()
{
	
}

void Button::setCaption(const std::wstring &str)
{
	caption = str;
}

std::wstring Button::getCaption() const
{
	return caption;
}

void Button::setCallback(std::function<void(Button*)> func)
{
	callback = func;
}

std::function<void(Button*)> Button::getCallback() const
{
	return callback;
}

void Button::draw(const mat2 &m, const vec2 &d) const
{
	unsigned int color = 0;
	if(clicked)
	{
		color = GREEN;
	}
	else
	{
		color = BLUE;
	}
	if(down)
	{
		if(clicked)
		{
			color = YELLOW;
		}
		else
		{
			color = RED;
		}
	}
	else
	if(inside)
	{
		if(clicked)
		{
			color = CYAN;
		}
		else
		{
			color = MAGENTA;
		}
	}
	setColorInt(color);
	translate(fvec2(getPosition()).data);
	transform((fmat2(getBounds().x(),0,0,getBounds().y())).data);
	drawQuad();
}

void Button::performAction(const Action &a)
{
	if(a.type == Action::ENTER)
	{
		inside = true;
	}
	else
	if(a.type == Action::LEAVE)
	{
		inside = false;
		down = false;
		hold = false;
	}
	else
	if(a.type == Action::DOWN)
	{
		down = true;
		hold = true;
	}
	else
	if(a.type == Action::UP)
	{
		down = false;
		if(hold)
		{
			hold = false;
			clicked = !clicked;
			if(a.button & Action::BUTTON_LEFT)
			{
				callback(this);
			}
		}
	}
}
