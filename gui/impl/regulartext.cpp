#include "regulartext.hpp"

#include <media/log.h>

using namespace gui;

RegularText::RegularText()
{
	
}

RegularText::~RegularText()
{
	if(image)
	{
		gFreeImage(image);
	}
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

void RegularText::drawText(const mat2 &m, const vec2 &d) const
{
	if(image)
	{
		gSetColorInt(G_BLACK);
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

void RegularText::updateTextImage()
{
	if(rasterizer && text_size > 0 && text.size() > 0)
	{
		if(image)
		{
			gFreeImage(image);
		}
		FRaster *ras = fRasterize(rasterizer,text.data(),text_size);
		dx = 0;
		dy = ras->height/2 - ras->origin_y - 0.36*text_size;
		image = gGenImage(ras->width,ras->height,ras->data);
		fFreeRaster(ras);
	}
}
