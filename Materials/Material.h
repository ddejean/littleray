#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <iostream>
#include "Pixel.h"
#include "Ray.h"
#include "Light.h"

/*
 * Default material class, with simple Lambert behavior.
 */
class Material {
public:
	double red;
	double green;
	double blue;
	double reflection;

	Material(void);
	Material(double r, double g, double b, double refl);
	virtual ~Material(void) {};

	/*
	 * Apply light contribution from material, light and view ray to
	 * pixel using the Lambert property.
	 */
	virtual void lightContribution(Pixel &in,
						   	   	   Ray &viewRay,
						   	   	   Light &light,
						   	   	   Ray &lightRay,
						   	   	   Vector &normal);

	friend std::istream &operator>>(std::istream &inputFile, Material &m);
};

#endif

