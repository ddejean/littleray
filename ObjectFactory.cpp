#include <stdexcept>
#include "xml/tinyxml.h"
#include "Object.h"
#include "ObjectFactory.h"
#include "SphereFactory.h"

Object *ObjectFactory::makeObject(Scene *s, TiXmlNode *n)
{
        TiXmlElement *elt = NULL;
        std::string nodeValue;

        /* Get node information */
        elt = n->ToElement();
        if (!elt) {
		std::cout << "Invalid tag found in the XML scene file ('" 
                          << n->Value() 
                          << "')." 
                          << std::endl;
		throw std::runtime_error("Aborting scene initialization.");
	}
	nodeValue = elt->Value();

        if (nodeValue.compare("sphere") == 0) {
                SphereFactory sF;
                Sphere *sphere = sF.makeSphere(s, n);
                return (Object *)sphere;
        } else {
                std::cout << "Invalid object tag '"
                          << n->Value()
                          << "' found in the <objects> sequence." 
                          << std::endl;
                throw std::runtime_error("Aborting scene initialization.");
        }
        return NULL;
}
