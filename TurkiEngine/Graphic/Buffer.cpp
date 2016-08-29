#include "Buffer.h"
namespace Turki
{
	Buffer::Buffer(GLsizei count, float vectorsize, GLfloat* Data)
	{
		VertexArrayCount = count;
		VectorSize = vectorsize;
		glGenBuffers(1, &BufferID);
		bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), Data, GL_STATIC_DRAW);
		unbind();
	}

	Buffer::~Buffer()
	{
	}
	void Buffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, BufferID);
	}
	void Buffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}