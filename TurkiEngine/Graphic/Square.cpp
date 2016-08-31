#include "Square.h"
namespace Turki
{

	Square::Square()
	{
	}

	Square::~Square()
	{
	}
	void Square::create(Shaders& drawShader, VertexArray& vao, mat4 pr_Mat, vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize)
	{
		m_Shader = &drawShader;
		vertexao = &vao;
		m_pr_Mat = pr_Mat;

		m_Position = position;
		m_Scale = scaleSize;
		m_Rotation = rotRoute;
		m_Angle = Angle;

		m_translation = m_translation.translation(position);
		m_rotation = m_rotation.rotation(Angle, rotRoute);


		//	scale = mat.scale(scaleSize);
		GLfloat verts[] = //2d 
		{
			0, 0, 0,
			0, scaleSize.y, 0,
			scaleSize.x, scaleSize.y, 0,
			scaleSize.x, 0, 0
		};
		GLfloat colorVerts[] = //2d color
		{
			0.4f ,0.5f, 0.0f,
			0.0f, 0.4f, 0.5f,
			0.0f, 0.2f, 0.0f,
			0.3f, 1.0f, 1.0f
		};
		GLushort indicies[] = { 0,1,2, 2,0,3 };

		Buffer* shape = new Buffer(3 * 4, 3, verts);
		vao.addVertex(shape, 0);
		Buffer* shapecolor = new Buffer(3 * 4, 3, colorVerts);
		vao.addVertex(shapecolor, 1);
		ibo = new IndexBuffer(3 * 2, 3, indicies);

	}
	void Square::draw(vec3 position, float Angle, vec3 rotRoute)
	{
		m_Position = position;
		m_Rotation = rotRoute;

		m_translation = m_translation.translation(position);
		m_rotation = m_rotation.rotation(Angle, rotRoute);

		m_Shader->UniformMatrix4("translation", m_translation * m_rotation);
		vertexao->bind();
		ibo->bind();
		glDrawElements(GL_TRIANGLES, ibo->IndexVertexArrayCount, GL_UNSIGNED_SHORT, 0);
		ibo->unbind();
		vertexao->unbind();
	}
}