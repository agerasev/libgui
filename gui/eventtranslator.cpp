#include "eventtranslator.hpp"

using namespace gui;

void LibMedia_EventTranslator::_app_handler(const Media_AppEvent *event, void *data)
{
	LibMedia_EventTranslator *self = static_cast<LibMedia_EventTranslator*>(data);
	if(self->screen)
	{
		switch(event->type)
		{
		default:
			break;
		}
	}
}

void LibMedia_EventTranslator::_surface_handler(const Media_SurfaceEvent *event, void *data)
{
	LibMedia_EventTranslator *self = static_cast<LibMedia_EventTranslator*>(data);
	if(self->screen)
	{
		switch(event->type)
		{
		case MEDIA_SURFACE_RESIZE:
			self->screen->setBounds(vec2(event->w,event->h));
		default:
			break;
		}
	}
}

static int __transform_buttons(Media_ButtonType mb)
{
	return 
	    Action::BUTTON_LEFT*((mb & MEDIA_BUTTON_LEFT) != 0) |
	    Action::BUTTON_MIDDLE*((mb & MEDIA_BUTTON_MIDDLE) != 0) |
	    Action::BUTTON_RIGHT*((mb & MEDIA_BUTTON_RIGHT) != 0);
}

void LibMedia_EventTranslator::_motion_handler(const Media_MotionEvent *event, void *data)
{
	LibMedia_EventTranslator *self = static_cast<LibMedia_EventTranslator*>(data);
	
	if(self->screen)
	{
		Action action;
		action.button = __transform_buttons(event->button);
		action.index = event->index;
		action.position = vec2(event->x,event->y);
		action.value = nullvec2;
		switch(event->action)
		{
		case MEDIA_ACTION_DOWN:
			action.type = Action::Type::DOWN;
			break;
		case MEDIA_ACTION_UP:
			action.type = Action::Type::UP;
			break;
		case MEDIA_ACTION_WHEEL:
			action.type = Action::Type::SCROLL;
			action.value = vec2(event->xval,event->yval);
			break;
		case MEDIA_ACTION_MOVE:
			action.type = Action::Type::MOTION;
			action.value = vec2(event->xval,event->yval);
		default:
			break;
		}
		self->screen->performAction(action);
	}
}

void LibMedia_EventTranslator::_sensor_handler(const Media_SensorEvent *event, void *data)
{
	
}

LibMedia_EventTranslator::LibMedia_EventTranslator()
{
	listener.data = static_cast<void*>(this);
	listener.app = &_app_handler;
	listener.surface = &_surface_handler;
	listener.motion = &_motion_handler;
	listener.sensor = &_sensor_handler;
}

LibMedia_EventTranslator::~LibMedia_EventTranslator()
{
	disconnect();
}

void LibMedia_EventTranslator::setScreen(Screen *s)
{
	screen = s;
}

void LibMedia_EventTranslator::connectToApp(Media_App *app)
{
	disconnect();
	this->app = app;
	Media_addListener(this->app,&listener);
}

void LibMedia_EventTranslator::disconnect()
{
	if(app)
	{
		Media_removeListener(app,&listener);
		app = nullptr;
	}
}
