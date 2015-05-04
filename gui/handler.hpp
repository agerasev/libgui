#pragma once

#ifndef LIBGUI_NO_LIBMEDIA

#include <media/media.h>

#include "screen.hpp"

namespace gui
{
class MediaHandler
{
private:
	Media_App *app = nullptr;
	Screen *screen = nullptr;
	
public:
	MediaHandler();
	~MediaHandler();
	
	void setScreen(Screen *s);
	
	bool handleSurface(const Media_SurfaceEvent *event);
	bool handleMotion(const Media_MotionEvent *event);
	void updateState();
	
	void setMediaApp(Media_App *app);
};
}

#endif
