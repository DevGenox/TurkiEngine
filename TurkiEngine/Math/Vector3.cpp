#include "Vector3.h"
namespace Turki
{
	vec3::vec3()
	{

	}
	vec3::vec3(float vecX, float vecY, float vecZ)
	{
		x = vecX;
		y = vecY;
		z = vecZ;
	}
	vec3& vec3::operator+(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	vec3& vec3::operator-(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	vec3& vec3::operator*(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}
	vec3& vec3::operator/(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}
	void vec3::operator=(const vec3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	vec3& vec3::operator+=(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	vec3& vec3::operator-=(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	bool vec3::operator==(const vec3& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
	bool vec3::operator!=(const vec3& other)
	{
		return x != other.x && y != other.y && z != other.z;
	}
}