#include <iostream>
#include <fstream>
#include <assert.h>
#include <cmath>
#include "Scene.h"
#include "Point.h"
#include "Light.h"
#include "Ray.h"
#include "Object.h"
#include "Material.h"
#include "Sphere.h"

Scene::Scene(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Scene::addObject(Object *o)
{
	assert(o != NULL);
	this->objects.push_back(o);
}

void Scene::addLight(Light *l)
{
	assert(l != NULL);
	this->lights.push_back(l);
}

void Scene::addMaterial(Material *m)
{
	assert(m != NULL);
	this->materials.push_back(m);
}

Pixel Scene::renderPixel(int x, int y)
{
	Pixel pixel;
        int level = 0;
        Point start(double(x), double(y), -10000.0f);
        Vector v(0.0f, 0.0f, 1.0f);
        Vector n;
        Ray viewRay(start, v, 1.0f);

        do {
                double t = 20000.0f;
                Object *cObject = NULL;
                Material *m = NULL;

                /* Intersections avec les spheres */
                for (unsigned int i = 0; i < this->objects.size(); ++i) {
                        if (this->objects[i]->hit(viewRay, t)) {
                                cObject = this->objects[i];
                                // Avoir une référence sur un material
                		m = cObject->material;
                        }
                }

                if (cObject == NULL) break;

                /* Calculer le nouveau point de départ */
                start = viewRay.origin + (viewRay.dir * t);
                /* Calculer la normale au point d'intersection */
                n = cObject->normal(viewRay, t);
                if (n.isNull()) break;

                /* Calculer la valeur d'éclarage au point */
                for (unsigned int i = 0; i < this->lights.size(); i++) { // Et les itérateurs ?
                	Light *cLight = this->lights[i];
                	Vector distance = cLight->position - start;
                	Ray lightRay;
                	double norm;

                	/* Calcul du rayon de lumière */
                	norm = distance.norm();
                	if (n * distance <= 0.0f || norm <= 0.0f) continue;
                	lightRay.origin = start;
                	lightRay.dir = distance * (1.0f / norm);
                	lightRay.lightness = 1.0f;

                	/* Vérifier que la sphere n'est pas dans l'ombre*/
                	bool hidden = false;
                	for (unsigned int j = 0; j < this->objects.size(); j++) {
                		Object *o = this->objects[j];
                		if (o->hit(lightRay, norm)) {
                			hidden = true;
                			break;
                		}
                	}

                	/* Si elle est eclairée, calculer la luminosité */
                	if (!hidden) {
                		m->lightContribution(pixel, viewRay, *cLight, lightRay, n);
                	}
                }

                /* Atténuer la lumière d'autant que nécessaire */
                viewRay.lightness *= m->reflection;
                /* Préparer la prochaine reflexion */
                // TODO: ajouter une méthode d'application de l'atténuation au materiaux, ainsi il prend un rayon entrée et le modifie.
                double reflet = 2.0f * (viewRay.dir * n);
                viewRay.origin = start;
                viewRay.dir = viewRay.dir - (n * reflet);

                level++;
        } while (viewRay.isStillVisible() && level < 10);

	return pixel;
}

void Scene::render(Display *display)
{
	Pixel p;

        for (int y = 0; y < this->height; y++) {
                for (int x = 0; x < this->width; x++) {
                	p = this->renderPixel(x, y);
                	display->writePixel(x, y, &p);
               }
        }
}
