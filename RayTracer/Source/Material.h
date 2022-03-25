#ifndef MATERIAL_H
#define MATERIAL_H

/***** Abstract class for all the material we will create *****/
#include "rtinc.h"

struct HitData;

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const HitData& hitData, Vector3D& attenuation, Ray& scattered) const = 0;
};

#endif