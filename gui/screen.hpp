#pragma once

#include "container.hpp"

namespace gui
{
class Screen : public virtual Container
{
public:
	Screen() {}
	virtual ~Screen() {}
	
	virtual void drawContainer(const mat2 &m, const vec2 &d) const = 0;
	virtual void performContainerAction(const Action &a) = 0;
};
}
