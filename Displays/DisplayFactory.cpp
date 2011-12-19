#include "DisplayFactory.h"
#include "SDLDisplay.h"
#include "FakeDisplay.h"

Display* DisplayFactory::makeDisplay(Scene *s)
{
	return new SDLDisplay(s);
}
