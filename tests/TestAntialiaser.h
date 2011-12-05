#ifndef TESTFAKEANTIALIASER_H_
#define TESTFAKEANTIALIASER_H_

#include "cxxtest/TestSuite.h"
#include "Antialiasers/Antialiaser.h"

class TestAntialiaser: public CxxTest::TestSuite {
private:
	Antialiaser *fake;
public:
	void tearDown();

	void testFakeAntialiaser(void);
	void testAntialiaser4x(void);
	void testAntialiaser16x(void);
};

#endif /* TESTFAKEANTIALIASER_H_ */
