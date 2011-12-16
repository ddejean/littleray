#include "TestVector.h"

void TestVector::setUp(void)
{
	a = Vector(0.0, 0.0, 0.0);
	b = Vector(0.0, 0.0, 0.0);
	c = Vector(0.0, 0.0, 0.0);
}

void TestVector::testGetters(void)
{
	a = Vector(1.0, 2.0, 3.0);
	TS_ASSERT_EQUALS(1.0, a.getX());
	TS_ASSERT_EQUALS(2.0, a.getY());
	TS_ASSERT_EQUALS(3.0, a.getZ());
}

void TestVector::testIsNull(void)
{
	TS_ASSERT(a.isNull());

	a = Vector(5.0, 6.0, 7.0);
	TS_ASSERT(!(a.isNull()));
}

void TestVector::testNorm(void)
{
	a = Vector(1.0, 0.0, 0.0);
	b = Vector(0.0, 1.0, 0.0);
	c = Vector(0.0, 0.0, 1.0);

	TS_ASSERT_EQUALS(a.norm(), 1.0);
	TS_ASSERT_EQUALS(b.norm(), 1.0);
	TS_ASSERT_EQUALS(c.norm(), 1.0);

	a = Vector(-1.0, 0.0, 0.0);
	b = Vector(0.0, -1.0, 0.0);
	c = Vector(0.0, 0.0, -1.0);

	TS_ASSERT_EQUALS(a.norm(), 1.0);
	TS_ASSERT_EQUALS(b.norm(), 1.0);
	TS_ASSERT_EQUALS(c.norm(), 1.0);

	a = Vector(3.0, 4.0, 12.0);
	TS_ASSERT_EQUALS(a.norm(), 13.0);
}

void TestVector::testMinusOperator(void)
{
	b = Vector(2.0, 3.0, 4.0);
	c = Vector(4.0, 3.0, 2.0);
	a = b - c;

	TS_ASSERT_EQUALS(a.getX(), -2.0);
	TS_ASSERT_EQUALS(a.getY(), 0.0);
	TS_ASSERT_EQUALS(a.getZ(), 2.0);
}

void TestVector::testScalarMultiplication(void)
{
	double coef = 1.0;

	b = a * coef;
	TS_ASSERT(b.isNull());

	a = Vector(1.0, 1.0, 1.0);
	b = a * coef;
	TS_ASSERT_EQUALS(b.getX(), 1.0);
	TS_ASSERT_EQUALS(b.getY(), 1.0);
	TS_ASSERT_EQUALS(b.getZ(), 1.0);

	coef = 5.0;
	b = a * coef;
	TS_ASSERT_EQUALS(b.getX(), coef);
	TS_ASSERT_EQUALS(b.getY(), coef);
	TS_ASSERT_EQUALS(b.getZ(), coef);
}
