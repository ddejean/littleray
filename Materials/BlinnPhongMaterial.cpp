#include <cmath>
#include "Vector.h"
#include "Material.h"
#include "BlinnPhongMaterial.h"

BlinnPhongMaterial::BlinnPhongMaterial(double r,
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

void BlinnPhongMaterial::lightContribution(Pixel &in,
					   	   	     	  Ray &viewRay,
					   	   	     	  Light &light,
					   	   	     	  Ray &lightRay,
					   	   	     	  Vector &normal)
{
	double blinnNorm;
	double blinnFactor;
	Vector blinnDir;

	/* Apply Lambert effect first */
	Material::lightContribution(in, viewRay, light, lightRay, normal);

	/* Then the blinn-phong effect */
	blinnDir = lightRay.dir - viewRay.dir;
	blinnNorm = blinnDir.norm();
	if (blinnNorm == 0.0)
		return;
	blinnDir = blinnDir * (1.0 / blinnNorm);
	blinnFactor = fmax(blinnDir * normal, 0.0);
	blinnFactor = this->specularValue * std::pow(blinnFactor, this->specularPower) * lightRay.lightness;
	in.red += blinnFactor * light.red;
	in.green += blinnFactor * light.green;
	in.blue += blinnFactor * light.blue;
}
