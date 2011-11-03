#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_

#include "Scene.h"
#include "Object.h"
#include "xml/tinyxml.h"

class ObjectFactory
{
public:
	/* Build a Material from a material XML Node */
	Object *makeObject(Scene *s, TiXmlNode *n);
};

#endif
