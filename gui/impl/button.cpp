#include "button.hpp"

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
	if(image)
	{
		gFreeImage(image);
	}
}

void RegularButton::setCaption(const std::wstring &str)
{
	caption = str;
	if(image)
	{
		gFreeImage(image);
	}
	int size = 28;
	fRaster *ras = fRasterize(nullptr,caption.data(),size);
	dx = 0;
	dy = ras->height/2 - ras->origin_y - 0.36*size;
	image = gGenImage(ras->width,ras->height,ras->data);
	fFreeRaster(ras);
}

std::wstring RegularButton::getCaption() const
{
	return caption;
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
	gTranslate(fvec2(getPosition()).data);
	gTransform((fmat2(getBounds().x(),0,0,getBounds().y())).data);
	gDrawQuad();
	if(image)
	{
		gSetColorInt(G_BLACK);
		gTranslate(fvec2(getPosition() + vec2(dx,dy)).data);
		gTransform((0.5f*fmat2(image->width,0,0,image->height)).data);
		gDrawImage(image);
	}
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
