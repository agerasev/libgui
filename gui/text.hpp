#pragma once

#include <string>

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

namespace gui
{
class Text
{
public:
	virtual void setText(const std::wstring &str) = 0;
	virtual std::wstring getText() const = 0;
	
	virtual void setTextSize(int size) = 0;
	virtual int getTextSize() const = 0;
	
	virtual void drawText(const mat2 &m, const vec2 &p) const = 0;
};
}
