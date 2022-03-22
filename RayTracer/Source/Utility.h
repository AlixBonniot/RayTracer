#ifndef UTILITY_H
#define UTILITY_H

#include "HittableList.h"
#include "Ray.h"
#include "Vector3D.h"

#include <iostream>

void WritePixel(std::ostream& out, const Vector3D& pixel, const int sample);
Vector3D RayColor(const Ray& ray, const Hittable& world);

#endif