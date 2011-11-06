/*
 * PhongBlinnMaterial.h
 *
 *  Created on: 6 nov. 2011
 *      Author: solarius
 */

#ifndef BLINNPHONGMATERIAL_H_
#define BLINNPHONGMATERIAL_H_

#include "Material.h"

class BlinnPhongMaterial: public Material {
public:
	double specularValue;
	double specularPower;

	BlinnPhongMaterial(double r,
	  	  	     	   double g,
	  	  	     	   double b,
	  	  	     	   double refl,
	  	  	     	   double specValue,
	  	  	     	   double specPower);
	virtual ~BlinnPhongMaterial() {};

	/*
	 * Apply light contribution from material, light and view ray to
	 * pixel using the Lambert then the Blinn-Phong properties.
	 */
	void lightContribution(Pixel &in,
				   	   	   Ray &viewRay,
				   	   	   Light &light,
				   	   	   Ray &lightRay,
				   	   	   Vector &normal);
};

#endif /* PHONGBLINNMATERIAL_H_ */
