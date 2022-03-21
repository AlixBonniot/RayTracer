#ifndef RTINC_H
#define RTINC_H

/*** Utility header for include files, constants and utility functions ***/
#include <cmath>
#include <memory>
#include <limits>

namespace constants
{
	constexpr float pi{ 3.1415926535897932385f };
	constexpr float infinity{ std::numeric_limits<float>::infinity() };
}

float RadiansToDegrees(const float radians)
{
	return (radians * 180.0f) / constants::pi;
}

float DegreesToRadians(const float degrees)
{
	return (degrees * constants::pi) / 180.0f;
}

#include "Ray.h"
#include "Vector3D.h"

#endif