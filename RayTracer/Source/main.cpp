#include "HittableList.h"
#include "Sphere.h"
#include "Utility.h"

#include <iostream>


int main()
{
	/*** Image ***/

	// (16.0 / 9.0) aspect ratio
	constexpr float aspectRatio{ 2.33333f };
	constexpr int imageWidth{ 3440 };
	constexpr int imageHeight{ static_cast<int>(imageWidth / aspectRatio) };

	/*** World ***/
	HittableList world{};
	world.Add(std::make_shared<Sphere>(Sphere{ { 0.0f, 0.0f, -1.0f }, 0.5f }));
	world.Add(std::make_shared<Sphere>(Sphere{ { 0.0f, -100.5f, -1.0f }, 100.0f }));

	/*** Camera ***/
	const float viewportHeight{ 2.0f };
	const float viewportWidth{ aspectRatio * viewportHeight };

	// Distance between the projection point (camera)
	// and the projection view (viewport)
	const float focalLength{ 1.0f };

	Vector3D camera{};
	Vector3D horizontal{ viewportWidth, 0.0f, 0.0f };
	Vector3D vertical{ 0.0f, viewportHeight, 0.0f };
	Vector3D lowerLeftCorner{ (camera - (horizontal * 0.5f)).x, (camera - (vertical * 0.5f)).y, -focalLength };

	/*** Render ***/
	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (int column{ imageHeight - 1 }; column >= 0; --column)
	{
		std::cerr << "\rScanline remaining: " << column << ' ' << std::flush;
		for (int row{ 0 }; row < imageWidth; ++row)
		{
			float u{ float(row) / (imageWidth - 1) };
			float v{ float(column) / (imageHeight - 1) };

			const Ray ray{ camera, lowerLeftCorner + (u * horizontal) + (v * vertical) - camera };
			Vector3D pixel{ RayColor(ray, world) };
			WritePixel(std::cout, pixel);
		}
	}

	std::cerr << "\nDone\n";

	return 0;
}