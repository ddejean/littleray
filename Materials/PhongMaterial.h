/*
 * PhongMaterial.h
 *
 *  Created on: 4 nov. 2011
 *      Author: solarius
 */

#ifndef PHONGMATERIAL_H_
#define PHONGMATERIAL_H_

#include "Material.h"

class PhongMaterial: public Material {
public:
	double specularValue;
	double specularPower;

	PhongMaterial(double r,
				  double g,
				  double b,
				  double refl,
				  double specValue,
				  double specPower);
	virtual ~PhongMaterial() {};

	/*
	 * Apply light contribution from material, light and view ray to
	 * pixel using the Lambert then the Phong properties.
	 */
	void lightContribution(Pixel &in,
						   	   	   Ray &viewRay,
						   	   	   Light &light,
						   	   	   Ray &lightRay,
						   	   	   Vector &normal);
};

#endif /* PHONGMATERIAL_H_ */
