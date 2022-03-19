#ifndef UTILITY_H
#define UTILITY_H

#include "Ray.h"
#include "Vector3D.h"

#include <iostream>

void WritePixel(std::ostream& out, const Vector3D& pixel);
Vector3D RayColor(const Ray& ray);
float HitSphere(const Vector3D& center, const float radius, const Ray& ray);

#endif