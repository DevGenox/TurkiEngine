#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matris4.h"
#define _USE_MATH_DEFINES
#include <cmath>
namespace Turki
{
	inline float toRadians(float angle)
	{
		return (angle * ((float)M_PI / 180.0f));

	}
	inline vec3 normalize(vec3& theVec)
	{
		float length = sqrt(theVec.x * theVec.x + theVec.y * theVec.y + theVec.z * theVec.z);

		if (length != 0) {
			theVec.x = theVec.x / length;
			theVec.y = theVec.y / length;
			theVec.z = theVec.z / length;
		}
		return theVec;
	}
	inline vec3 cross(vec3 theVec,vec3 theother)
	{
		vec3 getThis;
		getThis.x = theVec.y * theother.z - theother.y * theVec.z;
		getThis.y = theVec.z * theother.x - theother.z * theVec.x;
		getThis.z = theVec.x * theother.y - theother.x * theVec.y;
		return getThis;
	}
	inline float dot(vec3 theVec, vec3 theother)
	{
		return theVec.x * theother.x + theVec.y * theother.y + theVec.z * theother.z;
	}
}