#include "regularbuttonbase.hpp"

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

#include <font/font.h>
#include <media/media.h>
#include <graphics/graphics.h>

using namespace gui;

RegularButtonBase::RegularButtonBase()
{
	
}

RegularButtonBase::~RegularButtonBase()
{
	
}

void RegularButtonBase::setVisibility(bool v)
{
	RegularObject::setVisibility(v);
	if(v)
	{
		setTextVisibility(v);
		createTextImage();
	}
	else
	{
		freeTextImage();
	}
}

void RegularButtonBase::draw(const mat2 &m, const vec2 &d) const
{
	vec4 c = getCurrentColor();
	if(down)
	{
		c = vec4(0.8,0.8,0.8,1.0) & getCurrentColor();
	}
	else
	if(inside)
	{
		c = vec4(1.25,1.25,1.25,1.0) & getCurrentColor();
	}
	gSetColor(fvec4(c).data);
	vec2 pos = getOffsetPosition() + d;
	mat2 mat = m*mat2(getOffsetBounds().x(),0,0,getOffsetBounds().y());
	gTranslate(fvec2(pos).data);
	gTransform(fmat2(mat).data);
	gDrawQuad();
	drawText(m,pos);
}

bool RegularButtonBase::performAction(const Action &a)
{
	bool caught = false;
	if(getVisibility())
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
				if(a.button & Action::BUTTON_LEFT)
				{
					performClick();
				}
			}
		}
		caught = true;
	}
	return caught;
}
