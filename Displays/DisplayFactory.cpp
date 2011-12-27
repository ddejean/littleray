#include <iostream>
#include <assert.h>
#include <stdexcept>
#include "DisplayFactory.h"
#include "SDLDisplay.h"
#include "FakeDisplay.h"

Display* DisplayFactory::makeDisplay(Scene *s, std::string *type)
{
	if (type->compare("none") == 0) {
		std::cout << "Configuring without display." << std::endl;
		return new FakeDisplay(s);

	} else if (type->compare("sdl") == 0) {
		std::cout << "Configuring with a SDL display." << std::endl;
		return new SDLDisplay(s);
	} else {
		throw std::runtime_error("Invalid display type provided to DisplayFactory");
	}
	/* Must never happens */
	assert(0);
}
