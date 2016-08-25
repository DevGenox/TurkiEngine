#include "Shaders.h"

namespace Turki {


	Shaders::Shaders(const char* vertexPath, const char* fragmentPath)
	{
		programID = loadShaders(vertexPath, fragmentPath);
		glUseProgram(programID);
	}

	Shaders::~Shaders()
	{
		glDeleteProgram(programID);
	}
	GLint Shaders::GetUniformLocation(const GLchar* name)
	{
		return glGetUniformLocation(programID, name);
	}
	void Shaders::Uniform1f(const GLchar* name, const GLfloat value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}
	void Shaders::Uniform2f(const GLchar* name, const vec2& value)
	{
		glUniform2f(GetUniformLocation(name), value.x, value.y);
	}
	void Shaders::Uniform3f(const GLchar* name, const vec3& value)
	{
		glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
	}
	void Shaders::Uniform4f(const GLchar* name, const vec4& value)
	{
		glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
	}
	void Shaders::UniformMatrix4(const GLchar* name, const mat4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.nums);
	}
	GLuint Shaders::loadShaders(const char* vertexPath, const char* fragmentPath)
	{
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);


		std::string vertexShaderCode;

		std::ifstream vertexShaderSteam(vertexPath, std::ios::in);

		if (vertexShaderSteam.is_open())
		{
			std::string line = "";
			while (getline(vertexShaderSteam, line))
			{
				vertexShaderCode += "\n" + line;
			}
			vertexShaderSteam.close();
		}
		else
		{
			std::cout << "Vertex dosyasý açýlamadý.Doðru dosyada olduðuna emin misin?  " << vertexPath << std::endl;
			getchar();
			return 0;

		}



		std::string fragmentShaderCode;

		std::ifstream fragmentShaderSteam(fragmentPath, std::ios::in);

		if (fragmentShaderSteam.is_open())
		{
			std::string line = "";
			while (getline(fragmentShaderSteam, line))
			{
				fragmentShaderCode += "\n" + line;
			}
			fragmentShaderSteam.close();
		}
		else
		{
			std::cout << "Fragment dosyasý açýlamadý.Doðru dosyada olduðuna emin misin?  " << fragmentPath << std::endl;
			getchar();
			return 0;

		}

		GLint Result = GL_FALSE;
		int InfoLogLength;

		// Compile Vertex Shader

		std::cout << "Compiling shader : %s\n" << vertexPath << std::endl;
		char const* vertexSourcePointer = vertexShaderCode.c_str();
		glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
		glCompileShader(vertexShaderID);

		// Check Vertex Shader
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(vertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			printf("%s\n", &VertexShaderErrorMessage[0]);
		}

		// Compile Fragment Shader

		std::cout << "Compiling shader : %s\n" << fragmentPath << std::endl;
		char const* fragmentSourcePointer = fragmentShaderCode.c_str();
		glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
		glCompileShader(fragmentShaderID);

		// Check Fragment Shader
		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> fragmentShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(fragmentShaderID, InfoLogLength, NULL, &fragmentShaderErrorMessage[0]);
			printf("%s\n", &fragmentShaderErrorMessage[0]);
		}

		//Link Program
		std::cout << "Program Aktarýlýyor : %s\n" << fragmentPath << std::endl;
		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, vertexShaderID);
		glAttachShader(ProgramID, fragmentShaderID);
		glLinkProgram(ProgramID);

		// Check the program
		glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
		glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			printf("%s\n", &ProgramErrorMessage[0]);
		}


		glDetachShader(ProgramID, vertexShaderID);
		glDetachShader(ProgramID, fragmentShaderID);

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return ProgramID;
	}
}