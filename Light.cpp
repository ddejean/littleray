#include "Light.h"

Light::Light(Point &p, double r, double g, double b)
{
        this->position = p;
        this->red = r;
        this->green = g;
        this->blue = b;
}

std::istream &operator>>(std::istream &inputFile, Light &l)
{
        return inputFile >> l.position >> l.red >> l.green >> l.blue;
}

