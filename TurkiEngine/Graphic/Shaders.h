#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "GL\glew.h"
#include <SDL.h>
#include "../Math/Math.h"
namespace Turki
{
	class Shaders
	{
	public:
		Shaders(const char* vertexPath, const char* fragmentPath);
		~Shaders();
		GLuint programID;
		GLuint loadShaders(const char* vertexPath, const char* fragmentPath);
		GLint GetUniformLocation(const GLchar* name);
		void Uniform1f(const GLchar* name, const GLfloat value);
		void Uniform2f(const GLchar* name, const vec2& value);
		void Uniform3f(const GLchar* name, const vec3& value);
		void Uniform4f(const GLchar* name, const vec4& value);
		void UniformMatrix4(const GLchar* name, const mat4& matrix);
	private:
		
	};

}