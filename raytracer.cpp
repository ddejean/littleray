#include <iostream>
#include <sys/time.h>

#include "Displays/Display.h"
#include "Displays/SDLDisplay.h"
#include "Scene.h"
#include "SceneFactory.h"
#include "Displays/DisplayFactory.h"

int main(int argc, char **argv)
{
        Display *display;
        Scene *scene;
        /* Time evaluation */
        struct timeval before, after;
        double seconds, useconds;


        /* Create the scene and the screen */
        if (argc != 2) { 
                std::cout << "Error in program parameters." << std::endl;
                return EXIT_FAILURE;
        } else {
        		DisplayFactory displayFactory;
                SceneFactory sceneFactory;
                scene = sceneFactory.makeScene(argv[1]);
                display = displayFactory.makeDisplay(scene);
        }

        /* Render the picture */
        gettimeofday(&before, NULL);
        scene->render(display);
        gettimeofday(&after, NULL);
        seconds = (double) (after.tv_sec  - before.tv_sec);
        useconds = (double) (after.tv_usec - before.tv_usec);

        std::cout << "Rendering time: "
        		  << (seconds * 1000.0) + (useconds / 1000.0)
        		  << " ms.\n"
        		  << std::endl;

        /* Display, this call may block */
        display->refresh();

        /* Free memory */
        delete display;
        delete scene;

        return 0;
}

