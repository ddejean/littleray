#include "TestPixel.h"

void TestPixel::setUp(void)
{
	p = Pixel(0.0, 0.0, 0.0);
}

void TestPixel::testColorToByte(void)
{
	unsigned char c;

	c = p.getBlueOnByte();
	TS_ASSERT_EQUALS(c, 0);
	c = p.getGreenOnByte();
	TS_ASSERT_EQUALS(c, 0);
	c = p.getRedOnByte();
	TS_ASSERT_EQUALS(c, 0);

	p = Pixel(0.25, 0.5, 1.0);
	c = p.getRedOnByte();
	TS_ASSERT_EQUALS(c, 63);
	c = p.getGreenOnByte();
	TS_ASSERT_EQUALS(c, 127);
	c = p.getBlueOnByte();
	TS_ASSERT_EQUALS(c, 255);
}
