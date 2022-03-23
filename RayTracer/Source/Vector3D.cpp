#include "Vector3D.h"
#include "rtinc.h"

#include <cmath>

Vector3D::Vector3D()
: x{ 0.0f }
, y{ 0.0f }
, z{ 0.0f }
{
}

Vector3D::Vector3D(const float in_x, const float in_y, const float in_z)
: x{ in_x }
, y{ in_y }
, z{ in_z }
{
}

float Vector3D::LengthSquared() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3D::Length() const
{
	return sqrt(LengthSquared());
}

float Vector3D::Dot(const Vector3D& lhs, const Vector3D& rhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3D Vector3D::Cross(const Vector3D& lhs, const Vector3D& rhs)
{
	return 
	{
		(lhs.y * rhs.z) - (lhs.z * rhs.y),
		(lhs.z * rhs.x) - (lhs.x * rhs.z),
		(lhs.x * rhs.y) - (lhs.y * rhs.x)
	};
}

Vector3D& Vector3D::Normalize()
{
	const float vector_length{ Length() };
	if (vector_length < Config::epsilon)
	{
		return *this;
	}

	*this /= vector_length;
	return *this;
}

Vector3D Vector3D::GetNormalized() const
{
	return Vector3D{ *this }.Normalize();
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
	const float epsilon_squared{ Config::epsilon * Config::epsilon };
	if (difference.LengthSquared() < epsilon_squared)
	{
		return true;
	}

	return false;
}

bool Vector3D::operator!=(const Vector3D& rhs) const
{
	return !(*this == rhs);
}

Vector3D Vector3D::RandomVector()
{
	return Vector3D{ RandomFloat(), RandomFloat(), RandomFloat() };
}

Vector3D Vector3D::RandomVector(const float min, const float max)
{
	return Vector3D{ RandomFloat(min, max), RandomFloat(min, max), RandomFloat(min, max) };
}

Vector3D Vector3D::RandomUnitSphere()
{
	// This function will helps generate a diffuse material
	// First we pick a random point in a cube of -1.0f - 1.0f dimensions
	// Then we return it, if it's inside a unit sphere
	Vector3D point{};
	do
	{
		point = Vector3D::RandomVector(-1.0f, 1.0f);
	} while (point.LengthSquared() >= 1.0f);

	return point;
}

Vector3D Vector3D::RandomUnitSphereNormalized()
{
	return RandomUnitSphere().Normalize();
}

Vector3D Vector3D::RandomHemisphere(const Vector3D& normal)
{
	// We return point that are on the same hemisphere as the normal
	// This method is know as hemispherical scattering
	Vector3D point{ RandomUnitSphere() };
	if (Vector3D::Dot(point, normal) > 0.0f)
	{
		return point;
	}

	return -point;
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
