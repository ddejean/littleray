#include <stdexcept>
#include "Objects/SphereFactory.h"
#include "Objects/Sphere.h"
#include "Xml/tinyxml.h"

Sphere *SphereFactory::makeSphere(Scene *s, TiXmlNode *n)
{
        TiXmlElement *elt = NULL;
        std::string nodeValue;
        double x, y, z, radius;
        unsigned int mIndex;
        Material *m;

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

        /* Check the object type */
        assert(nodeValue.compare("sphere") == 0);

        /* Get sphere parameters */
        elt->QueryDoubleAttribute("x", &x);
        elt->QueryDoubleAttribute("y", &y);
        elt->QueryDoubleAttribute("z", &z);
        elt->QueryDoubleAttribute("radius", &radius);
        if (radius < 0.0f)
                throw std::range_error("Sphere radius must be greater than 0.");
        elt->QueryUnsignedAttribute("material", &mIndex);

        /* Get the corresponding material */
        m = s->materials[mIndex];
        if (!m) {
                std::cout << "Unavailable material "
                          << mIndex << ". "
                          << "Please verify that it is declared before the sphere which use it."
                          << std::endl;
                throw std::runtime_error("Unknow material.");
        }

        return new Sphere(m, x, y, z, radius);
}

