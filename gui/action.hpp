#pragma once

#include <4u/la/vec.hpp>

namespace gui
{

enum Button
{
	LEFT   = 0x10000,
	MIDDLE = 0x20000,
	RIGHT  = 0x40000
};

struct Action
{
public:
	enum Type
	{
		NONE = 0,
		MOTION,
		CLICK,
		HOLD,
		DOWN,
		UP,
		SCROLL
	};

	Type type;
	vec2 position;
	vec2 value;
	Button button;
	int index;
};

}
