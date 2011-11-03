#include <cmath>
#include "Vector.h"

Vector::Vector(void) {
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
}

Vector::Vector(double x, double y, double z)
{
        this->x = x;
        this->y = y;
        this->z = z;
}

double Vector::getX(void)
{
	return this->x;
}

double Vector::getY(void)
{
	return this->y;
}

double Vector::getZ(void)
{
	return this->z;
}

bool Vector::isNull(void)
{
	return (this->x == 0.0f	&& this->y == 0.0f && this->z == 0.0f);
}

double Vector::norm(void)
{
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector Vector::operator+(Vector &v)
{
        Vector result = Vector(this->x + v.x, this->y + v.y, this->z + v.z);
        return result;
}

Vector Vector::operator-(Vector v)
{
        Vector result = Vector(this->x - v.x, this->y - v.y, this->z - v.z);
        return result;
}

double Vector::operator*(Vector &v)
{
        return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::operator*(double c)
{
        Vector result = Vector(this->x * c, this->y * c, this->z * c);
        return result;
}

std::istream &operator>>(std::istream &inputFile, Vector &v)
{
        return inputFile >> v.x >> v.y >> v.z;
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

