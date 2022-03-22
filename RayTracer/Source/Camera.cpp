#include "Camera.h"

Camera::Camera(const float aspectRatio)
: m_origin{}
{
	const float viewportHeight{ 2.0f };
	const float viewportWidth{ aspectRatio * viewportHeight };

	// Distance between the projection point (camera)
	// and the projection view (viewport)
	const float focalLength{ 1.0f };
	m_horizontal = { viewportWidth, 0.0f, 0.0f };
	m_vertical = { 0.0f, viewportHeight, 0.0f };
	m_lowerLeftCorner = { (m_origin - (m_horizontal * 0.5f)).x, (m_origin - (m_vertical * 0.5f)).y, -focalLength };
}

Ray Camera::GetRay(const float u, const float v) const
{
	return { m_origin, m_lowerLeftCorner + (u * m_horizontal) + (v * m_vertical) - m_origin };
}
