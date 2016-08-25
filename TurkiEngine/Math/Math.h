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
}