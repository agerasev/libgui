#include "factory.hpp"

#include <font/font.h>
#include <media/media.h>

#include "impl/screen.hpp"
#include "impl/button.hpp"

using namespace gui;

Factory::Factory(Media_App *app)
{
	fInit();
	
	Media_Asset *asset = Media_openAsset(app,"dejavusans.ttf");
	if(asset)
	{
		long size = Media_getAssetLength(asset);
		void *data = static_cast<void*>(new unsigned char[size]);
		Media_readAsset(asset,size,data);
		fCreateRasterizer(data,size);
		Media_closeAsset(asset);
	}
	else
	{
		printWarn("Couldn't open asset file\n");
	}
}

Factory::~Factory()
{
	fDispose();
}

Screen *Factory::produceScreen()
{
	return new RegularScreen();
}

Button *Factory::produceButton()
{
	return new RegularButton();
}

