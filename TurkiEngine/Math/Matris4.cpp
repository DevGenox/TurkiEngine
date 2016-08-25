#include "Matris4.h"
namespace Turki
{
	mat4::mat4()
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			nums[i] = 0.0f;
		}
	}
	mat4::mat4(float diognal)
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			nums[i] = 0.0f;
		}
			nums[4 * 0] = diognal;
			nums[4 * 1 + 1] = diognal;
			nums[4 * 2 + 2] = diognal;
			nums[4 * 3 + 3] = diognal;
	}
	mat4& mat4::operator+(const mat4& other)
	{
		for (int i = 0; i < 16; i++)
		{
			nums[i] += other.nums[i];
		}
		return *this;
	}

	mat4& mat4::operator-(const mat4& other)
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			nums[i] -= other.nums[i];
		}
		return *this;
	}
	mat4 mat4::operator*(const mat4& right)
	{
		return multiply(right);
	}
	mat4& mat4::multiply(const mat4& other)
	{
		mat4 mat;
		for (int c = 0; c < 4; c++)
		{
			for (int r = 0; r < 4; r++)
			{
				float sum = 0.0f;
				for (int o = 0; o < 4; o++)
				{
					sum += nums[4 * o + c] * other.nums[4 * r + o];
				}
				mat.nums[4 * r + c] = sum;
			}
		}
		for (int i = 0; i < 4 * 4; i++)
		{
			nums[i] = mat.nums[i];
		}
		return *this;
	}
	mat4 mat4::translation(const vec3& translation)
	{
		mat4 mat(1);

		mat.nums[4 * 3 + 0] = translation.x;
		mat.nums[4 * 3 + 1] = translation.y;
		mat.nums[4 * 3 + 2] = translation.z;

		return mat;
	}
	mat4 mat4::scale(const vec3& scale)
	{
		mat4 mat(1);

		mat.nums[4 * 0 + 0] = scale.x;
		mat.nums[4 * 1 + 1] = scale.y;
		mat.nums[4 * 2 + 2] = scale.z;

		return mat;
	}
	mat4 mat4::rotation(const float angle, const vec3& axis)
	{
		mat4 mat(1);

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		float r = toRadians(angle);

		float c = cos(r);
		float s = sin(r);

		float mc = 1 - c;

		mat.nums[4 * 0 + 0] = (x * x * mc) + c;
		mat.nums[4 * 0 + 1] = (x * y * mc) + (z * s);
		mat.nums[4 * 0 + 2] = (x * z * mc) - (y * s);

		mat.nums[4 * 1 + 0] = (x * y * mc) - (z * s);
		mat.nums[4 * 1 + 1] = (y * y * mc) + c;
		mat.nums[4 * 1 + 2] = (y * z * mc) + (x * s);

		mat.nums[4 * 2 + 0] = (x * z * mc) + (y * s);
		mat.nums[4 * 2 + 1] = (y * z * mc) - (x * s);
		mat.nums[4 * 2 + 2] = (z * z * mc) + c;

		return mat;
	}
	mat4 mat4::perspective(float fov, float aspectRatio,float near, float far)
	{
		mat4 mat(1);

		float tov = 1 / tan(toRadians(fov / 2));
		float atov = tov / aspectRatio;



		mat.nums[4 * 0 + 0] = atov;
		mat.nums[4 * 1 + 1] = tov;
		mat.nums[4 * 2 + 2] = -(far + near) / (far - near);
		mat.nums[4 * 2 + 3] = -1;
		mat.nums[4 * 3 + 2] = (-2 * far * near) / (far - near);


		return mat;
	}
	mat4 mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
	{
		mat4 mat(1.0f);

		mat.nums[4 * 0 + 0] = 2.0f / (right - left);

		mat.nums[4 * 1 + 1] = 2.0f / (top - bottom);

		mat.nums[4 * 2 + 2] = 2.0f / (near - far);

		mat.nums[4 * 3 + 0] = (left + right) / (left - right);
		mat.nums[4 * 3 + 1] = (bottom + top) / (bottom - top);
		mat.nums[4 * 3 + 2] = (far + near) / (far - near);

		return mat;
	}


}