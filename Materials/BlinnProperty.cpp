#include <cmath>
#include "Maths/Vector.h"
#include "Material.h"
#include "BlinnProperty.h"

BlinnProperty::BlinnProperty(double r, double g, double b, double p):
	MaterialProperty(r, g, b), power(p)
{
}

void BlinnProperty::apply(Pixel &in,
					   	  Ray &viewRay,
					   	  Light &light,
					   	  Ray &lightRay,
					   	  Vector &normal)
{
	double blinnNorm;
	double blinnFactor;
	Vector blinnDir;

	/* Then the blinn-phong effect */
	blinnDir = lightRay.dir - viewRay.dir;
	blinnNorm = blinnDir.norm();
	if (blinnNorm == 0.0)
		return;
	blinnDir = blinnDir * (1.0 / blinnNorm);
	blinnFactor = fmax(blinnDir * normal, 0.0);
	blinnFactor = std::pow(blinnFactor, this->power) * lightRay.lightness;
	in.red += blinnFactor * this->red * light.red;
	in.green += blinnFactor * this->green * light.green;
	in.blue += blinnFactor * this->blue * light.blue;
}
