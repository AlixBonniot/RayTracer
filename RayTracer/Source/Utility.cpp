#include "Utility.h"
#include "rtinc.h"

// Function that write a pixel to the stream
// R, G, B varie from 0.0f to 1.0f and we convert them
// to 255 ASCII format
void WritePixel(std::ostream& out, const Vector3D& pixel, const int sample)
{
	float r{ pixel.x };
	float g{ pixel.y };
	float b{ pixel.z };

	// We divide the color by the number of samples
	const float scale{ 1.0f / sample };
	r *= scale;
	g *= scale;
	b *= scale;

	// Here X, Y and Z, replace the RGB value
	// because we are using a Vector3D
	// as Color data type
	out << static_cast<int>(256 * Clamp(r, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * Clamp(g, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * Clamp(b, 0.0f, 0.999f)) << '\n';
}

Vector3D RayColor(const Ray& ray, const Hittable& world)
{
	// We check if we hit any object in the world
	HitData hitData{};
	if (world.Hit(ray, 0, constants::infinity, hitData))
	{
		return Vector3D{ 0.5f * (hitData.normal + Vector3D{ 1.0f, 1.0f, 1.0f }) };
	}

	// White
	static const Vector3D startColor{ 1.0f, 1.0f, 1.0f };
	// Ligth blue
	static const Vector3D endColor{ 0.5f, 0.7f, 1.0f };
	static const Vector3D colorDifference{ endColor - startColor };


	Vector3D unit_vector{ ray.GetDirection().Normalize() };
	const float t = 0.5f * (unit_vector.y + 1.0f);

	// We use the linear interpolation equation
	// v0 + (v2 - v0) * t
	return startColor + colorDifference * t;
}
