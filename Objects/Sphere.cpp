#include "Sphere.h"
#include "Object.h"
#include "Material.h"
#include <cmath>

Sphere::Sphere(Material *m, double x, double y, double z, double r):
        Object(m),
        center(x, y, z),
        radius(r) 
{
}

/* Recherche de l'intersection sphere/rayon */
bool Sphere::hit(Ray &r, double &t)
{
        Vector dist = this->center - r.origin; 
        double B = r.dir * dist;
        double delta = B*B - dist * dist + this->radius * this->radius; 
        if (delta < 0.0f) 
                return false; 
        double t0 = B - sqrtf(delta);
        double t1 = B + sqrtf(delta);

        if ((t0 > 0.1f) && (t0 < t)) {
                t = t0;
                return true; 
        } 
        if ((t1 > 0.1f) && (t1 < t)) {
                t = t1; 
                return true; 
        }
        return false; 
}

Vector Sphere::normal(Ray &r, double t)
{
        Point p;
        Vector n;
        double norm;

        /* Point de départ avec paramètre */
	n = r.dir * t;
        p = r.origin + n;

        /* Normale à l'intersection */
        n = p - this->center;

        /* Normalisation du vecteur n */
        norm = n.norm();
        if (norm == 0.0f) return Vector(0.0f, 0.0f, 0.0f);
        n = n * (1.0f /norm);

        return n;
}
