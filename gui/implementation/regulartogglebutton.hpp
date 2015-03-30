#pragma once

#include "../togglebutton.hpp"

#include <functional>

#include "regularbuttonbase.hpp"

namespace gui
{
class RegularToggleButton : public RegularButtonBase, public virtual ToggleButton
{
private:
	std::function<void(ToggleButton*)> callback;
	vec4 color = vec4(0.5,0.5,0.5,1);
	vec4 toggle_color = vec4(0.8,0.8,0.8,1);
	bool state = false;
	
public:
	RegularToggleButton();
	virtual ~RegularToggleButton();
	
	virtual void setCallback(std::function<void(ToggleButton*)> func) override;
	virtual std::function<void(ToggleButton*)> getCallback() const override;
	
	virtual void setState(bool st) override;
	virtual bool getState() const override;
	
	virtual void setColor(const vec4 &c) override;
	virtual vec4 getColor() const override;
	
	virtual void setToggleColor(const vec4 &c) override;
	virtual vec4 getToggleColor() const override;
	
	virtual vec4 getCurrentColor() const override;
	virtual void performClick() override;
};
}
