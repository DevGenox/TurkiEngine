#pragma once
#include <GL\glew.h>
#include "../Math/Math.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shaders.h"
namespace Turki
{
	class Square
	{
	public:
		Square();
		~Square();
		void create(Shaders& drawShader, VertexArray& vao, mat4 pr_Mat, vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize);
		void draw(vec3 position, float Angle, vec3 rotRoute);

		Shaders* m_Shader;

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
		
		int dx = 1;
		int dy = 1;
	private:

	};

	
}