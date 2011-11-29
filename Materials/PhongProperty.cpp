#include <cmath>
#include "Vector.h"
#include "PhongProperty.h"

PhongProperty::PhongProperty(double r, double g, double b, double p):
         MaterialProperty(r, g, b), power(p)
{
}

void PhongProperty::apply(Pixel &in,
						  Ray &viewRay,
						  Light &light,
						  Ray &lightRay,
						  Vector &normal)
{
		double reflect;
		double phongTerm;
		Vector phongDir;

		/* Then phong effect */
		reflect = 2.0f * (lightRay.dir * normal);
		phongDir = lightRay.dir - (normal * reflect);
		phongTerm = fmax(phongDir * viewRay.dir, 0.0f) ;
		phongTerm = std::pow(phongTerm, this->power) * lightRay.lightness;
		in.red += phongTerm * this->red * light.red;
		in.green += phongTerm * this->green * light.green;
		in.blue += phongTerm * this->blue * light.blue;
}
