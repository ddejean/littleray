#ifndef _RAY_H_
#define _RAY_H_

#include "Maths/Point.h"
#include "Maths/Vector.h"

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

