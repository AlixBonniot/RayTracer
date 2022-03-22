#ifndef CAMERA_H
#define CAMERA_H

#include "rtinc.h"

class Camera
{
public:
	Camera(const float aspectRatio);

	Ray GetRay(const float u, const float v) const;

private:
	Vector3D m_origin;
	Vector3D m_horizontal;
	Vector3D m_vertical;
	Vector3D m_lowerLeftCorner;

};

#endif