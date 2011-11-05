#include <cmath>
#include "Vector.h"
#include "PhongMaterial.h"

PhongMaterial::PhongMaterial(double r,
		  	  	  	  	     double g,
		  	  	  	  	     double b,
		  	  	  	  	     double refl,
		  	  	  	  	     double specValue,
		  	  	  	  	     double specPower):
         Material(r, g, b, refl),
         specularValue(specValue),
         specularPower(specPower)
{
}

void PhongMaterial::lightContribution(Pixel &in,
					   	   	     	  Ray &viewRay,
					   	   	     	  Light &light,
					   	   	     	  Ray &lightRay,
					   	   	     	  Vector &normal)
{
		double reflect;
		double phongTerm;
		Vector phongDir;

		/* Apply Lambert effect first */
		Material::lightContribution(in, viewRay, light, lightRay, normal);

		/* Then phong effect */
		reflect = 2.0f * (lightRay.dir * normal);
		phongDir = lightRay.dir - (normal * reflect);
		phongTerm = fmax(phongDir * viewRay.dir, 0.0f) ;
		phongTerm = this->specularValue * std::pow(phongTerm, this->specularPower) * lightRay.lightness;
		in.red += phongTerm * light.red;
		in.green += phongTerm * light.green;
		in.blue += phongTerm * light.blue;
}
