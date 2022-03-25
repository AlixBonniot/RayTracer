#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

namespace config
{
	static constexpr float epsilon{ 1e-8f };
}

class Vector3D
{
public:
	Vector3D();
	Vector3D(const float in_x, const float in_y, const float in_z);

	float LengthSquared() const;
	float Length() const;

	static float Dot(const Vector3D& lhs, const Vector3D& rhs);
	static Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs);

	Vector3D& Normalize();
	Vector3D GetNormalized() const;

	Vector3D operator-() const;

	Vector3D operator+(const Vector3D& rhs) const;
	Vector3D& operator+=(const Vector3D& rhs);
	Vector3D operator-(const Vector3D& rhs) const;
	Vector3D& operator-=(const Vector3D& rhs);
	Vector3D& operator*=(const float scalar);
	Vector3D operator/(const float scalar) const;
	Vector3D& operator/=(const float scalar);

	bool operator==(const Vector3D& rhs) const;
	bool operator!=(const Vector3D& rhs) const;

	static Vector3D RandomVector();
	static Vector3D RandomVector(const float min, const float max);

	// Used for diffuse material
	static Vector3D RandomUnitSphere();
	static Vector3D RandomUnitSphereNormalized();
	static Vector3D RandomHemisphere(const Vector3D& normal);

	// Used for metallic material
	static Vector3D Reflect(const Vector3D& v, const Vector3D& n);

	bool NearZero() const;

public:
	float x;
	float y;
	float z;
};

Vector3D operator*(const Vector3D& vector, const float scalar);
Vector3D operator*(const float scalar, const Vector3D& vector);
Vector3D operator*(const Vector3D& rhs, const Vector3D& lhs);

std::ostream& operator<<(std::ostream& out, const Vector3D& vector);

#endif