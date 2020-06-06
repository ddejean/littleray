#ifndef PHONGMATERIAL_H_
#define PHONGMATERIAL_H_

#include "MaterialProperty.h"

class PhongProperty: public MaterialProperty {
private:
	double power;

public:
	double specularValue;
	double specularPower;

	PhongProperty(double r, double g, double b, double p);
	virtual ~PhongProperty() {};

	void apply(Pixel &in,
			   Ray &viewRay,
			   Light &light,
			   Ray &lightRay,
			   Vector &normal);
};

#endif /* PHONGMATERIAL_H_ */
