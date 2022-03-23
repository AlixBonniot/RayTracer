#ifndef RTINC_H
#define RTINC_H

/*** Utility header for include files, constants and utility functions ***/
#include "Ray.h"
#include "Vector3D.h"

#include <cmath>
#include <memory>
#include <limits>
#include <random>

namespace constants
{
	inline constexpr float pi{ 3.1415926535897932385f };
	inline constexpr float infinity{ std::numeric_limits<float>::infinity() };
}

inline float RadiansToDegrees(const float radians)
{
	return (radians * 180.0f) / constants::pi;
}

inline float DegreesToRadians(const float degrees)
{
	return (degrees * constants::pi) / 180.0f;
}

inline float RandomFloat(const float min, const float max)
{
	static std::uniform_real_distribution<float> distribution{ min, max };
	static std::mt19937	generator{};
	return distribution(generator);
}

inline float RandomFloat()
{
	static std::uniform_real_distribution<float> distribution{ 0.0f, 1.0f };
	static std::mt19937	generator{};
	return distribution(generator);
}

inline float Clamp(const float x, const float min, const float max)
{
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

#endif