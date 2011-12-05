#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include "Objects/Object.h"
#include "Materials/Material.h"
#include "Lights/Light.h"
#include "Display.h"
#include "Pixel.h"
#include "Antialiasers/Antialiaser.h"

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
                ~Scene(void);
                void addObject(Object *o);
                void addLight(Light *l);
                void addMaterial(Material *m);
                void render(Display *display);
        private:
                Pixel renderPixel(double x, double y);
};

#endif

