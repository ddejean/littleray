#ifndef _RAY_H_
#define _RAY_H_

#include "Point.h"
#include "Vector.h"

class Ray {
        public:
        	double lightness;
                Point origin;
                Vector dir;

                Ray(void);
                Ray(Point &o, Vector &d, double lightness = 1.0f);
                bool isStillVisible(void);
};

#endif

