#include "ContextFactory.h"
#include "Displays/DisplayFactory.h"
#include "SceneFactory.h"

Context* ContextFactory::makeContext(int argc, char **argv)
{
	Display *display;
	Scene *scene;


	/* Create the scene and the screen */
	if (argc != 2) {
		std::cout << "Error in program parameters." << std::endl;
		return 0;
	} else {

		DisplayFactory displayFactory;
		SceneFactory sceneFactory;
		scene = sceneFactory.makeScene(argv[1]);
		display = displayFactory.makeDisplay(scene);
	}

	return new Context(scene, display);
}

