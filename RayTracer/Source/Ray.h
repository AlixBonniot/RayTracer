#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"

class Ray
{
public:
	Ray();
	Ray(const Vector3D& in_origin, const Vector3D& in_direction);

	Vector3D at(const float t) const;

private:
	Vector3D origin;
	Vector3D direction;
};

#endif