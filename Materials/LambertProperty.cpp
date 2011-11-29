#include "LambertProperty.h"

LambertProperty::LambertProperty(double r, double g, double b):
	MaterialProperty(r, g, b)
{
}

void LambertProperty::apply(Pixel &in,
							Ray &viewRay,
							Light &light,
							Ray &lightRay,
							Vector &normal)
{
	double lambert;

	lambert = (lightRay.dir * normal) * viewRay.lightness;
	in.red += lambert * light.red * this->red;
	in.green += lambert * light.green * this->green;
	in.blue += lambert * light.blue * this->blue;
}
