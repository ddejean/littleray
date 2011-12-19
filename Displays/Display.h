#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Pixel.h"

class Scene;

class Display {
public:
    virtual ~Display(void) {};
    virtual void writePixel(int x, int y, Pixel *pixel) = 0;
    virtual void refresh(void) = 0;
};


#endif /* DISPLAY_H_ */
