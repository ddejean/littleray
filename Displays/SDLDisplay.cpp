#include "SDLDisplay.h"
#include "Scene.h"
#include <assert.h>
#include <SDL/SDL.h>

SDLDisplay::SDLDisplay(Scene *s)
{
	assert(s != NULL);

	SDL_Init(SDL_INIT_VIDEO);
	this->screen = SDL_SetVideoMode(
			s->width,
			s->height,
			32,
			SDL_HWSURFACE
	);
	SDL_WM_SetCaption(s->title.c_str(), NULL);
}

SDLDisplay::~SDLDisplay(void)
{
	assert(this->screen != NULL);
	SDL_Quit();
}

void SDLDisplay::writePixel(int x, int y, Pixel *pixel)
{
	uint32_t color;
	uint32_t *pixels;

	assert(this->screen != NULL);
	assert(pixel != NULL);

	color = SDL_MapRGB(this->screen->format,
			pixel->getRedOnByte(),
			pixel->getGreenOnByte(),
			pixel->getBlueOnByte());
	pixels = (uint32_t*)(this->screen->pixels);
	pixels[this->screen->w * y + x] = color;
}

void SDLDisplay::waitForQuit(void)
{
	SDL_Event event;

	while (event.type != SDL_QUIT)
		SDL_WaitEvent(&event);
}

void SDLDisplay::refresh(void)
{
	assert(this->screen != NULL);
	SDL_Flip(this->screen);
	waitForQuit();
}


