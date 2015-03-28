#pragma once

#include "../screen.hpp"

#include "regularcontainer.hpp"

namespace gui
{
class RegularScreen : public virtual RegularContainer, public Screen
{
public:
	RegularScreen();
	virtual ~RegularScreen();
	
	virtual void drawContainer(const mat2 &m, const vec2 &d) const override;
	virtual void performContainerAction(const gui::Action &a) override;
};
}
