#pragma once
#include <math.h>
namespace Turki
{
	struct vec3
	{

	public:
		vec3();
		vec3(float vecX, float vecY,float vecZ);
		float x;
		float y;
		float z;
	public:
		vec3& operator+(const vec3& other);
		vec3& operator-(const vec3& other);
		vec3& operator*(const vec3& other);
		vec3& operator/(const vec3& other);
		void operator=(const vec3& other);
		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);


		void normalize();
	};
}