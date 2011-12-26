#ifndef PIXEL_H_
#define PIXEL_H_

class Pixel
{
public:
	double red;
	double green;
	double blue;

	Pixel();
	Pixel(double r, double g, double b);
	unsigned char getRedOnByte(void);
	unsigned char getGreenOnByte(void);
	unsigned char getBlueOnByte(void);

private:
	unsigned char getColorToByte(double color);
};

#endif /* PIXEL_H_ */
