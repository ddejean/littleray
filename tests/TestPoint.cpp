#include "TestPoint.h"
#include "Maths/Vector.h"

void TestPoint::setUp(void)
{
	a = Point();
	b = Point();
	c = Point();
}

void TestPoint::testEquals(void)
{
	a = Point(1.0, 2.0, 3.0);

	TS_ASSERT_EQUALS(a, a);
	TS_ASSERT_EQUALS(b, b);
	TS_ASSERT_DIFFERS(a, b);
}

void TestPoint::testPlus(void)
{
	Vector v = Vector(1.0, 1.0, 1.0);
	Point a = Point(0.0, 0.0, 0.0);
	Point b = Point(2.0, 2.0, 2.0);

	c = a + v;
	TS_ASSERT_EQUALS(c, c);
	c = c + v;
	TS_ASSERT_EQUALS(c, b);
}
