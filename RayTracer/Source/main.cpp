#include "Utility.h"
#include "Vector3D.h"

#include <iostream>


int main()
{
	/*** Image ***/
	constexpr float aspect_ratio{ 16.0f / 9.0f };
	constexpr int image_width{ 1920 };
	constexpr int image_height{ static_cast<int>(image_width / aspect_ratio) };

	/*** Camera ***/
	const float viewport_height{ 2.0f };
	const float viewport_width{ aspect_ratio * viewport_height };

	// Distance between the projection point (camera)
	// and the projection view (viewport)
	const float focal_length{ 1.0f };

	Vector3D camera{ Vector3D::zero_vector };
	Vector3D horizontal{ viewport_width, 0.0f, 0.0f };
	Vector3D vertical{ 0.0f, viewport_height, 0.0f };
	Vector3D lower_left_corner{ (camera - (horizontal * 0.5f)).x, (camera - (vertical * 0.5f)).y, focal_length };

	/*** Render ***/
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int column{ image_height - 1 }; column >= 0; --column)
	{
		std::cerr << "\rScanline remaining: " << column << ' ' << std::flush;
		for (int row{ 0 }; row < image_width; ++row)
		{
			Vector3D pixel
			{
				float(row) / (image_width - 1),
				float(column) / (image_height - 1),
				0.25f
			};
			write_pixel(std::cout, pixel);
		}
	}

	std::cerr << "\nDone\n";

	return 0;
}