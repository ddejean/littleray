/*
 * LambertProperty.h
 *
 *  Created on: 28 nov. 2011
 *      Author: solarius
 */

#ifndef LAMBERTPROPERTY_H_
#define LAMBERTPROPERTY_H_

#include "MaterialProperty.h"

class LambertProperty: public MaterialProperty {
public:
	LambertProperty(double r, double g, double b);
	virtual ~LambertProperty(void) {};

	void apply(Pixel &in,
			   Ray &viewRay,
			   Light &light,
			   Ray &lightRay,
			   Vector &normal);
};

#endif /* LAMBERTPROPERTY_H_ */
