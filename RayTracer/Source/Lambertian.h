#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material
{
public:
	Lambertian(const Vector3D& albedo);

	virtual bool Scatter(const Ray& ray, const HitData& hitData, Vector3D& attenuation, Ray& scattered) const override;

private:
	Vector3D m_albedo;
};

#endif