#pragma once
#include "GL\glew.h"
namespace Turki
{
	class IndexBuffer
	{
	public:
		IndexBuffer(GLsizei count, float vectorsize, GLushort* Data);
		~IndexBuffer();
		GLuint indexBufferID;
		float IndexVertexArrayCount;
		float IndexVectorSize;
		void bind();
		void unbind();
	private:

	};

	
}