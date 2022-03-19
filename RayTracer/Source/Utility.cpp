#include "Utility.h"

// Function that write a pixel to the stream
// R, G, B varie from 0.0f to 1.0f and we convert them
// to 255 ASCII format
void WritePixel(std::ostream& out, const Vector3D& pixel)
{
	// Here X, Y and Z, replace the RGB value
	// because we are using a Vector3D
	// as Color data type
	out << static_cast<int>(255.999 * pixel.x) << ' '
		<< static_cast<int>(255.999 * pixel.y) << ' '
		<< static_cast<int>(255.999 * pixel.z) << '\n';
}

Vector3D RayColor(const Ray& ray)
{
	static const Vector3D sphereCenter{ 0.0f, 0.0f, -1.0f };
	float t{ HitSphere({ 0.0f, 0.0f, -1.0f }, 0.5f, ray) };
	if (t > 0.0f)
	{
		const Vector3D normal{ (ray.At(t) - sphereCenter).Normalize() };
		return Vector3D{ 0.5f * Vector3D{ normal.x + 1.0f, normal.y + 1.0f, normal.z + 1.0f } };
	}

	// White
	static const Vector3D startColor{ 1.0f, 1.0f, 1.0f };
	// Ligth blue
	static const Vector3D endColor{ 0.5f, 0.7f, 1.0f };
	static const Vector3D colorDifference{ endColor - startColor };


	Vector3D unit_vector{ ray.GetDirection().Normalize() };
	t = 0.5f * (unit_vector.y + 1.0f);

	// We use the linear interpolation equation
	// v0 + (v2 - v0) * alpha
	return startColor + colorDifference * t;
}

// To test if we hit the sphere or not, we use
// the equation of the sphere: https://www.kristakingmath.com/blog/center-radius-and-equation-of-the-sphere
// Because our formula is quadratic, we then find the discriminant
float HitSphere(const Vector3D& center, const float radius, const Ray& ray)
{
	const Vector3D originCenter{ ray.GetOrigin() - center };
	const float a{ ray.GetDirection().LengthSquared() };
	const float halfB{ Vector3D::Dot(originCenter, ray.GetDirection()) };
	const float c{ originCenter.LengthSquared() - (radius * radius)};
	const float discriminant{ (halfB * halfB) - a * c };

	if (discriminant < 0.0f)
	{
		return -1.0f;
	}
	
	return (-halfB - sqrt(discriminant)) / a;
}
