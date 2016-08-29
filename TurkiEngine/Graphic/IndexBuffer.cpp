#include "IndexBuffer.h"
namespace Turki
{
	IndexBuffer::IndexBuffer(GLsizei count, float vectorsize, GLushort* Data)
	{
		IndexVertexArrayCount = count;
		IndexVectorSize = vectorsize;
		glGenBuffers(1, &indexBufferID);
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), Data, GL_STATIC_DRAW);
		unbind();
	}

	IndexBuffer::~IndexBuffer()
	{
	}
	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	}
	void IndexBuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}