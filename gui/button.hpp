#pragma once

#include <functional>
#include <string>

#include "object.hpp"

namespace gui
{
class Button : public Object
{
private:
	std::function<void(Button*)> callback;
	std::wstring caption;
	bool inside = false, down = false, clicked = false;
	bool hold = false;
	
public:
	Button();
	virtual ~Button();
	
	void setCaption(const std::wstring &str);
	std::wstring getCaption() const;
	
	void setCallback(std::function<void(Button*)> func);
	std::function<void(Button*)> getCallback() const;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual void performAction(const Action &a) override;
};
}
