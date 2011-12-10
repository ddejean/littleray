#include <assert.h>
#include <stdexcept>
#include "Antialiasers/AntialiaserFactory.h"
#include "SceneFactory.h"
#include "Materials/MaterialFactory.h"
#include "Objects/ObjectFactory.h"
#include "Lights/LightFactory.h"
#include "Xml/tinyxml.h"

void SceneFactory::loadObjects(Scene *s, TiXmlNode *n)
{
	assert(s != NULL);
	assert(n != NULL);

	for (TiXmlNode *node = n->FirstChild();
			node != NULL;
			node = node->NextSibling())
	{
		ObjectFactory oF;
		Object *o;

		o = oF.makeObject(s, node);
		assert(o != NULL);
		s->addObject(o);
	}
}

Antialiaser* SceneFactory::findAntialiaser(TiXmlNode *root)
{
	AntialiaserFactory aF;
	return aF.makeAntialiaser(root);
}

Scene *SceneFactory::makeScene(const std::string &sceneFile)
{
	int width, height;
	const char* title;
	TiXmlNode *root = NULL;
	TiXmlElement *elt = NULL;
	std::string nodeValue;
	Scene *s;

	/* Open the file */
	TiXmlDocument xmlInput(sceneFile.c_str());
	if (!xmlInput.LoadFile())
		throw std::runtime_error("Unable to load '" + sceneFile + "' scene file.");
	root = xmlInput.RootElement();
	assert(root != NULL);

	/* Check root tag value */
	elt = root->ToElement();
	nodeValue = elt->Value();
	if (nodeValue.compare("scene") != 0)
		throw std::runtime_error("Scene file parsing error: root tag must be '<scene ...>', found '"+nodeValue+"'");

	/* Parse scene configuration */
	elt->QueryIntAttribute("width", &width);
	elt->QueryIntAttribute("height", &height);
	title = elt->Attribute("title");
	s = new Scene(width, height, title, findAntialiaser(root));

	/* For each kind of child, use the appropriate factory */
	for (TiXmlNode *node = root->FirstChild();
			node != NULL;
			node = node->NextSibling())
	{
		elt = node->ToElement();
		if (!elt) {
			std::cout << "Invalid tag found in the XML scene file ('" << node->Value() << "')." << std::endl;
			throw std::runtime_error("Aborting scene file parsing.");
		}
		nodeValue = elt->Value();

		/* Call the right Factory */
		if (nodeValue.compare("material") == 0) {
			Material *m;
			MaterialFactory mF;

			m = mF.makeMaterial(node);
			assert(m != NULL);
			s->addMaterial(m);

		} else if (nodeValue.compare("objects") == 0) {
			this->loadObjects(s, node);

		} else if (nodeValue.compare("light") == 0) {
			Light *l;
			LightFactory lF;

			l = lF.makeLight(node);
			assert(l != NULL);
			s->addLight(l);

		} else {
			std::cout << "Invalid tag found in the XML scene file ('" << node->Value() << "')." << std::endl;
			throw std::runtime_error("Aborting scene file parsing.");
		}
	}

	return s;
}

