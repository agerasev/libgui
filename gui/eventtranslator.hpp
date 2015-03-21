#pragma once

#include "screen.hpp"

#ifndef LIBGUI_NO_LIBMEDIA
#include <media/media.h>
#endif

namespace gui
{
class EventTranslator
{
public:
	virtual void setScreen(Screen *s) = 0;
};

#ifndef LIBGUI_NO_LIBMEDIA
class LibMedia_EventTranslator : public EventTranslator
{
private:
	Media_App *app = nullptr;
	Media_Listener listener;
	Screen *screen = nullptr;
	
	static void _app_handler(const Media_AppEvent *event, void *data);
	static void _surface_handler(const Media_SurfaceEvent *event, void *);
	static void _motion_handler(const Media_MotionEvent *event, void *data);
	static void _sensor_handler(const Media_SensorEvent *event, void *data);
	
public:
	LibMedia_EventTranslator();
	virtual ~LibMedia_EventTranslator();
	
	virtual void setScreen(Screen *s) override;
	void connectToApp(Media_App *app);
	void disconnect();
};
#endif
}
