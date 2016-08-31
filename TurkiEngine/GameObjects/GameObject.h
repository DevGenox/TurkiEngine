#pragma once
#include <GL\glew.h>
#include "../Math/Math.h"
#include "../Graphic/Buffer.h"
#include "../Graphic/VertexArray.h"
#include "../Graphic/IndexBuffer.h"
#include "../Graphic/Shaders.h"
namespace Turki
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		Shaders* m_Shader;

		GLuint vbo;
		GLuint vboColor;
		GLuint indexBufferID;

		IndexBuffer* ibo;
		VertexArray* vertexao;
	public:
		vec3 m_Position;
		vec3 m_Scale;
		vec3 m_Rotation;
		float m_Angle;


		mat4 m_pr_Mat;
		mat4 m_translation;
		mat4 m_rotation;
		mat4 m_scale;

	};

}