#include <assert.h>
#include <stdexcept>
#include "Xml/tinyxml.h"
#include "MaterialPropertyFactory.h"
#include "LambertProperty.h"
#include "PhongProperty.h"
#include "BlinnProperty.h"

MaterialProperty* MaterialPropertyFactory::makeMaterialProperty(TiXmlNode *n)
{
	double red, green, blue;
	TiXmlElement *elt = NULL;
	const char *type;

	assert(n != 0);
	elt = n->ToElement();
	type = elt->Attribute("type");
	std::string propertyType(type);

	elt->QueryDoubleAttribute("red", &red);
	elt->QueryDoubleAttribute("green", &green);
	elt->QueryDoubleAttribute("blue", &blue);

	if (propertyType.compare("lambert") == 0) {
		return new LambertProperty(red, green, blue);
	}
	else if (propertyType.compare("phong") == 0) {
		double power;
		elt->QueryDoubleAttribute("power", &power);
		return new PhongProperty(red, green, blue, power);
	}
	else if (propertyType.compare("blinn") == 0) {
		double power;
		elt->QueryDoubleAttribute("power", &power);
		return new BlinnProperty(red, green, blue, power);
	}
	else {
		throw std::runtime_error("Unknown property type specified in material.\nSupported types are lambert, phong and blinn.");
	}

	return 0;
}

