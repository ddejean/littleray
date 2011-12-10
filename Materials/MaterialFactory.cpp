#include <stdexcept>
#include "Material.h"
#include "MaterialProperty.h"
#include "MaterialFactory.h"
#include "MaterialPropertyFactory.h"
#include "Xml/tinyxml.h"

Material *MaterialFactory::makeMaterial(TiXmlNode *n)
{
	double reflection;
	MaterialProperty *diffuse = 0;
	MaterialProperty *specular = 0;
	MaterialPropertyFactory mFP;
	TiXmlElement *elt = NULL;
	std::string nodeValue;

	/* Get node information */
	elt = n->ToElement();
	if (!elt) {
		std::cout << "Invalid tag found in the XML scene file ('" << n->Value() << "')." << std::endl;
		throw std::runtime_error("Aborting scene file parsing.");
	}
	nodeValue = elt->Value();

	/* Check it is really a material, fail otherwise because of internal error */
	assert(nodeValue.compare("material") == 0);

	elt->QueryDoubleAttribute("reflection", &reflection);
	if (reflection < 0.0f || reflection > 1.0f)
		throw std::range_error("Material: reflection parameter must be between 0.0 and 1.0.");

	/* For each kind of child, use the appropriate factory */
	for (TiXmlNode *node = n->FirstChild();
			node != NULL;
			node = node->NextSibling())
	{
		elt = node->ToElement();
		if (!elt) {
			std::cout << "Invalid tag found in the XML scene file ('" << node->Value() << "')." << std::endl;
			throw std::runtime_error("Aborting scene file parsing.");
		}
		nodeValue = elt->Value();

		if (nodeValue.compare("diffuse") == 0) {
			diffuse = mFP.makeMaterialProperty(node);

		}
		else if (nodeValue.compare("specular") == 0) {
			specular = mFP.makeMaterialProperty(node);
		}
		else {
			std::cout << "Invalid tag found in the XML scene file ('" << node->Value() << "')." << std::endl;
			throw std::runtime_error("Aborting scene file parsing.");
		}
	}
	if (diffuse != 0) {
		return new Material(diffuse, specular, reflection);
	} else {
		std::cout << "A material must have a diffuse property." << std::endl;
		throw std::runtime_error("Aborting scene creation.");
	}
}



