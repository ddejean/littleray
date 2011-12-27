#include <getopt.h>
#include <stdexcept>

#include "ContextFactory.h"
#include "Displays/DisplayFactory.h"
#include "SceneFactory.h"

/* Program options */
static struct option long_options[] =
{
		{"display", 1, 0, 'd'},
		{"scene", 1, 0, 's'},
		{"help", 0, 0, 'h'},
		{NULL, 0, 0, 0}
};

void ContextFactory::help(void)
{
	std::cout << "Littleray: small C++ raytracer."<< std::endl;
	std::cout << "Options:"<< std::endl;
	std::cout << "\t--scene <file> \t\tmandatory, set the xml description file to use"<< std::endl;
	std::cout << "\t--display [none|sdl] \tdefines which kind of output the raytracer uses"<< std::endl;
}

Context* ContextFactory::makeContext(int argc, char **argv)
{
	int c, optindex;
	Display *display;
	Scene *scene;
	std::string *sceneName = 0,
			    *displayType = 0;

	while ((c = getopt_long(argc,
			                argv, "ds",
			                long_options,
			                &optindex)) != -1) {
		switch (c) {
		case 's':
			sceneName = new std::string(optarg);
			break;

		case 'd':
			displayType = new std::string(optarg);
			break;

		case 'h':
			this->help();
			return 0;
			break;

		default:
			std::cout << "Invalid option " << c << "." << std::endl;
			return 0;
			break;
		}
	}

	if (displayType == 0) {
		displayType = new std::string("sdl");
	}

	if (sceneName == 0) {
		std::cout << "--scene file switch is mandatory. Use --help for usage." << std::endl;
		throw std::runtime_error("Aborting argument parsing.");
	}

	SceneFactory sceneFactory;
	DisplayFactory displayFactory;
	scene = sceneFactory.makeScene(sceneName->c_str());
	display = displayFactory.makeDisplay(scene, displayType);

	delete sceneName;
	delete displayType;

	return new Context(scene, display);
}

