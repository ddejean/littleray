#include <stdexcept>
#include <assert.h>
#include "Material.h"
#include "Vector.h"

Material::Material(MaterialProperty *diff, MaterialProperty *spec, double refl):
	specular(spec),
	reflection(refl)
{
	if (diff == 0)
		throw std::runtime_error("The diffuse property of a material must be defined or the material will be invisible !");
	this->diffuse = diff;
}

Material::~Material(void)
{
	if (this->diffuse != 0)
		delete this->diffuse;
	if (this->specular != 0)
		delete this->specular;
}

void Material::lightContribution(Pixel &in,
					   	   	     Ray &viewRay,
					   	   	     Light &light,
					   	   	     Ray &lightRay,
					   	   	     Vector &normal)
{
	/* Apply diffuse surface effect */
	assert(this->diffuse != 0);
	this->diffuse->apply(in, viewRay, light, lightRay, normal);

	/* Apply specular effect if exists */
	if (this->specular != 0) {
		this->specular->apply(in, viewRay, light, lightRay, normal);
	}
}


