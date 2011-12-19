#ifndef FAKEDISPLAY_H_
#define FAKEDISPLAY_H_

#include "Display.h"

class FakeDisplay: public Display {
public:
	FakeDisplay(Scene *s);
	virtual ~FakeDisplay(void);
    void writePixel(int x, int y, Pixel *pixel);
    void refresh(void);
};

#endif /* FAKEDISPLAY_H_ */
