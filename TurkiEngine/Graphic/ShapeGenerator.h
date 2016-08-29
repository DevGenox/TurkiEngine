#pragma once
#include "GL\glew.h"
#include "../Math/Math.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shaders.h"
#include <vector>
#include "Square.h"
#include "Circle.h"
namespace Turki
{
	class ShapeGenerator
	{
	public:
		ShapeGenerator(Shaders& normShader, VertexArray& vao, mat4 pr_Mat);
		~ShapeGenerator();
		Square createSquare(vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize);
		Shaders* m_Shader;
		VertexArray* m_vao;
		mat4 m_pr_Mat;
	private:

	};



}
