#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point.h"
#include <iostream>
#include <fstream>

class Vector {
private:
	double x;
	double y;
	double z;

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

