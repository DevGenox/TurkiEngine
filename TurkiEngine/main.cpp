#include "Window/Window.h"
#include "Sound\SoundManager.h"
#include "ImageManager\ImageManager.h"
#include "Game.h"
#include "Math\Math.h"
#include "Graphic\Shaders.h"
#include "GL\glew.h"
#include "SDL.h"
#include "Graphic\Buffer.h"
#include "Graphic\Square.h"
#include "Graphic\IndexBuffer.h"
#include "Graphic\VertexArray.h"
#include "Graphic\ShapeGenerator.h"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
int main(int argc, char* args[])
{
	using namespace Turki;
	setlocale(LC_ALL, "Turkish");
	Window window("Turki ENGINE", WINDOW_WIDTH, WINDOW_HEIGHT, false);
	SoundManager soundmgr;
	ImageManager imageMgr;
	Game game;



	mat4 mat;
	mat4 ortho;
	mat4 pers;
	mat4 translation;
	mat4 rotation;
	mat4 scale;
	Shaders shader("Graphic/simpleVert.vertexshader", "Graphic/simpleFrag.fragmentshader");
	ortho = mat.orthographic(0.0f, 300.0f, 0.0f, 340.0f, -1.0f, 1.0f);
	pers = mat.perspective(45.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 10000.0f);

	translation = mat.translation(vec3(30, 15, 0));
	rotation = mat.rotation(-60, vec3(0, 0, -1));
	scale = mat.scale(vec3(1, 1, 0));

	mat4 alltranslation = translation * rotation *scale;



	game.load(window.getRenderer());
	glClearColor(1, 1, 1, 1);

	/*GLuint first = 0;
	ShapeGenerator gen;
	gen.createSquare(first,vec3(0,0,0) , alltranslation, ortho);*/




#if 0
	shader.UniformMatrix4("prMat", ortho);
	shader.UniformMatrix4("translation", alltranslation);

	GLfloat verts[] = //2d
	{
		0, 0, 0,
		12, 0, 0,
		0, 6, 0,
		12, 6, 0
	};
	GLfloat colorVerts[] = //2d color
	{
		0.4f ,0.5f, 0.0f,
		0.0f, 0.4f, 0.5f,
		0.0f, 0.2f, 0.0f,
		0.3f, 1.0f, 1.0f
	};


	GLuint vbo;
	GLuint vboColor;
	GLuint indexBufferID;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &vboColor);
	glBindBuffer(GL_ARRAY_BUFFER, vboColor);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorVerts), colorVerts, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, vboColor);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	GLushort indicies[] = { 0,1,2, 2,1,3 };

	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);
#elif 0

	shader.UniformMatrix4("prMat", ortho);
	shader.UniformMatrix4("translation", alltranslation);

	GLfloat verts[] = //2d 
	{
		0, 0, 0,
		12, 0, 0,
		0, 6, 0,
		12, 6, 0
	};
	GLfloat colorVerts[] = //2d color
	{
		0.4f ,0.5f, 0.0f,
		0.0f, 0.4f, 0.5f,
		0.0f, 0.2f, 0.0f,
		0.3f, 1.0f, 1.0f
	};
	GLushort indicies[] = { 0,1,2, 2,1,3 };
	VertexArray shapeVert;
	Buffer* shape = new Buffer(3 * 4, 3, verts);
	shapeVert.addVertex(shape, 0);
	Buffer* shapecolor = new Buffer(3 * 4, 3, colorVerts);
	shapeVert.addVertex(shapecolor, 1);





	IndexBuffer shapeInd(3 * 2, 3, indicies);
#elif 0
	VertexArray shapeVert;
	Square oha(shapeVert, ortho, vec3(10, 15, 0), -60, vec3(0, 0, -1), vec3(30, 30, 0));
	Square deneme(shapeVert, ortho, vec3(30, 15, 0), -30, vec3(0, 0, -1), vec3(30, 30, 0));
	shader.UniformMatrix4("prMat", ortho);
#elif 0
	VertexArray shapeVert;
	ShapeGenerator generator(shader, shapeVert, ortho);

	Square deneme = generator.createSquare(vec3(10, 15, 0), -60, vec3(0, 0, -1), vec3(30, 30, 0));
	Square oha = generator.createSquare(vec3(30, 15, 0), -30, vec3(0, 0, -1), vec3(30, 30, 0));
#elif 0
	int size = 0;
	VertexArray shapeVert;
	ShapeGenerator generator(shader, shapeVert, ortho);
	Square squares[1000];
#elif 1
	int size = 0;
	VertexArray shapeVert;
	ShapeGenerator generator(shader, shapeVert, pers);
	Square squares;
	squares = generator.createSquare(vec3(50, 50, 0), -30, vec3(0, 0, -1), vec3(2, 2, 0));
#endif

	GLuint lastTime = SDL_GetTicks();
	int nbFrames = 0;
	int angle = 0;

	do {
		/*GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout <<"Error : " << glewGetErrorString(error) << std::endl;
		}*/
		GLushort currentTime = SDL_GetTicks();
		nbFrames++;
		if (currentTime - lastTime >= 1000.0) {

			printf("%f FPS\n", nbFrames * 1000.0 / (currentTime - lastTime));
			nbFrames = 0;
			lastTime = currentTime;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#if 0 // very very very manual.No controller
		glBindVertexArray(vbo);
		glEnableVertexAttribArray(0);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

#elif 0 // no square class manual draw
		shapeVert.bind();
		shapeInd.bind();
		glDrawElements(GL_TRIANGLES, shapeInd.IndexVertexArrayCount, GL_UNSIGNED_SHORT, 0);
		shapeInd.unbind();
		shapeVert.unbind();
#elif 0 // no Shape Generator 
		
		angle++;
		if (angle == 360) angle = 0;
		deneme.draw(shader, vec3(50, 50, 0), -angle, vec3(0, 0, -1));
		oha.draw(shader, vec3(oha.m_Position.x + dx, oha.m_Position.y + dy, 0), -0, vec3(0, 0, -1));
		if (oha.m_Position.x >= 270 || oha.m_Position.x <= 0)
		{
			dx = -dx;
		}
		if (oha.m_Position.y >= 310 || oha.m_Position.y <= 0)
		{
			dy = -dy;
		}
#elif 0 // no Shape Generator 
		angle++;
		if (angle == 360) angle = 0;
		deneme.draw(vec3(50, 50, 0), -angle, vec3(0, 0, -1));
		oha.draw(vec3(oha.m_Position.x + dx, oha.m_Position.y + dy, 0), -0, vec3(0, 0, -1));
		if (oha.m_Position.x >= 270 || oha.m_Position.x <= 0)
		{
			dx = -dx;
		}
		if (oha.m_Position.y >= 310 || oha.m_Position.y <= 0)
		{
			dy = -dy;
		}
#elif 0 //Infinate(not infinate XD) squares by array
		int v1 = rand() % 1000 + 1;
		if (size != 999)
		{
			if (v1 == 5)
			{
				int px = rand() % 270 + 1;
				int py = rand() % 310 + 1;
				squares[size] = generator.createSquare(vec3(px, py, 0), -30, vec3(0, 0, -1), vec3(30, 30, 0));
				size++;

			}
		}
		for (int i = 0; i < size; i++)
		{
			
			squares[i].draw(vec3(squares[i].m_Position.x + squares[i].dx, squares[i].m_Position.y + squares[i].dy, 0), -0, vec3(0, 0, -1));
			if (squares[i].m_Position.x >= 270 || squares[i].m_Position.x <= 0)
			{
				squares[i].dx = -squares[i].dx;
			}
			if (squares[i].m_Position.y >= 310 || squares[i].m_Position.y <= 0)
			{
				squares[i].dy = -squares[i].dy;
			}
		}
	
#elif 1 //Perspective
		angle++;
		if (angle == 360) angle = 0;
		squares.draw(vec3(0, 0, -10), -angle, vec3(-1, 0, -0.5f));
#endif
		SDL_GL_SwapWindow(window.getWindow());

		game.update();
	} while (window.running());
	system("pause");
	return 0;
}