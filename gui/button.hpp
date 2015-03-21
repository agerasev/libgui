#pragma once

#include <functional>
#include <string>

#include "object.hpp"

namespace gui
{
class Button : public virtual Object
{
public:
	Button() {}
	virtual ~Button() {}
	
	virtual void setCaption(const std::wstring &str) = 0;
	virtual std::wstring getCaption() const = 0;
	
	virtual void setCallback(std::function<void(Button*)> func) = 0;
	virtual std::function<void(Button*)> getCallback() const = 0;
	
	virtual void draw(const mat2 &m, const vec2 &d) const = 0;
	virtual void performAction(const Action &a) = 0;
};
}
