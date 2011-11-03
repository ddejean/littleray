#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Point.h"
#include <iostream>

class Light {
public:
		Point position;
		double red;
		double green;
		double blue;

        Light(Point &p, double r, double g, double b);
        friend std::istream &operator>>(std::istream &inputFile, Light &l);
};

#endif

