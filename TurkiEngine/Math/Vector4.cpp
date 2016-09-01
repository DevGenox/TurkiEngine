#include "Vector4.h"
namespace Turki
{
	vec4::vec4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	vec4::vec4(float vecX, float vecY, float vecZ, float vecW)
	{
		x = vecX;
		y = vecY;
		z = vecZ;
		w = vecW;
	}
	vec4& vec4::operator+(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}
	vec4& vec4::operator-(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}
	vec4& vec4::operator*(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}
	vec4& vec4::operator/(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}
	void vec4::operator=(const vec4& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
	}
	vec4& vec4::operator+=(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}
	vec4& vec4::operator-=(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}
	bool vec4::operator==(const vec4& other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}
	bool vec4::operator!=(const vec4& other)
	{
		return x != other.x && y != other.y && z != other.z && w != other.w;
	}
}