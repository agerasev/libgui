#include "handler.hpp"

using namespace gui;

bool MediaHandler::handleSurface(const Media_SurfaceEvent *event)
{
	if(screen)
	{
		switch(event->type)
		{
		case MEDIA_SURFACE_INIT:
			screen->setVisibility(true);
			break;
		case MEDIA_SURFACE_TERM:
			screen->setVisibility(false);
			break;
		case MEDIA_SURFACE_RESIZE:
			screen->setBounds(vec2(event->w,event->h));
		default:
			break;
		}
		return true;
	}
	return false;
}

static int __transform_buttons(Media_ButtonType mb)
{
	return 
	    Action::BUTTON_LEFT*((mb & MEDIA_BUTTON_LEFT) != 0) |
	    Action::BUTTON_MIDDLE*((mb & MEDIA_BUTTON_MIDDLE) != 0) |
	    Action::BUTTON_RIGHT*((mb & MEDIA_BUTTON_RIGHT) != 0);
}

bool MediaHandler::handleMotion(const Media_MotionEvent *event)
{
	bool caught;
	if(screen)
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
		caught = screen->performAction(action);
	}
	return caught;
}

MediaHandler::MediaHandler()
{
	
}

MediaHandler::~MediaHandler()
{
	
}

void MediaHandler::updateState()
{
	
}

void MediaHandler::setScreen(Screen *s)
{
	screen = s;
}

void MediaHandler::setMediaApp(Media_App *a)
{
	app = a;
}
