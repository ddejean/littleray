#ifndef SPHEREFACTORY_H_
#define SPHEREFACTORY_H_

#include "Scene.h"
#include "Objects/Sphere.h"
#include "Xml/tinyxml.h"

class SphereFactory
{
public:
	/* Build a Material from a material XML Node */
	Sphere *makeSphere(Scene *s, TiXmlNode *n);
};

#endif
