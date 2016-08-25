#pragma once
namespace Turki
{
	struct vec4
	{

	public:
		vec4();
		vec4(float vecX, float vecY, float vecZ, float vecW);
		float x;
		float y;
		float z;
		float w;
	public:
		vec4& operator+(const vec4& other);
		vec4& operator-(const vec4& other);
		vec4& operator*(const vec4& other);
		vec4& operator/(const vec4& other);
		void operator=(const vec4& other);
		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);
	};
}