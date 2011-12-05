#include "Supersampler4x.h"

Supersampler4x::Supersampler4x(void)
{
}

Supersampler4x::~Supersampler4x(void)
{
}

double Supersampler4x::stepX(void)
{
	return 0.5;
}

double Supersampler4x::stepY(void)
{
	return 0.5;
}

double Supersampler4x::begin(void)
{
	return -0.5;
}

double Supersampler4x::end(void)
{
	return 0.5;
}

double Supersampler4x::contribution(void)
{
	return 0.25;
}

