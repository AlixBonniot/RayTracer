#include "Ray.h"

Ray::Ray()
: m_origin{}
, m_direction{}
{
}

Ray::Ray(const Vector3D& in_origin, const Vector3D& in_direction)
: m_origin{ in_origin }
, m_direction{ in_direction }
{
}

Vector3D Ray::GetOrigin() const
{
	return m_origin;
}

Vector3D Ray::GetDirection() const
{
	return m_direction;
}

Vector3D Ray::At(const float t) const
{
	// We return a point along the ray based
	// on the function P(t) = A + tB, where
	// A is the origin and B is the direction
	return Vector3D{ m_origin + (t * m_direction) };
}
