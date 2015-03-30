#pragma once

#include <functional>

#include "object.hpp"
#include "text.hpp"

namespace gui
{
class ToggleButton : public virtual Object, public virtual Text
{
public:
	virtual ~ToggleButton() {}
	
	virtual void setCallback(std::function<void(ToggleButton*)> func) = 0;
	virtual std::function<void(ToggleButton*)> getCallback() const = 0;
	
	virtual void setState(bool st) = 0;
	virtual bool getState() const = 0;
	
	virtual void setColor(const vec4 &c) = 0;
	virtual vec4 getColor() const = 0;
	
	virtual void setToggleColor(const vec4 &c) = 0;
	virtual vec4 getToggleColor() const = 0;
};
}
