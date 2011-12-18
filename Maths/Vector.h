#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point.h"
#include <iostream>
#include <fstream>

class Vector {
private:
	enum {
		X = 0,
		Y = 1,
		Z = 2,
#if defined(AVX)
		PAD = 3,
#endif
		MAX
	};

#if defined(AVX)
	typedef double v4df __attribute__ ((__vector_size__(32)));
	union dtable {
		double t[MAX];	/* Coords table */
		v4df v;   /* Coords SIMD vector */
	} coords;
#else
	double coords[MAX];
#endif

public:
	Vector(void);
	Vector(double x, double y, double z);
	double getX(void);
	double getY(void);
	double getZ(void);
	bool isNull(void);
	double norm(void);
	Vector operator-(Vector v);
	double operator*(Vector &v);
	Vector operator*(double c);

};

Vector operator-(const Point &p1, const Point &p2);

#endif

