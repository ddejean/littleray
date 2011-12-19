#include <cmath>
#include <assert.h>
#include "Vector.h"


Vector::Vector(void) {
	this->coords[X] = 0.0f;
	this->coords[Y] = 0.0f;
	this->coords[Z] = 0.0f;
}

Vector::Vector(double x, double y, double z)
{
	this->coords[X] = x;
	this->coords[Y] = y;
	this->coords[Z] = z;
}

double Vector::getX(void) { return this->coords[X]; }
double Vector::getY(void) {	return this->coords[Y]; }
double Vector::getZ(void) {	return this->coords[Z]; }

bool Vector::isNull(void)
{
	return (this->coords[X] == 0.0f	&& this->coords[Y] == 0.0f && this->coords[Z] == 0.0f);
}

double Vector::norm(void)
{
	return std::sqrt(this->coords[X] * this->coords[X]
	               + this->coords[Y] * this->coords[Y]
	               + this->coords[Z] * this->coords[Z]);
}

Vector Vector::operator-(Vector v)
{
	Vector result = Vector(this->coords[X] - v.coords[X],
						   this->coords[Y] - v.coords[Y],
			               this->coords[Z] - v.coords[Z]);
	return result;
}

double Vector::operator*(Vector &v)
{
	return this->coords[X] * v.coords[X]
	     + this->coords[Y] * v.coords[Y]
	     + this->coords[Z] * v.coords[Z];
}

Vector Vector::operator*(double c)
{
	Vector result = Vector(this->coords[X] * c,
						   this->coords[Y] * c,
						   this->coords[Z] * c);
	return result;
}

Vector operator-(const Point &p1, const Point &p2)
{
	Vector v = Vector(
			p1.x - p2.x,
			p1.y - p2.y,
			p1.z - p2.z
	);
	return v;
}
