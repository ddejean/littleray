#ifndef TESTPIXEL_H_
#define TESTPIXEL_H_

#include "cxxtest/TestSuite.h"
#include "Pixel.h"

class TestPixel: public CxxTest::TestSuite {
private:
	Pixel p;
public:
	void setUp(void);
	void testColorToByte(void);
};

#endif /* TESTPIXEL_H_ */
