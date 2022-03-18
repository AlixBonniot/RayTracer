#include "Ray.h"

Ray::Ray()
: origin{}
, direction{}
{
}

Ray::Ray(const Vector3D& in_origin, const Vector3D& in_direction)
: origin{ in_origin }
, direction{ in_direction }
{
}

Vector3D Ray::at(const float t) const
{
	// We return a point along the ray based
	// on the function P(t) = A + tB, where
	// A is the origin and B is the direction
	return Vector3D{ origin + (t * direction) };
}
