#pragma once

#include <media/media.h>

#include "screen.hpp"
#include "button.hpp"

namespace gui
{
class Factory
{
public:
	Factory(Media_App *app);
	~Factory();
	
	Screen *produceScreen();
	Button *produceButton();
};
}
