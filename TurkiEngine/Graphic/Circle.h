#pragma once
#include <GL\glew.h>
#include "../Math/Math.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shaders.h"
namespace Turki
{
	class Circle
	{
	public:
		Circle(Shaders& normShader, VertexArray& vao, mat4 pr_Mat, vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize, GLfloat radius, GLint numberOfSides);
		~Circle();
		void draw(Shaders& drawShader, vec3 position, float Angle, vec3 rotRoute);
		GLuint vbo;
		GLuint vboColor;
		GLuint indexBufferID;

		IndexBuffer* ibo;
		VertexArray* vertexao;

		vec3 m_Position;
		vec3 m_Scale;
		vec3 m_Rotation;
		float m_Angle;


		mat4 m_pr_Mat;
		mat4 m_translation;
		mat4 m_rotation;
		mat4 m_scale;
	private:

	};


}
