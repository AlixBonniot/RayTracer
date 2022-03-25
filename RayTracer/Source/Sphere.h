#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"

class Sphere : public Hittable
{
public:
	Sphere();
	Sphere(const Vector3D& center, const float radius, std::shared_ptr<Material> material);

	virtual bool Hit(const Ray& ray, const float tMin, const float tMax, HitData& hitData) const override;

	const Vector3D& GetCenter() const;
	float GetRadius() const;

private:
	Vector3D m_center;
	float m_radius;
	std::shared_ptr<Material> m_material;
};

#endif