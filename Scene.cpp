#include <iostream>
#include <fstream>
#include <assert.h>
#include <cmath>
#include "Scene.h"
#include "Point.h"
#include "Lights/Light.h"
#include "Lights/Ray.h"
#include "Objects/Object.h"
#include "Materials/Material.h"
#include "Objects/Sphere.h"

Scene::Scene(int w, int h, std::string t, Antialiaser *al)
{
	this->width = w;
	this->height = h;
	this->title = t;
	this->antialiaser = al;
}

Scene::~Scene(void)
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
		delete this->objects[i];
	this->objects.clear();

	for (unsigned int i = 0; i < this->materials.size(); i++)
		delete this->materials[i];
	this->materials.clear();

	for (unsigned int i = 0; i < this->lights.size(); i++)
		delete this->lights[i];
	this->lights.clear();
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

Pixel Scene::renderPixel(double x, double y)
{
	Pixel pixel;
	int level = 0;
	Point start(x, y, -10000.0f);
	Vector v(0.0f, 0.0f, 1.0f);
	Vector n;
	Ray viewRay(start, v, 1.0f);

	do {
		double t = 20000.0f;
		Object *cObject = NULL;
		Material *m = NULL;

		/* Find a meeting point with the objects */
		for (unsigned int i = 0; i < this->objects.size(); ++i) {
			if (this->objects[i]->hit(viewRay, t)) {
				cObject = this->objects[i];
				m = cObject->material;
			}
		}

		if (cObject == NULL) break;

		/* New start point */
		start = viewRay.origin + (viewRay.dir * t);
		/* Compute the normal vector at intersection point */
		n = cObject->normal(viewRay, t);
		if (n.isNull()) break;

		/* Light contribution at this point */
		for (unsigned int i = 0; i < this->lights.size(); i++) {
			Light *cLight = this->lights[i];
			Vector distance = cLight->position - start;
			Ray lightRay;
			double norm;

			/* Compute the ray from the light source*/
			norm = distance.norm();
			if (n * distance <= 0.0f || norm <= 0.0f) continue;
			lightRay.origin = start;
			lightRay.dir = distance * (1.0f / norm);
			lightRay.lightness = 1.0f;

			/* Check the object is not hidden by another */
			bool hidden = false;
			for (unsigned int j = 0; j < this->objects.size(); j++) {
				Object *o = this->objects[j];
				if (o->hit(lightRay, norm)) {
					hidden = true;
					break;
				}
			}

			/* Compute light if needed */
			if (!hidden) {
				m->lightContribution(pixel, viewRay, *cLight, lightRay, n);
			}
		}

		/* Decrease the light due to absorption  */
		viewRay.lightness *= m->reflection;
		/* Prepare the next ray travel */
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
	for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++) {

			Pixel p(0.0, 0.0, 0.0);
			Pixel parcel(0.0, 0.0, 0.0);
			double begin = this->antialiaser->begin();
			double end = this->antialiaser->end();

			for (double deltay = (double)y + begin; deltay < (double)y + end; deltay += this->antialiaser->stepY()) {
				for (double deltax = (double)x + begin; deltax < (double)x + end; deltax += this->antialiaser->stepX()) {

					/* For each supplementary pixel, contribute to the final one
					 * with a position-dependant coefficient.
					 */
					double contribution = this->antialiaser->contribution();
					parcel = this->renderPixel(deltax, deltay);
					p.blue += contribution * parcel.blue;
					p.red += contribution * parcel.red;
					p.green += contribution * parcel.green;
				}
			}

			display->writePixel(x, y, &p);
		}
	}
}
