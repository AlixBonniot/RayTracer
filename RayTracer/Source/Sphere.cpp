#include "Sphere.h"

Sphere::Sphere()
: m_center{}
, m_radius{ 0.0f }
{
}

Sphere::Sphere(const Vector3D& center, const float radius, std::shared_ptr<Material> material)
: m_center{ center }
, m_radius{ radius }
, m_material{ material }
{
}

bool Sphere::Hit(const Ray& ray, const float tMin, const float tMax, HitData& hitData) const
{
	// To test if we hit the sphere or not, we use
	// the equation of the sphere: https://www.kristakingmath.com/blog/center-radius-and-equation-of-the-sphere
	// Because our formula is quadratic, we then find the discriminant
	const Vector3D originCenter{ ray.GetOrigin() - m_center };
	const float a{ ray.GetDirection().LengthSquared() };
	const float halfB{ Vector3D::Dot(originCenter, ray.GetDirection()) };
	const float c{ originCenter.LengthSquared() - (m_radius * m_radius) };
	const float discriminant{ (halfB * halfB) - a * c };

	// Means that our equation has no solution, therefore the sphere has not been hit
	if (discriminant < 0.0f)
	{
		return false;
	}

	// We find a root that lies in the min-max range
	const float determinantSq{ sqrt(discriminant) };
	float root{ (-halfB - determinantSq) / a };
	if (root < tMin || tMax < root)
	{
		root = (-halfB + determinantSq) / a;
		if (root < tMin || tMax < root)
		{
			return false;
		}
	}

	// We compute the hit data
	hitData.t = root;
	hitData.point = ray.At(hitData.t);
	hitData.material = m_material;
	Vector3D outwardNormal{ (hitData.point - m_center) / m_radius };
	hitData.SetFaceNormal(ray, outwardNormal);
	return true;
}

const Vector3D& Sphere::GetCenter() const
{
	return m_center;
}

float Sphere::GetRadius() const
{
	return m_radius;
}
