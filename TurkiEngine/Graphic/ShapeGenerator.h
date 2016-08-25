#pragma once
#include "Vertex.h"
#include "ShapeData.h"
#include "../Math/Math.h"
namespace Turki
{
	class ShapeGenerator
	{
	public:
		ShapeGenerator();
		~ShapeGenerator();
		void createTriangle(vec3 position, mat4 translation, mat4 prMat);
	private:

	};



}
