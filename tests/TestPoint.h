#ifndef TESTPOINT_H_
#define TESTPOINT_H_

#include "cxxtest/TestSuite.h"
#include "Maths/Point.h"

class TestPoint: public CxxTest::TestSuite {
private:
	Point a, b, c;

public:
	void setUp(void);

	void testEquals(void);
	void testPlus(void);
};

#endif /* TESTPOINT_H_ */
