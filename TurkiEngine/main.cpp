#include "Window/Window.h"
#include "Sound\SoundManager.h"
#include "ImageManager\ImageManager.h"
#include "Game.h"
#include "Math\Math.h"
#include "Graphic\Shaders.h"
#include "Graphic\Vertex.h"
#include "GL\glew.h"
#include "SDL.h"

int main(int argc, char* args[])
{
	using namespace Turki;
	setlocale(LC_ALL, "Turkish");
	Window window("Turki ENGINE", 1024, 768, false);
	SoundManager soundmgr;
	ImageManager imageMgr;
	Game game;

	Shaders shader("Graphic/simpleVert.vertexshader", "Graphic/simpleFrag.fragmentshader");

	mat4 mat;
	mat4 ortho;
	mat4 pers;
	mat4 translation;
	mat4 rotation;
	mat4 scale;


	ortho = mat.orthographic(0.0f, 36.0f, 0.0f, 30.0f, -1.0f, 1.0f);
	pers = mat.perspective(0.0f, 1.0f, 0.1f, 10.0f);

	translation = mat.translation(vec3(10, 2, 0));
	rotation = mat.rotation(-60, vec3(0, 0, -1));
	scale = mat.scale(vec3(1, 1, 0));

	shader.UniformMatrix4("prMat", ortho);
	shader.UniformMatrix4("translation", translation * rotation * scale);





	Vertex verts[] = //2d 
	{
		vec3(0, 0, 0),
		vec3(12, 0, 0),
		vec3(0, 6, 0),
		vec3(12, 6, 0)
	};
	VertexColor colorVerts[] = //2d color
	{
		vec3(0.4f ,0.5f, 0.0f),
		vec3(0.0f, 0.4f, 0.5f),
		vec3(0.0f, 0.2f, 0.0f),
		vec3(0.3f, 1.0f, 1.0f)
	};


	game.load(window.getRenderer());
	glClearColor(1, 0.5f, 1, 1);

	GLuint vao = 0;
	GLuint vbo;
	GLuint vboColor;
	GLuint buffer;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &vboColor);
	glBindBuffer(GL_ARRAY_BUFFER, vboColor);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorVerts), colorVerts, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vboColor);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	GLushort indicies[] = { 0,1,2, 2,1,3 };
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);





	GLuint lastTime = SDL_GetTicks();
	int nbFrames = 0;
	do {

		GLushort currentTime = SDL_GetTicks();
		nbFrames++;
		if (currentTime - lastTime >= 100.0) {

			printf("%f FPS\n", nbFrames * 1000.0 / (currentTime - lastTime));
			nbFrames = 0;
			lastTime = currentTime;
		}
		glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

		glBindVertexArray(vbo);
		glEnableVertexAttribArray(0);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
		SDL_GL_SwapWindow(window.getWindow());
		//	game.update();
	} while (window.running());

	system("pause");
	return 0;
}