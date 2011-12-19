#ifndef _SDLDISPLAY_H_
#define _SDLDISPLAY_H_

#include <SDL/SDL.h>
#include "Display.h"

class SDLDisplay: public Display {
        private:
                SDL_Surface *screen;
                void waitForQuit(void);
        public:
                SDLDisplay(Scene *s);
                virtual ~SDLDisplay(void);
                void writePixel(int x, int y, Pixel *pixel);
                void refresh(void);
};

#endif
