#include "FakeAntialiaser.h"

FakeAntialiaser::FakeAntialiaser() {}

FakeAntialiaser::~FakeAntialiaser() {}


double FakeAntialiaser::stepX(void)
{
	return 1.0;
}

double FakeAntialiaser::stepY(void)
{
	return 1.0;
}

double FakeAntialiaser::begin(void)
{
	return 0.0;
}

double FakeAntialiaser::end(void)
{
	return 1.0;
}

double FakeAntialiaser::contribution(void)
{
	return 1.0;
}
