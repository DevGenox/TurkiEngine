#pragma once
#include "Vertex.h"
#include "GL\glew.h"
namespace Turki
{
	struct ShapeData
	{
		Vertex* verticies;
		GLuint numVertices;
		GLushort* indicies;
		GLuint numIndicies;
	};
}