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
	float text_size = 16;
	float dx = 0, dy = 0;
	GImage *image = nullptr;
	vec4 color = vec4(0,0,0,1);
	bool visible = false;
	
public:
	RegularText();
	virtual ~RegularText();
	
	virtual void setText(const std::wstring &str) override;
	virtual std::wstring getText() const override;
	
	virtual void setTextSize(int size) override;
	virtual int getTextSize() const override;
	
	virtual void setTextColor(const vec4 &c) override;
	virtual vec4 getTextColor() const override;
	
	void drawText(const mat2 &m, const vec2 &d) const;
	
	void setFont(FRasterizer *r);
	FRasterizer *getFont() const;
	
	void createTextImage();
	void freeTextImage();
	void updateTextImage();
	
	void setTextVisibility(bool v);
	bool getTextVisibility() const;
};
}
