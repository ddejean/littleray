#ifndef TESTFAKEANTIALIASER_H_
#define TESTFAKEANTIALIASER_H_

#include "cxxtest/TestSuite.h"
#include "Antialiaser/Antialiaser.h"

class TestFakeAntialiaser: public CxxTest::TestSuite {
private:
	Antialiaser *fake;
public:
	void setUp();
	void tearDown();

	void testFakeAntialiaser();
};

#endif /* TESTFAKEANTIALIASER_H_ */
