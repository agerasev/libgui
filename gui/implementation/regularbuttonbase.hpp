#pragma once

#include "../button.hpp"

#include <functional>
#include "regularobject.hpp"
#include "regulartext.hpp"

namespace gui
{
class RegularButtonBase : public RegularObject, public RegularText
{
private:
	bool inside = false, down = false;
	bool hold = false;
	
public:
	RegularButtonBase();
	virtual ~RegularButtonBase();
	
	virtual void setVisibility(bool v) override;
	
	virtual void draw(const mat2 &m, const vec2 &d) const override;
	virtual bool performAction(const Action &a) override;
	
	virtual vec4 getCurrentColor() const = 0;
	virtual void performClick() = 0;
};
}
