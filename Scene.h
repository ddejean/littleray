#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include "Object.h"
#include "Material.h"
#include "Light.h"
#include "Display.h"
#include "Pixel.h"
#include "Antialiaser.h"

class Scene {
        public:
                int width;
                int height;
                std::string title;
                std::vector<Object*> objects;
                std::vector<Material*> materials;
                std::vector<Light*> lights;
                Antialiaser *antialiaser;

                Scene(int w, int h, std::string t, Antialiaser *al);
                void addObject(Object *o);
                void addLight(Light *l);
                void addMaterial(Material *m);
                void render(Display *display);
        private:
                Pixel renderPixel(double x, double y);
};

#endif

