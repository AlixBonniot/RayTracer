#include "Vector3D.h"

#include <cmath>

Vector3D Vector3D::zero_vector{ 0.0f, 0.0f, 0.0f };

Vector3D::Vector3D(const float in_x, const float in_y, const float in_z)
: x{ in_x }
, y{ in_y }
, z{ in_z }
{
}

float Vector3D::length_squared() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3D::length() const
{
	return sqrt(length_squared());
}

float Vector3D::dot_product(const Vector3D& lhs, const Vector3D& rhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3D Vector3D::cross_product(const Vector3D& lhs, const Vector3D& rhs)
{
	return 
	{
		(lhs.y * rhs.z) - (lhs.z * rhs.y),
		(lhs.z * rhs.x) - (lhs.x * rhs.z),
		(lhs.x * rhs.y) - (lhs.y * rhs.x)
	};
}

Vector3D& Vector3D::normalize()
{
	const float vector_length{ length() };
	if (vector_length < config::epsilon)
	{
		return *this;
	}

	*this /= vector_length;
	return *this;
}

Vector3D Vector3D::get_normalized() const
{
	return Vector3D{ *this }.normalize();
}

Vector3D Vector3D::operator-() const
{
	return { -x, -y, -z };
}

Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
	return Vector3D{ *this } += rhs;
}

Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
	return Vector3D{ *this } -= rhs;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vector3D& Vector3D::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3D Vector3D::operator/(const float scalar) const
{
	return Vector3D{ *this } /= scalar;
}

Vector3D& Vector3D::operator/=(const float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

bool Vector3D::operator==(const Vector3D& rhs) const
{
	Vector3D difference{ *this - rhs };
	// We use epsilon squared in order to avoid
	// the full length computation
	const float epsilon_squared{ config::epsilon * config::epsilon };
	if (difference.length_squared() < epsilon_squared)
	{
		return true;
	}

	return false;
}

bool Vector3D::operator!=(const Vector3D& rhs) const
{
	return !(*this == rhs);
}

Vector3D operator*(const Vector3D& vector, const float scalar)
{
	return Vector3D{ vector } *= scalar;
}

Vector3D operator*(const float scalar, const Vector3D& vector)
{
	return Vector3D{ vector } *= scalar;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vector)
{
	out << '(' << vector.x << ' ' << vector.y << ' ' << vector.z << ')';
	return out;
}
