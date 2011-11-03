#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <istream>

class Vector;

class Point {
        private:
                double x;
                double y;
                double z;

        public:
                Point(void);
                Point(double x, double y, double z);
                Point operator+(Vector v);
                friend Vector operator-(const Point &p1, const Point &p2);
                friend std::istream &operator>>(std::istream &inputFile, Point &p);
};


#endif

