#include <cmath>
#include <assert.h>
#include "Vector.h"

/*** Arch-dependant includes ***/
#if defined(AVX)
#include <immintrin.h>
#endif


#if defined(AVX) /*** x86_64 with AVX vector implementation ***/

Vector::Vector(void) {
	this->coords.v = __builtin_ia32_xorpd256(this->coords.v, this->coords.v);
}

Vector::Vector(double x, double y, double z)
{
	this->coords.t[X] = x;
	this->coords.t[Y] = y;
	this->coords.t[Z] = z;
	this->coords.t[PAD] = 0.0f;
}

double Vector::getX(void) {	return this->coords.t[X]; }
double Vector::getY(void) {	return this->coords.t[Y]; }
double Vector::getZ(void) {	return this->coords.t[Z]; }

bool Vector::isNull(void)
{
	return (this->coords.t[X] == 0.0f
		 && this->coords.t[Y] == 0.0f
		 && this->coords.t[Z] == 0.0f);
}

double Vector::norm(void)
{
	union dtable product;
	double sum;

	product.v = __builtin_ia32_mulpd256(this->coords.v, this->coords.v);
	sum = product.t[X] + product.t[Y] + product.t[Z];

	return std::sqrt(sum);
}

Vector Vector::operator-(Vector v)
{
	Vector result;
	result.coords.v = __builtin_ia32_subpd256(this->coords.v, v.coords.v);
	return result;
}

double Vector::operator*(Vector &v)
{
	union dtable product;

	product.v = __builtin_ia32_mulpd256(this->coords.v, v.coords.v);

	return product.t[X] + product.t[Y] + product.t[Z];
}

Vector Vector::operator*(double c)
{
	Vector result = Vector(this->coords.t[X] * c,
						   this->coords.t[Y] * c,
						   this->coords.t[Z] * c);
	return result;
}

#else /*** Arch generic vector implementation ***/

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


#endif

/*** Fully generic implementation ***/

Vector operator-(const Point &p1, const Point &p2)
{
	Vector v = Vector(
			p1.x - p2.x,
			p1.y - p2.y,
			p1.z - p2.z
	);
	return v;
}
