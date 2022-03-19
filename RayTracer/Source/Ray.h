#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"

class Ray
{
public:
	Ray();
	Ray(const Vector3D& in_origin, const Vector3D& in_direction);

	Vector3D GetOrigin() const;
	Vector3D GetDirection() const;

	Vector3D At(const float t) const;

private:
	Vector3D m_origin;
	Vector3D m_direction;
};

#endif