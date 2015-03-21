#pragma once

#include "../button.hpp"

#include <functional>
#include <string>

#include "object.hpp"

#include <graphics/graphics.h>

namespace gui
{
class RegularButton : public virtual RegularObject, public Button
{
private:
	std::function<void(Button*)> callback;
	std::wstring caption;
	bool inside = false, down = false, clicked = false;
	bool hold = false;
	
	GImage *image = nullptr;
	int dx = 0, dy = 0;
	
public:
	RegularButton();
	virtual ~RegularButton();
	
	virtual void setCaption(const std::wstring &str) override;
	virtual std::wstring getCaption() const override;
	
	virtual void setCallback(std::function<void(Button*)> func) override;
	virtual std::function<void(Button*)> getCallback() const override;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual void performAction(const Action &a) override;
};
}
