#include "Lambertian.h"
#include "Hittable.h"

Lambertian::Lambertian(const Vector3D& albedo)
: m_albedo{ albedo }
{
}

bool Lambertian::Scatter(const Ray& ray, const HitData& hitData, Vector3D& attenuation, Ray& scattered) const
{
	Vector3D scatterDirection{ hitData.normal + Vector3D::RandomHemisphere(hitData.normal) };
	// We catch degenerate scatter direction
	if (scatterDirection.NearZero())
	{
		scatterDirection = hitData.normal;
	}

	scattered = Ray{ hitData.point, scatterDirection };
	attenuation = m_albedo;
	return true;
}
