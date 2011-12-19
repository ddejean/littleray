#ifndef DISPLAYFACTORY_H_
#define DISPLAYFACTORY_H_

#include "Display.h"

class DisplayFactory {
public:
		Display* makeDisplay(Scene *s);
};

#endif /* DISPLAYFACTORY_H_ */
