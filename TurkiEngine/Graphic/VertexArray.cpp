#include "VertexArray.h"
namespace Turki
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayID);
	}

	VertexArray::~VertexArray()
	{
		for (int i=0; i < m_Buffer.size(); i++)
		{
			delete m_Buffer[i];
		}
	}
	void VertexArray::addVertex(Buffer* buffer, GLuint index)
	{

		bind();
		buffer->bind();
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->VectorSize, GL_FLOAT, GL_FALSE, 0, 0);
		buffer->unbind();
		unbind();

	}
	void VertexArray::bind()
	{
		glBindVertexArray( m_ArrayID);
	}
	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}
}