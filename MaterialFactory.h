#ifndef MATERIALFACTORY_H_
#define MATERIALFACTORY_H_

#include "Material.h"
#include "xml/tinyxml.h"

class MaterialFactory
{
public:
	/* Build a Material from a material XML Node */
	Material *makeMaterial(TiXmlNode *n);
};

#endif /* MATERIALFACTORY_H_ */
