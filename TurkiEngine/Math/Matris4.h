#pragma once
#include "Math.h"
namespace Turki
{
	struct mat4
	{

	public:
		mat4();
		mat4(float diognal);
		float nums[4 * 4];

		mat4& operator+(const mat4& other);
		mat4& operator-(const mat4& other);

		mat4 operator*(const mat4& right);

		mat4& multiply(const mat4& other);

		mat4 translation(const vec3& translation);
		mat4 rotation(const float angle, const vec3& axis);
		mat4 scale(const vec3& scale);
		mat4 perspective(float fov, float aspectRatio, float near, float far);
		mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
	};
}