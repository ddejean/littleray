#ifndef OBJECT_H_
#define OBJECT_H_

#include <assert.h>
#include "Maths/Vector.h"
#include "Lights/Ray.h"
#include "Materials/Material.h"

class Object
{
public:
	Material *material;

	Object(Material *m) {
		assert(m != NULL);
		material = m;
	}
	virtual ~Object(void) {};

	virtual bool hit(Ray &r, double &t) = 0;
	virtual Vector normal(Ray &r, double t) = 0;
};

#endif /* OBJECT_H_ */
