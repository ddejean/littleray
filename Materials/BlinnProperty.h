#ifndef BLINNPHONGMATERIAL_H_
#define BLINNPHONGMATERIAL_H_

#include "MaterialProperty.h"

class BlinnProperty: public MaterialProperty {
private:
	double power;

public:
	BlinnProperty(double r, double g, double b, double p);
	virtual ~BlinnProperty(void) {};

	void apply(Pixel &in,
			   Ray &viewRay,
			   Light &light,
			   Ray &lightRay,
			   Vector &normal);
};

#endif /* PHONGBLINNMATERIAL_H_ */
