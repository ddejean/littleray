#ifndef MATERIALPROPERTYFACTORY_H_
#define MATERIALPROPERTYFACTORY_H_

#include "MaterialProperty.h"
#include "xml/tinyxml.h"

class MaterialPropertyFactory {
public:
	/* Build a MaterialProperty from a property XML node */
	MaterialProperty* makeMaterialProperty(TiXmlNode *n);
};

#endif /* MATERIALPROPERTYFACTORY_H_ */
