#include "Metal.h"
#include "Hittable.h"

Metal::Metal(const Vector3D& albedo)
: m_albedo{ albedo }
{
}

bool Metal::Scatter(const Ray& ray, const HitData& hitData, Vector3D& attenuation, Ray& scattered) const
{
	const Vector3D reflected{ Vector3D::Reflect(ray.GetDirection().Normalize(), hitData.normal) };
	scattered = Ray{ hitData.point, reflected };
	attenuation = m_albedo;
	return (Vector3D::Dot(scattered.GetDirection(), hitData.normal) > 0);
}
