#include "SDLDisplay.h"
#include "Scene.h"
#include <assert.h>
#include <SDL2/SDL.h>

SDLDisplay::SDLDisplay(Scene *s)
{
	assert(s != NULL);

	SDL_Init(SDL_INIT_VIDEO);
    this->width = s->width;
    this->height = s->height;

    // Create the rendering context.
    this->screen = SDL_CreateWindow(s->title.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    s->width, s->height,
                                    SDL_WINDOW_OPENGL);
    this->renderer = SDL_CreateRenderer(this->screen, -1, 0);

    // Clean the screen.
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);

    // Prepare a texture to draw.
    this->texture = SDL_CreateTexture(renderer,
                                      SDL_PIXELFORMAT_ARGB8888,
                                      SDL_TEXTUREACCESS_STREAMING,
                                      s->width, s->height);
    this->format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    // Create a buffer to receive updates.
    this->pixels = new uint32_t[s->width * s->height];
}

SDLDisplay::~SDLDisplay(void)
{
	assert(this->screen != NULL);
	SDL_Quit();
}

void SDLDisplay::writePixel(int x, int y, Pixel *pixel)
{
	uint32_t color;

	assert(this->screen != NULL);
	assert(pixel != NULL);

	color = SDL_MapRGB(this->format,
			pixel->getRedOnByte(),
			pixel->getGreenOnByte(),
			pixel->getBlueOnByte());
	this->pixels[this->width * y + x] = color;
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
    SDL_UpdateTexture(this->texture, NULL, this->pixels, this->width * sizeof (uint32_t));
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
    SDL_RenderPresent(this->renderer);
	waitForQuit();
}


