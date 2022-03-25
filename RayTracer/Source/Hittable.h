#ifndef HITTABLE_H
#define HITTABLE_H

/*** Abstract class for all objects that can be hit the ray ***/

#include "Ray.h"
#include "Vector3D.h"

class Material;

struct HitData
{
	Vector3D point;
	Vector3D normal;
	std::shared_ptr<Material> material;
	bool bFrontFace;
	float t;

	// Helper function that help to determine which side the ray is comming from
	void SetFaceNormal(const Ray& ray, const Vector3D& outwardNormal)
	{
		bFrontFace = (Vector3D::Dot(ray.GetDirection(), outwardNormal) < 0);
		normal = bFrontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual bool Hit(const Ray& ray, const float tMin, const float tMax, HitData& hitData) const = 0;
};

#endif