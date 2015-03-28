#pragma once

#include <string>
#include <graphics/graphics.h>
#include <font/font.h>

#include "../text.hpp"

namespace gui 
{
class RegularText : public virtual Text
{
private:
	std::wstring text;
	FRasterizer *rasterizer = nullptr;
	int text_size = 0;
	int dx = 0, dy = 0;
	GImage *image = nullptr;
	
public:
	RegularText();
	virtual ~RegularText();
	
	virtual void setText(const std::wstring &str) override;
	virtual std::wstring getText() const override;
	
	virtual void setTextSize(int size) override;
	virtual int getTextSize() const override;
	
	virtual void drawText(const mat2 &m, const vec2 &d) const override;
	
	void setFont(FRasterizer *r);
	FRasterizer *getFont() const;
	
	void updateTextImage();
};
}
