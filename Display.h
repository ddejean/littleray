#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <SDL/SDL.h>
#include "Pixel.h"

class Scene;

class Display {
        private:
                SDL_Surface *screen;
        public:
                Display(Scene *s);
                ~Display(void);
                void writePixel(int x, int y, Pixel *pixel);
                void refresh(void);
                void waitForQuit(void);
};

#endif

