#ifndef MATERIALPROPERTY_H_
#define MATERIALPROPERTY_H_

#include "Pixel.h"
#include "Ray.h"
#include "Light.h"
#include "Vector.h"

class MaterialProperty {
protected:
	double red;
	double green;
	double blue;

public:
	MaterialProperty(double r, double g, double b): red(r), green(g), blue(b) {};

	/*
	 * Apply light contribution from material, light and view ray to
	 * pixel using the Lambert then the Blinn-Phong properties.
	 */
	virtual void apply(Pixel &in,
	   	   	      	   Ray &viewRay,
	   	   	      	   Light &light,
	   	   	      	   Ray &lightRay,
	   	   	      	   Vector &normal) = 0;
};

#endif /* MATERIALPROPERTY_H_ */
