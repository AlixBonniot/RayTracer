#include "Camera.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Utility.h"
#include "rtinc.h"

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
	Camera camera{ aspectRatio };
	const int sample{ 50 };
	const int maxDepth{ 50 };

	/*** Render ***/
	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (int column{ imageHeight - 1 }; column >= 0; --column)
	{
		std::cerr << "\rScanline remaining: " << column << ' ' << std::flush;
		for (int row{ 0 }; row < imageWidth; ++row)
		{
			// Anti-alliasing process
			Vector3D pixel{};
			for (int i{ 0 }; i < sample; ++i)
			{
				// Based on the number of sample we want, we pick sample around the
				// pixel to generate a blended pixel of the colors around him
				float u{ (float(row) + RandomFloat()) / (imageWidth - 1)};
				float v{ (float(column) + RandomFloat()) / (imageHeight - 1)};

				const Ray ray{ camera.GetRay(u, v) };
				pixel += RayColor(ray, world, maxDepth);
			}

			WritePixel(std::cout, pixel, sample);
		}
	}

	std::cerr << "\nDone\n";

	return 0;
}