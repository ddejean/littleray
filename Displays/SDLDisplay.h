#ifndef _SDLDISPLAY_H_
#define _SDLDISPLAY_H_

#include <SDL2/SDL.h>
#include "Display.h"

class SDLDisplay: public Display {
        private:
                int width;
                int height;
                SDL_Window *screen;
                SDL_Renderer *renderer;
                SDL_Texture *texture;
                SDL_PixelFormat *format;
                uint32_t *pixels;
                void waitForQuit(void);
        public:
                SDLDisplay(Scene *s);
                virtual ~SDLDisplay(void);
                void writePixel(int x, int y, Pixel *pixel);
                void refresh(void);
};

#endif
