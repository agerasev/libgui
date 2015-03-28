#include "regularbutton.hpp"

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

#include <font/font.h>
#include <media/media.h>
#include <graphics/graphics.h>

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

void RegularButton::draw(const mat2 &m, const vec2 &d) const
{
	unsigned int color = 0;
	if(clicked)
	{
		color = G_GREEN;
	}
	else
	{
		color = G_BLUE;
	}
	if(down)
	{
		if(clicked)
		{
			color = 0xff00cc00;
		}
		else
		{
			color = 0xffcc0000;
		}
	}
	else
	if(inside)
	{
		if(clicked)
		{
			color = 0xff44ff44;
		}
		else
		{
			color = 0xffff4444;
		}
	}
	gSetColorInt(color);
	vec2 pos = getPosition() + d;
	mat2 mat = m*mat2(getBounds().x(),0,0,getBounds().y());
	gTranslate(fvec2(pos).data);
	gTransform(fmat2(mat).data);
	gDrawQuad();
	drawText(m,pos);
}

void RegularButton::performAction(const Action &a)
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
