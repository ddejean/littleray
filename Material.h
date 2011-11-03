#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <iostream>
#include "Pixel.h"
#include "Ray.h"
#include "Light.h"

class Material {
public:
	double red;
	double green;
	double blue;
	double reflection;

	Material(void);
	Material(double r, double g, double b, double refl);

	/*
	 * Apply light contribution from material, light and view ray to
	 * pixel using the material light properties.
	 */
	void lightContribution(Pixel &in,
						   Ray &viewRay,
						   Light &light,
						   Ray &lightRay,
						   Vector &normal);

	friend std::istream &operator>>(std::istream &inputFile, Material &m);
};

#endif

