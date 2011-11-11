#include <string>
#include <stdexcept>
#include "AntialiaserFactory.h"
#include "Antialiaser.h"
#include "Supersampler4x.h"
#include "Supersampler16x.h"

Antialiaser* AntialiaserFactory::makeAntialiaser(TiXmlNode *n)
{
	TiXmlElement *elt = 0;
	const char* sampler;

	assert(n != 0);

	elt = n->ToElement();
	sampler = elt->Attribute("antialiaser");

	if (sampler == 0)
		return new Supersampler4x();

	{
		std::string s(sampler);
		if (s.compare("16x") == 0)
			return new Supersampler16x();
		else if (s.compare("16x") == 0)
			return new Supersampler4x();
		else
			return new Supersampler4x();
	}
	/* Never happens */
	throw std::runtime_error("Bug in antialiaser factory !");
	return 0;
}

