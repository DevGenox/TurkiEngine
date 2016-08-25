#pragma once
namespace Turki
{
	struct vec2
	{

	public:
		vec2();
		vec2(float vecX, float vecY);
		float x;
		float y;
	public:
		vec2& operator+(const vec2& other);
		vec2& operator-(const vec2& other);
		vec2& operator*(const vec2& other);
		vec2& operator/(const vec2& other);
		void operator=(const vec2& other);
		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		bool operator==(const vec2& other);
		bool operator!=(const vec2& other);
	};
}