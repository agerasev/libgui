#pragma once

#include "../button.hpp"

#include <functional>

#include "regularbuttonbase.hpp"

namespace gui
{
class RegularButton : public RegularButtonBase, public virtual Button
{
private:
	std::function<void(Button*)> callback;
	vec4 color = vec4(0.5,0.5,0.5,1);
	
public:
	RegularButton();
	virtual ~RegularButton();
	
	virtual void setCallback(std::function<void(Button*)> func) override;
	virtual std::function<void(Button*)> getCallback() const override;
	
	virtual void setColor(const vec4 &c) override;
	virtual vec4 getColor() const override;
	
	virtual vec4 getCurrentColor() const override;
	virtual void performClick() override;
};
}
