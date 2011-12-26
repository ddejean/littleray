#include "Point.h"
#include "Vector.h"

Point::Point(void) {
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
}

Point::Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
}

Point Point::operator+(Vector v)
{
	 Point p = Point(
		      this->x + v.getX(), 
		      this->y + v.getY(),
		      this->z + v.getZ()
			);
	 return p;
}

bool Point::operator ==(const Point &p)
{
	return ((this->x == p.x)
		 && (this->y == p.y)
		 && (this->z == p.z));
}
