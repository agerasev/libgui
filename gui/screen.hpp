#pragma once

#include "container.hpp"

namespace gui
{
class Screen : public Container
{
public:
	Screen();
	virtual ~Screen();
	
	virtual void drawContainer(const mat2 &m, const vec2 &d) const override;
	virtual void performContainerAction(const Action &a) override;
};
}
