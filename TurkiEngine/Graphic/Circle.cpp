#include "Circle.h"
namespace Turki
{
	Circle::Circle(Shaders& normShader, VertexArray& vao, mat4 pr_Mat, vec3 position, float Angle, vec3 rotRoute, vec3 scaleSize, GLfloat radius, GLint numberOfSides)
	{
		/*int numberOfVertices = numberOfSides + 2;

		GLfloat twicePi = 2.0f * M_PI;

		GLfloat circleVerticesX[numberOfVertices];
		GLfloat circleVerticesY[numberOfVertices];
		GLfloat circleVerticesZ[numberOfVertices];

		circleVerticesX[0] = x;
		circleVerticesY[0] = y;
		circleVerticesZ[0] = z;

		for (int i = 1; i < numberOfVertices; i++)
		{
			circleVerticesX[i] = x + (radius * cos(i *  twicePi / numberOfSides));
			circleVerticesY[i] = y + (radius * sin(i * twicePi / numberOfSides));
			circleVerticesZ[i] = z;
		}

		GLfloat allCircleVertices[(numberOfVertices) * 3];

		for (int i = 0; i < numberOfVertices; i++)
		{
			allCircleVertices[i * 3] = circleVerticesX[i];
			allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
			allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
		}*/

	}

	Circle::~Circle()
	{
	}
	void Circle::draw(Shaders& drawShader, vec3 position, float Angle, vec3 rotRoute)
	{
		m_Position = position;
		m_Rotation = rotRoute;

		m_translation = m_translation.translation(position);
		m_rotation = m_rotation.rotation(Angle, rotRoute);

		drawShader.UniformMatrix4("translation", m_translation * m_rotation);
		vertexao->bind();
		ibo->bind();
	//	glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
	//	glDrawElements(GL_TRIANGLES, ibo->IndexVertexArrayCount, GL_UNSIGNED_SHORT, 0);
		ibo->unbind();
		vertexao->unbind();
	}

}