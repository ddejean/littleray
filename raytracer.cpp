#include <iostream>

#include "Point.h"
#include "Vector.h"
#include "Display.h"
#include "Scene.h"
#include "Ray.h"
#include "SceneFactory.h"

int main(int argc, char **argv)
{
        Display *display;
        SceneFactory *sceneFactory;
        Scene *scene;

        /* Allouer la scene et l'affichage */
        if (argc != 2) { 
                std::cout << "Error in program parameters." << std::endl;
                return EXIT_FAILURE;
        } else {
                sceneFactory = new SceneFactory();
                scene = sceneFactory->makeScene(argv[1]);
                display = new Display(scene);
                delete sceneFactory;
        }

        /* Rendu de l'image */
        scene->render(display);
        display->refresh();
        display->waitForQuit();

        /* Libération de mémoire */
        delete display;
        delete scene;

        return 0;
}

