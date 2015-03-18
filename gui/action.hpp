#pragma once

#include <4u/la/vec.hpp>

namespace gui
{

struct Action
{
public:
	enum Type
	{
		NONE = 0,
		MOTION,
		DOWN,
		UP,
		ENTER,
		LEAVE,
		SCROLL
	};
	
	static const int 
	  BUTTON_LEFT   = 0x1,
	  BUTTON_MIDDLE = 0x2,
	  BUTTON_RIGHT  = 0x4;

	Type type;
	vec2 position;
	vec2 value;
	int button;
	int index;
};

}
