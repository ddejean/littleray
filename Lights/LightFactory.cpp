#include <stdexcept>
#include "Light.h"
#include "LightFactory.h"
#include "Maths/Point.h"
#include "Xml/tinyxml.h"

Light *LightFactory::makeLight(TiXmlNode *n)
{
		Point p;
		double x, y, z;
		double r, g, b;
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
		assert(nodeValue.compare("light") == 0);

		elt->QueryDoubleAttribute("x", &x);
		elt->QueryDoubleAttribute("y", &y);
		elt->QueryDoubleAttribute("z", &z);

		elt->QueryDoubleAttribute("red", &r);
		if (r < 0.0f || r > 1.0f)
			throw std::range_error("Light: red parameter must be between 0.0 and 1.0.");

		elt->QueryDoubleAttribute("blue", &b);
		if (b < 0.0f || b > 1.0f)
			throw std::range_error("Light: blue parameter must be between 0.0 and 1.0.");

		elt->QueryDoubleAttribute("green", &g);
		if (g < 0.0f || g > 1.0f)
			throw std::range_error("Light: green parameter must be between 0.0 and 1.0.");

		p = Point(x, y, z);
		return new Light(p, r, g, b);
}
