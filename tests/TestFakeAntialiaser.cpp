#include "TestFakeAntialiaser.h"
#include "Antialiaser/FakeAntialiaser.h"

void TestFakeAntialiaser::setUp()
{
	this->fake = new FakeAntialiaser();
}

void TestFakeAntialiaser::tearDown()
{
	delete this->fake;
}

void TestFakeAntialiaser::testFakeAntialiaser()
{
	TS_ASSERT_DIFFERS(this->fake, (void*)0);
}
