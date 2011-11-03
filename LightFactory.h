#ifndef LIGHTFACTORY_H_
#define LIGHTFACTORY_H_

#include "Light.h"
#include "xml/tinyxml.h"

class LightFactory {
public:
		Light *makeLight(TiXmlNode *n);
};

#endif /* LIGHTFACTORY_H_ */
