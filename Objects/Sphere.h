#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <iostream>
#include <fstream>
#include "Point.h"
#include "Vector.h"
#include "Lights/Ray.h"
#include "Materials/Material.h"
#include "Objects/Object.h"

class Sphere : public Object {
        public:
                /* Attributes */
                Point center;
                double radius;

                /* TORS */
                Sphere(Material *m, double x, double y, double z, double r);
                virtual ~Sphere(void) {};

                /* Methods */
                bool hit(Ray &r, double &t);
                Vector normal(Ray &r, double t);

                /* Operators */
                friend std::istream &operator>>(std::istream &inputFile, Sphere &s);
};

#endif

