#pragma once

#include "../button.hpp"

#include <functional>
#include <string>

#include "regularobject.hpp"
#include "regulartext.hpp"

#include <graphics/graphics.h>

namespace gui
{
class RegularButton : public RegularObject, public RegularText, public virtual Button
{
private:
	std::function<void(Button*)> callback;
	bool inside = false, down = false, clicked = false;
	bool hold = false;
	
public:
	RegularButton();
	virtual ~RegularButton();
	
	virtual void setCallback(std::function<void(Button*)> func) override;
	virtual std::function<void(Button*)> getCallback() const override;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual void performAction(const Action &a) override;
};
}
