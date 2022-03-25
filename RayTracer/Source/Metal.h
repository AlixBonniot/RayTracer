#ifndef METAL_H
#define METAL_H

#include "Material.h"

class Metal : public Material
{
public:
	Metal(const Vector3D& albedo);

	virtual bool Scatter(const Ray& ray, const HitData& hitData, Vector3D& attenuation, Ray& scattered) const override;

private:
	Vector3D m_albedo;
};

#endif