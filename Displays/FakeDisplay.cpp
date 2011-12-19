#include "FakeDisplay.h"

FakeDisplay::FakeDisplay(Scene *s) { (void)s; }

FakeDisplay::~FakeDisplay(void) {}

void FakeDisplay::writePixel(int x, int y, Pixel *pixel)
{
	(void)x;
	(void)y;
	(void)pixel;
}

void FakeDisplay::refresh(void) {}

