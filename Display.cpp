#include "Display.h"
#include "Scene.h"
#include <assert.h>
#include <SDL/SDL.h>

Display::Display(Scene *s)
{
        assert(s != NULL);

        SDL_Init(SDL_INIT_VIDEO);
        this->screen = SDL_SetVideoMode(
                        s->width,
                        s->height,
                        32,
                        SDL_HWSURFACE
                       );
}

Display::~Display(void)
{
        assert(this->screen != NULL);
        SDL_Quit();
}

void Display::writePixel(int x, int y, Pixel *pixel)
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

void Display::refresh(void)
{
       assert(this->screen != NULL);
       SDL_Flip(this->screen); 
}

