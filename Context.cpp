#include <iostream>
#include <sys/time.h>

#include "Context.h"
#include "Scene.h"
#include "Displays/Display.h"

Context::Context(Scene *s, Display *d)
{
	this->scene = s;
	this->display = d;
}

Context::~Context(void)
{
	if (this->scene)
		delete this->scene;
	if (this->display)
		delete this->display;
}

void Context::render(void)
{
    /* Time evaluation */
    struct timeval before, after;
    double seconds, useconds;

    /* Render the picture */
    gettimeofday(&before, NULL);
    this->scene->render(this->display);
    gettimeofday(&after, NULL);

    seconds = (double) (after.tv_sec  - before.tv_sec);
    useconds = (double) (after.tv_usec - before.tv_usec);

    std::cout << "Rendering time: "
    		  << (seconds * 1000.0) + (useconds / 1000.0)
    		  << " ms.\n"
    		  << std::endl;

}

void Context::refresh(void)
{
    /* Display, this call may block */
    this->display->refresh();
}

