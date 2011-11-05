#include "Material.h"
#include "Vector.h"

Material::Material(void)
{
        this->red = 0.0f;
        this->green = 0.0f;
        this->blue = 0.0f;
        this->reflection = 0.0f;
}

Material::Material(double r, double g, double b, double refl)
{
        this->red = r;
        this->green = g;
        this->blue = b;
        this->reflection = refl;
}

void Material::lightContribution(Pixel &in,
					   	   	     Ray &viewRay,
					   	   	     Light &light,
					   	   	     Ray &lightRay,
					   	   	     Vector &normal)
{
		double lambert;

		lambert = (lightRay.dir * normal) * viewRay.lightness;
		in.red += lambert * light.red * this->red;
		in.green += lambert * light.green * this->green;
		in.blue += lambert * light.blue * this->blue;
}
std::istream &operator>>(std::istream &inputFile, Material &m)
{
        return inputFile >> m.red >> m.green >> m.blue >> m.reflection;
}

