#include <stdexcept>
#include "PhongMaterial.h"
#include "MaterialFactory.h"
#include "Material.h"
#include "xml/tinyxml.h"

Material *MaterialFactory::makeMaterial(TiXmlNode *n)
{
	double red, green, blue, reflection;
	const char *effectAttr = NULL;
	std::string *effect;
	TiXmlElement *elt = NULL;
	std::string nodeValue;

	/* Get node information */
	elt = n->ToElement();
	if (!elt) {
		std::cout << "Invalid tag found in the XML scene file ('" << n->Value() << "')." << std::endl;
		throw std::runtime_error("Aborting scene file parsing.");
	}
	nodeValue = elt->Value();

	/* Check it is really a material not, fail otherwise because of internal error */
	assert(nodeValue.compare("material") == 0);

	elt->QueryDoubleAttribute("red", &red);
	if (red < 0.0f || red > 1.0f)
		throw std::range_error("Material: red parameter must be between 0.0 and 1.0.");

	elt->QueryDoubleAttribute("blue", &blue);
	if (blue < 0.0f || blue > 1.0f)
		throw std::range_error("Material: blue parameter must be between 0.0 and 1.0.");

	elt->QueryDoubleAttribute("green", &green);
	if (green < 0.0f || green > 1.0f)
		throw std::range_error("Material: green parameter must be between 0.0 and 1.0.");

	elt->QueryDoubleAttribute("reflection", &reflection);
	if (reflection < 0.0f || reflection > 1.0f)
		throw std::range_error("Material: reflection parameter must be between 0.0 and 1.0.");

	/* Check material effects and allocate the right one */
	effectAttr = elt->Attribute("effect");
	if (effectAttr == 0)
		return new Material(red, green, blue, reflection);

	effect = new std::string(effectAttr);
	if (effect->compare("phong") == 0) {
		double specularValue, specularPower;

		elt->QueryDoubleAttribute("specular-value", &specularValue);
		elt->QueryDoubleAttribute("specular-power", &specularPower);

		delete effect;
		return (Material*) new PhongMaterial(red, green, blue, reflection, specularValue, specularPower);

	}

	std::cout << "Invalid material effect detected." << std::endl;
	delete effect;
	throw std::runtime_error("Aborting scene initialization.");
}



