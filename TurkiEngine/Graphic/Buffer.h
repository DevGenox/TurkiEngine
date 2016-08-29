#pragma once
#include <GL\glew.h>
namespace Turki
{
	class Buffer
	{
	public:
		Buffer(GLsizei count, float vectorsize, GLfloat* Data);
		~Buffer();
		GLuint BufferID;
		GLsizei VertexArrayCount;
		float VectorSize;
		void bind();
		void unbind();
	private:

	};

	
}