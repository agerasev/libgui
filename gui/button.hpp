#pragma once

#include <functional>

#include "object.hpp"
#include "text.hpp"

namespace gui
{
class Button : public virtual Object, public virtual Text
{
public:
	virtual ~Button() {}
	
	virtual void setCallback(std::function<void(Button*)> func) = 0;
	virtual std::function<void(Button*)> getCallback() const = 0;
	
	virtual void setColor(const vec4 &c) = 0;
	virtual vec4 getColor() const = 0;
};
}
