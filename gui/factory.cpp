#include "factory.hpp"

#include <font/font.h>
#include <media/media.h>

#include "implementation/regularscreen.hpp"
#include "implementation/regularbutton.hpp"
#include "implementation/regulartogglebutton.hpp"

using namespace gui;

Factory::Factory(Media_App *app)
{
	fInit();
	Media_Asset *asset = Media_openAsset(app,"dejavusans.ttf");
	if(asset)
	{
		long size = Media_getAssetLength(asset);
		file_data = new unsigned char[size];
		Media_readAsset(asset,size,static_cast<void*>(file_data));
		Media_closeAsset(asset);
		rasterizer = fCreateRasterizer(static_cast<void*>(file_data),size);
	}
	else
	{
		printWarn("Couldn't open asset file\n");
	}
}

Factory::~Factory()
{
	fDestroyRasterizer(rasterizer);
	delete[] file_data;
	fDispose();
}

Screen *Factory::produceScreen()
{
	RegularScreen *screen = new RegularScreen;
	return screen;
}

Button *Factory::produceButton()
{
	RegularButton *button = new RegularButton;
	button->setFont(rasterizer);
	return button;
}

ToggleButton *Factory::produceToggleButton()
{
	RegularToggleButton *button = new RegularToggleButton;
	button->setFont(rasterizer);
	return button;
}
