#pragma once
#include <GL\glew.h>
#include "Buffer.h"
#include <vector>
namespace Turki
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
		void addVertex(Buffer* buffer, GLuint index);
		void bind();
		void unbind();
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffer;
	};

	
}
