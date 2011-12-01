#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <iostream>
#include "Pixel.h"
#include "Ray.h"
#include "Light.h"
#include "MaterialProperty.h"

/*
 * Default material class, with simple Lambert behavior.
 */
class Material {
public:
	MaterialProperty *diffuse;
	MaterialProperty *specular;
	double reflection;

	Material(MaterialProperty *diffuse, MaterialProperty *specular, double refl);
	virtual ~Material(void);

	/*
	 * Apply light contribution from material, light and view ray to
	 * pixel using the Lambert property.
	 */
	virtual void lightContribution(Pixel &in,
						   	   	   Ray &viewRay,
						   	   	   Light &light,
						   	   	   Ray &lightRay,
						   	   	   Vector &normal);
};

#endif

