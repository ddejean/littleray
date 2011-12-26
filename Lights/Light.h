#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Maths/Point.h"
#include <iostream>

class Light {
public:
		Point position;
		double red;
		double green;
		double blue;

        Light(Point &p, double r, double g, double b);
};

#endif

