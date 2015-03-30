#include "regulartext.hpp"

#include <media/log.h>

using namespace gui;

RegularText::RegularText()
{
	
}

RegularText::~RegularText()
{
	freeTextImage();
}

void RegularText::setText(const std::wstring &str)
{
	text = str;
	updateTextImage();
}

std::wstring RegularText::getText() const
{
	return text;
}

void RegularText::setTextSize(int size)
{
	text_size = size;
	updateTextImage();
}

int RegularText::getTextSize() const
{
	return text_size;
}

void RegularText::setTextColor(const vec4 &c)
{
	color = c;
}

vec4 RegularText::getTextColor() const
{
	return color;
}

void RegularText::drawText(const mat2 &m, const vec2 &d) const
{
	if(image && visible)
	{
		gSetColor(fvec4(color).data);
		gTranslate(fvec2(d + vec2(dx,dy)).data);
		gTransform(fmat2(0.5*m*mat2(image->width,0,0,image->height)).data);
		gDrawImage(image);
	}
}

void RegularText::setFont(FRasterizer *r)
{
	rasterizer = r;
	updateTextImage();
}

FRasterizer *RegularText::getFont() const
{
	return rasterizer;
}

void RegularText::createTextImage()
{
	if(!image && rasterizer && visible && text_size > 0 && text.size() > 0)
	{
		FRaster *ras = fRasterize(rasterizer,text.data(),text_size);
		dx = 0 + 0.5*(ras->width%2);
		dy = ras->height/2.0 - ras->origin_y - 0.36*text_size + 0.5*((ras->height + 1)%2);
		image = gGenImage(ras->width,ras->height,ras->data);
		fFreeRaster(ras);
	}
}

void RegularText::freeTextImage()
{
	if(image)
	{
		gFreeImage(image);
		image = nullptr;
	}
}

void RegularText::updateTextImage()
{
	freeTextImage();
	createTextImage();
}

void RegularText::setTextVisibility(bool v)
{
	visible = v;
	updateTextImage();
}

bool RegularText::getTextVisibility() const
{
	return visible;
}
