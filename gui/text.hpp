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
	
	virtual void setTextSize(int s) = 0;
	virtual int getTextSize() const = 0;
	
	virtual void setTextColor(const vec4 &c) = 0;
	virtual vec4 getTextColor() const = 0;
};
}
