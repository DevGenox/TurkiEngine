#include "ShapeGenerator.h"

namespace Turki
{
	ShapeGenerator::ShapeGenerator(Shaders& normShader, VertexArray& vao, mat4 pr_Mat)
	{
		m_Shader = &normShader;
		m_vao = &vao;
		m_pr_Mat = pr_Mat;
		normShader.UniformMatrix4("prMat", pr_Mat);
	}

	ShapeGenerator::~ShapeGenerator()
	{
	}
	Square ShapeGenerator::createSquare(vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize)
	{
		Square squ;
		squ.create(*m_Shader, *m_vao, m_pr_Mat, position, Angle, rotRoute, scaleSize);
		squ.dx = 1;
		squ.dy = 1;
		return squ;
	}
	Cube ShapeGenerator::createCube(vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize)
	{
		Cube cub;
		cub.create(*m_Shader, *m_vao, m_pr_Mat, position, Angle, rotRoute, scaleSize);
		cub.dx = 1;
		cub.dy = 1;
		return cub;
	}
}