#include "Ray.h"

Ray::Ray(void)
{
	this->lightness = 1.0f;
        this->origin = Point(0, 0, 0);
        this->dir = Vector(0, 0, 0);
}

Ray::Ray(Point &o, Vector &d, double lightness)
{
	this->lightness = lightness;
        this->origin = o;
        this->dir = d;
}

bool Ray::isStillVisible(void)
{
	return (this->lightness >= 0.0f);
}

