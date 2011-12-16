#ifndef TESTVECTOR_H_
#define TESTVECTOR_H_

#include "cxxtest/TestSuite.h"
#include "Maths/Vector.h"

class TestVector: public CxxTest::TestSuite {
private:
	Vector a, b, c;

public:
	void setUp(void);

	void testGetters(void);
	void testIsNull(void);
	void testNorm(void);
	void testMinusOperator(void);
	void testScalarMultiplication(void);
	void testVectorCreationFromPoints(void);
	void testMultiplyAdd(void);
};

#endif /* TESTVECTOR_H_ */
