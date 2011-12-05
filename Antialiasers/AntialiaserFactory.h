#ifndef ANTIALIASERFACTORY_H_
#define ANTIALIASERFACTORY_H_

#include "Antialiaser.h"
#include "xml/tinyxml.h"

class AntialiaserFactory {
public:
	Antialiaser *makeAntialiaser(TiXmlNode *n);
};

#endif /* ANTIALIASERFACTORY_H_ */
