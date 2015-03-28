#pragma once

#include <functional>
#include <string>

#include "object.hpp"
#include "text.hpp"

namespace gui
{
class Button : public virtual Object, public virtual Text
{
public:
	Button() {}
	virtual ~Button() {}
	
	virtual void setCallback(std::function<void(Button*)> func) = 0;
	virtual std::function<void(Button*)> getCallback() const = 0;
	
	virtual void draw(const mat2 &m, const vec2 &d) const = 0;
	virtual void performAction(const Action &a) = 0;
};
}
