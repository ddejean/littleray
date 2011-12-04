#include "TestAntialiaser.h"
#include "Antialiaser/FakeAntialiaser.h"
#include "Antialiaser/Supersampler4x.h"
#include "Antialiaser/Supersampler16x.h"

void TestAntialiaser::tearDown()
{
	delete this->fake;
	this->fake = 0;
}

void TestAntialiaser::testFakeAntialiaser()
{
	this->fake = new FakeAntialiaser();

	double begin = this->fake->begin();
	double end = this->fake->end();
	double cumul = 0.0;

	for (double deltay = begin; deltay < end; deltay += this->fake->stepY()) {
		for (double deltax = begin; deltax < end; deltax += this->fake->stepX()) {
			cumul += this->fake->contribution();
		}
	}
	TS_ASSERT_EQUALS(cumul, 1.0);
}

void TestAntialiaser::testAntialiaser4x(void)
{
	this->fake = new Supersampler4x();

	double begin = this->fake->begin();
	double end = this->fake->end();
	double cumul = 0.0;

	for (double deltay = begin; deltay < end; deltay += this->fake->stepY()) {
		for (double deltax = begin; deltax < end; deltax += this->fake->stepX()) {
			cumul += this->fake->contribution();
			TS_ASSERT_LESS_THAN_EQUALS(this->fake->contribution(), 0.25);
		}
	}
	TS_ASSERT_EQUALS(cumul, 1.0);
}

void TestAntialiaser::testAntialiaser16x(void)
{
	this->fake = new Supersampler16x();

	double begin = this->fake->begin();
	double end = this->fake->end();
	double cumul = 0.0;

	for (double deltay = begin; deltay < end; deltay += this->fake->stepY()) {
		for (double deltax = begin; deltax < end; deltax += this->fake->stepX()) {
			cumul += this->fake->contribution();
		}
	}
	TS_ASSERT_LESS_THAN(cumul, 1.3);
	TS_ASSERT_LESS_THAN(1.2, cumul);
}
