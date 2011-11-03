#ifndef SCENEFACTORY_H_
#define SCENEFACTORY_H_

#include "Scene.h"
#include "xml/tinyxml.h"

class SceneFactory
{
private:
	void loadObjects(Scene *s, TiXmlNode *n);
public:
	/* Build a Scene from a scene file */
	Scene *makeScene(const std::string &sceneFile);
};

#endif /* SCENEFACTORY_H_ */
