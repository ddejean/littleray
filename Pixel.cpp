#include <algorithm>
#include "Pixel.h"

Pixel::Pixel()
{
	this->red = 0.0f;
	this->green = 0.0f;
	this->blue = 0.0f;
}

Pixel::Pixel(double r, double g, double b)
{
	this->red   = r;
	this->green = g;
	this->blue  = b;
}

unsigned char Pixel::getColorToByte(double color)
{
	return (unsigned char) std::min(color * 255.0, 255.0);
}

unsigned char Pixel::getRedOnByte(void)
{
	return this->getColorToByte(this->red);
}

unsigned char Pixel::getGreenOnByte(void)
{
	return this->getColorToByte(this->green);
}

unsigned char Pixel::getBlueOnByte(void)
{
	return this->getColorToByte(this->blue);
}
