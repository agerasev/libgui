#pragma once

#include <media/media.h>
#include <font/font.h>

#include "screen.hpp"
#include "button.hpp"

namespace gui
{
class Factory
{
private:
	FRasterizer *rasterizer = nullptr;
	unsigned char *file_data = nullptr;
	
public:
	Factory(Media_App *app);
	~Factory();
	
	Screen *produceScreen();
	Button *produceButton();
};
}
