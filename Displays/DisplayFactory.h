#ifndef DISPLAYFACTORY_H_
#define DISPLAYFACTORY_H_

#include <string>
#include "Display.h"

class DisplayFactory {
public:
		Display* makeDisplay(Scene *s, std::string *type);
};

#endif /* DISPLAYFACTORY_H_ */
