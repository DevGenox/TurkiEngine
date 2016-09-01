#include "Vector2.h"
namespace Turki
{
	vec2::vec2()
	{
		x = 0;
		y = 0;
	}
	vec2::vec2(float vecX, float vecY)
	{
		x = vecX;
		y = vecY;
	}
	vec2& vec2::operator+(const vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	vec2& vec2::operator-(const vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	vec2& vec2::operator*(const vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}
	vec2& vec2::operator/(const vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}
	void vec2::operator=(const vec2& other)
	{
		x = other.x;
		y = other.y;
	}
	vec2& vec2::operator+=(const vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	vec2& vec2::operator-=(const vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	bool vec2::operator==(const vec2& other)
	{
		return x == other.x && y == other.y;
	}
	bool vec2::operator!=(const vec2& other)
	{
		return x != other.x && y != other.y;
	}
}