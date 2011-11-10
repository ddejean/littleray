#include <assert.h>
#include "Supersampler16x.h"

#define X_MAX 	4
#define Y_MAX	4

static const double contributions[Y_MAX][X_MAX] = {
		{0.015625, 0.046875, 0.046875, 0.015625},
		{0.046875, 0.150625, 0.150625, 0.046875},
		{0.046875, 0.150625, 0.150625, 0.046875},
		{0.015625, 0.046875, 0.046875, 0.015625}
};

Supersampler16x::Supersampler16x():
	/* Supersampler value initializations */
	x(0),
	y(0)
{}

Supersampler16x::~Supersampler16x() {}

double Supersampler16x::stepX(void)
{
	this->x = (this->x < X_MAX-1) ? this->x + 1 : this->x;
	return 0.25;
}

double Supersampler16x::stepY(void)
{
	this->y = (this->y < Y_MAX-1) ? this->y + 1 : this->y;
	return 0.25;
}

double Supersampler16x::begin(void)
{
	return -0.875;
}

double Supersampler16x::end(void)
{
	return 0.875;
}

double Supersampler16x::contribution(void)
{
	assert(x < X_MAX && y < Y_MAX);
	return contributions[this->y][this->x];
}

