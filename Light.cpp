#include "Light.h"

Light::Light(Point &p, double r, double g, double b)
{
        this->position = p;
        this->red = r;
        this->green = g;
        this->blue = b;
}
